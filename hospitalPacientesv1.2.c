/*
Programa: hospitalPacientesV1.2.c
Programador: Rodolfo Gutierrez Robles
Descripción: programa para el registro de pacientes
Fecha de creación: 27 febrero, 2018
Última modificación: 1 marzo, 2018
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/*
 
Nombre y apellido paterno (cadena de caracteres)
Edad (entero)
Sexo (carácter)
Condición del paciente (entero), 
esto se refiere al estado de salud en que ingresa el paciente. 
Los valores van de 1 a 5, donde 5 representa el máximo grado de gravedad.
*/

void dibujarMarco();


int main(){

	struct paciente {
		char fecha[10];
		char nombreApellido[50];
		int edad;
		char sexo; //flush
		int condicion;	
	} pacientes[100];
	
	int contador=0, i, posPaciente, selec1, selec2, selec3;
	char nombreRegistrado[50], buscarNombre[50];
	
	system ("color 0a");
	do {
		
		system("cls");
		dibujarMarco();
		
		gotoxy(21,3); printf("Hospital Angeles y Santos A.C.");
		gotoxy(17,5); printf("Programa para el registro de pacientes");
		gotoxy(5,8);  printf("Menu principal");
		gotoxy(5,10); printf("1) Registrar un paciente");
		gotoxy(5,11); printf("2) Buscar un paciente");
		gotoxy(5,12); printf("3) Salir\n");
		gotoxy(5,14); printf("Elige una opci%cn: ",162);
		scanf("%d", &selec1);
	
	switch(selec1) {
				
		case 1: //menu registro
		do {
			system("cls");
			dibujarMarco();
		
			gotoxy(21,3); printf("Hospital Angeles y Santos A.C.");
			gotoxy(17,5); printf("Programa para el registro de pacientes");
			gotoxy(5,8);  printf("Menu de Registro");
			gotoxy(5,10); printf("1) Registro de datos");
			gotoxy(5,11); printf("2) Regresar al menu principal\n");
			gotoxy(5,14); printf("Elige una opci%cn: ",162);
			scanf("%d", &selec2);
			
			switch (selec2) {
				
			case 1: //registro
			system("cls");
			printf("\t Registro de pacientes \n\n");
			
			if (contador>=100)
				printf("\nEl hospital esta lleno\n");
			
			else {
				printf("Ingresa los datos del paciente\n");
				printf("Numero de registro:%.3d\n", contador+1);
				printf("Fecha de ingreso [dd-mm-aa]: ");
				scanf("%s", pacientes[contador].fecha);
				printf("nombre y apellido paterno: ");
				fflush(stdin); //limpia buffer del teclado
				gets(pacientes[contador].nombreApellido);
				printf("edad: ");
				scanf("%d", &pacientes[contador].edad);
				printf("sexo (m/f): ");
				fflush(stdin); //limpia buffer del teclado
				scanf("%c", &pacientes[contador].sexo);
				printf("condicion del paciente 1 al 5, de leve a grave: ");
				scanf("%d", &pacientes[contador].condicion);
				printf("\nRegistro exitoso\n\n");
				contador++;		
			}
				system ("pause");
				break;
				
				case 2:
				break;
			} // cierre selec2
			} while (selec2!=2);
		break;
		
		case 2: //menu consulta
		do {
			system("cls");
			dibujarMarco();
		
			gotoxy(21,3); printf("Hospital Angeles y Santos A.C.");
			gotoxy(17,5); printf("Programa para la consulta de pacientes");
			gotoxy(5,8);  printf("Menu de Consulta");
			gotoxy(5,10); printf("1) Consulta de datos");
			gotoxy(5,11); printf("2) Regresar al menu principal\n");
			gotoxy(5,14); printf("Elige una opci%cn :",162);
			scanf("%d", &selec3);
			
				switch (selec3) {
				case 1: //consulta
				
				system("cls");
				printf("\t Consulta de pacientes \n\n");
				printf("Ingresa Nombre y apellido paterno del paciente: ");
				fflush(stdin); //limpia buffer del teclado
				gets(buscarNombre);  
				//printf("El paciente a buscar es: %s ",buscarNombre);
				
				//hacer un ciclo para que recorra los registros
				
				for (i=0; i<contador; i++) {
				
					strcpy(nombreRegistrado,pacientes[i].nombreApellido);
					if (strcmp(buscarNombre,nombreRegistrado)==0) {
					posPaciente = i;
					
					printf("Datos del paciente: \n");		
					printf("fecha de ingreso:%s \n", pacientes[posPaciente].fecha);
					printf("nombre: %s \n", pacientes[posPaciente].nombreApellido);
					printf("edad: %d \n", pacientes[posPaciente].edad);
					printf("sexo: %c \n", pacientes[posPaciente].sexo);
					printf("Condicion: %d \n", pacientes[posPaciente].condicion);
				}	else if {
						printf("No se encontro registro: \n");
					}
				}	
				
														
					
					
				
				
				
				/*
				for (i=0; i<n; i++) {
					if (empleados[i].salario>sMayor) {
					sMayor = empleados[i].salario;
					pMayor=i;
					}		
				*/
				
				
				
				/*
																	
				printf("fecha de ingreso:%s \n", pacientes[0].fecha);
				printf("nombre: %s \n", pacientes[0].nombreApellido);
				printf("edad: %d \n", pacientes[0].edad);
				printf("sexo: %c \n", pacientes[0].sexo);
				printf("Condicion: %d \n", pacientes[0].condicion);
				
				*/
	
				system ("pause");
				
				break;
				
				case 2:
				break;
			} //cierre selec3
			} while (selec3!=2);
		break;
		
		} //cierre selec1
		
		
	} while (selec1!=3);
		
printf("\n\n");
system("pause");
return 0;		
		
	} 
	
	
void dibujarMarco() {
	//inicio dibujo de marco
	gotoxy(1,1); printf("%c",201);		//esq sup izq    
  	 		
  	  	
	int i; 					//borde superior
	gotoxy(2,1);
	for (i=0; i<68; i++) 
	  	printf("%c",205); 
  	
  	int xVi=1, yVi=2;  		//vertical izquierda
	int j;					
	for (j=0; j<15; j++){
		gotoxy(xVi,yVi);	
		printf("%c",186);  
		yVi= yVi+1;
	}
	
	gotoxy(70,1); printf("%c",187);		//esq sup der
	 		
	
	int xVd=70, yVd=2;		//vertical derecha
	int k;					
	for (k=0; k<15; k++){
		gotoxy(xVd,yVd);	
		printf("%c",186);  
		yVd= yVd+1;
	}
	
	gotoxy(2,6);  			//linea intermedia
	int l;
	for (l=0; l<68; l++)
	printf("%c",205);  
	
	gotoxy(1,16); printf("%c",200);		//esq inf izq
	
	
	gotoxy(2,16);  			//borde inferior
	int m;
	for (m=0; m<68; m++)
	printf("%c",205); 
	
	gotoxy(70,16); printf("%c",188); //esq inf der
	
	//fin dibujo de marco

}
