#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"");
    system("color 1E");
    /** 12.Dada la pila ORIGEN ordenarla en forma ascendente por método de inserción dejando el resultado
        en la pila ORIGEN. Para este ejercicio usar lo aprendido para el ejercicio 5.
        Método de inserción: ver cómo funciona
        */
    /**
    pila origen
    Pila final ascendente osea  1 2 3 4 7

    pila aux 7 4 3 2 1

   7 4     3 2 1

    */
    Pila origen;
    inicpila(&origen);

    Pila destino;
    inicpila(&destino);

    Pila auxiliar;
    inicpila(&auxiliar);

    if(!pilavacia(&origen))
    {
        // Si la pila origen no esta vacia, le paso el primer elemento...
        apilar(&destino, desapilar(&origen));

        while(!pilavacia(&origen))
        {
           // Recorro la pila aux y voy poniendo en el orden que va
            while(!pilavacia(&destino))
            {
                if(tope(&origen) < tope(&destino))
                {

                }
            }
        }
    } else
    {
        printf("\nLa pila se encuentra vacia.\n");
    }

    printf("                           Fin Programa!!!\n");
    system("pause");
    return 0;
}
