import hmac                  # Module pour le calcul d'un code d'authentification à message unique (HMAC)
import hashlib               # Module pour le calcul de hachages cryptographiques
import struct                # Module pour l'emballage et le déballage de données binaires
import argparse              # Module pour faciliter la création de ligne de commande
import os                    # Module pour les fonctions d'interaction avec le système d'exploitation
from cryptography.fernet import Fernet   # Module pour la génération de clés de chiffrement et déchiffrement

def load_key(keyfile):
    with open(keyfile, 'rb') as f:     # Ouverture du fichier clé en mode binaire
        key = f.read()                # Lecture du contenu du fichier dans une variable key
    return key

def save_key(keyfile, key):
    key = Fernet.generate_key()       # Génération d'une nouvelle clé
    with open(keyfile, 'wb') as f:    # Ouverture du fichier clé en mode binaire
        f.write(key)                 # Écriture de la clé générée dans le fichier
    print('Key was successfully saved in {}.'.format(keyfile))   # Affichage d'un message de confirmation

def hotp(key, counter, digits=6):
    hmac_digest = hmac.new(key, struct.pack('>Q', counter), hashlib.sha1).digest()   # Calcul du code d'authentification à message unique
    offset = hmac_digest[-1] & 0x0f    # Récupération de la dernière valeur de hmac_digest
    truncated_digest = hmac_digest[offset:offset+4]   # Récupération des 4 valeurs suivant offset
    code = struct.unpack('>I', truncated_digest)[0] & 0x7fffffff   # Conversion des valeurs en entier non signé 32 bits et application d'un masque pour obtenir 31 bits (la valeur obtenue sera toujours positive)
    code %= 10 ** digits              # Calcul de la valeur finale du code avec le nombre de chiffres souhaité
    return code

if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='ft_otp')   # Création d'un objet ArgumentParser avec le nom du programme
    group = parser.add_mutually_exclusive_group(required=True)   # Création d'un groupe mutuellement exclusif pour les options de ligne de commande
    group.add_argument('-g', '--generate-key', metavar='KEYFILE', help='Generate and save a new key to KEYFILE.')   # Ajout de l'option -g ou --generate-key avec la variable KEYFILE pour spécifier le fichier de clé
    group.add_argument('-k', '--get-password', metavar='KEYFILE', help='Get a new one-time password based on the key in KEYFILE.')   # Ajout de l'option -k ou --get-password avec la variable KEYFILE pour spécifier le fichier de clé
    args = parser.parse_args()         # Analyse des arguments de la ligne de commande et stockage dans un objet Namespace

    if args.generate_key: # Si l'argument "generate_key" est présent dans la ligne de commande
        if not os.path.exists(args.generate_key): # Vérifier si le fichier spécifié par l'utilisateur existe
            print('Error: {} does not exist.'.format(args.generate_key)) # Si le fichier n'existe pas, imprimer un message d'erreur
            exit(1) # Sortir du programme avec un code d'erreur
        key = load_key(args.generate_key) # Charger la clé à partir du fichier spécifié
        if len(key) < 64: # Vérifier si la clé a une longueur de 64 caractères hexadécimaux
            print('Error: key must be 64 hexadecimal characters.') # Si la clé n'a pas une longueur de 64 caractères hexadécimaux, imprimer un message d'erreur
            exit(1) # Sortir du programme avec un code d'erreur
        save_key('ft_otp.key', key) # Enregistrer la clé dans un fichier appelé "ft_otp.key"
        exit(0) # Sortir du programme avec un code de réussite

    if args.get_password: # Si l'argument "get_password" est présent dans la ligne de commande
        if not os.path.exists(args.get_password): # Vérifier si le fichier spécifié par l'utilisateur existe
            print('Error: {} does not exist.'.format(args.get_password)) # Si le fichier n'existe pas, imprimer un message d'erreur
            exit(1) # Sortir du programme avec un code d'erreur
        key = load_key(args.get_password) # Charger la clé à partir du fichier spécifié
        counter = int(os.urandom(8).hex(), 16) # Générer un compteur aléatoire de 8 octets et le convertir en entier
        password = str(hotp(key, counter)).zfill(6) # Générer un mot de passe en utilisant le compteur et la clé, et le remplir avec des zéros à gauche jusqu'à une longueur de 6 caractères
        print(password) # Imprimer le mot de passe
        exit(0) # Sortir du programme avec un code de réussite

