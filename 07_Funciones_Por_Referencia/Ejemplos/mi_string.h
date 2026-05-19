#ifndef _MI_STRING_H
#define _MI_STRING_H 1

/*
 * mi_strlen 
 * devuelve la longitud de una cadena
*/
int mi_strlen(char *s);

/*
*
*/
void mi_strcpy(char *destino, char *origen);

/*
*
*/
void mi_strcat(char *destino, char *origen);

/*
*
*/
void mi_toUpperCase(char *s);

/*
 *
 */
void mi_toLowerCase(char *s);
/*
 * 
 */
int mi_strcmp(char *str1, char *str2);
#endif