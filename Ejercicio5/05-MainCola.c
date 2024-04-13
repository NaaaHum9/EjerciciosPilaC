#include "05-Cola.h"
/**
 * 5. Write a program to count the number of elements in a queue. &gt;
Expected Output:
Initialize a queue!
Check the queue is empty or not? Yes
Number of elements in queue: 0
Insert some elements into the queue:
Queue elements are: 1 2 3
Number of elements in queue: 3
Delete two elements from the said queue:
Queue elements are: 3
Number of elements in queue: 1
Insert another element into the queue:
Queue elements are: 3 4
Number of elements in the queue: 2
*/

int datosEntrada(COLA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA);
int contador(COLA);
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
        printf("3 - Salir\n");
        scanf("%i", &opc);
        printf("\n");

        switch (opc){
            case 1:
                printf("\nIngerse el elemento: \n");
                scanf("%i", &x);
                encolar(C, x);
                contador(C);
                break;
            case 2:
                mostrarCola(C);
                break;
        }
    } while (opc != 3);

}

void mostrarCola(COLA C){
    int x;
    printf("\nElementos de la cola:\n\n");
    while (es_vaciaCola(C) == FALSE){
        x = desencolar(C);
        printf("%i, ", x);
    }
}

int contador(COLA C){
    int cont;
    cont = tamanio(C);
    printf("\nNumeros de elementos en la cola: %i", cont);
    printf("\n");
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