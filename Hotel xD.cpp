/*Registrar una habitacion*/


#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
	int dia,mes,anio;
};

struct persona{
	char apynom[100];
	int dni;
	fecha fechanac;
		
};

void ingresarHuespedesHab(persona huesped[],int cant); 
void mostrarHuespedes(persona huesped [],int cant);
int cantidadHuespedes();

main(){
	persona huesped[5];
	int cant=cantidadHuespedes();
	ingresarHuespedesHab(huesped,cant);	
	mostrarHuespedes(huesped,cant);
	
}

void ingresarHuespedesHab(persona huesped[],int cant){

	for(int i=0;i<cant;i++){
		printf("\nIngrese el nombre del huesped %d:  ",i+1);
		_flushall();
		gets(huesped[i].apynom);
		printf("\nIngresar el DNI del  huesped %d:  ",i+1);
		scanf("%d",&huesped[i].dni);
		printf("\nIngrese la fecha de nacimiento del huesped %d (dia, mes, anio):  ",i+1);
		scanf("%d",&huesped[i].fechanac.dia);
		scanf("%d",&huesped[i].fechanac.mes);
		scanf("%d",&huesped[i].fechanac.anio);
	}	
}

void mostrarHuespedes(persona huesped [],int cant){

	for(int i=0;i<cant;i++){
		printf("\nHuesped %d:\n  ",i+1);
		printf("\nNombre:  ");
		puts(huesped[i].apynom);
	
	}
}

int cantidadHuespedes(){
	int cant;
	bool band=true;

	
	while(band){	
		printf("\nIndique cuantas personas son:  ");
		scanf("%d",&cant);
		if(cant>5){
			system("cls");
			printf("\nSon mas de 5 personas BOLUDO");
			band=true;
		}
		else{
			band=false;
		}
	}
	return cant;
	
}

