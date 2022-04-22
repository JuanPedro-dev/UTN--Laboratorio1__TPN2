#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 3e");
    /** 4) Encontrar el menor elemento de una pila y guardarlo en otra. (sin variables, solo pilas)  */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para testing
    apilar(&pila, 10);
    apilar(&pila, 30);
    apilar(&pila, 10);
    apilar(&pila, 7);
    apilar(&pila, 19);

    // Creo una pila descarte para no perder datos
    Pila descarte;
    inicpila(&descarte);

    // Creo una pila menor para guardar el menor sin crear una "variable"
    Pila menor;
    inicpila(&menor);

    // Paso el primer valor a "menor" para poder empezar a comparar con el resto.
    if(!pilavacia(&pila))
    {
        apilar(&descarte, tope(&pila));
        apilar(&menor, desapilar(&pila));
    } else
    {
        printf("\n>> La pila esta VACIA!!!!!");
    }

    // Itero la pila y voy comparando
    while(!pilavacia(&pila))
    {
        if(tope(&menor) > tope(&pila))
        {
            apilar(&descarte, tope(&pila));
            desapilar(&menor);
            apilar(&menor, desapilar(&pila));
        } else
        {
            apilar(&descarte, desapilar(&pila));
        }
    }

    // Armo de nuevo la pila
    while(!pilavacia(&descarte))
    {
        apilar(&pila, desapilar(&descarte));
    }


    // Muestro las pilas.
    system("cls");
    printf("                            Resultados: \n\n");
    if(!pilavacia(&menor))
    {
        printf("\n>> El menor de la pila es: %i\n\n", tope(&menor));

    }else
    {
        printf("\n>> El menor de la pila es: 'No se ingreso una pila.'\n\n", tope(&menor));
    }
    printf(">> Pila es: \n");
    mostrar(&pila);
    printf("\n>> Pila descarte: \n");
    mostrar(&descarte);
    printf("\n\n                        Fin del Programa!\n");
    return 0;
}
