#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

 typedef struct
{
    char nombre [50];
    char descripcion[100];
    float precio;
    int isEmpty;
}Producto;

int producto_altaProducto(Producto arrayProducto[],int size,int indice);
int producto_inicializarArrayProductos(Producto arrayProducto[],int cantidadDeElementos,int valor);
int producto_mostrarArrayProductos(Producto arrayProducto[],int cantidadDeElementos);
int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos, int limite);


int producto_getString(char* pBuffer, int limite);
int producto_getPrecio(  float* pPrecio, int limite, char* msg,
                    char* msgErr, int reintentos);
