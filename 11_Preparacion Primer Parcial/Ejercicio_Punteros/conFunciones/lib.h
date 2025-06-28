
#ifndef __LIB_H__
#define __LIB_H__ 1
#include <stdio.h>

char * f_strchr(char *string, char caracter);
void f_strcpy(char *destino, char *origen);
void f_strcat(char *destino, char origen[20]);
void f_toLowerCase (char *string);
void f_toUpperCase(char *string);
void f_toggleCase(char *string);

#endif