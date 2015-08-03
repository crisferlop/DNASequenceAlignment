#include "secuenceAlignment.h"
#include <stdio.h>
#include <stdlib.h>
#include "iofile.h"
#include <limits.h>
#include "ioperipherals.h"
/*
 * main.c
 *
 *  Created on: 31/7/2015
 *      Author: cristianfernando
 */


int main(int argc, char **argv) {
	readFile(argv[1]);
	if (argc == 3){
		if (exitsFile(argv[1]) && exitsFile(argv[2]) && isValidFilePath(argv[1]) && isValidFilePath(argv[2])){
			if (isDNAFileExtension(argv[1]) && isDNAFileExtension(argv[2])){
				if (!strcmp(argv[1],argv[2])){
					printf("please, select different files.\n");
				}
				else{
					char *secuenceA = readFile(argv[1]);
					char *secuenceB = readFile(argv[2]);
					if( secuenceA && secuenceB){
						if (isValidContents(secuenceA) && isValidContents(secuenceB)){
							alignment(secuenceA,secuenceB);
						}
						else printf("the file(s) contents is invalid.\n");
					}
					else printf("error on file(s) reading.\n");
					free(secuenceA);
					free(secuenceB);
				}
			}
			else printf("Invalid file(s) extension, the correctly extension is \".dna\".\n");
		}
		else printf("Invalid file path(s). Remember, the file paths can only contain alphanumerics characters, one dot and spaces.\n");
	}
	else {
		printf("You need pass two arguments");
		if (argc > 3)printf(" only");
		printf(".\n");
	}
	return 0;
}
