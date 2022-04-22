#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 3e");
    /** 5) Insertar un elemento en una pila ordenada de menor (tope) a mayor (base)
        de forma tal que se conserve el orden. (sin variables, solo pilas)  */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para testing
    apilar(&pila, 100);
    apilar(&pila, 90);
    apilar(&pila, 50);
    apilar(&pila, 30);
    apilar(&pila, 10);

    // Creo una pila descarte para no perder datos.
    Pila descarte;
    inicpila(&descarte);

    // Creo una pila menor para guardar el menor sin crear una "variable".
    Pila elementoNuevo;
    inicpila(&elementoNuevo);

    // Descomentar para probar insertando distintos valores.
//    apilar(&elementoNuevo, 555);
    apilar(&elementoNuevo, 55);
//    apilar(&elementoNuevo, 5);

    // si flag = 0, es porque no metio el numero a la pila
    int flag = 0;

    // Itero la pila y voy comparando
    while(!pilavacia(&pila) && flag == 0)
    {
        if(tope(&elementoNuevo) > tope(&pila))
        {
            apilar(&descarte, desapilar(&pila));
        } else
        {
            apilar(&pila, tope(&elementoNuevo));
            // termino porque ya pase el numero
            flag = 1;
        }
    }

   /** Si flag = 0, signfica:
                                Pila vacia: el numero es mayor a todos en pila
                                Pila llena: el numero es menor a todos en pila
   */
    if(flag == 0 )
    {
        apilar(&pila, tope(&elementoNuevo));
    }

    // Armo de nuevo la pila con el numero agregado
    while(!pilavacia(&descarte))
    {
        apilar(&pila, desapilar(&descarte));
    }

    // Muestro las pilas.
    printf("\n                            Resultados: \n\n");
    printf(">> La pila es: \n");
    mostrar(&pila);
    printf("\n>> Pila descarte: \n");
    mostrar(&descarte);
    printf("\n>>Pila elemento Nuevo");
    mostrar(&elementoNuevo);
    printf("\n\n                        Fin del Programa!\n");



    return 0;
}
