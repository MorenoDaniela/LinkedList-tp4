#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Client.h"
#include "funciones.h"

int main()
{
    int option = 0;
    //int flag=0;
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas = ll_newLinkedList();

    controller_loadFromText("clientes",listaClientes);
    controller_loadFromTextVenta("ventas",listaVentas);

    do{
        getInt("1. Alta de cliente.\n2. Modificacion de cliente.\n"
                "3. Baja de cliente.\n4. Listar clientes.\n5. Realizar una venta.\n6. Anular venta.\n7. Informar ventas.\n"
                "8. Informar ventas por producto.\n9. Generar informe de ventas.\n"
                "11. Informar cantidad de ventas por cliente.\n12. Salir.\n","\nError, opcion incorrecta.\n",1,12,3,&option);
        system("cls");
        switch(option)
        {
            case 1:
                controller_addClient(listaClientes);
                controller_ListClient(listaClientes);//
                controller_saveAsText("clientes",listaClientes);
                break;
            case 2:
                controller_editClient(listaClientes);
                controller_ListClient(listaClientes);//
                controller_saveAsText("clientes",listaClientes);
                break;
            case 3:
                controller_removeClient(listaClientes,listaVentas);
                controller_ListClient(listaClientes);//
                controller_saveAsText("clientes",listaClientes);
                break;
            case 4:
                controller_ListClient(listaClientes);
                break;
            case 5:
                controller_addVenta(listaVentas,listaClientes);
                controller_ListVenta(listaVentas);
                controller_saveAsTextVentas("ventas",listaVentas);
                break;
            case 6:
                //controller_removeVenta(listaVentas);
                break;
            case 7:
                controller_ListVenta(listaVentas);
                break;
            case 8:

                break;
            case 9:
                controller_saveAsTextVentas("ventas",listaVentas);
                break;
            case 10:
                break;
            case 11:
                break;
        }
    }while(option != 12);
    return 0;
}
