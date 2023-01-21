#include "Lista.h"

Nodo* crearNodo(Dato valor, int* error){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->valor = valor;
    nodo->sig = nodo->ant = NULL;
    nodo->pos = 0;
    *error = 0;
    return nodo;
}

Lista* crearLista(int* error){
    Lista* l =(Lista*)malloc(sizeof(Lista));
    if(l == NULL)
        *error = 1;
    *l = NULL;
    *error = 0;
    return l;
}

void insertFinal(Lista *l, Dato valor, int* error){
    Nodo* nuevo = crearNodo(valor, error);
    if(*l == NULL){
        *l = nuevo;
        (*l)->sig = (*l)->ant = NULL;
        (*l)->pos = 0;
    }
    else{
        Nodo* aux = *l;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->sig = NULL;
        nuevo->ant = aux;
        nuevo->pos = aux->pos + 1;
    }
    *error = 0;
}

void insertInicio(Lista *l, Dato valor, int *error){
    Nodo* nuevo = crearNodo(valor, error);
    if(*l == NULL){
        *l = nuevo;
        (*l)->sig = (*l)->ant = NULL;
        (*l)->pos = 0;
    }
    else{
        Nodo* aux = *l;
        aux->ant = nuevo;
        nuevo->ant = NULL;
        nuevo->sig = aux;
        nuevo->pos = 0;
        *l = nuevo;
        while(aux->sig != NULL){
            aux->pos = aux->pos + 1;
            aux = aux->sig;
        }
        aux->pos = aux->pos + 1;
    }
    *error = 0;
}

void insertNPos(Lista *l, Dato valor, int pos, int* error){
    Nodo* nuevo = crearNodo(valor, error);
    if(*l == NULL){
        *l = nuevo;
        (*l)->sig = (*l)->ant = NULL;
        (*l)->pos = 1;
    } else if(pos == 0) {
        insertInicio(l, valor, error);
    } else if(pos == contarNodos(*l)-1) {
        insertFinal(l, valor, error);
    } else {
        Nodo* aux = *l;
        while(aux->pos != pos){
            aux = aux->sig;
        }
        nuevo->sig = aux;
        nuevo->ant = aux->ant;
        nuevo->pos = pos;
        aux->ant->sig = nuevo;
        aux->ant = nuevo;
        while(aux->sig != NULL){
            aux->pos = aux->pos + 1;
            aux = aux->sig;
        }
        aux->pos = aux->pos + 1;
    }
    *error = 0;
}

Dato extractInicio(Lista *l, int* error){
    if(*l == NULL){
        perror("Lista vacia");
        *error = -1;
        return -1;
    }else{
        Nodo* aux = *l;
        Dato answer = aux->valor;
        *l = (*l)->sig;
        aux->sig = NULL;
        free(aux);
        if(*l != NULL){
            (*l)->ant = NULL;
            (*l)->pos = 0;
            aux = *l;
            while(aux->sig != NULL){
                aux = aux->sig;
                aux->pos = aux->pos - 1;
            }
            aux->pos = aux->pos - 1;
        }
        return answer;
    }
    *error = 0;
}

Dato extractFinal(Lista *l, int* error){
    if(*l == NULL){
        perror("Lista vacia");
        *error = -1;
        return -1;
    }else{
        Nodo* aux = *l;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        Dato answer = aux->valor;
        aux->ant->sig = NULL;
        aux->ant=NULL;
        free(aux);
        return answer;
    }
    *error = 0;
}

Dato extractNPos(Lista *l, int pos, int* error){
    if(*l == NULL){
        perror("Lista vacia");
        *error = -1;
        return -1;
    } else if(pos == 0){
        return extractInicio(l, error);
    } else if(pos == contarNodos(*l)-1){
        return extractFinal(l, error);
    } else {
        Nodo* aux = *l, *aux2;
        while(aux->pos != pos){
            aux = aux->sig;
        }
        Dato answer = aux->valor;
        aux->ant->sig = aux->sig;
        aux->sig->ant = aux->ant;
        aux2 = aux->sig;
        aux->sig = aux->ant = NULL;
        free(aux);
        while(aux2->sig != NULL){
            aux2->pos = aux2->pos - 1;
            aux2 = aux2->sig;
        }
        aux2->pos = aux2->pos - 1;
        *error = 0;
        return answer;
    }
}

void recorrerLista(Lista *l, int *error){
    if(*l == NULL){
        printf("Lista vacia\n");
        *error = 1;
    }
    else{
        Nodo* aux = *l;
        while(aux->sig != NULL){
            printf("Valor: %d , Pos: %d\n", aux->valor, aux->pos);
            aux = aux->sig;
        }
        printf("Valor: %d , Pos: %d\n ", aux->valor, aux->pos);
        printf("\n---------------------\n");
        *error = 0;
    }
}

int contarNodos(Lista l){
    Nodo* aux = l;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->sig;
    }
    return cont;
}

void borrarLista(Lista *l, int *error){
    if(*l == NULL){
        perror("Lista vacia");
        *error = -1;
        return;
    }
    Nodo* aux = *l;
    while(aux != NULL){
        *l = (*l)->sig;
        aux->sig = NULL;
        aux->ant = NULL;
        free(aux);
        aux = *l;
    }
    *error = 0;
}

void destruirLista(Lista *l, int *error){
    if(*l == NULL){
        perror("No se puede aplicar esta operacion\n");
        *error = -1;
    } else {
        borrarLista(l, error);
        free(*l);
        puts("Eliminando Lista");
        *error = 0;
    }
}

void main(){
    int error = 0;
    Lista *lista = crearLista(&error);
    Nodo data;
    Dato extract;
    int answer;
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
        puts("9.Contar Nodos");
        puts("10.Destruir Lista");
        puts("0. Salir");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.valor);
                insertInicio(lista, data.valor, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &data.valor);
                insertFinal(lista, data.valor, &error);
                break;
            case 3:
                puts("Inserte valor y la posición");
                scanf("%d %d", &data.valor, &pos);
                insertNPos(lista, data.valor, pos, &error);
                break;
            case 4:
                extract = extractInicio(lista, &error);
                printf("El valor extraido es %d\n", extract);
                break;
            case 5:
                extract = extractFinal(lista, &error);
                printf("El valor extraido es %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &pos);
                extract = extractNPos(lista, pos, &error);
                printf("El valor extraido es %d\n", extract);
                break;
            case 7:
                recorrerLista(lista, &error);
                break;
            case 8:
                borrarLista(lista, &error);
                break;
            case 9:
                printf("La lista tiene %d nodos\n", contarNodos(*lista));
                break;
            case 10:
                destruirLista(lista,&error);
                break;
            default:
                opc=0;
                puts("Cusbye");
                break;
        }
    } while (opc != 0);
}