#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int cantidad;
    float importe;
}Entregas;


Entregas* Entregas_new();
Entregas* Entregas_newParametros(char* idStr,char* nombre,char* cantidad, char* importe);
int Entregas_delete(Entregas* this);

int Entregas_setId(Entregas* this,int id);
int Entregas_getId(Entregas* this,int* id);
int Entregas_getIdString(Entregas* this, char* id);
int Entregas_setIdString(Entregas* this, char* id);

int Entregas_setNombre(Entregas* this,char* nombre);
int Entregas_getNombre(Entregas* this,char* nombre);

int Entregas_setCantidad(Entregas* this,int cantidad);
int Entregas_getCantidad(Entregas* this,int* cantidad);
int Entregas_setCantidadString(Entregas* this, char* cantidad);
int Entregas_getCantidadString(Entregas* this, char* cantidad);

int Entregas_setImporte(Entregas* this, float importe);
int Entregas_getImporte(Entregas* this,float* importe);
int Entregas_setImporteString(Entregas* this, char* importe);
int Entregas_getImporteString(Entregas* this, char* importe);




#endif // ENTREGAS_H_INCLUDED
