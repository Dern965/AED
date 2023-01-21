#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Dato;

typedef struct Nodo{
    Dato valor;
    int pos;
    struct Nodo *ant,*sig;
} Nodo;

typedef struct Nodo* Lista;

//Prefunciones
Nodo* crearNodo(Dato valor, int* error);
Lista* crearLista(int* error);

void insertFinal(Lista *l, Dato valor, int* error);
void insertInicio(Lista *l, Dato valor, int *error);
void insertNPos(Lista *l, Dato valor, int pos, int* error);

Dato extractInicio(Lista *l, int* error);
Dato extractFinal(Lista *l, int* error);
Dato extractNPos(Lista *l, int pos, int* error);

void recorrerLista(Lista *l, int *error);
void borrarLista(Lista *l, int *error);

void destruirLista(Lista *l, int *error);