
#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>

int main(){
    int x=1,p;
    p=fork();
    if(p==0)
      x=10;
      else{
        wait(NULL);
        printf("%d\n",x);
      }
}