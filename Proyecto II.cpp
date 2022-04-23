

void ingresar() 
{ 
   Persona info;  
 
   
   cout << "Ingrese nombre de alumno: "<<endl;
   cin >> info.nombre;
   cout << "Ingrese correo electronico: "<<endl;
   cin >> info.correo; 
      
   insertar(info);
   cout << "Alumno ingresado Correctamente" << endl;
}

void ingresarnotas() 
{ 
   char id[10];
   Persona info;  
   cout << "Ingrese id alumno a modificar: ";
   cin >> id;
   cout << "Ingrese nota Bimestre #1 de alumno: "<<endl;
   cin >> info.n1;
   cout << "Ingrese nota Bimestre #2 de alumno: "<<endl;
   cin >> info.n2;
   cout << "Ingrese nota Bimestre #3 de alumno: "<<endl;
   cin >> info.n3;
   cout << "Ingrese nota Bimestre #4 de alumno: "<<endl;
   cin >> info.n4; 
   insertarnotas(info);
   cout << "notas ingresadas Correctamente" << endl;
}


void ingresargrado() 
{ 
   Grado info;  
 
   cout << "Ingrese nombre del grado "<<endl;
   cin >> info.nombre;
   cout << "Ingrese nivel o codigo de grado "<<endl;
   cin >> info.nivel; 
   cout << "Ingrese la seccion "<<endl;
   cin >> info.seccion; 
   insertargrado(info);
   cout << "Grado agregado correctamente" << endl;
}

void insertar(Persona info) 
{  
   char *consulta;
   char sentencia[] = "INSERT INTO alumnos2(id,nombre,correo) VALUES(NULL,\'%s\',\'%s\' )";
   
   consulta = new char[strlen(sentencia)+sizeof(Persona)-sizeof(int)];   
   sprintf(consulta, sentencia,info.nombre, info.correo);
   
   obj_mysql.ejecutar_sql(consulta);
} 

void insertargrado(Grado info) 
{  
   char *consulta;
   char sentencia[] = "INSERT INTO grado(id,nombre,nivel,seccion) VALUES(NULL,\'%s\',\'%s\',\'%s\' )";
   
   consulta = new char[strlen(sentencia)+sizeof(Persona)-sizeof(int)];   
   sprintf(consulta, sentencia,info.nombre, info.nivel,info.seccion);
   
   obj_mysql.ejecutar_sql(consulta);
} 
void insertarnotas(Persona info) 
{  
   char *consulta;
   char sentencia[] = "UPDATE alumnos2 SET n1=\'%s\', n2=\'%s\', n3=\'%s\' ,n4=\'%s\' WHERE id=%d ";
   consulta = new char[strlen(sentencia)+sizeof(Persona)-sizeof(int)];   
   sprintf(consulta, sentencia,info.n1, info.n2,info.n3,info.n4);
   
   obj_mysql.ejecutar_sql(consulta);
} 

void buscar()
{
   char correo[20];
   char *consulta;
   char sentencia[] =  "SELECT * FROM alumnos2 WHERE correo=\'%s\'";
   MYSQL_RES *res;
   MYSQL_ROW  row;   
   
   cout << "Ingrese Correo Electronico a buscar: ";
   cin >> correo;
   
   consulta = new char[strlen(sentencia)+strlen(correo)];   
   sprintf(consulta, sentencia, correo);
   res = obj_mysql.ejecutar_sql(consulta);
   
   if(obj_mysql.filas_afectadas()>0)
   {
       row = obj_mysql.obtener_fila(res);
	   cout << "Id: " << row[0] << endl;
	   cout << "Nombre: " << row[1] << endl;	   
	   cout << "Correo: " << row[2] << endl;	   
	   cout << "Promedio: " << row[3] << endl;
	   cout << "Nota bimestre # 1: " << row[4] << endl;   
	   cout << "Nota bimestre # 2: " << row[5] << endl; 
	   cout << "Nota bimestre # 3: " << row[6] << endl;     
	   cout << "Nota bimestre # 4: " << row[7] << endl;  
	   cout << "Seccion: " << row[8] << endl;    
	    cout << "Grado o Nivel Academico: " << row[9] << endl;  
   }
   else
      cout << "Persona no encontrada" << endl;
}


