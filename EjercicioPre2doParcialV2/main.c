#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "Arraylist.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName, Arraylist* listaEmpleados);

int main()
{
    // Definir lista de empleados
    Arraylist* listaEmpleados =  ll_newArraylist();
    Arraylist* listaNueva = ll_newArraylist();

    // Crear lista empledos
    //...

    // Leer empleados de archivo data.csv
    /*
    if(controller_loadFromText("data.csv",listaEmpleados)==1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados\n");
        ll_map(listaEmpleados,em_calcularSueldo);

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==0)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");
    }
    else
        printf("Error leyendo empleados\n");
        */


        controller_loadFromText("sueldos.csv",listaEmpleados);
        //ll_map(listaEmpleados,sacarMayores);
        listaNueva = ll_filter(listaEmpleados,sacarMayores);
        generarArchivoSueldos("sinMayores.csv",listaNueva);


    return 0;
}

int generarArchivoSueldos(char* path,Arraylist* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int lenth;
    int id;
    char name[4096];
    int horas;
    int sueldo;

    Empleado *pEmployee=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            lenth= ll_len(pArrayListEmployee);
            for(i=0;i<lenth;i++)
            {
                pEmployee =ll_get(pArrayListEmployee,i);
                if ( pEmployee!=NULL &&
                    !Empleado_getId(pEmployee,&id) &&
                    !Empleado_getNombre(pEmployee,name) &&
                    !Empleado_getHorasTrabajadas(pEmployee,&horas) &&
                    !Empleado_getSueldo(pEmployee,&sueldo))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",id,name,horas,sueldo);
                    }else
                        Empleado_delete(pEmployee);
            }
            retorno = 0;
        }
        if (retorno==0)
        {
            printf ("\nLista guardada correctamente.\n");
        }else
            printf ("\nNo se pudo guardar la lista correctamente.\n");
        fclose(pFile);
    }
    return retorno;
}
