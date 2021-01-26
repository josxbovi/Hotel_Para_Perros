#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

struct registro{
    int cod;
};

void menu(FILE* punt, registro reg);
void llenarArchivo(FILE* punt, registro reg);

int main(){
    registro reg;
    FILE* puntero;

    menu(puntero, reg);


}

void menu(FILE* punt, registro reg){
    int opcion,aux,total, band;
	
	do{
	system("cls");		
	printf("1 Para llenar archivo\n\n");
	scanf("%d",&opcion);
    
    switch(opcion){
        case 1:
            llenarArchivo(punt, reg);
            break;
        default:
        printf("Opcion no valida");
        break;}
    
    
    
    } while (aux==1);
    
}

void llenarArchivo(FILE* punt, registro reg){
    int aux;
    punt=fopen("numeros.dat","a+b");

        do{
        printf("Ingresa numero:  ");
        scanf("%d",&reg.cod);
        fwrite(&reg,sizeof(reg),1,punt);
        printf("\nQueres ingresar mas:  1 para si");
        scanf("%d",&aux);

    }while(aux == 1);
    fclose(punt);
}
