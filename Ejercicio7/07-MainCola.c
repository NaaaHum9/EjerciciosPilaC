#include "07-Cola.h"
/**
 * 7. Write a program to calculate the sum of the elements in a queue. &gt;
Expected Output:
Queue elements are: 1 2 3 4 5
Sum of the elements in the queue is: 15
Remove 2 elements from the said queue:
Queue elements are: 3 4 5
Sum of the elements in the queue is: 12
Insert 3 more elements:
Queue elements are: 3 4 5 300 400 500
Sum of the elements in the queue is: 1212
*/

int datosEntrada(COLA, COLA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA);
int suma(COLA);
void liberarMem(COLA, COLA);
void manejaError(int);

int main(){
    COLA C, C1;
    int aux;
    C = crearCola();
    C1 = crearCola();
    
    datosEntrada(C, C1);   
    liberarMem(C, C1);
}

int datosEntrada(COLA C, COLA C1){
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
                encolar(C1, x);
                break;
            case 2:
                mostrarCola(C);
                suma(C1);
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

int suma(COLA C1){
    int sum=0, i;
    for ( i = 0; i <= tamanio(C1); i++){
        sum += desencolar(C1);
        printf("\nSuma: %i", sum);
    }
        
    /*while (es_vaciaCola(C1) == FALSE){
        elem = desencolar(C1);
        elem1 = desencolar(C1);
        sum = elem + elem1;
        printf("\nSuma: %i", sum);
    }*/
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