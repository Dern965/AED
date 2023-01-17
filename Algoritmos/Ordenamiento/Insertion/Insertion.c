#include <stdio.h>

typedef struct{
    int valor;
    float valor2;
}Generico;

void ordenaInsertion(Generico* arreglo,int tam){
    int i,j;
    Generico pivote;
    for(i=1;i<tam;i++){
        pivote=arreglo[i];
        j=i-1;
        while ((j>=0)&&(pivote.valor<arreglo[j].valor))
        {
            arreglo[j+1]=arreglo[j];
            j--;
        }
        arreglo[j+1] = pivote;
    }
}

void imprimeArr(Generico* arreglo, int tam){
    for(int i=0;i<tam;i++){
        printf("Arreglo %d: int: %d y float: %f\n",i,arreglo[i].valor,arreglo[i].valor2);
    }
}

void main(){
    Generico arr[3]={{1,1.1},{-5,1.1},{-17,-17.1}};
    ordenaInsertion(arr,3);
    imprimeArr(arr,3);
}