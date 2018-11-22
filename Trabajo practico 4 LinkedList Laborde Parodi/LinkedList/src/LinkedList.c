#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* list)
{
    int returnAux=-1;

    if( list != NULL)
    {
        returnAux=list->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    if ( this  !=NULL  && nodeIndex >= 0 && nodeIndex<ll_len(this) )
    {

        pNode=this->pFirstNode;

        for(int i=0; i<nodeIndex; i++)
        {
            pNode = pNode->pNextNode;
        }

    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node * pNodeNuevo;
    Node * pnodoAux;
    Node * pnodoAux2;


    if (this!=NULL)
    {

        if(nodeIndex>=0 && nodeIndex<=ll_len(this))
        {
            pNodeNuevo=(Node*) malloc(sizeof(Node));

            if(pNodeNuevo!=NULL)
            {
                if(nodeIndex==0)
                {
                    pNodeNuevo->pNextNode=this->pFirstNode;
                    pNodeNuevo->pElement=pElement;
                    this->pFirstNode=pNodeNuevo;
                    this->size++;
                    returnAux=0;
                }
                if(nodeIndex==ll_len(this))
                {
                    pNodeNuevo->pNextNode=NULL;
                    pNodeNuevo->pElement=pElement;
                    pnodoAux=getNode(this,nodeIndex-1);
                    pnodoAux->pNextNode=pNodeNuevo;
                    this->size++;
                    returnAux=0;

                }
                if(nodeIndex!=0 && nodeIndex<ll_len(this))
                {
                    pnodoAux=getNode(this,nodeIndex);
                    pNodeNuevo->pNextNode=pnodoAux; //getNode(this,nodeIndex);
                    pNodeNuevo->pElement=pElement;
                    pnodoAux2=getNode(this,nodeIndex-1);
                    pnodoAux2->pNextNode=pNodeNuevo;
                    //   printf("%d\n",this->size);
                    // this->size=contador;
                    // printf("%d\n",this->size);
                    returnAux=0;

                }


            }


        }

    }



    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        addNode(this, ll_len(this), pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node * auxNode;

    if( this !=NULL && index>=0 && index<ll_len(this))
    {

        auxNode= getNode(this,index);
        returnAux=auxNode->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if( this!=NULL )
    {
        if(index >= 0 && index<ll_len(this))
        {
            if(index == ll_len(this))
            {
                ll_add(this,pElement);
            }
            else
            {
                auxNode=getNode(this,index);
                auxNode->pElement=pElement;
            }
            returnAux=0;
        }

    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxnode;
    Node* NodeDelete;

    if( this!=NULL)
    {
        if(index>=0 && index<ll_len(this))
        {
            if(index==0)
            {
                NodeDelete=getNode(this,index);
                this->pFirstNode=getNode(this,1);
            }
            else
            {
                NodeDelete=getNode(this,index);
                auxnode=getNode(this,index-1);
                if(NodeDelete->pNextNode==NULL)
                {
                    auxnode->pNextNode=NULL;
                }
                else
                {
                    auxnode->pNextNode=getNode(this,index+1);
                }
            }

            free(NodeDelete);
            this->size--;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this )
{
    int returnAux = -1;
    Node* auxNode;
    if( this != NULL)
    {
        for(int i=ll_len(this); i>-1; i--)
        {
            auxNode = getNode(this,i);
            free(auxNode);
        }
        this->size=0;
        this->pFirstNode=NULL;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
*/
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this !=NULL )
    {
        if(this->size==0 )
        {
            returnAux=1;
        }
        else
        {

            ll_clear(this);
            returnAux=0;
        }
        free((this));
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* list, void* pElement)
{
    int returnAux = -1;
    Node* auxnode;

    if( list!=NULL )
    {
        for(int i=0; i<ll_len(list); i++)
        {
            auxnode=getNode(list,i);
            if( pElement == auxnode->pElement ) returnAux=i;
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if( this!=NULL)
    {
        returnAux=0;

        if( (ll_len(this)) == 0)
        {
            returnAux=1;
        }

    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!= NULL)
    {
        if(index>=0 && index<=ll_len(this))
        {
            addNode(this,index,pElement);
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* list,int index)
{
    void* returnAux = NULL;
    Node* pNodeDelete;

    if( list != NULL )
    {

        if(index>=0 && index<ll_len(list))
        {
            pNodeDelete=getNode(list,index);
            returnAux= pNodeDelete->pElement;
            list->size--;
            ll_remove(list,index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if( this!=NULL )
    {
        returnAux=0;
        if(ll_indexOf(this,pElement) != -1)
        {
            returnAux=1;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* list,LinkedList* this2)
{
    int returnAux = -1;
    Node* auxTHIS;
    Node* auxTHIS2;

    if(list!=NULL && this2!=NULL)
    {
        returnAux=0;
        for(int i=0; i<ll_len(this2); i++)
        {
            returnAux=0;
            auxTHIS2= ll_get(this2,i);
            for(int j=0; j<ll_len(list); j++)
            {
                auxTHIS= ll_get(list,j);
                if(auxTHIS2==auxTHIS)
                {
                    returnAux=1;
                }
            }
            if(returnAux==0) break;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* list,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(list!=NULL)
    {
        if(from>=0 && from<=ll_len(list) && to>=0 && to<=ll_len(list) && to>=from)
        {
            cloneArray=ll_newLinkedList();
            if(cloneArray!=NULL)
            {
                for(int i=from ; i<=to ; i++)
                {
                    pElement=ll_get(list,i);
                    ll_add(cloneArray,pElement);
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* list)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    if(list!=NULL)
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=0; i<ll_len(list); i++)
            {
                pElement=ll_get(list,i);
                addNode(cloneArray,i,pElement);
            }
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* list, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* aux;

    if(list != NULL && pFunc != NULL && (order == 0  || order == 1))
    {

        if(list!=NULL)
        {
            for(int i=0; i< ll_len(list)-1; i++)
            {
                for(int j=i+1; j <ll_len(list) ; j++ )
                {
                    if(order)
                    {

                        if( pFunc( ll_get(list, i), ll_get(list, j)) >0)
                        {
                            aux = ll_get(list, i);
                            ll_set(list, i, ll_get(list, j));
                            ll_set(list, j, aux);

                        }
                    }
                    else
                    {
                        if( pFunc( ll_get(list, i), ll_get(list, j))  < 0)
                        {
                            aux = ll_get(list, i);
                            ll_set(list, i, ll_get(list, j));
                            ll_set(list, j, aux);

                        }

                    }

                }

            }
            returnAux=0;
        }

    }

    return returnAux;

}

