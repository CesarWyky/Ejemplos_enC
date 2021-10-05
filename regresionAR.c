/*

Creación:24/08/2021
Última modificación:
Programa de regresión líneal, 
generación de datos para el 
cálculo de mínimos cuadrados
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
 

//Variables globales
int tam =5; //Este es el valor de n de la ecuación general de los mínimos cuadrados
float n[5];
float t[5];



//Cabeceras
/*
Función para generar aleatorios flotantes
Por simplicidad se modifican arreglos globales, por ello se toma un proceso 
tipo VOID.
*/
void aleatorios(){ 
    int i;
    srand((unsigned) time(NULL));
    for (i = 0; i < tam ; i++){
        n[i]=(float)(rand() % 500)/10;
        printf("Temperatura %d es: %1.2f\n", i, n[i]);
        //////printf( "%1.3f\n", ( rand( ) % 7501 ) / 1000.0f );
    }
}

/*
Función para generar la secuencia de tiempo con incrementos de 0.1s
Por simplicidad se modifican arreglos globales, por ello se toma un proceso 
tipo VOID.
*/
void tiempos(){
    int i=0;
    t[0]=0.1;
    for(i = 1; i < tam ; i++){
        t[i]= t[i-1] + 0.1; 
    }
    for(i = 0; i < tam ; i++){
        printf("El tiempo %d es : %1.2f\n", i, t[i]);
        printf("\b\b"); 
    }
}  

/*
Función para calcular la sumatoria del producto de los puntos X * Y 
Regresa un flotante con el resultado de la sumatoria.
*/
float x_por_y(){
    int i;
    float pro,suma_pro=0;
    for(i=0; i < tam ; i++){
        pro= n[i]*t[i];
        suma_pro= suma_pro + pro;
    }
    return suma_pro;
}

/* 
Funciónes para calcular la sumatoria de los puntos X y Y,
regresa un flotante con dicho valor.
*/
float suma_x(){
    int i;
    float sum_x=0;;
    for(i=0; i < tam ; i++){
        sum_x= sum_x + n[i];
    }
    return sum_x;
}

float suma_y(){
    int i;
    float sum_y=0;;
    for(i=0; i < tam ; i++){
        sum_y= sum_y + t[i];
    }
    return sum_y;
}

/* 
Función para calcular la sumatoria del cuadrado de las X, este valor
es devuelto en una variable tipo flotante.
*/
float suma_x_cua(){
    int i;
    float sum_xcua=0;;
    for(i=0; i < tam ; i++){
        sum_xcua= sum_xcua + (n[i] * n[i]);
    }
    return sum_xcua;
}

/*
Funcion que calcula el valor absoluto de la sumatoria de X,
dicho valor es regresado en un flotante.
*/
float abs_x(){
    float sumaX = suma_x();
    float abs_X = fabs(sumaX);
    abs_X = abs_X * abs_X;
    return abs_X;
}

/*
Función para calcular la pendiente de la recta
*/
float pendiente(){
    float suma, sumaX, sumaY, sumaXCUA, abso_X, m;
    suma = x_por_y(); 
    sumaX = suma_x();
    sumaY = suma_y();
    sumaXCUA = suma_x_cua();
    abso_X = abs_x();
    m= (((tam *  suma)- (sumaX * sumaY))/((tam * sumaXCUA)-abso_X));
    return m;
}

/*
Función para calcular la ordenada al origen de la recta
*/
float ordenada(){
    float suma, sumaX, sumaY, sumaXCUA, abso_X, b;
    suma = x_por_y();
    sumaX = suma_x();
    sumaY = suma_y();
    sumaXCUA = suma_x_cua();
    abso_X = abs_x(); 
    b = (((sumaY * sumaXCUA)-(sumaX * suma))/((tam * sumaXCUA)-abso_X));
    return b;
}


void grafica(){
FILE *gnuplot = popen("gnuplot", "w");
fprintf(gnuplot, "plot '-'\n");
int i;
for (i = 0; i < tam; i++)
    fprintf(gnuplot, "%g %g\n", n[i], t[i]);
fprintf(gnuplot, "e\n");
fflush(gnuplot);
}



//Programa principal
int main(){
    float pend, orde;
    //float suma, sumaX, sumaY, sumaXCUA, abso_X, pend;

    aleatorios(); //Invocación a la función para generar aleatorios
    tiempos(); //Invocación de la función para generar los tiempos en pasos de .1s

    pend = pendiente(); //Invocación para calcular la pendiente de la recta
    printf("El valor de la pendiente es: %1.5f\n", pend);
    
    orde = ordenada();//Invocación para calcular la ordenada al origen de la recta
    printf("El valor de la ordenada al origen es: %1.5f\n", orde);

    printf("La ecuación de la recta calculada a partir de mínimos cuandrasdos es:\n"); //Impresión de la ecuación de la recta
    printf("Y = %1.5f * X + %1.5f \n", pend, orde);

    grafica();
    
    return 0;

}

