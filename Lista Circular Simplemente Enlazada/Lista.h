#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Dato;

typedef struct Nodo{
    Dato valor;
    int pos;
    struct Nodo *sig;
};

typedef struct Nodo* Lista;

//Prefunciones lista
Lista *crearLista(int *error);
void insertInicio(Dato val, Lista *cl, int *error);
void insertFinal(Dato val, Lista *cl, int *error);
void insertNPos(Dato val, Lista *cl, int *error, int pos);

Dato extractInicio(Lista *cl, int *error);
Dato extractFinal(Lista *cl, int *error);
Dato extractNPos(Lista *cl, int *error, int pos);

void recorrerLista(Lista *cl, int *error);
bool isEmptyL(Lista cl, int *error);
void borrarLista(Lista *cl, int *error);
void destruirLista(Lista *cl, int *error);