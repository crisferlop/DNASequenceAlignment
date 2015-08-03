/*
 * ioperipherals.h
 *
 *  Created on: 31/7/2015
 *      Author: cristianfernando
 */

#ifndef IOPERIPHERALS_H_
#define IOPERIPHERALS_H_

/**
 * @brief Imprime un entero en pantalla.
 * @param data es el entero a imprimir
 */
void printlnInt(int data);
/**
 * @brief Imprime una cadena de caracteres en pantalla.
 * @param data es el string a imprimir
 */
void printlnString(char * data);
/**
 * @brief Imprime un dato float en pantalla.
 * @param data es el float a imprimir
 */
void printlnFloat(float data);
/**
 * @brief Imprime un entero sin signo en pantalla.
 * @param data es el entero sin signo a imprimir
 */
void printlnUInt(unsigned int data);
/**
 * @brief Imprime un entero corto en pantalla.
 * @param data es el entero corto a imprimir
 */
void printlnShort(short data);
/**
 * @brief Imprime un entero largo en pantalla.
 * @param data es el entero largo a imprimir
 */
void printlnLong(long data);

/**
 * @brief obtiene un entero del teclado.
 * @param el puntero del entero en donde se colocara lo escaneado
 * @return un entero corto, si es 0 entonces la entrada estaba corrupta
 * tenia caracteres diferentes de numeros, si retorna 1 es que
 * se pudo leer bien el entero
 */
short scanInt(int *data);

/**
 * @brief obtiene una cadena de caracteres del teclado.
 * @return una cadena de caracteres en memoria dinamica, es responsabilidad
 * del programador liberarla de memoria
 */
char * scanString();

#endif /* IOPERIPHERALS_H_ */
