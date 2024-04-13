#include "01-Ejercicio.h"

void manejoMsg(int);
PILA crearPila(){
    PILA S;
    S = (PILA)malloc(sizeof(Pila));
    if (S == NULL){
        manejoMsg(0);
        exit(0);
    }
    S->tope = 1;
    return S;
}

int es_vaciaPila(PILA S){
    if (S->tope == -1){
        return TRUE;
    }
    return FALSE;
    
}

void apilar(PILA S, int e){
    if (S->tope == TAM-1){//en caso de que esta llena o sea 99
        manejoMsg(1);// Pila llena
        exit(0);
    }
    (S->tope)++;
    S->pila[S->tope] = e;
}

int desapilar(PILA S){
    int a;
    if (es_vaciaPila(S) == TRUE){
        manejoMsg(2);//Pila vacia
        exit(0);
    }
    a = S->pila[S->tope];
    (S->tope)--;
    return a;
}

//copiar
int copiaPila(PILA S, PILA S2, PILA S3){
    int aux;
    while (es_vaciaPila(S) == FALSE){
        aux = desapilar(S);
        apilar(S2, aux);
        apilar(S3, aux);
    }
    
}

int elemTope(PILA S){
    int a;
    if (es_vaciaPila(S) == TRUE){
        manejoMsg(2);//pila vacia
        exit(0);
    }
    a = S->pila[S->tope];
    return a;
}
