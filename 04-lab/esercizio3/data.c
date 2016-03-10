#include <stdio.h>

#define N 100
#define L 3

int main(void){
	
	int seq[N][L],g,m,h,i,j,cambio=0;

	for(i=0;i<N;i++){
		printf("giorno: ");
		scanf("%d",&g);
		printf("mese: ");
		scanf("%d",&m);
		printf("anno: ");
		scanf("%d",&h);
		if(g==00 && m==00 && h==0000)
			break;
		else{
			seq[i][0]=g;
			seq[i][1]=m;
			seq[i][2]=h;
		}
	}

	for(j=1,g=seq[0][0],m=seq[0][1],h=seq[0][2];j<i;j++){
		if(seq[j][2]<h){
			cambio=1;
		}else{
			if(seq[j][2]==h && seq[j][1]<m){
				cambio=1;	
			}else{
				if(seq[j][1]==m && seq[j][0]<g){
					cambio=1;
				}
			}
		}
		if(cambio){
			g=seq[j][0];
			m=seq[j][1];
			h=seq[j][2];
		}else
			cambio=0;
	}

	printf("data piu recente: %02d/%02d/%04d\n",g,m,h);

	return 0;
}