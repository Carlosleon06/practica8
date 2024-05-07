#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "estructuras.h"


void imprimir_cola(Cola *cola, int *numE){

    for(int i = 0; i < cola->cantidad_nodos; i++){
        
        printf("[%d] %s\n", *numE, cola->inicio->archivo.nombre);
        (*numE)++;
        printf("\n");
        enqueue(cola, dequeue(cola));
    }
}

void imprimir_cola_main(Cola_main *cola_main)
{
    if(cola_main->cantidad_colas == 0){
        printf("No hay archivos en la cola\n");
        return;
    }
    int numE = 1;
    for(int i = 0; i < cola_main->cantidad_colas; i++)
    {
        printf("Archivos de (%d) pagina(s)\n", cola_main->inicio->inicio->archivo.paginas);   
        imprimir_cola(cola_main->inicio, &numE);
        enqueue2(cola_main, dequeue2(cola_main));
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

    nuevo->sig = NULL;
    cola->cantidad_nodos++;
}

Nodo *dequeue(Cola *cola)
{
    Nodo *aux = cola->inicio;
    if (cola->inicio->sig != NULL){
        cola->inicio = cola->inicio->sig;
        cola->cantidad_nodos--;
    } else {
        inicializar_cola(cola);
    }
    
    aux->sig = NULL;
    return aux;
}

void agregar_archivo(Nodo *nodo, Cola_main *cola_main)
{
    nodo = crear_nodo();
    nodo->archivo.nombre = (char *)malloc(50 * sizeof(char));
    printf("Nombre del archivo: \n");
    scanf("%s", nodo->archivo.nombre);
    printf("Numero de paginas: \n");
    scanf("%hd", &nodo->archivo.paginas);
    
    if(nodo->archivo.paginas == 0){
        printf("Valor no válido.\n");
        return;
    }
    if(cola_main->cantidad_colas == 0){
        Cola *cola = (Cola *)malloc(sizeof(Cola));
        inicializar_cola(cola);
        enqueue(cola, nodo);
        enqueue2(cola_main, cola);
        return;
    }
    if (nodo->archivo.paginas < cola_main->inicio->inicio->archivo.paginas){
        Cola *cola = (Cola *)malloc(sizeof(Cola));
        inicializar_cola(cola);
        enqueue(cola, nodo);
        enqueue2(cola_main, cola);    

        for (int i = 0; i < cola_main->cantidad_colas - 1; i++)
            enqueue2(cola_main, dequeue2(cola_main)); 

    } else if (nodo->archivo.paginas > cola_main->fin->inicio->archivo.paginas) {
        Cola *cola = (Cola *)malloc(sizeof(Cola));
        inicializar_cola(cola);
        enqueue(cola, nodo);
        enqueue2(cola_main, cola);  

    } else {
        for (int i = 0; i < cola_main->cantidad_colas; i++){
            if (nodo->archivo.paginas == cola_main->inicio->inicio->archivo.paginas){
                enqueue(cola_main->inicio, nodo);
                enqueue2(cola_main, dequeue2(cola_main)); 
            } else if (nodo->archivo.paginas < cola_main->inicio->inicio->archivo.paginas && nodo->archivo.paginas > cola_main->fin->inicio->archivo.paginas){
                Cola *cola = (Cola *)malloc(sizeof(Cola));
                inicializar_cola(cola);
                enqueue(cola, nodo);
                enqueue2(cola_main, cola);  
            } else {
                enqueue2(cola_main, dequeue2(cola_main)); 
            }
        }
    }
}

void eliminar_archivo(Cola_main *cola_main)
{
    int num_elemento, archivo;
    if (cola_main->cantidad_colas == 0 || cola_main->inicio == NULL)
    {
        printf("No hay archivos en la cola\n");
        return;
    }
    imprimir_cola_main(cola_main);
    printf("Que archivo desea eliminar: ");
    scanf("%d", &num_elemento);
    
    if (num_elemento <= 0)
    {
        printf("Cola no valida\n");
        return;
    }
    int numE = 1;
    for(int i = 0; i < cola_main->cantidad_colas; i++)
    {
        for(int j = 0; j < cola_main->inicio->cantidad_nodos; j++){
            if (numE == num_elemento){
                Nodo *aux = dequeue(cola_main->inicio);
                free(aux->archivo.nombre);
                free(aux);
            }
            if (j != cola_main->inicio->cantidad_nodos)
                enqueue(cola_main->inicio, dequeue(cola_main->inicio));
            numE++;
        }
        if(cola_main->inicio->cantidad_nodos == 0){
            free(dequeue2(cola_main));
        } 
        if (i != cola_main->cantidad_colas)
            enqueue2(cola_main, dequeue2(cola_main));
    }
}

void eliminar_todo(Cola_main *cola){
    if (cola->inicio == NULL) {
        printf("No hay archivos en la cola\n");
        return;
    }
    int numN = cola->inicio->cantidad_nodos;
    int numC = cola->cantidad_colas;
    for(int i = 0; i < numC; i++){
        for(int j = 0; j < numN; j++){
            Nodo *aux = dequeue(cola->inicio);
            free(aux->archivo.nombre);
            free(aux);
        }
        free(dequeue2(cola));
    }
}

void procesar(Cola_main *cola){
    if (cola->inicio == NULL) {
        printf("No hay archivos en la cola\n");
        return;
    }
    if(cola->cantidad_colas == 0){
        printf("No hay archivos en la cola\n");
        return;  
    } 
    if(cola->inicio->cantidad_nodos != 0){
        Nodo *aux = dequeue(cola->inicio);
        printf("Imprimiendo archivo: %s\n", aux->archivo.nombre);
        free(aux->archivo.nombre);
        free(aux);
        if(cola->inicio->cantidad_nodos == 0){
            free(dequeue2(cola));
        }  
    }
}

Nodo *crear_nodo(){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->sig = NULL;
    return nuevo;
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

Cola *dequeue2(Cola_main *cola)
{
    Cola *aux = cola->inicio;
    if (cola->inicio->sig != NULL){
        cola->inicio = cola->inicio->sig;
        cola->cantidad_colas--;
    }
    else {
        inicializar_cola_main(cola);
    }
    aux->sig = NULL;
    return aux;
}

void invertir(Cola_main *cola_main){
    Pila *pila = (Pila *)malloc(sizeof(Pila));
    pila->cima = NULL;
    pila->cantidad_nodos = 0;
    for (int i = 0; i < cola_main->cantidad_colas; i++){
        pila->cima->sig = cola_main->inicio;
        pila->cima = dequeue2(cola_main);
        pila->cantidad_nodos++;
        
    }
    for(int i = pila->cantidad_nodos; i == 0; i--){
        enqueue2(cola_main, pila->cima);
        pila->cima = pila->cima->sig;
        pila->cantidad_nodos--;
    }
}


