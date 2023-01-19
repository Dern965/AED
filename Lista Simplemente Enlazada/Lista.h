#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Dato;

typedef struct Nodo{
    Dato valor;
    struct Nodo* sig;
    int pos;
};

typedef struct Nodo* Lista;
Lista* l;

//Prefunciones
Lista* crearLista(int *error);
void insertInicio(Lista *l,Dato val,int *error);
void insertFinal(Lista *l,Dato val,int *error);
void insertNPos(Lista *l,Dato val,int *error, int pos);

void extractInicio(Lista *l,int *error);
void extractFinal(Lista *l,int *error);
void extractNPos(Lista *l,int *error, int pos);

void recorrerLista(Lista l,int *error);
void borrarLista(Lista* l, int *error);
void destruirLista(Lista* l, int *error);