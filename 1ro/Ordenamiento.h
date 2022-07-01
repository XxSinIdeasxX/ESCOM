void Bubble(int a[],int n){
	int i,j,t;
	for(j=0;j<n-1;j++)
		for(i=n-1;i>j;i--)
			if(a[i]<a[i-1]){
				t=a[i];a[i]=a[i-1];a[i-1]=t;
			}
}
void QuickSort(int a[], int n){
	int p;
	if (n>1){
        p=Particion(a,n);
		QuickSort(a, p);
		QuickSort(a+p+1, n-p-1);
	}
}
int Particion(int a[], int n){
	int p=0, q=1, k=0, m=0;

	while((p<(n-1))&&(q<n)){
        while((q<n)&&(a[p]<a[q]))
            q++;
        if(q<n){
            m=a[q];
            for(k=q;k>p;k--)
                a[k]=a[k-1];
            a[p]=m;
            p++; q=p+1;
        }
	}
	return p;
}


