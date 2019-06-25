#ifndef ENTREGAS_C_INCLUDED
#define ENTREGAS_C_INCLUDED
#include "Entregas.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
Entregas* Entregas_new()
{
    return (Entregas*) malloc(sizeof(Entregas));
}


Entregas* Entregas_newParametros(char* idStr,char* nombre,char* cantidad, char* importe)
{
    Entregas* retorno=NULL;
    Entregas* pAuxEntregas;

    if (idStr!=NULL && nombre!=NULL && cantidad!=NULL && importe!=NULL)
    {
        pAuxEntregas=Entregas_new();
        if (pAuxEntregas!=NULL)
        {
            if (!Entregas_setIdString(pAuxEntregas,idStr) &&
                !Entregas_setNombre(pAuxEntregas,nombre) &&
                !Entregas_setCantidadString(pAuxEntregas,cantidad)&&
                !Entregas_setImporteString(pAuxEntregas,importe))
                {
                    retorno=pAuxEntregas;
                }else
                     {
                        Entregas_delete(pAuxEntregas);
                     }
        }
    }
    return retorno;
}

int Entregas_delete(Entregas* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}

int Entregas_setId(Entregas* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,1000))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}


int Entregas_getId(Entregas* this,int* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Entregas_getIdString(Entregas* this, char* id)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && id != NULL)
    {
        Entregas_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int Entregas_setNombre(Entregas* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Entregas_getNombre(Entregas* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL )
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Entregas_setCantidad(Entregas* this,int cantidad)
{
    int retorno=-1;
    if (this!=NULL && cantidad>=0 && isValidInt(cantidad,1,1000))
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Entregas_getCantidad(Entregas* this,int* cantidad)
{
    int retorno=-1;
    if (this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Entregas_setCantidadString(Entregas* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad!=NULL)
    {
        if (isValidNumber(cantidad))
        {
            retorno= Entregas_setCantidad(this,atoi(cantidad));
        }
    }
    return retorno;
}

int Entregas_setIdString(Entregas* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isValidNumber(id))
        {
            retorno = Entregas_setId(this,atoi(id));
        }
    }
    return retorno;
}

float Entregas_setImporte(Entregas* this,float importe)//
{
    float retorno=-1;
    //printf("HEY\n");
    if (this!=NULL && importe>=0 && isValidFloat(importe,1,10000))
    {
        this->importe=importe;
        retorno=0;
    }
    return retorno;
}

float Entregas_getImporte(Entregas* this, float* importe)//
{
    float retorno=-1;

    if (this!=NULL && importe!=NULL)
    {
        *importe=this->importe;
        retorno=0;
    }
    return retorno;
}

float Entregas_setImporteString(Entregas* this, char* importe)//
{
    float retorno = -1;
    if(this != NULL && importe!=NULL)
    {
        if (isValidNumber(importe))
        {
            retorno = Entregas_setImporte(this,atof(importe));
            //printf("RETORNO:%d \n",retorno);
        }
    }
    return retorno;
}


float Entregas_getImporteString(Entregas* this, char* importe)//
{
    float retorno = -1;
    float buffer;

    if(this != NULL && importe != NULL)
    {
        Entregas_getImporte(this,&buffer);
        sprintf(importe,"%.2f",buffer);
        //printf("PRECIO: %f",buffer);
        retorno = 0;
    }
    return retorno;
}



#endif // ENTREGAS_C_INCLUDED
