#include <stdio.h>

int main(void){
	
	int h1,m1,s1,h2,m2,s2,h,m,s;

	printf("primo orario\n");
	printf("hh: ");
	scanf("%d",&h1);
	printf("mm: ");
	do{
		scanf("%d",&m1);
	}while(m1>=60);
	printf("ss: ");
	do{
		scanf("%d",&s1);
	}while(s1>=60);

	printf("secondo orario\n");
	printf("hh: ");
	scanf("%d",&h2);
	printf("mm: ");
	do{
		scanf("%d",&m2);
	}while(m2>=60);
	printf("ss: ");
	do{
		scanf("%d",&s2);
	}while(s2>=60);

	if(s1<s2){
		s=(s1+10)-s2;
		m1--;
	}else
		s=s1-s2;

	if(m1<m2){
		m=(m1+10)-m2;
		h1--;
	}else
		m=m1-m2;

	h=h1-h2;

	if(h<0)
		h=-h;

	printf("%d:%d:%d\n",h,m,s);



	return 0;
}