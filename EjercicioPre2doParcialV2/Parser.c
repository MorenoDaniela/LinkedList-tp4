#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Parser.h"
#include "Empleado.h"

int parser_parseEmpleados(FILE* fileName, Arraylist* listaEmpleados)
{
    int retorno=-1;
    char auxNombre[500];
    char auxId[500];
    char auxHoras[500];
    //char auxSueldo[500];
    int flag=0;

    Empleado* pAuxEmployee;

    if (fileName!=NULL && listaEmpleados!=NULL)
    {
        while (!feof(fileName))
        {
            fscanf(fileName,"%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras);

            if (flag==0)
            {
                flag++;
                continue;
            }
            pAuxEmployee = Empleado_newParametros(auxId,auxNombre,auxHoras);
            //printf ("ID %s NOMBRE: %s HORAS: %s\n",auxId,auxNombre,auxHoras);
            if (pAuxEmployee !=NULL)
            {
                ll_add(listaEmpleados,pAuxEmployee);

                retorno=0;
            }
        }
        fclose(fileName);
    }

    return retorno;
}

int controller_loadFromText(char* path , Arraylist* pArrayListEmployee)
{
    int retorno=0;
    FILE* pFile = NULL;

    if (path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "r");

                if (pFile!=NULL)
                {
                    ll_clear(pArrayListEmployee);
                    if (!parser_parseEmpleados(pFile,pArrayListEmployee))
                    {
                        retorno=1;
                        printf ("Carga ok.\n");
                    }
                }
        fclose (pFile);
    }
    return retorno;
}
