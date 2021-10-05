/*
    Primer Programa Avanzado
    
    Cesar Benavides Alvarez
    version 0.1
    Este programa genera una regresion lineal de un conjunto de datos
    necesita un circuito : N
    colocar una imagen en el repositorio : ruta
    terminales que se utilizan. El modo de configuracion

*/

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#define N 1000

int cantValores;

// funcion que crea un arreglo dinamico
// crea arreglo de tipo double
double * crea_array_double(int cuantos)
{
    double* apelems=NULL;
    
    apelems= (double *)malloc(cuantos*sizeof(double));
    if(apelems == NULL)
        printf("ERROR.. memoria insuficiente\n");
    return apelems;
}


// cuenta las lineas del archivo
void cuentaLineasArchivo(FILE *fp){
	char buffer[100];
	int c=0,n=0;char l;
	
	while(fgets(buffer,100,fp) != NULL){		
            n++;
    }
	printf("tam del archivo = %d \n",n);
	cantValores=n;
	
	 rewind(fp);
}

// descarga los valores del archivo a los arreglos X Y
void cargaValores(double *x,double *y, FILE *fp){

    char buffer[20];
	char *ptrtoken;
	// recorrido del archivo
	for (int i=0;i<cantValores;i++){
		fgets(buffer,20,fp); // lee la linea del archivo
		ptrtoken = strtok(buffer,","); // lee la primer columna hasta la coma
		x[i]= (double)atof(ptrtoken);
        ptrtoken = strtok(NULL,"\n");
        y[i]= (double)atof(ptrtoken); // lee la segunda columna hasta la coma
		printf("indice %d X:%e Y:%e \n",i,x[i],y[i]);
	}    

}



// carga el archivo con los valores para usar en la regresion lineal
void cargaPuntosXY(char archivo[],double *x, double *y){
    
    FILE *fp; // variable para leer el archivo
    fp=fopen(archivo,"r");
    if(fp==NULL){fputs("error de lectura \n", stderr);exit(1);} // comprueba si se cargo el archivo
    
    cuentaLineasArchivo(fp); // cuenta lineas del archivo muestra
    x=crea_array_double(cantValores); // crea el arreglo para las muestras X
    y=crea_array_double(cantValores); // crea el arreglo para las muestras Y

    cargaValores(x,y,fp); // almacena los valores de X e Y

}


/*Programa principal*/
int main(int argc, char *argv[])
{
    //Declaracion de variables
    char archivo[100];
    double *x,*y;

    if (argc==1){
        printf("Debes de ingresar el nombre del archivo donde estan las variables...");
        exit(1);
    }

    sprintf(archivo,"%s",argv[1]);
    printf("archivo a abrir %s \n", archivo);
    cargaPuntosXY(archivo,x,y);
    //Declaracion de variables 
  /* int n,i;
   double m,b,sumax,sumay,sumaxy,sumax2;
   double x[N],y[N];
  
   // Pedimos la cantidad de puntos
    
   printf("\nIngrese la Cantidad  de puntos: ");
   scanf("%d",&n);

    // mostramos los puntos para pedir el peso y la estatura
   for (i=0;i<n;i++)
   {
        printf("\nPunto==> %d: \tPeso : ",i+1);
        scanf("%f",&y[i]);
        printf("\tEstatura : ",i+1);
        scanf("%f",&x[i]);    
   }

    // Hacemos las sumatorias 
   sumax=sumay=sumaxy=sumax2=0;
   for (i=0;i<n;i++)
   {
       /* suma de los produtos* /
        sumaxy += x[i]*y[i];
        /*  suma de los valores de x^2* /
        sumax2 += x[i]*x[i];
        /*suma de los valores de x* /
        sumax += x[i];
        /*suma de los valores de y* /
        sumay += y[i];
  
   }

   /* Calculamos la pendiente (m) y la interseccion (b)* /
   m = (n*sumaxy - sumax*sumay) / (n*sumax2 - sumax*sumax);
   b = (sumay - m*sumax) / n;

   // Mostramos los valores de la pendiente y de la interseccion
   printf("\n\npendiente(m) = %f \nInterseccion(b) = %f\n\n",m,b);
  
   // la formula para calcular la variable dependiente(Y) es:
   printf("\n\nValor de la variable dependiente es Y = %f*X+ (%f)\n\n",m,b);
  
   //system("pause"); */
   return 0;
}