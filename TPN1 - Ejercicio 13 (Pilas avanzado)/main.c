#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "../Librerias/pila.h"


/** 13. Suponer un juego de cartas en el que en cada mano se reparten dos cartas
    por jugador. Un jugador gana la mano cuando la suma de sus cartas es mayor que las
    del contrario y al hacerlo coloca todas las cartas (las de él y las de su rival) en
    su pila de puntos. En caso de empate (y para simplificar) siempre gana el jugador1.
    Simular la ejecución del juego de tal manera que dada una pila MAZO (con un número de
    elementos múltiplo de cuatro) distribuya las cartas en las pilas PUNTOSJUG1 y PUNTOSJUG2
    como si estos hubieran jugado. Utilizar las pilas auxiliares que crea conveniente. */

int main()
{
    system("color 1E");
    setlocale(LC_ALL,"");

    printf("                        Juego cartas - el mayor gana.\n\n");

    // Creo el mazo.
    Pila mazo;
    inicpila(&mazo);

    apilar(&mazo, 3);
    apilar(&mazo, 4);
    apilar(&mazo, 9);
    apilar(&mazo, 2);
    apilar(&mazo, 7);
    apilar(&mazo, 1);


    // Voy a contar 4 cartas para poder jugar, si estan disponibles, ejecuto el juego
    // Pila mazo_aux para contar:
    Pila mazo_aux;
    inicpila(&mazo_aux);


    //Al finalizar el juego pide que el jugador ganador se quede con las cartas.
    Pila pilaJugador1;
    inicpila(&pilaJugador1);
    Pila pilaJugador2;
    inicpila(&pilaJugador2);

    for(int i=0; i<4 && !pilavacia(&mazo); i++)
    {
        apilar(&mazo_aux, desapilar(&mazo));

        // ya pase 4 cartas, entonces tengo 4 cartas y juego...
        if (i == 3)
        {
            // Creo las manos de los jugadores
            Pila cartasJugador2;
            inicpila(&cartasJugador2);

            Pila cartasJugador1;
            inicpila(&cartasJugador1);

            // Reparto, ya verifique que sea multiplo de 4 asique no verifico de nuevo...
            while(!pilavacia(&mazo_aux))
            {
                apilar(&cartasJugador2, desapilar(&mazo_aux));
                apilar(&cartasJugador1, desapilar(&mazo_aux));
            }

          // Para no perder los datos los almaceno en una auxiliar
            Pila cartasJugador1_aux;
            inicpila(&cartasJugador1_aux);
            Pila cartasJugador2_aux;
            inicpila(&cartasJugador2_aux);


            // Muestro las cartas que tiene cada uno en una tabla...
            printf("        Jugador 1       Jugador 2\n");
            while(!pilavacia(&cartasJugador1))
            {
                printf("Cartas:     %d              %d.\n", tope(&cartasJugador1), tope(&cartasJugador2) );

                apilar(&cartasJugador1_aux, desapilar(&cartasJugador1) );
                apilar(&cartasJugador2_aux, desapilar(&cartasJugador2));

            }


            // Calculo las sumas para ver el reultado...
            int sumaJugador1 = 0;
            int sumaJugador2 = 0;

            while(!pilavacia(&cartasJugador1_aux))
            {
                sumaJugador1 += tope(&cartasJugador1_aux);
                apilar(&cartasJugador1, desapilar(&cartasJugador1_aux));
            }

            while(!pilavacia(&cartasJugador2_aux))
            {
                sumaJugador2 += tope(&cartasJugador2_aux);
                apilar(&cartasJugador2, desapilar(&cartasJugador2_aux));
            }

            printf("-----------------------------------\n");
            printf("Suma        %d              %d\n\n", sumaJugador1, sumaJugador2);

            if(sumaJugador1 >= sumaJugador2)
            {
                printf("Felicidades jugador 1 es el ganador\n\n");
                // El ganador se lleva las cartas
                while(!pilavacia(&cartasJugador1))
                {
                    apilar(&pilaJugador1, desapilar(&cartasJugador1));
                    apilar(&pilaJugador1, desapilar(&cartasJugador2));
                    printf("Te llevaste las cartas: ");
                    mostrar(&pilaJugador2);
                }

            } else
            {
                printf("Felicidades jugador 2 es el ganador\n\n");
                // El ganador se lleva las cartas
                while(!pilavacia(&cartasJugador1))
                {
                    apilar(&pilaJugador2, desapilar(&cartasJugador1));
                    apilar(&pilaJugador2, desapilar(&cartasJugador2));
                }
                printf("Te llevaste las cartas: ");
                mostrar(&pilaJugador2);
            }
        }
    }




    printf("\n\n                Fin del programa!\n\n");
    system("pause");
}
