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

/**
 * @brief convierte un char a "nucleotido" el char tiene que ser A,G,T o C. Esta funcion es de ayuda
 * para la funcion
 * @link alignment(char* dna1,char* dna2)
 * @param pCharacter es el caracter que se  convertira a nucleotido
 * @return un entero que representa un nucleotido
 */
int convertCharToNucletide(char pCharacter);


/**
 * @brief verifica si un archivo tiene extesion ".dna". Para que se considere una extesion valida la direccion
 * del archivo debe contar como minimo con una longitud de 5 caracteres
 * @param filePath es la direccion del archivo a analizar la extension del mismo
 * @return 1 si el archivo tiene la extension ".dna", 0 si no la tiene
 */
int isDNAFileExtension(char *filePath);
/**
 * @brief genera una cadena de caracteres aleatoriamente con un largo deseado, el largo tiene que se ser
 * el largo real de la cadena de caracteres menos uno para que el programador pueda colocar el caracter de
 * escape manualmente fuera de esta funcion.
 * @param dna es la cadena en donde se generaran la cadena aleatoria de ADN.
 * @param lenght es el largo de la cadena de caracteres.
 */
void generateDNA(char *dna, int lenght);

/**
 * @brief convierte un "nucleotido" a char los caracteres de salida son A,G,C o T. Esta funcion es de ayuda
 * para la funcion generateDNA(char *, int ).
 * Obteniendo numeros aleatorios para generar la cadena de ADN a partir de estos numeros, pasando por esta
 * funcion.
 * @param pNucleotide es un entero que toma algun valor de los nucleotidos presentes
 * @return se obtiene un caracter con el valor A,G,C o T. Si el valor de la entrada es invalido se retorna como
 * resultado un nucleotido malo
 * @link BAD_NUCLEOTIDE
 */
char convertNucletideToChar(int pNucleotide);

/**
 * @brief mediante este metodo el usuario puede realizar la verificacion referente al contenido de un string
 * si este se considena una cadena de ADN. Un string que se considere como una cadena de ADN tiene que cumplir
 * una unica condicion, que el contenido o en su defecto los caracteres son A,C,G o T.
 * @param dna es la cadena de caracteres a evaluar
 * @return 1 si cumple con la condicion de ser una cadena de ADN, 0 si la cadena no es de ADN osea contiene algun
 * otro valor que no sea A,C,G o T.
 */
short isValidNucleotideContents(char *dna);

/**
 * @brief Este es el algoritmo de Needleman - Wunsch, para alinear dos cadenas de ADN, este algoritmo no tiene
 * verificacion de que las cadenas de caracteres sean consideradas como cadena de ADN. El algoritmo
 * imprime en pantalla la alineacion
 * @param dna1 es la primera cadena de adn
 * @param dna2 es la segunda cadena de adn
 * @see isValidNucleotideContents(char *dna)
 */
void alignment(char* dna1,char* dna2);
/**
 * @brief Verifica si una direccion de archivo es valida, es un algoritmo minimalista por lo que realmente
 * verifica si cumple con las siguientes condiciones:
 * 1) la direccion del archivo puede tener o no un punto.
 * 2) la direccion del archivo solamente puede contener caracteres alfanumericos con excepcion de los espacios y
 * el punto. Nota no puede contener separadores de archivo ejemplo direccion/de archivo.extension
 * el caracter "/" no es permitido.
 * @param filepath es la direccion del archivo
 * @return 1 si la direccion del archivo es valida segun las anteriores clausulas, 0 en el caso contrario
 */
short isValidFilePath(char * filepath);

/**
 * @brief invierte un string, y esto lo hace sobre el mismo
 * @param string es la cadena de caracteres a invertir
 */
void invertString(char * string);

#endif /* SECUENCEALIGNMENT_H_ */
