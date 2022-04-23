//
void buscargrado()
{
   char idgrado[10];
   char *consulta;
   char sentencia[] =  "SELECT * FROM grado WHERE id=\'%s\'";
   MYSQL_RES *res;
   MYSQL_ROW  row;   
   
   cout << "Ingrese el Id a buscar del grado: ";
   cin >> idgrado;
   
   consulta = new char[strlen(sentencia)+strlen(idgrado)];   
   sprintf(consulta, sentencia, idgrado);
   res = obj_mysql.ejecutar_sql(consulta);
   
   if(obj_mysql.filas_afectadas()>0)
   {
       row = obj_mysql.obtener_fila(res);
	   cout << "Id Interno: " << row[0] << endl;
	   cout << "Nombre de grado: " << row[1] << endl;	   
	   cout << "Nivel Academico: " << row[2] << endl;	   
	   cout << "Seccion: " << row[3] << endl;
	        	   
   }
   else
      cout << "Grado o nivel Academico no Encontrado" << endl;
}

void modificar()
{
   char correo[20];
   char *consulta;
   char *temp;
   char sentencia_buscar[] = "SELECT * FROM alumnos2 WHERE correo = \'%s\'";
   MYSQL_RES *res;
   MYSQL_ROW  row;   
   Persona info;
   cout << "Ingrese ID correo electronico a modificar : ";
   cin >> correo;

   consulta = new char[strlen(sentencia_buscar)+strlen(correo)];   
   sprintf(consulta, sentencia_buscar, correo);
   res = obj_mysql.ejecutar_sql(consulta);

   if(obj_mysql.filas_afectadas()>0)
   {
       row = obj_mysql.obtener_fila(res);
       sprintf(temp, "%s", row[0]);
       int id = atoi(temp);  
       cout << "Ingrese nota #1 ";
       cin >> info.n1;
       cout << "Ingrese nota #2 ";
       cin >> info.n2;
       cout << "Ingrese nota #3 ";
       cin >> info.n3;
       cout << "Ingrese nota #4 ";
       cin >> info.n4;         
       actualizar(info);
       cout << "Datos actualizados exitosamente" << endl;       
   }
   else
      cout << "Persona no encontrada" << endl;
} 

void actualizar(Persona info)
{
   char nombre[20];
   char *consulta;
   char sentencia[] = "UPDATE alumnos2 SET n1=\'%s\', n2=\'%s\', n3=%d, n4=\'%s\' WHERE id=%d";
   
   consulta = new char[strlen(sentencia)+strlen(nombre)];   
   sprintf(consulta, sentencia, info.nombre, info.correo, info.n1, info.n2, info.id);
   obj_mysql.ejecutar_sql(consulta);
} 
void eliminar() 
{ 
   char correo[20];
   char *consulta;
   char *temp;
   char sentencia_buscar[] = "SELECT * FROM alumnos2 WHERE correo=\'%s\'";
   char sentencia_eliminar[] = "DELETE FROM alumnos2 WHERE id=%d";
   MYSQL_RES *res;
   MYSQL_ROW  row;   
   Persona info;
   
   cout << "Ingrese ID correo electronico a eliminar: ";
   cin >> correo;

   consulta = new char[strlen(sentencia_buscar)+strlen(correo)];   
   sprintf(consulta, sentencia_buscar, correo);
   res = obj_mysql.ejecutar_sql(consulta);

   if(obj_mysql.filas_afectadas()>0)
   {
       row = obj_mysql.obtener_fila(res);
       sprintf(temp, "%s", row[0]);
       int id = atoi(temp);
       consulta = new char[strlen(sentencia_eliminar)+sizeof(int)];   
       sprintf(consulta, sentencia_eliminar, id);
       obj_mysql.ejecutar_sql(consulta);
       cout << "Datos eliminados exitosamente" << endl;       
   }
   else
      cout << "Persona no encontrada" << endl;
} 
