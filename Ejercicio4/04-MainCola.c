#include "04-Cola.h"
/**
 * 4. Write a program to implement a queue using an array. Create a function
that removes an element from the queue. &gt;
Expected Output:
Initialize a queue!
Check the queue is empty or not? Yes
Insert some elements into the queue:
1 2 3
Insert another element into the queue:
1 2 3 4
Check the queue is empty or not? No
*/

int datosEntrada(COLA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA);
void eliminarElem(COLA);
void colaVacia(COLA);
void liberarMem(COLA, COLA);
void manejaError(int);

int main(){
    COLA C, C1;
    int aux;
    C = crearCola();
    C1 = crearCola();
    
    datosEntrada(C);   
    liberarMem(C, C1);
}

int datosEntrada(COLA C){
    int opc=0,x;
    do{
        printf("\nSeleccione una opcion\n");
        printf("1 - Ingresar elemento\n");
        printf("2 - Mostrar cola\n");
        printf("3 - Elmininar elemento\n");
        printf("4 - Salir\n");
        scanf("%i", &opc);
        printf("\n");

        switch (opc){
            case 1:
                printf("\nIngerse el elemento: \n");
                scanf("%i", &x);
                encolar(C, x);
                break;
            case 2:
                mostrarCola(C);
                break;
            case 3:
                eliminarElem(C);
                mostrarCola(C); 
                colaVacia(C);
                break;
        }
    } while (opc != 4);

}

void mostrarCola(COLA C){
    int x;
    printf("\nElementos de la cola:\n\n");
    while (es_vaciaCola(C) == FALSE){
        x = desencolar(C);
        printf("%i, ", x);
    }
    
}

void eliminarElem(COLA C){
    int elem;
    elem = desencolar(C);
    printf("Elemento eliminado: \n");
    printf("%i", elem);
    
}

void colaVacia(COLA C){
    if (es_vaciaCola(C) == TRUE){
        printf("\nCola con elementos\n");
    }else{
        printf("\nCola vacia\n");
    }
    
}

void liberarMem(COLA C, COLA C1){
    free(C);
    free(C1);
    manejaError(1);
}

void manejaError(int msg){
    char * mensajes[] = {"\n\nNo hay memoria disponible", "\n\nSe ha liberado la memoria", 
                        "\n\nPila llena", "\n\nPila vacia", "\n\nCola llena", "\n\nCola vacia"};
    printf("%s", mensajes[msg] );
}