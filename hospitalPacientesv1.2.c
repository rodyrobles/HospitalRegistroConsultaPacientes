/*
Programa: hospitalPacientesV10.c
Programador: Rodolfo Gutierrez Robles
Descripción: programa para el registro de pacientes
Fecha de creación: 27 febrero, 2018
Última modificación: 27 febrero, 2018
*/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*
 
Nombre y apellido paterno (cadena de caracteres)
Edad (entero)
Sexo (carácter)
Condición del paciente (entero), 
esto se refiere al estado de salud en que ingresa el paciente. 
Los valores van de 1 a 5, donde 5 representa el máximo grado de gravedad.
*/

void dibujarMarco() {
	//inicio dibujo de marco
	gotoxy(1,1);			//esq sup izq    
  	printf("%c",201); 		
  	  	
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
	
	gotoxy(70,1);			//esq sup der
	printf("%c",187); 		
	
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
	
	gotoxy(1,16);			//esq inf izq
	printf("%c",200);
	
	gotoxy(2,16);  			//borde inferior
	int m;
	for (m=0; m<68; m++)
	printf("%c",205); 
	
	gotoxy(70,16);			//esq inf der
	printf("%c",188);
	//fin dibujo de marco

}



int main(){

	struct paciente {
		char fecha[10];
		char nombreApellido[50];
		int edad;
		char sexo; //flush
		int condicion;	
	} pacientes[200];
	
	int c=0, selec1, selec2, selec3;
	char nombrePaciente;
	
	system ("color 0a");
	do {
		
		system("cls");
		dibujarMarco();
		
		gotoxy(21,3);
		printf("Hospital Angeles y Santos A.C.");
		gotoxy(17,5);  
		printf("Programa para el registro de pacientes");
		gotoxy(5,8);  
		printf("Menu principal");
		gotoxy(5,10);
		printf("1) Registrar un paciente");
		gotoxy(5,11);
		printf("2) Buscar un paciente");
		gotoxy(5,12);
		printf("3) Salir\n");
		gotoxy(5,14);
		printf("Elige una opci%cn: ",162);
		scanf("%d", &selec1);
	
	switch(selec1) {
				
		case 1: //menu registro
		do {
			system("cls");
			dibujarMarco();
		
			gotoxy(21,3);
			printf("Hospital Angeles y Santos A.C.");
			gotoxy(17,5);  
			printf("Programa para el registro de pacientes");
			gotoxy(5,8);  
			printf("Menu de Registro");
			gotoxy(5,10);
			printf("1) Registro de datos");
			gotoxy(5,11);
			printf("2) Regresar al menu principal\n");
			gotoxy(5,14);
			printf("Elige una opci%cn: ",162);
			scanf("%d", &selec2);
			
		switch (selec2) {
				
				case 1: //registro
				system("cls");
				printf("\t Registro de pacientes \n\n");
				if (c>=200)
			printf("El hospital esta lleno");
			else {
												
				printf("Ingresa los datos del paciente\n");
				printf("clave:%.3d\n", c);
				printf("Fecha de ingreso [dd-mm-aa]: ");
				scanf("%s", pacientes[c].fecha);
				printf("nombre y apellido paterno: ");
				fflush(stdin); //limpia buffer del teclado
				gets(pacientes[c].nombreApellido);
				printf("edad: ");
				scanf("%d", &pacientes[c].edad);
				printf("sexo (m/f): ");
				fflush(stdin); //limpia buffer del teclado
				scanf("%c", &pacientes[c].sexo);
				printf("condicion del paciente 1 al 5, de leve a grave: ");
				scanf("%d", &pacientes[c].condicion);
				printf("\nRegistro exitoso\n\n");
				c++;		
			}
				system ("pause");
				break;
				
				case 2:
				break;
			} 
			} while (selec2!=2);
		break;
		
		case 2: //menu consulta
		do {
			system("cls");
			dibujarMarco();
		
		gotoxy(21,3);
		printf("Hospital Angeles y Santos A.C.");
		gotoxy(17,5);  
		printf("Programa para la consulta de pacientes");
		gotoxy(5,8);  
		printf("Menu de Consulta");
		gotoxy(5,10);
		printf("1) Consulta de datos");
		gotoxy(5,11);
		printf("2) Regresar al menu principal\n");
		gotoxy(5,14);
		printf("Elige una opci%cn :",162);
		scanf("%d", &selec3);
			
		switch (selec3) {
				case 1: //consulta
				
				system("cls");
				printf("\t Consulta de pacientes \n\n");
								
				//printf("Ingresa Nombre y apellido paterno del paciente: ");
				//scanf("%s", &nombrePaciente);
				
				//temporalmente apunta a indice 0
																	
				printf("fecha de ingreso:%s \n", pacientes[0].fecha);
				printf("nombre: %s \n", pacientes[0].nombreApellido);
				printf("edad: %d \n", pacientes[0].edad);
				printf("sexo: %c \n", pacientes[0].sexo);
				printf("Condicion: %d \n", pacientes[0].condicion);
					
					
					
					
								
				//hacer un ciclo para que recorra los registros
				
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
			} 
			} while (selec2!=2);
		break;
		
		} //cierre switch
		
		
	} while (selec1!=3);
		
system("pause");
return 0;		
		
			
		
	} 
	
	
	
