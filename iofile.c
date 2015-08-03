#include "iofile.h"
#include <stdio.h>
#include <stdlib.h>
/*
 * iofile.c
 *
 *  Created on: 31/7/2015
 *      Author: cristianfernando
 */

char* readFile(char* filePath){
	FILE * myFile = fopen(filePath,"r");
	/*Esta verificacion sirve para saber si el archivo existe o se pudo
	 * abrir debido a que el usuario puede agregarlo en algun lugar indebido
	 * o quiere abrir un archivo indebido
	 */
	if (myFile){
		fseek(myFile,0L,SEEK_END);
		if (ftell(myFile) <= 1000000){
			size_t size = ftell(myFile)+1;
			fseek(myFile,size-2,SEEK_SET);
			char finalChar = (char)fgetc(myFile);
			if(finalChar == '\n')size -= 1;
			fseek(myFile,0L,0);
			char * toReturn = (char*)malloc(size);
			fgets(toReturn,size,myFile);
			toReturn[size-1] = '\0';
			fclose(myFile);
			return toReturn;
		}
	}
	return 0;
}
short int exitsFile(char *filePath){
	FILE * myFile = fopen(filePath,"r");
	/*Esta verificacion sirve para saber si el archivo existe o se pudo
	 * abrir debido a que el usuario puede agregarlo en algun lugar indebido
	 * o quiere abrir un archivo indebido
	 */
	if (myFile){
		fclose(myFile);
		return 1;
	}
	return 0;
}
short int createFile(char*filePath,short int overwrite){
	if (!filePath)return 0;
	FILE * myFile = 0;
	if (!overwrite)myFile = fopen(filePath,"w");
	else myFile = fopen(filePath,"w+");
	/*Esta verificacion sirve para saber si el archivo existe o se pudo
	 * abrir debido a que el usuario puede agregarlo en algun lugar indebido
	 * o quiere abrir un archivo indebido
	 */
	if (myFile != NULL){
		fclose(myFile);
		return 1;

	}
	return 0;
}


short int writeOnFile(char*filePath, char* contents, short int overwrite){
	if (!filePath)return 0;
	FILE * myFile = 0;
	if (overwrite)myFile = fopen(filePath,"w");
	else myFile = fopen(filePath,"w+");
	/*Esta verificacion sirve para saber si el archivo existe o se pudo
	 * abrir debido a que el usuario puede agregarlo en algun lugar indebido
	 * o quiere abrir un archivo indebido
	 */
	if (myFile){
		fputs(contents,myFile);
		fclose(myFile);
		return 1;
	}
	return 0;
}
