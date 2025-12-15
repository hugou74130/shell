/**
 * EXPLICATION DU CODE split_string
 * 
 * Objectif: Diviser une chaîne en mots et retourner un tableau
 * Exemple: "ls -l /tmp" → ["ls", "-l", "/tmp", NULL]
 */

 #include <stdio.h>      /* printf() */
 #include <stdlib.h>     /* malloc(), free() */
 #include <string.h>     /* strcpy(), strtok(), strlen() */
 
 /**
  * DÉCLARATION DE LA FONCTION
  * @str: la chaîne à diviser
  * return: un tableau de chaînes (NULL terminé)
  */
 char **split_string(char *str)
 {
     /* DÉCLARATION DES VARIABLES */
     char **av;        /* Tableau de pointeurs (tableau de chaînes) */
     char *token;      /* Le mot courant trouvé */
     char *copy;       /* Copie de str (strtok modifie la chaîne) */
     int i = 0;        /* Index pour remplir le tableau */
 
     /* ÉTAPE 1: ALLOUER MÉMOIRE POUR LA COPIE */
     copy = malloc(strlen(str) + 1);
     /* strlen(str) = nombre de caractères
      * + 1 = pour le \0 (null terminator)
      * malloc() alloue la mémoire
      */
 
     /* ÉTAPE 2: VÉRIFIER SI L'ALLOCATION A RÉUSSI */
     if (copy == NULL)
     {
         /* Si malloc a échoué, retourner NULL */
         return NULL;
     }
 
     /* ÉTAPE 3: COPIER LA CHAÎNE */
     strcpy(copy, str);
     /* strcpy copie str dans copy
      * Exemple: copy = "ls -l /tmp"
      * On doit le faire parce que strtok() modifie la chaîne
      */
 
     /* ÉTAPE 4: PRÉPARER strtok */
     token = strtok(copy, " ");
     /* strtok divise la chaîne par le délimiteur " " (espace)
      * token = "ls" (premier mot)
      * Le reste de copy = "-l /tmp"
      */
 
     /* ÉTAPE 5: ALLOUER MÉMOIRE POUR LE TABLEAU */
     av = malloc(sizeof(char *) * 1024);
     /* sizeof(char *) = taille d'un pointeur (8 bytes)
      * * 1024 = on alloue 1024 pointeurs
      * Cela permet de stocker jusqu'à 1024 mots
      * Exemple: av[0], av[1], av[2], ...
      */
 
     /* ÉTAPE 6: REMPLIR LE TABLEAU AVEC LES MOTS */
     while (token != NULL)
     {
         /* La boucle continue tant qu'il y a des mots */
 
         /* Allouer mémoire pour le mot courant */
         av[i] = malloc(strlen(token) + 1);
         /* strlen(token) = nombre de caractères du mot
          * + 1 = pour le \0
          * Exemple: av[0] = malloc(3) pour "ls"
          */
 
         /* Copier le mot dans le tableau */
         strcpy(av[i], token);
         /* av[0] = "ls"
          * av[1] = "-l"
          * av[2] = "/tmp"
          */
 
         /* Passer au mot suivant */
         token = strtok(NULL, " ");
         /* NULL = continue avec la chaîne précédente
          * " " = délimiteur (espace)
          * token = "-l" (deuxième mot)
          */
 
         /* Incrémenter l'index */
         i++;
         /* i = 0, puis 1, puis 2, etc. */
     }
 
     /* ÉTAPE 7: TERMINER LE TABLEAU PAR NULL */
     av[i] = NULL;
     /* Après la boucle, i = 3
      * av[3] = NULL
      * C'est le marqueur de fin du tableau
      * Exemple: av = ["ls", "-l", "/tmp", NULL]
      */
 
     /* ÉTAPE 8: LIBÉRER LA COPIE */
     free(copy);
     /* On n'a plus besoin de copy
      * La libérer évite les fuites mémoire
      */
 
     /* ÉTAPE 9: RETOURNER LE TABLEAU */
     return av;
     /* Le programme qui appelle split_string()
      * recevra le tableau av
      */
 }
 
 /**
  * RÉSUMÉ DU FLUX:
  * 
  * 1. Allouer mémoire pour copie de str
  * 2. Vérifier si l'allocation a réussi
  * 3. Copier str dans copy
  * 4. Commencer à diviser avec strtok
  * 5. Allouer mémoire pour le tableau (1024 pointeurs)
  * 6. Pour chaque mot:
  *    - Allouer mémoire pour le mot
  *    - Copier le mot dans le tableau
  *    - Passer au mot suivant
  *    - Incrémenter l'index
  * 7. Terminer le tableau avec NULL
  * 8. Libérer la copie
  * 9. Retourner le tableau
  * 
  * EXEMPLE COMPLET:
  * 
  * Entrée: "ls -l /tmp"
  * 
  * Étape 1-3:
  *   copy = "ls -l /tmp"
  * 
  * Étape 4-6 (Boucle):
  *   i=0: token="ls"   → av[0]="ls"   → i=1
  *   i=1: token="-l"   → av[1]="-l"   → i=2
  *   i=2: token="/tmp" → av[2]="/tmp" → i=3
  *   token=NULL → sortir de la boucle
  * 
  * Étape 7:
  *   av[3] = NULL
  * 
  * Retour: av = ["ls", "-l", "/tmp", NULL]
  */