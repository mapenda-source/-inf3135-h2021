#include <stdio.h>

void afficherMatrice(int matrice[3][3]);
void additionnerMatrices(int matrice1[3][3] , int matrice2[3][3] , int resultat[3][3]);
int main(){
int matrice1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int matrice2[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int resultat[3][3];

additionnerMatrices(matrice1, matrice2 , resultat) ;

int nombre[3,8] 
//afficherMatrice(matrice);
}

void afficherMatrice(int matrice[3][3]){
printf("%d " , matrice[0][0]);
printf("%d " , matrice[0][1]);
printf("%d " , matrice[0][2]);
printf("\n%d " , matrice[1][0]);
printf("%d " , matrice[1][1]);
printf("%d " , matrice[1][2]);
printf("\n%d " , matrice[2][0]);
printf("%d " , matrice[2][1]);
printf("%d " , matrice[2][2]);
}


void additionnerMatrices(int matrice1[3][3] , int matrice2[3][3] , int resultat[3][3]){
resultat[0][0]=matrice1[0][0]+matrice2[0][0] ;
resultat[0][1]=matrice1[0][1]+matrice2[0][1] ;
resultat[0][2]= matrice1[0][2]+matrice2[0][2] ; 
resultat[1][0]=matrice1[1][0]+matrice2[1][0] ; 
resultat[1][1]=matrice1[1][1]+matrice2[1][1] ;
resultat[1][2]=matrice1[1][2]+matrice2[1][2];
resultat[2][0]=matrice1[2][0]+matrice2[2][0] ;
resultat[2][1]=matrice1[2][1]+matrice2[2][1] ; 
resultat[2][2]=matrice1[2][2]+matrice2[2][2];
     
        afficherMatrice(resultat);

}