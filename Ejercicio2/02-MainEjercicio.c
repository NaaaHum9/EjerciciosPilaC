#include "01-Ejercicio.h"
/**
 * Funciona el codigo pero al momento de imprimir me da dos datos 
 * de basura al inicio y al final, y en medio se tienen los elementos de la pila
 * 
*/
/*2. Write a program to implement a stack using a singly linked list.
Expected Output:
Push data 1
Push data 2
Push data 3
Push data 4
Pop data: 4
Pop data: 3
Pop data: 2
Pop data: 1
Check a stack is empty or not?
Stack is empty!*/
void datosPila(PILA);
void mostrarPila(PILA);
void liberarMem(PILA, PILA, PILA);
void manejoMsg(int);

int main(){
    int selec = 0;
    PILA S, S2, S3;

    S = crearPila();
    S2 = crearPila();
    S3 = crearPila();

    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Igresar elemento \n");
        printf("2 - Mostrar elementos \n");
        printf("3 - Salir \n");
        scanf("%i", &selec);
        printf("\n");
        switch (selec){
        case 1:
            datosPila(S);
            break;
        case 2:
            copiaPila(S, S2, S3);
            mostrarPila(S2);
            break;
        }

    } while (selec != 3);
    liberarMem(S, S2, S3);
    
}

void datosPila(PILA S){
    int e;
    printf("Ingrese un elemento: \n");
    scanf("%i", &e);
    apilar(S, e);
    //apilar(S, S->pila);

}

//pila donde se aguarde los elementos de la pila S
void mostrarPila(PILA S2){
    int aux;
    printf("Elementos ingresados: \n");
    while (es_vaciaPila(S2) == FALSE){
        aux = desapilar(S2);
        printf("%i \n", aux);
    }
    
}

void manejoMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . .","Pila llena", "Pila vacia", "Se ha liberado la memoria . . .  "};
    printf("%s", mensajes[msg] );
}

void liberarMem(PILA S, PILA S2, PILA S3){
    free(S);
    free(S2);
    free(S3);
    manejoMsg(3);
}
