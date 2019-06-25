int controller_loadFromText(char* path , LinkedList* pArrayListClient);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListClient);
int controller_addClient(LinkedList* pArrayListClient);
int controller_editClient(LinkedList* pArrayListClient);
int controller_removeClient(LinkedList* pArrayListClient,LinkedList* pArrayListVentas);
int controller_ListClient(LinkedList* pArrayListClient);
int controller_sortClient(LinkedList* pArrayListClient);
int controller_saveAsText(char* path , LinkedList* pArrayListClient);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListClient);
int controller_findIdClient(LinkedList* pArrayListClient, int* idBuscada);
int controller_maxId(LinkedList* pArrayClient);
int controller_returnIndex(LinkedList* pArrayClient,int* valorBuscado);


int controller_findIdClientEnVentas(LinkedList* pArrayListVenta, int* idBuscada);

int ll_sort2(LinkedList* this, int (*pFunc)(void* ,void*), int order);

int controller_loadFromTextVenta(char* path , LinkedList* pArrayListVenta);
int controller_ListVenta(LinkedList* pArrayListVenta);
int controller_maxIdVenta(LinkedList* pArrayVenta);
int controller_addVenta(LinkedList* pArrayListVenta, LinkedList* pArrayListClient);
int controller_saveAsTextVentas(char* path , LinkedList* pArrayListVenta);
int controller_removeVenta(LinkedList* pArrayListVenta);
int controller_returnIndexVenta(LinkedList* pArrayVenta,int* valorBuscado);

