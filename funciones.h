#pragma once
#include <stdlib.h>
#include "estructuras.h"

void imprimir_cola(Cola *cola, int *numE);

void imprimir_cola_main(Cola_main *cola_main);

void agregar_archivo(Nodo *nodo, Cola_main *cola_main);

void eliminar_archivo(Cola_main *cola_main);

void enqueue(Cola *cola, Nodo *nuevo);

Nodo *dequeue(Cola *cola);

Cola *dequeue2(Cola_main *cola_main);

void enqueue2(Cola_main *cola_main, Cola *nuevo);

Nodo *crear_nodo();

void inicializar_cola(Cola *cola);

void inicializar_cola_main(Cola_main *cola_main);

void invertir(Cola_main *cola_main);

void eliminar_todo(Cola_main *cola);

void procesar(Cola_main *cola);





