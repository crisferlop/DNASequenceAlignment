#include "secuenceAlignment.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
const int A = 0;
const int G = 1;
const int C = 2;
const int T = 3;
const int _ = 4;/* "Nucleotido" GAP */
const int BAD_NEOCLEOTIDE = -1;


/*
 * Nucleotidos version caracteres
 */
const char cA = 'A';
const char cG = 'G';
const char cC = 'C';
const char cT = 'T';
const char c_ = '_';/* "Nucleotido" GAP */


const int SIMILARITY_MATRIX [5][5] = {
		// A  G  C  T
	/*A*/{10,-1,-3,-4},
	/*G*/{-1, 7,-5,-3},
	/*C*/{-3,-5, 9, 0},
	/*T*/{-4,-3, 0, 8}
};


int convertCharToNucletide(char pCaracter){
	if (pCaracter == cA){
		return A;
	}
	else if (pCaracter == cG){
		return G;
	}
	else if (pCaracter == cT){
		return T;
	}
	else if (pCaracter == cC){
		return C;
	}
	else if (pCaracter == c_){
		return _;
	}
	else{
		return BAD_NEOCLEOTIDE;
	}
}
char convertNucletideToChar(int pNucleotide){
	if (pNucleotide == A){
		return cA;
	}
	else if (pNucleotide == G){
		return cG;
	}
	else if (pNucleotide == T){
		return cT;
	}
	else if (pNucleotide == C){
		return cC;
	}
	else if (pNucleotide == _){
		return c_;
	}
	else{
		return BAD_NEOCLEOTIDE;
	}
}

void generateDNA(char * dna, int lenght){
	int current = 0;
	srand(time(NULL));
	while(current < lenght){
		dna[current] = convertNucletideToChar(rand()%4);
		current++;
	}
}

int isDNAFileExtension(char *filePath){
	int size = strlen(filePath);
	if (size > 4
			&& filePath[size - 1] == 'a'
			&& filePath[size - 2] == 'n'
			&& filePath[size - 3] == 'd'
			&& filePath[size - 4] == '.'
			)return 1;
	return 0;
}


short isNucleotide(char Nucleotid){
	return (Nucleotid == cA || Nucleotid == cC || Nucleotid == cG || Nucleotid == cT)?1:0;
}


short isValidNucleotideContents(char *dna){
	int lenght = strlen(dna);
	int current = 0;
	if (lenght == 0)return 0;
	while(current < lenght)if (!isNucleotide(dna[current++]))return 0;
	return 1;
}


void invertString(char * string){
	if (string){
		int lenght = strlen(string);
		char * tmp = malloc(sizeof(char)* (lenght+1));
		int current = 0;
		tmp[lenght] = '\0';
		while(current < lenght){
			tmp[current] = string[lenght -1 - current];
			current++;
		}
		strcpy(string,tmp);
		free(tmp);
	}
}


int ** generateMatrix(int width, int height){
	int *array = malloc(sizeof(int)*width*height);
	if (!array) return NULL;
	int **matrix = malloc(sizeof(int*)*height);
	if (!matrix){free(array);return NULL;}
	int current = 0;
	while(current < height){
		// manejo de direccionamiento de memoria
		matrix[current] = array + width*current;
		current++;
	}
	return matrix;
}

void liberateMatrix(int ** matrix){
	free(*matrix);
	free(matrix);
}


/**
 *En la matriz genera el gap por ejemplo en la siguiente matriz 3x3
 *------------------
 * | _ | A | G | T |
 *------------------
 *_| 0 |-5 |-10|-15| <- Gap inicializado
 *------------------
 *A|-5 | 0 | 0 | 0 |
 *------------------
 *G|-10| 0 | 0 | 0 |
 *------------------
 *T|-15| 0 | 0 | 0 |
 *------------------
 *   ^
 *   |
 *   Gap inicializado
 */
void initGapOnScoreMatrix(int ** matrix, int gap, int width,int height){
	for (int column = 0; column < width; column++)matrix[0][column] = gap * column;
	for (int row = 0; row < height; row++)matrix[row][0] = gap * row;
}

int max(int count, ...){
	int *start = (int*)&count;
	int i = 0;
	int max = -100000000;
	for (i = 0; i < count; i++)
	{
		start++;
		if (max < *start)
			max = *start;
	}
	return max;
}


void alignment(char* dna1,char* dna2){
	const int gap = -5;
	const int dna1lenght = strlen(dna1) + 1;
	const int dna2lenght = strlen(dna2) + 1;

	int i = 0;
	int j = 0;

	int stringsize = dna1lenght > dna2lenght ? dna1lenght: dna2lenght;

	char *resultFirst = calloc((stringsize+1),sizeof(char));
	char *resultSecond = calloc((stringsize+1),sizeof(char));
	resultFirst[stringsize] = '\0';
	resultSecond[stringsize] = '\0';
	/**
	 * Genera una matriz en memoria dinamica indicando el ancho y el alto
	 */
	int **scoreMatrix = generateMatrix(dna1lenght, dna2lenght);
	
	initGapOnScoreMatrix(scoreMatrix,gap,dna1lenght,dna2lenght);
	char tmp[] = " ";
	for (i = 1; i < dna2lenght; i++){
		for (j = 1; j < dna1lenght; j++){
			int match = scoreMatrix[i - 1][j - 1] + SIMILARITY_MATRIX[convertCharToNucletide(dna2[i - 1])][convertCharToNucletide(dna1[j - 1])];
			int del = scoreMatrix[i - 1][j] + gap;
			int insert = scoreMatrix[i][j - 1] + gap;
			scoreMatrix[i][j] = max(3, match, del, insert);
		}
	}
	i = dna2lenght - 1;
	j = dna1lenght - 1;
	while ((i > 0) && (j > 0))
	{
		int match = scoreMatrix[i - 1][j - 1] + SIMILARITY_MATRIX[convertCharToNucletide(dna2[i - 1])][convertCharToNucletide(dna1[j - 1])];
		int del = scoreMatrix[i - 1][j] + gap;
		int insert = scoreMatrix[i][j - 1] + gap;

		if (match == scoreMatrix[i][j])
		{
			tmp[0] = dna1[j - 1];
			strcat(resultFirst, tmp);
			tmp[0] = dna2[i - 1];
			strcat(resultSecond, tmp);
			i--;
			j--;
		}
		else if (del == scoreMatrix[i][j])
		{
			tmp[0] = dna2[i - 1];
			strcat(resultFirst, tmp);
			tmp[0] = '-';
			strcat(resultSecond, tmp);
			i--;
		}
		else if (insert == scoreMatrix[i][j])
		{
			tmp[0] = '-';
			strcat(resultFirst, tmp);
			tmp[0] = dna1[j - 1];
			strcat(resultSecond, tmp);
			j--;
		}
	}
	while (i > 0)
	{
		tmp[0] = dna2[i - 1];
		strcat(resultFirst, tmp);
		tmp[0] = '-';
		strcat(resultSecond, tmp);
		i--;
	}
	while (j > 0)
	{
		tmp[0] = '-';
		strcat(resultFirst, tmp);
		tmp[0] = dna1[j - 1];
		strcat(resultSecond, tmp);
		j--;
	}
	invertString(resultFirst);
	invertString(resultSecond);
	printf("%s",resultSecond);
	printf("\n");
	printf("%s\n",resultFirst);
	free(resultFirst);
	free(resultSecond);
}

short isValidFilePath(char * filepath){
	int lenght =strlen(filepath);
	short isValid = 1;
	int current = 0;
	int pointsCounter = 0;
	while(current  < lenght){
		if(filepath[current ]== '.')pointsCounter++;
		if ((!isalnum(filepath[current]) && filepath[current] != ' ' && filepath[current] != '.') || pointsCounter == 2){
			isValid = 0;
			break;
		}
		current++;
	}
	return isValid;
}

