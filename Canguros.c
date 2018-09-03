#include <stdio.h>
int main(int argc, char *argv[]) {
	int C,N;
	int	v[1000000],cn=0,t=0;
	char l;
	scanf("%d" "%d",&C,&N);
	while(N!=0){
		scanf("%c",&l);
		switch(l){
		case 'A':
			C=C-v[0];
			for(int i=0;i<(t-1);i++){
				v[i]=v[i+1];
			}
			t--;
			cn--;
			N--;
			break;
		case 'C':
			printf("%i\n",t);
			N--;
			break;

		case 'N':
			scanf("%d",&v[cn]);
			v[cn]++;
			cn++;
			t++;
			N--;
			break;
		case 'R':
			printf("%i\n",C);	
			N--;
			break;
		}       
	}
	return 0;
}
