#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
int respuesta(int n);



//Bloque Principal
int main(){
	int n=0;
	printf("Ingrese el orden de la matriz:\n");
	scanf("%d",&n);
	if(n>2 && n<7){
		respuesta(n); //llamando a la funcion "respuesta"
	}else{
		printf("Este juego no est\240 dise\244ado para valores menores que 3 ni mayores que 6\n");
	}
	getch();
}



//Implementaciones
int respuesta(int n){
	int matriz[n][n], posible, bandera, contador=0, operacion, calculo, muestra[n][n], usuario[n][n], col, fil,valor,pregunta, iguales=0;
	for(int i=0; i<n; i++){ //llena las matrices en ceros.
		for(int j=0; j<n; j++){
			matriz[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){
			muestra[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){
			usuario[i][j]=0;
		}
	}
	srand(time(NULL));  
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			do{
				posible=(rand()%n)+1;	
				for(int k=0; k<n; k++){
					if(posible==matriz[k][j]){
						bandera=1;
						break;
					}else{
						bandera=0;
					}
				}
				if(bandera==0){
					contador++;
					for(int l=0; l<n; l++){
						if(posible==matriz[i][l]){
							if(contador==1000000){
								printf("Ooops intente de nuevo\n");
								bandera=0; 
								break;
							}else{
								bandera=1;
									break;
							}
							
						}else{
							bandera=0;
						}
					}
				}	
			}while(bandera==1);
			matriz[i][j]=posible;
		}
	}
	//kenken unsolved
	for(int i=0; i< 5; i++){
		printf("\n");
	}
	switch(n){
		case 3:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][0]+matriz[1][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]-matriz[1][0];
					operacion=45;
				}else{
					calculo=matriz[1][0]-matriz[0][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][0]*matriz[1][0];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]/matriz[1][0];
					operacion=47;
				}else{
					calculo=matriz[1][0]/matriz[0][0];
					operacion=47;
				}
			}
			muestra[0][0]=calculo;
			muestra[1][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][1]+matriz[0][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]-matriz[0][2];
					operacion=45;
				}else{
					calculo=matriz[0][2]-matriz[0][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][1]*matriz[0][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]/matriz[0][2];
					operacion=47;
				}else{
					calculo=matriz[0][2]/matriz[0][1];
					operacion=47;
				}
			}
			muestra[0][1]=calculo;
			muestra[0][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][1]+matriz[1][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]-matriz[1][2];
					operacion=45;
				}else{
					calculo=matriz[1][2]-matriz[1][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][1]*matriz[1][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]/matriz[1][2];
					operacion=47;
				}else{
					calculo=matriz[1][2]/matriz[1][1];
					operacion=47;
				}
			}
			muestra[1][1]=calculo;
			muestra[1][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[2][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[2][1]){
					calculo=matriz[2][0]-matriz[2][1];
					operacion=45;
				}else{
					calculo=matriz[2][1]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[2][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[2][1]){
					calculo=matriz[2][0]/matriz[2][1];
					operacion=47;
				}else{
					calculo=matriz[2][1]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[2][1]=operacion;
			muestra[2][2]=matriz[2][2];
			break;
		case 4:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][0]+matriz[1][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]-matriz[1][0];
					operacion=45;
				}else{
					calculo=matriz[1][0]-matriz[0][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][0]*matriz[1][0];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[0][0]>matriz[1][0]){
					calculo=matriz[0][0]/matriz[1][0];
					operacion=47;
				}else{
					calculo=matriz[1][0]/matriz[0][0];
					operacion=47;
				}
			}
			muestra[0][0]=calculo;
			muestra[1][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][1]+matriz[0][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]-matriz[0][2];
					operacion=45;
				}else{
					calculo=matriz[0][2]-matriz[0][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][1]*matriz[0][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][1]>matriz[0][2]){
					calculo=matriz[0][1]/matriz[0][2];
					operacion=47;
				}else{
					calculo=matriz[0][2]/matriz[0][1];
					operacion=47;
				}
			}
			muestra[0][1]=calculo;
			muestra[0][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[3][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]-matriz[3][0];
					operacion=45;
				}else{
					calculo=matriz[3][0]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[3][0];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]/matriz[3][0];
					operacion=47;
				}else{
					calculo=matriz[3][0]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[3][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][1]+matriz[3][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][1]>matriz[3][0]){
					calculo=matriz[2][1]-matriz[3][1];
					operacion=45;
				}else{
					calculo=matriz[3][1]-matriz[2][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][1]*matriz[3][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]/matriz[3][1];
					operacion=47;
				}else{
					calculo=matriz[3][1]/matriz[2][1];
					operacion=47;
				}
			}
			muestra[2][1]=calculo;
			muestra[3][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
					calculo=matriz[1][2]+matriz[2][2];
					operacion=43;
			}
			if(operacion==1){
				if(matriz[1][2]>matriz[2][2]){
					calculo=matriz[1][2]-matriz[2][2];
					operacion=45;
				}else{
					calculo=matriz[2][2]+matriz[1][2];
					operacion=45;
				}
			}
			if(operacion==2){
					calculo=matriz[1][2]*matriz[2][2];
					operacion=42;
			}
			if(operacion==3){
				if(matriz[1][2]>matriz[2][2]){
					calculo=matriz[1][2]/matriz[2][2];
					operacion=47;
				}else{
					calculo=matriz[2][2]/matriz[1][2];
					operacion=47;
				}
			}
			muestra[1][2]=calculo;
			muestra[2][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[3][2]+matriz[3][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[3][2]>matriz[3][3]){
					calculo=matriz[3][2]-matriz[3][3];
					operacion=45;
				}else{
					calculo=matriz[3][3]-matriz[3][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[3][2]*matriz[3][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[3][2]>matriz[3][3]){
					calculo=matriz[3][2]/matriz[3][3];
					operacion=47;
				}else{
					calculo=matriz[3][3]/matriz[3][2];
					operacion=47;
				}
			}
			muestra[3][2]=calculo;
			muestra[3][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][3]+matriz[2][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][3]>matriz[2][3]){
					calculo=matriz[1][3]-matriz[2][3];
					operacion=45;
				}else{
					calculo=matriz[2][3]-matriz[1][3];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][3]*matriz[2][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[1][3]>matriz[2][3]){
					calculo=matriz[1][3]/matriz[2][3];
					operacion=47;
				}else{
					calculo=matriz[2][3]/matriz[1][3];
					operacion=47;
				}
			}
			muestra[1][3]=calculo;
			muestra[2][3]=operacion;
			muestra[1][1]=matriz[1][1];
			muestra[0][3]=matriz[0][3];
			break;
		case 5:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][0]+matriz[0][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][0]>matriz[0][1]){
					calculo=matriz[0][0]-matriz[0][1];
					operacion=45;
				}else{
					calculo=matriz[0][1]-matriz[0][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][0]*matriz[0][1];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[0][0]>matriz[0][1]){
					calculo=matriz[0][0]/matriz[0][1];
					operacion=47;
				}else{
					calculo=matriz[0][1]/matriz[0][0];
					operacion=47;
				}
			}
			muestra[0][0]=calculo;
			muestra[0][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][2]+matriz[0][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][2]>matriz[0][3]){
					calculo=matriz[0][2]-matriz[0][3];
					operacion=45;
				}else{
					calculo=matriz[0][3]-matriz[0][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][2]*matriz[0][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][2]>matriz[0][3]){
					calculo=matriz[0][2]/matriz[0][3];
					operacion=47;
				}else{
					calculo=matriz[0][3]/matriz[0][2];
					operacion=47;
				}
			}
			muestra[0][2]=calculo;
			muestra[0][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[3][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]-matriz[3][0];
					operacion=45;
				}else{
					calculo=matriz[3][0]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[3][0];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]/matriz[3][0];
					operacion=47;
				}else{
					calculo=matriz[3][0]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[3][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][1]+matriz[3][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][1]>matriz[3][0]){
					calculo=matriz[2][1]-matriz[3][1];
					operacion=45;
				}else{
					calculo=matriz[3][1]-matriz[2][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][1]*matriz[3][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]/matriz[3][1];
					operacion=47;
				}else{
					calculo=matriz[3][1]/matriz[2][1];
					operacion=47;
				}
			}
			muestra[2][1]=calculo;
			muestra[3][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
					calculo=matriz[1][1]+matriz[1][2];
					operacion=43;
			}
			if(operacion==1){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]-matriz[1][2];
					operacion=45;
				}else{
					calculo=matriz[1][2]-matriz[1][1];
					operacion=45;
				}
			}
			if(operacion==2){
					calculo=matriz[1][1]*matriz[1][2];
					operacion=42;
			}
			if(operacion==3){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]/matriz[1][2];
					operacion=47;
				}else{
					calculo=matriz[1][2]+matriz[1][1];
					operacion=47;
				}
			}
			muestra[1][1]=calculo;
			muestra[1][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[4][0]+matriz[4][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[4][0]>matriz[4][1]){
					calculo=matriz[4][0]-matriz[4][1];
					operacion=45;
				}else{
					calculo=matriz[4][1]-matriz[4][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[4][0]*matriz[4][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[4][0]>matriz[4][1]){
					calculo=matriz[4][0]-matriz[4][1];
					operacion=47;
				}else{
					calculo=matriz[4][1]/matriz[4][0];
					operacion=47;
				}
			}
			muestra[4][0]=calculo;
			muestra[4][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][4]+matriz[3][4];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][4]>matriz[3][4]){
					calculo=matriz[2][4]-matriz[3][4];
					operacion=45;
				}else{
					calculo=matriz[3][4]-matriz[2][4];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][4]*matriz[3][4];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][4]>matriz[3][4]){
					calculo=matriz[2][4]/matriz[3][4];
					operacion=47;
				}else{
					calculo=matriz[3][4]-matriz[2][4];
					operacion=47;
				}
			}
			muestra[2][4]=calculo;
			muestra[3][4]=operacion;
			operacion=rand()%2;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[0][4]+matriz[1][3]+matriz[1][4];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[0][4]*matriz[1][3]*matriz[1][4];
				operacion=42;
			}
			muestra[0][4]=calculo;
			muestra[1][3]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[2][2]+matriz[2][3]+matriz[3][3];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[2][2]*matriz[2][3]*matriz[3][3];
				operacion=42;
			}
			muestra[2][2]=calculo;
			muestra[3][3]=operacion;
			if(operacion==0){
				calculo=matriz[3][2]+matriz[4][2]+matriz[4][3];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[3][2]*matriz[4][2]*matriz[4][3];
				operacion=42;
			}
			muestra[3][2]=calculo;
			muestra[4][3]=operacion;
			muestra[1][0]=matriz[1][0];
			muestra[4][4]=matriz[4][4];
			break;
		case 6:
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][1]+matriz[1][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][2]-matriz[1][2];
					operacion=45;
				}else{
					calculo=matriz[1][2]-matriz[1][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][1]*matriz[1][2];
				operacion=42;
			}
			if(operacion==3){
				if(matriz[1][1]>matriz[1][2]){
					calculo=matriz[1][1]/matriz[1][2];
					operacion=47;
				}else{
					calculo=matriz[1][2]/matriz[1][1];
					operacion=47;
				}
			}
			muestra[1][1]=calculo;
			muestra[1][2]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[1][3]+matriz[1][4];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[1][3]>matriz[1][4]){
					calculo=matriz[1][3]-matriz[1][4];
					operacion=45;
				}else{
					calculo=matriz[1][4]-matriz[1][3];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[1][3]*matriz[1][4];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[1][3]>matriz[1][4]){
					calculo=matriz[1][3]/matriz[1][4];
					operacion=47;
				}else{
					calculo=matriz[1][4]/matriz[1][3];
					operacion=47;
				}
			}
			muestra[1][3]=calculo;
			muestra[1][4]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[0][5]+matriz[1][5];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[0][5]>matriz[1][5]){
					calculo=matriz[0][5]-matriz[1][5];
					operacion=45;
				}else{
					calculo=matriz[1][5]-matriz[0][5];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[0][5]*matriz[1][5];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[0][5]>matriz[1][5]){
					calculo=matriz[0][5]/matriz[1][5];
					operacion=47;
				}else{
					calculo=matriz[1][5]/matriz[0][5];
					operacion=47;
				}
			}
			muestra[0][5]=calculo;
			muestra[1][5]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][0]+matriz[3][0];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]-matriz[3][0];
					operacion=45;
				}else{
					calculo=matriz[3][0]-matriz[2][0];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][0]*matriz[3][0];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][0]>matriz[3][0]){
					calculo=matriz[2][0]/matriz[3][0];
					operacion=47;
				}else{
					calculo=matriz[3][0]/matriz[2][0];
					operacion=47;
				}
			}
			muestra[2][0]=calculo;
			muestra[3][0]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][1]+matriz[3][1];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]-matriz[3][1];
					operacion=45;
				}else{
					calculo=matriz[3][1]-matriz[2][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][1]*matriz[3][1];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][1]>matriz[3][1]){
					calculo=matriz[2][1]/matriz[3][1];
					operacion=47;
				}else{
					calculo=matriz[3][1]/matriz[2][1];
					operacion=47;
				}
			}
			muestra[2][1]=calculo;
			muestra[3][1]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][2]+matriz[2][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][2]>matriz[2][3]){
					calculo=matriz[2][2]-matriz[2][3];
					operacion=45;
				}else{
					calculo=matriz[2][3]-matriz[2][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][2]*matriz[2][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[2][3]){
					calculo=matriz[2][2]-matriz[2][3];
					operacion=47;
				}else{
					calculo=matriz[2][3]/matriz[2][2];
					operacion=47;
				}
			}
			muestra[2][2]=calculo;
			muestra[2][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[3][2]+matriz[3][3];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[3][2]>matriz[3][3]){
					calculo=matriz[3][2]-matriz[3][3];
					operacion=45;
				}else{
					calculo=matriz[3][3]-matriz[3][2];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[3][2]*matriz[3][3];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[3][3]){
					calculo=matriz[3][2]-matriz[3][3];
					operacion=47;
				}else{
					calculo=matriz[3][3]/matriz[3][2];
					operacion=47;
				}
			}
			muestra[3][2]=calculo;
			muestra[3][3]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[4][3]+matriz[4][4];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[4][3]>matriz[4][4]){
					calculo=matriz[4][3]-matriz[4][4];
					operacion=45;
				}else{
					calculo=matriz[4][4]-matriz[4][3];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[4][3]*matriz[4][4];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[4][3]>matriz[4][4]){
					calculo=matriz[4][3]-matriz[4][4];
					operacion=47;
				}else{
					calculo=matriz[4][4]/matriz[4][3];
					operacion=47;
				}
			}
			muestra[4][3]=calculo;
			muestra[4][4]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[5][4]+matriz[5][5];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[5][4]>matriz[5][5]){
					calculo=matriz[5][4]-matriz[5][5];
					operacion=45;
				}else{
					calculo=matriz[5][5]-matriz[5][4];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[5][4]*matriz[5][5];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[5][5]){
					calculo=matriz[5][4]-matriz[5][5];
					operacion=47;
				}else{
					calculo=matriz[5][5]/matriz[5][4];
					operacion=47;
				}
			}
			muestra[5][4]=calculo;
			muestra[5][5]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[2][4]+matriz[2][5];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[2][4]>matriz[2][5]){
					calculo=matriz[2][4]-matriz[2][5];
					operacion=45;
				}else{
					calculo=matriz[2][5]-matriz[2][4];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[2][4]*matriz[2][5];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[2][5]){
					calculo=matriz[2][4]-matriz[2][5];
					operacion=47;
				}else{
					calculo=matriz[2][5]/matriz[2][4];
					operacion=47;
				}
			}
			muestra[2][4]=calculo;
			muestra[2][5]=operacion;
			operacion=rand()%4;
			if(operacion==0){
				calculo=matriz[4][1]+matriz[4][2];
				operacion=43;
			}
			if(operacion==1){
				if(matriz[4][1]>matriz[4][2]){
					calculo=matriz[4][1]-matriz[4][2];
					operacion=45;
				}else{
					calculo=matriz[4][2]-matriz[4][1];
					operacion=45;
				}
			}
			if(operacion==2){
				calculo=matriz[4][1]*matriz[4][2];
				operacion=42;
				
			}
			if(operacion==3){
				if(matriz[2][2]>matriz[4][2]){
					calculo=matriz[4][1]-matriz[4][2];
					operacion=47;
				}else{
					calculo=matriz[4][2]/matriz[4][1];
					operacion=47;
				}
			}
			muestra[4][1]=calculo;
			muestra[4][2]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[0][1]+matriz[0][0]+matriz[1][0];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[1][0]*matriz[0][0]*matriz[1][0];
				operacion=42;
			}
			muestra[0][1]=calculo;
			muestra[1][0]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[0][2]+matriz[0][3]+matriz[0][4];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[0][2]*matriz[0][3]*matriz[0][4];
				operacion=42;
			}
			muestra[0][2]=calculo;
			muestra[0][4]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[3][4]+matriz[3][5]+matriz[4][5];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[3][4]*matriz[3][5]*matriz[4][5];
				operacion=42;
			}
			muestra[3][4]=calculo;
			muestra[4][5]=operacion;
			operacion=rand()%2;
			if(operacion==0){
				calculo=matriz[5][0]+matriz[5][1]+matriz[5][2];
				operacion=43;
			}
			if(operacion==1){
				calculo=matriz[5][0]*matriz[5][1]*matriz[5][2];
				operacion=42;
			}
			muestra[5][0]=calculo;
			muestra[5][2]=operacion;
			muestra[4][0]=matriz[4][0];
			muestra[5][3]=matriz[5][3];
			break;
	}
	do{
		for(int i=0; i<100; i++){ //clear screen
			printf("\n");
		}
		switch(n){
			case 3:
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==0 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
				break;
			case 4: 
		    	for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==0 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
			    break;
			case 5: 
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==0 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==0 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
				break;
			case 6:
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==1 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==5 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==0 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==5 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						system("color a");
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
				break;
		}
		for(int i=0; i<5; i++){
			printf("\n");
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("[%d]",usuario[i][j]);
			}
			printf("\n");
		}
		printf("fila de la casilla que desea llenar \n");
		scanf("%d",&fil);
		printf("columna de la casilla que desea llenar \n");
		scanf("%d",&col);
		printf("valor con que desea llenar \n");
		scanf("%d",&valor);
		usuario[fil][col]=valor;
		for(int i=0; i<100; i++){
			printf("\n");
		}
		switch(n){
			case 3:
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==0 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
				break;
			case 4: 
		    	for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==0 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
			    break;
			case 5: 
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==0 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==0 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
				break;
			case 6:
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						if(i==1 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==1){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==3 && j==3){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==5 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==2 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==1 && j==0){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==0 && j==4){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==4 && j==5){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						if(i==5 && j==2){
							printf("[%c]",muestra[i][j]);
							continue;
						}
						system("color a");
						printf("[%d]",muestra[i][j]);
					}
					printf("\n");
				}
				break;
		}
		for(int i=0; i<5; i++){
			printf("\n");
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("[%d]",usuario[i][j]);
			}
			printf("\n");
		}
		printf("desea llenar otra casilla? SI=1 NO=0 \n");
		scanf("%d",&pregunta);
	}while(pregunta==1);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(matriz[i][j]==usuario[i][j]){
					iguales++;
				}
			}
		}
		if(iguales==(n*n)){
			system("color a");
			printf("；ELICIDADES HA GANADO!\n");
		}else{
			printf("FRACASO!!! lo siento, debi\242 tener algo como esto:\n");
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					printf("[%d]",matriz[i][j]);
				}
				printf("\n");
			}
		}
	}
