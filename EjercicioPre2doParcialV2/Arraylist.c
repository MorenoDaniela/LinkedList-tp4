#ifndef ARRAYLIST_C_INCLUDED
#define ARRAYLIST_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arraylist.h"


static Node* getNode(Arraylist* this, int nodeIndex);
static int addNode(Arraylist* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo Arraylist en memoria de manera dinamica
 *
 *  \param void
 *  \return Arraylist* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
Arraylist* ll_newArraylist(void)
{
    Arraylist* this;
    this = (Arraylist *)malloc(sizeof(Arraylist));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(Arraylist* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(Arraylist* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if (this!=NULL && nodeIndex>=0 && nodeIndex<this->size)
    {
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++)//cuando nodeindex sea 0 el primer nodo va a sguir siendo el primero que en este caso es null porque la lista esta vacia
        {
            pNode = pNode->pNextNode;//cuando i!=0 pNode apunta al que sigue hasta que no se pueda iterar mas el ultimo ya se que es null
            if (i==nodeIndex)
                pNode=NULL;//sacar estasdos lineas
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this Arraylist* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(Arraylist* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
 static int addNode(Arraylist* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoNuevo;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNodoNuevo = (Node*) malloc(sizeof(Node));
        if(pNodoNuevo != NULL)
        {
            pNodoNuevo->pElement = pElement;
            if(nodeIndex == 0)
            {
                if(this->pFirstNode == NULL) pNodoNuevo->pNextNode = NULL;
                if(this->pFirstNode != NULL)  pNodoNuevo->pNextNode = this->pFirstNode;
                this->pFirstNode = pNodoNuevo;
            }
            else
            {
                pNodoAnterior = getNode(this,nodeIndex-1);
                pNodoNuevo->pNextNode = pNodoAnterior->pNextNode;
                pNodoAnterior->pNextNode = pNodoNuevo;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}
/*
 static int addNode(Arraylist* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* anteriorNode;
    Node* newNode;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        newNode = (Node*) malloc(sizeof(Node));
        if(newNode != NULL)
        {
            newNode->pElement = pElement;
            if(nodeIndex == 0)
            {
                if(this->pFirstNode == NULL) //si el primer nodo es null
                    newNode->pNextNode = NULL;//al que apunto va a ser null porque solo tengo un elemento asi que apunto a null
                if(this->pFirstNode != NULL) //si el primero nodo no es null
                {
                    newNode->pNextNode = this->pFirstNode;//apunto al que vino primero en la lista(ya que vendria a ser el segundo)
                    this->pFirstNode = newNode;//el nuevo nodo pasa a ser el pFirstNode de la lista
                }
            }
            else//cuando el nodeindex no sea 0 es decir se qiera agregar un nodo en el medio o al final
            {
                anteriorNode = getNode(this,nodeIndex-1);//el nodo anterior es el que esta una posicion antes del nodeindex que ingrese
                newNode->pNextNode = anteriorNode->pNextNode;//el puntero al sig del nuevo nodo es igual al puntero que ahora tiene el nodo anterior
                //ES DECIR el nuevo nodo va a apuntar a lo que esta apuntando el anterior
                anteriorNode->pNextNode = newNode;//el anterior ahora va a apuntar al nuevo
            }
            this->size++;//incremento el size ya que agregue un elemento
            returnAux = 0;
        }
    }
    return returnAux;
}*/

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(Arraylist* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList Arraylist* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(Arraylist* this, void* pElement)
{
    int returnAux = -1;
    int limite;

    if (this!=NULL)
    {
        limite=ll_len(this);
        if(!addNode(this,limite,pElement))
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(Arraylist* this, int index)
{
    void* returnAux = NULL;
    Node* nodo=NULL;

    if (this!=NULL && index>=0)
    {
        nodo=getNode(this,index);
        if (nodo!=NULL)
            returnAux=nodo->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */

int ll_set(Arraylist* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux=NULL;

    if (this!=NULL && index>=0)
    {
        nodoAux= getNode(this,index);
        if (nodoAux!=NULL)
        {
            nodoAux->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(Arraylist* this,int index)
{
    int returnAux = -1;
    Node* nodo=NULL;
    Node* anterior=NULL;
    Node* siguiente=NULL;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        nodo=getNode(this,index);
        anterior=getNode(this,index-1);
        siguiente=getNode(this,index+1);

        if(nodo!=NULL && anterior!=NULL)
        {
            anterior->pNextNode=siguiente;
        }else
            {
                this->pFirstNode=siguiente;
            }
        free(nodo);
        returnAux=0;
        this->size--;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(Arraylist* this)
{
    int returnAux = -1;
    int i;

    if (this!=NULL)
    {
        for(i=0;i<ll_len(this);i++)
        {
            ll_remove(this,i);
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this Arraylist* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(Arraylist* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this Arraylist* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(Arraylist* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodoAux=NULL;

    if (this!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            nodoAux=getNode(this,i);
            if (nodoAux->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this Arraylist* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(Arraylist* this)
{
    int returnAux = -1;
    Node* nodoAux=NULL;

    if (this!=NULL)
    {
        nodoAux=getNode(this,0);
        if (nodoAux==NULL)
        {
            returnAux=1;
        }else
            returnAux=0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(Arraylist* this, int index, void* pElement)
{
    int returnAux=-1;

    if (this!=NULL && index>=0 && index<=ll_len(this))
    {
        if (addNode(this,index,pElement)==0)
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this Arraylist* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(Arraylist* this,int index)
{
    void* returnAux = NULL;
    Node* nodo=NULL;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        nodo=getNode(this,index);
        returnAux=nodo->pElement;
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this Arraylist* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(Arraylist* this, void* pElement)
{
    int returnAux = -1;
    Node* nodo=NULL;
    int i;

    if (this!=NULL)
    {
        for (i=0;i<=ll_len(this);i++)
        {
            nodo=getNode(this,i);
            if (nodo!=NULL && pElement==nodo->pElement)
            {
                returnAux=1;
                break;
            }else
                returnAux=0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this Arraylist* Puntero a la lista
 * \param this2 Arraylist* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(Arraylist* this,Arraylist* this2)
{
    int returnAux = -1;
    void* element;
    int i;

    if (this!=NULL && this2!=NULL)
    {
        returnAux=1;
        for (i=0;i<ll_len(this);i++)
        {
            element=ll_get(this2,i);
            if (ll_contains(this,element)==0)
            {
                 returnAux=0;
                 break;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList Arraylist* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return Arraylist* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
Arraylist* ll_subList(Arraylist* this,int from,int to)
{
    Arraylist* cloneArray = NULL;

    if (this!=NULL && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this))
    {
        cloneArray=ll_newArraylist();
        for (;from<to;from++)
        {
            ll_add(cloneArray,ll_get(this,from));
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList Arraylist* Puntero a la lista
 * \return Arraylist* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
Arraylist* ll_clone(Arraylist* this)
{
    Arraylist* cloneArray = NULL;

    if (this!=NULL)
    {
        cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList Arraylist* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(Arraylist* this, int (*pFunc)(void* ,void*), int order)
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

//PUNTERO AL ARRAY, PUNTERO A LA FUNCION.
//map recorre la lista a cada uno de los elementos de la lista se los pasa como param a la funcion
//recine un puntero a funcion
//agarra cada elemento del arraylist y se lo pasa a esta funcion como parametro.
//(ADENTRO DE ESTA FUNCION PENSAMOS ALGO QUE AFECTE A TODO)
//POR EJEMPLO UNA FUNCION QUE AUMENTE EL SUELDO RECIBA UN EMPLEADO Y LE AUMENTE EL SUELDO
//LLAMAR A MAP UNA VEZ POR CADA UNO DE LOS EMPLEADOS.

int ll_map(Arraylist* this, void (*pFunc)(void*))
{
    int returnAux=-1;
    int i;
    void* element;

    if (this!=NULL && pFunc!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            element=ll_get(this,i);
            pFunc(element);
            returnAux=0;
        }
    }
    return returnAux;
}


//FILTER teniamos una funcion que generaba un clone,
//filter recibe un parametro mas que es un puntero a funcion,
// esa funcion determina si este elemento integra o no la lista nueva, devuelve verdadero o falso
//si devuelve verdadero se agrega a la lista, si devuelve falso no.
//por ejmplo sublist empleados mayores de 40 a�os
//recibe un empleado y verifica la edad, si es mayor de 40 a�os revuelvo verdadero

Arraylist* ll_filter(Arraylist* this, int (*pFunc) (void*))
{
    Arraylist* cloneArray = NULL;
    int i;
    void* element;

    if (this!=NULL && pFunc!=NULL)
    {
        cloneArray=ll_newArraylist();
        for (i=0;i<ll_len(this);i++)
        {
            element=ll_get(this,i);
            if (pFunc(element))
            {
               ll_add(cloneArray,element);
            }
        }
    }
    return cloneArray;
}

//REDUCE HACE PARECIDO A FILTER, SI A ESE ELEMENTO ACTUAL HAY QUE ELIMINARLO O NO DE LA LISTA, VERDADERO O FALSO
//EJEMPLO A TODOS LOS AMYORES DE 30 SACARLOS DELA LISTA
//RECIBE LA LISTA Y LA FUNCION QUE LE DICE SI HAY O NO QUE SACAR AL ELEMENTO.

Arraylist* ll_reduce(Arraylist* this, int (*pFunc) (void*))
{
    int i;
    void* element;

    if (this!=NULL && pFunc!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            element=ll_get(this,i);
            if (pFunc(element)==1)
            {
                ll_remove(this,i);//se puede usar ll_pop
                i--;
            }
        }
    }
    return this;
}


#endif // ARRAYLIST_C_INCLUDED
