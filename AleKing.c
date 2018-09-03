#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int a,*b,op,i,j,aux,m;
	scanf("%d",&a);
	b=(int*)malloc(a*sizeof(int));
	for(int i=0;i<a;i++){
		scanf("%d",&b[i]);
	}
	scanf("%d",&op);
	switch(op){
	case 1:
		for(int i=a-1;i>=0;i--){
			printf("%d ",b[i]);
		}
		break;
	case 2:
		for(j=0;j<a;j++){
			printf("%d ",b[j]);
		}
		break;
	case 3:
		for(i=0;i<a;i++){
			m=i;
			for(j=i+1;j<a;j++){
				if(b[j]<b[m]){
					m=j;
				}
			}
			aux=b[i];
			b[i]=b[m];
			b[m]=aux;
		}
		for(i=a-1;i>=0;i--){
			printf("%d ",b[i]);
		}
		break;
	default:
		break;
	}
	
	return 0;
}

