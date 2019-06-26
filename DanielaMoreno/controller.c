#ifndef CONTROLLER_C_INCLUDED
#define CONTROLLER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
                        printf ("Carga Entregas ok.\n");
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
                    printf("ID:%d Nombre: %s Cantidad: %d Importe: %.2f\n",auxId, bufferName, auxCantidad, bufferImporte);
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

int entregasFiltroGold(void* p)
{
    int retorno = 0;
    Entregas* auxEntrega = (Entregas*)p;

    if (strcmp(auxEntrega->nombre,"GOLD")==0)
    {
        retorno=1;
    }
    return retorno;
}

int entregasFiltroPlus(void* p)
{
    int retorno = 0;
    Entregas* auxEntrega = (Entregas*)p;

    if (strcmp(auxEntrega->nombre,"PLUS")==0)
    {
        retorno=1;
    }
    return retorno;
}

int entregasFiltroRegular(void* p)
{
    int retorno = 0;
    Entregas* auxEntrega = (Entregas*)p;

    if (strcmp(auxEntrega->nombre,"REGULAR")==0)
    {
        retorno=1;
    }
    return retorno;
}

int cantidadEntregada(LinkedList* pArrayList)
{
    int retorno=-1;
    int i;
    int cantidadEntregada=0;
    int acumulador=0;

    if (pArrayList!=NULL)
    {
        Entregas* pAux;
        for (i=0;i<ll_len(pArrayList);i++)
        {
            pAux=ll_get(pArrayList,i);
            if(Entregas_getCantidad(pAux,&cantidadEntregada)==0)
            {
                acumulador = cantidadEntregada+acumulador;
            }
            retorno=acumulador;
            //printf("Acumulador: %d",acumulador);
        }

    }
    return retorno;
}

float importeTotal(LinkedList* pArrayList)
{
    float retorno=-1;
    int i;
    float importeTotal;
    float acumuladorImporte;

    if (pArrayList!=NULL)
    {
        Entregas* pAux;
        for (i=0;i<ll_len(pArrayList);i++)
        {
            pAux=ll_get(pArrayList,i);
            if (Entregas_getImporte(pAux,&importeTotal)==0)
            {
                acumuladorImporte=importeTotal+acumuladorImporte;
            }
            retorno=acumuladorImporte;
        }
    }
    return retorno;

}


int controller_saveAsTextInformes(char* path , LinkedList* pArrayListEntregas)
{
    int retorno = -1;
    int totalEntregas=0;
    int gold=0;
    int regular=0;
    int plus=0;
    int bultosEntregados=0;
    float promedioBultosPorEntrega=0;
    float promedioPorEntrega=0;

    //Entregas *pEntregas=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEntregas != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            totalEntregas= ll_len(pArrayListEntregas);
            gold=ll_count(pArrayListEntregas,entregasFiltroGold);
            regular=ll_count(pArrayListEntregas,entregasFiltroRegular);
            plus=ll_count(pArrayListEntregas,entregasFiltroPlus);


            bultosEntregados=cantidadEntregada(pArrayListEntregas);
            promedioBultosPorEntrega=bultosEntregados/(float)totalEntregas;
            promedioPorEntrega=importeTotal(pArrayListEntregas)/totalEntregas;

            fprintf(pFile, "*****************************\nInforme de Ventas\n*****************************\n");
            fprintf(pFile, "- Cantidad Total de Entregas: %d\n", totalEntregas);
            fprintf(pFile, "- Cantidad de Entregas por Tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n", gold, regular, plus);
            fprintf(pFile, "- Cantidad Total de Bultos Entregados: %d\n", bultosEntregados);
            fprintf(pFile, "- Promedio de Bultos por Entrega: %.2f\n", promedioBultosPorEntrega);
            fprintf(pFile, "- Importe promedio por Entrega: %.2f\n", promedioPorEntrega);
            fprintf(pFile, "*****************************");

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
