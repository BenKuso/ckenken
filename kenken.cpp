#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Prototipos.
void ceros(int matriz[6][6], int muestra[6][6], int usuarios[6][6], int n); //Función que llena en ceros las matrices usadas.
void respuesta(int matriz[6][6], int n);									//Función que genera un cuadrado Latino (CL).
void calculos(int muestra[6][6], int matriz[6][6], int n);					//Función que dado el CL asocia casillas y genera los calculos a realizar.
void user(int muestra[6][6], int usuario[6][6], int n);						//Función que permite al usuario llenar un arreglo
void resultado(int matriz[6][6],int usuario[6][6], int n);
int cuatro(int m[6][6], int u[6][6]);
//Bloque Principal.
int main(){
	int n, matriz[6][6], muestra[6][6], usuario[6][6];  //Declaración de variables requeridas.
	system("cls");
	printf("Ingrese el orden de la matriz \n");			//Imprime mensaje que solicite el orden de la Matriz.
	scanf("%d",&n);
	if(n>=3 && n<=6){	 								//Lee el orden de la matriz.
		ceros(matriz,muestra, usuario, n);				//Llama a la función ceros.
		respuesta(matriz, n);							//Llama a la función respuesta.
		calculos(muestra, matriz, n);					//Llama a la función calculo.
		user(muestra, usuario, n);						//Llama a la función user.
		resultado(matriz, usuario, n);					//Llama a la función resultado.
		system("pause");
	}else{
		printf("Este juego no está diseñado para n\243meros mayores que 6 ni menores que 2\n");  //If que controla no salirse del rango e imprima mensaje si sucede.
	}
}
//Implemmentaciones
						//ceros.
void ceros(int matriz[6][6], int muestra[6][6], int usuario[6][6], int n){
	for(int i=0; i<n; i++){ 							//ciclo que permite llenar las matrices en ceros.
		for(int j=0; j<n; j++){
			matriz[i][j]=0;
			muestra[i][j]=0;
			usuario[i][j]=0;
		}
	}	
}
						//respuesta.
void respuesta(int matriz[6][6], int n){
	int z, original;
	srand(time(NULL));
	z=1+rand()%n;
	original=z;
	printf("%d\n",z);
	for(int i=0; i<n; i++){
		z=z+i;
		for(int j=0; j<n; j++){
			if(z>n){
				z=(z-n);
			}
			matriz[i][j]=z;
			z++;
		}
		z=original;
	}
}				
					//calculos.
void calculos(int muestra[6][6], int matriz[6][6], int n){
	int calculo, operacion;								//Declaración de variables requeridas.
	switch(n){											//Switch que asocia casillas según el orden.
		case 3:								
			operacion=rand()%4;							//genera un valor aleatorio que representan una operación aritmética.
			if(operacion==0){							//0=+ 1=- 2=* 3=/.
				calculo=matriz[0][0]+matriz[1][0];		//Se realiza el calculo requerido contemplando evitar números negativos.
				operacion=43;							//Se asigna el valor en ASCII para el símbolo de la operación:
			}											//43=+ 45=-  42=* 47=/.
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
			muestra[0][0]=calculo;						//de las casillas asociadas a la primera se le asigna el valor de la operación efectuada
			muestra[1][0]=operacion;					//a la última el valor en ASCII.
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
}	
					//Usuario.
void user(int muestra[6][6], int usuario[6][6], int n){
	int fil, col, valor, pregunta; 							//Declaración de variables usadas.
	do{														//ciclo do wuile que permita repetir siempre que el usuario así lo desee.
		for(int i=0; i<100; i++){ 							//clear screen.
			printf("\n");
		}
		cuatro(muestra,usuario);
		for(int i=0; i<5; i++){						//Salto de línea que separa un cuadrado de otro.
			printf("\n");
		}
		cuatro(muestra,usuario);
		printf("fila de la casilla que desea llenar \n");	//Muestra un mensaje pidiendo la fila de la casilla.
		scanf("%d",&fil);									//Lee la fila.
		printf("columna de la casilla que desea llenar \n");//Muestra un mensaje pidiendo la columna de la casilla.
		scanf("%d",&col);									//Lee la columna.
		printf("valor con que desea llenar \n");			//Pide el valor que se pondrá en la casilla indicada.
		scanf("%d",&valor);									//lee dicho valor.
		usuario[fil][col]=valor;							//Llena el valor dado en la casilla indicada. 
		for(int i=0; i<100; i++){					//De nuevo hace un Clear Screen.
			printf("\n");
		}
		cuatro(muestra,usuario);
		for(int i=0; i<5; i++){					
			printf("\n");
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("[%d]",usuario[i][j]);
			}
			printf("\n");
		}
		printf("desea llenar otra casilla? SI=1 NO=0 \n");//pregunta si desea llenar otra casilla, al resonder si, se repetirá el ciclo.
		scanf("%d",&pregunta);							  //recibe la respuesta
	}while(pregunta==1);								  //Compara la respuesta dada y determina si se repite o no el ciclo.	
}		
					//resultado.
void resultado(int matriz[6][6],int usuario[6][6], int n){
	int iguales=0;										//Declara la variable tipo contador usada para determinar la victoria o derrota.
		for(int i=0; i<n; i++){							//Doble ciclo que comparará valor por valor la matriz original y la que lleno el usuario.
			for(int j=0; j<n; j++){
				if(matriz[i][j]==usuario[i][j]){
					iguales++;							//En caso de que dos valores sean iguales, se añaden al contador.
				}
			}
		}
		if(iguales==(n*n)){								//Si el contador es igual a n^2 entonces ambas matrices son identicas, lo que significa que el usuario ha ganado.
			system("color a");							//Cambio de color a Verde.
			printf("¡FELICIDADES HA GANADO!\n");		//Imprime mensaje de Victoria.
		}else{											//Caso contrario el usuario ha perdido.
			system("color c");							//cambio de color a rojo.
			printf("FRACASO!!! lo siento, debi\242 tener algo como esto:\n"); 	//Mensaje de Derrota.
			for(int i=0; i<n; i++){						//Doble ciclo para imprimir arreglo.
				for(int j=0; j<n; j++){
					printf("[%d]",matriz[i][j]);		//Se le proporciona al usuario la repuesta correcta que debió haber tenido.
				}
				printf("\n");
			}
		}
}									



int cuatro(int m[6][6], int u[6][6]){   
	printf("+------+------+------+------+------+\n");
	printf("| %i%c          | %i%c          | %i%c   |\n",m[0][0],m[0][1],m[0][2],m[0][3],m[0][4],m[1][3]);
	printf("| [%i]         | [%i]         | [%i]  |\n",u[0][0],u[0][1],u[0][2],u[0][3],u[0][4]);
	printf("+------+------+------+------+      +\n");
	printf("| %i    | %i%c          |             |\n",m[1][0],m[1][1],m[1][2]);
	printf("| [%i]  | [%i]    [%i]  | [%i]    [%i]  |\n",u[1][0],u[1][1],u[1][2],u[1][3],u[1][4]);
	printf("+------+------+------+------+------+\n");
	printf("| %i%c   | %i%c   | %i%c          | %i%c   |\n",m[2][0],m[3][0],m[2][1],m[3][1],m[2][2],m[3][3],m[2][4],m[3][4]);
	printf("| [%i]  | [%i]  | [%i]    [%i]  | [%i]  |\n",u[2][0],u[2][1],u[2][2],u[2][3],u[2][4]);
	printf("+      +      +------+      +      +\n");
	printf("|      |      | %i%c   |      |      |\n",m[3][2],m[3][3]);
	printf("| [%i]  | [%i]  | [%i]  | [%i]  | [%i]  |\n",u[3][0],u[3][1],u[3][2],u[3][3],u[3][4]);
	printf("+------+------+      +------+------+\n");
	printf("| %i%c          |             | %i    |\n",m[4][0],m[4][1],m[4][4]);
	printf("| [%i]    [%i]  | [%i]    [%i]  | [%i]  |\n",u[4][0],u[4][1],u[4][2],u[4][3],u[4][4]);
	printf("+------+------+------+------+------+\n");
}
