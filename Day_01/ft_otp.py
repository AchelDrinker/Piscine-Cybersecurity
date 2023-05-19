from cryptography.fernet import Fernet  # Importation du module Fernet pour le chiffrement
import datetime  # Importation du module datetime pour manipuler les dates et heures
import hmac  # Importation du module hmac pour le calcul de hachage
import hashlib  # Importation du module hashlib pour les fonctions de hachage
import base64  # Importation du module base64 pour les opérations de codage en base64
import argparse  # Importation du module argparse pour analyser les arguments en ligne de commande
import sys  # Importation du module sys pour accéder aux paramètres du système
import os  # Importation du module os pour les opérations sur le système de fichiers

def decrypt_key():
    with open('filekey.key', 'rb') as key_file:  # Ouverture du fichier 'filekey.key' en mode lecture binaire
        key = key_file.read()  # Lecture du contenu du fichier et stockage dans la variable 'key'
    with open('ft_otp.key', 'rb') as encrypted_key_file:  # Ouverture du fichier 'ft_otp.key' en mode lecture binaire
        encrypted_key = encrypted_key_file.read()  # Lecture du contenu du fichier et stockage dans 'encrypted_key'
    cipher = Fernet(key)  # Création d'une instance Fernet avec la clé 'key'
    decrypted_key = cipher.decrypt(encrypted_key)  # Décryptage de 'encrypted_key' avec la clé 'key'
    return decrypted_key.decode()  # Retourne la clé décryptée sous forme de chaîne de caractères

def generate_otp_key():
    hex_key = decrypt_key()  # Récupération de la clé décryptée
    hashed = hmac.new(base64.b16decode(hex_key, casefold=True), int(count_time()).to_bytes(8, byteorder='big'), hashlib.sha1)  # Calcul du hachage en utilisant la clé
    digest = hashed.hexdigest()  # Conversion du hachage en une chaîne hexadécimale
    offset = int(digest[-1], 16)  # Récupération de l'offset à partir du dernier caractère du hachage
    bin_code = bin(int(digest[offset * 2:offset * 2 + 8], 16))  # Conversion d'une partie du hachage en une chaîne binaire
    otp = int(bin_code[3:], 2) % 10 ** 6 if len(bin_code[2:]) > 31 else int(bin_code[2:], 2) % 10 ** 6  # Génération de l'OTP
    print(str(otp).zfill(6))  # Affichage de l'OTP avec un remplissage de zéros à gauche

def count_time():
    dt = datetime.datetime.now(datetime.timezone.utc)  # Récupération de l'heure actuelle en utilisant le fuseau horaire UTC
    dt_min = datetime.datetime.min.replace(tzinfo=datetime.timezone.utc)  # Récupération de l'heure minimale avec le fuseau horaire UTC
    dt = dt - (dt - dt_min) % datetime.timedelta(seconds=30)  # Arrondissement de l'heure actuelle à la plus proche période de 30 secondes
    utc_time = dt.replace(tzinfo=datetime.timezone.utc)  # Conversion de l'heure en utilisant le fuseau horaire UTC
    utc_timestamp = utc_time.timestamp()  # Conversion de l'heure en timestamp
    return int(utc_timestamp) // 30  # Retourne l'heure divisée par 30 pour obtenir le compte de temps

def main():
    parser = argparse.ArgumentParser(description='ft_otp')  # Création d'un objet ArgumentParser avec une description
    parser.add_argument('-g', type=str)  # Ajout d'un argument -g qui accepte une valeur sous forme de chaîne de caractères
    parser.add_argument('-k', action='store_true')  # Ajout d'un argument -k qui n'a pas de valeur, juste une présence
    args = parser.parse_args()  # Analyse des arguments de la ligne de commande

    if not os.path.isfile('filekey.key'):  # Vérification si le fichier 'filekey.key' n'existe pas
        os.system("touch filekey.key 2> /dev/null")  # Création du fichier 'filekey.key'
        print("File filekey.key created")  # Affichage d'un message de confirmation

        key = Fernet.generate_key()  # Génération d'une nouvelle clé Fernet
        with open('filekey.key', 'wb') as key_file:  # Ouverture du fichier 'filekey.key' en mode écriture binaire
            key_file.write(key)  # Écriture de la clé dans le fichier
            print("Key generated")  # Affichage d'un message de confirmation

    if not any(vars(args).values()):  # Vérification si aucun argument n'a été spécifié
        print('\nPlease use arguments or check the usage with ft_otp -h.\n')  # Affichage d'un message d'erreur
        sys.exit(1)  # Arrêt du programme avec un code de sortie 1 (erreur)

    if args.g:  # Vérification si l'argument -g a été spécifié
        if args.g == 'key.hex' and os.path.isfile('./key.hex'):  # Vérification si l'argument -g a la valeur 'key.hex' et si le fichier 'key.hex' existe
            my_key = open('key.hex', 'r').read()  # Lecture de la clé à partir du fichier 'key.hex'
            with open('filekey.key', 'rb') as key_file:  # Ouverture du fichier 'filekey.key' en mode lecture binaire
                key = key_file.read()  # Lecture du contenu du fichier et stockage dans la variable 'key'
            cipher = Fernet(key)  # Création d'une instance Fernet avec la clé 'key'
            encrypted_key = cipher.encrypt(my_key.encode())  # Chiffrement de la clé
            with open('ft_otp.key', 'wb') as key_file:  # Ouverture du fichier 'ft_otp.key' en mode écriture binaire
                key_file.write(encrypted_key)  # Écriture de la clé chiffrée dans le fichier
                print("Encrypted key written to ft_otp.key.")  # Affichage d'un message de confirmation
        elif len(args.g) == 64:  # Vérification si la valeur de l'argument -g a une longueur de 64 caractères
            my_key = args.g  # Récupération de la clé spécifiée dans l'argument -g
            print('Flag -g activated')  # Affichage d'un message
            if not os.path.isfile('filekey.key'):  # Vérification si le fichier 'filekey.key' n'existe pas
                os.system("touch ft_otp.key 2> /dev/null")  # Création du fichier 'ft_otp.key'
                print("ft_otp.key created")  # Affichage d'un message de confirmation
            if os.path.isfile('key.key'):  # Vérification si le fichier 'key.key' existe
                user_input = input('You are about to generate a new key, this process will permanently erase the old key. Do you wish to continue? [y][N]')  # Demande de confirmation à l'utilisateur
                if user_input.lower() == 'y':  # Vérification si l'utilisateur a répondu 'y'
                    print("Processing to create new key")  # Affichage d'un message de confirmation
                else:
                    os.system('clear')  # Effacement de l'écran
                    sys.exit(1)  # Arrêt du programme avec un code de sortie 1 (erreur)
                print("ft_otp.key created")  # Affichage d'un message de confirmation
            with open('filekey.key', 'rb') as key_file:  # Ouverture du fichier 'filekey.key' en mode lecture binaire
                key = key_file.read()  # Lecture du contenu du fichier et stockage dans la variable 'key'
            cipher = Fernet(key)  # Création d'une instance Fernet avec la clé 'key'
            encrypted_key = cipher.encrypt(my_key.encode())  # Chiffrement de la clé
            with open('ft_otp.key', 'wb') as key_file:  # Ouverture du fichier 'ft_otp.key' en mode écriture binaire
                key_file.write(encrypted_key)  # Écriture de la clé chiffrée dans le fichier
                print("Encrypted key written to ft_otp.key.")  # Affichage d'un message de confirmation
        else:
            print('Generator, incorrect argument or file not found!')  # Affichage d'un message d'erreur
            sys.exit(1)  # Arrêt du programme avec un code de sortie 1 (erreur)

    if args.k:  # Vérification si l'argument -k a été spécifié
        generate_otp_key()  # Génération de l'OTP

if __name__ == '__main__':
    main()  # Appel de la fonction principale
