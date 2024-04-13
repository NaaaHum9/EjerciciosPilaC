#include "06-Cola.h"
/**
 * 6. Write a program to reverse the elements of a queue. &gt;
Expected Output:
Queue elements are:

1 2 3 4 5
Reverse Queue, elements are:
5 4 3 2 1
Add two elements to the said queue:
Queue elements are:
5 4 3 2 1 100 200
Reverse Queue, elements are:
200 100 1 2 3 4 5
*/

int datosEntrada(COLA, COLA, PILA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA, PILA);
void liberarMem(COLA, COLA, PILA);
void manejaError(int);

int main(){
    COLA C, C1;
    PILA S;
    int aux;
    C = crearCola();
    C1 = crearCola();
    S = crearPila();
    
    datosEntrada(C, C1, S);   
    liberarMem(C, C1, S);
}

int datosEntrada(COLA C, COLA C1, PILA S){
    int opc=0,x;
    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Ingresar elemento\n");
        printf("2 - Mostrar cola\n");
        printf("3 - Salir\n");
        scanf("%i", &opc);
        printf("\n");

        switch (opc){
            case 1:
                printf("\nIngerse el elemento: \n");
                scanf("%i", &x);
                encolar(C, x);
                apilar(S, x);
                copiaCola(C, C1);
                break;
            case 2:
                mostrarCola(C1, S);
                break;
        }
    } while (opc != 3);

}

void mostrarCola(COLA C1, PILA S){
    int x, y;
    printf("\nElementos de la cola invertida:\n\n");
    while (es_vaciaPila(S) == FALSE){
        x = desapilar(S);
        printf("%i, ", x);
    }
    
    printf("\nElementos en la cola: \n\n");
    while (es_vaciaCola(C1) == FALSE){
        y = desencolar(C1);
        printf("%i, ", y);
    }
    
    
}


void liberarMem(COLA C, COLA C1, PILA S){
    free(C);
    free(C1);
    free(S);
    manejaError(1);
}

void manejaError(int msg){
    char * mensajes[] = {"\n\nNo hay memoria disponible", "\n\nSe ha liberado la memoria", 
                        "\n\nPila llena", "\n\nPila vacia", "\n\nCola llena", "\n\nCola vacia"};
    printf("%s", mensajes[msg] );
}