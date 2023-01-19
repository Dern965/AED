#include "Cola.h"

Cola* crearCola(int *error){
    Cola *q = (Cola*)malloc(sizeof(Cola));
    if(q == NULL){
        perror("No hay memoria para la cola");
        *error = -2;
        return NULL;
    }
    q->cab=NULL;
    q->fin=NULL;
    q->cursor=0;
    *error=0;
    return q;
}

void enColar(Cola *q, int *error, struct Nodo nuevoNodo){
    struct Nodo *nodoUsuario = malloc(sizeof(struct Nodo));
    if(nodoUsuario == NULL){
        perror("No hay memoria para almacenar la info");
        *error=-1;
        return;
    }
    nodoUsuario->valor=nuevoNodo.valor;
    nodoUsuario->sig=NULL;
    if(isEmpty(*q,error)){
        q->cab=nodoUsuario;
        q->fin=nodoUsuario;
    }else{
        q->fin->sig=nodoUsuario;
        q->fin=q->fin->sig;
    }
    *error=0;
    q->cursor++;
}

Dato desenColar(Cola *q, int *error){
    struct Nodo *aux = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(isEmpty(*q,error)){
        perror("No puedes realizar esta operacion");
        *error=-1;
        return -1;
    }
    else{
        aux->valor = q->cab->valor;
        aux->sig=NULL;
        if(q->cursor == 1){
            q->cab=NULL;
            q->fin=NULL;
            q->cursor=0;
        }else{
            q->cab=q->cab->sig;
            q->cursor--;
        }
        *error=0;
    }
    return aux->valor;
}

bool isEmpty(Cola q, int *error){
    if(q.cursor==0){
        *error=-3;
        return true;
    }else{
        *error=0;
        return false;
    }
}

void borrarCola(Cola *q, int *error){
    while(!isEmpty(*q,error)){
        Dato valorf;
        valorf = desenColar(q,error);
        printf("Valor extraido: %d\n",valorf);
        *error=0;
    }
}

void destruirCola(Cola *q, int *error){
    if(isEmpty(*q,error)){
        perror("No hay info en la cola");
        *error=-1;
    }else{
        borrarCola(q,error);
        free(q);
        *error=0;
        puts("Se destruyo la cola");
    }
}

void recorrerCola(Cola q,int *error){
    if(isEmpty(q,error)){
        perror("La cola esta vacia");
        *error=-3;
    }else{
        struct Nodo* aux = q.cab;
        for(int i=0;i<q.cursor;i++){
            printf("Dato %d: %d\n",(i+1),aux->valor);
            aux=aux->sig;
        }
    }
}

void main(){
    int error =0;
    Cola *q=crearCola(&error);
    struct Nodo nodo;
    Dato dato;
    int opc;

    do{
        puts("Wenas");
        puts("1. Encolar");
        puts("2. Desencolar");
        puts("3. Borrar Cola");
        puts("4. Destruir Cola");
        puts("5. Imprimir Cola");
        puts("0. Salir");
        fflush(stdin);
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            puts("Dame un valor:");
            fflush(stdin);
            scanf("%d",&nodo.valor);
            enColar(q,&error,nodo);
            break;
        case 2:
            dato=desenColar(q,&error);
            printf("Dato extraido: %d\n",dato);
            break;
        case 3:
            borrarCola(q,&error);
            break;
        case 4:
            destruirCola(q,&error);
            break;
        case 5:
            recorrerCola(*q,&error);
            break;
        default:
            opc=0;
            puts("Cusbye");
            break;
        }
    }while(opc != 0);
}