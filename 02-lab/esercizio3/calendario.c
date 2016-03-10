#include <stdio.h>

int main(void){
	
	int g,m,j,i,count=0,max;

	printf("Inserisci il numero del mese (1 = gennaio, ···, 12 = dicembre): ");
	scanf("%d",&m);
	printf("Inserisci il giorno di inizio mese (1 = lunedi, ···, 7 = domenica): ");
	scanf("%d",&g);

	if(m==4 || m==6 || m==9 || m==11)
		max = 30;
	else{
		if(m==2)
			max =28;
		else
			max=31;
	}
	printf("L   M   M   G   V   S   D\n");

	for(i=0;i<max;i++){
		for(j=1;j<=7;j++){
			if(j<=(g-1) && count==0)
				printf("    ");
			else{
				count++;
				printf("%2d  ",count);
				if(count>=max){
					app=1;
					break;
				}  
			}				
		}
		if(app==1) break;
		printf("\n");
	};

	printf("\n");
	return 0;

}