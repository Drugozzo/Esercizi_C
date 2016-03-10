#include <stdio.h>

typedef struct {
	float x,y;
}Punto;

typedef struct {
	Punto p1,p2;
}Rettangolo;

typedef enum { FALSO , VERO } Bool;

Rettangolo creaRet(Punto p1, Punto p2);
void stampaRet(Rettangolo *r);
int areaRet(Rettangolo *r);
void centro(Rettangolo *r);
void trasla(Rettangolo *r);
Bool cade(Punto p, Rettangolo *r);

int main(void){
	
	Rettangolo r;
	Punto p1,p2,p;
	Bool b;

	printf("Rettangolo\n");
	printf("inserisci il primo punto:\n");
	printf("x: ");
	scanf("%f",&p1.x);
	printf("y: ");
	scanf("%f",&p1.y);
	printf("inserisci il secondo punto:\n");
	printf("x: ");
	scanf("%f",&p2.x);
	printf("y: ");
	scanf("%f",&p2.y);

	r=creaRet(p1,p2);

	stampaRet(&r);

	printf("area: %d\n", areaRet(&r));

	centro(&r);

	printf("inserisci un punto p\n");
	printf("x: ");
	scanf("%f",&p.x);
	printf("y: ");
	scanf("%f",&p.y); 

	b=cade(p,&r);

	printf("%d\n",b);


	return 0;
}

Rettangolo creaRet(Punto p1, Punto p2){
	Rettangolo r;
	r.p1.x=p1.x;
	r.p1.y=p1.y;
	r.p2.x=p2.x;
	r.p2.y=p2.y;
	return r;
}

void stampaRet(Rettangolo *r){
	printf("Stampa rettangolo\np1.x: %.02f, p1.y: %.02f\np2.x: %.02f, p2.y: %.02f\n", r->p1.x,r->p1.y,r->p2.x,r->p2.y);
}

int areaRet(Rettangolo *r){
	int a;
	a=((r->p1.x - r->p2.x)*(r->p1.y - r->p2.y));
	if(a<0)
		a=-a;
	return a;
}

void centro(Rettangolo *r){
	Punto p;
	float x,y;
	
	x=(r->p1.x - r->p2.x)/2;
	if(x<0){
		x=-x;
		x=x+r->p1.x;
	}else{
		x=x+r->p2.x;
	}

	y=(r->p1.y - r->p2.y)/2;
	if(x<0){
		y=-y;
		y=y+r->p1.y;
	}else{
		y=y+r->p2.y;
	}

	p.x=x;
	p.y=y;

	printf("centro x: %.02f, y: %.02f\n", p.x,p.y);


}

void trasla(Rettangolo *r){
	float x,y;

	printf("x da traslare: ");
	scanf("%f",&x);
	printf("y da traslare: ");
	scanf("%f",&y);

	r->p1.x = r->p1.x+x;
	r->p2.x = r->p2.x+x;
	r->p1.y = r->p1.y+y;
	r->p2.y = r->p2.y+y; 

	printf("Stampa rettangolo traslato\np1.x: %.02f, p1.y: %.02f\np2.x: %.02f, p2.y: %.02f\n", r->p1.x,r->p1.y,r->p2.x,r->p2.y);

}

Bool cade(Punto p, Rettangolo *r){
	Bool b = VERO;

	if(r->p1.x < r->p2.x){
		if(r->p1.y < r->p2.y){
			if(!(p.x>=r->p1.x && p.x<=r->p2.x && p.y>=r->p1.y && p.y<=r->p2.y))
				b=FALSO;
		}else{
			if(!(p.x>=r->p1.x && p.x<=r->p2.x && p.y>=r->p2.y && p.y<=r->p1.y))
				b=FALSO;
		}
	}else{
		if(r->p1.y < r->p2.y){
			if(!(p.x>=r->p2.x && p.x<=r->p1.x && p.y>=r->p1.y && p.y<=r->p2.y))
				b=FALSO;
		}else{
			if(!(p.x>=r->p2.x && p.x<=r->p1.x && p.y>=r->p2.y && p.y<=r->p1.y))
				b=FALSO;
		}
	}

	return b;
}
