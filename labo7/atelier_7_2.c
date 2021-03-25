#include <stdio.h>
#include <string.h>

typedef char typer;
void add(typer mat1[5][50] , typer mat2[5][50] , typer resultat[5][50]);
void avg(typer mat);
void afficher(typer mat[5][50]);

int main(){
typer mat1[5][50]={""};
strcpy(mat1[0],"Les Canadiens sont une equipe de hockey");
strcpy(mat1[1],"Les Nordiques sont de Quebec");
strcpy(mat1[2],"Ils ne FONT pas de politique");
strcpy(mat1[3],"Super moi non plu");
strcpy(mat1[4],"Hourra!");

afficher(mat1);

typer mat2[5][50]={""};
strcpy(mat2[0],"Je dors ZZZ zzz");
strcpy(mat2[1],"Le cours de C est le meilleur");
strcpy(mat2[2],"J'aime apprendre");
strcpy(mat2[3],"Nous avons tous le temps pour un bon repas");
strcpy(mat2[4],"UQAM est mon univers");

typer resultat[5][50]={""};

add(mat1 , mat2 , resultat);

}

void add(typer mat1[5][50] , typer mat2[5][50] , typer resultat[5][50]){
for(int i=0 ; i < 5 ; i++){
  for(int j=0 ; j < 50 ; j++){
  resultat[i][j]=mat1[i][j] + mat2[i][j];
  }
}
afficher(resultat);
}

void afficher(typer mat[5][50]){
for(int i=0 ; i< 5 ; i++){
    for(int j=0 ; j< 50 ; j++ ){
    if((int)mat[i][j] < 32){
        mat[i][j]=' ';
    }    
    printf( "%c:%d ", mat[i][j] , (int)mat[i][j]);
    }
    printf("\n");
}
}

