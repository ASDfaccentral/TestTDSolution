# TestTDSolution
Partie I :
Une entreprise enregistre les contacts de ses clients dans un annuaire représenté par une liste
chaînée. Chaque contacte de l'annuaire est reçu via une structure de données avec les
informations suivantes : nom, prénom, numéro de téléphone, l'identifiant de la wilaya et numéro
du contacte. Pour optimiser le temps de recherche et pour classifier les clients, l’entreprise à
décider de créer une multi-liste. Le nouvel annuaire permet de classifier les clients par Wilaya.
Le nouvel annuaire contient une liste chaînée des wilayas ordonnées par ordre croissant des
identifiants des wilayas. Chaque élément de la liste contient l’identifiant de la wilaya et deux
pointeurs : un pointeur qui pointe sur l’élément suivant et un pointeur qui pointe vers une liste
des clients de cette wilaya. Chaque élément de cette liste contient le numéro du contacte, le
nom, le prénom et le numéro de téléphone du client. La liste des contacts est ordonnée par
ordre croissant des identifiants des clients. Ci-dessous une représentation graphique de
l’annuaire téléphonique.
1- Donnez les 3 structures de données.
2- Ecrire une fonction récursive qui permet de créer la liste des wilayas (voir figure).
3- Ecrire une fonction récursive qui permet d’ajouter un élément de l’ancien annuaire
vers le nouvel annuaire.
4- Ecrire une fonction récursive qui permet de transférer tous les contacts de l’ancien
annuaire vers le nouvel annuaire.
5- Quelle est la complexité temporelle (au pire et moyenne) d’une fonction de recherche
d’un client dans le nouvel annuaire ? Expliquez votre raisonnement sans forcément
calculer le coût exact.

Partie II
Après l’implémentation de la solution proposer dans la partie I, l’équipe technique a commencé
les tests sur le nouvel annuaire. Le responsable technique à trouver qu’à chaque fois qu’il lance
une requête de recherche d’un contacte en utilisant les clés il trouve que le temps de recherche
étais énorme. Fortement déçu de la solution proposée dans la partie I, il demande aux ingénieurs
de proposer une nouvelle architecture qui prend moins de temps. Un des ingénieurs propose
d’utiliser les arbres binaires de recherche pour implémenter l’architecture. Selon lui cette
architecture permet de réduire énormément la complexité temporelle. Ci-dessous une
représentation graphique du nouvel annuaire téléphonique.
1- Donnez les nouvelles structures de données
2- Ecrire une fonction récursive qui permet d’ajouter un élément de l’ancien annuaire
vers le nouvel annuaire (l’annuaire de base et non pas de la solution proposer dans la
partie I).
3- Ecrire une fonction récursive qui permet d’afficher le nouvel annuaire.
4- Quelle est la complexité temporelle (au pire et moyenne) d’une fonction de recherche
d’un client dans le nouvel annuaire ? Expliquez votre raisonnement sans forcément
calculer le coût exact.
Partie III
Le responsable technique propose de faire une petite modification sur l’arbre binaire de
recherche pour avoir une complexité au pire meilleur.
1- Que-ce-que le responsable technique propose de faire ?
