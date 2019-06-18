#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "Arraylist.h"

int parser_parseEmpleados(FILE* fileName, Arraylist* listaEmpleados);
int controller_loadFromText(char* path , Arraylist* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
