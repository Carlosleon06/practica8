#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "funciones.h"

int main(void)
{
    Cola_main cola_main;
    Nodo *nodo;    
    int option;
    int corre_programa=1;
    inicializar_cola_main(&cola_main);

    while(corre_programa)
    {  
        printf("\n\r [0] CAMBIAR PRIORIDAD");
        printf("\n\r [1] MOSTRAR COLA DE IMPRESION");
        printf("\n\r [2] AGREGAR ARCHIVO");
        printf("\n\r [3] ELIMINAR ARCHIVO");
        printf("\n\r [4] ELIMINAR TODOS LOS ARCHIVOS");
        printf("\n\r [5] PROCESAR/IMPRIMIR ARCHIVO");
        printf("\n\r [6] TERMINAR PROGRAMA");
        
        printf("\n\r Escoge opcion: ");
        scanf("%d",&option);
        switch(option)
        {
        case 0:
                invertir(&cola_main);
                break;
        case 1:
                imprimir_cola_main(&cola_main);
                break;

        case 2:
                agregar_archivo(nodo, &cola_main);
                break;

        case 3:
                eliminar_archivo(&cola_main);
                break;
        case 4:
                eliminar_todo(&cola_main);
                break;

        case 5:
                procesar(&cola_main);
                break;
        case 6:
                corre_programa=0;
                break;

        default:
                break;
        }
    }
    printf("\n\n\r");
    return 0;
}

