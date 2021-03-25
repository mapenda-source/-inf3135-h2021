#include <stdio.h>

enum Nombre_e {
    INT, FLOAT, DOUBLE
};

typedef struct {           // Un nombre
    enum Nombre_e type;  // Le type de nombre
    union {
        int i;
        float f;
        double d;
    } valeur;              // La valeur
} Nombre_t;


Nombre_t max(Nombre_t a, Nombre_t b);

int main(){
enum Nombre_e a = 10000;
printf("%d" , a);   
}


Nombre_t max(Nombre_t a, Nombre_t b){
if(a.type > b.type && a.valeur.d + a.valeur.f + a.valeur.i > b.valeur.d + b.valeur.f + b.valeur.i){
    return a;
}else{
    return b;
}
}