#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);
int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos, int limite);
//float getFloat(char mensaje[]);
char getChar(char mensaje[]);
int getFloat(char* pBuffer,int limite);
#endif // UTN_H_INCLUDED
