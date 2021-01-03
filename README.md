# ProgAvanc-e
Projet par Simon Jolivalt et Timéo Jacquier


Notre projet est un jeu de "plateforme 2D". A l'origine, le personnage devait se déplacer sur des plateformes générés semi aléatoirement à partir de schéma. Des ennemies sont présents et éliminables à travers un système de tir, et l'objectif est d'aller le plus loin possible, sachant que les scores sont comptabilisés et que l'objectif est de battre le High Score précédent. En cas de collision avec un ennemi, le score retombe à zéro et l'on recommence
Par faute de temps, les plateformes sont présentes, mais généré aléatoirement, et l'on rencontre quelques problèmes quand il en vient à gérer leurs collisions.

Contrôle :
 q : avancer vers la gauche
 d : avancer vers la droite
 s : tirer
 Espace : sauter en l'air
 p : mettre en pause
 esc : quitter le jeu (possible également depuis le menu de pause)
 
Le jeu est développé en C avec la bibliothèque graphique SDL, les dessins réalisés par une amie, Ema Glamcevski, étudiante en fac de Lettres

La compilation et exécution est possible simplement en récupérant le contenu de la branche "Master" ou grâce aux fichiers de l'archive.
La compilation se fait grâce au Makefile fourni par l'exécution de la commande "make". Celle ci génère quelques Warning qui n'ont cependant aucune incidence quand au bon déroulement du jeu. Le jeu se lance par la commande "./main".
La doc est complète et à jour, de type doxygen, et facilement générable.
