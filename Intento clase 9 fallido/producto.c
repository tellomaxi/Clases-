#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"
#define BUFFER_STR 4096

int producto_altaProducto(Producto arrayProducto[],int size,int indice)
{
    int retorno = -1;
    int i=0;
    char auxNombre [50];
    char auxDescripcion[100];
    float auxPrecio=0;
    if(arrayProducto !=NULL && size >0 && indice >= 0 && indice < size && arrayProducto[i].isEmpty )
    {
        if ((utn_getNombre(auxNombre,50,"ingrese nombre del producto\n","Error, reingrese nombre\n", 2)==0 )&&
            (utn_getNombre(auxDescripcion,50,"ingrese descripcion del producto\n","Error, reingrese descripcion\n", 2)==0) &&
             (producto_getPrecio(&auxPrecio,50,"ingrese precio","Error reingrese precio",2)==0))
        {
            strncpy(arrayProducto[i].nombre,auxNombre,50);
            strncpy(arrayProducto[i].descripcion,auxDescripcion,50);
            arrayProducto[i].isEmpty =0;
            retorno =0;
        }
    }
    return retorno;
}

int producto_inicializarArrayProductos(Producto arrayProducto[],int cantidadDeElementos,int valor)
{
    int retorno = -1;
    int i;
    if(arrayProducto !=NULL && cantidadDeElementos >0 )
    {
        for(i=0;i < cantidadDeElementos; i++)
            {
                arrayProducto[i].isEmpty = valor;
            }
    retorno =0;
    }
    return retorno;
}

int producto_mostrarArrayProductos(Producto arrayProducto[],int cantidadDeElementos)
{
    int retorno = -1;
    int i;
    if(arrayProducto !=NULL && cantidadDeElementos >0 )
    {
        for(i=0;i < cantidadDeElementos; i++)
            {
                if(!arrayProducto[i].isEmpty)
            {
            printf("Nombre\n%s - D : %s - P %f",arrayProducto[i].nombre,arrayProducto[i].descripcion,arrayProducto[i].precio);
        } //= valor;
    }
    retorno =0;
    }
    return retorno;
}


int producto_getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}

/*static int isFloat(char* pBuffer,int limite)
{
    int retorno= 0;
    int i;
    if(pBuffer != NULL && limite >0)
    {
        retorno= 1;
        for(i=0; i<limite && pBuffer[i] != '\0';i++ )
        {
            if((pBuffer[i] >= 0 && pBuffer[i] <= 9) && (pBuffer[i] == ',' || pBuffer [i] == '.' ))
            {
                retorno =0;
                break;
            }
        }
    }

    return retorno;
}

int getFloat(char* pBuffer,int limite)
{
    char bufferString [5];
    int retorno = -1;


    if(getString(bufferString,sizeof(bufferString)) == 0 && isFloat(bufferString, limite))
    {
        *pBuffer = atof(bufferString);
        retorno = 0;
    }

    return retorno;
}


int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos, int limite)

{
    int retorno=-1;
    char buffer;
    if( pFloat != NULL &&  msg != NULL && msgErr != NULL &&
         min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getFloat(&buffer,limite) == 0 &&
                buffer >= min && buffer <= max)
            {
                retorno = 0;
                *pFloat = buffer;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
*/
static int isValidPrecio(char* pBuffer,int limite)
{
    int retorno = -1;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if((pBuffer[i] >= '0') && (pBuffer[i] <= '9') && (pBuffer[i] != '.'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int producto_getPrecio(  float* pPrecio, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferPrecio[BUFFER_STR];

    if( pPrecio != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( producto_getString(&bufferPrecio,limite) == 0 &&
                isValidPrecio(bufferPrecio,limite))
            {
                strncpy(pPrecio,bufferPrecio,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

