import argparse  # module pour traiter les arguments de la ligne de commande
import os  # module pour interagir avec le système de fichiers
from PIL import Image  # module pour travailler avec des images
from PIL.ExifTags import TAGS  # module pour traduire les tags EXIF en chaînes de caractères

ALLOWED_EXTENSIONS = {".jpg", ".jpeg", ".png", ".gif", ".bmp"}  # ensemble de toutes les extensions d'images autorisées

def parse_metadata(image_path):
    """Fonction qui lit les métadonnées d'une image et les affiche"""
    image = Image.open(image_path)  # ouvre l'image
    exif_data = image._getexif()  # récupère les données EXIF
    if exif_data:  # s'il y a des données EXIF
        for tag_id, value in exif_data.items():
            tag = TAGS.get(tag_id, tag_id)  # traduit l'ID du tag en chaîne de caractères
            print(f"{tag}: {value}")  # affiche le tag et sa valeur
    else:  # s'il n'y a pas de données EXIF
        print("No EXIF data found.")  # affiche un message
    print(f"Creation time: {os.path.getctime(image_path)}")  # affiche la date de création de l'image

def main():
    """Point d'entrée principal du programme"""
    parser = argparse.ArgumentParser(description="Scorpion program to parse image metadata")  # crée un objet ArgumentParser pour traiter les arguments de la ligne de commande
    parser.add_argument("files", nargs="+", help="image files to parse")  # ajoute un argument obligatoire pour les fichiers d'images à traiter
    args = parser.parse_args()  # analyse les arguments de la ligne de commande

    for file in args.files:  # pour chaque fichier passé en argument
        if os.path.isfile(file) and file.lower().endswith(tuple(ALLOWED_EXTENSIONS)):  # si c'est un fichier et qu'il a une extension autorisée
            parse_metadata(file)  # analyse ses métadonnées
        else:
            print(f"{file} is not a valid image file.")  # sinon, affiche un message d'erreur
    print("Done.")  # affiche un message de fin

if __name__ == "__main__":
    main()  # appelle la fonction main() si le script est exécuté directement

