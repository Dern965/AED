#include "Bicola.h"

Bicola* crearBicola(int *error){
    Bicola *newBiCola = malloc(sizeof(Bicola));
    if(newBiCola==NULL){
        perror("No hay memoria para la Bicola");
        *error = -2;
        return NULL;
    }
    newBiCola->cab=NULL;
    newBiCola->fin=NULL;
    newBiCola->cursor=0;
    *error=0;
    return newBiCola;
}

void enColarInicio(Bicola* bq, int *error, struct Nodo nuevoNodo){
    struct Nodo *node = malloc(sizeof(struct Nodo));
    if(node==NULL){
        perror("No hay memoria para almacenar tu información");
        *error = -1;
        return;
    }
    node->valor = nuevoNodo.valor;
    node->sig = NULL;
    if(isEmpty(*bq, error)){
        bq->cab = node;
        bq->fin = node;
    } else {
        node->sig = bq->cab;
        bq->cab = node;
    }
    *error = 0;
    bq->cursor = bq->cursor+1;
}

void enColarFinal(Bicola* bq, int *error, struct Nodo nuevoNodo){
    struct Nodo *node = malloc(sizeof(struct Nodo));
    if(node==NULL){
        perror("No hay memoria para almacenar tu información");
        *error = -1;
        return;
    }
    node->valor = nuevoNodo.valor;
    node->sig = NULL;
    if(isEmpty(*bq, error)){
        bq->cab = node;
        bq->fin = node;
    } else {
        bq->fin->sig = node;
        bq->fin = bq->fin->sig;
    }
    *error = 0;
    bq->cursor=bq->cursor+1;
}

Dato desenColar(Bicola* bq, int *error){
    struct Nodo *aux = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(isEmpty(*bq,error)){
        perror("No puedes realizar esta operacion");
        *error=-1;
        return -1;
    }
    else{
        aux->valor = bq->cab->valor;
        aux->sig=NULL;
        if(bq->cursor == 1){
            bq->cab=NULL;
            bq->fin=NULL;
            bq->cursor=0;
        }else{
            bq->cab=bq->cab->sig;
            bq->cursor--;
        }
        *error=0;
    }
    return aux->valor;
}

bool isEmpty(Bicola bq, int *error){
    if(bq.cursor==0){
        *error=-3;
        return true;
    }else{
        *error=0;
        return false;
    }
}

void borrarCola(Bicola *bq, int *error){
    struct Nodo *aux = malloc(sizeof(struct Nodo));
    while(!isEmpty(*bq, error)){
        aux = bq->cab;
        printf("Eliminando nodo con valor: %d\n", aux->valor);
        bq->cab = bq->cab->sig;
        bq->cursor = bq->cursor - 1;
    }
    free(aux);
    *error = 0;
}

void destruirCola(Bicola *bq,int*error){
    if(isEmpty(*bq, error)){
        perror("No hay información en la cola\n");
        *error = -1;
    } else{
        borrarCola(bq, error);
        free(bq);
        *error=0;
    }
}

void recorrerCola(Bicola bq, int *error){
    if(isEmpty(bq,error)){
        perror("La cola esta vacia");
        *error=-3;
    }else{
        struct Nodo* aux = bq.cab;
        for(int i=0;i<bq.cursor;i++){
            printf("Dato %d: %d\n",(i+1),aux->valor);
            aux=aux->sig;
        }
        *error=0;
    }
}

void main(){
    int error = 0;
    Bicola *bicola = crearBicola(&error);
    struct Nodo dato;
    Dato extract;
    int opc;
    do{
        puts("Menú de ususario");
        puts("1.Encolar");
        puts("2.Encolar al inicio");
        puts("3.Desencolar");
        puts("4.Limpiar la bicola");
        puts("5.Mostrar la bicola");
        puts("6.Destruir bicola");
        puts("------------------");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                puts("Inserte valor");
                scanf("%d", &dato.valor);
                enColarFinal(bicola, &error, dato);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &dato.valor);
                enColarInicio(bicola, &error, dato);
                break;

            case 3:
                extract = desenColar(bicola, &error);
                printf("Dato extraido: %d\n", extract);
                break;
            case 4:
                borrarCola(bicola, &error);
                break;
            case 5:
                recorrerCola(*bicola, &error);
                break;
            case 6:
                destruirCola(bicola,&error);
                break;
            default:
                opc=0;
                puts("Cusbye");
                break;
        }
    } while (opc != 0);
}