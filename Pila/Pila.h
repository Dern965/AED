#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int valor;
    struct Nodo* ant;
};

typedef struct{
    struct Nodo* cima;
    int cursor;
}Pila;

Pila* crearPila(int*);
void consultarCima(Pila, int*);
void apilar(Pila*, int*, struct Nodo);
void desapilar(Pila*, int*,struct Nodo*);
bool isEmpty(Pila, int*);
void vaciarPila(Pila*,int* );
void destruirPila(Pila*, int*);