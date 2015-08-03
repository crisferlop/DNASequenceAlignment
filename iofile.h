#include <string.h>

/*
 * iofile.c
 *
 *  Created on: 31/7/2015
 *      Author: cristianfernando
 */

#ifndef IOFILE_C_
#define IOFILE_C_

/**
 * @brief Esta funcion lee un archivo y retorna los caracteres leidos, la
 * cadena de caracteres esta dispuesta en memoria dinamica por lo que es
 * responsabilidad del programador limpiar la memoria de este
 * @param filePath es la direccion de el archivo representada mediante una cadena de caracteres
 * @return un puntero nulo si el archivo no existe, si no retorna el contenido
 */
char* readFile(char* filePath);

/**
 * @brief Esta funcion verifica si un archivo existe o no, mediante un short int
 * para ahorar memoria de la pila de memoria.
 * @param filePath es la direccion de archivo de la cual se comprobara su existencia
 * @return se retorna 0 en el caso que el archivo no exista y 1 si este existe
 */
short int exitsFile(char *filePath);
/**
 * @brief Se encarga de se  crear un archivo en la direccion a solicitar, si el
 * archivo existe se puede sobrescribir.
 * @param filePath es la direccion en donde se desea crear el archivo
 * @param overwrite es el parametro que define si el archivo se desea sobrescribir en el caso de que exista
 * @return 1 en el caso de que el archivo sea creado exitosamente, 0 si hubo algun error
 */
short int createFile(char*filePath, short int overwrite);
/**
 * @brief Funcion encargada de escribir sobre un archivo.
 * @param filePath es la direccion del archivo en el que se escribira
 * @param contents es el contenido a escribir en el archivo
 * @param overwrite si el valor es 1 la cadena de caracteres sera el que
 * contenga el archivo, en otras palabras sobrescribir el contenido del archivo
 * con la cadena de caracteres, si es 0 entonces agregara al contenido del
 * archivo la cadena de caracteres deseada.
 * @return 0 en el caso de que no se pueda escribir en el archivo. 1 si fue exitoso
 */
short int writeOnFile(char*filePath, char* contents, short int overwrite);


#endif /* IOFILE_C_ */
