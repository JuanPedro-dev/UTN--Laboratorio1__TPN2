#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 3e");
    /** 1) Sumar los elementos de una pila (usar variables) */

    // Creo una pila y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para el testing.
    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 20);
    apilar(&pila, 20);
    apilar(&pila, 20);


    // Creo una pila Auxiliar para no perder datos y la limpio (vacio);
    Pila Aux;
    inicpila(&Aux);

    // Creo la variable acumulador para ir sumandole los valores del tope de la pila.
    int acumulador = 0;

    // Itero la pila y voy sumando en acumulador
    while(!pilavacia(&pila))
    {
        acumulador += tope(&pila);
        apilar(&Aux, desapilar(&pila));
    }

    // Paso a pila para que quede como ingreso
    while(!pilavacia(&Aux))
    {
        apilar(&pila, desapilar(&Aux));
    }

    // Muestro las pilas.
    printf("\n                                        Resultados\n\n");
    printf(">> La suma de los valores de la pila es: %i\n", acumulador);
    printf("\n>> Pila: \n");
    mostrar(&pila);
    printf("\n>> Pila auxiliar: \n");
    mostrar(&Aux);
    printf("\n\n                                      Fin del Programa!\n");
    return 0;
}
