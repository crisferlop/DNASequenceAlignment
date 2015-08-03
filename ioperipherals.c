/*
 * ioperipherals.c
 *
 *  Created on: 31/7/2015
 *      Author: cristianfernando
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <inttypes.h>
#include "ioperipherals.h"
#include <ctype.h>

void printlnInt(int data){printf("%d\n", data);}
void printlnString(char * data){printf("%s\n", data);}
void printlnFloat(float data){printf("%f\n", data);}
void printlnUInt(unsigned int data){printf("%u\n", data);}
void printlnShort(short data){printf("%hd\n", data);}
void printlnLong(long data){printf("%ld\n", data);}

short flushInputBuffer(){
	char cleaner;
	int counter = 0;
	do{scanf("%c", &cleaner);counter++;}
	while(cleaner != '\n');
	// 0 si no habia solo un retorno, 1 si habia algo
	return counter==1?0:1;
}


short scanInt(int *data){
	if (data){
		unsigned int datanum = 0;
		char check;
		short isNumber = 1;
		int counter = 0;
		short negative = 1;
		scanf("%c",&check);
		if(isdigit(check))datanum += check - '0';
		else if ('-' == check)negative = -1;
		else {flushInputBuffer(); return 0;}
		while (isNumber){
			scanf("%c",&check);
			if(isdigit(check))datanum = datanum * 10 + check - '0';
			else{
				if (check != '\n')isNumber = 0;
				else break;
			}
			if (datanum > (unsigned int)INT_MAX){flushInputBuffer();isNumber = 0;}
			counter++;
		}
		if (isNumber){
			*data = negative*datanum;
			return 1;
		}
	}
	flushInputBuffer();
	return 0;
}


typedef struct dynamicChar{
	struct dynamicChar *next;
	char data;

} NodeChar;

char * scanString(){
	NodeChar * head = NULL;
	NodeChar * current = NULL;
	char cleaner = '0';
	int counter = 0;
	scanf("%c", &cleaner);
	/* hace una pila de caracteres en memoria dinamica con el fin de que
	 * la redimension y el recolocado de memoria que son operaciones costosas
	 * sean cambiadas por un metodo mas complicado, pero menos costoso
	 * que implica mover los datos de entrada a una pila y luego de alli
	 * moverlo a la memoria dinamica
	 */
	do{
		current = malloc(sizeof(NodeChar));
		current->data = cleaner;
		current->next = head;
		head = current;
		counter++;
		scanf("%c", &cleaner);
	}while(cleaner != '\n');
	counter++;
	current = malloc(sizeof(NodeChar));
	current->data = '\0';
	current->next = head;
	head = current;
	// se pasa de la pila a la variable de retorno liberando la memoria
	// ocupada por la pila
	char * toReturn = malloc(sizeof(char)*counter);

	while(counter != 0){
		toReturn[counter-1] = head->data;
		head = head->next;
		free(current);
		current = head;
		counter--;
	}
	return toReturn;
}

