void Burbuja(Elem a[],int n){
	int i,j;
	for(j=0;j<n-1;j++)
		for(i=n-1;i>j;i--)
			if(EsMenor(a[i], a[i-1]))
				Intercambia(a+i, a+i-1);
//				t=a[i];a[i]=a[i-1];a[i-1]=t;			
}
void OrdMezcla(Elem l[], int x){
	int n,m,i,j,k;
	n=x/2;
	m=x-n;
	Elem l1[n],l2[m];
	for(i=0;i<n;i++){l1[i]=l[i];}
	for(j=0;j<m;j++){l2[j]=l[j+n];}
	Burbuja(l1,n);
	Burbuja(l2,m);
	i=0;
	j=0;
	for(k=0;k<x;k++){
		if((j==m)||(i==n)){
			if(j==m){
				l[k]=l1[i];
				i++;
			}else{
				l[k]=l2[j];
				j++;
			}
		}else{
			if(EsMenor(l1[i],l2[j])){
				l[k]=l1[i];
				i++;
			}else{
				l[k]=l2[j];
				j++;
			}
		}
	}
}
void OrdInsercion(Elem a[],int n){
	Elem p[1];
	int i,j,k;
	for(i=1;i<n;i++){
		j=0;
		p[0]=a[i];
		while(EsMenor(a[j],a[i])){j++;}
		for(k=i-1;k>=j;k--){a[k+1]=a[k];}
		a[j]=p[0];
//		printf("\ni:%d j:%d - ",i,j);
//		ImpArreglo(a,n);
	}
}

