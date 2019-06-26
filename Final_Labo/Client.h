#ifndef client_H_INCLUDED
#define client_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int dni;
}Client;

typedef struct
{
    int idVenta;
    int idCliente;
    int codigoProducto;
    int cantidad;
    float precio;
}Venta;

Client* client_new();
Client* client_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
//Client* client_newBinario(Client cliente);

Venta* venta_new();//
Venta* venta_newParametros(char* idStringVenta,char* idStringCliente,char* codigo, char* cantidad, char* precio);//

int client_delete(Client* this);
int venta_delete(Venta* this);

int client_setId(Client* this,int id);
int client_getId(Client* this,int* id);

int client_setHorasTrabajadas(Client* this,int horasTrabajadas);
int client_getHorasTrabajadas(Client* this,int* horasTrabajadas);

int client_setSueldo(Client* this,int sueldo);
int client_getSueldo(Client* this,int* sueldo);

int client_setSueldoString(Client* this, char* sueldo);
int client_getSueldoString(Client* this, char* sueldo);

int client_setHorasTrabajadasString(Client* this, char* horasTrabajadas);
int client_getHorastrabajadasString(Client* this, char* horasTrabajadas);

int client_setIdString(Client* this, char* id);
int client_getIdString(Client* this, char* id);

int client_getDniString(Client* this, char* dni);
int client_setDniString(Client* this, char* dni);

int client_getDni(Client* this,int* dni);
int client_setDni(Client* this,int dni);

int client_setApellido(Client* this,char* apellido);
int client_getApellido(Client* this,char* apellido);

int client_setNombre(Client* this,char* nombre);
int client_getNombre(Client* this,char* nombre);

int venta_setIdCliente(Venta* this,int id);//
int venta_getIdCliente(Venta* this,int* id);//

int venta_setIdVenta(Venta* this,int id);//
int venta_getIdVenta(Venta* this,int* id);//

int venta_setIdClienteString(Venta* this, char* idCliente);//
int venta_getIdClienteString(Venta* this, char* idCliente);//

int venta_setIdVentaString(Venta* this, char* idVenta);//
int venta_getIdVentaString(Venta* this, char* idVenta);//

int venta_setCodigo(Venta* this,int codigo);//
int venta_getCodigo(Venta* this,int* codigo);//

int venta_setCodigoString(Venta* this, char* codigo);//
int venta_getCodigoString(Venta* this, char* codigoProducto);//

int venta_setPrecio(Venta* this,float precio);//
int venta_getPrecio(Venta* this,float* precio);//

int venta_setPrecioString(Venta* this, char* precio);//
int venta_getPrecioString(Venta* this, char* precio);//

int venta_setCantidad(Venta* this,int cantidad);//
int venta_getCantidad(Venta* this,int* cantidad);//

int venta_setCantidadString(Venta* this, char* cantidad);//
int venta_getCantidadString(Venta* this, char* cantidad);//



int client_compararNombre(void* this1, void* this2);
#endif // client_H_INCLUDED
