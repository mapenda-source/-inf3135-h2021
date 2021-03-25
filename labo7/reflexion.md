### Voici mes raisonnement étape par étape 
créer un fichier getQuote.sh
créer un dossier data et à l'intérieur on cree indice.txt
comment récupérer les données de chacun des indices listés dans le fichieer.
on sait que chaque ligne dans le fichier contient un indice.à
donc pour lire chaque ligne , on ecrit dans le fichier script bash:
#! /bin/bash

while read ligne
do
echo -e "$line" 
done < indice.txt


toutefois il m'est dit de l'enrégistreer les fichier json pour chaque indice donnée.
par exemple pour le BCE :
curl https://query1.finance.yahoo.com/v7/finance/quote?symbols={BCE}.to -o "BCE.json"
Donc cette commande enrégistre le fichier json BCE dans un fichier BCE.json.

En fin dans le script , on aura :
#! /bin/bash

while read ligne
do
curl https://query1.finance.yahoo.com/v7/finance/quote?symbols="$line".to -o "$line".json  
done < indice.txt

Tout ceci va être mis dans le fichier getQuote.sh 
l'execution de ce scripte produira les fichier:
BCE.json , BMO.json , BLU.json ,BNS.json et K.json.


Maintenant , il nous reste à produire notre programme tp1.c.

Que fait ce programme ?
le programme tp1 recupere , en uutilisant 
le fichier indices.txt et les fichiers.json , les valeurs suivante:
fiftyTwoWeekLow
fiftyTwoWeekHigh
regularMarketPrice
trailingAnnualDividendYield

Comment recupérer ces valeurs en un temps optimal?
Comment manipuler les fichiers en C ?
Quelle méthode me permet de lire les lignes voulu pour enfin extraire les valeurs?

Pour traiter les fichiers , nous allons se servir d'une structure de type FILE dans le librairie stdio.h.
J'utilise de la méthode fopen qui renvoie un pointeur FILE.

Pour lire par exemple fichier indice.txt ligne par ligne 
je vais faire ceci:

#define Taille_MAX 100

Dans le main:

FILE* fichier = NULL;
char chaine[TAILLLE_MAX] = "";

fichier = fopen("indice.txt", "r");

pour lire chaque ligne:

if(fichier != NULL) // car le fichier doit exister
{
    while(fgets(chaine, TAILLLE_MAX, fichier)!= NULL) tant qu'il y a pas d'erreur
    {
       printf("%s", chaine);
    }
    fclose(fichier); // parce que le flux doit être fermer.
}

Ce code va nous lister dans chaque boucle la ligne(un indice) suivante du fichier indice.txt:
BCE
BNS
BLU
BMO
K

Comme ça , on va s'en servir du boucle pour lire le fichier json pour chaque indice.

comment extraire les valeur du fichier json ?
Doit je utiiliser une librairie permettant de amnipuler du json ?
Ou doit je les manipuler comme un fichier standard toutefoisle format json revele peut etre 
un simplicité à chercher.

Dans ce cas , il serait important de penser aux formatages.
car json est constitué de clé et valeurs.
Avec la methode fscanf , je pourrais recupere cle et la valeur de chaque ligne.
Et si la clé correspond à ce que nous cherchons , on prends sa valeur.

exemple pour le fichier BCE.json.

`
#define Taille_MAX 100
int main(){
FILE* fichier = NULL;
char chaine[TAILLLE_MAX] = "";
int valeur;
char str1[100]
fichier = fopen("BCE.json", "r");
if(fichier != NULL) // car le fichier doit exister
{
    while(fgets(chaine, TAILLLE_MAX, fichier)!= NULL) tant qu'il y a pas d'erreur
    {
        je recupere la clé et les valeurs avec fscanf
         fscanf(chaine, "%s %d", str1, &valeur);
         printf("%s %d", str1, &valeur")
    }
    fclose(fichier); // parce que le flux doit être fermer.
}
}

`
// aucun résultat

Cette methode ne serait pas la bonne car toutes les ecriture 
sont faite sur une seule ligne.

Alors essayons de segmenter la ligne 
par les virgules de délimitation de la structure de json.

alors:

`
#define Taille_MAX 100
#define DELIMS ":"

int main(){
CHAR *pc, *ps;
FILE* fichier = NULL;
char chaine[TAILLLE_MAX] = "";
int valeur;
char str1[100]
fichier = fopen("BCE.txt", "r");
if(fichier != NULL) // car le fichier doit exister
{
    while(fgets(chaine, TAILLLE_MAX, fichier)!= NULL) tant qu'il y a pas d'erreur
    {
        //ici on fait la délimitation avec la méthode strtok définie dans le string.h.
    }
    fclose(fichier); // parce que le flux doit être fermer.
}
}
`

Pourquoi j'ai choisi cette méthode , parceque le prof dit dans le cours que c'est une bonne solution
pour récupérer des données dans un fichier. 

exemple d'utilisation avec le format json:
`
#include <stdio.h>
#define TAILLE_MAX 100
#include <string.h>
#define DELIMS "," //delimitation sur les virgules
#define DELIM ":" // après délimitation sur les deux points

int main(){
char s[80];
char *pc, *ps; // pc stocke temporaiment les chaines entre le virgules puis ps temporaiment stocke les chaines entre les deux points.
char *str1[100]; //  stocke les chaines entre le virgules

strcpy(s, "{\"nom\":\"dioum\",\"age\":23,\"prenom\":\"mapenda\"}");  // définition d'un exemple de format json

// delimitation sur virgule et stokcker dans dans le tableau str1;
pc=strtok(s,DELIMS);
int i=0;
while (pc != NULL)
{
//printf("%s\n", pc);
str1[i]=pc;
i++;// la taille du tableau str1.
pc = strtok(NULL, DELIMS);
}

char *str2[100]; // stocke les chaines en les deux point .
int k=0;
for(int j=0; j<i; j++){
ps=strtok(str1[j], DELIM);
while(ps != NULL){
str2[k]=ps; // stokage
k++;
//printf("%s\n", ps);
ps = strtok(NULL , DELIM);
}
}

//ici on recupere la valeur de l'age , ce qui donne 23.
//on peut meme stoker cette valeur dans une variable nommmé age de type int. 
for (int l=0; l<k ; l++){
//if(strcmp(str2[l],"\"age\"")==0){
printf("%s",str2[l]);
}
}
return 0;
}
`
//resultat:
{"nom"
"dioum"
"age"
"23"
"prenom"
"mapenda"}

on voit que chaque donnée , sa valeur est à la ligne suivante.

c'est ainsi que nous allons traiter un fichier json pour récuperer les valeurs.
par exemple pour le BCE.json.
`
#include <stdio.h>
#define TAILLE_MAX 100
#include <string.h>
#define DELIMS ","
#define DELIM ":"

int main(){
//char s[80];
FILE* fichier = NULL;
char *pc, *ps;
char *str1[100];
char chaine[TAILLE_MAX]="";
int valeur;
//char *str2[100];
fichier =fopen("BCE.json", "r");
if(fichier != NULL)
{
  while(fgets(chaine , TAILLE_MAX , fichier) != NULL)
  {
  pc= strtok(chaine, DELIMS);
  int i=0;
  while(pc != NULL)
  {
   str1[i] = pc;
   i++;
   pc = strtok(NULL, DELIMS);
  }
  char* str2[100];
  int k=0;
  for(int j=0 ; j < i ; j++){
  ps= strtok(str1[j] , DELIM);
  while(ps != NULL){
  str2[k]=ps;
  k++;
  ps = strtok(NULL, DELIM);
  }
  }
  for(int l = 0 ; l < k ; l++){
  printf("%s\n",str2[l]);
  }
  }
  fclose(fichier);
}

// le resultat c'est:
{"quoteResponse"
{"result"
[{"language"
"en-US"
"region"
"US"
"quoteType"
"EQUITY"
"quoteSourceName
"
"Delayed Quote"
"triggerable"
true
"currency"
"CAD"
"marketState"
"CLOSED"
"exchange"
"TOR"
"shor
tName"
"BCE INC."
"longName"
"BCE Inc."
"messageBoardId"
"finmb_170260"
"exchangeTimezoneName"
"Ame
rica/Toronto"
"exchangeTimezoneShortName"
"EST"
"gmtOffSetMilliseconds"
-18000000
"market"
"ca_mark
et"
"esgPopulated"
false
"regularMarketChange"
-0.7200012
"regularMarketChangePercent"
-1.2921773
"
regularMarketTime"
1613768400
"regularMarketPrice"
55.0
"regularMarketDayHigh"
55.75
"regularMarket
DayRange"
"54.855 - 55.75"
"regularMarketDayLow"
54.855
"regularMarketVolume"
8584387
"regularMarke
tPreviousClose"
55.72
"bid"
54.92
"ask"
55.0
"bidSize"
0
"askSize"
0
"fullExchangeName"
"Toronto"
"
financialCurrency"
"CAD"
"regularMarketOpen"
55.69
"averageDailyVolume3Month"
3354855
"averageDaily
Volume10Day"
4181466
"fiftyTwoWeekLowChange"
8.970001
"fiftyTwoWeekLowChangePercent"
0.19487295
"fi
ftyTwoWeekRange"
"46.03 - 64.36"
"fiftyTwoWeekHighChange"
-9.360001
"fiftyTwoWeekHighChangePercent"
-0.14543195
"fiftyTwoWeekLow"
46.03
"fiftyTwoWeekHigh"
64.36
"dividendDate"
1618444800
"earningsTi
mestamp"
1612422027
"earningsTimestampStart"
1620217800
"earningsTimestampEnd"
1620649800
"trailing
AnnualDividendRate"
3.33
"trailingPE"
19.927536
"trailingAnnualDividendYield"
0.0597631
"epsTrailin
gTwelveMonths"
2.76
"epsForward"
3.39
"epsCurrentYear"
3.14
"priceEpsCurrentYear"
17.515923
"shares
Outstanding"
904400000
"bookValue"
18.782
"fiftyDayAverage"
55.281765
"marketCap"
49742000128
"firs
tTradeDateMilliseconds"
831389400000
"priceHint"
2
"fiftyDayAverageChange"
-0.28176498
"fiftyDayAve
rageChangePercent"
-0.005096888
"twoHundredDayAverage"
55.847298
"twoHundredDayAverageChange"
-0.84
729767
"twoHundredDayAverageChangePercent"
-0.015171686
"forwardPE"
16.224188
"priceToBook"
2.92833
57
"sourceInterval"
15
"exchangeDataDelayedBy"
15
"tradeable"
false
"symbol"
"BCE.TO"}]
"error"
nul
l}}
`
Avec ce résultat je peux en tirer les donnée que je souhaite avec strcmp dans le dernier boucle for. 

`
#define Taille_MAX 100
FILE* fichier = NULL;
char chaine[TAILLLE_MAX] = "";
#include <string.h>
#define DELIMS "," //delimitation sur les virgules
#define DELIM ":" // après délimitation sur les deux points

fichier = fopen("indice.txt", "r");

if(fichier != NULL) // car le fichier doit exister
{
    while(fgets(chaine, TAILLLE_MAX, fichier)!= NULL) //tant qu'il y a pas d'erreur
    {
                    char *pc, *ps; // pc stocke temporaiment les chaines entre le virgules puis ps temporaiment stocke les chaines entre les deux points.
                    char *str1[100]; //  stocke les chaines entre le virgules

                    strcpy(s, "{\"nom\":\"dioum\",\"age\":23,\"prenom\":\"mapenda\"}");  // définition d'un exemple de format json

                    // delimitation sur virgule et stokcker dans dans le tableau str1;
                    pc=strtok(chaine,DELIMS);
                    int i=0;
                    while (pc != NULL)
                    {
                    //printf("%s\n", pc);
                    str1[i]=pc;
                    i++;// la taille du tableau str1.
                    pc = strtok(NULL, DELIMS);
                    }

                    char *str2[100]; // stocke les chaines en les deux point .
                    int k=0;
                    for(int j=0; j<i; j++){
                    ps=strtok(str1[j], DELIM);
                    while(ps != NULL){
                    str2[k]=ps; // stokage
                    k++;
                    //printf("%s\n", ps);
                    ps = strtok(NULL , DELIM);
                    }
                    }

                    //ici on recupere la valeur de l'age , ce qui donne 23.
                    //on peut meme stoker cette valeur dans une variable nommmé age de type int. 
                    for (int l=0; l<k ; l++){
                    if(strcmp(str2[l],"\"age\"")==0){
                    printf("%s",str2[++l]);
                    }
                    }
 }
    fclose(fichier); // parce que le flux doit être fermer.
}
`

maintenant il reste à remplacer ce bout de code:  strcpy(s, "{\"nom\":\"dioum\",\"age\":23,\"prenom\":\"mapenda\"}");  par la lecture
des fichier json dans un boucle.
voici le code:


`
#include <stdbool.h>
#include <stdio.h>
#define TAILLE_MAX 100
#include <string.h>
#define DELIMS ","
#define DELIM ":"

int main(){
//char s[80];
float fiftyTwoWeekLow;
float trailingAnnualDividendYield;
float regularMarketPrice;
float fiftyTwoWeekHigh;

FILE* fichier = NULL;
FILE* fichier1 = NULL;
char *pc, *ps;
char *str1[100];
char chaine[TAILLE_MAX]="";
char chaine1[TAILLE_MAX]="";
    
    
fichier = fopen("data/indice.txt" , "r");
if(fichier != NULL){
while(fgets(chaine1 , TAILLE_MAX , fichier)!=NULL)
{
fiftyTwoWeekLow =0 ;
fiftyTwoWeekHigh = 0;
trailingAnnualDividendYield = 0;
regularMarketPrice = 0;

//recupérer le nom du fichier sans le caractere '\n'
size_t size = strlen(chaine1)-1;
char chai[TAILLE_MAX] = "";
strncat(chai , chaine1 , size);
printf("%s  " , chai);
//chemin vers le fichier json
strcpy(chai,"");
strcat(chai,"data/");
strncat(chai ,chaine1,size);
strcat(chai , ".json");

fichier1 = fopen( chai, "r");
if(fichier1 != NULL)
{
char chaine2[2000]="";
  while(fgets(chaine , TAILLE_MAX , fichier1) != NULL)
  {
  strcat(chaine2 , chaine);
  }
  //printf("%s", chaine2);
  pc= strtok(chaine2, DELIMS);
  int i=0;
  while(pc != NULL)
  {
   str1[i] = pc;
   //printf("%s\n",pc);
   i++;
   pc = strtok(NULL,DELIMS);
 } 

  
  char* str2[100];
  int k=0;
  for(int j=0 ; j < i ; j++){
  ps= strtok(str1[j],DELIM);
  while(ps != NULL){
  str2[k]=ps;
  k++;
  ps = strtok(NULL,DELIM);
  }
  }
 
 }
 }
}
  fclose(fichier1);

return 0;
}
`

De ce fait les valeurs seront enrégistrer lors de chaque itération dans str2.
Dans ce cas avant de sortir de la boucle , on recupere et affiche les valeurs dans ces fichiers.



Comme il a été prévu , après la detection d'une variable (par exemple fiftyTwoWeekLow) dans le tableau à
l'indice l alors sa valeur est dans l'indice l+1.

`
  for(int l = 0 ; l < k ; l++){
  if(strcmp(str2[l],"\"fiftyTwoWeekLow\"")==0)
  {
   sscanf(str2[++l], "%f" , &fiftyTwoWeekLow);
  }
  else if(strcmp(str2[l], "\"fiftyTwoWeekHigh\"")==0)
  {
   sscanf(str2[++l],"%f" ,&fiftyTwoWeekHigh);
  }
  else if(strcmp(str2[l], "\"regularMarketPrice\"")==0){
   sscanf(str2[++l] , "%f" , &regularMarketPrice);
  }
  else if(strcmp(str2[l], "\"trailingAnnualDividendYield\"")==0){
   sscanf(str2[++l] , "%f" , &trailingAnnualDividendYield);
  }
 }

` 


Puis j'applique la formule indiqué et afficher:

`
 float cx= 1 - ((double)((int)(1000*(fiftyTwoWeekHigh - regularMarketPrice)))/(int)(1000*(fiftyTwoWeekHigh - fiftyTwoWeekLow)));
  int pourt = (int)(100*cx);
  if(pourt <= 25 ){
  printf("c-1  ");
  }else if(pourt <= 50){
  printf("c-2  ");
  }else if(pourt <= 75){
  printf("c-3  ");
  }else{
  printf("c-4  ");
  }
  float dividend=100*trailingAnnualDividendYield;

  if(dividend <= 3){
  printf("DIV-1  ");
  }else if(dividend <= 6){
  printf("DIV-2  ");
  }else{
  printf("DIV-3  ");
  }

  printf("%.2f  " , regularMarketPrice);
  printf("%.2f%%\n", dividend);

`

Tous ceci se déroule dans chaque itération. 

apres j'obtiens ça :

`
#include <stdbool.h>
#include <stdio.h>
#define TAILLE_MAX 100
#include <string.h>
#define DELIMS ","
#define DELIM ":"

int main(){
float fiftyTwoWeekLow;
float trailingAnnualDividendYield;
float regularMarketPrice;
float fiftyTwoWeekHigh;

FILE* fichier = NULL;
FILE* fichier1 = NULL;
char *pc, *ps;
char *str1[100];
char chaine[TAILLE_MAX]="";
char chaine1[TAILLE_MAX]="";
    
    
fichier = fopen("data/indice.txt" , "r");
if(fichier != NULL){
while(fgets(chaine1 , TAILLE_MAX , fichier)!=NULL)
{
fiftyTwoWeekLow =0 ;
fiftyTwoWeekHigh = 0;
trailingAnnualDividendYield = 0;
regularMarketPrice = 0;

//recupérer le nom du fichier sans le caractere '\n'
size_t size = strlen(chaine1)-1;
char chai[TAILLE_MAX] = "";
strncat(chai , chaine1 , size);
printf("%s  " , chai);
//chemin vers le fichier json
strcpy(chai,"");
strcat(chai,"data/");
strncat(chai ,chaine1,size);
strcat(chai , ".json");

fichier1 = fopen( chai, "r");
if(fichier1 != NULL)
{
char chaine2[2000]="";
  while(fgets(chaine , TAILLE_MAX , fichier1) != NULL)
  {
  strcat(chaine2 , chaine);
  }
  //printf("%s", chaine2);
  pc= strtok(chaine2, DELIMS);
  int i=0;
  while(pc != NULL)
  {
   str1[i] = pc;
   //printf("%s\n",pc);
   i++;
   pc = strtok(NULL,DELIMS);
 } 

  
  char* str2[100];
  int k=0;
  for(int j=0 ; j < i ; j++){
  ps= strtok(str1[j],DELIM);
  while(ps != NULL){
  str2[k]=ps;
  k++;
  ps = strtok(NULL,DELIM);
  }
  }
  for(int l = 0 ; l < k ; l++){
  if(strcmp(str2[l],"\"fiftyTwoWeekLow\"")==0)
  {
   sscanf(str2[++l], "%f" , &fiftyTwoWeekLow);
  }
  else if(strcmp(str2[l], "\"fiftyTwoWeekHigh\"")==0)
  {
   sscanf(str2[++l],"%f" ,&fiftyTwoWeekHigh);
  }
  else if(strcmp(str2[l], "\"regularMarketPrice\"")==0){
   sscanf(str2[++l] , "%f" , &regularMarketPrice);
  }
  else if(strcmp(str2[l], "\"trailingAnnualDividendYield\"")==0){
   sscanf(str2[++l] , "%f" , &trailingAnnualDividendYield);
  }
 }
  fclose(fichier1);
  float cx= 1 - ((double)((int)(1000*(fiftyTwoWeekHigh - regularMarketPrice)))/(int)(1000*(fiftyTwoWeekHigh - fiftyTwoWeekLow)));
  int pourt = (int)(100*cx);
  if(pourt <= 25 ){
  printf("c-1  ");
  }else if(pourt <= 50){
  printf("c-2  ");
  }else if(pourt <= 75){
  printf("c-3  ");
  }else{
  printf("c-4  ");
  }
  float dividend=100*trailingAnnualDividendYield;

  if(dividend <= 3){
  printf("DIV-1  ");
  }else if(dividend <= 6){
  printf("DIV-2  ");
  }else{
  printf("DIV-3  ");
  }

  printf("%.2f  " , regularMarketPrice);
  printf("%.2f%%\n", dividend);
  }
  }
  fclose(fichier);
  } 
  return 0;
}
`

comment récuperer les flux d'entrer pour vérifier tous cas de commande test ?

`
flux= stdin;
if(flux == NULL){
flux= fopen("data/indices.txt" , "r");
}
if(flux != NULL){
while(fgets(chaine1 , TAILLE_MAX , flux)!=NULL)
{
fiftyTwoWeekLow =0 ;
fiftyTwoWeekHigh = 0;
trailingAnnualDividendYield = 0;
regularMarketPrice = 0;
...
...
...

`