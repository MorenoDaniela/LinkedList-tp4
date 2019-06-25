#ifndef PARSER_C_INCLUDED
#define PARSER_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Entregas.h"

int parser_EntregasFromText(FILE* pFile , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    char auxId[500];
    char auxNombre[500];
    char auxCantidad[500];
    char auxImporte[500];
    //int flag=0;

    Entregas* pAuxEntregas;

    if (pFile!=NULL && pArrayListEntregas!=NULL)
    {
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^;];%[^;];%[^;];%[^\n]\n",auxId,auxNombre,auxCantidad,auxImporte);

            //if (flag==0)
            //{
              //  flag++;
                //continue;
            //}
            pAuxEntregas = Entregas_newParametros(auxId,auxNombre,auxCantidad,auxImporte);
            if (pAuxEntregas !=NULL)
            {
                ll_add(pArrayListEntregas,pAuxEntregas);
                retorno=0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}

#endif // PARSER_C_INCLUDED
