#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_Nombres 10

typedef struct{
    char nombre[TAM_Nombres];
    int edad;
}Dato;

//Ordenar por nombre (char)
void ordenarNom(Dato* arr){
    Dato aux,aux2;
    int i,j;
    float com;
    for(i=0;i<TAM_Nombres-1;i++){
        for(j=i+1;j<TAM_Nombres;j++){
            com=strcasecmp(arr[i].nombre,arr[j].nombre);
            if(com>0){
                strcpy(aux.nombre,arr[i].nombre);
                aux2=arr[i];
                strcpy(arr[i].nombre,arr[j].nombre);
                arr[i]=arr[j];
                strcpy(arr[j].nombre,aux.nombre);
                arr[j]=aux2;
            }
        }
    }
}

//Ordenar por edad (int)
void ordenarEdad(Dato* arr){
    Dato aux;
    int i,j;
    for(i=0; i<TAM_Nombres-1;i++){
        for(j=i+1; j<TAM_Nombres; j++){
            if(arr[i].edad>arr[j].edad){
                aux=arr[i];
                arr[i]=arr[j];
                arr[j]=aux;
            }
        }
    }
}

void imprimeArreglo(Dato* arr){
    for(int i=0; i<TAM_Nombres;i++){
        printf("Dato %d: Nombre %s, Edad %d\n",i+1,arr[i].nombre,arr[i].edad);
    }
}

void main(){
    Dato arr[TAM_Nombres]={{"Agripino",20},{"Emilio",17},{"Antonia", 45},{"Nepomuceno",10},{"Juanponcio",69},{"Erny",65},{"Asdf",39},{"Assas",83},{"visitacion",74},{"Mario",72}};
    puts("Arreglo Original:");
    imprimeArreglo(arr);
    ordenarEdad(arr);
    puts("Arreglo ordenado por edad:");
    imprimeArreglo(arr);
    ordenarNom(arr);
    puts("Arreglo ordenado por nombre:");
    imprimeArreglo(arr);
}