#include "util.h"

// Compilation : gcc -Wall -std=c99 exemple.c util.c
// Ceci est un exemple d'utilisation de util.c


int main (int argc, char const *argv[])
{
  int *reg_base = malloc(REGISTRE_LIMIT_INITIAL * sizeof(int));
  print_zone_contenu(reg_base,REGISTRE_LIMIT_INITIAL,0,REGISTRE_LIMIT_INITIAL);
  
  struct var v = {"variable", {12,13}};
  
  struct var *vars[2];
  
  vars[0] = &v;
  vars[1]=NULL; //sert pour localiser la fin du tableau
  print_vars(vars);
  print_zone_contenu(reg_base,REGISTRE_LIMIT_INITIAL,v.tableau.pos,v.tableau.taille); 
  print_erreur(HORS_SEG);
  print_erreur(MEM_INSUFFISANTE);
  print_erreur(NO_VAR);
  print_limit(REGISTRE_LIMIT_INITIAL);  
  print_prompt();
  return 0;
}