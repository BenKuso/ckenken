#include <stdio.h>

void llenaCeros(int mat[15][15],int orden);
void cuboMagico(int mat[15][15],int orden);
void muestraCubo(int mat[15][15],int orden);
int pideOrden();
int main(){
	int orden,cubo[15][15];
	
	orden=pideOrden();
	llenaCeros(cubo,orden);
	cuboMagico(cubo,orden);
	muestraCubo(cubo,orden);
	
}
int pideOrden(){
	int orden;
	do{
		printf("Orden de tu cubo magico entre 3 y 15 ");
		scanf("%i",&orden);
	}while((orden<3 || orden>15)|| (orden%2==0));
	return orden;
}
void llenaCeros(int mat[15][15],int orden){
	for(int i=0;i<orden;i++)
	   for(int j=0;j<orden;j++)
	      mat[i][j]=0;
}
void cuboMagico(int mat[15][15],int orden){
	printf("\n\ngenera el cubo \n\n");
	int i=1,y,x,yant,xant;
	x=orden/2;
	y=0;
	xant=x;
	yant=y;
	mat[y][x]=i;
	while(i<(orden*orden)){
		i++;
		x++;
		y--;
		//comprobando si estoy en rango
		if(x==orden)
		   x=0;
		if(y==(-1))
		   y=orden-1;
		//verificar si la matriz esta vacia en la posicion calculada
		if(mat[y][x]!=0){
			x=xant;
			y=yant+1;
	    }
		mat[y][x]=i;	
		xant=x;
		yant=y;
		
	}
}
void muestraCubo(int mat[15][15],int orden){
	for(int i=0;i<orden;i++){
		for(int j=0; j<orden;j++){
			 printf("[%i]",mat[i][j]);
		}
		printf("\n");
	}
}
