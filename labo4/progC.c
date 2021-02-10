#include <stdio.h>

int inverse(unsigned char _a[] , unsigned long _size);

int main (){

unsigned char tab[] = {0,2,3,47,5,43,3,2,6,90,12,34,65,6,89,8};

unsigned long size = sizeof(tab)/sizeof(char);

int ret = inverse(tab , size);

printf("%d\n", ret);
}


int inverse(unsigned char _a[] , unsigned long _size){
int i = 0;
int j = _size-1;

while(i < j){
int tmp = _a[i];
_a[i]=_a[j];
_a[j]= tmp;
i++;
j--; 
}
return _a[0];
}
