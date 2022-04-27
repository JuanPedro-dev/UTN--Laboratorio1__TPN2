#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"

int main()
{
    setlocale(LC_ALL,"");
    system("color 1E");
    /** 12.Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado
        en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.
        Método de inserción: ver cómo funciona
        */

    Pila origen, destino, auxiliar;
    inicpila(&origen);
    inicpila(&destino);
    inicpila(&auxiliar);

    // Pila de prueba:
    apilar(&origen, 2);
    apilar(&origen, 21);
    apilar(&origen, 34);
    apilar(&origen, 8);
    apilar(&origen, 7);

    if(!pilavacia(&origen))
    {
        // Si la pila origen no esta vacia, le paso el primer elemento...
        apilar(&destino, desapilar(&origen));

        while(!pilavacia(&origen))
        {
            // Recorro la pila origen y voy poniendo en el orden que va
            while(!pilavacia(&origen))
            {
                if(tope(&origen) > tope(&destino))
                {
                    apilar(&auxiliar, desapilar(&destino));
                    apilar(&destino, desapilar(&origen));
                }
                else
                {
                    apilar(&auxiliar, desapilar(&origen));
                }
            }
            // rearmo origen
            while(!pilavacia(&auxiliar))
            {
                apilar (&origen, desapilar(&auxiliar));
            }
            //Paso el tope para comparar si es el "nuevo menor"
            if(!pilavacia(&origen))
            {
                apilar(&destino, desapilar(&origen));
            }
        }
    }
    else
    {
        printf("\nLa pila se encuentra vacia.\n");
    }
    while(!pilavacia(&destino))
    {
        apilar(&origen,desapilar(&destino));
    }

    printf(" >>> La Pila origen ha sido ordenada: \n\n ");
    mostrar(&origen);

    printf("\n\n                           Fin Programa!!!\n");
    system("pause");
    return 0;
}
