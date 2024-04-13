#ifndef _ejercicio02_
#define _ejrcicio02_
#define TAM 100
#define TRUE 1
#define FALSE 0

/*************************************************
 * Headers utilizados para la creacion de la pila*
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pila[TAM];
    int tope;
}Pila;

/*******************************
 * Prototipos de las funciones *
 *******************************/
typedef Pila* PILA;
PILA crearPila();
void apilar(PILA S, int e);
int desapilar(PILA S);
int es_vaciaPila(PILA S);
int elemtope(PILA S);
int copiaPila(PILA S, PILA S2, PILA S3);

#endif