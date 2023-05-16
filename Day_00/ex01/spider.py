import argparse # importation de la bibliothèque argparse pour traiter les arguments de la ligne de commande
import os # importation de la bibliothèque os pour manipuler les fichiers et les dossiers
import requests # importation de la bibliothèque requests pour effectuer des requêtes HTTP
from bs4 import BeautifulSoup # importation de la bibliothèque BeautifulSoup pour analyser des pages HTML
from urllib.parse import urljoin # importation de la fonction urljoin pour joindre des URL

DEFAULT_DEPTH = 5 # déclaration de la profondeur maximale de recherche
DEFAULT_PATH = "./data" # déclaration du dossier de destination des images téléchargées
ALLOWED_EXTENSIONS = {".jpg", ".jpeg", ".png", ".gif", ".bmp"} # déclaration des extensions de fichier autorisées

def download_image(url, path):
    """Télécharge une image depuis une URL et l'enregistre dans un fichier"""
    response = requests.get(url) # effectue une requête HTTP pour récupérer l'image
    if response.status_code == 200: # si la requête a réussi
        with open(path, "wb") as f: # ouvre un fichier binaire en écriture
            f.write(response.content) # écrit le contenu de l'image dans le fichier

def extract_images(url, path, depth):
    """Récupère les images d'une page web et de ses pages liées (si depth > 0)"""
    response = requests.get(url) # effectue une requête HTTP pour récupérer la page web
    soup = BeautifulSoup(response.content, "html.parser") # analyse la page avec BeautifulSoup
    for img in soup.find_all("img"): # parcourt toutes les balises <img> de la page
        img_url = img.get("src") # récupère l'URL de l'image
        if img_url and img_url.lower().endswith(tuple(ALLOWED_EXTENSIONS)): # si l'URL est valide et l'extension est autorisée
            img_abs_url = urljoin(url, img_url) # convertit l'URL relative en URL absolue
            filename = os.path.basename(img_abs_url) # extrait le nom du fichier de l'URL absolue
            image_path = os.path.join(path, filename) # crée le chemin complet du fichier à enregistrer
            download_image(img_abs_url, image_path) # télécharge l'image et l'enregistre dans le fichier
    if depth > 0: # si la profondeur de recherche n'est pas atteinte
        for link in soup.find_all("a"): # parcourt toutes les balises <a> de la page
            link_url = link.get("href") # récupère l'URL du lien
            if link_url and link_url.startswith(url) and not link_url.endswith(".pdf"): # si l'URL est valide et ne pointe pas vers un fichier PDF
                link_abs_url = urljoin(url, link_url) # convertit l'URL relative en URL absolue
                extract_images(link_abs_url, path, depth-1) # recherche les images de la page liée récursivement

def main():
    """Point d'entrée principal du programme"""
    parser = argparse.ArgumentParser(description="Spider program to download images from a website") # Crée un objet ArgumentParser pour traiter les arguments de la ligne de commande
    parser.add_argument("url", help="URL of the website") # Ajoute un argument obligatoire pour l'URL du site web
    parser.add_argument("-r", "--recursive", action="store_true", help="recursively download images") # Ajoute un argument optionnel pour le téléchargement récursif des images
    parser.add_argument("-l", "--depth-level", type=int, default=DEFAULT_DEPTH, help="maximum depth level for recursive download") # Ajoute un argument optionnel pour le niveau de profondeur maximale pour le téléchargement récursif
    parser.add_argument("-p", "--path", default=DEFAULT_PATH, help="path where downloaded files will be saved") # Ajoute un argument optionnel pour le chemin où les fichiers téléchargés seront enregistrés
    args = parser.parse_args() # Parse les arguments de la ligne de commande
    if not os.path.exists(args.path): # Crée le dossier de destination s'il n'existe pas
        os.makedirs(args.path)
    extract_images(args.url, args.path, args.depth_level) # Extrait les images du site web
    print("Pictures has been downloaded in the folder named Data.") # Affiche un message de confirmation

if __name__ == "__main__":
    main()