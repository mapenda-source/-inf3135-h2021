#include <stdio.h>

int estTrie(int _a[] , unsigned long _size);

int main(){
int tab [] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};

unsigned long size = sizeof(tab)/sizeof(int);

int ret = estTrie(tab, size);

printf("%d\n", ret);
}


int estTrie(int _a[] , unsigned long _size){

for(int i = 0 ; i < _size-1 ; i++){
  if(_a[i]>_a[i+1]){
  return 20;
  }
 }
return 1;
}
