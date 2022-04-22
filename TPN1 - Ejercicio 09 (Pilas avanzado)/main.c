#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 1e");
    /** 9) Verificar si una pila DADA es capicúa.  */

    // Creo una pila para cargar los datos y la limpio (vacio);
    Pila pila;
    inicpila(&pila);

    // Cargo 5 valores para testing
    apilar(&pila, 2);
    apilar(&pila, 1);
    apilar(&pila, 1);
    apilar(&pila, 5);
    apilar(&pila, 1);
    apilar(&pila, 1);
//    apilar(&pila, 2);

    ////////////////////////////    Si quiero evitar perdida de información //////////////////
    // Si quiero evitar destruir la pila uso un backup
    Pila backup;
    inicpila(&backup);

    // Pila backup 2
    Pila backup2;
    inicpila(&backup2);

    while(!pilavacia(&pila))
    {
        apilar(&backup, tope(&pila));
        apilar(&backup2, desapilar(&pila));
    }

    while(!pilavacia(&backup2))
    {
        apilar(&pila, desapilar(&backup2));
    }


    //////////////////////////////////////////////////////////////////////////////////////////
    // Creo una pila descarte para no perder datos
    Pila descarte;
    inicpila(&descarte);

    // Necesito saber cuántos son para poder comparar la primer parte con la segunda.
    int contador = 0;

    // Itero la pila para la busqueda y hago uso del flag para detener la busqueda
    while(!pilavacia(&pila))
    {
        contador++;
        apilar(&descarte, desapilar(&pila));
    }

    // Avisara cuando tenga valores distintos
    int flag = 0;

    // Paso la mitad de los elementos.
    if(contador % 2 == 0)
    {
        int mitad = contador / 2;
        while(contador > mitad)
        {
            apilar(&pila, desapilar(&descarte));
            contador--;
        }
            // Comparación
            while(!pilavacia(&descarte) && !pilavacia(&pila) && flag == 0)
            {
                if (tope(&descarte) == tope(&pila))
                {
                    desapilar(&descarte);
                    desapilar(&pila);
                } else
                {
                    flag = 1;
                }
            }
    } else
    {
        int mitad = (contador - 1) / 2;
        while(contador > mitad)
        {
            apilar(&pila, desapilar(&descarte));
            contador--;
        }
        // Como la cantidad es impar "paso la mitad" pero queda uno mas en descarte
        desapilar(&pila);

        // Comparación
        while(!pilavacia(&descarte) && !pilavacia(&pila) && flag == 0)
        {

            if (tope(&descarte) == tope(&pila))
            {
                desapilar(&descarte);
                desapilar(&pila);
            } else
            {
                flag = 1;
            }
        }

    }



    // Rearmo la pila
    while(!pilavacia(&backup))
    {
        apilar(&pila, desapilar(&backup));
    }
    // Muestro las pilas.

    printf("                            Resultados: \n\n" );
    if(flag == 0)
    {
        printf("\n >> La pila es capicúa!!!!.\n");
    }else
    {
        printf("\n >> La pila NO es capicúa!.\n");
    }
    printf("\n>> La pila original es: \n");
    mostrar(&pila);
    printf("\n>> Pila descarte: \n");
    mostrar(&descarte);
    printf("\n>> Pila backup: \n");
    mostrar(&backup);
     printf("\n>> Pila backup 2: \n");
    mostrar(&backup2);
    printf("\n\n                        Fin del Programa!\n");

/////////////////////////////////////////////    Alternativa del profe ////////////////////////////////////////////////////
  /**

    // Creo tres pilas, dos para comparar y una para rearmar la pila original
    Pila pila;
    Pila pilaAux;
    Pila descarte;
    inicpila(&pila);
    inicpila(&pilaAux);
    inicpila(&descarte);

    // Pila de Prueba
    apilar(&pila, 1);
    apilar(&pila, 2);
    apilar(&pila, 3);
    apilar(&pila, 2);
    apilar(&pila, 1);

    // Itero pila, copiando en descarte y Aux.
    while(!pilavacia(&pila))
    {
        apilar((&pilaAux), tope(&pila));
        apilar((&descarte), desapilar(&pila));
    }

    // Rearmo pila
    while(!pilavacia(&pilaAux))
    {
        apilar(&pila, desapilar(&pilaAux));
    }

    // ya tengo la pila en su orden Original y en descarte tengo su invertida.
    // Si es capicua al comparar sus valores son iguales...

    int flag = 1; // flag para marcar que son iguales, 0 para marcar que no es capicua

    while(!pilavacia(&pila) && flag == 1)
    {
        if(tope(&pila) == tope(&descarte))
        {
            apilar((&pilaAux), desapilar(&pila));
            desapilar(&descarte);
        } else
        {
            flag = 0;
        }
    }

    // Rearmo pila con la pila auxiliar.
    while(!pilavacia(&pilaAux))
    {
        apilar((&pila), desapilar(&pilaAux));
    }


    // Mostrar resultados:
    if(flag==1)
    {
        printf("\n\n                           Resultados: ");
        printf("\n\n >> La Pila ingresada es capicúa:\n");
        mostrar(&pila);
    } else
    {
        printf("\n\n                           Resultados: ");
        printf("\n\n >> La Pila ingresada NO es capicúa:\n");
        mostrar(&pila);
    }
    printf("\n\n                Fin programa -  create by Juan Pedro UTN !\n");
    */

    return 0;
}
