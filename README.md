# Push_swap

Tri d'une pile d'entiers à l'aide d'un jeu d'opérations restreint, avec pour objectif de minimiser le nombre de mouvements. Implémentation en C reposant sur la recherche de la **plus longue sous-séquence croissante**.

Projet réalisé dans le cadre du cursus **École 42 Paris** (2022).

---

## Le problème

Deux piles, `a` et `b`. La pile `a` contient les entiers à trier, `b` est vide. Seules onze opérations sont autorisées :

| Opération | Effet |
|---|---|
| `sa` / `sb` / `ss` | Échanger les deux premiers éléments d'une pile, ou des deux |
| `pa` / `pb` | Déplacer le premier élément d'une pile vers l'autre |
| `ra` / `rb` / `rr` | Rotation : le premier élément passe en dernier |
| `rra` / `rrb` / `rrr` | Rotation inverse : le dernier élément passe en premier |

Le programme n'effectue aucun affichage du tri : il produit la **suite d'opérations** qui, appliquée à la pile initiale, aboutit à `a` triée et `b` vide.

La difficulté n'est pas de trier — n'importe quel algorithme naïf y parvient — mais de le faire en **peu de coups**. Aucun accès direct à un élément n'est possible : tout déplacement se paie en rotations.

---

## Utilisation

```bash
make
./push_swap 3 1 5 2 4
```

Les nombres peuvent aussi être passés comme une seule chaîne :

```bash
./push_swap "3 1 5 2 4"
```

Compter les opérations produites :

```bash
./push_swap 3 1 5 2 4 | wc -l
```

Les doublons, les valeurs non numériques et les dépassements d'entier sont rejetés avec un message d'erreur.

---

## Approche

**Petites piles : cas traités à part**

Deux ou trois éléments se trient par une suite d'opérations déterminée à l'avance. Cinq éléments également, via un traitement spécifique. Passer par l'algorithme général sur ces tailles coûterait plus de coups qu'il n'en faut.

**Grandes piles : conserver le meilleur ordre déjà présent**

L'idée directrice est de **ne pas déplacer ce qui est déjà bien placé**. Le programme recherche dans la pile `a` la plus longue sous-séquence d'éléments déjà croissants — pas nécessairement contigus. Ces éléments restent en place ; tous les autres sont envoyés vers `b`.

C'est un problème classique d'algorithmique, résolu ici par programmation dynamique : pour chaque élément, on calcule la longueur de la plus longue séquence croissante qui s'y termine, puis on remonte la chaîne pour reconstruire la séquence retenue.

L'intérêt est direct : plus la séquence conservée est longue, moins il y a d'éléments à replacer, donc moins d'opérations au total.

**Réinsertion au moindre coût**

Chaque élément de `b` doit ensuite revenir dans `a`, à sa place. Pour chacun, le programme calcule le nombre de rotations nécessaires de part et d'autre, puis déplace en priorité celui dont le coût total est le plus faible.

Les rotations simultanées (`rr`, `rrr`) sont exploitées lorsque les deux piles doivent tourner dans le même sens : deux mouvements sont ainsi payés au prix d'un.

**Finalisation**

Une fois `b` vidée, une dernière série de rotations amène le plus petit élément en tête de `a`.

---

## Organisation

```
main.c              point d'entrée
parsing.c           validation et conversion des arguments
init_list.c         construction de la pile chaînée
init_list2.c
operation.c         les onze opérations
sort_three.c        cas à trois éléments
sort_five.c         cas à cinq éléments
sort_all.c          algorithme général — recherche de la séquence croissante
sort_all_utils.c    envoi vers b, sélection des éléments
sort_all_utils2.c   calcul des coûts et réinsertion
utils.c             fonctions auxiliaires
utils2.c
printf/             implémentation personnelle de printf
```

---

## Ce que le projet m'a apporté

- **Le coût d'une opération** — travailler avec un jeu d'instructions contraint oblige à raisonner en nombre de mouvements plutôt qu'en lignes de code. C'est la première fois que j'ai eu à optimiser une solution qui fonctionnait déjà.
- **Programmation dynamique** — la recherche de la plus longue sous-séquence croissante m'a fait manipuler concrètement le principe : résoudre des sous-problèmes et réutiliser leurs résultats plutôt que tout recalculer.
- **Heuristique de coût** — accepter qu'un choix localement optimal ne garantit pas l'optimum global, et mesurer les résultats sur des jeux d'essai plutôt que de se fier à l'intuition.
- **Structures chaînées** — implémenter les opérations directement sur une liste chaînée, sans passer par un tableau intermédiaire.
