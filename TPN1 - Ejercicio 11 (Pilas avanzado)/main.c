#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"
int main()
{
    setlocale(LC_ALL,"");
    system("color 3e");
    /** 11.Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2)
        dejando el resultado en una pila también ordenada en forma creciente (ORDENADAFINAL).   */

    // Creo las pilas necesarias y las vacio...

    Pila ordenada1;
    inicpila(&ordenada1);

    Pila ordenada2;
    inicpila(&ordenada2);

    Pila ordenadaFinal;
    inicpila(&ordenadaFinal);

    Pila aux1;
    inicpila(&aux1);

    Pila aux2;
    inicpila(&aux2);

    Pila auxFinal;
    inicpila(&auxFinal);

    // Bloque de prueba:
    apilar(&ordenada1, 1);
    apilar(&ordenada1, 2);
    apilar(&ordenada1, 3);
    apilar(&ordenada1, 6);
    apilar(&ordenada1, 9);

    apilar(&ordenada2, 1);
    apilar(&ordenada2, 3);
    apilar(&ordenada2, 4);
    apilar(&ordenada2, 5);
    apilar(&ordenada2, 7);


    // Manos a la obra,
    while(!pilavacia(&ordenada1) && !pilavacia(&ordenada2))
    {
        if(tope(&ordenada1) >= tope(&ordenada2))
        {
            apilar(&aux1, tope(&ordenada1));
            apilar(&auxFinal, desapilar(&ordenada1));
        } else
        {
            apilar(&aux2, tope(&ordenada2));
            apilar(&auxFinal, desapilar(&ordenada2));
        }
    }

    // Me fijo si quedo algo en alguna de las pila y lo paso..
    while(!pilavacia(&ordenada1))
    {
        apilar(&aux1, tope(&ordenada1));
        apilar(&auxFinal, desapilar(&ordenada1));
    }

    while(!pilavacia(&ordenada2))
    {
        apilar(&aux2, tope(&ordenada2));
        apilar(&auxFinal, desapilar(&ordenada2));
    }

    // Paso a la pila final para que quede ordenado...
    while(!pilavacia(&auxFinal))
    {
        apilar(&ordenadaFinal, desapilar(&auxFinal));
    }

    // Rearmo las pilas originales...
    while(!pilavacia(&aux1))
    {
        apilar(&ordenada1, desapilar(&aux1));
    }

    while(!pilavacia(&aux2))
    {
        apilar(&ordenada2, desapilar(&aux2));
    }

    printf("\n\n                           Resultados: ");
    printf("\n\n >>> La pila ORDENADA1 ES: ");
    mostrar(&ordenada1);
    printf("\n\n >>> La pila ORDENADA2 ES: ");
    mostrar(&ordenada2);

    printf("\n\n >>> La pila ORDENADAFINAL ES: ");
    mostrar(&ordenadaFinal);
    return 0;
}
