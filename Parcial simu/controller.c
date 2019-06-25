#ifndef CONTROLLER_C_INCLUDED
#define CONTROLLER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entregas.h"
#include "parser.h"
#include "funciones.h"
#include "controller.h"
#define MAX_ID 1000000
#define SORT_DOWN 0
#define SORT_UP 1

int controller_loadFromText(char* path , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    //int opcion;
    FILE* pFile = NULL;

    if (path!=NULL && pArrayListEntregas!=NULL)
    {
        pFile = fopen (path, "r");
        //getInt("Esta a punto de cargar la lista: \nSi desea conservar los cambios hechos debe volver al menu y elegir la opcion 8.\n"
          //      "Si ya ha guardado los cambios o esta es la primera vez que carga la lista solo seleccione continuar.\n\n 1-Volver al menu.\n 2-Continuar.\n","Error, opcion invalida.\n",1,2,3,&opcion);
            //if(opcion==2)
            //{
                if (pFile!=NULL)
                {
                    ll_clear(pArrayListEntregas);
                    if (!parser_EntregasFromText(pFile,pArrayListEntregas))
                    {
                        retorno=0;
                        printf ("Carga Entregases ok.\n");
                    }
                }
            //}
        fclose (pFile);
    }
    return retorno;
}



int controller_ListEntregas(LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    Entregas* pEntregas;
    int auxId;
    int auxCantidad;
    char bufferName[4000];
    float bufferImporte;
    int length;
    int i;

    if (pArrayListEntregas!=NULL)
    {
        length=ll_len(pArrayListEntregas);
        for (i=0;i<length;i++)
        {
            pEntregas = ll_get(pArrayListEntregas,i);
            if (pEntregas!=NULL)
            {
                if (!Entregas_getId(pEntregas,&auxId) &&
                !Entregas_getNombre(pEntregas, bufferName) &&
                !Entregas_getCantidad(pEntregas,&auxCantidad) &&
                !Entregas_getImporte(pEntregas,&bufferImporte))
                {
                    printf("ID:%d Nombre: %s Cantidad: %d Importe: %f\n",auxId, bufferName, auxCantidad, bufferImporte);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    int i;
    int lenth;
    int id;
    char name[4096];
    int cantidad;
    float importe;

    Entregas *pEntregas=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEntregas != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            lenth= ll_len(pArrayListEntregas);
            for(i=0;i<lenth;i++)
            {
                pEntregas =ll_get(pArrayListEntregas,i);
                if ( pEntregas!=NULL &&
                    !Entregas_getId(pEntregas,&id) &&
                    !Entregas_getNombre(pEntregas,name) &&
                    !Entregas_getCantidad(pEntregas,&cantidad) &&
                    !Entregas_getImporte(pEntregas,&importe))
                    {
                        fprintf(pFile,"%d,%s,%d,%f\n",id,name,cantidad,importe);
                    }else
                        Entregas_delete(pEntregas);
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





#endif // CONTROLLER_C_INCLUDED
