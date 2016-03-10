#include <stdio.h>

int main(void){
	
	int n=500,d=250;
	char c;
	
	do{
		printf("il numero è %d? ",n);
		scanf("%c",&c);
		
		if(c==60)	//minore
			n=d-1;
		else{
			if(c==62){
				n=n+d;	
			}
		}
		if(c=='=')
			break;
		d=d/2;
		do c=getchar(); while(c!='\n');
	}while(1);
	return 0;

}