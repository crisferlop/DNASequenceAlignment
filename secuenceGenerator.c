/*
 * secuenceGenerator.c
 *
 *  Created on: 1/8/2015
 *      Author: cristianfernando
 */
#include "iofile.h"
#include "ioperipherals.h"
#include "secuenceAlignment.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
	int lenght;
	int rightValue = 0;
	while (!rightValue){
		printf("Specify the length of the DNA sequence: ");
		rightValue = scanInt(&lenght) && lenght >=7 && lenght <=1000000;
		if (!rightValue)printlnString("Error: try again.");
	}
	rightValue = 0;
	char * filename = 0;
	char* dna = malloc(sizeof(char)*(lenght+1));
	while (!rightValue){
		printf("Type the name of the file: ");
		filename = scanString();
		if (!isDNAFileExtension(filename)){
			char * newfilename;
			// en esta linea se realizo un cambio antes existia un +4 en vez de un +5
			// se hizo el cambio debio a un error en la liberacion de memoria que antes no estaba
			// implementada
			newfilename = malloc(sizeof(char)*(strlen(filename)+5));
			newfilename[0] = '\0';
			strcat(newfilename,filename);
			strcat(newfilename,".dna");
			free (filename);
			filename = newfilename;
		}
		// se implementa la validacion de archivos o al menos una version minimalista de esto,
		// solo se pueden hacer archivos que contengan datos alfanumericos, un unico punto
		// y espacios
		if (isValidFilePath(filename) && createFile(filename, 1)){
			generateDNA(dna,lenght);
			dna[lenght]= '\0';
			if (writeOnFile(filename,dna,1))rightValue= 1;

		}
		else{
			printlnString("Error. Try again.");
		}
		//cambio agregado para liberar memoria
		free(filename);
	}
	printf("File %s has been generated successfully with the following content: \n\n", filename);
	printf("%s\n", dna);
	printf("\n");
	free(dna);
	return 0;
}
