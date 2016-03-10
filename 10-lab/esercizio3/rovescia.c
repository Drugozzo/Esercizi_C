#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int *a, n=2 ,*p, c,*q,cont=0;

	scanf("%d",&c);
	switch(c){

		case 1:
		scanf("%d",&n);
		a=malloc(n*sizeof(int));

		for(p=a;p<a+n;p++){
			scanf("%d",p);
		}
		
		for(p--;p>=a;p--)
			printf("%d ",*p );
		break;

		case 2:
		a=malloc(n*sizeof(int));
		p=a;
		scanf("%d",&c);
		
		while(c!=0){
			printf("n: %d\n",n );
			*p=c;
			if((p+1)>=a+n){
				n*=2;
				printf("n size: %lu\n", n*sizeof(int));
				a=realloc(a,n*sizeof(int));
				p=a+cont;
			}
			p++;
			cont++;

			scanf("%d",&c);
			
		}

		for(q=a,p=p-1;p>q;p--)
			printf("%d ", *p);
		break;

		case 3:
		n=15;
		a=malloc(n*sizeof(int));
		p=a;

		scanf("%d",&c);

		while(c!=0){
			*p=c;
			if((p+1)>=a+n){
				n+=10;
				a=realloc(a,n*sizeof(int));
				p=a+cont;
			}
			p++;
			cont++;
			scanf("%d",&c);
		}
		for(q=a,p=p-1;p>q;p--)
			printf("%d ", *p);
		break;
	}

	printf("\n");

	return 0;
}
