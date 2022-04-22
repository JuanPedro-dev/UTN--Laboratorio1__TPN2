#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 1e");
    /** 6) Usando lo resuelto en el ejercicio 4, pasar los elementos de una pila a otra de forma
    tal que la segunda pila quede ordenada de mayor (tope) a menor (base). Esto se llama método
    de ordenación por selección.  */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para testing
    apilar(&pila, 64);
    apilar(&pila, 81);
    apilar(&pila, 5);
    apilar(&pila, 30);
    apilar(&pila, 10);

    // Creo una pila descarte para no perder datos
    Pila descarte;
    inicpila(&descarte);


    // Pila pilaParaDestruir
    Pila backup;
    inicpila(&backup);

    // Aqui copio los valores en descarte para armar la pila nuevamente y trabajo con la copia backup
    // Esto de debe que en el procedimiento destruyo la pila
    while(!pilavacia(&pila))
    {
        apilar(&descarte, tope(&pila));
        apilar(&backup, desapilar(&pila));
    }

    while(!pilavacia(&descarte))
    {
        apilar(&pila, desapilar(&descarte));
    }


    // Creo una pila menor para guardar el menor sin crear una "variable"
    Pila menor;
    inicpila(&menor);

    Pila ordenada;
    inicpila(&ordenada);

    // Aca se destruye la pila backup.
    while(!pilavacia(&backup))
    {
        // Paso el primer valor a "menor" para poder empezar a comparar con el resto.
        //apilar(&descarte, tope(&pila));
        apilar(&menor, desapilar(&backup));


        // Itero la pila backup y voy comparando
        while(!pilavacia(&backup))
        {
            if(tope(&menor) > tope(&backup))
            {
                apilar(&descarte, desapilar(&menor));
                apilar(&menor, desapilar(&backup));
            } else
            {
                apilar(&descarte, desapilar(&backup));
            }
        }

        // Pongo el menor en ordenada
        apilar(&ordenada, desapilar(&menor));

        // Armo de nuevo la pila backup con los valores sin el menor
        while(!pilavacia(&descarte))
        {
            apilar(&backup, desapilar(&descarte));
        }
    }

    // Muestro las pilas.
    printf("                            Resultados: \n\n");

    printf(">> La pila original es: \n");
    mostrar(&pila);
    printf("\n>> La backup es: \n");
    mostrar(&backup);
    printf("\n>> Pila descarte: \n");
    mostrar(&descarte);
    printf("\n>> Pila Ordenada: \n");
    mostrar(&ordenada);
    printf("\n\n                        Fin del Programa!\n");



    return 0;
}
