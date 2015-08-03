/*
 * secuenceAlignement.h
 *
 *  Created on: 31/7/2015
 *      Author: cristianfernando
 */

#ifndef SECUENCEALIGNMENT_H_
#define SECUENCEALIGNMENT_H_



/*
 * estos son los elementos que componen una cadena de caracteres de
 * "ADN", por decirlo de otra manera son nucleotidos
 */
const int A;
const int G;
const int C;
const int T;
const int _;/* "Nucleotido" GAP */
const int BAD_NEOCLEOTIDE;


/*
 * Nucleotidos version caracteres
 */
const char cA;
const char cG;
const char cC;
const char cT;
const char c_;/* "Nucleotido" GAP */

const int SCORE_MATRIX [5][5];


int convertCharToNucletide(char pCaracter);
char convertNucletideToChar(int pNucleotide);
int isDNAFileExtension(char *filePath);
void generateDNA(char *dna, int lenght);
short isValidContents(char *dna);
void alignment(char* dna1,char* dna2);
short isValidFilePath(char * filepath);
void invertString(char * string);

#endif /* SECUENCEALIGNMENT_H_ */
