#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 3e");
    /** 2) Contar los elementos de una pila (usar variables)  */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para el testig.
    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 30);
    apilar(&pila, 40);
    apilar(&pila, 50);


    // Creo una pila Auxiliar para cargar los datos y la limpio (vacio);
    Pila Aux;
    inicpila(&Aux);

    // Creo la variable contador para saber cuantos valores hay.
    int contador = 0;

    // Itero la pila y voy sumando 1 en contador
    while(!pilavacia(&pila))
    {
        contador++;
        apilar(&Aux, desapilar(&pila));
    }

    // Paso a pila para que quede como ingreso
    while(!pilavacia(&Aux))
    {
        apilar(&pila, desapilar(&Aux));
    }

    // Muestro las pilas.
    printf("\n                                        Resultados\n\n");
    printf(">> La cantidad de valores en pila: %i\n\n", contador);
    printf("\n>> Pila: \n");
    mostrar(&pila);
    printf("\n>> Pila auxiliar: \n");
    mostrar(&Aux);
    printf("\n\n                                      Fin del Programa!\n");



    return 0;
}
