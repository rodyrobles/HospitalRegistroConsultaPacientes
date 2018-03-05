/*
Programa: hospitalPacientesV1.2.c
Programador: Rodolfo Gutierrez Robles
Descripción: programa para el registro de pacientes
Fecha de creación: 27 febrero, 2018
Última modificación: 4 marzo, 2018
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void dibujarMarco();
void dibujarMarco2();

struct paciente {
		char nombreApellido[50];
		int edad;
		char sexo; 
		int condicion;	
	} pacientes[10];

int main(){

	int  i=0, registro=0, encontrado, selec1, selec2, selec3;
	char nombreRegistrado[50], nombreBuscado[50];
	
	system ("color 0a");
	do {
		
		system("cls");
		dibujarMarco();
		
		gotoxy(21,3); printf("Hospital Angeles y Santos A.C.");
		gotoxy(17,5); printf("Programa para el registro de pacientes");
		highvideo();textbackground(GREEN);
		gotoxy(5,8);  printf("Menu principal");
		lowvideo();textbackground(BLACK);
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
			highvideo();textbackground(GREEN);
			gotoxy(5,8);  printf("Menu de Registro");
			lowvideo();textbackground(BLACK);
			gotoxy(5,10); printf("1) Registro de datos");
			gotoxy(5,11); printf("2) Regresar al menu principal\n");
			gotoxy(5,14); printf("Elige una opci%cn: ",162);
			scanf("%d", &selec2);
			
			switch (selec2) {
				
				case 1: //registro
					system("cls");
					dibujarMarco2();
					gotoxy(21,3); printf("Hospital Angeles y Santos A.C.");
					gotoxy(17,5); printf("Programa para el registro de pacientes");
					highvideo();textbackground(GREEN);
					gotoxy(25,8);  printf("Registro de pacientes\n\n");
					lowvideo();textbackground(BLACK);
					
					if(registro>9){
						printf("\tCupo de hospital lleno\n\n");
						
					} else {
					
						printf("\tIngresa los datos del paciente #%.3d\n\n", registro+1);
						printf("\tNombre y apellido paterno: ");
						fflush(stdin); //limpia buffer del teclado
						gets(pacientes[registro].nombreApellido);
						
						printf("\tEdad: ");
						scanf("%d", &pacientes[registro].edad);
						printf("\tSexo (m/f): ");
						fflush(stdin); //limpia buffer del teclado
						scanf("%c", &pacientes[registro].sexo);
						printf("\tCondicion del paciente, ingrese un numero\n");
						printf("\t1=Muy Leve 2=Leve 3=Grave 4=Muy grave 5=En extremo grave: ");
						scanf("%d", &pacientes[registro].condicion);
						
						printf("\n\tRegistro exitoso\n\n");
						registro++;		
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
			highvideo();textbackground(GREEN);
			gotoxy(5,8);  printf("Menu de Consulta");
			lowvideo();textbackground(BLACK);
			gotoxy(5,10); printf("1) Consulta de datos");
			gotoxy(5,11); printf("2) Regresar al menu principal\n");
			gotoxy(5,14); printf("Elige una opci%cn :",162);
			scanf("%d", &selec3);
			
				switch (selec3) {
				case 1: //consulta
				
					system("cls");
					dibujarMarco2();
					
					gotoxy(21,3); printf("Hospital Angeles y Santos A.C.");
					gotoxy(17,5); printf("Programa para el registro de pacientes");
					highvideo();textbackground(GREEN);
					gotoxy(25,8);  printf("Consulta de pacientes\n\n");
					lowvideo();textbackground(BLACK);
					
					printf("Ingresa Nombre y apellido paterno: ");
					fflush(stdin); //limpia buffer del teclado
					gets(nombreBuscado);  
					///Busqueda -------------------------------------
					encontrado=0;
					for (i=0; i<10; i++) {
						strcpy(nombreRegistrado,pacientes[i].nombreApellido);
						
						if (strcmp(nombreRegistrado,nombreBuscado)==0) {
																		
							printf("\n\tPaciente #%.3d\n",i+1);		
							printf("\tNombre: %s \n", pacientes[i].nombreApellido);
							printf("\tEdad: %d \n", pacientes[i].edad);
							printf("\tSexo: %c \n", pacientes[i].sexo);
							printf("\tCondicion: %d", pacientes[i].condicion);
							encontrado=1; 
						}	
					}	//fin for
						
						if (encontrado==0) printf("\n\tNO hay registros con este nombre");
						
						
					///Busqueda -------------------------------------
					printf("\n\n");
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
	int x,y;
	
	system ("color 0a");
	//inicio dibujo de marco
	gotoxy(1,1); printf("%c",201);		//esq sup izq    
  	  	  	
	for (x=2; x<70; x++) { 				//borde superior
	  	gotoxy(x,1);
		printf("%c",205);
  	  	}	
  		    		
	for (y=2; y<17; y++){ 				//vertical izquierda
		gotoxy(1,y);
		printf("%c",186); 
		}
	
	gotoxy(70,1); printf("%c",187);		//esq sup der
	 		
	for (y=2; y<17; y++){ 				//vertical derecha
		gotoxy(70,y);	
		printf("%c",186);  
		}
		
	for (x=2; x<70; x++) { 				//linea intermedia
		gotoxy(x,6);
		printf("%c",205);
		}  
		
	gotoxy(1,16); printf("%c",200);		//esq inf izq
	
	for (x=2; x<70; x++){ 				//borde inferior
		gotoxy(x,16);
		printf("%c",205); 
	}
	
	gotoxy(70,16); printf("%c",188); 	//esq inf der
	//fin dibujo de marco
}

void dibujarMarco2() {
	int x,y;
	
	system ("color 0a");
	//inicio dibujo de marco
	gotoxy(1,1); printf("%c",201); 		//esq sup izq    
  	
  	for (x=2; x<70; x++) { 				//borde superior
	  	gotoxy(x,1);
		printf("%c",205);
  	  	} 
  	
  	for (y=2; y<6; y++){ 				//vertical izquierda
		gotoxy(1,y);
		printf("%c",186); 
		}
  	
  	gotoxy(70,1);	printf("%c",187);	//esq sup der
	 		
	for (y=2; y<6; y++){ 				//vertical izquierda
		gotoxy(70,y);
		printf("%c",186); 
		}
		
	gotoxy(1,6);	printf("%c",200);	//esq inf izq
	gotoxy(70,6);	printf("%c",188);	//esq inf der
	
	for (x=2; x<70; x++) { 				//borde inferior
	  	gotoxy(x,6);
		printf("%c",205);
  	  	} 
	
	//fin dibujo de marco2
}

