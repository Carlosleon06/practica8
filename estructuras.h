#ifndef _QUEUES_H
#define _QUEUES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct dato
{
    char *nombre;
    short int paginas;
} Dato;

typedef struct nodo
{
    Dato archivo;
    struct nodo *sig;
} Nodo;

typedef struct cola
{
    Nodo *inicio;
    Nodo *fin;
    short int cantidad_nodos;
    struct cola *sig;
} Cola;

typedef struct cola_main
{
    Cola *inicio;
    Cola *fin;
    short int cantidad_colas;
} Cola_main;

typedef struct pila
{
    Cola *cima;
    short int cantidad_nodos;
} Pila;

#endif
