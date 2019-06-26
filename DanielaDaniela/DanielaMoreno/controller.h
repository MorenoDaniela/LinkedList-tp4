#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path , LinkedList* pArrayListEntregas);
int controller_ListEntregas(LinkedList* pArrayListEntregas);
int controller_saveAsText(char* path , LinkedList* pArrayListEntregas);


#endif // CONTROLLER_H_INCLUDED
