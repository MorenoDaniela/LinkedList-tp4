#include "Empleado.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ID 5000
#define MAX_HORAS 240
#define MAX_SUELDO 2000000

/** \brief Reserva espacio en memoria para un empleado
 * \param void
 * \return Empleado*
 */
Empleado* Empleado_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

/** \brief Valida los campos y los carga en una variable Empleado
 *
 * \param idStr char* id en modo texto.
 * \param nombreStr char*
 * \param horasTrabajadasStr char* horas trabajadas en texto.
 * \param sueldo char* sueldo en texto.
 * \return Empleado* pAuxEmpleado, NULL si puntero a idStr/nombreStr/horasTrabajdasStr/sueldo NULL, pAuxEmpleado si salio todo bien.
 *
 */

 Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Empleado* retorno=NULL;
    Empleado* pAuxEmpleado;

    if (idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL)
    {
        pAuxEmpleado=Empleado_new();
        if (pAuxEmpleado!=NULL)
        {
            if (!Empleado_setIdString(pAuxEmpleado,idStr) &&
                !Empleado_setNombre(pAuxEmpleado,nombreStr) &&
                !Empleado_setHorasTrabajadasString(pAuxEmpleado,horasTrabajadasStr))
                {
                    retorno=pAuxEmpleado;
                }else
                     {
                        Empleado_delete(pAuxEmpleado);
                     }
        }
    }
    return retorno;
}
 /*
Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Empleado* retorno=NULL;
    Empleado* pAuxEmpleado;

    if (idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
    {
        pAuxEmpleado=Empleado_new();
        if (pAuxEmpleado!=NULL)
        {
            if (!Empleado_setIdString(pAuxEmpleado,idStr) &&
                !Empleado_setNombre(pAuxEmpleado,nombreStr) &&
                !Empleado_setHorasTrabajadasString(pAuxEmpleado,horasTrabajadasStr)&&
                !Empleado_setSueldoString(pAuxEmpleado,sueldo))
                {
                    retorno=pAuxEmpleado;
                }else
                     {
                        Empleado_delete(pAuxEmpleado);
                     }
        }
    }
    return retorno;
}*/

/** \brief Valida los campos y los carga en una variable Empleado
 * \param empleado Empleado
 * \return Empleado*
 */
Empleado* Empleado_newBinario(Empleado empleado)
{
    Empleado* retorno = NULL;
    Empleado* pAux = Empleado_new();
    if(pAux != NULL)
    {
        if(!Empleado_setId(pAux,empleado.id)&&
           !Empleado_setNombre(pAux,empleado.nombre) &&
            !Empleado_setHorasTrabajadas(pAux,empleado.horasTrabajadas)&&
           !Empleado_setSueldo(pAux,empleado.sueldo))
        {
                retorno = pAux;
        }else
            {
                Empleado_delete(pAux);
            }
    }
    return retorno;
}
/** \brief Libera el espacio reservado en memoria para un empleado.
 *
 * \param Empleado* this
 * \return int retorno -1 si this NULL, 0 si logro liberar correctamente.
 *
 */
int Empleado_delete(Empleado* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el id y lo carga en la variable Empleado
 *
 * \param this Empleado*
 * \param id int
 * \return int retorno -1 si this es NULL, id menor a 0 o si id no es un numero, 0 si ok.
 *
 */
int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,MAX_ID))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el id de un empleado.
 *
 * \param this Empleado* empleado
 * \param int* id
 * \return int retorno -1 si this es NULL o id es NULL, 0 si se obtuvo bien.
 *
 */
int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el nombre y lo carga en la variable Empleado
 *
 * \param this Empleado*
 * \param nombre char*
 * \return int retorno -1 si this es NULL, si nombre es NULL o si nombre no es un nombre, 0 si logra validar y cargar.
 *
 */
int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Empleado* empleado
 * \param char* nombre
 * \return int retorno -1 si this es NULL o nombre es NULL, 0 si se obtuvo bien.
 *
 */
int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL )
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida las horas trabajdas y la carga en la variable Empleado
 *
 * \param this Empleado*
 * \param horasTrabajadas int
 * \return int retorno -1 si this es NULL, horasTrabajadas menor a 0 o si horasTrabajadas no es un numero, 0 si ok.
 *
 */
int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas>=0 && isValidInt(horasTrabajadas,1,MAX_HORAS))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param this Empleado* empleado
 * \param int* horasTrabajadas
 * \return int retorno -1 si this es NULL o horasTrabajadas es NULL, 0 si se obtuvo bien.
 *
 */
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el sueldo y lo carga en la variable Empleado
 *
 * \param this Empleado*
 * \param sueldo int
 * \return int retorno -1 si this es NULL, sueldo menor a 0 o si sueldo no es un numero, 0 si ok.
 *
 */
int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo>=0 && isValidInt(sueldo,1,MAX_SUELDO))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Empleado* empleado
 * \param int* sueldo
 * \return int retorno -1 si this es NULL o sueldo es NULL, 0 si se obtuvo bien.
 *
 */
int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el id y lo carga en la variable Empleado
 *
 * \param Empleado* this
 * \param id char* id string.
 * \return int retorno -1 si this es NULL, si id es NULL o si id no es un numero.
 *
 */
int Empleado_setIdString(Empleado* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isValidNumber(id))
        {
            retorno = Empleado_setId(this,atoi(id));
        }
    }
    return retorno;
}

/** \brief Obtiene el id de un empleado como string.
 *
 * \param this Empleado* empleado
 * \param char* id
 * \return int retorno -1 si this es NULL o id es NULL, 0 si todo ok.
 *
 */
int Empleado_getIdString(Empleado* this, char* id)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && id != NULL)
    {
        Empleado_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}
/** \brief Valida las horas trabajadas y lo carga en la variable Empleado
 *
 * \param Empleado* this
 * \param horasTrabajadasStr char* horas trabajadas string.
 * \return int retorno -1 si this es NULL, si horasTrabajadasStr es NULL o si horas trabajadas no es un numero.
 *
 */
int Empleado_setHorasTrabajadasString(Empleado* this, char* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas!=NULL)
    {
        if (isValidNumber(horasTrabajadas))
        {
            retorno= Empleado_setHorasTrabajadas(this,atoi(horasTrabajadas));
        }
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param this Empleado* empleado
 * \param char* horasTrabajadas
 * \return int retorno -1 si this es NULL o horasTrabajadas es NULL, 0 si todo ok.
 *
 */
int Empleado_getHorastrabajadasString(Empleado* this, char* horasTrabajadas)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && horasTrabajadas != NULL)
    {
        Empleado_getHorasTrabajadas(this,&buffer);
        sprintf(horasTrabajadas,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el sueldo y lo carga en la variable Empleado
 *
 * \param Empleado* this
 * \param sueldoStr char* sueldo string.
 * \return int retorno -1 si this es NULL, si sueldo es NULL o si sueldo no es un numero.
 *
 */
int Empleado_setSueldoString(Empleado* this, char* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo!=NULL)
    {
        if (isValidNumber(sueldo))
        {
            retorno= Empleado_setSueldo(this,atoi(sueldo));
        }
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un empleado como string.
 *
 * \param this Empleado* empleado
 * \param char* sueldo
 * \return int retorno -1 si this es NULL o sueldo es NULL, 0 si todo ok.
 *
 */
int Empleado_getSueldoString(Empleado* this, char* sueldo)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && sueldo != NULL)
    {
        Empleado_getSueldo(this,&buffer);
        sprintf(sueldo,"%d",buffer);//sprintf convierte un int en una cadena
        retorno = 0;
    }
    return retorno;
}

/** \brief Compara entre 2 nombres
 *
 * \param this1 void* primer empleado.
 * \param this2 void* segundo empleado
 * \return int retorno: -1 si el segundo nombre es el mayor, 1 si el primer nombre es el mayor, 0 si son iguales.
 *
 */
int Empleado_compararNombre(void* this1, void* this2)
{
    int retorno=0;
    int comparacion;
    char auxStr1[4096];
    char auxStr2[4096];
    Empleado_getNombre((Empleado*)this1,auxStr1);
    Empleado_getNombre((Empleado*)this2,auxStr2);
    comparacion= strcmp(auxStr1,auxStr2);
    if (comparacion >0)
    {
        retorno=1;
    }else if (comparacion<0)
        {
            retorno= -1;
        }

    return retorno;
}

/*
 Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350*/

void em_calcularSueldo(void* p)
{
    int horas;
    int auxSueldo=0;
    int total=0;
    //int totalMedio=0;

    if (p!=NULL)
    {
        Empleado_getHorasTrabajadas(p,&horas);
        if (horas<=120)
        {
            auxSueldo=horas*180;
            total=auxSueldo;
        }

        if (horas>120 && horas<160)
        {
            auxSueldo=120*180;
            total=auxSueldo+(horas-120)*240;
        }

        if ((int)p>=160)
        {
            auxSueldo=(120*180)+(40 * 240);
            //totalMedio=auxSueldo+(horas-120)*240;
            total=auxSueldo+(horas-160)*350;
        }

        Empleado_setSueldo(p,total);
    }
}

void sacarMayores(void*p)//que el sueldo sea mayor a 20000
{
    //int retorno=0;
    int auxSueldo;

    if (p!=NULL)
    {
        Empleado_getSueldo(p,&auxSueldo);
        if (auxSueldo<20000)
        {
            //printf ("Sueldo: ",auxSueldo);
            //retorno=1;
        }
    }

    //return retorno;
}
