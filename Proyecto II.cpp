// funcion ordenar
void ordenar() 
{   
   MYSQL_RES *res;
   MYSQL_ROW row;
   int filas, columnas;
   
   res = obj_mysql.ejecutar_sql("SELECT * FROM alumnos2 ORDER BY id");
   filas = obj_mysql.numero_filas(res);
   columnas = obj_mysql.numero_columnas(res);
   
   cout << "--- Listado de personas por ID de Alumnos ("  << filas << ") ---" << endl; 
   
   for(int j=0; j<columnas; j++)
       cout << obj_mysql.nombre_columna(res, j) <<  " - ";
   cout << endl;

   while(row = obj_mysql.obtener_fila(res)) 
   {
       for(int j=0; j<columnas; j++)
       {
           cout << row[j] << ", ";
       }
       cout << endl;
   }    
   cout << "Se han ordenado todos los registros por: ID" << endl; 
} 

void mostrar() 
{ 
   MYSQL_RES *res;
   MYSQL_ROW row;
   int filas, columnas;
   
   res = obj_mysql.ejecutar_sql("SELECT * FROM alumnos2");
   filas = obj_mysql.numero_filas(res);
   columnas = obj_mysql.numero_columnas(res);
   
   cout << "--- Listado de personas ("  << filas << ") ---" << endl; 
   
   for(int j=0; j<columnas; j++)
       cout << obj_mysql.nombre_columna(res, j) <<  " - ";
   cout << endl;

   while(row = obj_mysql.obtener_fila(res)) 
   {
       for(int j=0; j<columnas; j++)
       {
           cout << row[j] << ", ";
       }
       cout << endl;
   }   
} 

void mostrargrado() 
{ 
   MYSQL_RES *res;
   MYSQL_ROW row;
   int filas, columnas;
   
   res = obj_mysql.ejecutar_sql("SELECT * FROM grado");
   filas = obj_mysql.numero_filas(res);
   columnas = obj_mysql.numero_columnas(res);
   
   cout << "--- Listado de grados o nivel academica ("  << filas << ") ---" << endl; 
   
   for(int j=0; j<columnas; j++)
       cout << obj_mysql.nombre_columna(res, j) <<  " - ";
   cout << endl;

   while(row = obj_mysql.obtener_fila(res)) 
   {
       for(int j=0; j<columnas; j++)
       {
           cout << row[j] << ", ";
       }
       cout << endl;
   }   
} 

char menu(void) 
{ 
   //char c; 
   int c;
   cout << "** SISTEMA DE ALUMNOS PROYECTO II**" <<endl;
   cout << "(1) AGREGAR ALUMNO" <<endl;
   cout << "(2) AGREGAR UN GRADO" <<endl;
   cout << "(3) AGREGAR UNA NOTA" <<endl;
   cout << "(4) BUSCAR UN ALUMNO" <<endl;
   cout << "(5) BUSCAR UN GRADO"  <<endl;
   cout << "(6) BORRAR UN ALUMNO O GRADO" <<endl;
   cout << "(7) MODIFICAR LOS DATOS DE UN ALUMNO"<<endl;
   cout << "(8) MODIFICAR LOS DATOS DE UN GRADO"<<endl;
   cout << "(9) LISTAR LOS ALUMNOS DE UN GRADO Y SECCION"<<endl;
  // cout << "(10) LISTAR LOS ALUMNOS DE UN GRADO Y SECCION"<<endl;
     
   cout<<"Seleccion: "; 
   c=getchar(); 
   cout << endl; 
   return(c); 
}

void pausa()
{
   cout << endl;
   system("PAUSE");
   cout << endl;
}

