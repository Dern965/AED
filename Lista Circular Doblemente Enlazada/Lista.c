#include "Lista.h"

Nodo* crearNodo(Dato val, int* error){
    Nodo* new = (Nodo*)malloc(sizeof(Nodo));
    if(new == NULL){
        perror("Error al crear el nodo");
        *error = -1;
    }else{
        new->valor = val;
        new->sig = NULL;
        new->ant = NULL;
        *error = 0;
    }
    return new;
}

Lista* crearLista(int* error){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(l == NULL){
        perror("Error al crear la lista");
        *error = -1;
    }else{
        *l = NULL;
        *error = 0;
    }
    return l;
}

void insertInicio(Lista* l,Dato val, int* error){
    Nodo* new = crearNodo(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->sig = (*l)->ant = new;
        (*l)->pos = 0;
    }
    else{
        (*l)->ant->sig = new;
        new->sig = *l;
        new->sig = (*l)->ant;
        (*l)->ant = new;
        *l = new;
        Nodo* aux = *l;
        aux = *l;
        int i = 0;
        while(aux->sig != *l){
            aux->pos = i;
            aux = aux->sig;
            i++;
        }
        aux->pos = i;
    }
    *error = 0;  
}

void insertFinal(Lista* l, Dato val, int* error){
    Nodo* new = crearNodo(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->sig = (*l)->ant = new;
        (*l)->pos = 0;
    } else {
        Nodo* aux = *l;
        (*l)->ant->sig = new;
        new->ant = (*l)->ant;
        (*l)->ant = new;
        new->ant = *l;
        new->pos = aux->pos + 1;
    }
    *error = 0;
}

void insertNPos(Lista* l, Dato val, int pos, int* error){
    Nodo* new = crearNodo(val, error);
    if(*l == NULL){
        *l = new;
        (*l)->sig = (*l)->ant = new;
        (*l)->pos = 0;
    } else {
        Nodo* aux = *l;
        while(aux->pos != pos){
            aux = aux->sig;
        }
        aux->ant->sig = new;
        new->sig = aux->ant;
        aux->ant = new;
        new->sig = aux;
        Nodo* aux2 = *l;
        int i = 0;
        while(aux2->sig != *l){
            aux2->pos = i;
            aux2 = aux2->sig;
            i++;
        }
        aux2->pos = i;
    }
    *error = 0;
}

Dato extractFin(Lista* l, int* error){
    Dato extract;
    if(*l == NULL){
        perror("Error al eliminar el nodo");
        *error = -1;
        return -1;
    } else {
        Nodo* aux = (*l)->ant;
        extract =(*l)->ant->valor;
        if(aux != (*l)->sig){
            (*l)->ant->ant->sig = *l;
            (*l)->ant = (*l)->ant->ant;
            free(aux);
        }else{
            aux->ant = aux->sig = NULL;
            *l = NULL;
            free(aux);
        }
        *error = 0;
        return extract;
    }
}

Dato extractInicio(Lista* l, int* error){
    Dato extract;
    if(*l == NULL){
        perror("Error al eliminar el nodo");
        *error = -1;
        return -1;
    } else {
        Nodo* aux = *l;
        extract =(*l)->valor;
        if(aux != (*l)->sig){
            (*l)->ant->sig = (*l)->sig;
            (*l)->sig->ant = (*l)->ant;
            *l = (*l)->sig;
            free(aux);
            Nodo* aux2 = *l;
            int i = 0;
            while(aux2->sig != *l){
                aux2->pos = i;
                aux2 = aux2->sig;
                i++;
            }
            aux2->pos = i;
        } else {
            aux->ant = aux->sig = NULL;
            *l = NULL;
            free(aux);
        }
        *error = 0;
        return extract;
    }
}

Dato extractNPos(Lista* l, int pos, int* error){
    Dato extract;
    if(*l == NULL){
        perror("Error al eliminar el nodo");
        *error = -1;
        return -1;
    } else {
        Nodo* aux = *l;
        while(aux->pos != pos){
            aux = aux->sig;
        }
        extract = aux->valor;
        if(aux != (*l)->sig){
            aux->ant->sig = aux->sig;
            aux->sig->ant = aux->ant;
            free(aux);
            Nodo* aux2 = *l;
            int i = 0;
            while(aux2->sig != *l){
                aux2->pos = i;
                aux2 = aux2->sig;
                i++;
            }
            aux2->pos = i;
        } else {
            aux->ant = aux->sig = NULL;
            *l = NULL;
            free(aux);
        }
        *error = 0;
        return extract;
    }
}

void recorreLista(Lista l){
    if(l == NULL){
        printf("La lista esta vacia");
    } else {
        Nodo* aux = l;
        while(aux->sig != l){
            printf("Valor: %d Pos: %d \n", aux->valor, aux->pos);
            aux = aux->sig;
        }
        printf("Valor: %d Pos: %d\n", aux->valor, aux->pos);
    }
}

void borrarLista(Lista* l, int *error){
    if(*l == NULL){
        perror("La lista esta vacia");
    } else {
        while(*l != NULL){
            printf("Eliminando %d\n", extractInicio(l, error));
        }
        *error = 0;
    }
}

void destruirLista(Lista *l, int *error){
    if(*l == NULL){
        perror("La lista esta vacia");
        *error = -1;
    } else {
        borrarLista(l, error);
        free(*l);
        *error = 0;
    }
}

void main(){
    int error = 0;
    Lista *lista = crearLista(&error);
    Dato new;
    Dato extract;
    int answer;
    int opc;
    int pos;
    do{
        puts("wenas");
        puts("1.Insertar al inicio");
        puts("2.Insertar al final");
        puts("3.Insertar en una posicion");
        puts("4.Extraer del inicio");
        puts("5.Extraer del final");
        puts("6.Extraer de una posicion");
        puts("7.Mostrar Lista");
        puts("8.Limpiar Lista");
        puts("9.Destruir Lista");
        puts("0.Salir");
        fflush(stdin);
        scanf("%d", &opc);
        puts("-------------------------");
        switch (opc){
            case 1:
                puts("Inserte valor");
                fflush(stdin);
                scanf("%d", &new);
                insertInicio(lista, new, &error);
                break;
            case 2:
                puts("Inserte valor");
                fflush(stdin);
                scanf("%d", &new);
                insertFinal(lista, new, &error);
                break;
            case 3:
                puts("Inserte el valor y la posición");
                fflush(stdin);
                scanf("%d", &new);
                scanf("%d", &pos);
                insertNPos(lista, new, pos, &error);
                break;
            case 4:
                extract = extractInicio(lista, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 5:
                extract = extractFin(lista, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &pos);
                extract = extractNPos(lista, pos, &error);
                printf("El valor extraido es: %d\n", extract);
                break;
            case 7:
                recorreLista(*lista);
                break;
            case 8:
                borrarLista(lista, &error);
                break;
            case 9:
                destruirLista(lista,&error);
                break;
            default:
                opc=0;
                puts("Cusbye");
                break;
        }
    } while (opc != 0);
}