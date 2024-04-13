#include "06-Cola.h"

void manejaError();

COLA crearCola(){
    COLA C;
    C = (COLA)malloc(sizeof(Cola));
    if (C == NULL){
        manejaError(0);
        exit(0);
    }
    C->primero = 0;
    C->ultimo = 0;
    C->tam = 0;
    return C;

}

int es_vaciaCola(COLA C){
    if (C->tam == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

//Calcula la posicion en la cola
int sig(int i){
    int p;
    p = (i+1) % TAMCOLA;
    return p;
}

void encolar(COLA C, int x){
    if (C->tam == TAMCOLA){
        manejaError(4);//cola llena
        exit(0);
    }
    C->cola[C->ultimo] = x;
    C->ultimo = sig(C->ultimo);
    C->tam = C->tam+1;
}

int desencolar(COLA C){
    int v;
    if (es_vaciaCola(C) == TRUE){
        manejaError(5);
        exit(0);
    }
    v = C->cola[C->primero];
    C->primero = sig(C->primero);
    C->tam = C->tam-1;
    return v;
    
}

int copiaCola(COLA C1, COLA C2){
    int x;
    while (es_vaciaCola(C1) == FALSE){
        x = desencolar(C1);
        encolar(C2, x);
    }
    
}

// CONSULTAR EL PRIMER ELEMENTO DE LA ESTRUCTURA COLA
int primero(COLA C){
    int v;
    if (es_vaciaCola(C) == TRUE){
        manejaError(5);
        exit(0);
    }
    v = C->cola[C->primero];
    return v;
}

//PILA

PILA crearPila(){
    PILA S;
    S = (PILA)malloc(sizeof(Pila));
    if (S == NULL){
        manejaError(0);
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
        manejaError(1);// Pila llena
        exit(0);
    }
    (S->tope)++;
    S->pila[S->tope] = e;
}

int desapilar(PILA S){
    int a;
    if (es_vaciaPila(S) == TRUE){
        manejaError(2);//Pila vacia
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
        manejaError(2);//pila vacia
        exit(0);
    }
    a = S->pila[S->tope];
    return a;
}