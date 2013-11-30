#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdbool.h>

// Compilation : gcc -Wall -std=c99 exemple.c util.c
// Ceci est un exemple d'utilisation de util.c

int cmp(const void *, const void *);

typedef struct Mem {
	char Data[100];
	struct Mem * pNext;
}Mem;

typedef struct Bitmap {
	int *Data;
}Bitmap;

typedef struct Variable {
	char *Nom;
	int debut;
	int fin;
	struct Variable * pNext;
	struct Variable * pBefore;	
}Variable;



char **str_split (char *s, const char *ct)
{
   char **tab = NULL;

   if (s != NULL && ct != NULL)
   {
      int i;
      char *cs = NULL;
      size_t size = 1;

/* (1) */
      for (i = 0; (cs = strtok (s, ct)); i++)
      {
         if (size <= i + 1)
         {
            void *tmp = NULL;

/* (2) */
            size <<= 1;
            tmp = realloc (tab, sizeof (*tab) * size);
            if (tmp != NULL)
            {
               tab = tmp;
            }
            else
            {
               fprintf (stderr, "Memoire insuffisante\n");
               free (tab);
               tab = NULL;
               exit (EXIT_FAILURE);
            }
         }
/* (3) */
         tab[i] = cs;
         s = NULL;
      }
      tab[i] = NULL;
   }
   return tab;
}


int main (int argc, char const *argv[]) {

	char cmd[100];
	char taille[100];
	char identicateur1[100];
	char identicateur2[100];
	char pos[100];
	int *list;
	bool keepGoing = true;
	//int number;
	int i = 0;

	int tailleInt;

	int registreLimit = REGISTRE_LIMIT_INITIAL;

	//struct Mem *New;
	//struct Mem *Head;
	//Head = NULL;

	struct Variable *variableNew;
	struct Variable *variableHead;

	struct Variable *variableIndex;
	struct Variable *variableBefore;
	struct Variable *variableNext;

	bool trouve;
	int indexInsertion;
	int counteur;
		

	variableHead = NULL;

	struct Bitmap *bitmap;
	
	//initialization du registre de base
	int *reg_base = malloc(registreLimit * sizeof(int));
	//reg_base[0] = 123;
	//reg_base[1] = 777;
	//reg_base[5] = 555; 

	
	//initialization bitmap
	bitmap = (Bitmap*)malloc(sizeof(struct Bitmap));
	//bitmap = (Bitmap*)malloc(registreLimit* sizeof(struct Bitmap));
	bitmap->Data = (int*)malloc(registreLimit * sizeof(int));
	for(i = 0; i < registreLimit ; i++ ){
		bitmap->Data[i] = 0;
	}
/*
	bitmap->Data[2] = 1;
	bitmap->Data[4] = 1;
	bitmap->Data[6] = 1;
	bitmap->Data[8] = 1;
	bitmap->Data[10] = 1;
	bitmap->Data[12] = 1;
	for(i = 0; i < registreLimit ; i++ ){
		printf( "\nN° %d: %d\n", i, bitmap->Data[i] );
	}
*/

	//initialization variable
	//variableNew = (Variable*)malloc(sizeof(struct Variable));
	//variableNew = (Variable*)malloc(REGISTRE_LIMIT_INITIAL * sizeof(struct Variable));
	
	//insertion de la premiere variable
	//variableNew->Nom = (char*)malloc(100 * sizeof(char));
	//variableNew->Nom = "Var1";
	//variableNew->debut = 0;
	//variableNew->fin = 4;
	//variableNew->pNext = variableHead;
	//variableHead = variableNew;

	//insertion de la seconde variable
	//variableNew = (Variable*)malloc(sizeof(struct Variable));
	//variableNew = (Variable*)malloc(REGISTRE_LIMIT_INITIAL * sizeof(struct Variable));
	//variableNew->Nom = (char*)malloc(100 * sizeof(char));
	//variableNew->Nom = "Var2";
	//variableNew->debut = 1;
	//variableNew->fin = 15;

	//le nouvelle element devient la tete
	//variableNew->pNext = variableHead;
	//variableHead = variableNew;
	/*
	//affichage des variables
	printf( "\nVariables entrees: \n" );
	printf( "\nNom: %s\n", variableHead->Nom );
	printf( "\nDebut: %d\n", variableHead->debut );
	printf( "\nFin: %d\n", variableHead->fin );

	printf( "\nNom: %s\n", variableHead->pNext->Nom );
	printf( "\nDebut: %d\n", variableHead->pNext->debut );
	printf( "\nFin: %d\n", variableHead->pNext->fin );
	*/
	
	//variableNew = (Variable*)malloc(REGISTRE_LIMIT_INITIAL * sizeof(struct Variable));
	//variableNew->pNext = variableHead;
	//variableHead = variableNew;

	//New = (Mem*)malloc(sizeof(struct Mem));
	//New->pNext = Head;
	//Head = New; 
	
	// Prints each argument on the command line.
	//for( int i = 0; i < argc; i++ )
	//{
		//printf( "arg %d: %s\n", i, argv[i] );
	//}

	//int *reg_base = malloc(REGISTRE_LIMIT_INITIAL * sizeof(int));
	//print_zone_contenu(reg_base, REGISTRE_LIMIT_INITIAL, 0, REGISTRE_LIMIT_INITIAL);

	//struct var v = {"variable", {12,13}};

	//struct var *vars[2];

	//vars[0] = &v;
	//vars[1]=NULL; //sert pour localiser la fin du tableau
	//print_vars(vars);
	//print_zone_contenu(reg_base, REGISTRE_LIMIT_INITIAL, v.tableau.pos, v.tableau.taille); 
	//print_erreur(HORS_SEG);
	//print_erreur(MEM_INSUFFISANTE);
	//print_erreur(NO_VAR);
	//print_limit(REGISTRE_LIMIT_INITIAL);  
	//print_prompt();

	do{
		print_prompt();
		scanf("%s",cmd);
		printf("\nCommand entrer: %s\n", cmd);

		//char str[] = "nicolasj.developpez.com/articles/libc/string/#LIII-D";
		//char **tab = str_split(cmd, "#");
		//int i;
 
		//for( i=0; tab[i]; i++) {
			//puts(tab[i]);
		//}
		//free(tab);
 
		//return 0;


		if(strcmp(cmd,"M") == 0){
			//M

			//affiche la valeur du registre limite (la taille) du segment de mémoire en cours
			//-La taille initiale du segment de mémoire en cours est 32 (entiers) initialisés à 0
			printf("\nLA COMMAND ENTREE EST : %s\n", cmd);
			print_limit(registreLimit);  

		} else if(strcmp(cmd,"I") == 0) {
			//I <taille>
			
			printf("\nLA COMMAND ENTREE EST : %s", cmd);
			scanf("%s",taille);
			printf("\n<taille>: %s\n", taille);
			//libère le segment de mémoire en cours, supprime toute les va-riables et crée un nouveau segment de longueur <taille> 
			//en terme de la taille d’un int.
			//-<taille> est un entier strictement positif
			//-Toute les cases dans le nouveau segment sont initialisées à zéro.

			registreLimit = atoi(taille);

			free(reg_base);
			reg_base = (int*)malloc(registreLimit * sizeof(int));

			free(bitmap);
			free(bitmap->Data);

			bitmap = (Bitmap*)malloc(sizeof(struct Bitmap));
			//bitmap = (Bitmap*)malloc(registreLimit* sizeof(struct Bitmap));
			bitmap->Data = (int*)malloc(registreLimit * sizeof(int));
			for(i = 0; i < registreLimit ; i++ ){
				bitmap->Data[i] = 0;
			}

			//elimine les variables existantes
			variableNew = NULL;
			variableHead = NULL;

			variableNew = (Variable*)malloc(sizeof(struct Variable));
			variableNew->Nom = (char*)malloc(100 * sizeof(char));
			variableNew->pNext = variableHead;
			variableHead = variableNew;
			
			

		} else if(strcmp(cmd,"N") == 0) {
			//N <identif> <taille> <list>
			trouve = false;
			indexInsertion = -1;
			counteur = 0;
				
			//printf("\nLA COMMAND ENTREE EST : %s", cmd);
			scanf("%s",identicateur1);
			//printf("\n<identif>: %s", identicateur1);
			scanf("%d",&tailleInt);
			//printf("\n<taille>: %d", taille);
			list = (int*)malloc(atoi(taille) * sizeof(int));
			for(i = 0; i < tailleInt; i++) {
				scanf("%d",&list[i]);
			}

			i = 0;
			//compte le nombre d'espace libre et determine ou insere dans le registre de base.
			while(trouve == false && i < registreLimit ){
				if( bitmap->Data[i] == 0 ){
					if(indexInsertion == -1){
						indexInsertion = i;	
					}
					counteur = counteur + 1;
					if(counteur >= tailleInt){
						trouve = true;//sort de la boucle
						//indexInsertion = i;
					}
				}else if(bitmap->Data[i] == 1){
					counteur = 0;
					indexInsertion = -1;
				}
				i = i + 1;
			}

			printf("\n<counteur>: %d", counteur);
			printf("\n<index insertion>: %d", indexInsertion);
			printf("\n<trouve>: %d\n", trouve);

			if(indexInsertion != -1 && counteur >= tailleInt && trouve == true){
				//creation d une variable dans la liste chainee
				variableNew = (Variable*)malloc(sizeof(struct Variable));
				variableNew->Nom = (char*)malloc(100 * sizeof(char));
				variableNew->Nom = identicateur1;
				variableNew->debut = indexInsertion;
				variableNew->fin = indexInsertion + tailleInt;
				variableNew->pNext = variableHead;
				variableHead->pBefore = variableNew;
				variableHead = variableNew;
				
				for(i = indexInsertion; i < (indexInsertion + tailleInt); i++){
					//insertion dans le registre					
					reg_base[i] = list[i-indexInsertion];
					//modification du bitmap
					bitmap->Data[i] = 1;
				}				
			}else{
				//reajuster la memoire
			}
			print_zone_contenu(reg_base, registreLimit, 0, 32);
			/* int counteur = 0;
			for(i = 0; i < registreLimit; i++ ){
				if( bitmap->Data[i] == 0 ){
					counteur = counteur + 1;
				}
			} */



			//for(i = 0; i < tailleInt; i++) {
				//printf("\n<list>: %d\n", list[i]);
			//}
			//scanf("%s",list);
			//printf("\n<list>: %s\n", list);

			//alloue dans le segment de mémoire en cours un tableau (référencé
			//par la variable <identif>) de <taille> entiers et initialise ses
			//cases avec les éléments de <list>. La variable <identif> peut
			//être déjà existante.
			//- <list> est une séquence d’entiers séparés par des blancs.
			//- On suppose que <taille> représente toujours la longeur de
			//<list>. <taille> ne peut être nulle.
			//- Pour satisfaire cette requête une allocation dans le segment
			//de mémoire courant par l’algorithme first fit est tentée. En cas
			//d’échec le ramasse miettes est lancé. Celui-ci récupère les ta-
			//bleaux déréférencés (ceux qui ne sont référencés par aucune
			//variable et fusionne les troues créées avec les troues voisins
			//s’il en existe. Ensuite on tente une deuxième fois le first fit.
			//En cas d’échec on calcule l’espace libre total. Si celui-ci suf-
			//fit à la requête, le compactage est lancé puis par first fit
			//est lancé pour l’allocation. En cas d’insuffisance de la mé-
			//moire, la variable <identif> n’est ni créée ni modifiée et
			//print_erreur(MEM_INSUFFISANTE) le signale.



		} else if(strcmp(cmd,"D") == 0) {
			//D <identif>

			printf("\nLA COMMAND ENTREE EST : %s", cmd);
			scanf("%s",identicateur1);
			printf("\n<identif>: %s\n", identicateur1);
			//supprime la variable <identif> mais pas le tableau
			//- Si cette variable n’existe pas, l’appel print_erreur(NO_VAR)
			//permet de le signaler
			trouve = false;
			//struct Variable *variableIndex;
			//struct Variable *variableBefore;
			//struct Variable *variableNext;
			variableIndex = variableHead;
			while(trouve == false && variableIndex != NULL){
				if( strcmp(variableIndex->Nom,identicateur1 ) == 0 ){
					variableBefore = variableIndex->pBefore;
					variableNext = variableIndex->pNext;	
					if( variableBefore != NULL && variableNext != NULL ){
						variableBefore->pNext = variableNext;
						variableNext->pBefore = variableBefore;
					}else if( variableBefore == NULL && variableNext != NULL ){
						variableNext->pBefore = NULL;
					}else if( variableBefore != NULL && variableNext == NULL ){
						variableBefore->pNext = NULL;
					}else if( variableBefore == NULL && variableNext == NULL ){
					}
					trouve = true;
				}
				variableIndex = variableIndex->pNext; 
			}

		} else if(strcmp(cmd,"R") == 0) {
			//R <identif1> <identif2>
		
			printf("\nLA COMMAND ENTREE EST : %s", cmd);
			scanf("%s",identicateur1);
			printf("\n<identif1>: %s", identicateur1);
			scanf("%s",identicateur2);
			printf("\n<identif2>: %s\n", identicateur2);
			//permet d’ajouter ou de modifier <identif1> comme une autre
			//référence du tableau référencé par <identif2>
			//- Si la variable <identif2> n’existe pas cette instruction est
			//ignorée et l’appel print_erreur(NO_VAR) permet de le signaler.

			//permet de le signaler
			trouve = false;
			 
			variableIndex = variableHead;
			while(trouve == false && variableIndex != NULL){
				if( strcmp(variableIndex->Nom,identicateur1 ) == 0 ){
					variableNew = (Variable*)malloc(sizeof(struct Variable));
					variableNew->Nom = (char*)malloc(100 * sizeof(char));
					variableNew->Nom = identicateur2;
					variableNew->debut = variableIndex->debut;
					variableNew->fin = variableIndex->fin;
					variableNew->pNext = variableHead;
					variableHead->pBefore = variableNew;
					variableHead = variableNew;
					trouve = true;
				}
				variableIndex = variableIndex->pNext; 
			}
			

		} else if(strcmp(cmd,"P") == 0) {
			//P <pos> <taille>

			printf("\nLA COMMAND ENTREE EST : %s", cmd);
			scanf("%s",pos);
			printf("\n<pos>: %s", pos);			
			scanf("%s",taille);
			printf("\n<taille>: %s\n", taille);

			//affiche <taille> éléments entiers du segment de mémoire en
			//cours à partir de la position <pos>.
			//- Une erreur est signalée si les bornes du segment de mémoire
			//courant sont dépassés en utilisant la fonction appropriée fournie.
			
			//print_zone_contenu(reg_base, REGISTRE_LIMIT_INITIAL, 0, REGISTRE_LIMIT_INITIAL);
			print_zone_contenu(reg_base, registreLimit, atoi(pos), atoi(taille));


			

		} else if(strcmp(cmd,"L") == 0) {
			//L
			struct var v;
			int variableNombre = 0;
			printf("\nLA COMMAND ENTREE EST : %s\n", cmd);		
			//affiche selon l’ordre alphabétique des noms, la liste des variables
			//avec les positions de début des zones qu’elles réfèrent et leurs
			//tailles respectives

			trouve = false;
						 
			variableIndex = variableHead;
			while(trouve == false && variableIndex != NULL){
				variableNombre = variableNombre + 1;
				variableIndex = variableIndex->pNext; 
			}

			int j = 0;

			char **s = (char**)malloc(variableNombre * sizeof(char*));
			variableIndex = variableHead;
			while(trouve == false && variableIndex != NULL && j < variableNombre ){
				s[j] = variableIndex->Nom; 
				j = j + 1;
				variableNombre = variableNombre + 1;
				variableIndex = variableIndex->pNext; 
			}

			qsort( (char*)s, variableNombre, sizeof(s[0]), cmp);

			struct var *vars[variableNombre + 1];

			j = 0;
			variableIndex = variableHead;
			while(variableIndex != NULL && j < variableNombre){
				if(strcmp(variableIndex->Nom, s[j] ) == 0){
					strcpy(v.id, variableIndex->Nom);
					v.tableau.pos = variableIndex->debut;
					v.tableau.taille =  variableIndex->fin - variableIndex->debut;
					//v = {variableIndex->Nom, { variableIndex->debut, variableIndex->fin - variableIndex->debut}};



					
					//v = {variableIndex->Nom, { variableIndex->debut, variableIndex->fin - variableIndex->debut}};
					vars[j] = &v;
				}
				variableIndex = variableIndex->pNext;
				j = j + 1;
			}			
			vars[variableNombre]=NULL;
			print_vars(vars);
			
  
  			
  
  			vars[0] = &v;
  			vars[1]=NULL; //sert pour localiser la fin du tableau

  			print_vars(vars);

			/*
			struct var v = {"variable", {12,13}};
  
  			struct var *vars[2];
  
  			vars[0] = &v;
  			vars[1]=NULL; //sert pour localiser la fin du tableau
  			print_vars(vars);

			i = 0;
			while(){

			}
			*/


		} else if(strcmp(cmd,"C") == 0) {
			//C

			printf("\nLA COMMAND ENTREE EST : %s\n", cmd);
			//lance le ramasse miettes et le compacteur la mémoire


		} else if(strcmp(cmd,"Q") == 0){
			//Q
			printf("\nLA COMMAND ENTREE EST : %s\n", cmd);
			//quitte minimem
			keepGoing = false;
		}
	}while(keepGoing);
	printf("\nEND of MINIMEM\n");


	return 0;
}

int cmp(const void *x, const void *y)
{
    return(strcmp(*((char**)x),*((char**)y)));       
}


