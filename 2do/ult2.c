#include <stdio.h>
#include <stdlib.h>

void geometrica(){
	int n, i, j;
	float sum, k, potencia;
	sum=0;
	printf("\nn=?\n___\n\\    __1__\n/__  (k)^i\ni=0\n");
	printf("\n(no es recomendable usar un n demasiado grande)\nNumero de terminos para n: ");
	scanf("%d", &n);
	printf("\nValor de k: ");
	scanf("%f",&k);
	for (i = 0; i <= n; i++){
		potencia=k;
		for(j=1;j<i;j++)potencia=potencia*k;
		if (i==0)potencia=1;
		sum+=1.0/potencia;
	}
	printf("\nEl resultado es: %f\n", sum);
}

void armonica(){
	int i, n;
	float sum;
	sum=0;
	printf("\nn=?\n___\n\\    _1_\n/__   n\ni=1\n");
	printf("\nNumero de terminos para n: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum+=1.0/i;
	}
	printf("\nEl resultado es: %f\n", sum);
}

int main(){
	printf("\nPrograma que calcula la suma para series de forma geometrica o armonioca\n");
	int opc;
	while(1){
		printf("\n1. Serie geometrica\n");
		printf("2. Serie armonica\n");
		printf("3. Salir\n");
		printf("\nEliga una opcion: ");
		scanf("%d", &opc);

		switch(opc)
		{
			case 1:
			geometrica();
			break;
			case 2:
			armonica();
			break;
			case 3:
			printf("\nHasta luego :D");
			exit(0);
			break;
			default:
			printf("\n<Opcion no valida>\n");
		}
	}
	return 0;
}