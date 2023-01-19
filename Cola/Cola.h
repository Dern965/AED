#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int Dato;

typedef struct Nodo{
    Dato valor;
    struct Nodo* sig;
};

typedef struct{
    struct Nodo* cab;
    struct Nodo* fin;
    int cursor;
}Cola;

//Prefunciones Cola

Cola* crearCola(int *error);
void enColar(Cola *q, int *error, struct Nodo nuevoNodo);
Dato desenColar(Cola *q, int *error);
bool isEmpty(Cola q, int *error);
void borrarCola(Cola *q, int *error);
void destruirCola(Cola *q, int *error);
void recorrerCola(Cola q,int *error);