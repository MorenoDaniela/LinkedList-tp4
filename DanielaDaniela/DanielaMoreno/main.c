#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "Entregas.h"
#include "funciones.h"
int main()
{
    LinkedList* listaEntregas = ll_newLinkedList();

    controller_loadFromText("data.csv",listaEntregas);
    controller_ListEntregas(listaEntregas);
    //controller_saveAsText("informes.txt",listaEntregas);
    return 0;
}
