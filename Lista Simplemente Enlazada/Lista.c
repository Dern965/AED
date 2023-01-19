#include "Lista.h"

Lista* crearLista(int *error){
    Lista *nuevaL =malloc(sizeof(Lista));
    if(nuevaL == NULL){
        perror("No hay memoria para crear la lista");
        *error=-1;
        return NULL;
    }
    *nuevaL=NULL;
    return nuevaL;
}

void insertInicio(Lista *l,Dato val,int *error){
    struct Nodo* nuevo = malloc(sizeof(struct Nodo));

    nuevo->valor=val;
    nuevo->sig=NULL;
    nuevo->pos=0;

    if(*l==NULL){
        *l=nuevo;
    }else{
        Lista aux = *l;
        *l=nuevo;
        (*l)->sig=aux;
        aux=*l;
        aux=aux->sig;
        while (aux!=NULL)
        {
            aux->pos++;
            aux=aux->sig;
        }
    }
    *error=0;
}

void insertFinal(Lista *l,Dato val,int *error){
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));

    if(*l == NULL){
        nuevo->valor=val;
        nuevo->sig=NULL;
        nuevo->pos=0;
        *l=nuevo;
    }else{
        Lista aux = *l;
        while (aux->sig != NULL)
        {
            aux = aux->sig;
        }
        nuevo->valor=val;
        nuevo->pos++;
        nuevo->sig= NULL;
        aux->sig=nuevo;
        *error=0;
    }
}

void insertNPos(Lista *l,Dato val,int *error, int pos){
    struct Nodo *nuevo = malloc(sizeof(Lista));

    Lista aux = *l;
    bool exists = false;

    nuevo->valor = val;
    nuevo->sig = NULL;
    nuevo->pos = pos;

    while (aux != NULL){
        if (aux->pos == pos - 1){
            exists = true;
            nuevo->sig = aux->sig;
            aux->sig = nuevo;
            aux = aux->sig->sig;
            while (aux != NULL){
                aux->pos=aux->pos+1;
                aux = aux->sig;
            }
            *error = 0;
            return;
        }
        aux = aux->sig;
        exists = false;
    }
    if(!exists){
        perror("La posicion no existe\n");
        *error = -1;
    }
}

void extractInicio(Lista *l,int *error){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else {
        Dato extract = (*l)->valor;
        printf("Valor extraido: %d \n", extract);
        Lista aux = *l;
        *l=(*l)->sig;
        aux->sig=NULL;
        free(aux);
        aux = *l;
        while (aux != NULL){
            aux->pos=aux->pos-1;
            aux = aux->sig;
        }
        *error = 0;
    }
}

void extractFinal(Lista *l,int *error){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else {
        Lista aux = *l;
        while (aux->sig->sig != NULL){
            aux = aux->sig;
        }
        Dato extract = aux->sig->valor;
        printf("Valor extraido: %d \n", extract);
        free(aux->sig);
        aux->sig=NULL;
        *error = 0;
    }
}

void extractNPos(Lista *l,int *error, int pos){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else if(pos == 0){
        extractInicio(l, error);
    } else {
        Lista aux = *l;
        bool exists = false;
        while (aux != NULL){
            if (aux->pos == pos - 1){
                exists = true;
                Lista aux2 = aux->sig;
                Dato extract = aux2->valor;
                printf("Valor extraido: %d \n", extract);
                aux->sig = aux2->sig;
                aux2->sig = NULL;
                free(aux2);
                aux=aux->sig;
                while (aux != NULL){
                    aux->pos=aux->pos-1;
                    aux = aux->sig;
                }
                *error = 0;
                return;
            }
            aux = aux->sig;
            exists = false;
        }
        *error = 0;
        if (!exists){
            perror("La posicion no existe\n");
            *error = -1;
        }
    }
}

void recorrerLista(Lista l,int *error){
    if(l == NULL){
        return;
    }
    printf("Valor: %d, Posicion: %d\n", l->valor, l->pos);
    recorrerLista(l->sig,error);
}

void borrarLista(Lista* l, int *error){
    Lista aux = *l;
    while(aux != NULL){
        Dato extract = aux->valor;
        printf("Valor extraído: %d \n", extract);
        *l = (*l)->sig;
        free(aux);
        aux = *l;
    }
    *error = 0;
}

void destruirLista(Lista* l, int *error){
    if(l==NULL){
        perror("No hay valores en la Lista");
        *error = -1;
    } else {
        borrarLista(l, error);
        puts("Lista eliminada");
        free(l);
        *error = 0;
    }
}

void main(){
     int error = 0;
    Lista *l = crearLista(&error);
    struct Nodo dato;
    Dato extract;
    int opc;
    int pos;
    do{
        puts("Wenas");
        puts("1.Insertar al Inicio");
        puts("2.Insertar al Final");
        puts("3.Insertar en N posición");
        puts("4.Eliminar al Inicio");
        puts("5.Eliminar al Final");
        puts("6.Eliminar en N posición");
        puts("7.Mostrar Lista");
        puts("8.Limpiar Lista");
        puts("9.Destruir Lista");
        puts("0.Salir");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                puts("Inserte valor");
                scanf("%d", &dato.valor);
                insertInicio(l, dato.valor, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &dato.valor);
                insertFinal(l, dato.valor, &error);
                break;
            case 3:
                puts("Inserte valor y la posicion");
                scanf("%d %d", &dato.valor, &pos);
                insertNPos(l, dato.valor, &error, pos);
                break;
            case 4:
                extractInicio(l, &error);
                break;
            case 5:
                extractFinal(l, &error);
                break;
            case 6:
                puts("Inserte la posicion");
                scanf("%d", &pos);
                extractNPos(l, &error, pos);
                break;
            case 7:
                recorrerLista(*l, &error);
                break;
            case 8:
                borrarLista(l,&error);
                break;
            case 9:
                destruirLista(l,&error);
                break;
            default:
                opc=0;
                puts("Cusbye");
                break;
        }
    } while (opc!=0);
}