#include "Client.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ID 5000
#define MAX_HORAS 500
#define MAX_DNI 50000000
#define MIN_DNI 999999
#define MIN_CODIGO 1000
#define MAX_CODIGO 1002
#define MAX_PRECIO 1000000

/** \brief Reserva espacio en memoria para un cliente
 * \param void
 * \return Client*
 */
Client* client_new()
{
    return (Client*) malloc(sizeof(Client));
}

Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

/** \brief Valida los campos y los carga en una variable Client
 *
 * \param idStr char* id en modo texto.
 * \param nombreStr char*
 * \param horasTrabajadasStr char* horas trabajadas en texto.
 * \param sueldo char* sueldo en texto.
 * \return Client* pAuxClient, NULL si puntero a idStr/nombreStr/horasTrabajdasStr/sueldo NULL, pAuxClient si salio todo bien.
 *
 */
Client* client_newParametros(char* idStr,char* nombreStr,char* apellido, char* dni)
{
    Client* retorno=NULL;
    Client* pAuxClient;

    if (idStr!=NULL && nombreStr!=NULL && apellido!=NULL && dni!=NULL)
    {
        pAuxClient=client_new();
        if (pAuxClient!=NULL)
        {
            if (!client_setIdString(pAuxClient,idStr) &&
                !client_setNombre(pAuxClient,nombreStr) &&
                !client_setApellido(pAuxClient,apellido)&&
                !client_setDniString(pAuxClient,dni))
                {
                    retorno=pAuxClient;
                }else
                     {
                        client_delete(pAuxClient);
                     }
        }
    }
    return retorno;
}

Venta* venta_newParametros(char* idVenta,char* idCliente,char* codigo, char* cantidad, char*precio)
{
    Venta* retorno=NULL;
    Venta* pAuxVenta;

    if (idCliente!=NULL && idVenta!=NULL && codigo!=NULL && cantidad!=NULL && precio!=NULL)
    {
        pAuxVenta=venta_new();

        if (pAuxVenta!=NULL)
        {
            //printf("A VER\n");
            if (!venta_setIdVentaString(pAuxVenta,idVenta) &&
                !venta_setIdClienteString(pAuxVenta,idCliente) &&
                !venta_setCodigoString(pAuxVenta,codigo)&&
                !venta_setCantidadString(pAuxVenta,cantidad) &&
                !venta_setPrecioString(pAuxVenta,precio))
                {
                    retorno=pAuxVenta;
                }else
                     {
                        venta_delete(pAuxVenta);
                     }
        }
    }
    return retorno;
}

/** \brief Valida los campos y los carga en una variable Client
 * \param cliente Client
 * \return Client*
 */
 /*
Client* client_newBinario(Client cliente)
{
    Client* retorno = NULL;
    Client* pAux = client_new();
    if(pAux != NULL)
    {
        if(!client_setId(pAux,cliente.id)&&
           !client_setNombre(pAux,cliente.nombre) &&
            !client_setHorasTrabajadas(pAux,cliente.horasTrabajadas)&&
           !client_setSueldo(pAux,cliente.sueldo))
        {
                retorno = pAux;
        }else
            {
                client_delete(pAux);
            }
    }
    return retorno;
}*/
/** \brief Libera el espacio reservado en memoria para un cliente.
 *
 * \param Client* this
 * \return int retorno -1 si this NULL, 0 si logro liberar correctamente.
 *
 */
int client_delete(Client* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para una venta.
 *
 * \param Venta* this
 * \return int retorno -1 si this NULL, 0 si logro liberar correctamente.
 *
 */
int venta_delete(Venta* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el id y lo carga en la variable Client
 *
 * \param this Client*
 * \param id int
 * \return int retorno -1 si this es NULL, id menor a 0 o si id no es un numero, 0 si ok.
 *
 */
int client_setId(Client* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,MAX_ID))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el id y lo carga en la variable Client
 *
 * \param this Client*
 * \param id int
 * \return int retorno -1 si this es NULL, id menor a 0 o si id no es un numero, 0 si ok.
 *
 */
int venta_setIdCliente(Venta* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,MAX_ID))
    {
        this->idCliente=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el id de un cliente.
 *
 * \param this Venta* venta
 * \param int* id cliente
 * \return int retorno -1 si this es NULL o id es NULL, 0 si se obtuvo bien.
 *
 */
int venta_getIdCliente(Venta* this,int* id)//
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->idCliente;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el id de un cliente.
 *
 * \param this Client* cliente
 * \param int* id
 * \return int retorno -1 si this es NULL o id es NULL, 0 si se obtuvo bien.
 *
 */
int client_getId(Client* this,int* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int venta_setIdVenta(Venta* this,int id)//
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,MAX_ID))
    {
        this->idVenta=id;
        retorno=0;
    }
    return retorno;
}

int venta_getIdVenta(Venta* this,int* id)//
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->idVenta;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida el nombre y lo carga en la variable Client
 *
 * \param this Client*
 * \param nombre char*
 * \return int retorno -1 si this es NULL, si nombre es NULL o si nombre no es un nombre, 0 si logra validar y cargar.
 *
 */
int client_setNombre(Client* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
/** \brief Valida el apellido y lo carga en la variable Client
 *
 * \param this Client*
 * \param apellido char*
 * \return int retorno -1 si this es NULL, si apellido es NULL o si apellido no es un nombre, 0 si logra validar y cargar.
 *
 */
int client_setApellido(Client* this,char* apellido)
{
    int retorno=-1;

    if (this!=NULL && apellido!=NULL && isValidName(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el nombre de un cliente.
 *
 * \param this Client* cliente
 * \param char* nombre
 * \return int retorno -1 si this es NULL o nombre es NULL, 0 si se obtuvo bien.
 *
 */
int client_getNombre(Client* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL )
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el apellido de un cliente.
 *
 * \param this Client* cliente
 * \param char* apellido
 * \return int retorno -1 si this es NULL o apellido es NULL, 0 si se obtuvo bien.
 *
 */
int client_getApellido(Client* this,char* apellido)
{
    int retorno=-1;

    if (this!=NULL && apellido!=NULL )
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}
/** \brief Valida las horas trabajdas y la carga en la variable Client
 *
 * \param this Client*
 * \param horasTrabajadas int
 * \return int retorno -1 si this es NULL, horasTrabajadas menor a 0 o si horasTrabajadas no es un numero, 0 si ok.
 *
 */
 /*
int client_setHorasTrabajadas(Client* this,int horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas>=0 && isValidInt(horasTrabajadas,1,MAX_HORAS))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}*/

/** \brief Obtiene las horas trabajadas de un cliente.
 *
 * \param this Client* cliente
 * \param int* horasTrabajadas
 * \return int retorno -1 si this es NULL o horasTrabajadas es NULL, 0 si se obtuvo bien.
 *
 */
 /*
int client_getHorasTrabajadas(Client* this,int* horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}*/

/** \brief Valida el sueldo y lo carga en la variable Client
 *
 * \param this Client*
 * \param sueldo int
 * \return int retorno -1 si this es NULL, sueldo menor a 0 o si sueldo no es un numero, 0 si ok.
 *
 */

 /*
int client_setSueldo(Client* this,int sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo>=0 && isValidInt(sueldo,1,MAX_SUELDO))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}*/

/** \brief Obtiene el sueldo de un cliente.
 *
 * \param this Client* cliente
 * \param int* sueldo
 * \return int retorno -1 si this es NULL o sueldo es NULL, 0 si se obtuvo bien.
 *
 */

 /*
int client_getSueldo(Client* this,int* sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
*/
/** \brief Valida el id y lo carga en la variable Client
 *
 * \param Client* this
 * \param id char* id string.
 * \return int retorno -1 si this es NULL, si id es NULL o si id no es un numero.
 *
 */
int client_setIdString(Client* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isValidNumber(id))
        {
            retorno = client_setId(this,atoi(id));
        }
    }
    return retorno;
}

int venta_setIdClienteString(Venta* this, char* idCliente)//
{
    int retorno = -1;
    if(this != NULL && idCliente!=NULL)
    {
        if (isValidNumber(idCliente))
        {
            retorno = venta_setIdCliente(this,atoi(idCliente));
        }
    }
    return retorno;
}

int venta_getIdClienteString(Venta* this, char* idCliente)//
{
    int retorno = -1;
    int buffer;

    if(this != NULL && idCliente != NULL)
    {
        venta_getIdCliente(this,&buffer);
        sprintf(idCliente,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int venta_setIdVentaString(Venta* this, char* idVenta)//
{
    int retorno = -1;
    if(this != NULL && idVenta!=NULL)
    {
        if (isValidNumber(idVenta))
        {
            retorno = venta_setIdVenta(this,atoi(idVenta));
        }
    }
    return retorno;
}
int venta_getIdVentaString(Venta* this, char* idVenta)//
{
    int retorno = -1;
    int buffer;

    if(this != NULL && idVenta != NULL)
    {
        venta_getIdVenta(this,&buffer);
        sprintf(idVenta,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int venta_setCodigo(Venta* this,int codigo)//
{
    int retorno=-1;

    if (this!=NULL && codigo>=0 && isValidInt(codigo,MIN_CODIGO,MAX_CODIGO))
    {
        this->codigoProducto=codigo;
        retorno=0;
    }
    return retorno;
}

int venta_getCodigo(Venta* this,int* codigo)//
{
    int retorno=-1;

    if (this!=NULL && codigo!=NULL)
    {
        *codigo=this->codigoProducto;
        retorno=0;
    }
    return retorno;
}

int venta_setCodigoString(Venta* this, char* codigo)//
{
    int retorno = -1;
    if(this != NULL && codigo!=NULL)
    {
        if (isValidNumber(codigo))
        {
            retorno = venta_setCodigo(this,atoi(codigo));
        }
    }
    return retorno;
}
int venta_getCodigoString(Venta* this, char* codigoProducto)//
{
    int retorno = -1;
    int buffer;

    if(this != NULL && codigoProducto != NULL)
    {
        venta_getCodigo(this,&buffer);
        sprintf(codigoProducto,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int venta_setPrecio(Venta* this,float precio)//
{
    int retorno=-1;
    //printf("HEY\n");
    if (this!=NULL && precio>=0 && isValidFloat(precio,1,MAX_PRECIO))
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int venta_getPrecio(Venta* this, float* precio)//
{
    int retorno=-1;

    if (this!=NULL && precio!=NULL)
    {
        *precio=this->precio;
        retorno=0;
    }
    return retorno;
}

int venta_setPrecioString(Venta* this, char* precio)//
{
    int retorno = -1;
    if(this != NULL && precio!=NULL)
    {
        //printf ("Precio: %s \n",precio);//Hasta aca viene todo bien
        if (isValidFloatNumber(precio))//no pasa esta validacion si esta devuelve 1 deberia entrar, pero esta devolviendo 0
        {
            //printf ("Precio: %s",precio);
            retorno = venta_setPrecio(this,atof(precio));
        }
    }
    return retorno;
}

int venta_getPrecioString(Venta* this, char* precio)//
{
    int retorno = -1;
    float buffer;

    if(this != NULL && precio != NULL)
    {
        venta_getPrecio(this,&buffer);
        sprintf(precio,"%f",buffer);
        //printf("PRECIO: %f",buffer);
        retorno = 0;
    }
    return retorno;
}

int venta_setCantidad(Venta* this,int cantidad)//
{
    int retorno=-1;

    if (this!=NULL && cantidad>=0 && isValidInt(cantidad,1,1000))//revisar aca limite
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int venta_getCantidad(Venta* this,int* cantidad)//
{
    int retorno=-1;

    if (this!=NULL && cantidad!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int venta_setCantidadString(Venta* this, char* cantidad)//
{
    int retorno = -1;
    if(this != NULL && cantidad!=NULL)
    {
        if (isValidNumber(cantidad))
        {
            retorno = venta_setCantidad(this,atoi(cantidad));
        }
    }
    return retorno;
}

int venta_getCantidadString(Venta* this, char* cantidad)//
{
    int retorno = -1;
    int buffer;

    if(this != NULL && cantidad != NULL)
    {
        venta_getCantidad(this,&buffer);
        sprintf(cantidad,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el id de un cliente como string.
 *
 * \param this Client* cliente
 * \param char* id
 * \return int retorno -1 si this es NULL o id es NULL, 0 si todo ok.
 *
 */
int client_getIdString(Client* this, char* id)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && id != NULL)
    {
        client_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}
/** \brief Valida las horas trabajadas y lo carga en la variable Client
 *
 * \param Client* this
 * \param horasTrabajadasStr char* horas trabajadas string.
 * \return int retorno -1 si this es NULL, si horasTrabajadasStr es NULL o si horas trabajadas no es un numero.
 *
 */

 /*
int client_setHorasTrabajadasString(Client* this, char* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas!=NULL)
    {
        if (isValidNumber(horasTrabajadas))
        {
            retorno= client_setHorasTrabajadas(this,atoi(horasTrabajadas));
        }
    }
    return retorno;
}*/

/** \brief Obtiene las horas trabajadas de un cliente como string.
 *
 * \param this Client* cliente
 * \param char* horasTrabajadas
 * \return int retorno -1 si this es NULL o horasTrabajadas es NULL, 0 si todo ok.
 *
 */
 /*
int client_getHorastrabajadasString(Client* this, char* horasTrabajadas)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && horasTrabajadas != NULL)
    {
        client_getHorasTrabajadas(this,&buffer);
        sprintf(horasTrabajadas,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}*/

/** \brief Valida el sueldo y lo carga en la variable Client
 *
 * \param Client* this
 * \param sueldoStr char* sueldo string.
 * \return int retorno -1 si this es NULL, si sueldo es NULL o si sueldo no es un numero.
 *
 */

 /*
int client_setSueldoString(Client* this, char* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo!=NULL)
    {
        if (isValidNumber(sueldo))
        {
            retorno= client_setSueldo(this,atoi(sueldo));
        }
    }
    return retorno;
}*/

/** \brief Obtiene el sueldo de un cliente como string.
 *
 * \param this Client* cliente
 * \param char* sueldo
 * \return int retorno -1 si this es NULL o sueldo es NULL, 0 si todo ok.
 *
 */

 /*
int client_getSueldoString(Client* this, char* sueldo)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && sueldo != NULL)
    {
        client_getSueldo(this,&buffer);
        sprintf(sueldo,"%d",buffer);//sprintf convierte un int en una cadena
        retorno = 0;
    }
    return retorno;
}*/



 /** \brief Valida el dni y lo carga en la variable Client
 *
 * \param this Client*
 * \param dni int
 * \return int retorno -1 si this es NULL, dni menor a 0 o si dni no es un numero, 0 si ok.
 *
 */

int client_setDni(Client* this,int dni)
{
    int retorno=-1;

    if (this!=NULL && dni>=0 && isValidInt(dni,MIN_DNI,MAX_DNI))
    {
        this->dni=dni;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el dni de un cliente.
 *
 * \param this Client* cliente
 * \param int* dni
 * \return int retorno -1 si this es NULL o dni es NULL, 0 si se obtuvo bien.
 *
 */
int client_getDni(Client* this,int* dni)
{
    int retorno=-1;

    if (this!=NULL && dni!=NULL)
    {
        *dni=this->dni;
        retorno=0;
    }
    return retorno;
}
/** \brief Valida el dni y lo carga en la variable Client
 *
 * \param Client* this
 * \param dniStr char* dni string.
 * \return int retorno -1 si this es NULL, si dni es NULL o si sueldo no es un numero.
 *
 */
int client_setDniString(Client* this, char* dni)
{
    int retorno = -1;

    if(this != NULL && dni!=NULL)
    {
        if (isValidNumber(dni))
        {
            retorno= client_setDni(this,atoi(dni));
        }
    }
    return retorno;
}

/** \brief Obtiene el dni de un cliente como string.
 *
 * \param this Client* cliente
 * \param char* dni
 * \return int retorno -1 si this es NULL o dni es NULL, 0 si todo ok.
 *
 */
int client_getDniString(Client* this, char* dni)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && dni != NULL)
    {
        client_getDni(this,&buffer);
        sprintf(dni,"%d",buffer);//sprintf convierte un int en una cadena
        retorno = 0;
    }
    return retorno;
}

/** \brief Compara entre 2 nombres
 *
 * \param this1 void* primer cliente.
 * \param this2 void* segundo cliente
 * \return int retorno: -1 si el segundo nombre es el mayor, 1 si el primer nombre es el mayor, 0 si son iguales.
 *
 */
int client_compararNombre(void* this1, void* this2)
{
    int retorno=0;
    int comparacion;
    char auxStr1[4096];
    char auxStr2[4096];
    client_getNombre((Client*)this1,auxStr1);
    client_getNombre((Client*)this2,auxStr2);
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



