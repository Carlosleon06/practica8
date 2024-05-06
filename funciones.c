#include "funciones.h"
#include "estructuras.h"


void imprimir_cola(Cola *cola)
{
    Nodo *aux = cola->inicio;
    while (aux != NULL)
    {
        printf("Nombre: %s\n", aux->archivo.nombre);
        printf("Paginas: %d\n", aux->archivo.paginas);
        aux = aux->sig;
    }
}

void enqueue(Cola *cola, Nodo *nuevo)
{
    if (cola->inicio == NULL)
    {
        cola->inicio = nuevo;
        cola->fin = nuevo;
    }
    else
    {
        cola->fin->sig = nuevo;
        cola->fin = nuevo;
    }
    cola->cantidad_nodos++;
}

Nodo dequeue(Cola *cola)
{
    Nodo *aux = cola->inicio;
    cola->inicio = cola->inicio->sig;
    free(aux);
    cola->cantidad_nodos--;
    return *aux;
}

void agregar_archivo(Nodo nodo, Cola_main *cola_main)
{
    if(nodo.archivo.paginas == NULL){
        printf("No se puede agregar un archivo vacio\n");
        return;
    }
    crear_nodo(nodo);
    printf("Nombre del archivo: ");
    scanf("%s", nodo.archivo.nombre);
    printf("Numero de paginas: ");
    scanf("%d", &nodo.archivo.paginas);

    for(int i = 0; i < cola_main->cantidad_colas; i++){
        
        if(nodo.archivo.paginas > cola_main->fin->fin->archivo.paginas){
        Cola *cola = (Cola *)malloc(sizeof(Cola));
        inicializar_cola(cola);
        enqueue(cola, &nodo);
        enqueue2(cola_main, cola);
        
        if(nodo.archivo.paginas < cola_main->inicio->inicio->archivo.paginas){
        Cola *cola = (Cola *)malloc(sizeof(Cola));
        inicializar_cola(cola);
        enqueue(cola, &nodo);
        enqueue2(cola_main, cola);
    }


    if()
    if()
    enqueue(cola, archivo);
    if (cola->inicio == NULL)
    {
        cola_main->inicio = cola;
        cola_main->fin = cola;
    }
    else
    {
        cola_main->fin->sig = cola;
        cola_main->fin = cola;
    }
    cola_main->cantidad_nodos++;
}

void crear_nodo(Nodo nodo){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->sig = NULL;
}

void inicializar_cola(Cola *cola)
{
    cola->inicio = NULL;
    cola->fin = NULL;
    cola->cantidad_nodos = 0;
}

void inicializar_cola_main(Cola_main *cola_main)
{
    cola_main->inicio = NULL;
    cola_main->fin = NULL;
    cola_main->cantidad_colas = 0;
}

void enqueue2(Cola_main *cola, Cola *nuevo){
    if (cola->inicio == NULL)
    {
        cola->inicio = nuevo;
        cola->fin = nuevo;
    }
    else
    {
        cola->fin->sig = nuevo;
        cola->fin = nuevo;
    }
    cola->cantidad_colas++;
}

Cola dequeue2(Cola_main *cola)
{
    Cola *aux = cola->inicio;
    cola->inicio = cola->inicio->sig;
    free(aux);
    cola->cantidad_colas--;
    return *aux;
}
