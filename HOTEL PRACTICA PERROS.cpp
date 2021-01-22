#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct fecha{
	int dia,mes,anio;
};

struct persona{
	char apynom[100];
	//int dni;
	//fecha fechanac;
		
};

struct habitacion{
	persona huespedes[5];
	bool ocupada;
};

void rellenarHotel(int P, int M, int N, habitacion arreglo[][10][10]);
void ingresarDatos(int P, int M, int N, int arreglo[][100][10]);
void mostrarDatos(int P, int M, int N, int arreglo[][100][10]);
int cantDePersonas(int P, int M, int N, int arreglo[][100][10]);
void checkIn(int P, int M, int N, habitacion arreglo[][10][10]);
void menu(int P, int M, int N, habitacion arreglo[][10][10]);
int longitud(habitacion arreglo[][10][10], int hp, int hm,int hn);


main(){
	system("color B0");
	habitacion habitaciones[10][10][10];
	int Photeles=2, Mpisos=3, Nhabitaciones=4;
	int arreglo[100][100][10];
	
	rellenarHotel(Photeles,Mpisos,Nhabitaciones,habitaciones);
	
	menu(Photeles,Mpisos,Nhabitaciones,habitaciones);

}

void menu(int P, int M, int N, habitacion arreglo[][10][10]){
	int opcion,aux,total, band;
	
	do{
	system("cls");		
	printf("\t\t\t\t\t*****HOTEL PARA PERROS****\n\n");
	printf("1 Para mostrar disponibilidad\n");
	printf("2 Para ingresar un huesped\n");
	printf("3 Para ver la cantidad de huespedes total\n\n");
	scanf("%d",&opcion);
	
	switch(opcion){
		case 1:
			//mostrarDatos(P,M,N,arreglo);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		case 2:
			do{
				checkIn(P,M,N,arreglo);	
				//mostrarDatos(P,M,N,arreglo);
				printf("Desea ingresar otro huesped: 1 si\n");
				scanf("%d",&band);
			}while(band==1);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		case 3:
			//total = cantDePersonas(P,M,N,arreglo);
			//printf("\nCantidad de personas: %d",total);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		default:
			printf("Toca bien pelotudo\n");
			aux = 1;
			break;
	}
	}while(aux==1);
}

void ingresarDatos(int P, int M, int N, int arreglo[][100][10]){	
	for(int i=0;i<P;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				printf("\nIngresar cantidad de personas en hotel %d, piso %d y habitacion %d: ",i+1,j+1,k+1);
				scanf("%d",&arreglo[i][j][k]);
			}
		}
	}	
}

void mostrarDatos(int P, int M, int N, int arreglo[][100][10]){
	system("cls");
	for(int i=0;i<P;i++){
		printf("\n\nHotel %d\n",i+1);
		for(int j=M;j>=0;j--){
			for(int k=0;k<N;k++){
				printf("%d	",arreglo[i][j][k]);
			}
			printf("\n");
		}
	}
}

int cantDePersonas(int P, int M, int N, int arreglo[][100][10]){
	int suma=0;
	for(int i=0;i<P;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				suma = suma + arreglo[i][j][k];
			}
		}
	}
	return suma;
}

void rellenarHotel(int P, int M, int N, habitacion arreglo[][10][10]){
	for(int i=0;i<P;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
			
				arreglo[i][j][k].ocupada=false;
			}
		}
	}		
}

void checkIn(int P, int M, int N, habitacion arreglo[][10][10]){
	int hp,hm,hn;
			
	do{
		printf("\nIngresar numero de hotel: ");
		scanf("%d",&hp);
	}while(hp>P);
	
	do{
		printf("\nIngresar piso: ");
		scanf("%d",&hm);
	}while(hm>M);
	
	do{
		printf("\nIngresar habitacion: ");
		scanf("%d",&hn);
	}while(hn>N);
	
	if(arreglo[hp-1][hm-1][hn-1].ocupada==false ){
		printf("Habitacion desocupada\nIngresar cantidad de huespedes: ");
		//scanf("%d",&arreglo[hp-1][hm-1][hn-1]);
	}
	else{
		printf("La habitacion está ocupada");
	}
	
}

int longitud(habitacion arreglo[][10][10],int hp, int hm,int hn){
	//return sizeof(arreglo[hp-1][hm-1][hn-1].huespedes)/sizeof(arreglo[hp-1][hm-1][hn-1].huespedes[0];
	
}


