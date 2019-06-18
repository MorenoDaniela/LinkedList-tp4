#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

Empleado* Empleado_new();
//Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Empleado* Empleado_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
Empleado* Empleado_newBinario(Empleado empleado);

int Empleado_delete(Empleado* this);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);

int Empleado_setSueldoString(Empleado* this, char* sueldo);
int Empleado_getSueldoString(Empleado* this, char* sueldo);

int Empleado_setHorasTrabajadasString(Empleado* this, char* horasTrabajadas);
int Empleado_getHorastrabajadasString(Empleado* this, char* horasTrabajadas);

int Empleado_setIdString(Empleado* this, char* id);
int Empleado_getIdString(Empleado* this, char* id);

int Empleado_compararNombre(void* this1, void* this2);


void em_calcularSueldo(void* p);

#endif // EMPLEADO_H_INCLUDED
