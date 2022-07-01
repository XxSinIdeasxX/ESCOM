#include <stdio.h>
#include <math.h>

int main(){

  for(int C=2;C<=100;C++){
    double raiz=sqrt((double)C);
    int aux=2;
    while(1){
      if (aux<=raiz){
        if(C%aux==0){
          break;
        }
        else{
          aux++;
        }
      }
      else{
        printf("%d\n",C);
        break;
      }
    }
  }
return 0;
}
