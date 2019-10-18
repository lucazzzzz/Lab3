# Laboratoire 3 - GUI avec tkinter

## Créer Projet VisualStudio

Pour commencer, il faut tout d'abord créer un projet VisualStudio en C++ dans le dossier de notre choix:

![Screenshot #1](https://github.com/lucazzzzz/Lab3/blob/master/Images/CreerProjetVS.JPG)

Ensuite, il faut ajouter tous les fichiers d'en-tête et tous les fichiers sources au projet:

![Screenshot #2](https://github.com/lucazzzzz/Lab3/blob/master/Images/AjouterFichiersdeGit.jpg)

Finalement, il faut régler correctement les propriétés du projet pour que le code fonctionne! Voici 3 images qui illustrent toutes les librairies à ajouter et toutes les configurations à changer sur VisualStudio (ne pas oublier de changer les options de configuration pour Release et les options de plateforme pour x64):

![Screenshot #3](https://github.com/lucazzzzz/Lab3/blob/master/Images/ProprietesProjetLib.jpg)

![Screenshot #4](https://github.com/lucazzzzz/Lab3/blob/master/Images/LibrairiePython.jpg)

![Screenshot #5](https://github.com/lucazzzzz/Lab3/blob/master/Images/LibrairieDirectShow.jpg)

## Ajouter la vidéo sur le C:/

Il ne faut pas oublier d'ajouter la vidéo à manipuler au bon endroit, pour cet exemple se sera le disque C:/ mais il peut être n'importe où dans l'ordinateur

![Screenshot #6](https://github.com/lucazzzzz/Lab3/blob/master/Images/ExampleAVI.jpg)

## Configuration Python

Il ne reste que le fichier videoplayer.py à ajouter au bon endroit, se sera dans le même dossier que le fichier myModule.pyd. Il faut générer la solution sur VisualStudio avant de compléter cette étape. Ne pas oublier d'ouvrir la console de commande dans le même dossier que le fichier videoplayer.py:

![Screenshot #7](https://github.com/lucazzzzz/Lab3/blob/master/Images/FichierPYauBonEndroit.JPG)

![Screenshot #8](https://github.com/lucazzzzz/Lab3/blob/master/Images/InvdeCommande.JPG)

Maintenant il faut créer l'environnement virtuel pour exécuter le fichier videoplayer.py et installer la librairie readchar pour que le code fonctionne. Voici une image de toutes les commandes à effectuer sur la console de commande:

![Screenshot #9](https://github.com/lucazzzzz/Lab3/blob/master/Images/CommandesVENV.JPG)

La dernière commande "python videoplayer.py" va exécuter le code et l'interface tkinter vas apparaître. Notre code a été écrit en fonction que l'utilisateur appuie sur le boutton "Search File" en premier, si un autre boutton est appuyé avant le logiciel ne fonctionne pas. Lorsque l'utilisateur appuye sur le boutton "Search File" une fenêtre apparait et demande où aller chercher le fichier "Example.AVI", dans notre cas ce sera dans le disque C:/ 

![Screenshot #10](https://github.com/lucazzzzz/Lab3/blob/master/Images/SearchFileExampleAVI.JPG)

L'uilisateur peut maintenant utiliser les autres bouttons dans l'interface tkinter : Pause/Play pour arrêter et faire jouer la vidéo, Avance Rapide pour que la vidéo avance deux fois plus vite, Reset pour revenir au début de la vidéo et Quitter pour fermer l'interface et la vidéo
