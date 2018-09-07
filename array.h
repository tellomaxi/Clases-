#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED
#define CANTIDAD_EMPLEADOS 6
#define DATO_INVALIDO -1
#define false 0
#define true 1


int array_mostrarArray(int* pArray, int limite);
int array_calcularMaximo(int* pArray, int limite, int* pMaximo);
int array_init(int* pArray, int limite, int valor);
int array_ordenar(int* pArray, int limite, int orden);
int array_minimoDesde(int* pArray, int limite, int desde, int* pMinimo);
void array_swap(int*elementoA,int* elementoB);
#endif // ARRAYS_H_INCLUDED
