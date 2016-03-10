#include <stdio.h>


typedef struct{
	int x,y;
}Punto;

typedef struct {
	Punto p1,p2;
}Rettangolo;

typedef struct{
	Punto p;
	int r;
}Cerchio;

int main(void){

	Rettangolo r;
	Cerchio c;
	int b,h;

	printf("Rettangolo\n");
	printf("x1: ");
	scanf("%d",&r.p1.x);
	printf("y1: ");
	scanf("%d",&r.p1.y);
	printf("x2: ");
	scanf("%d",&r.p2.x);
	printf("y2: ");
	scanf("%d",&r.p2.y);

	printf("Cerchio\n");
	printf("x: ");
	scanf("%d",&c.p.x);
	printf("y: ");
	scanf("%d",&c.p.y);
	printf("r: ");
	scanf("%d",&c.r);
	b=r.p1.x-r.p2.x;
	if(b<0)
		b=-b;
	h=r.p1.y-r.p2.y;
	if(h<0)
		h=-h;

	printf("Area Rettangolo: %d\n",h*b);
	printf("Perimetro: %d\n",(b+h)*2);

	printf("Area cerchio: %.2f\n",(c.r*c.r*3.14));
	printf("Circonferenza: %.2f\n",(2*c.r*3.14));
	

	return 0;
}