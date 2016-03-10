#include <stdio.h>
#include <string.h>

void smallest_largest( char *s[], int n, char **smallest, char **largest );

int main(void){
	
	char *s[]={"ciao","mi","chiamo","lorenzo","e","sono","un","gran","figo"};
	//char s[9][10]={"ciao","mi","chiamo","lorenzo","e","sono","un","gran","figo"};

	int n=9,i;
	char *min,*max;
	//char min, max;
	smallest_largest(s,n,&min,&max);
	printf("cacca\n");

	for(i=0;i<n;i++)
		printf("%s,%p \n", s[i],&s[i]);

	printf("\n");
	
	printf("%s\n",min);
	printf("%s\n",max);

	//printf("%p \n\n",min);
	return 0;


}

void smallest_largest( char *s[], int n, char **smallest, char **largest ){
	int i;
	for(i=1,*smallest=s[0];i<n;i++){
		//printf("s[i]: %s,\nsmallest: %s,\nstrcmp: %d\n\n",s[i],smallest[0],strcmp(s[i],*smallest));
		if(strcmp(s[i],*smallest)<0){
			//printf("%p=%p \n",smallest,&s[i]);
			*smallest=s[i];


		}
		//printf("%p\n",smallest );
		//printf("%p\n", largest);
	}

	for(i=1,*largest=s[0];i<n;i++){
		printf("s[i]: %s,\nlargest: %s,\nstrcmp: %d\n\n",s[i],largest[0],strcmp(s[i],*largest));
		if(strcmp(s[i],*largest)>0)
			*largest=s[i];
	}
		//printf("%p\n",*smallest );
		//printf("%p\n", *largest);
}
