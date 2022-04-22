#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"
int main()
{
    setlocale(LC_ALL,"");
    system("color 3e");
    // preguntar si la idea es fijarse si tienen valores repetidos entre a y b.

    /** 10. Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos
        repetidos sobre sí mismo), realizar un programa que calcule en la pila C la operación de unión.   */

    // Creo las pilas a usar, una auxiliar para cada una y una final aUnionB
    Pila originalA;
    Pila originalB;
    Pila auxA;
    Pila auxB;
    Pila aUnionB;

    inicpila(&originalA);
    inicpila(&originalB);
    inicpila(&auxA);
    inicpila(&auxB);
    inicpila(&aUnionB);

    // Creo el modulo de prueba
    apilar((&originalA),1);
    apilar((&originalA),3);
    apilar((&originalA),5);

    apilar((&originalB),3);
    apilar((&originalB),4);
    apilar((&originalB),5);
    apilar((&originalB),2);

    // Idea pasar toda una pila por ej originalB a aUnionB e ir comparando el tope de originalA si esta o no...
    while(!pilavacia(&originalB))
    {
        apilar((&aUnionB), tope(&originalB));
        apilar((&auxB), desapilar(&originalB));
    }

    // Rearmo pila originalB
    while(!pilavacia(&auxB))
    {
        apilar((&originalB), desapilar(&auxB));
    }

    // Tengo dos opciones ahorro una pila usando auxB que no la voy a usar mas o uso una nueva.
    Pila auxUnion;
    inicpila(&auxUnion);

    // Ahora comparo si el tope de originalA esta...

    while(!pilavacia(&originalA))
    {
        int flag = 0; // no son iguales
        while(!pilavacia(&aUnionB) && flag == 0)
        {
           if(tope(&originalA) == tope(&aUnionB))
            {
                apilar((&auxA), desapilar(&originalA)); // escape pila originalA
                flag = 1; // son iguales...
            } else
            {
                apilar((&auxUnion), desapilar(&aUnionB));
            }
        }

        if(flag==0)
        {
            apilar((&aUnionB), tope(&originalA));
            apilar((&auxA), desapilar(&originalA));
        }
        // Rearmo aUnionB
        while(!pilavacia(&auxUnion))
        {
            apilar((&aUnionB), desapilar(&auxUnion));
        }

    }
    // Rearmo la originalA
    while(!pilavacia(&auxA))
    {
        apilar((&originalA), desapilar(&auxA));
    }

    // Mostrar resultados:

        printf("\n\n                           Resultados: ");

        printf("\n\n >> La pila original A es:\n");
        mostrar(&originalA);
        printf("\n\n >> La pila original B es:\n");
        mostrar(&originalB);
        printf("\n\n >> La union de las pilas ingresadas es:\n");
        mostrar(&aUnionB);

    printf("\n\n                Fin programa -  create by Juan Pedro UTN !\n");
    return 0;
}
