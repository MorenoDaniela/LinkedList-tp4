#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Client.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"
#define MAX_ID 1000000
#define SORT_DOWN 0
#define SORT_UP 1

int controller_loadFromText(char* path , LinkedList* pArrayListClient)
{
    int retorno=-1;
    //int opcion;
    FILE* pFile = NULL;

    if (path!=NULL && pArrayListClient!=NULL)
    {
        pFile = fopen (path, "r");
        //getInt("Esta a punto de cargar la lista: \nSi desea conservar los cambios hechos debe volver al menu y elegir la opcion 8.\n"
          //      "Si ya ha guardado los cambios o esta es la primera vez que carga la lista solo seleccione continuar.\n\n 1-Volver al menu.\n 2-Continuar.\n","Error, opcion invalida.\n",1,2,3,&opcion);
            //if(opcion==2)
            //{
                if (pFile!=NULL)
                {
                    ll_clear(pArrayListClient);
                    if (!parser_ClientFromText(pFile,pArrayListClient))
                    {
                        retorno=0;
                        printf ("Carga clientes ok.\n");
                    }
                }
            //}
        fclose (pFile);
    }
    return retorno;
}
//int controller_loadFromBinary(char* path , LinkedList* pArrayListClient);
int controller_addClient(LinkedList* pArrayListClient)
{
    int retorno=-1;
    Client* pAuxClient = client_new();
    int bufferDni;
    char bufferName[4000];
    char bufferApellido[4000];
    int ID;

    if (pArrayListClient!=NULL && pAuxClient!=NULL)
    {
        ID=controller_maxId(pArrayListClient);
        if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",2,35,3,bufferName)==0 &&
            getName("Ingrese apellido: ","Error, apellido no valido.\n",2,50,3,bufferApellido)==0 &&
            getInt("Ingrese dni: ","Error, dni no valido.\n",999999,60000000,3,&bufferDni)==0)
            {
                client_setId(pAuxClient,ID);
                client_setNombre(pAuxClient,bufferName);
                client_setApellido(pAuxClient,bufferApellido);
                client_setDni(pAuxClient,bufferDni);
                ll_add(pArrayListClient,pAuxClient);
                printf ("Cliente agregado correctamente.\n");
                retorno=0;
            }else
                printf ("\nNo se pudo agregar el cliente nuevo.\n");
    }
    return retorno;
}
int controller_editClient(LinkedList* pArrayListClient)
{
    int retorno=-1;
    int bufferDni;
    char bufferNombre[4000];
    char bufferApellido[4000];
    int ID;
    int index;
    int opcion;
    Client* pAux;

    if (pArrayListClient!=NULL)
    {
        if (getInt("\nIngrese id del Cliente para modificar sus datos: \n","Error, id no valido.",1,MAX_ID,3,&ID)==0)
        {
            index = controller_returnIndex(pArrayListClient,&ID);
            pAux = ll_get(pArrayListClient,index);
            printf ("\n El id del Cliente a modificar es: %d\n",ID);
            if (index!=-1 && pAux!=NULL)
            {
                do
                {
                    getInt ("Ingrese opcion a modificar:\n 1-Nombre.\n 2-Apellido.\n 3-DNI.\n 4-Salir de modificacion.\n","Error, opcion no valida.\n",1,4,3,&opcion);
                    switch (opcion)
                    {
                    case 1:
                        if (getName("Ingrese nuevo nombre del Cliente: \n","Error, nombre no valido.\n",2,50,3,bufferNombre)==0)
                        {
                            client_setNombre(pAux,bufferNombre);
                            printf("\nModificacion exitosa.\n");
                            retorno=0;
                        }else
                            printf ("\nModificacion sin exito.\n");
                        break;
                    case 2:
                        fflush(stdin);
                        if (getName("Ingrese nuevo apellido: \n","Error, apellido no valido.\n",2,50,3,bufferApellido)==0)
                        {
                            client_setApellido(pAux,bufferApellido);
                            printf("\nModificacion exitosa.\n");
                            retorno=0;
                        }else
                            printf ("\nModificacion sin exito.\n");
                        break;
                    case 3:
                        fflush(stdin);
                        if (getInt("Ingrese dni: \n","Error, dni no validas.\n",999999,70000000,3,&bufferDni)==0)
                        {
                            client_setDni(pAux,bufferDni);
                            printf("\nModificacion exitosa.\n");
                            retorno=0;
                        }else
                            printf ("\nModificacion sin exito.\n");
                        break;
                    case 4:
                        break;
                    }
                }while(opcion!=4);
            }
        }
    }
    return retorno;
}

int controller_removeClient(LinkedList* pArrayListClient, LinkedList* pArrayListVentas)
{
    int retorno=-1;
    int ID;
    int index;
    Client* pAux=NULL;

    if (pArrayListClient!=NULL)
    {
        if (getInt("Ingrese id del Cliente a dar de baja: ","Error, id no valido.\n",1,MAX_ID,3,&ID)==0)
        {
            index=controller_returnIndex(pArrayListClient,&ID);

            if (index!=-1 && controller_findIdClientEnVentas(pArrayListVentas,&ID)==-2)
            {
                pAux=ll_pop(pArrayListClient,index);
                if (pAux!=NULL)
                {
                    client_delete(pAux);
                    printf ("\nBaja exitosa del Cliente con id: %d.\n",ID);
                    retorno=0;
                }else
                    printf ("\nNo se pudo dar de baja.\n");
            }else
                printf ("\nNo se encontro el id. Intente de nuevo.\n");
        }
    }
    return retorno;
}

int controller_ListClient(LinkedList* pArrayListClient)
{
    int retorno=-1;
    Client* pCliente;
    int auxId;
    int auxDni;
    char bufferName[4000];
    char bufferApellido[4000];
    int length;
    int i;

    if (pArrayListClient!=NULL)
    {
        length=ll_len(pArrayListClient);
        for (i=0;i<length;i++)
        {
            pCliente = ll_get(pArrayListClient,i);
            if (pCliente!=NULL)
            {
                if (!client_getId(pCliente,&auxId) &&
                !client_getNombre(pCliente, bufferName) &&
                !client_getApellido(pCliente,bufferApellido) &&
                !client_getDni(pCliente,&auxDni))
                {
                    printf("ID:%d Nombre: %s Apellido: %s Dni: %d\n",auxId, bufferName, bufferApellido, auxDni);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int controller_sortClient(LinkedList* pArrayListClient)
{
    int retorno=-1;

    if (pArrayListClient!=NULL)
    {
        ll_sort(pArrayListClient,client_compararNombre,SORT_UP);
        retorno=0;
    }
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListClient)
{
    int retorno = -1;
    int i;
    int lenth;
    int id;
    char name[4096];
    char apellido[4096];
    int dni;

    Client *pClient=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListClient != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            lenth= ll_len(pArrayListClient);
            for(i=0;i<lenth;i++)
            {
                pClient =ll_get(pArrayListClient,i);
                if ( pClient!=NULL &&
                    !client_getId(pClient,&id) &&
                    !client_getNombre(pClient,name) &&
                    !client_getApellido(pClient,apellido) &&
                    !client_getDni(pClient,&dni))
                    {
                        fprintf(pFile,"%d,%s,%s,%d\n",id,name,apellido,dni);
                    }else
                        client_delete(pClient);
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
//int controller_saveAsBinary(char* path , LinkedList* pArrayListClient)
int controller_findIdClient(LinkedList* pArrayListClient, int* idBuscada)
{
    int retorno=-1;
    int lenth;
    int ID;
    int i;
    Client* pAuxClient;

    lenth= ll_len(pArrayListClient);

    if (pArrayListClient!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxClient=ll_get(pArrayListClient,i);
            if (pAuxClient!=NULL)
            {
                 client_getId(pAuxClient,&ID);
                if (ID==*idBuscada)
                {
                    *idBuscada=ID;
                    retorno=0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int controller_maxId(LinkedList* pArrayClient)
{
    int retorno=-1;
    int lenth;
    int ID;
    int maxID=0;
    int i;
    Client* pAuxClient;

    lenth= ll_len(pArrayClient);

    if (pArrayClient!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxClient=ll_get(pArrayClient,i);
            if (pAuxClient!=NULL)
            {
                 client_getId(pAuxClient,&ID);
                if (ID>maxID)
                {
                    maxID=ID;
                }
            }
        }
        maxID=maxID+1;
        retorno=maxID;
    }
    return retorno;
}
int controller_returnIndex(LinkedList* pArrayClient,int* valorBuscado)
{
    int retorno=-1;
    int i;
    int ID;
    int lenth = ll_len(pArrayClient);
    Client* pAuxClient;

    if (pArrayClient!=NULL && valorBuscado!=NULL)
    {
        for (i=0;i<=lenth;i++)
        {
            pAuxClient= ll_get(pArrayClient,i);
            client_getId(pAuxClient,&ID);
            if (ID==*valorBuscado)
            {
                *valorBuscado=ID;
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int ll_sort2(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int swap;
    void* element1;
    void* element2;
    //void* auxiliar;

    if (this!=NULL && (order==0 || order==1) && pFunc!=NULL)
    {
        while(swap)
        {
            swap=0;
            for (i=0;i<ll_len(this)-1;i++)
            {
                element1=ll_get(this,i);
                element2=ll_get(this,i+1);
                //auxiliar=ll_get(this,i);

                if ( ((pFunc(element1,element2)>0) && order==1) ||//ascendente a-z 1-10// el 1 es mas grande que el 2
                    ((pFunc(element1,element2)<0) && order==0))//descendente z-a 10-1//el 2 es mas grande que el 1
                {
                    swap=1;
                    ll_set(this,i,element2);
                    ll_set(this,i+1,element1);//aca element1 x auxiliar probar
                }else continue;

                /*
                if ( pFunc(element1,element2)<0 && order==0)//descendente z-a 10-1//el 2 es mas grande que el 1
                {
                    ll_set(this,i,element2);
                    ll_set(this,i+1,auxiliar);
                }else
                    continue;*/
            }
        }//while(flagSwap);
        returnAux=0;
    }
    return returnAux;

}

int controller_loadFromTextVenta(char* path , LinkedList* pArrayListVenta)
{
    int retorno=-1;
    //int opcion;
    FILE* pFile = NULL;

    if (path!=NULL && pArrayListVenta!=NULL)
    {
        pFile = fopen (path, "r");
        //getInt("Esta a punto de cargar la lista: \nSi desea conservar los cambios hechos debe volver al menu y elegir la opcion 8.\n"
          //      "Si ya ha guardado los cambios o esta es la primera vez que carga la lista solo seleccione continuar.\n\n 1-Volver al menu.\n 2-Continuar.\n","Error, opcion invalida.\n",1,2,3,&opcion);
            //if(opcion==2)
            //{
                if (pFile!=NULL)
                {
                    ll_clear(pArrayListVenta);
                    if (!parser_VentaFromText(pFile,pArrayListVenta))
                    {
                        retorno=0;
                        printf ("Carga ventas ok.\n");
                    }
                }
            //}
        fclose (pFile);
    }
    return retorno;
}

int controller_ListVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    Venta* pVenta;
    int auxIdVenta;
    int auxIdCliente;
    int auxCodigo;
    int auxCantidad;
    float auxPrecio;
    int length;
    int i;

    if (pArrayListVenta!=NULL)
    {
        length=ll_len(pArrayListVenta);
        for (i=0;i<length;i++)
        {
            pVenta = ll_get(pArrayListVenta,i);
            if (pVenta!=NULL)
            {
                if (!venta_getIdVenta(pVenta,&auxIdVenta) &&
                !venta_getIdCliente(pVenta,&auxIdCliente) &&
                !venta_getCodigo(pVenta, &auxCodigo) &&
                !venta_getCantidad(pVenta,&auxCantidad) &&
                !venta_getPrecio(pVenta,&auxPrecio))
                {
                    printf("ID VENTA: %d ID CLIENTE: %d Codigo: %d Cantidad: %d Precio unitario: %.2f\n",auxIdVenta, auxIdCliente, auxCodigo, auxCantidad, auxPrecio);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int controller_maxIdVenta(LinkedList* pArrayVenta)
{
    int retorno=-1;
    int lenth;
    int ID;
    int maxID=0;
    int i;
    Venta* pAuxVenta;

    lenth= ll_len(pArrayVenta);

    if (pArrayVenta!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxVenta=ll_get(pArrayVenta,i);
            if (pAuxVenta!=NULL)
            {
                 venta_getIdVenta(pAuxVenta,&ID);
                if (ID>maxID)
                {
                    maxID=ID;
                }
            }
        }
        maxID=maxID+1;
        retorno=maxID;
    }
    return retorno;
}

int controller_addVenta(LinkedList* pArrayListVenta, LinkedList* pArrayListClient)
{
    int retorno=-1;
    Venta* pAuxVenta = venta_new();
    int idCliente;
    int codigo;
    int cantidad;
    float precio1=8999.99000;
    float precio2=12999.99000;
    float precio3=19480.99000;
    int ID;

    if (pArrayListClient!=NULL && pArrayListVenta!=NULL && pAuxVenta!=NULL)
    {
        ID=controller_maxIdVenta(pArrayListVenta);
        if (!getInt("Ingrese id del cliente que solicita la venta: ","Error, id no valido.",1,MAX_ID,3,&idCliente) &&
            !controller_findIdClient(pArrayListClient,&idCliente))
        {
            if (getInt("\nIngrese codigo del producto: \n","Error, codigo no valido.\n",1000,1002,3,&codigo)==0 &&
                getInt("Ingrese cantidad: ","Error, cantidad apellido no valido.\n",1,1000,3,&cantidad)==0)
                {
                    switch (codigo)
                    {
                    case 1000:
                        venta_setIdVenta(pAuxVenta,ID);
                        venta_setIdCliente(pAuxVenta,idCliente);
                        venta_setCodigo(pAuxVenta,codigo);
                        venta_setCantidad(pAuxVenta,cantidad);
                        venta_setPrecio(pAuxVenta,precio1);
                        ll_add(pArrayListVenta,pAuxVenta);
                        printf ("Cliente agregado correctamente.\n");
                        retorno=0;
                        break;
                    case 1001:
                        venta_setIdVenta(pAuxVenta,ID);
                        venta_setIdCliente(pAuxVenta,idCliente);
                        venta_setCodigo(pAuxVenta,codigo);
                        venta_setCantidad(pAuxVenta,cantidad);
                        venta_setPrecio(pAuxVenta,precio2);
                        ll_add(pArrayListVenta,pAuxVenta);
                        printf ("Cliente agregado correctamente.\n");
                        retorno=0;
                        break;
                    case 1002:
                        venta_setIdVenta(pAuxVenta,ID);
                        venta_setIdCliente(pAuxVenta,idCliente);
                        venta_setCodigo(pAuxVenta,codigo);
                        venta_setCantidad(pAuxVenta,cantidad);
                        venta_setPrecio(pAuxVenta,precio3);
                        ll_add(pArrayListVenta,pAuxVenta);
                        printf ("Cliente agregado correctamente.\n");
                        retorno=0;
                    break;
                    default :
                        break;
                    }

                }else
                    printf ("\nNo se pudo concretar la venta.\n");
        }
    }
    return retorno;
}

int controller_removeVenta(LinkedList* pArrayListVenta)
{
    int retorno=-1;
    int ID;
    int index;
    Venta* pAux=NULL;

    if (pArrayListVenta!=NULL)
    {
        if (getInt("Ingrese id de la venta a anular: ","Error, id no valido.\n",1,MAX_ID,3,&ID)==0)
        {
            index=controller_returnIndexVenta(pArrayListVenta,&ID);
            if (index!=-1)
            {
                pAux=ll_pop(pArrayListVenta,index);
                if (pAux!=NULL)
                {
                    venta_delete(pAux);
                    printf ("\nBaja exitosa de la venta con id: %d.\n",ID);
                    retorno=0;
                }else
                    printf ("\nNo se pudo dar de baja.\n");
            }else
                printf ("\nNo se encontro el id. Intente de nuevo.\n");
        }
    }
    return retorno;
}

int controller_returnIndexVenta(LinkedList* pArrayVenta,int* valorBuscado)
{
    int retorno=-1;
    int i;
    int ID;
    int lenth = ll_len(pArrayVenta);
    Venta* pAuxVenta;

    if (pArrayVenta!=NULL && valorBuscado!=NULL)
    {
        for (i=0;i<=lenth;i++)
        {
            pAuxVenta= ll_get(pArrayVenta,i);
            venta_getIdVenta(pAuxVenta,&ID);
            if (ID==*valorBuscado)
            {
                *valorBuscado=ID;
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int controller_saveAsTextVentas(char* path , LinkedList* pArrayListVenta)
{
    int retorno = -1;
    int i;
    int lenth;
    int id;
    int idCliente;
    int codigo;
    int cantidad;
    float precio;

    Venta *pVenta=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListVenta != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            lenth= ll_len(pArrayListVenta);
            for(i=0;i<lenth;i++)
            {
                pVenta =ll_get(pArrayListVenta,i);
                if ( pVenta!=NULL &&
                    !venta_getIdVenta(pVenta,&id) &&
                    !venta_getIdCliente(pVenta,&idCliente) &&
                    !venta_getCodigo(pVenta,&codigo) &&
                    !venta_getCantidad(pVenta,&cantidad) &&
                    !venta_getPrecio(pVenta,&precio))
                    {
                        fprintf(pFile,"%d,%d,%d,%d, %f\n",id,idCliente,codigo,cantidad,precio);
                    }else
                        venta_delete(pVenta);
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

int controller_findIdClientEnVentas(LinkedList* pArrayListVenta, int* idBuscada)
{
    int retorno=-1;
    int lenth;
    int ID;
    int i;
    Venta* pAuxVenta;

    lenth= ll_len(pArrayListVenta);

    if (pArrayListVenta!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxVenta=ll_get(pArrayListVenta,i);
            if (pAuxVenta!=NULL)
            {
                 venta_getIdCliente(pAuxVenta,&ID);
                if (ID==*idBuscada)
                {
                    *idBuscada=ID;
                    retorno=0;
                    break;
                }else
                    retorno=-2;
            }
        }
    }
    return retorno;
}
