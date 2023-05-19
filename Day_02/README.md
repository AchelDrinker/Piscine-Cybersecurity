# ft_onion

Voici un guide rapide pour minifier votre ft_onion, avec les commandes essentielles pour faire fonctionner le serveur dans les plus brefs délais.

Le projet est expliqué dans la section guide qui contient des informations sur tor et les services cachés, ssh et nginx. 

## Docker ou VirtualBox 

À mon goût, j'opterais pour Docker car il consomme moins de ressources et occupe moins d'espace,

De plus, avec docker vous pouvez directement télécharger une image de nginx.

Tout d'abord nous installons docker ou nous le démarrons, dans les macs de l'école 42 nous le démarrons depuis le terminal de la manière suivante : 
```
$> /sgoinfre/shared/42toolbox/init_docker.sh 
```
Ou depuis un autre appareil, nous allons sur le bureau de Docker.
Une fois installé, nous pouvons démarrer notre serveur avec la commande suivante dans le terminal :
```
$> docker run -it -p 4242:4242 -p 80:80 --name [container name] [docker image]
```
-it : Rend le conteneur interactif depuis le terminal.

-p : Exposer le port 4242 et 80, dans ce cas, à partir du conteneur en tant que port 4242 et 80, n'importe quel autre port fera l'affaire.

--name : Le nom du conteneur.

image : dans ce cas j'ai choisi debian (installation avec ```docker pull debian```)

Pour sortir de ce processus, nous exécutons :
```
$> exit
```
Pour le redémarrer on exécute dans le terminal : 
```
$> docker start -i [nom du conteneur]. 
```

## Installation des paquets 

Les paquets les plus importants pour ce serveur sont nginx, Openssh-server et tor.

Pour les installer, il faut utiliser apt comme suit :

Pour Openssh-server 
```
$> apt update
$> apt install openssh-server 
```
Pour nginx :
```
$> apt install nginx 
```
Pour tor :
```
$> apt install tor 
```
Il serait également utile d'installer sudo pour accéder à la racine depuis ssh facilement, et vim pour modifier les fichiers confortablement. 
```
$> apt install sudo 
$> apt install vim 
```

## Configuration du serveur

Pour la configuration du serveur, nous devons comprendre ce que sont tor, nginx et ssh. 

Pour commencer notre configuration, nous allons créer un utilisateur et le placer dans le groupe sudo : 
```
$> adduser user
$> usermod -aG sudo user
```
Ceci sera utile lorsque nous voudrons nous connecter via ssh à notre serveur. 

Nous allons continuer à configurer ssh, pour nous connecter à notre serveur à partir du port 4242. 
```
$> cd /etc/ssh 
$> vim sshd_config 
```
Nous allons décommenter la ligne suivante afin de pouvoir nous connecter à partir du port 4242. 
```
#Port 22
```
Et changer le port en 4242 
```
Port 4242 
```
Et pour démarrer ssh : 
```
$> service ssh start 
```
Nous pouvons ainsi nous connecter en ssh à notre serveur sur le port 4242. 

Une fois ssh configuré, nous allons aller sur nginx avec lequel nous allons héberger notre serveur web via http.

Pour ce faire, nous allons d'abord aller dans nginx.conf : 
```
$> cd /etc/nginx 
$> vim nginx.conf 
```
et décommenter la ligne server_tokens :
```
20 ~ server_tokens off ;
```
Cela permet de cacher la bannière du serveur et d'améliorer la sécurité. 

Ensuite, nous irons dans /var/www/html
```
$> cd /var/www/html
```
Créer une page index.html lambda (voir index.html), qui est la page que nous allons afficher.

Pour démarrer notre serveur dans nginx, nous écrivons :
```
$> service nginx start 
```
Et en tapant la ligne ci-dessous dans la barre de notre navigateur de préférence, nous nous connecterons à notre serveur. 

http://localhost:80 

Enfin, nous devons configurer tor qui sera notre service caché, 

Pour ce faire, nous allons chercher le fichier torrc :
```
$> cd /etc/tor 
$> vim torrc 
```
Modifier en décommentant le port et l'adresse :
```
71 ~ HiddenServiceDir /var/lib/tor/hidden_service/ 
72 ~ HiddenServicePort 80 127.0.0.1.1:80 
```
Ceci connectera notre service caché à travers le port 80 et sauvegardera les données dans /var/lib/tor/hidden_service/. 

Nous terminons ainsi la configuration de notre serveur avec le service caché. 

## Démarrer notre serveur 

Pour démarrer notre serveur, nous devons démarrer tor et obtenir le nom d'hôte qui se trouve dans /var/lib/tor/hidden_service/hostname. 

Pour démarrer tor, il faut taper 
```
$> tor  
```
Depuis un terminal en ssh : 
```
$> sudo su (il nous demandera le mot de passe de l'utilisateur) 
$> cd /var/lib/tor/hidden_service/ 
$> cat hostname 
```
Cela nous donnera un hash avec un .onion à la fin [xxxxxx...xxx.onion] et ce sera notre lien de connexion dans tor ou Brave tor. 

Notre serveur est alors terminé.
