#include "Lista.h"

Lista *crearLista(int *error){
    Lista *cl = malloc(sizeof(Lista));
    if(cl==NULL){
        perror("No se puede crear la lista");
        *error = -1;
    } else {
        *cl = NULL;
        *error = 0;
    }
    return cl;
}

void insertInicio(Dato val, Lista *cl, int *error){
    struct Nodo *nodo = malloc(sizeof(struct Nodo));
    nodo->valor = val;
    if(*cl==NULL){
        *cl = nodo;
        nodo->sig = nodo;
        nodo->pos = 0;
        *error = 0;
    } else {
        struct Nodo *aux = *cl;
        int i=1;
        while(aux->sig!=*cl){
            aux->pos=i;
            aux = aux->sig;
            i++;
        }
        aux->pos = i;
        nodo->sig = *cl;
        nodo->pos = 0;
        aux->sig = nodo;
        *cl = nodo;
    }
    *error = 0;
}

void insertFinal(Dato val, Lista *cl, int *error){
    struct Nodo *nodo = malloc(sizeof(struct Nodo));
    nodo->valor = val;
    if(*cl==NULL){
        *cl = nodo;
        nodo->sig = nodo;
        nodo->pos = 0;
        *error = 0;
    } else {
        struct Nodo *aux = *cl;
        int prevPos;
        while(aux->sig!=*cl){
            aux = aux->sig;
        }
        prevPos = aux->pos;
        nodo->pos = prevPos+1;
        nodo->sig = *cl;
        aux->sig = nodo;
    }
    *error = 0;
}

void insertNPos(Dato val, Lista *cl, int *error, int pos){
    struct Nodo *nodo = malloc(sizeof(struct Nodo));
    nodo->valor = val;
    if(*cl==NULL && pos!=0){
        perror("No puedes hacer esta operacion");
        *error = -1;
    } else if(*cl==NULL && pos==0){
        insertInicio(val, cl, error);
    } else {
        struct Nodo *aux = *cl;
        while (aux->sig!=*cl){
            if(aux->pos==pos-1){
                nodo->pos = pos;
                nodo->sig = aux->sig;
                aux->sig = nodo;
                aux = aux->sig->sig;
                while(aux->sig!=*cl){
                    aux->pos = aux->pos+1;
                    aux = aux->sig;
                }
                aux->pos = aux->pos+1;
                *error = 0;
                break;
            }
            aux = aux->sig;
        }
        *error = 0;
        if(pos==aux->pos+1){
            insertFinal(val, cl, error);
        }
    }
}

Dato extractInicio(Lista *cl, int *error){
    if(*cl==NULL){
        perror("La lista esta vacia");
        *error = -1;
        return -1;
    } else {
        struct Nodo *aux = *cl;
        Dato extract = (*cl)->valor;

        if(aux->sig==*cl){
            *cl = NULL;
            return extract;
        }

        while (aux->sig!=*cl){
            aux = aux->sig;
        }
        struct Nodo *aux2 = *cl;
        aux->sig = aux2->sig;
        *cl = (*cl)->sig;
        aux = *cl;
        int i = 0;
        while (aux->sig!=*cl){
            aux->pos=i;
            aux = aux->sig;
            i++;
        }
        aux->pos = i;
        *error = 0;
        return extract;
    }
}

Dato extractFinal(Lista *cl, int *error){
    if(*cl==NULL){
        perror("Lista Vacia");
        *error = -1;
        return -1;
    } else {
        Dato extract;
        struct Nodo *aux = *cl;

        if(aux->sig==*cl){
            extract = aux->valor;
            *cl = NULL;
            return extract;
        }

        while(aux->sig->sig!=*cl){
            aux = aux->sig;
        }
        struct Nodo *aux2 = aux->sig;
        aux2->sig = NULL;
        extract =  aux2->valor;
        aux->sig=*cl;
        *error = 0;
        return extract;
    }
}

Dato extractNPos(Lista *cl, int *error, int pos){
    if(pos==0){
        return extractInicio(cl, error);
    }
    if(*cl==NULL){
        perror("No puedes extraer:(");
        *error = -1;
        return -1;
    } else {
        Dato extract;
        struct Nodo *aux = *cl;
        while(aux->sig!=*cl){
            if(aux->pos==pos-1){
                extract = aux->sig->valor;
                struct Nodo *aux2 = aux->sig;
                aux->sig = aux2->sig;
                aux = aux->sig;
                while (aux->sig!=*cl){
                    aux->pos=aux->pos-1;
                    aux = aux->sig;
                }
                aux->pos = aux->pos - 1;
                *error = 0;
                return extract;
            }
            aux = aux->sig;
        }
        perror("No se encontro la posición");
        *error = -1;
        return -1;
    }
}

void recorrerLista(Lista *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        Lista aux = *cl;
        while(aux->sig!=*cl){
            printf("Valor: %d\tPosicion: %d\n", aux->valor, aux->pos);
            aux = aux->sig;
        }
        printf("Valor: %d\tPosicion: %d\n", aux->valor, aux->pos);
        *error = 0;
    }
}

bool isEmptyL(Lista cl, int *error){
    if(cl==NULL){
        return true;
    } else {
        return false;
    }
}

void borrarLista(Lista *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        Dato temp;
        while(!isEmptyL(*cl, error)){
            temp = extractInicio(cl, error);
            printf("Eliminado %d\n", temp);
        }
    }
}

void destruirLista(Lista *cl, int *error){
    if(*cl==NULL){
        perror("No puedes hacer esta operacion\n");
        *error = -1;
    } else {
        borrarLista(cl, error);
        free(cl);
        printf("Lista eliminada\n");
    }
}

void main(){
    int error = 0;
    Lista *cl = crearLista(&error);
    struct Nodo data;
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
        puts("8.Borrar Lista");
        puts("9.Destruir Lista");
        puts("0.Salir");
        scanf("%d", &opc);
        switch (opc){
            case 1:
                puts("Inserte valor");
                scanf("%d", &data.valor);
                insertInicio(data.valor, cl, &error);
                break;
            case 2:
                puts("Inserte valor");
                scanf("%d", &data.valor);
                insertFinal(data.valor, cl, &error);
                break;
            case 3:
                puts("Inserte valor y la posición");
                scanf("%d %d", &data.valor, &pos);
                insertNPos(data.valor, cl, &error, pos);
                break;
            case 4:
                extract = extractInicio(cl, &error);
                printf("El valor extraído es: %d\n", extract);
                break;
            case 5:
                extract = extractFinal(cl, &error);
                printf("El valor extraído es: %d\n", extract);
                break;
            case 6:
                puts("Inserte la posición");
                scanf("%d", &pos);
                extract = extractNPos(cl, &error, pos);
                printf("El valor extraído es: %d\n", extract);
                break;
            case 7:
                recorrerLista(cl, &error);
                break;
            case 8:
                borrarLista(cl, &error);
                break;
            case 9:
                destruirLista(cl,&error);
                break;
            default:
                opc=0;
                puts("Cusbye");
                break;
        }
    } while (opc != 0);
}