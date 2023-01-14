#include "Pila.h"

Pila* crearPila(int* error){
    Pila* pila= (Pila*)malloc(sizeof(Pila));
    if(pila == NULL){
        perror("No hay memoria para la pila\n");
        *error=-2;
        return NULL;
    }
    pila->cima= NULL;
    pila->cursor=0;
    *error=0;
    return pila;
}

void consultarCima(Pila p, int* error){
    if(!isEmpty(p,error) && error==0){
        printf("Vlor en la cima: %d\n",p.cima->valor);
    }
    *error=0;
}

void apilar(Pila* p, int* error, struct Nodo dato){
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodo == NULL){
        perror("No hay memoria para almacenar tu info\n");
        *error=-1;
    }
    nodo->valor=dato.valor;
    nodo->ant=p->cima;
    p->cima=nodo;
    p->cursor++;
    *error=0;
}

void desapilar(Pila* p, int* error,struct Nodo* datoex){
    if(!isEmpty(*p,error)){
        struct Nodo* aux=p->cima;
        datoex->valor=aux->valor;
        p->cima=aux->ant;
        aux->ant=NULL;
        p->cursor--;
        free(aux);
        *error=0;
    }else{
        *error=-3;
    }
}

bool isEmpty(Pila p, int* error){
    if(p.cima==NULL){
        *error=-3;
        return true;
    }else{
        *error=0;
        return false;
    }
}

void vaciarPila(Pila* p,int* error){
    while(!isEmpty(*p,error)){
        struct Nodo datoex;
        desapilar(p,error,&datoex);
        printf("Valor extraido: %d\n",datoex.valor);
        *error=0;
    }
}

void destruirPila(Pila* p, int* error){
    if(isEmpty(*p,error)){
        puts("Destruyendo pila");
        free(p);
    }else{
        puts("No se pudo destruir debido a que contiene informacion");
    }
}

void main(){
    int error;
    int cantidad;
    Pila *p=crearPila(&error);
    struct Nodo dato;
    puts("Cuantos datos vas a ingresar a la pila?");
    fflush(stdin);
    scanf("%d",&cantidad);
    for(int i=0; i<cantidad;i++){
        puts("Ingresa un valor");
        fflush(stdin);
        scanf("%d",&dato.valor);
        apilar(p,&error,dato);
    }
    consultarCima(*p,&error);
    vaciarPila(p,&error);
}