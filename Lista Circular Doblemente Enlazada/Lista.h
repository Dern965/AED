#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int Dato;

typedef struct Nodo{
    Dato valor;
    int pos;
    struct Nodo *ant, *sig;
} Nodo;

typedef struct Nodo* Lista;

//Prefunciones
Nodo* crearNodo(Dato val, int* error);
Lista* crearLista(int* error);

void insertInicio(Lista* l,Dato val, int* error);
void insertFinal(Lista* l, Dato val, int* error);
void insertNPos(Lista* l, Dato val, int pos, int* error);

Dato extractFin(Lista* l, int* error);
Dato extractInicio(Lista* l, int* error);
Dato extractNPos(Lista* l, int pos, int* error);

void recorreLista(Lista l);
void borrarLista(Lista* l, int *error);

void destruirLista(Lista *l, int *error);