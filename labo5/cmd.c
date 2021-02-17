#include <stdio.h>
#include <string.h>

int main(int argc , char* argv[] ){
printf("----ExempleA------\n");
for(int i= 0 ; i < argc ; i++){
//int taille = sizeof(argv)/sizeof(char*);
printf("arg[%d]: %s\n" , i , argv[i]);
}

printf("----ExempleB-----\n");

for (int i = argc-1 ; i >0 ; i--){
printf("%s ", argv[i]);
}
printf("\n");

printf("----ExempleC-----\n");

for(int i= argc-1 ; i>0 ; i--){
   int taille =(int)sizeof(argv[i])/sizeof(argv[i][0]);
   for(int j = taille-1 ; j >= 0 ; j--){
   printf("%c", argv[i][j]);
   }
   printf(" ");
}

printf("\n");

return 0;
}
