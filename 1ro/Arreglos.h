void LeeArreglo(int a[], int n){
    int i;
    for (i=0; i<n;i++){
        scanf("%d",&a[i]);
    }
}
void ImpArreglo(int a[], int n){
    int i;
    for (i=0; i<n;i++)
         printf("%d ", a[i]);
    printf("\n");
}
void RandArreglo(int a[], int n){
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++)
        a[i]=rand();
}
void CopyArreglo(int a[],int b[],int n){
	int i;
	for(i=0;i<n;i++)
		b[i]=a[i];
}
