#include <stdio.h>
#include <stdlib.h>

struct Ensemble
{
  int* tab;
  int indice;
} ensemble;

int ajouter(struct Ensemble* , int);
int supprimer(struct Ensemble * , int);
int rechercher(struct Ensemble *E , int valeur);
int vider(struct Ensemble *E);

int main(){

struct Ensemble E ={NULL , 0};
int valeur1 = 2;
int valeur2 = 3 ; 
ajouter(&E , valeur1);
ajouter(&E , valeur2);
ajouter(&E , 5);
//printf("%d %d %d", E.tab[0] , E.tab[1] , E.tab[2]);
supprimer(&E , valeur1);
rechercher(&E , valeur1);

printf("%d\n", E.tab[0]);

vider(&E);
supprimer(&E , valeur2);
}
int ajouter(struct Ensemble * E , int valeur ){
    if(rechercher(&E , valeur)==-1){
      E->tab = realloc(E->tab , sizeof(int));
      *(E->tab+E->indice)=valeur;
      E->indice = E->indice + 1;
    }else{
        puts("la valeur existe déjà");
    }
    return valeur;
}


int supprimer(struct Ensemble *E , int valeur){
    int taille = E->indice;
    if(taille==0){
        printf("pas d'element");
    }else if(taille==1){
        if(E->tab[0]==valeur){
            E->tab=NULL;
            E->indice = 0;
        }
    }
    else{
     int * tab1=NULL;       
     int j=0;
     for(int i=0 ; i < E->indice ; i++){
        if(E->tab[i] != valeur){
         tab1 = realloc(tab1 , sizeof(int));
         tab1[j]=E->tab[i];
         j++;
        }
     }
      E->tab=tab1;  
      E->indice=j;  
    }
 return 0;
}

int rechercher(struct Ensemble *E , int valeur)
{
    if(E->indice==0){
        puts("vide");
        return -1;
    }else{
    for(int i=0 ; i < E->indice ; i++){
        if(E->tab[i] == valeur){
        printf("valeur trouvee\n");
         return 1;
        }
     }
    }
    puts("valeur non trouvee");
    return -1;
}

int vider(struct Ensemble *E){
    E->indice=0;
    E->tab=NULL;
    puts("l'ensemble est vide\n");
    return 0;
}

struct Ensemble union(struct Ensemble *E1 , struct Ensemble *E2)
{
    for(int i=0 ; i < E2->indice ; i++ ){
    ajouter(&E1 , E2->tab[i]);
    }
    return E1;
};

//*/