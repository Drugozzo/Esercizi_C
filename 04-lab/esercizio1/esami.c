#include <stdio.h>

int main(void){
	
	int a[5][5],i,j,n;
	float mediatot,m=0,media[5];
	for(i=0;i<5;i++){
		printf("studente %d\n",(i+1));
		for(j=0;j<5;j++){
			scanf("%d",&n);
			a[i][j]=n;
			m=m+n;
		}
		m=m/5;
		media[i]=m;
		m=0;
	}

	for(i=0;i<5;i++){
		printf("media %d: %.2f ",(i+1),media[i]);
		mediatot=mediatot+media[i];
	}

	printf("\nmediatot: %.2f\n", (mediatot/5));

	return 0;
}