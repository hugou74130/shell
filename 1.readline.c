/**
 * EXPLICATION DU CODE prompt
 * 
 * Objectif: Afficher "$ ", lire une commande, l'afficher
 * Répéter jusqu'à EOF (Ctrl+D)
 */

 #include <stdio.h>      /* printf(), getline() */
 #include <stdlib.h>     /* free() */
 
 /**
  * FONCTION MAIN
  */
 int main(void)
 {
     /* ===== DÉCLARATION DES VARIABLES ===== */
 
     char *line;         /* Pointeur pour stocker la ligne lue
                            Exemple: line → "cat prompt.c\n"
                         */
 
     size_t len = 0;     /* Taille du buffer alloué
                            size_t = unsigned long
                            len = 0 au départ
                            getline() va l'augmenter automatiquement
                         */
 
     ssize_t read;       /* Nombre de caractères lus par getline()
                            ssize_t = signed long
                            read = 5 pour "cat\n"
                            read = -1 pour EOF
                         */
 
     /* ===== BOUCLE INFINIE ===== */
     while (1)
     {
         /* La boucle continue à l'infini
            On la quittera seulement avec break
         */
 
         /* ===== INITIALISER line À NULL ===== */
         line = NULL;
         /* À chaque itération, réinitialiser line à NULL
            Pourquoi? Parce que getline() a besoin que line soit NULL
            ou un pointeur valide au départ
         */
 
         /* ===== AFFICHER LE PROMPT ===== */
         printf("$ ");
         /* Affiche le prompt "$ " sans newline
            Le curseur reste sur la même ligne
         */
 
         /* ===== LIRE UNE LIGNE ===== */
         read = getline(&line, &len, stdin);
         /* getline() = fonction standard pour lire une ligne
            &line = adresse du pointeur line
            &len = adresse de la taille du buffer
            stdin = lire depuis l'entrée standard (clavier)
            
            Exemple:
            L'utilisateur tape: "cat prompt.c"
            puis appuie sur Enter
            
            Après getline():
            line = "cat prompt.c\n"
            len = taille du buffer alloué
            read = 14 (nombre de caractères lus avec \n)
         */
 
         /* ===== VÉRIFIER EOF ===== */
         if (read == -1)
         {
             /* getline() retourne -1 si EOF
                EOF = End Of File
                Ctrl+D sur Linux/Mac = EOF
                
                Si read == -1:
                - Utilisateur a appuyé sur Ctrl+D
                - Fin du fichier/flux d'entrée
             */
             break;
             /* Sortir de la boucle while
                Arrêter le programme
             */
         }
 
         /* ===== AFFICHER LA LIGNE LUE ===== */
         printf("%s", line);
         /* Affiche la ligne lue
            line = "cat prompt.c\n"
            printf() affiche: cat prompt.c
            (le \n est inclus, donc nouvelle ligne)
         */
     }
 
     /* ===== APRÈS LA BOUCLE ===== */
 
     free(line);
     /* Libérer la mémoire allouée par getline()
        getline() alloue automatiquement la mémoire
        On doit la libérer
     */
 
     return 0;
     /* Retourner 0 = succès */
 }
 
 /**
  * RÉSUMÉ DU FLUX
  */
 
 /*
  * 1. Déclarer les variables
  * 2. Boucle infinie:
  *    a) Initialiser line à NULL
  *    b) Afficher "$ "
  *    c) Lire une ligne avec getline()
  *    d) Si EOF (read == -1): sortir
  *    e) Afficher la ligne lue
  * 3. Libérer la mémoire
  */
 
 /**
  * EXEMPLE D'EXÉCUTION
  */
 
 /*
  Affichage:  $ cat prompt.c
              (l'utilisateur tape "cat prompt.c" et appuie sur Enter)
  
  Valeurs après getline():
  line = "cat prompt.c\n"
  len = 1024 (ou plus, alloué automatiquement)
  read = 15 (nombre de caractères lus)
  
  printf("%s", line) affiche: cat prompt.c
  
  ---
  
  Affichage:  $ ls -l
  
  Valeurs après getline():
  line = "ls -l\n"
  read = 6
  
  printf("%s", line) affiche: ls -l
  
  ---
  
  Affichage:  $ 
  
  L'utilisateur appuie sur Ctrl+D
  
  Valeurs après getline():
  read = -1 (EOF)
  
  if (read == -1) → break
  Sortir de la boucle
  Libérer line
  Retourner 0
  Fin du programme
  */
 
 /**
  * DIFFÉRENCE AVEC INITIALISER line DANS LA BOUCLE
  */
 
 /*
  POURQUOI initialiser line = NULL dans la boucle?
  
  Première itération:
  - line = NULL (initialisation)
  - getline() alloue 1024 bytes
  - line pointe vers ces 1024 bytes
  
  Deuxième itération:
  - line = NULL (on le réinitialise)
  - getline() alloue une nouvelle mémoire
  - L'ancienne mémoire n'est PAS libérée!
  
  C'est une fuite mémoire!
  
  MEILLEUR CODE:
  
  while (1)
  {
      printf("$ ");
      read = getline(&line, &len, stdin);
      if (read == -1)
          break;
      printf("%s", line);
  }
  free(line);
  
  Sans réinitialiser line à NULL chaque fois.
  getline() réutilisera le buffer existant.
  */