#include <stdio.h>
#include <stdlib.h>

char *read_line( void );
char *read_word( void );

int main(void){

	printf("%s\n",read_line());
	printf("%s\n",read_word());



	return 0;
}

char *read_line( void ){
	int size=2,n=0;
	char *p,*temp,c;

	p=malloc(size*sizeof(int));

	while(1){
		c=getchar();
		if(c!='\n'){
			p[n++]=c;
			if(n>=size){
				size*=2;
				temp=realloc(p,size*sizeof(int));
				if(temp==NULL){
					break;
				}else{
					p=temp;
				}
			}
		}else{
			break;
		}
	}
	return p;
}

char *read_word( void ){
	int size=2,n=0;
	char *p,*temp,c;

	p=malloc(size*sizeof(int));

	while(1){
		c=getchar();
		if((c>=48 && c<=57) || (c>=65 && c<=90) || (c>=97 && c<=122)){
			p[n++]=c;
			if(n>=size){
				size*=2;
				temp=realloc(p,size*sizeof(int));
				if(temp==NULL){
					break;
				}else{
					p=temp;
				}
			}
		}else{
			break;
		}
	}
	return p;
}
