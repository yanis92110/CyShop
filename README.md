# CyShopShop

## CyShopShop est un programme de concessionnaire de voitures qui vous permet de soit:

* Jouer le rôle d'un client qui peut parcourir le catalogue de voitures en fonction de leur catégories (Voitures
sportives, de ville ou SUV) et acheter celles qui lui plaisent.

* Jouer le rôle d'un gérant de la concession qui aura accès au stock des voitures, qui devra gérer les ruptures de
stocks ainsi que les 5 voitures qui ont le stock le plus bas. Il pourra, en fonction des besoins de la concession
commander des voitures ou s'en débarasser.

## Comment lancer le programme?

* Sur votre machine

Téléchargez sur votre machine le programme en dossier compressé (.ZIP) et décompresser le. Lancez un invité de
commandes dans le dossier décompressé, verifiez que vous êtes bien dans le dossier contenant les fichiers, éxécutez
la commande 'make' puis '/main' et le programme se lançera.

* Sur GitHub

Cliquez sur le bouton vert "use this template" en haut à droite puis dliquez sur "Open in codespace". Un codespace se
lançera, entrer dans le terminal la commande 'make' puis la commande './main' pour lancer le programme.


## Bugs Connus

* L'historique d'achats se fait lignes par lignes, donc si un client vient acheter lors de 2 éxécutions différentes, alors son historique sera scindé et comptera comme les historiques de 2 clients différents.
* Lorsque l'on supprime une voiture cela dérègle le tableau
