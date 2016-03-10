#include <stdio.h>
#include <string.h>

void smallest_largest( char *s[], int n, char **min, char **max );

int main(int argc, char **argv){
	
	char *min,*max;

	int i;

	smallest_largest(argv,argc,&min,&max);

	printf("min: %s\nmax: %s\n",&min[0],&max[0]);

	return 0;
}

void smallest_largest( char *s[], int n, char **min, char **max ){
	int i;

	for(i=2,*min=s[1],*max=s[1];i<n;i++){
		if(strcmp(s[i],*min)<0)
			*min=s[i];
		else{
			if(strcmp(s[i],*max)>0)
				*max=s[i];
		}
	}
}
