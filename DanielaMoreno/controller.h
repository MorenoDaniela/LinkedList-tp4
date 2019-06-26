#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEntregas);
int controller_ListEntregas(LinkedList* pArrayListEntregas);
int controller_saveAsText(char* path , LinkedList* pArrayListEntregas);
int entregasFiltroGold(void* p);
int entregasFiltroPlus(void* p);
int entregasFiltroRegular(void* p);
int informes(LinkedList* listaEntregas);
int cantidadEntregada(LinkedList* pArrayList);
float importeTotal(LinkedList* pArrayList);
int controller_saveAsTextInformes(char* path , LinkedList* pArrayListEntregas);


#endif // CONTROLLER_H_INCLUDED
