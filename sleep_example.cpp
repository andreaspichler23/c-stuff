#include<stdio.h>
#include <iostream>         
#include <unistd.h>         

using namespace std;

int main(){

int count = 0;

while(-1){
  count++;
  printf("hello world %d\n", count);

sleep(1); // in seconds
}

return 0;
}
