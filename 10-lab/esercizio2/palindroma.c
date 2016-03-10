#include <stdio.h>
#include <string.h>

void palindroma(char *s);

int main(int argc, char **argv){
	
	char **p;

	for(p=argv+1;p<argv+argc;p++)
		palindroma(p[0]);

	printf("\n");
	
	return 0;
}

//aladin.unimi.it

void palindroma(char *s){
	char *q,*r;
	int pal=1;

	for(q=s,r=s+strlen(s)-1;q<s+(strlen(s)/2);q++,r--){
		if(*q!=*r){
			pal=0;
			break;
		}
	}

	(pal==1)?(printf("%s è palindroma\n",s)):(printf("%s non è palindroma\n",s ));
}
