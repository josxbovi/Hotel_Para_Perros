#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct fecha{
	int dia,mes,anio;
};

struct persona{
	char apynom[100];
	int dni;
	fecha fechanac;
		
};

struct habitacion{
	persona huespedes[5];
	bool ocupada;
	int cantHues;
};

void rellenarHotel(int P, int M, int N, habitacion arreglo[][10][10]);
void mostrarCantPersonas(int P, int M, int N, habitacion arreglo[][10][10]);
int cantDePersonas(int P, int M, int N, habitacion arreglo[][10][10]);
void checkIn(int P, int M, int N, habitacion arreglo[][10][10]);
void menu(int P, int M, int N, habitacion arreglo[][10][10]);
int verificCantidad();
void mostrarPPH(int P, int M, int N, habitacion arreglo[][10][10]); //personas por habitacion 
void checkOut(int P, int M, int N, habitacion arreglo[][10][10]);

main(){
	system("color B0");
	printf("Caca");
	habitacion habitaciones[10][10][10];
	int Photeles=2, Mpisos=3, Nhabitaciones=4;
	
	rellenarHotel(Photeles,Mpisos,Nhabitaciones,habitaciones);
	menu(Photeles,Mpisos,Nhabitaciones,habitaciones);


}

void menu(int P, int M, int N, habitacion arreglo[][10][10]){
	int opcion,aux,total, band;
	
	do{
	system("cls");		
	printf("\t\t\t\t\t*****HOTEL PARA PERROS****\n\n");
	printf("1 Para mostrar disponibilidad\n\n");
	printf("2 Para ingresar un huesped\n\n");
	printf("3 Para ver la cantidad de huespedes total\n\n");
	printf("4 Para ver una habitacion \n\n");
	printf("5 Para realizar el Check-Out\n\n");
	scanf("%d",&opcion);
	
	switch(opcion){
		case 1:
			mostrarCantPersonas(P,M,N,arreglo);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		case 2:
			do{
				checkIn(P,M,N,arreglo);	
				mostrarCantPersonas(P,M,N,arreglo);
				printf("\n\n\t\tDesea ingresar otro huesped: 1 si\n");
				scanf("%d",&band);
			}while(band==1);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		case 3:
			total=cantDePersonas(P,M,N,arreglo);
			printf("\nCantidad de personas: %d",total);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		case 4:
			mostrarPPH(P,M,N,arreglo);
			printf("\n\nDesea volver al menu (1 para si): \n");
			scanf("%d",&aux);
			break;
		case 5:
			checkOut(P,M,N,arreglo);
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

void mostrarCantPersonas(int P, int M, int N, habitacion arreglo[][10][10]){
	system("cls");
	for(int i=0;i<P;i++){
		printf("\n\nHotel %d\n",i+1);
		for(int j=M;j>=0;j--){
			for(int k=0;k<N;k++){
				printf("%d	",arreglo[i][j][k].cantHues);
			}
			printf("\n");
		}
	}
}

int cantDePersonas(int P, int M, int N, habitacion arreglo[][10][10]){
	int suma=0;
	for(int i=0;i<P;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				suma = suma + arreglo[i][j][k].cantHues;
			}
		}
	}
	return suma;
}

void rellenarHotel(int P, int M, int N, habitacion arreglo[][10][10]){
	for(int i=0;i<P;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				arreglo[i][j][k].cantHues=0;
				arreglo[i][j][k].ocupada=false;
			}
		}
	}		
}

void checkIn(int P, int M, int N, habitacion arreglo[][10][10]){
	int hp,hm,hn,cant;
	printf("\t\t\t**Check-In**\n\n");		
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
		printf("\n***Habitacion desocupada***\n ");
		cant=verificCantidad();
		for(int i=0;i<cant;i++){
			_flushall();
			printf("Ingrese el nombre del huesped %d:  ",i+1);
			gets(arreglo[hp-1][hm-1][hn-1].huespedes[i].apynom);
			printf("Ingrese el numero DNI del huesped %d:\n\n  ",i+1);
			scanf("%d",&arreglo[hp-1][hm-1][hn-1].huespedes[i].dni);
			printf("Ingrese la fecha de nacimiento (DD/MM/AAAA):\n\n ");
			scanf("%d",&arreglo[hp-1][hm-1][hn-1].huespedes[i].fechanac.dia);
		}
	arreglo[hp-1][hm-1][hn-1].ocupada=true;
	arreglo[hp-1][hm-1][hn-1].cantHues=cant;
}
	else{
		printf("\n***Habitacion ocupada, ingrese otra habitacion***\n\n\t");
		system("pause");
	}
	
} 

int verificCantidad(){
	int cant;
	bool band=true;

	
	while(band){	
		printf("\nIndique cuantas personas son:  ");
		scanf("%d",&cant);
		if(cant>5){
			system("cls");
			printf("\nDebe ingresar un maximo de 5 personas por habitacion  ");
			band=true;
		}
		else{
			band=false;
		}
	}
	return cant;
	
}

void mostrarPPH(int P, int M, int N, habitacion arreglo[][10][10]){
	int hp,hm,hn;
		printf("\t\t\t**VER HABITACION**\n\n");		
	do{
		printf("\nIngresar numero de hotel: ");
		scanf("%d",&hp);
	}while(hp>P);
	
	do{
		printf("\nIngresar piso: ");
		scanf("%d",&hm);
	}while(hm>M);
	do{
		printf("\nIngresar habitacion:  ");
		scanf("%d",&hn);
	}while(hn>N);
	if(arreglo[hp-1][hm-1][hn-1].ocupada==true){
	printf("\nHay %d huespedes\n  ",arreglo[hp-1][hm-1][hn-1].cantHues);
	for(int i=0;i<arreglo[hp-1][hm-1][hn-1].cantHues;i++){
		puts(arreglo[hp-1][hm-1][hn-1].huespedes[i].apynom);
		printf("\n");
	}	
		
	}
	else{
		printf("\nNo hay huespedes\n\n ");
		//system("pause");
	}
	
	
}
void checkOut(int P, int M, int N, habitacion arreglo[][10][10]){
	int hp,hm,hn,cant;
	char CadVacia[40];
	CadVacia[0]= '\0'; //Es una cadena vac�a
	printf("\t\t\t**Check-In**\n\n");		
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
	
	if(arreglo[hp-1][hm-1][hn-1].ocupada==true){
		for(int i=0;i<arreglo[hp-1][hm-1][hn-1].cantHues;i++){
			strcpy (arreglo[hp-1][hm-1][hn-1].huespedes[i].apynom,CadVacia);
		}
	arreglo[hp-1][hm-1][hn-1].ocupada=false;
	arreglo[hp-1][hm-1][hn-1].cantHues=0;
	printf("Habitacion desocupada\n\n");
}
	else{
		printf("\n***Habitacion ocupada, ingrese otra habitacion***\n\n\t");
		system("pause");
	}
	
} 
	




