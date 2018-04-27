#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
/*Comentario
Generar un programa que me permita guardar los datos de los clientes
de un banco,nombre,documento y el tipo de transacciones a realizar. Se
requiere conocer el tiempo total de la atencion las personas en la cola,los
tiempos estimados para cada transaccion son los sgtes:
Retiro 4min
Deposito 2min
Consulta 3.5min
Actualizacion 5min
Pagos 2min
Elaborado por:Fernando Lopez Mejia, Leyder Londoño*/
struct Cliente{
	char id[10];
	char nombre[20];
	char tipo_trans[15];
	int estado;
	float tiempo;
};
struct Nodo{
	Cliente c;
	Nodo *siguiente;
};


void cargar_cliente();
void insertarLista();
void mostrarLista();
void buscarElemento();
void eliminarElemento();
void eliminarLista();
void Menu();

Cliente c;
Nodo *lista=NULL;
Cliente b;
Cliente usuario2;

int main() {
	Menu();
	return 0;
}
void Menu(){
	
	int opc;
	
	do{
		
		printf("\n|------------------------------------------------------|");
		printf("\n|INGRESE EL NUMERO CORRESPONDIENTE A LA OPCION DESEADA |");
		printf("\n|-------------------------|----------------------------|");
		printf("\n|                         |                            |");
		printf("\n| 1. Insertar Cliente     | 2. Mostrar Cliente         |");
		printf("\n|                         |                            |");
		printf("\n| 3. Buscar Cliente       | 4. Eliminar Cliente        |"); 
		printf("\n|                         |                            |"); 
		printf("\n| 5. Eliminar Cliente     | 6 Salir                    |");
		printf("\n|------------------------------------------------------|");
		
		printf("\nOPCION:");
		scanf("%d",&opc);
		
		switch(opc){
			
		case 1: cargar_cliente();
		break;
		
		case 2: mostrarLista();
		break;
		
		case 3: buscarElemento();
		break;
		
		case 4: eliminarElemento();
		break;
		
		case 5: 
			printf(" La Lista se ha eliminado \n");
			while(lista!=NULL){/* Mientras el dato no sea el final de la lista */
				eliminarLista();
			}
			break;
			
		default: printf("\n\t\tGracias por elegirnos!! \n");
		printf("\n\t\t");
		system("pause");
		break;}
	}while(opc!=6);
}
void cargar_cliente(){
	
	int opcion,num;
	
	printf("\n Digite cuantos usuarios desea ingresar \n");
	scanf("%d",&num);
	
	for(int i=0;i<num;i++){
		printf("\n Ingrese el nombre : ");
		fflush stdin;
		gets(usuario2.nombre);
		printf("\n Ingrese el documento : ");
		gets(usuario2.id);
		int opc=0;
		printf("\n|-----------------------------------------|");
		printf("\n|             MENU DE LISTAS               |");
		printf("\n|-----------------------------------------|");
		printf("\n|  SELECCIONE EL TIPO DE TRANSACCION QUE  |");
		printf("\n|                DESEA                    |");
		printf("\n|------------------|----------------------|");
		printf("\n|                  |                      |");
		printf("\n| 1. RETIRO        | 2. DEPOSITO          |");
		printf("\n|                  |                      |");
		printf("\n| 3. CONSULTA      | 4. ACTUALIZACION     |");
		printf("\n|                  |                      |");
		printf("\n| 5. PAGOS         | 6. SALIR             |");
		printf("\n|------------------|----------------------|");
		printf("\n|-----------------------------------------|");
		
		printf("\n\nOPCION :");
		scanf("%d",&opc);		
		switch(opc) {
		case 1:
			//system("cls");
			strcpy(usuario2.tipo_trans,"Retiro");
			usuario2.tiempo=4;
			break;
		case 2:
			//system("cls");
			strcpy(usuario2.tipo_trans,"Deposito");
			usuario2.tiempo=2;
			break;
		case 3:
			//system("cls");
			strcpy(usuario2.tipo_trans,"Consulta");
			usuario2.tiempo=3.5;
			break;
		case 4:
			//system("cls");
			strcpy(usuario2.tipo_trans,"Actualizacion");
			usuario2.tiempo=5;
			break;
		case 5:
			//system("cls");	
			strcpy(usuario2.tipo_trans,"Pagos");
			usuario2.tiempo=2;
			break;
		case 6:
			//system("cls");
			printf("\n\t\tGRACIAS POR ELEGIR LA MEJOR OPCION \n"); 
			exit(6);
			break;
		default:
			//system("cls");
			printf("\n\t\tHA INGRESADO UN DATO INVALIDO \n");
			break;
		}	
		printf("1. Es mujer embarazada o tiene alguna discapacidad \n");
		printf("2. General\n");
		printf("Ingrese una opcion\n");
		scanf("%d",&opcion);
		if(opcion==1){
			strcpy(usuario2.nombre,"Preferencial");
			usuario2.estado=1;
		}else if(opcion==2){
			strcpy(usuario2.nombre,"General");
			usuario2.estado=2;
		}else{
			printf("\n Opcion mal ingresada!\n");
		}
		insertarLista();	
	}

	
}

void insertarLista(){
	
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->c=usuario2;
	Nodo *aux1=lista;
	Nodo *aux2;
	while((aux1 != NULL)&&(aux1->c.estado < 2)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
	printf("El dato se agrego con exito a la lista \n");
}
void mostrarLista(){
	Nodo *actual = new Nodo();
	actual = lista;

	while(actual != NULL){
		printf("\n\t\t[%s] ",actual->c.nombre);
		printf("\n\t\t[%s] ",actual->c.id);
		printf("\n\t\t[%s] ",actual->c.tipo_trans);
		printf("\n\t\t[%.1f] ",actual->c.tiempo);
		actual=actual->siguiente;
	}
}
void buscarElemento(){
	bool band=false;
	
	Nodo *actual = new Nodo();
	actual=lista;
	printf("Ingrese por favor el id del cliente \n");
	fflush stdin;
	gets(usuario2.id);
	/* Recorrer la lista */
	while(actual != NULL){
		if(strcmp(actual->c.id, usuario2.id)){
			actual=actual->siguiente;
		}
	}
	if(band== true){
		printf("El Elemento SI a sido encontrado en la lista \n");
	}
	else{
		printf("El Elemento NO a sido encontrado en la lista \n");
	}
}
void eliminarElemento(){
	printf("Ingrese el id del cliente \n");
	fflush stdin;
	gets(c.id);
	/* Preguntar si la lista esta vacia */
	if(lista !=NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		/* Recorrer la lista */
		while((aux_borrar !=NULL)&&(strcmp(aux_borrar->c.id, c.id))){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		/* El elemento no ha sido encontrado */
		if(aux_borrar == NULL){
			printf(" El Elemento no fue encontrado \n");
		}
		/* Si el primer elemento es el que vamos a eliminar */
		else if(anterior == NULL){
			lista = lista ->siguiente;
			delete aux_borrar;
			printf(" El Elemento fue borrado \n");
		}
		/* Si el elemento esta en la lista pero no es el primer nodo */
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			printf(" El Elemento fue borrado \n");
		}
	}
}
void eliminarLista(){
	Nodo *aux=lista;
	b =aux->c;
	lista= aux->siguiente;
	delete aux;
}

