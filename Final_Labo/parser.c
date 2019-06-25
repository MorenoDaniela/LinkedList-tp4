#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Client.h"

int parser_ClientFromText(FILE* pFile , LinkedList* pArrayListClient)
{
    int retorno=-1;
    char auxId[500];
    char auxNombre[500];
    char auxApellido[500];
    char auxDni[500];
    //int flag=0;

    Client* pAuxClient;

    if (pFile!=NULL && pArrayListClient!=NULL)
    {
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxApellido,auxDni);

            //if (flag==0)
            //{
              //  flag++;
                //continue;
            //}
            pAuxClient = client_newParametros(auxId,auxNombre,auxApellido,auxDni);
            if (pAuxClient !=NULL)
            {
                ll_add(pArrayListClient,pAuxClient);
                retorno=0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}
//int parser_ClientFromBinary(FILE* pFile , LinkedList* pArrayListClient);
int parser_VentaFromText(FILE* pFile , LinkedList* pArrayListVenta)
{
    int retorno=-1;
    char auxId[4000];
    char auxIdCliente[4000];
    char auxCodigo[4000];
    char auxCantidad[4000];
    char auxPrecio[4096];
    //int flag=0;

    Venta* pAuxVenta;

    if (pFile!=NULL && pArrayListVenta!=NULL)
    {
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxIdCliente,auxCodigo,auxCantidad,auxPrecio);

            //if (flag==0)
            //{
              //  flag++;
                //continue;
            //}
            pAuxVenta = venta_newParametros(auxId,auxIdCliente,auxCodigo,auxCantidad,auxPrecio);
            if (pAuxVenta !=NULL)
            {
                ll_add(pArrayListVenta,pAuxVenta);
                retorno=0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}
