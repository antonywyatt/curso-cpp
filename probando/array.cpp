#include<stdio.h>
#define num 3
float calificacion[num];
float suma=0,promedio;
int i;
int main(){
    printf("programa para el calculo del promedio de 3 calificaciones: \n");
    
    for(i=0;i<num;i++){
        printf("dame la calificacion: \n",i+1);
        scanf("%f",&calificacion[i]);
    }

    for(i=0;i<num;i++){
        suma=suma+calificacion[i];
    }

    promedio=suma/num;

    printf("El promedio es %f\n\n",promedio);

    return 0;
}
