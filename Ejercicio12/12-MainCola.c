#include "12-Cola.h"
/**
 * 12. Write a program to sort the elements of a queue in ascending order. &gt;
Expected Output:

Input some elements into the queue:
Elements of the queue:
4 2 7 5 1
Sort the said queue:
Elements of the sorted queue in ascending order:
1 2 4 5 7
Input two more elements into the queue:
Elements of the queue:
1 2 4 5 7 -1 3
Sort the said queue:
Elements of the sorted queue in ascending order:
-1 1 2 3 4 5 7
*/

int datosEntrada(COLA);//solicita los datos int hasta que el usuario indique qeu ya no mas
void mostrarCola(COLA);
void ordenamiento(COLA);
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

void ordenamiento(COLA C){
    int tem, i, j;
    for ( i = 0; i < tamanio(C)-1; i++){
        for ( j = 0; j < tamanio(C)-i-1; j++){
            if (/* condition */)
            {
                /* code */
            }
            
        }
        
        /* code */
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