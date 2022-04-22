#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 3e");
    /** 3) Calcular el promedio de los valores de una pila (usar variables). */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para el testing.
    apilar(&pila, 10);
    apilar(&pila, 20);
    apilar(&pila, 20);
    apilar(&pila, 20);
    apilar(&pila, 20);

    // Creo una pila Auxiliar y la limpio (vacio);
    Pila Aux;
    inicpila(&Aux);

    // Creo la variable acumulador para sumar en acumulador los valores del tope.
    int acumulador = 0;

    // Creo la variable contador para saber cuantos elementos hay.
    int contador = 0;

    // Creo la variable promedio para realizar la cuenta final.
    float promedio;

    // Itero la pila y voy sumando en acumulador
    while(!pilavacia(&pila))
    {
        contador++;
        acumulador += tope(&pila);
        apilar(&Aux, desapilar(&pila));
    }

    promedio = acumulador / contador;

    // Paso a pila para que quede como ingreso
    while(!pilavacia(&Aux))
    {
        apilar(&pila, desapilar(&Aux));
    }

    // Muestro las pilas.
    printf("\n                                       Resultados\n\n");
    printf(">> Promedio: %.2f          Nº de valores: %i \n", promedio, contador);
    printf("\n>> Pila: \n");
    mostrar(&pila);
    printf("\n>> Pila auxiliar: \n");
    mostrar(&Aux);
    printf("\n\n                                      Fin del Programa!\n");

    return 0;
}
