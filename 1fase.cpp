// Ejecutar el archivo "script.sql", el cual creará la base "alumnos2" y
// la tabla "alumnos2", ademas de unos datos para la misma.

#include "sql_db.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Definición de estructura
struct persona{ 
   int id; 
   char nombre[100] ; 
   char correo[50]; 
   float promedio; 
   float n1;
   float n2;
   float n3;
   float n4;
   char seccion [5];
   int grado;
   
};

typedef struct persona Persona;

struct grado{ 

   char nombre[100]; 
   char nivel[10];
   char seccion [10];
     
};

typedef struct grado Grado;

// Objeto global
sql_db obj_mysql("localhost", "root", "Abc123**", "umg");

// Prototipos de metodos
void ingresar(), insertar(Persona info), ingresargrado(), insertargrado(Grado info) ; 
void buscar(), buscargrado(),modificar(), actualizar(Persona info), eliminar();
void ordenar(), mostrar(),ingresarnotas(), insertarnotas(Persona info), mostrargrado(); 
char menu(void); void pausa();

int main(int argc, char *argv[])
{
   system("CLS"); 
   char op; 

   for(;;) 
   { 
     fflush(stdin);
     switch(op=menu()) 
     { 
        case '1': 
           ingresar(); 
           pausa(); 
           break; 
        case '2': 
           ingresargrado(); 
           pausa();
           break; 
        case '3': 
           modificar(); 
           pausa(); 
           break; 
        case '4': 
           buscar(); 
           pausa(); 
           break; 
        case '5': 
           buscargrado(); 
           pausa();
           break; 
        case '6': 
           eliminar(); 
           pausa();
           break;
        case '9': 
           mostrar(); 
           pausa(); 
           break; 
        case '7': 
           modificar();
           pausa(); 
           break;   
		case '10': 
           mostrargrado();
           pausa(); 
           break; 		        
        default : 
           cout << "Opcion no valida intente nuevamente"; 
           pausa();
           break; 
     } 

     if(op=='7') break; 
     system("CLS"); 
   } 

   return 0;
}
