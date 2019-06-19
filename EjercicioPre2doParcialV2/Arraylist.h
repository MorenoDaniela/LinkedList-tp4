#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct Arraylist
{
    Node* pFirstNode;
    int size;
}typedef Arraylist;

//Publicas
Arraylist* ll_newArraylist(void);
int ll_len(Arraylist* this);
Node* test_getNode(Arraylist* this, int nodeIndex);
int test_addNode(Arraylist* this, int nodeIndex,void* pElement);
int ll_add(Arraylist* this, void* pElement);
void* ll_get(Arraylist* this, int index);
int ll_set(Arraylist* this, int index,void* pElement);
int ll_remove(Arraylist* this,int index);
int ll_clear(Arraylist* this);
int ll_deleteArraylist(Arraylist* this);
int ll_indexOf(Arraylist* this, void* pElement);
int ll_isEmpty(Arraylist* this);
int ll_push(Arraylist* this, int index, void* pElement);
void* ll_pop(Arraylist* this,int index);
int ll_contains(Arraylist* this, void* pElement);
int ll_containsAll(Arraylist* this,Arraylist* this2);
Arraylist* ll_subList(Arraylist* this,int from,int to);
Arraylist* ll_clone(Arraylist* this);
int ll_sort(Arraylist* this, int (*pFunc)(void* ,void*), int order);


Arraylist* ll_reduce(Arraylist* this, int (*pFunc) (void*));
Arraylist* ll_filter(Arraylist* this, int (*pFunc) (void*));
int ll_map(Arraylist* this, void (*pFunc)(void*));

#endif // ARRAYLIST_H_INCLUDED
