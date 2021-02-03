#include <stdio.h>
#include <stdbool.h>
#include <time.h>
int boucleAvant(int);

int boucleApres(int);

__int128 racineCarreEntiere(__int128);

int somme(int);

bool  estTrie(int[]);

int elementPlusFrequenmt(int[]);

int main(){
clock_t t1,t2;

t1= clock();
racineCarreEntiere(4294967296);
t2= clock();
printf("%ld",t2-t1);

t1 = clock();
racineCarreEntiere(17179869184);
t2= clock();
printf("%ld",t1-t2);
}


int boucleAvant(int x){
for (int i=0;i<x;++i){
printf("i\n");
}
}

int boucleAprès(int x){
for (int j=0;j<x;j++){
printf("j\n");
}
}

int racineCarreEntiere(_int128 x){
int racine = 1;

for(int i = 0 ; i <= x ; i++ ){
if(i*i <= x){
racine = i ;
}else{
return i-1; 
}
return  i;
}
}

int somme (int t[]){
int somme = 0;
int taille  = sizeof(t)/sizeof(t[0])
for(int i = 0 ; i <taille  ; i++){
somme = somme + t[i];
}
return 0;
}

int estTrie(int t[]){
bool value = true ;
int taille = sizeof(t)/sizeof(t[0]);

for (int i =0 ; i< taille-1 ; i++){
if(t[i] >= t[i+1]){
return false;
}
}
return value;
}

int elementPlusFrequent(int t[]){
int taille = sizeof(t)/sizeof(t[0]);
int frequent = t[0];
for (int i = 0 ; i < taille-1 ; i++){
int n =0;
for(int j = 0 ; j < taille-1 ;  j++){
int count=0;
  if(t[i]==t[j]){
  count++;
  }
}
if(count > n){
n= count;
frequent=t[0];
}

}
return frequent;
}

