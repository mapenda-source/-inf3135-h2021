#include <stdio.h>

int compte(int _a[] , unsigned long _size);

int main(){

int tab [] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};

unsigned long size = sizeof(tab)/sizeof(int);

int ret = compte(tab , size);

printf("%d\n" , ret);

}


int compte(int _a[] , unsigned long _size){
 int max = _a[0];
 for( int i = 0 ; i < _size ; i++){
   if(_a[i] > max){
    max = _a[i];
   }
 }

return max;
}
