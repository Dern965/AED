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
}Bicola;

//Prefunciones Bicola
Bicola* crearBicola(int *error);

void enColarInicio(Bicola* bq, int *error, struct Nodo nuevoNodo);
void enColarFinal(Bicola* bq, int *error, struct Nodo nuevoNodo);

Dato desenColar(Bicola* bq, int *error);

bool isEmpty(Bicola bq, int *error);
void borrarCola(Bicola *bq, int *error);
void destruirCola(Bicola *bq,int*error);
void recorrerCola(Bicola bq, int *error);