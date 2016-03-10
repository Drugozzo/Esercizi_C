#include <stdio.h>

#define N 100

int main(void){
	
	char c, a[N];
	int i=0, k,j;

	scanf("%d",&k);

	while((c=getchar())!='.'){
		a[i]=c;
		i++;
	}

	for(j=0;j<i;j++){
		if(a[j]>=65 && a[j]<=90){
			if(a[j]+k>90)
				a[j]=(a[j]+k)-91+65;
			else
				a[j]=a[j]+k;
		}else{
			if(a[j]>=97 &&a[j]<=122){
				if(a[j]+k>122)
					a[j]=(c+k)-123+97;
				else
					a[j]=a[j]+k;
			}
		}
		printf("%c",a[j]);
	}

	printf("\n");

	return 0;
}