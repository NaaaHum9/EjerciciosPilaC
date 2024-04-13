#ifndef _cola07_
#define _cola07_
#define TAMCOLA 100
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
int tamanio(COLA C1);

#endif