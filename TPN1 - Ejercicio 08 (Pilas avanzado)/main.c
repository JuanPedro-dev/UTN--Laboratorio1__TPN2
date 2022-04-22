#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 1e");
    /** 8) Eliminar un elemento de una pila. El eliminarlo, finalizar el recorrido
        y dejar el resto en el mismo orden.  */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para testing
    apilar(&pila, 2);
    apilar(&pila, 8);
    apilar(&pila, 5);
    apilar(&pila, 3);
    apilar(&pila, 6);

    // Creo una pila descarte para no perder datos
    Pila descarte;
    inicpila(&descarte);

    // Elemento Buscado.
    int buscar;
    buscar = 5;
    buscar = 122;

    // Flag, marca la salida al encontrar una coincidencia.
    int flag = 0;

    // Itero la pila para la busqueda y hago uso del flag para detener la busqueda
    while(!pilavacia(&pila) && flag == 0)
    {
        if (buscar == tope(&pila))
        {
            desapilar(&pila);
            flag = 1;
        }
        apilar(&descarte, desapilar(&pila));
    }

    // Rearmo la pila
    while(!pilavacia(&descarte))
    {
        apilar(&pila, desapilar(&descarte));
    }

    // Muestro las pilas.
    printf("                            Resultados: \n\n");

    if(flag == 0)
    {
        printf(">> El elemento %i, NO se encuenta en pila.\n", buscar);
    } else
    {
        printf(">> El elemento %i, fue eliminado de la pila.\n", buscar);
    }
    printf("\n>> La pila original es: \n");
    mostrar(&pila);
    printf("\n>> Pila descarte: \n");
    mostrar(&descarte);
    printf("\n\n                        Fin del Programa!\n");




    return 0;
}
