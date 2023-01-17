#include <stdio.h>

typedef struct{
    int val;
    float val2;
}Numeros;

void mezcla(Numeros* arrD, int mitad, Numeros* arrI, int omitad, Numeros* arreglo, int tam){
    int i=0,j=0,k=0;
    while ((i<mitad) && (j<omitad))
    {
        if (arrI[i].val < arrD[j].val)
        {
            arreglo[k]=arrI[i];
            k++;
            i++;
        }
        else{
            arreglo[k]=arrD[j];
            k++;
            j++;
        }
    }
    while(i<mitad){
        arreglo[k++]=arrI[i++];
    }
    while (j<omitad)
    {
        arreglo[k++]=arrD[j++];
    }
    
}
void sort(Numeros* arreglo,int tam){
    if(tam>1){
        int mitad = tam/2;
        Numeros arrI[mitad], arrD[tam-mitad];
        int i,j,k;
        for(i=0,k=0;i<mitad;i++,k++){
            arrI[i] = arreglo[k];
        }
        for(j=0;j<(tam-mitad);j++,k++){
            arrD[j]=arreglo[k];
        }
        sort(arrI,mitad);
        sort(arrD,tam-mitad);
        mezcla(arrD,mitad,arrI,tam-mitad,arreglo,tam);
    }
}
void impArreglo(Numeros* num, int n){
    for(int i=0;i<n;i++){
        printf("Arreglo %d: Numero: %d\tFloat: %f\n",i,num[i].val,num[i].val2);
    }
}
void main(int argc, char** argv){
    Numeros arreglo[5]={{1,3},{4,5.4},{9,76.3},{12,44},{2,1.1}};
    puts("El arreglo original es");
    impArreglo(arreglo,5);
    puts("Se ordena");
    sort(arreglo,5);
    puts("El arreglo ordenado es:");
    impArreglo(arreglo,5);
}