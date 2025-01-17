#ifndef _cola06_
#define _cola06_
#define TAMCOLA 100
#define TAM 100
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cola[TAMCOLA];
    int primero, ultimo;
    int tam;

}Cola;

typedef Cola* COLA;
COLA crearCola();
int es_vaciaCola(COLA C);
int sig(int i);
void encolar(COLA C, int x);
int desencolar(COLA C);
int primero(COLA C);
int copiaCola(COLA C1, COLA C2);

//PILA

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