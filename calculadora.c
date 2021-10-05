/*
    Primer Programa Intermedio
    
    Cesar Benavides Alvarez
    version 0.1
    Este programa genera el calculo de 3 operaciones
    para encontrar las raices de una funcion Cuadratica,
    cubica o recta
    necesita un circuito : N
    colocar una imagen en el repositorio : ruta
    terminales que se utilizan. El modo de configuracion

*/

// bibliotecas
#include <stdio.h>
#include <math.h>

/* 
operacion cuadratica
pide dos valores al usuario
*/
void cuadratica(){
    double a, b, c;

    printf("Ingrese coeficiente a de la ecuación: ");
    scanf("%lf", &a);
    printf("Ingrese coeficiente b de la ecuación: ");
    scanf("%lf", &b);
    printf("Ingrese coeficiente c de la ecuación: ");
    scanf("%lf", &c);
    if (a == 0)
        printf("El coeficiente a no puede ser igual a cero");
    else {
        double discriminante = pow(b, 2) - 4 * a*c;
        if (discriminante >= 0)
            if (discriminante == 0) {
                double x = -b / (2 * a);
                printf("La raíz única es %.3lf\n", x);
            } else {
                double x1, x2;
                x1 = (-b + sqrt(discriminante)) / (2 * a);
                x2 = (-b - sqrt(discriminante)) / (2 * a);
                printf("La raíz real x1 es %.3lf\n", x1);
                printf("La raíz real x2 es %.3lf\n", x2);
            }
        else {
            double parteReal, parteImaginaria;
            discriminante = fabs(discriminante);
            parteReal = -b / (2 * a);
            parteImaginaria = sqrt(discriminante) / (2 * a);
            printf("La raíz compleja x1 es %.3lf + %.3lfi\n", parteReal, parteImaginaria);
            printf("La raíz compleja x2 es %.3lf - %.3lfi\n", parteReal, parteImaginaria);
        }
    }
}

//funcion raiz cubica
double rcu (double E) { 
    // calculo por el metodo de tablas exponenciales y logaritmicas
    // formula exp(ln(E)/3)
    double raiz;
    if (E> 0) { // el logaritmo natural puede calculaa E>0
        raiz = exp(log(E)/3);
    }
    if (E== 0){ // el logaritmo natural no puede calcular E=0
        raiz = 0;
    }
    if (E<0) {
        raiz =-exp(log(-E)/3); // el logaritmo natural no calcula E < 0
        // es necesario poner el signo "-" a E
    }
    return raiz;
}

/* 
operacion de suma
pide dos valores al usuario
*/
void cubica(){
   double A,B,C,D;
   double a1,b1,c1;
   double p,q,dis;
   double x,y,z,pi;
   double ab,ac;
   double u,v,t;
 
   printf(" Ecuacion cubica de la forma AX^3 + BX^2 + CX + D\n");
   printf(" Introduzca A \n");
   scanf("%lf", &A);
   printf(" Introduzca B \n");
   scanf("%lf", &B);
   printf(" Introduzca C\n");
   scanf("%lf", &C);
   printf(" Introduzca D\n");
   scanf("%lf", &D);
   //cout.precision(3); // muestra la cantidad de decimales deseada
   t = 0.0000000009; // tolerancia o margen de error
   pi = 3.141592654; // el numero pi
   a1 = B/A;
   b1 = C/A;
   c1 = D/A;
   p = b1 - (a1*a1)/3; // variable p del metodo
   q = (2*a1*a1*a1)/27 - (a1*b1)/3 + c1; // variable q del metodo
   dis = (q*q) + (4*p*p*p)/27; // discriminante
   printf(" Ecuacion reducida : Z^3 + %f Z + %f\n",(float)p,(float)q);
   printf(" El discriminante es: %f\n",(float)dis);

   if ( dis >= t ) { //discriminante > 0
     ab = 0.5*(-q + sqrt(dis));
     double racub(ab); // raiz cubica 1, calculo de u
     if (ab> 0) {
	    racub = exp(log(ab)/3);
     };
     if (ab== 0){
	    racub = 0;
     };
     if (ab<0) {
	    racub =-exp(log(-ab)/3);
     };
     ac = -0.5*(q + sqrt(dis));

	 double racub2(ac);
     if (ac> 0) {
	    racub2 = exp(log(ac)/3); //raiz cubica 2, calculo de v
     };
     if (ac== 0){
	    racub2 = 0;
     };
     if (ac<0) {
	    racub2 =-exp(log(-ac)/3);
     };

     u = racub; // variable u del metodo de cardano
     v = racub2; // variable v del metodo de cardano
     x = u + v -(a1/3);
     y = (-0.5)*(u+v) -(a1/3);
     z = (0.5)*sqrt(3)*(u-v);
     printf(" La ecuacion tiene una raiz real y 2 complejas ");
     printf(" X1 %e:",x);
     printf(" X2 %e: + %ei",y,z);
     printf(" X3 %e: - %ei",y,z);
}
 
/* 
   if ((dis < t and dis > -t) and (p>=-t and p<=t)){ //discriminante= p = 0
     cout<<" La ecuacion tiene una sola raiz"<<endl;
     cout<<" X :"<<-(a1/3);
	};
 
 
   if ((dis < t and dis > -t) and (p>=t or p<=-t)){ // discriminante = 0
     ab = -0.5*q;
     double racub(ab);
     if (ab> 0) {
	racub = exp(log(ab)/3); // raiz cubica de u, solo se calcula u
     };
     if (ab== 0){
	racub = 0;
     };
     if (ab<0) {
	racub =-exp(log(-ab)/3);
     };
     u = racub;
     x = 2*u -(a1/3);
     y = -u -(a1/3);
     printf(" La ecuacion tiene raices multiples");
     printf(" X1 %f:",x);
     printf(" X2=X3 %f:",y);
	};
 
 
   if ( dis <= -t ) { // discriminate < 0
    x = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt(-27/(p*p*p)))/3) -(a1/3);
    y = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +2*pi/3) -(a1/3);
    z = (2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +4*pi/3) -(a1/3);
     printf(" La ecuacion tiene 3 raices distintas");
     printf(" X1 %f :",x);
     printf(" X2 %f:",y);
     printf(" X3 %f:",z);
    };

}*/

/* 
operacion de suma
pide dos valores al usuario
*/
void multiplica(){
    int n1, n2;
    printf( "\n   Introduzca primer operando: " );
    scanf( "%d", &n1);
    printf( "\n   Introduzca segundo operando: " );
    scanf( "%d", &n2);
    printf( "\n   %d * %d = %d\n", n1, n2, n1 * n2 );
}


/*
Muestra menu de las posibles operaciones

*/
void muestraMenu(){
    printf( "\n   >>> MENU CALCULADORA <<<" );
        printf( "\n\n   1. calcular raices ecuacion cuadratica." );
        printf( "\n   2. Restar dos numeros.");
        printf( "\n   3. Multiplicar dos numeros.");
        printf( "\n   4. Salir.\n" );

}


void calculadora(){
    char opcion;
   /* ciclo de trabajo para el menu*/
    do
    {
        muestraMenu();

       /* Filtramos la opción elegida por el usuario */
        do
        {
            printf( "\n   Introduzca opcion (1-4): " );
            fflush( stdin );
            scanf( "%c", &opcion);

        } while ( opcion < '1' || opcion > '4' );

        /* La opción sólo puede ser '1', '2', '3' o '4' */

        switch ( opcion )
        {
                      /* Opción 1: calcular raices cuadraticas */
            case '1': cuadratica();
                      break;

                      /* Opción 2: Calcular raices cubicas */
            case '2': cubica();
                      break;

                      /* Opción 3: Calcular ecuacion de la recta */
            case '3': multiplica();

        }

    } while ( opcion != '4' );

}

/*
Funcion principal
*/
int main()
{
   
    calculadora();
    return 0;
}