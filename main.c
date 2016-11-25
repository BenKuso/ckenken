#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int respuesta(int n);

//Bloque Principal
int main(){
	int n;
	printf("Ingrese el orden de la matriz:\n");
	scanf("%d",&n);
	respuesta(n); //llamando a la funcion "respuesta"
	getch();
}

//Implementaciones
int respuesta(int n){
	int matriz[n][n], posible, bandera;
	
	for(int i=0; i<n; i++){ //llena la matriz en ceros
		for(int j=0; j<n; j++){
			matriz[i][j]=0;
		}
	}
	
	srand(time(NULL));  
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			bandera=1;
			while(bandera==1){
				posible=1+rand()%n;
				for(int k=0; k<n; k++){
					if(posible==matriz[k][j]){
						bandera=1;
						break;
					}else{
						bandera=0;
					}
				}
				if(bandera==0){
					for(int l=0; l<n; l++){
						if(posible==matriz[i][l]){
							bandera=1;
							break;
						}else{
							bandera=0;
						}
					}
				}
			}
			matriz[i][j]=posible;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("[%d]",matriz[i][j]);
		}
		printf("\n");
	}
}
