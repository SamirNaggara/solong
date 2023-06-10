# Projet de Naggara Samir

Ce projet consiste à creer un petit labyrinth en utilisant seulement le langage c et un mini librairie appelée minilibx.

Dans ce mini jeu, vous aiderez Bilal a attraper des chats. Une fois cela réalisé, plus qu'à attraper la crêpe et vous avez gagné !

C'est à vous de creer la carte, de la placer dans un fichier .ber à la racine du projet, et de l'envoyer en argument du programme pour l'executer.

La carte est créée comme suit :
P -> Le personnage
1 -> Les murs
0 -> Un espace vide
C -> Les chats
E -> La crêpe

En lançant le programme par défaut, une carte basic est automatiquement fourni

# Installation

git clone <ce-repot>
make
./solong 
ou
./solong <map-name>

# Réalisation

Pour ce projet, j'ai voulu bien rangé les éléments.

J'ai donc créé une structure avec toutes les infos concernant le canva tel que les infos sur la carte, sur les sprites, la position du joueur et de chaque objet.

La carte elle même est rangée dans une liste chainée, ou chaque élément est un point de la carte.
En plus de la position x et y du point considéré, on a aussi sont type (mur ou autre...), mais aussi un accès directe vers le pointeur contenant les points adjacents.

Il suffit donc de faire canva->tile.up pour avoir la case en haut de cette à laquelle je suis.
Ou nul s'il n'y a rien.

Une fois bien rangée, il faut initialiser la minilibx, creer tout les sprites, placer la carte de façon à ce que le joueur sois bien dedans, puis creer le tout.

Une boucle est alors à l'écoute de chaque mouvement du clavier.
Le joueur bougera en fonction des touches du claviers préssée


