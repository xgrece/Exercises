#Ejercicio 1
#define NUM_PARTICIPANTES 5
#define NUM_CARRERAS 3

int main() {
    int ganador = 0;
    float mejor_tiempo = 999999; // Inicializamos con un valor muy grande
    float tiempo_total_ganador = 0;
    float suma_tiempos = 0;
    float promedio_total = 0;

    for (int i = 1; i <= NUM_PARTICIPANTES; i++) {
        float tiempo_total = 0;

        for (int j = 1; j <= NUM_CARRERAS; j++) {
            float tiempo_carrera;

            printf("Ingrese el tiempo de la carrera %d para el participante %d: ", j, i);
            scanf("%f", &tiempo_carrera);

            tiempo_total += tiempo_carrera;

            if (tiempo_carrera < mejor_tiempo) {
                mejor_tiempo = tiempo_carrera;
            }
        }

        if (tiempo_total < tiempo_total_ganador || tiempo_total_ganador == 0) {
            tiempo_total_ganador = tiempo_total;
            ganador = i;
        }

        suma_tiempos += tiempo_total;
    }

    promedio_total = suma_tiempos / NUM_PARTICIPANTES;

    printf("\nEl ganador del premio 'mas rapido del dia' es el participante %d\n", ganador);
    printf("El promedio total de los corredores es: %.2f\n", promedio_total);
    printf("El mejor tiempo del dia es: %.2f\n", mejor_tiempo);

    return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 2
#include <stdio.h>

float ingresarSaldoTotal() {
    float saldoTotal;
    printf("Ingrese el saldo total: ");
    scanf("%f", &saldoTotal);
    return saldoTotal;
}

float ingresarPago() {
    float pago;
    printf("Ingrese el pago parcial: ");
    scanf("%f", &pago);
    return pago;
}

int main() {
    float saldoTotal, saldoParcial, pago, mejorPago = 0, peorPago = 999999;
    float totalSaldos = 0, totalPagos = 0;
    int cantidadPagos;
    char respuesta;

    do {
        saldoTotal = ingresarSaldoTotal();
        saldoParcial = saldoTotal;
        cantidadPagos = 0;

        while (saldoParcial > 0) {
            pago = ingresarPago();
            saldoParcial -= pago;

            if (pago > mejorPago) {
                mejorPago = pago;
            }

            if (pago < peorPago) {
                peorPago = pago;
            }

            cantidadPagos++;
        }

        float vuelto = 0;
        char hayVuelto;

        if (saldoParcial < 0) {
            vuelto = -saldoParcial;
            hayVuelto = 'S';
        } else {
            hayVuelto = 'N';
        }

        printf("Cantidad de pagos realizados: %d\n", cantidadPagos);
        printf("¿Hay que entregar vuelto? %c\n", hayVuelto);
        printf("Vuelto a entregar: %.2f\n", vuelto);

        totalSaldos += saldoTotal;
        totalPagos += cantidadPagos;

        printf("Desea ingresar otro saldo total? (S/N): ");
        scanf(" %c", &respuesta);
        printf("\n");

    } while (respuesta == 'S' || respuesta == 's');

    float promedioSaldos = totalSaldos / totalPagos;
    float promedioPagos = totalPagos / (totalSaldos > 0 ? totalSaldos : 1);

    printf("Mejor pago recibido: %.2f\n", mejorPago);
    printf("Peor pago recibido: %.2f\n", peorPago);
    printf("Promedio de saldos a abonar: %.2f\n", promedioSaldos);
    printf("Promedio de los pagos recibidos: %.2f\n", promedioPagos);

    return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 3
#include <stdio.h>

int ingresardeudatotal(){
 int deudatotal;  
  printf("ingrese el monto de la deuda");
  scanf("%i", &deudatotal);
  return deudatotal;
}
  int ingresarpago(){
    int pago;
  printf("ingrese el pago ");
  scanf("%i", &pago);
    return pago;
}

int main(void) 
{
    //declaro las variables
   int pagototal=0, deudatotal=0, vuelto=0, mejorpago=0, peorpago=99999, pagoparcial, deudaparcial, cantidadPagos=0, pago, hayvuelto, totaldeuda, totalpago, promediopagos, promediodeudas; 
char respuesta;
  //conversion de variables
   do{
    deudatotal = ingresardeudatotal();
    deudaparcial = deudatotal;
  
    while(deudaparcial > 0){
      pago = ingresarpago();
      deudatotal -= pagoparcial;
  
      if(pago > mejorpago){
        mejorpago = pago;
      }
      if(pago < peorpago){
        peorpago = pago;
      }
      cantidadPagos ++;
  }
     //parte vuelto, guardo en char el valor hayvuelto
  if(deudaparcial < 0)
  {
    char hayvuelto;
     hayvuelto = 'S';
    vuelto -= deudaparcial;
  }
    else{
      hayvuelto = 'n';
    }
    
  
     printf("la cantidad de pagos realizados fueron: %i\n", cantidadPagos);
     printf("el mejor pago fue de %i \n y el peor pago fue de %i", mejorpago, peorpago);
     printf("hay vuelto? %c /n", hayvuelto);

     totaldeuda += deudatotal;
     totalpago += pagototal;
     
      printf("Desea ingresar otro saldo total? (S/N): ");
        scanf(" %c", &respuesta);
        printf("\n");

   }while(respuesta =='S');
          promediodeudas = (totaldeuda/totalpago);
          promediopagos= (totalpago/totaldeuda);
  return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 4 (otra version del ejercicio 2)
#include <stdio.h>

float ingresarSaldoTotal() {
    float saldoTotal;
    printf("Ingrese el saldo total: ");
    scanf("%f", &saldoTotal);
    return saldoTotal;
}

float ingresarPago() {
    float pago;
    printf("Ingrese el pago parcial: ");
    scanf("%f", &pago);
    return pago;
}

int main() {
    float saldoTotal, saldoParcial, pago, mejorPago = 0, peorPago = 999999;
    float totalSaldos = 0, totalPagos = 0;
    int cantidadPagos;
    char respuesta;

    do {
        saldoTotal = ingresarSaldoTotal();
        saldoParcial = saldoTotal;
        cantidadPagos = 0;

        while (saldoParcial > 0) {
            pago = ingresarPago();
            saldoParcial -= pago;

            if (pago > mejorPago) {
                mejorPago = pago;
            }

            if (pago < peorPago) {
                peorPago = pago;
            }

            cantidadPagos++;
        }

        float vuelto = 0;
        char hayVuelto;

        if (saldoParcial < 0) {
            vuelto = -saldoParcial;
            hayVuelto = 'S';
        } else {
            hayVuelto = 'N';
        }

        printf("Cantidad de pagos realizados: %d\n", cantidadPagos);
        printf("¿Hay que entregar vuelto? %c\n", hayVuelto);
        printf("Vuelto a entregar: %.2f\n", vuelto);

        totalSaldos += saldoTotal;
        totalPagos += cantidadPagos;

        printf("Desea ingresar otro saldo total? (S/N): ");
        scanf(" %c", &respuesta);
        printf("\n");

    } while (respuesta == 'S' || respuesta == 's');
float promedioSaldos = totalSaldos / totalPagos;
    float promedioPagos = totalPagos / (totalSaldos > 0 ? totalSaldos : 1);

return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 5
#include <stdio.h>

int main(void) {

  int edad=0,cantHombres=0,promedio_edad_M=0,cant_menores=0,menoredad=9999999,cantMenorEdad=0;
  
  int promedio_edad_F=0,cantMujeres=0,cant_18=0;
  
  float peso=0,sumapeso_F=0,promediio_pesoF=0,promedio_pesoM=0,sumapeso_M=0,mayorpeso=0;

  char sexo;


 do {
    printf("\nIngrese su edad:\n");
    scanf("%i", &edad);
} while (edad < 0 || edad > 100);
while(edad !=0){
getchar();
  printf("\ningrese su sexo (F/M):\n");
  scanf("%c", &sexo);

do {
    printf("\nIngrese su peso:\n");
    scanf("%f", &peso);
} while (peso < 0 || peso > 200);

  if(sexo=='F'){
  cantMujeres++;
  sumapeso_F += peso;
  promedio_edad_F += edad;
    if(edad>=18){
      cant_18++;
    }
  }
  if(sexo=='M'){
  cantHombres++;
  sumapeso_M += peso;
  promedio_edad_M += edad;
    if(edad<18){
      cant_menores++;
    }
  }
  if(peso>mayorpeso){
    mayorpeso = peso;
  }
  if(edad<menoredad){
    menoredad = edad;
    cantMenorEdad=1;
    if(edad==menoredad){
      cantMenorEdad++;
    }
  }
do {
    printf("\nIngrese su edad:\n");
    scanf("%i", &edad);
} while (edad < 0 || edad > 100);
}
  promediio_pesoF = (sumapeso_F / cantMujeres);
  promedio_pesoM = (sumapeso_M / cantHombres);
  promedio_edad_F = (promedio_edad_F / cantMujeres);
  promedio_edad_M = (promedio_edad_M / cantHombres);
printf("\nel promedio de peso femenino fue de %.2f y el promedio masculino fue de %.2f\n",promediio_pesoF,promedio_pesoM);
  printf("\nel promedio de edad femenino fue de %i y el promedio masculino fue de %i\n",promedio_edad_F, promedio_edad_M);
  printf("\nla cantidad de mujeres +18 fue de %i\n",cant_18);
  printf("\nla cantidad de hombres -18 fue de %i\n",cant_menores);
  printf("\nel mayor peso leido fue de %.2f\n",mayorpeso);
  printf("\nla menor edad leida fue de %i y se repitio %i veces\n", menoredad,cantMenorEdad);
  return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 6

#include <stdio.h>

int main(void) {
 int vector1[20];
  int vector2[20];
  int vector3[20];
  int posicion, i,valor, num=0;
printf("-----------------Punto 2-------------------\n");
  for(i=0; i < 20; i++){
printf("Ingrese un numero para el vector 1:\n");
    scanf("%i", &vector1[i]);
  }
  
  for(i=0; i < 20; i++){
printf("Ingrese un numero para el vector 2\n");
    scanf("%i", &vector2[i]);
  }

  for(i=0; i<20; i++){
    printf("Ingrese un valor\n");
    scanf("%i", &valor);
    vector1[0] = valor;
  }

  vector2[0] = 100 - valor;
  printf("original %i\n", vector1[i]);
  printf("restando 100 %i\n",vector2[i]);

printf("-----------------punto A-------------------\n");

  for(i=0; i<20; i++){
  if((i%2)==0){
vector3[i] = (i + vector1[i] + vector2[i])*3;
  }
    else{
      vector3[i] = vector1[i] - vector2[i];
    }
  }
    printf("calculo %i\n", vector3[i]);
  
  printf("-----------------Punto B-------------------\n");

  while(posicion){

printf("ingrese una posicion (0-19) (-1 para terminar)\n");
scanf("%i", &posicion);

      if(posicion==-1){
        break;
      }
    if(posicion<0 || posicion>20){
      printf("Numero invalido.Ingrese un numero valido (0-19\n");
    continue;
    }    
  }
printf("valores en la posicion %i\n",posicion);
  printf("-----------------Punto C-------------------\n");

  for(i=20; i<0; i--){

    if((i%2)==0){
      printf("%i", vector3[i]);
    }
  }
  return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 7

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void imprimirTablero(int tablero[SIZE][SIZE]) {
    printf("Tablero:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool validarCasillero(int tablero[SIZE][SIZE], int fila, int columna) {
    if (fila < 0 || fila >= SIZE || columna < 0 || columna >= SIZE) {
        return false;
    }
    return true;
}

bool disparoAcertado(int tablero[SIZE][SIZE], int fila, int columna) {
    if (tablero[fila][columna] == 1) {
        tablero[fila][columna] = 9; // Marcamos el casillero como "Tocado"
        return true;
    }
    return false;
}

int main(void) {
    int tablero[SIZE][SIZE] = {0};

    // Cargar los barcos en el tablero
    srand(time(NULL));
    int barcos_cargados = 0;
    while (barcos_cargados < 8) {
        int fila = rand() % SIZE;
        int columna = rand() % SIZE;

        // Verificar si el casillero está ocupado o adyacente a otro barco
        bool casillero_valido = true;
        if (tablero[fila][columna] == 0) {
            // Verificar casilleros adyacentes
            for (int i = fila - 1; i <= fila + 1; i++) {
                for (int j = columna - 1; j <= columna + 1; j++) {
                    if (validarCasillero(tablero, i, j) && tablero[i][j] == 1) {
                        casillero_valido = false;
                        break;
                    }
                }
                if (!casillero_valido) {
                    break;
                }
            }
        } else {
            casillero_valido = false;
        }

        if (casillero_valido) {
            tablero[fila][columna] = 1;
            barcos_cargados++;
        }
    }

    imprimirTablero(tablero);

    int disparos = 0;
    int disparosTocados = 0;

    while (true) {
        int fila, columna;
        printf("Ingrese fila y columna para disparar (0-%d): ", SIZE - 1);
        scanf("%d %d", &fila, &columna);

        if (!validarCasillero(tablero, fila, columna)) {
            printf("Coordenadas fuera de rango. Juego terminado.\n");
            break;
        }

        if (disparoAcertado(tablero, fila, columna)) {
            printf("Tocado!\n");
            disparosTocados++;
        } else {
            printf("Agua.\n");
        }

        disparos++;
        if (disparos == 10) {
            printf("Has realizado 10 disparos.\n");
            break;
        }
    }

    printf("Total de disparos realizados: %d\n", disparos);
    printf("Total de disparos tocados %i", disparosTocados);
  return 0; 
}

#-------------------------------------------------------------------------
#Ejercicio 8

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

int matriz[50][50], promedio[50];
int i,e,sumaDiagonal=0, promedios=0, sumacolumna=0, fila=0;

    srand(time(NULL));

    
    for (i = 0; i < 50; i++) {
        for (e = 0; e < 50; e++) {
            matriz[i][e] = rand() % 1001;
    }
    }
  printf("%i\n", matriz[i][i]);
   
    for (i = 0; i < 50; i++) {
        sumaDiagonal += matriz[i][i];
    }
    printf("\nLa suma de los valores de la diagonal principal es: %i\n", sumaDiagonal);
printf("\n-----------------------------2----------------------\n");

for(e=0; e<50; e++){
  for(i=0; i<50; i++){
    sumacolumna += matriz[i][e];
  }
   promedio[e] = (sumacolumna / 50);
}
  printf("Vector de promedios:\n");
    for (e = 0; e < 50; e++) {
        printf("%d ", promedio[e]);
    }
    printf("\n");
printf("\n--------------------------3-------------------------\n");

do{
printf("ingrese un numero (0-49)\n");
scanf("%i",&fila);
if(fila<0 || fila >49){
  printf("numero de fila no valido (0-49)\n");
  }
  else{
    printf("fila %i\n",fila);
    for(i=0; i<=49; i++){
      printf("%i",matriz[fila][i]);
    }
       printf("\n");
     }
    } while (fila >= 0 && fila < 49);
 
 return 0; 
}

#-------------------------------------------------------------------------
#Ejercicio 9

#include <stdio.h>
#include <stdlib.h>
int menu();
int leerInt(int,int);
int elevar(int,int);
int mayor(int,int,int,int,int);
int repetidos(int,int,int);
int revisaLetra(char);
void mostrarOrdenado(int,int,int,char);

int main(void)
{
  int base,exponente,resultadoA;
  int numA1,numA2,numA3,numA4,numA5;
  int numB1,numB2,numB3,resultadoB;
  char letraA;
  int numC1,numC2,numC3,resultadoC;
  char letraB;
  
  menu();
 int op =leerInt(0, 5); 
  while(op != 0)
    {
  
  switch (op)      
  {
   
    case 1:
      //printf("OPCION 1 ELEGIDA");      
      system("clear");
      printf("ingrese base: ");
      scanf("%i",&base);
      printf("\ningrese exponente: ");
      scanf("%i",&exponente);
      resultadoA=elevar(base,exponente);
      printf("\nel resultado es: %i",resultadoA);
      getchar();
      getchar();
      menu();
    /*  main();*/
      break;
    case 2:
      //printf("OPCION 2 ELEGIDA");      
      system("clear");
      printf("ingrese 5 valores: \n");
      scanf("%i",&numA1);
      scanf("%i",&numA2);
      scanf("%i",&numA3);
      scanf("%i",&numA4);
      scanf("%i",&numA5);      
      printf("el mayor de los numeros ingresados es: %i",mayor(numA1,numA2,numA3,numA4,numA5));          
      getchar();
      getchar();
      menu();
    /*  main();*/
      break;
    case 3:
      //printf("OPCION 3 ELEGIDA");
      system("clear");
      printf("ingrese 3 valores: \n");
      scanf ("%i",&numB1);
      scanf ("%i",&numB2);
      scanf ("%i",&numB3);
      printf("hubo %i repetidos",repetidos(numB1,numB2,numB3));    
      getchar();
      getchar();
      menu();
    /*  main();*/
      break;
    case 4:
      //printf("OPCION 4 ELEGIDA");  
      system("clear");
      printf("ingrese una letra: \n");  
      scanf (" %c",&letraA);      
      printf("resultado: %i",revisaLetra(letraA));  
      getchar();
      getchar();
      menu();
    /*  main();*/
      break;    
    case 5:
      //printf("OPCION 5 ELEGIDA");
      system("clear");
      printf("INGRESAR 3 VALORES: \n");
      scanf("%i",&numC1);
      scanf("%i",&numC2);
      scanf("%i",&numC3);
      printf("¿Orden ascendente o descendente? a/d: ");
      scanf(" %c",&letraB);    
      mostrarOrdenado(numC1, numC2, numC3, letraB);
      getchar();
      getchar();
      menu();
     /* main();    */  
      break;      
  }
      
      op =leerInt(0, 5);   
      }
    system("clear");
  
  return 0;
}

int menu(void)
{
  system("clear");
  printf("\n1) Elevar un número a una potencia\n");
  printf("2) Encontrar el número mayor\n");
  printf("3) Cantidad de números repetidos\n");
  printf("4) Detectar letras minusculas, mayusculas y números\n");
  printf("5) Ordenar números en orden ascendente o descendente\n");
  printf("\n0) Salir\n");  
  return 0;
}

//FUNCION DEL PUNTO 1:
int elevar(int val1,int val2)
{
  int i,resultado=1;
  for (i=0;i<val2;i++)
  {
    resultado*=val1;
  }    
  return resultado;  
}
//FUNCION DEL PUNTO 2:
int mayor(int val1,int val2,int val3,int val4,int val5)
{
  int resultado;
  if (val1>val2 && val1>val3 && val1>val4 && val1>val5)
  {
    return val1;
  }
  if (val2>val1 && val2>val3 && val2>val4 && val2>val5)
  {
    return val2;
  }
  if (val3>val1 && val3>val2 && val3>val4 && val3>val5)
  {
    return val3;
  }
  if (val4>val1 && val4>val2 && val4>val3 && val4>val5)
  {
    return val4;
  } 
  return val5;  
}
//FUNCION DEL PUNTO 3:
int repetidos(int val1,int val2,int val3)
{
  int cantRep=1;
  if (val1==val2)
  {
    cantRep++;
    if (val1==val3)
    { 
      cantRep++;
    }
  }
  else
  {
    if (val1==val3)
    {
      cantRep++;
    }
    if (val2==val3)
    {
      cantRep++;
    }
  }
  if (cantRep==1)
  {
    cantRep=0;
  }
  return cantRep;
}
//FUNCION DEL PUNTO 4:
int revisaLetra(char letra)
{
  int resultado;
  if (letra>=97 && letra<=122)
  {
    resultado=1;
  }  
  if (letra>=65 && letra<=90)
  {
    resultado=2;
  }  
  if ((letra>=0 && letra<=64) || (letra>=91 && letra<=96)|| (letra>=123 && letra<=127))
  {
    resultado=0;
  }
  return resultado;  
}
//FUNCION DEL PUNTO 5:
void mostrarOrdenado(int num1,int num2,int num3,char letra)
{
  switch (letra)
  {
    case 'a':
      if ((num1>num2) && (num1>num3) && (num2>num3))
      {
        printf("%i\n",num3);
        printf("%i\n",num2);
        printf("%i\n",num1);        
      }
      if ((num1>num2) && (num1>num3) && (num2<num3))
      {
        printf("%i\n",num2);
        printf("%i\n",num3);
        printf("%i\n",num1);
      }
      if ((num2>num1) && (num2>num3) && (num1>num3))
      {
        printf("%i\n",num3);
        printf("%i\n",num1);
        printf("%i\n",num2);
      }
      if ((num2>num1) && (num2>num3) && (num1<num3))
      {
        printf("%i\n",num1);
        printf("%i\n",num3);
        printf("%i\n",num2);
      }
      if ((num3>num1) && (num3>num2) && (num1>num2))
      {
        printf("%i\n",num2);
        printf("%i\n",num1);
        printf("%i\n",num3);
      }   
      if ((num3>=num1) && (num3>=num2) && (num1<=num2))
      {
        printf("%i\n",num1);
        printf("%i\n",num2);
        printf("%i\n",num3);
      }       
      break;
    case 'd':
      if ((num1>num2) && (num1>num3) && (num2>num3))
      {
        printf("%i\n",num1);
        printf("%i\n",num2);
        printf("%i\n",num3);
      }
      if ((num1>num2) && (num1>num3) && (num2<num3))
      {
        printf("%i\n",num1);
        printf("%i\n",num3);
        printf("%i\n",num2);
      }
      if ((num2>num1) && (num2>num3) && (num1>num3))
      {
        printf("%i\n",num2);
        printf("%i\n",num1);
        printf("%i\n",num3);
      }
      if ((num2>num1) && (num2>num3) && (num1<num3))
      {
        printf("%i\n",num2);
        printf("%i\n",num3);
        printf("%i\n",num1);
      }
      if ((num3>num1) && (num3>num2) && (num1>num2))
      {
        printf("%i\n",num3);
        printf("%i\n",num1);
        printf("%i\n",num2);
      }   
      if ((num3>=num1) && (num3>=num2) && (num1<=num2))
      {
        printf("%i\n",num3);
        printf("%i\n",num2);
        printf("%i\n",num1);
      }        
    break;
    default:
      printf("0 0 0");
    break;
  }  
}
//FUNCION DEL PUNTO 6:
int leerInt(int valorMinimo,int valorMaximo)
{
  int resultado,rangoValido=0;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ",valorMinimo,valorMaximo);
  scanf("\n%i",&resultado);
  while(resultado<valorMinimo || resultado>valorMaximo)
  {
     printf("\nFUERA DE RANGO, ingrese nuevamente\n");
     scanf("\n%i",&resultado);
  }
  return resultado;
}

#-------------------------------------------------------------------------
#Ejercicio 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroAleatorio[9]; //Indices de 0 a 9, resultan 10 numeros
    int i, j;
    int hayRepeticiones;

    srand (time(NULL));
    for (i=0; i<9; i++) {
          numeroAleatorio[i] = rand() % 1999 - 999;
    }

   
    for (i=0; i<9; i++) {
        printf("Aleatorio %d vale: %d\n", i, numeroAleatorio[i]);
    }

    return 0;

}

#-------------------------------------------------------------------------
#Ejercicio 11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para cargar el vector con valores aleatorios entre -999 y 999
void cargarVector(int vector[], int tam) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        vector[i] = rand() % 1999 - 999;
    }
}

// Función para mostrar el vector utilizando aritmética de punteros
void mostrarVector(int vector[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", *(vector + i));
    }
    printf("\n");
}

// Función para reemplazar un valor en el vector y contar cuántas veces se modificó
int reemplazarValor(int vector[], int tam, int valorBuscado, int nuevoValor) {
    int vecesModificado = 0;
    for (int i = 0; i < tam; i++) {
        if (vector[i] == valorBuscado) {
            vector[i] = nuevoValor;
            vecesModificado++;
        }
    }
    return vecesModificado;
}

// Función para ordenar el vector de mayor a menor o de menor a mayor
void ordenarVector(int vector[], int tam, int ascendente) {
    int temp;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if ((ascendente && vector[j] > vector[j + 1]) || (!ascendente && vector[j] < vector[j + 1])) {
                // Intercambiar elementos si es necesario
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}

// Función para calcular el valor mayor, el valor menor y su frecuencia
void calcularMayorMenorFrecuencia(int vector[], int tam, int *mayor, int *menor, int *frecMayor, int *frecMenor) {
    *mayor = vector[0];
    *menor = vector[0];
    *frecMayor = 1;
    *frecMenor = 1;

    for (int i = 1; i < tam; i++) {
        if (vector[i] > *mayor) {
            *mayor = vector[i];
            *frecMayor = 1;
        } else if (vector[i] == *mayor) {
            (*frecMayor)++;
        }

        if (vector[i] < *menor) {
            *menor = vector[i];
            *frecMenor = 1;
        } else if (vector[i] == *menor) {
            (*frecMenor)++;
        }
    }
}

// Función para mostrar una parte del vector utilizando aritmética de punteros
void mostrarParteVector(int vector[], int desde, int hasta) {
    for (int *ptr = vector + desde; ptr <= vector + hasta; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

int main() {
    int vector[100];
    int opcion;
    int valorBuscado, nuevoValor;
    int vecesModificado;
    int mayor, menor, frecMayor, frecMenor;
    int desde, hasta;

    do {
        printf("\nMenu de opciones:\n");
        printf("1. Cargar vector random\n");
        printf("2. Mostrar vector completo\n");
        printf("3. Reemplazar valor\n");
        printf("4. Ordenar de mayor a menor\n");
        printf("5. Ordenar de menor a mayor\n");
        printf("6. Calcular mayor y menor\n");
        printf("7. Mostrar una parte\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                cargarVector(vector, 100);
                printf("Vector cargado con valores aleatorios.\n");
                break;
            case 2:
                mostrarVector(vector, 100);
                break;
            case 3:
                printf("Ingrese el valor buscado: ");
                scanf("%d", &valorBuscado);
                printf("Ingrese el nuevo valor: ");
                scanf("%d", &nuevoValor);
                vecesModificado = reemplazarValor(vector, 100, valorBuscado, nuevoValor);
                printf("Se modifico %d veces.\n", vecesModificado);
                break;
            case 4:
                ordenarVector(vector, 100, 1); // Ordenar de mayor a menor
                printf("Vector ordenado de mayor a menor.\n");
                break;
            case 5:
                ordenarVector(vector, 100, 0); // Ordenar de menor a mayor
                printf("Vector ordenado de menor a mayor.\n");
                break;
            case 6:
                calcularMayorMenorFrecuencia(vector, 100, &mayor, &menor, &frecMayor, &frecMenor);
                printf("El valor mayor es %d y aparece %d veces.\n", mayor, frecMayor);
                printf("El valor menor es %d y aparece %d veces.\n", menor, frecMenor);
                break;
            case 7:
                printf("Ingrese la posicion 'desde': ");
                scanf("%d", &desde);
                printf("Ingrese la posicion 'hasta': ");
                scanf("%d", &hasta);
                mostrarParteVector(vector, desde, hasta);
                break;
            case 8:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 8);

    return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 12 (parecido al punto 11)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int leerValor(int, int);
void vectorRandom(int *, int);
void mostrarVec(int, int *);
int reemplazar(int *, int, int, int);
void ordenarVec(int *, int, int);
void calcularMayorMenor(int vec[], int size, int *mayorNum, int *menorNum,
                        int *cantMayorNum, int *cantMenorNum);
void mostrarParteVec(int *, int, int);

int main() {
  int vector[100];
  int opcion;
  int valorBuscado, nuevoValor;
  int vecesModif;
  int mayor, menor, cantMayor, cantMenor;
  int desde, hasta, size;
  bool primero = false;

  size = sizeof(vector) / sizeof(int);

  do {
    printf("\nMenu de opciones:\n");
    printf("\n1. Cargar vector random\n");
    if (!primero) {
      printf("-------------------------------------\n");
      printf("Primero debes ingresar la opcion (1) para que el programa arranque\n");
      printf("-------------------------------------\n\n");
    }
    printf("2. Mostrar vector completo\n");
    printf("3. Reemplazar valor\n");
    printf("4. Ordenar de mayor a menor\n");
    printf("5. Ordenar de menor a mayor\n");
    printf("6. Calcular mayor y menor\n");
    printf("7. Mostrar una parte\n");
    printf("8. Salir\n");
    printf("Seleccione una opcion: \n");
    opcion = leerValor(1, 8);

    switch (opcion) {
    case 1:
      vectorRandom(vector, size);
      printf("Vector cargado con valores aleatorios.\n");
      primero = true;
      break;
    case 2:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }

      mostrarVec(size, vector);
      break;
    case 3:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      printf("Ingrese el valor buscado: ");
      scanf("%d", &valorBuscado);
      printf("Ingrese el nuevo valor: ");
      scanf("%d", &nuevoValor);
      vecesModif = reemplazar(vector, size, valorBuscado, nuevoValor);
      printf("Se modifico %d veces.\n", vecesModif);
      break;
    case 4:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      ordenarVec(vector, size, 1); // Ordenar de mayor a menor
      printf("Vector ordenado de mayor a menor.\n");
      break;
    case 5:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }

      ordenarVec(vector, size, 0); // Ordenar de menor a mayor
      printf("Vector ordenado de menor a mayor.\n");
      break;
    case 6:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }

      calcularMayorMenor(vector, size, &mayor, &menor, &cantMayor,
                         &cantMenor);
      printf("El valor mayor es %d y aparece %d veces.\n", mayor, cantMayor);
      printf("El valor menor es %d y aparece %d veces.\n", menor, cantMenor);
      break;
    case 7:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      printf("Ingrese la posicion 'desde': ");
      scanf("%d", &desde);
      printf("Ingrese la posicion 'hasta': ");
      scanf("%d", &hasta);
      mostrarParteVec(vector, desde, hasta);
      break;
    case 8:
      printf("Saliendo del programa.\n");
      break;
    }
  } while (opcion != 8);

  return 0;
}

int leerValor(int valorMinimo, int valorMaximo) {
  int resultado;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ", valorMinimo, valorMaximo);
  scanf(" %i", &resultado);
  while (resultado < valorMinimo || resultado > valorMaximo) {
    printf("\nFUERA DE RANGO, ingrese nuevamente \n");
    scanf(" %i", &resultado);
  }

  return resultado;
}
// Funcion 1 - Vector random
void vectorRandom(int *vec, int size) {
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    vec[i] = rand() % 1999 - 999;
  }
}
// Funcion 2 - Mostrar vector
void mostrarVec(int size, int *vector) {
  int *puntInicio, *puntFin, *posicion;
  puntInicio = vector;
  puntFin = puntInicio + size;
  posicion = puntInicio;

  while (posicion < puntFin) {
    printf("|  %i ", *posicion);
    posicion++;
  }
}
// Funcion 3 - Reemplazar en el vector
int reemplazar(int vec[], int size, int valorBus, int valorNuevo) {
  int vecesModif = 0;
  for (int i = 0; i < size; i++) {
    if (vec[i] == valorBus) {
      vec[i] = valorNuevo;
      vecesModif++;
    }
  }
  return vecesModif;
}
// Funcion 4/5 - Ordenar de menor a mayor
void ordenarVec(int vec[], int size, int ascendente) {
  int j, tmp;
  for (int i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (ascendente == 0) {
        if (vec[j] > vec[j + 1]) {
          tmp = vec[j];
          vec[j] = vec[j + 1];
          vec[j + 1] = tmp;
        }
      }
      if (ascendente == 1) {
        if (vec[j] < vec[j + 1]) {
          tmp = vec[j];
          vec[j] = vec[j + 1];
          vec[j + 1] = tmp;
        }
      }
    }
  }
}
// Funcion 6 – Calcular mayor y menor
void calcularMayorMenor(int vec[], int size, int *mayorNum, int *menorNum,
                        int *cantMayorNum, int *cantMenorNum) {
  int *puntInicio = vec;
  int *puntFin = puntInicio + size;
  int *posicion = puntInicio;

  *mayorNum = *menorNum = *posicion;
  *cantMayorNum = *cantMenorNum = 1;
  posicion++;

  while (posicion < puntFin) {
    if (*posicion == *mayorNum) {
      (*cantMayorNum)++;
    } else if (*posicion > *mayorNum) {
      *mayorNum = *posicion;
      *cantMayorNum = 1;
    }

    if (*posicion == *menorNum) {
      (*cantMenorNum)++;
    } else if (*posicion < *menorNum) {
      *menorNum = *posicion;
      *cantMenorNum = 1;
    }
    posicion++;
  }
}
// funcion 7 - Mostrar una parte

void mostrarParteVec(int *vec, int desde, int hasta) {

  if (desde >= 0 && desde < 100 && hasta >= 0 && hasta < 100) {
    printf("Elementos desde la posición %i hasta la posición %i:\n", desde,
           hasta);
    for (int *p = vec + desde; p <= vec + hasta; p++) {
      printf("%i\n", *p);
    }
    printf("\n");
  } else {
    printf("Rango de posiciones no válido.\n");
  }
}

/*
void mostrarVectorCompleto(int* refvecPrincipalOriginal,int size)
{
  int* puntInicio,*puntFin,*posicion;
  puntInicio=refvecPrincipalOriginal;
  puntFin=puntInicio+size;
  posicion=puntInicio;

  while (posicion<puntFin)
  {
    printf("|  %i ",*posicion);
    posicion++;
  }
}
*/

#-------------------------------------------------------------------------
#Ejercicio 13

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leerValor(int, int);
void ingresarTxt(char *, int);
void minusculas(char *, bool);
void alReves(char *);
void buscarLetra(char *, char, int *);
void longitud(char *, int *);

int main(void) {
  const int size = 1000;
  char text[size];
  int opcion;
  char *text2;
  char letra;
  int cantidadRepet = 0;
  int longit = 0;
  text2 = text;
  bool primero=false;

  do {
       printf("\n-------------------------------------");
    printf("\nMenu de opciones:\n");
    printf("\n1. Ingresar un texto (min 10 letras)\n");
    if(!primero){
      printf("-------------------------------------\n");
      printf("Primero debes ingresar la opcion (1) para que el programa arranque\n");
    }
    printf("2. Mostrar texto en mayuscula\n");
    printf("3. Mostrar texto en minuscula\n");
    printf("4. Texto dado vuelta\n");
    printf("5. Buscar una letra\n");
    printf("6. largo del texto\n");
    printf("7. Salir\n");
    printf("Seleccione una opcion: \n");
       printf("-------------------------------------\n\n");
    opcion = leerValor(1, 7);

    switch (opcion) {
    case 1:
      ingresarTxt(text, 10);
      primero=true;
      
      break;
      
    case 2:
       if (!primero) {
        printf("\nDebes ingresar la opción 1 antes de esta.\n");
        
        break;
      }
      minusculas(text2, false);
      break;
      
    case 3:
      if (!primero) {
        printf("\nDebes ingresar la opción 1 antes de esta.\n");
        break;
      }
      minusculas(text2, true);
      break;
    case 4:
      if (!primero) {
        printf("\nDebes ingresar la opción 1 antes de esta.\n");
        break;
      }
      alReves(text2);
      break;
    case 5:
      if (!primero) {
        printf("\nDebes ingresar la opción 1 antes de esta.\n");
        break;
      }
      printf("Ingrese la letra que quieres buscar: ");
      getchar();
      scanf("%c", &letra);
      buscarLetra(text2, letra, &cantidadRepet);
      printf(
          "La cantidad de veces que se repetio la letra (%c) fue de %d veces\n",
          letra, cantidadRepet);
      break;
    case 6:
      if (!primero) {
        printf("\nDebes ingresar la opción 1 antes de esta.\n");
        break;
      }
      longitud(text2, &longit);
      printf("La longitud del string es de (%i) caracteres\n", longit);
      break;
    case 7:
      printf("Saliendo del programa.\n");
      break;
    }
  } while (opcion != 7);

  return 0;
}

int leerValor(int valorMinimo, int valorMaximo) {
  int resultado;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ", valorMinimo, valorMaximo);
  scanf(" %i", &resultado);
  while (resultado < valorMinimo || resultado > valorMaximo) {
    printf("\nFUERA DE RANGO, ingrese nuevamente \n");
    scanf(" %i", &resultado);
  }

  return resultado;
}

// funcion 1 - Ingresar un texto
void ingresarTxt(char *text2, int minimo) {
  printf("Ingrese un texto de minimo %i letras: ", minimo);
  while (1) {
    getchar();
    fgets(text2, 1000, stdin);
    text2[strcspn(text2, "\n")] = '\0';
    if (strlen(text2) < minimo) {
      printf("El texto debe tener al menos %d caracteres. Intente nuevamente: ",
             minimo);
    } else {
      break;
    }
  }
}
// funcion 2 y 3 - mayusculas y minusculas (aplicando booleano)
void minusculas(char *text2, bool valor) {
  if (valor == false) {
    while (*text2 != '\0') {
      if (*text2 >= 'a' && *text2 <= 'z') {
        *text2 = *text2 - 32;
      }
      printf("%c", *text2);
      text2++;
    }
  }

  /* if (valor == true) {
     for (int i = 0; i < strlen(text2); i++) {
       if (text2[i] >= 'a' && text2[i] <= 'z') {
         text2[i] = text2[i] - 32;
       }
       printf("%c", text2[i]);
     }
   }
   */
  if (valor == true) {
    while (*text2 != '\0') {
      if (*text2 >= 'A' && *text2 <= 'Z') {
        *text2 = *text2 + 32;
      }
      printf("%c", *text2);
      text2++;
    }
  }
  
}
/* for (int i = 0; i < strlen(text2); i++) {
   if (text2[i] >= 'A' && text2[i] <= 'Z') {
     text2[i] = text2[i] + 32;
   }
   printf("%c", text2[i]);
 }
}
}
*/
// funcion 4 - texto dado vuelta
void alReves(char *text2) {
  char *text3 = text2;
  printf("Copia del original al reves:\n");
  /* for (int i = strlen(text3)-1; i >= 0; i--) {
     printf("%c", text3[i]);
   }
   */
  while (*text3 != '\0') {
    text3++;
  }
  text3--;
  while (text3 >= text2) {
    printf("%c", *text3);
    text3--;
  }
  
  printf("\nTexto original:\n");
  while (*text2 != '\0') {
    printf("%c", *text2);
    text2++;
  }
}
// funcion 5 - buscar letra
void buscarLetra(char *text2, char letra, int *cantidadRepet) {
  *cantidadRepet = 0;

  while (*text2 != '\0') {
    if (*text2 == letra || tolower(*text2) == tolower(letra)) {
      (*cantidadRepet)++;
    }
    text2++;
  }
}

// funcion 6 - largo del texto
void longitud(char *text2, int *longit) {
  *longit = 0;
  while (*text2 != '\0') {
    (*longit)++;
    text2++;
  }
}

#-------------------------------------------------------------------------
#Ejercicio 14 (struct)

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Materia {
  char nombre[50];
  int año;
} Materia;

typedef struct Nota {
  int valor;
  char obs[50];
  Materia mat;
} Nota;

typedef struct Alumno {
  int legajo;
  char nombre[50];
  char apellido[50];
  Nota notas[3];
} Alumno;

//------------------------
int leerValor(int, int);
void NuevoAlumno(Alumno *, Materia *);
void MostrarAlumno(Alumno);
float CalcularPromedio(Alumno);
void MostrarMaterias(Materia *);
void BuscarAlumno(Alumno *, int);
void AlumnosApro(Alumno *, int);
void mejorPromedio(Alumno *, int);
//------------------------

int main() {
  int opcion;
  bool primero = false;
  //------------------------
  int nuevoAlumno = 0;
  Alumno kids[10];
  Materia mats[10];
  int i;
  //------------------------
  strcpy(mats[0].nombre, "Matematica 1");
  mats[0].año = 1;

  strcpy(mats[1].nombre, "Lengua 1");
  mats[1].año = 1;

  strcpy(mats[2].nombre, "Programacion 2");
  mats[2].año = 2;
  //-----------------------
  do {
    printf("\nMenu de opciones:\n");
    printf("1. Dar de alta alumno.\n");
    if (!primero) {
      printf("-------------------------------------\n");
      printf("Primero debes ingresar la opcion (1) para que el programa "
             "arranque\n");
      printf("-------------------------------------\n\n");
    }
    printf("2. Buscar alumno.\n");
    printf("3. Mostrar todos los datos con el promedio de cada alumno.\n");
    printf("4. Mostrar alumnos aprobados (+4).\n");
    printf("5. Mejor promedio\n");
    printf("6. Salir\n");

    printf("Seleccione una opcion: \n");
    opcion = leerValor(1, 6);

    switch (opcion) {
    case 1:
      /* for (i = 0; i < 3; i++) {
         printf("\nAlumno n°%i\n", i + 1);
         printf("-------------\n");*/
      MostrarMaterias(mats);
      NuevoAlumno(&kids[nuevoAlumno], mats);
      nuevoAlumno++;
      primero = true;
      break;
    case 2:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      BuscarAlumno(kids, nuevoAlumno);
      break;
    case 3:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");

        break;
      }
      for (i = 0; i < nuevoAlumno; i++) {
        MostrarAlumno(kids[i]);
      }
      break;
    case 4:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      AlumnosApro(kids, nuevoAlumno);
      break;
    case 5:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      mejorPromedio(kids, nuevoAlumno);
      break;
    case 6:
      printf("Saliendo del programa.\n");
      break;
    }
  } while (opcion != 6);

  return 0;
}

int leerValor(int valorMinimo, int valorMaximo) {
  int resultado;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ", valorMinimo, valorMaximo);
  scanf(" %i", &resultado);
  while (resultado < valorMinimo || resultado > valorMaximo) {
    printf("\nFUERA DE RANGO, ingrese nuevamente \n");
    scanf(" %i", &resultado);
  }
  return resultado;
}

// FUNCIÓN 1 - Dar de alta
void NuevoAlumno(Alumno *alu, Materia *mats) {
  printf("\n-- Materias disponibles: -- \n");
  printf("\nIngrese el legajo: ");
  scanf("%i", &alu->legajo); /*el operador -> nos permite acceder al puntero alu
                                directo a su contenido para poder entrar a la
                                variable, otra forma es: (*alu).legajo   */
  while (getchar() != '\n')
    ;
  printf("\nIngrese el nombre: ");
  fgets(alu->nombre, sizeof(alu->nombre), stdin);
  strtok(alu->nombre, "\n");
  //  while (getchar() != '\n');
  printf("\nIngrese el apellido: ");
  fgets(alu->apellido, sizeof(alu->apellido), stdin);
  strtok(alu->nombre, "\n");
  //   while (getchar() != '\n');
  printf("Ingrese las 3 notas:\n");
  for (int i = 0; i < 3; i++) {
    printf("\nNota %i: ", i + 1);
    scanf(" %i", &alu->notas[i].valor);
    while (getchar() != '\n')
      ;
    printf("\nObservaciones a esa nota: ");
    fgets(alu->notas[i].obs, sizeof(alu->notas[i].obs), stdin);
    //   while (getchar() != '\n');
    while (getchar() != '\n') {
      printf("\nMateria de esa nota: (1 - 2 - 3): ");
      int numMat;
      scanf("%i", &numMat);
      if (numMat < 0 || numMat > 3) {
        printf("Valor no válido. (1 - 2 - 3):\n");
      } else {
        alu->notas[i].mat = mats[numMat - 1];
        break;
      }
    }
  }
}
// FUNCIÓN 2 - Buscar alumno
void BuscarAlumno(Alumno *alus, int size) {
  int valor;
  printf("\nIngrese el legajo que desea buscar: ");
  scanf("%i", &valor);
  int cant = 0;
  for (int i = 0; i < size; i++) {
    if (alus[i].legajo == valor) {
      cant++;
      MostrarAlumno(alus[i]);
    }
  }
  if (cant == 0)
    printf("\nAlumno no encontrado");
}
// FUNCIÓN 3 - Mostrar alumnos
void MostrarAlumno(Alumno alu) {
  printf("\n--------------------------------------------\n");
  printf("%i | %s %s |\n", alu.legajo, alu.nombre,
         alu.apellido); /*con el punto puedo identificar la variable a utilizar
                           de la estructura*/
  printf("Notas: \n");
  for (int i = 0; i < 3; i++) {
    printf("Materia: %s | Nota %i: %i | Observaciones: %s\n",
           alu.notas[i].mat.nombre, i + 1, alu.notas[i].valor,
           alu.notas[i].obs);
  }
  printf("Promedio general: %f", CalcularPromedio(alu));
}
float CalcularPromedio(Alumno a) {
  float prom = 0;
  for (int i = 0; i < 3; i++) {
    prom += a.notas[i].valor;
  }
  prom = prom / 3;

  return prom;
}
void MostrarMaterias(Materia *mats) {
  printf("\n-- Materias disponibles: -- \n");
  for (int i = 0; i < 3; i++) {
    printf("%i - %s (%i)\n", i + 1, mats[i].nombre, mats[i].año);
  }
}
// FUNCIÓN 4 - Alumnos aprobados
void AlumnosApro(Alumno *alus, int size) {
  int i;
  float promedio;
  for (int i = 0; i < size; i++) {
    promedio = CalcularPromedio(alus[i]);
    if (promedio >= 4.0) {
      MostrarAlumno(alus[i]);
    }
  }
}
// FUNCIÓN 5 - Mejor promedio
void mejorPromedio(Alumno *alu, int size) {
  int i;
  float mejorPromedio = 0;
  for (i = 0; i < size; i++) {
    float promedio = CalcularPromedio(alu[i]);
    if (promedio > mejorPromedio) {
      mejorPromedio = promedio;
    }
  }
  printf("El mejor promedio es %f\n", mejorPromedio);
}

#-------------------------------------------------------------------------
#Ejercicio 15

#include <stdio.h>
#include <string.h>

typedef struct Materia
{
  char nombre[50];
  int año;
} Materia;

typedef struct Nota
{
  int valor;
  char obs[50];
  Materia mat;
}Nota;

typedef struct Alumno {
  int legajo;
  char nombre[50];
  char apellido[50];
  Nota notas[3];
}Alumno;

void NuevoAlumno(Alumno *, Materia *);
void MostrarAlumno(Alumno);
float CalcularPromedio(Alumno);
Alumno MejorAlumno( Alumno *);
void MostrarMaterias(Materia* );

int main(void) {
  Alumno vecAlumnos[100]; /*declaramos un vector usando el tipo de datos
                                    struct Alumno*/
  Materia vecMaterias[10];

  strcpy(vecMaterias[0].nombre, "Matematica 1");
  vecMaterias[0].año = 1;
  
  strcpy(vecMaterias[1].nombre, "Lengua 1");
  vecMaterias[1].año = 1;
  
  strcpy(vecMaterias[2].nombre, "Programacion 2");
  vecMaterias[2].año = 2;
  
  int i;
  /*Vamos a cargar 3 alumnos para el ejemplo*/
  for (i = 0; i < 3; i++) {
    printf("\nAlumno n°%i\n", i);
    printf("-------------\n");
   MostrarMaterias(vecMaterias);
    NuevoAlumno(&vecAlumnos[i], vecMaterias);
  }
  printf("\nLos alumnos cargados fueron: \n");
  printf("-------------------------------\n");

  for (i = 0; i < 3; i++) {
    MostrarAlumno(vecAlumnos[i]);
  }
  //getchar();

  printf("\nEl mejor alumno es:\n");
  MostrarAlumno(MejorAlumno(vecAlumnos)); 

  
  return 0;

  
}

void NuevoAlumno(Alumno *alu, Materia* mats) {
  printf("\nIngrese el legajo: ");
  scanf("%i", &alu->legajo); /*el operador -> nos permite acceder al puntero alu
                                directo a su contenido para poder entrar a la
                                variable, otra forma es: (*alu).legajo   */

  getchar();
  printf("\nIngrese el nombre: ");
  gets(alu->nombre);
  printf("\nIngrese el apellido: ");
  gets(alu->apellido);

  printf("Ingrese las 3 notas:\n");

  for(int i = 0; i <3; i++)
    {
      printf("\nNota %i: ", i+1);
      scanf(" %i", &alu->notas[i].valor);
      while(getchar() != '\n');
      printf("Observaciones a esa nota: ");
      gets(alu->notas[i].obs);
      printf("Materia de esa nota: (0 - 1 - 2): ");
      int numMat;
      scanf("%i", &numMat);
      alu->notas[i].mat = mats[numMat];
    }
}

void MostrarAlumno(Alumno alu) {
  printf("\n--------------------------------------------\n");
  printf("%i | %s %s | Promedio:\n", alu.legajo, alu.nombre,
         alu.apellido); /*con el punto puedo identificar la variable a utilizar
                           de la estructura*/
  printf("Notas: \n");
  for(int i=0; i < 3; i++)
    {
      printf("Materia: %s | Nota %i: %i | Observaciones: %s\n", alu.notas[i].mat.nombre,i+1, alu.notas[i].valor, alu.notas[i].obs);
    }
printf("Promedio general: %f", CalcularPromedio(alu));
}

float CalcularPromedio( Alumno a)
{
  float prom=0;
  for(int i=0;i<3;i++)
    {
      prom+=a.notas[i].valor;
    }
  prom=prom/3;

  return prom;
}

Alumno MejorAlumno( Alumno* alus)
{
   Alumno mejor = alus[0];

  for(int i = 0; i<3; i++)
    {
      if(CalcularPromedio(mejor) < CalcularPromedio(alus[i]))
      {
        mejor = alus[i];
      }
      
    }
  
  return mejor;
}

void MostrarMaterias(Materia* mats)
{
  printf("\n-- Materias disponibles: -- \n");
  for(int i=0; i<3; i++)
    {
      printf("%i - %s (%i)\n", i, mats[i].nombre, mats[i].año );
    }
}

#-------------------------------------------------------------------------
#Ejercicio 16

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Materia {
  char nombre[50];
  int año;
} Materia;

typedef struct Nota {
  int valor;
  char obs[50];
  Materia mat;
} Nota;

typedef struct Alumno {
  int legajo;
  char nombre[50];
  char apellido[50];
  Nota notas[3];
} Alumno;

typedef struct Nodo {
  struct Alumno datos;
  struct Nodo *sig;
} Nodo;

//------------------------
int leerValor(int, int);
Nodo nodoNuevo(Alumno *, Materia *);
void MostrarAlumno(Alumno);
float CalcularPromedio(Alumno);
void MostrarMaterias(Materia *);
void BuscarAlumno(Alumno *, int);
void AlumnosApro(Alumno *, int);
void mejorPromedio(Alumno *, int);
//------------------------

int main() {
  int opcion;
  bool primero = false;
  //------------------------
  int nuevoAlumno = 0;
  Alumno kids[10];
  Materia mats[10];
  int i;
  //------------------------
  strcpy(mats[0].nombre, "Matematica 1");
  mats[0].año = 1;

  strcpy(mats[1].nombre, "Lengua 1");
  mats[1].año = 1;

  strcpy(mats[2].nombre, "Programacion 2");
  mats[2].año = 2;
  //-----------------------
  do {
    printf("\nMenu de opciones:\n");
    printf("1. Dar de alta alumno.\n");
    if (!primero) {
      printf("-------------------------------------\n");
      printf("Primero debes ingresar la opcion (1) para que el programa "
             "arranque\n");
      printf("-------------------------------------\n\n");
    }
    printf("2. Buscar alumno.\n");
    printf("3. Mostrar todos los datos con el promedio de cada alumno.\n");
    printf("4. Mostrar alumnos aprobados (+4).\n");
    printf("5. Mejor promedio\n");
    printf("6. Salir\n");

    printf("Seleccione una opcion: \n");
    opcion = leerValor(1, 6);

    switch (opcion) {
    case 1:
      /* for (i = 0; i < 3; i++) {
         printf("\nAlumno n°%i\n", i + 1);
         printf("-------------\n");*/
      MostrarMaterias(mats);
      nodoNuevo(&kids[nuevoAlumno], mats);
      nuevoAlumno++;

      primero = true;
      break;
    case 2:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      BuscarAlumno(kids, nuevoAlumno);
      break;
    case 3:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");

        break;
      }
      for (i = 0; i < nuevoAlumno; i++) {
        MostrarAlumno(kids[i]);
      }
      break;
    case 4:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      AlumnosApro(kids, nuevoAlumno);
      break;
    case 5:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      mejorPromedio(kids, nuevoAlumno);
      break;
    case 6:
      printf("Saliendo del programa.\n");
      break;
    }
  } while (opcion != 6);

  return 0;
}

int leerValor(int valorMinimo, int valorMaximo) {
  int resultado;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ", valorMinimo, valorMaximo);
  scanf(" %i", &resultado);
  while (resultado < valorMinimo || resultado > valorMaximo) {
    printf("\nFUERA DE RANGO, ingrese nuevamente \n");
    scanf(" %i", &resultado);
  }
  return resultado;
}

// FUNCIÓN 1 - Dar de alta
Nodo nodoNuevo(Alumno *alu, Materia *mats) {

Nodo *nuevoNodo =(Nodo *)malloc(sizeof(Nodo));
nuevoNodo->sig=NULL;

  
  printf("\n-- Materias disponibles: -- \n");
  printf("\nIngrese el legajo: ");
  scanf("%i", &alu->legajo); /*el operador -> nos permite acceder al puntero alu
                                directo a su contenido para poder entrar a la
                                variable, otra forma es: (*alu).legajo   */
  while (getchar() != '\n')
    ;
  printf("\nIngrese el nombre: ");
  fgets(alu->nombre, sizeof(alu->nombre), stdin);
  strtok(alu->nombre, "\n");
  //  while (getchar() != '\n');
  printf("\nIngrese el apellido: ");
  fgets(alu->apellido, sizeof(alu->apellido), stdin);
  strtok(alu->nombre, "\n");
  //   while (getchar() != '\n');
  printf("Ingrese las 3 notas:\n");
  for (int i = 0; i < 3; i++) {
    printf("\nNota %i: ", i + 1);
    scanf(" %i", &alu->notas[i].valor);
    while (getchar() != '\n')
      ;
    printf("\nObservaciones a esa nota: ");
    fgets(alu->notas[i].obs, sizeof(alu->notas[i].obs), stdin);
    //   while (getchar() != '\n');
    while (getchar() != '\n') {
      printf("\nMateria de esa nota: (1 - 2 - 3): ");
      int numMat;
      scanf("%i", &numMat);
      if (numMat < 0 || numMat > 3) {
        printf("Valor no válido. (1 - 2 - 3):\n");
      } else {
        alu->notas[i].mat = mats[numMat - 1];
        break;
      }
    }
  }
  printf("Nodo cargado");
  return *nuevoNodo;
}
// FUNCIÓN 2 - Buscar alumno
void BuscarAlumno(Alumno *alus, int size) {
  int valor;
  printf("\nIngrese el legajo que desea buscar: ");
  scanf("%i", &valor);
  int cant = 0;
  for (int i = 0; i < size; i++) {
    if (alus[i].legajo == valor) {
      cant++;
      MostrarAlumno(alus[i]);
    }
  }
  if (cant == 0)
    printf("\nAlumno no encontrado");
}
// FUNCIÓN 3 - Mostrar alumnos
void MostrarAlumno(Alumno alu) {
  
  printf("\n--------------------------------------------\n");
  printf("%i | %s %s |\n", alu.legajo, alu.nombre,
         alu.apellido); /*con el punto puedo identificar la variable a utilizar
                           de la estructura*/
  printf("Notas: \n");
  for (int i = 0; i < 3; i++) {
    printf("Materia: %s | Nota %i: %i | Observaciones: %s\n",
           alu.notas[i].mat.nombre, i + 1, alu.notas[i].valor,
           alu.notas[i].obs);
  }
  printf("Promedio general: %f", CalcularPromedio(alu));
}
float CalcularPromedio(Alumno a) {
  float prom = 0;
  for (int i = 0; i < 3; i++) {
    prom += a.notas[i].valor;
  }
  prom = prom / 3;

  return prom;
}
void MostrarMaterias(Materia *mats) {
  printf("\n-- Materias disponibles: -- \n");
  for (int i = 0; i < 3; i++) {
    printf("%i - %s (%i)\n", i + 1, mats[i].nombre, mats[i].año);
  }
}
// FUNCIÓN 4 - Alumnos aprobados
void AlumnosApro(Alumno *alus, int size) {
  int i;
  float promedio;
  for (int i = 0; i < size; i++) {
    promedio = CalcularPromedio(alus[i]);
    if (promedio >= 4.0) {
      MostrarAlumno(alus[i]);
    }
  }
}
// FUNCIÓN 5 - Mejor promedio
void mejorPromedio(Alumno *alu, int size) {
  int i;
  float mejorPromedio = 0;
  for (i = 0; i < size; i++) {
    float promedio = CalcularPromedio(alu[i]);
    if (promedio > mejorPromedio) {
      mejorPromedio = promedio;
    }
  }
  printf("El mejor promedio es %f\n", mejorPromedio);
}


#-------------------------------------------------------------------------
#Ejercicio 17

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------
typedef struct Materia {
  char nombre[50];
  int año;
} Materia;

typedef struct Nota {
  int valor;
  char obs[50];
  Materia mat;
} Nota;
typedef struct Alumno {
  int legajo;
  char apyn[100];
  Nota notas[3];
} Alumno;

typedef struct Nodo {
  struct Alumno datos;
  struct Nodo *sig;
} Nodo;

//-------------------
int leerValor(int, int);
struct Nodo *nuevoNodo();
void mostrarLista(Nodo *);
struct Nodo *agregar(Nodo *, Alumno);
Nodo *NuevoAlumno(Materia *, Nodo *);
void MostrarAlumno(Alumno);
float CalcularPromedio(Alumno);
void MostrarMaterias(Materia *);
void BuscarAlumno(Nodo *, int);
void buscarAprobados(Nodo *);
Nodo* eliminar(Nodo*, int);
//-------------------
int main(void) {
  Nodo *pIni;
  pIni = NULL;
  Alumno alu;
  Materia mats[10];
  int i = 0;
  int opcion;
  bool primero = false;
  int nuevoAlumno = 0;
  int valor;

  //------------------------
  /*int nuevoAlumno = 0;
  Nodo *kids = NULL;
  // Alumno kids[10];
  Materia mats[10];
  int i = 0;*/
  //------------------------
  strcpy(mats[0].nombre, "Matematica 1");
  mats[0].año = 1;

  strcpy(mats[1].nombre, "Lengua 1");
  mats[1].año = 1;

  strcpy(mats[2].nombre, "Programacion 2");
  mats[2].año = 2;
  //-----------------------
  do {

    printf("\nMenu de opciones:\n");
    printf("1. Dar de alta alumno.\n");
    if (!primero) {
      printf("-------------------------------------\n");
      printf("Primero debes ingresar la opcion (1) para que el programa "
             "arranque\n");
      printf("-------------------------------------\n\n");
    }
    printf("2. Buscar alumno.\n");
    printf("3. Mostrar todos los datos con el promedio de cada alumno.\n");
    printf("4. Mostrar alumnos aprobados (+7).\n");
    printf("5.Eliminar alumno\n");
    printf("6. Salir\n");

    printf("Seleccione una opcion: \n");
    opcion = leerValor(1, 6);

    switch (opcion) {
    case 1:
      MostrarMaterias(mats);
      pIni = NuevoAlumno(mats, pIni);
      primero = true;
      break;

    case 2:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }

      printf("\nIngrese el legajo que desea buscar: ");
      scanf("%i", &valor);
      BuscarAlumno(pIni, valor);
      break;
    case 3:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      mostrarLista(pIni);
      break;
    case 4:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      buscarAprobados(pIni);
      break;
    case 5:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      printf("\nIngrese el legajo que desea eliminar: ");
      scanf("%i", &valor);
      pIni=eliminar( pIni, valor);
      break;
    case 6:
      printf("Saliendo del programa.\n");
      break;
    }
  } while (opcion != 6);

  return 0;
}

int leerValor(int valorMinimo, int valorMaximo) {
  int resultado;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ", valorMinimo, valorMaximo);
  scanf(" %i", &resultado);
  while (resultado < valorMinimo || resultado > valorMaximo) {
    printf("\nFUERA DE RANGO, ingrese nuevamente \n");
    scanf(" %i", &resultado);
  }
  return resultado;
}

// Función 1 - Nuevo nodo
Nodo *nuevoNodo() {
  Nodo *p;
  p = (Nodo *)malloc(sizeof(Nodo));
  p->sig = NULL;
  return p;
}
// Función 2 - mostrar nodos
void mostrarLista(Nodo *lista) {
  Nodo *p;
  p = lista;
  while (p != NULL) {
    MostrarAlumno(p->datos);
    // printf("%i - %s\n", p->datos.legajo, p->datos.apyn);
    p = p->sig; /*paso al siguiente nodo*/
  }
}
// Función 3 - agregar nodos
Nodo *agregar(Nodo *pIni, Alumno alu) {
  Nodo *p = pIni;
  if (p == NULL) // es el primero que se inserta
  {
    p = nuevoNodo();
    p->datos = alu;
    return p;
  }
  // Si no era el único debemos avanzar hasta el último nodo
  while (p->sig != NULL) {
    p = p->sig;
  }
  /*ahora que ya estamos en el último (es p en este momento), agregamos el
   * nuevo nodo*/
  Nodo *nuevo = nuevoNodo();
  p->sig = nuevo;
  nuevo->datos = alu;
  return pIni;
}
void BuscarAlumno(Nodo *pIni, int valor) {
  Nodo *p;
  p = pIni;
  int cant = 0;
  while (p != NULL) {
    if (p->datos.legajo == valor) {
      cant++;
      MostrarAlumno(p->datos);
    }
    p = p->sig;
  }
  if (cant == 0) {
    printf("\nAlumno no encontrado");
  }
}
// FUNCIÓN 3 - Mostrar alumnos
void MostrarAlumno(Alumno alu) {
  printf("\n--------------------------------------------\n");
  printf("%i | %s  |\n", alu.legajo, alu.apyn); /*con el punto puedo identificar
                           la variable a utilizar de la estructura*/
  printf("Notas: \n");
  for (int i = 0; i < 3; i++) {
    printf("Materia: %s | Nota %i: %i | Observaciones: %s\n",
           alu.notas[i].mat.nombre, i + 1, alu.notas[i].valor,
           alu.notas[i].obs);
  }
  printf("Promedio general: %f", CalcularPromedio(alu));
}
float CalcularPromedio(Alumno a) {
  float prom = 0;
  for (int i = 0; i < 3; i++) {
    prom += a.notas[i].valor;
  }
  prom = prom / 3;

  return prom;
}
Nodo *NuevoAlumno(Materia *mats, Nodo *pIni) {
  Alumno alu;
  printf("Ingrese un número de legajo: ");
  scanf("%i", &alu.legajo);
  printf("Ingrese el nombre y apellido del alumno: ");
  getchar();
  fgets(alu.apyn, sizeof(alu.apyn), stdin);
  strtok(alu.apyn, "\n");
  printf("Ingrese las 3 notas:\n");
  for (int i = 0; i < 3; i++) {
    printf("\nNota %i: ", i + 1);
    scanf("%i", &alu.notas[i].valor);
    while (getchar() != '\n') {
    }
    printf("\nObservaciones a esa nota: ");
    fgets(alu.notas[i].obs, sizeof(alu.notas[i].obs), stdin);
    strtok(alu.notas[i].obs, "\n");
    int numMat;
    do {
      printf("\nMateria de esa nota (1 - 2 - 3): ");
      scanf("%i", &numMat);
      while (getchar() != '\n') {
      }
      if (numMat < 1 || numMat > 3) {
        printf("Valor no válido. (1 - 2 - 3):\n");
      }
    } while (numMat < 1 || numMat > 3);

    alu.notas[i].mat = mats[numMat - 1];
  }
  pIni = agregar(pIni, alu);
  return pIni;
}

void MostrarMaterias(Materia *mats) {
  printf("\n-- Materias disponibles: -- \n");
  for (int i = 0; i < 3; i++) {
    printf("%i - %s (%i)\n", i + 1, mats[i].nombre, mats[i].año);
  }
}
void buscarAprobados(Nodo *pIni) {
  Nodo *p;
  p = pIni;
  printf("\nLos alumnos aprobados son:\n");

  while (p != NULL) {
    if (CalcularPromedio(p->datos) >= 7.0) {
      MostrarAlumno(p->datos);
    }
    p = p->sig;
  }
}

Nodo* eliminar(struct Nodo* pIni, int legajo)
{
  
 Nodo* actual = pIni;
 Nodo* anterior = NULL;
if(actual == NULL) //lista vacia
{
printf("No hay datos en la lista\n");
return actual;
}
if(actual->datos.legajo == legajo) //es el primero de la lista
{
pIni = pIni->sig;
free(actual);
printf("Eliminado correctamente\n");
return pIni;
}
while(actual != NULL)
{
if(actual->datos.legajo == legajo)

{
anterior->sig = actual->sig;
free(actual);
printf("Eliminado correctamente\n");
return pIni;
}
anterior = actual;
actual = actual->sig;
}
printf("No se encontró el legajo\n");
return pIni;
}

#-------------------------------------------------------------------------
#Ejercicio 18

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------------

typedef struct pelicula {
  int codigo;
  char nombre[100];
  char descripcion[100];
  int duracion;
} pelicula;

typedef struct Nodo {
  struct pelicula datos;
  struct Nodo *sig;
} Nodo;

//------------------------
int leerValor(int, int);
struct Nodo *nuevoNodo();
void mostrarLista(Nodo *);
Nodo *agregar(Nodo *, pelicula);
Nodo *nuevaPeli(Nodo *);
void mostrarCatalogo(pelicula);
void peliculaTime(Nodo *, int);
Nodo *eliminar(struct Nodo *, int);
//------------------------
int main(void) {
  Nodo *pIni;
  pIni = NULL;
  pelicula peli;
  int i = 0;
  int opcion;
  bool primero = false;
  int nuevoAlumno = 0;
  int time;
  int cod;
  //------------------------

  do {

    printf("\nMenu de opciones:\n");
    printf("1. Agregar pelicula.\n");
    if (!primero) {
      printf("-------------------------------------\n");
      printf("Primero debes ingresar la opcion (1) para que el programa "
             "arranque\n");
      printf("-------------------------------------\n\n");
    }
    printf("2. Mostrar todas las peliculas.\n");
    printf("3. Mostrar todas las peliculas con una duracion maxima.\n");
    printf("4. Eliminar una pelicula.\n");
    printf("5. Salir\n");

    printf("Seleccione una opcion: \n");
    opcion = leerValor(1, 5);

    switch (opcion) {
    case 1:
      pIni = nuevaPeli(pIni);
      primero = true;
      break;

    case 2:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      mostrarLista(pIni);
      break;
    case 3:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      printf("Ingrese el tiempo max de duracion de la pelicula: ");
      scanf("%i", &time);
     peliculaTime(pIni, time);
      break;
    case 4:
      if (!primero) {
        printf("Debes ingresar la opción 1 antes de esta.\n");
        break;
      }
      printf("\nIngrese el codigo de la pelicula que desea eliminar: ");
      scanf("%i", &cod);
      pIni = eliminar(pIni, cod);
      break;
    case 5:
      printf("Saliendo del programa.\n");
      break;
    }
  } while (opcion != 5);

  return 0;
}

int leerValor(int valorMinimo, int valorMaximo) {
  int resultado;
  printf("\nINGRESE UN NUMERO ENTRE %i y %i: ", valorMinimo, valorMaximo);
  scanf(" %i", &resultado);
  while (resultado < valorMinimo || resultado > valorMaximo) {
    printf("\nFUERA DE RANGO, ingrese nuevamente \n");
    scanf(" %i", &resultado);
  }
  return resultado;
}

//----------------- Funciones Nodos -----------

// Función 1 - Nuevo nodo
Nodo *nuevoNodo() {
  Nodo *p;
  p = (Nodo *)malloc(sizeof(Nodo));
  p->sig = NULL;
  return p;
}
// Función 2 - mostrar nodos
void mostrarLista(Nodo *lista) {
  Nodo *p;
  p = lista;
  while (p != NULL) {
    mostrarCatalogo(p->datos);
    // printf("%i - %s\n", p->datos.legajo, p->datos.apyn);
    p = p->sig; /*paso al siguiente nodo*/
  }
}
// Función 3 - agregar nodos
Nodo *agregar(Nodo *pIni, pelicula peli) {
  Nodo *p = pIni;
  if (p == NULL) // es el primero que se inserta
  {
    p = nuevoNodo();
    p->datos = peli;
    return p;
  }
  // Si no era el único debemos avanzar hasta el último nodo
  while (p->sig != NULL) {
    p = p->sig;
  }
  /*ahora que ya estamos en el último (es p en este momento), agregamos el
   * nuevo nodo*/
  Nodo *nuevo = nuevoNodo();
  p->sig = nuevo;
  nuevo->datos = peli;
  return pIni;
}

//----------------- Funciones Pelicula -----------

// Funcion 1 - Nueva pelicula
Nodo *nuevaPeli(Nodo *pIni) {
  pelicula peli;
  printf("\nIngrese el codigo de la pelicula: ");
  scanf("%i", &peli.codigo);
  printf("\nIngrese el nombre de la pelicula: ");
  getchar();
  fgets(peli.nombre, sizeof(peli.nombre), stdin);
  strtok(peli.nombre, "\n");
  printf("\nIngrese una descripcion de la pelicula: ");
  fgets(peli.descripcion, sizeof(peli.descripcion), stdin);
  printf("\nIngrese la duracion de la pelicula: ");
  scanf("%i", &peli.duracion);
  pIni = agregar(pIni, peli);
  return pIni;
}

// FUNCIÓN 2 - Mostrar peliculas
void mostrarCatalogo(pelicula peli) {
  printf("\n--------------------------------------------\n");
  printf("%i | %s  |\n", peli.codigo, peli.nombre); /*con el punto puedo
                           identificar la variable a utilizar de la estructura*/
  printf("Descripcion: ");
  printf("%s", peli.descripcion);
  printf("\nLa duracion de la pelicula es de %i minutos \n", peli.duracion);
}

// Funcion 3 - Buscar pelicula por tiempo
void peliculaTime(Nodo *pIni, int time) {
  Nodo *p;
  p = pIni;
  int cant = 0;
  while(p!=NULL){
  if (p->datos.duracion <= time) {
    mostrarCatalogo(p->datos);
    cant++;
  }
     p = p->sig;
  }
  if (cant == 0) {
    printf("No hay peliculas con duracion menor a %i", time);
  }
}

// Función 4 - Eliminar pelicula
Nodo *eliminar(struct Nodo *pIni, int codigo) {
  Nodo *actual = pIni;
  Nodo *anterior = NULL;
  if (actual == NULL) // lista vacia
  {
    printf("No hay datos en la lista\n");
    return actual;
  }
  if (actual->datos.codigo == codigo) // es el primero de la lista
  {
    pIni = pIni->sig;
    free(actual);
    printf("Eliminado correctamente\n");
    return pIni;
  }
  while (actual != NULL) {
    if (actual->datos.codigo == codigo) {
      anterior->sig = actual->sig;
      free(actual);
      printf("Eliminado correctamente\n");
      return pIni;
    }
    anterior = actual;
    actual = actual->sig;
  }
  printf("No se encontró el codigo\n");
  return pIni;
}

#-------------------------------------------------------------------------
#Ejercicio 19

#include <stdio.h>

/*A. Crear una función “puntoA” que reciba un vector tipo int largo 100 y otro valor int llamado
“mayor”. La función debe mostrar por pantalla todos los números del vector cuyo valor sea
mayor o igual al valor enviado que se llama “mayor” y debe retornar la suma de todos los
valores mostrados. Mostrar por pantalla el valor retornado desde main.*/

int puntoA(int[], int);
int main(void) {

int vec[100];
int mayor=0;
  int i;
  printf("ingrese 10 numeros: ");
  for(i=0; i<10; i++){
    scanf("%i",&vec[i]);
  }
  printf("ingrese un numero mayor");
  scanf("%i",&mayor);
int x = puntoA(vec, mayor);
  printf("la suma es de: %i",x);
  return 0;
}

int puntoA(int vec[], int mayor){

  int i;
  int suma=0;
  
  for(i=0;i<10;i++){
    if(vec[i]>=mayor){
      printf("%i \n",vec[i]);
      suma+=vec[i];
  }
  }
    return suma;
  }
  
#-------------------------------------------------------------------------
#Ejercicio 20

#include <stdio.h>
/*Crear una función que reciba una un vector tipo int largo 1000 y debe guardar en 3 variables
utilizando punteros por referencia:
• En el primero la suma de todos los números en posiciones par del vector
• En el segundo el promedio total del vector
• En el tercero la cantidad de veces que se encuentra el valor cero como dato en el vector*/

void funcion(int *, int *, float *, int *);

int main(void) {

  int vector[10];
  int suma, cantidad;
  float promedio;
  printf("Ingrese 10 numeros: \n");
  for(int i = 0; i < 10; i++){
    scanf("%d\n", &vector[i]);
  }
  funcion(vector,&suma, &promedio,&cantidad);
  
  return 0;
}

void funcion(int *vector, int *s, float *p, int *c){
  *s = 0;
  *p = 0;
  *c = 0;

  for(int i = 0; i < 10; i++){
    if(vector[i] % 2 == 0){
      *s = *s + vector[i];
    }
  }
  printf("La suma de los pares es de: %i \n", *s);
  *p = *s / 10;
  printf("El promedio de las sumas de los pares es de: %f\n", *p);
  for(int i = 0; i < 10; i++){
    if(vector[i] == 0){
      *c = *c + 1;
    }
  }
  printf("%i", *c);
}
  
#-------------------------------------------------------------------------
#Ejercicio 21

#include <stdio.h>
/*Crear una función “puntoC” que reciba un vector tipo int largo 100 y otro valor int llamado
  “buscado”. La función debe mostrar por pantalla las posiciones donde se encuentra el valor
  buscado y debe retornar la cantidad de veces que fue encontrado. Agregar el código que usa la
  función desde main (un ejemplo completo que la use y muestre los valores obtenidos).*/

int puntoC(int[] ,int , int);
int main(void) {

 const int  size=10;
int vec[size];
int buscando=0;
  
printf("ingrese 10 numeros :");
  for(int i=0;i<size;i++){
  scanf("%i",&vec[i]);
  }
  printf("ingrese un numero a buscar: ");
  scanf("%i",&buscando);
 int x = puntoC( vec, size, buscando);
printf("la cantidad de veces que se hayo el numero en el vector fue de %i \n",x);
  return 0;
}
int puntoC(int vec[],int size, int buscando){
int cant=0;
for(int i=0;i<size;i++){
  if(vec[i]==buscando){
  cant++;
    printf("\nel valor buscado se encuentra en la posicion %i\n",i);
  }
}
  return cant;
}

#-------------------------------------------------------------------------
#Ejercicio 22

#include <stdio.h>

/*
Crear una función que reciba 2 parámetros llamados primero y segundo. Segundo
debe ir como referencia usando punteros y la función debe retornar la suma de
ambos y dejar el valor más grande los dos guardado en “segundo”. Agregar el
código que usa la función desde main (un ejemplo completo que la use y muestre
los valores obtenidos).
*/

int suma(int, int *);

int main(void) {

  int primero, segundo;

  printf("Ingrese el primer numero: ");
  scanf("%i", &primero);
  printf("Ingrese el segundo numero: ");
  scanf("%i", &segundo);

  int resultado = suma(primero, &segundo);

  printf("El resultado es: %i", resultado);

  return 0;
}

int suma(int primero, int *segundo) {
  int a = primero;
  int *b = segundo;
  int suma = 0;
  int mayor = 0;
  suma = primero + *segundo;

  if (primero >= *segundo) {
    *segundo = primero;
  }
  // menor = *segundo;
  /*} else {
      mayor = *segundo;
     //menor = *primero;
  }*/

  printf("El mayor es: %i \n", *segundo);
  return suma;
}

#-------------------------------------------------------------------------
#Ejercicio 23

#include <stdio.h>
/*Crear una función que reciba un vector int, un valor mínimo y otro máximo. La
función debe mostrar el vector completo utilizando aritmética de punteros, pero
debe mostrar el valor si el mismo está dentro de los valores mínimo y máximo
recibidos.*/
void mostrarVec(int *, int , int , int);
int main(void) {

  const int size = 10;
  int vec[size];
  int minimo;
  int maximo;

  printf("llene el vector con 10 numeros: \n");
  for (int i = 0; i < size; i++) {
    scanf("%i", &vec[i]);
  }
  printf("ingrese un rango minimo: ");
  scanf("%i", &minimo);
  printf("ingrese un rango maximo: ");
  scanf("%i", &maximo);
 mostrarVec( vec, size, minimo, maximo);
  return 0;
}

void mostrarVec(int *vector, int size, int min, int max) {

  int *puntero = vector;

  for (int i = 0; i < size; i++) {
    if (*puntero >= min && *puntero <= max) {
      printf("%i\n",*puntero);
    }
    puntero++;
  }
}

#-------------------------------------------------------------------------
#Ejercicio 24

#include <stdio.h>
/*Crear una función que reciba un vector tipo char y dos valores int ‘desde’ y
‘hasta’. La función debe llenar con la letra ‘x’ a las posiciones del vector que
se encuentren entre los valores ‘desde’ y ‘hasta’. Lo debe realizar aplicando
aritmética de punteros. Mostrar todo el vector antes y después del cambio. Solo
con aritmética de punteros.*/
void Letrass(char *, int, int);

int main(void) {

  char letras[50] = "djsadjsajdas";

  int desde = 4;
  int hasta = 8;

  Letrass(letras, desde, hasta);

  return 0;
}

void Letrass(char *letras, int desde, int hasta) {
  int i;
  char *puntero = letras;
  char *hastaa = puntero;

   printf("vector sin modificar %s \n", letras);
  
  puntero=puntero+desde;
  hastaa=hastaa+hasta;
  while (puntero < hastaa) {
    *puntero = 'x';
    puntero++;
  }
 
    printf("Vector después del cambio: ");
    printf("%s \n", letras);
    }
  
#-------------------------------------------------------------------------
#Ejercicio 25

#include <stdio.h>
/*Escribir una función que reciba un string y muestre solo las consonantes por
pantalla empleando aritmética de punteros.*/
void consonante(char *);
int main(void) {

  char cadena[100] = "hola como estas";
  consonante(cadena);
  return 0;
}
void consonante(char *cadena) {
  int i;
  char temp[100];
  char *p = cadena;

  while (*p != '\0') {
    if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u') {
      temp[i] = *p;
    }
    p++;
  }
  while (temp[i] != '\0') {
    printf("%c", temp[i]);
    i++;
  }
}

#-------------------------------------------------------------------------
#Ejercicio 26

#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[] = "Hola";
    char cadena2[] = "Adiós";

    int resultado = strcmp(cadena1, cadena2);

    if (resultado == 0) {
        printf("Las cadenas son iguales.\n");
    } else if (resultado < 0) {
        printf("La cadena 1 es menor que la cadena 2.\n");
    } else {
        printf("La cadena 1 es mayor que la cadena 2.\n");
    }

    return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 27

#include <stdio.h>
//---Prototipo de funcion---
void mayorNumero(int numero[], int cantidad);
 //---Funcion main---
int main(void) {
  //Inicializo una variable tipo vector
  int numero[10];
//Ciclo for
  for (int i = 0; i < 10; i++) {
    printf("ingrese el numero n°%i : ", i + 1);
    scanf("%i", &numero[i]);
  }
//Llamo a la funcion
  mayorNumero(numero, 10);
  return 0;
}
//---Funcion encontrar mayor numero y cantidad de veces que se repite---
void mayorNumero(int numero[], int cantidad) {
  //Inicializo mayorNumero con lo que contenga el vector en la posicion 0
  int mayorNumero = numero[0];
  int repetido = 1;
  for (int i = 1; i < cantidad; i++) {
    //Condicion if para comparar los numeros
    if (numero[i] > mayorNumero) {
      mayorNumero = numero[i];
      repetido = 1;
    } else if (numero[i] == mayorNumero) {
      repetido++;
    }
  }
  //Mostramos lo pedido
  printf("el numero mas alto fue %i y la cantidad de veces que se encontro fue "
         "de %i",
         mayorNumero, repetido);
}

#-------------------------------------------------------------------------
#Ejercicio 28

#include <stdio.h>
//---Prototipo de funcion---
void mayorNumero(int mayorNum, int cantidad);
  //---Funcion main---
int main(void){
  //Inicializacion de variables
  int mayorNum, cantidad;
  //Llamado de la funcion
  mayorNumero(mayorNum, 10);
  return 0;
}
//---Funcion mayorNumero---
void mayorNumero(int mayorNum, int cantidad){
  int numero;
  int repetido=1;
  //Le pedimos al usuario que ingrese un numero
  printf("ingrese un numero: ");
  scanf("%i",&mayorNum);
  //Ciclo for
  for(int i=0;i<cantidad;i++){
    printf("ingrese el numero n°%i: ",i+1);
    scanf("%i",&numero);
    //Condicional if donde compaara el numero ingresado con el numero mayor
    if(numero>mayorNum){
      mayorNum=numero;
      repetido=1;
    }else if(numero==mayorNum){
          repetido++;
        }
      }
  //Muestra lo pedido
  printf("el mayor valor fue %i y se repitio %i veces", mayorNum, repetido);
}
#-------------------------------------------------------------------------
#Ejercicio 29

#include <stdio.h>
#include <string.h>
//---Funcion main---
int main(void) {
  //Inicializacion de variables
int tipoFac, cantItems, cantMismoIt, precio,mayorPrecio=0, total=0;
  //variables tipo char
  char tipoArticulo[100],nombreMayorPrecio[100];
  int cantidadMayorPrecio = 0;
  int resultado=0;
  float promedio=0;
  //menu
  printf("-------------------------------------\n");
 printf("Tipo 1: responsable inscripto, discrimina el 10,5 porciento de descuento\n"); 
  printf("Tipo 2: consumidor final, se aplica el 21 porciento\n");
  printf("Tipo 3: bienes y servicios, tiene una deducción del 27 porciento\n");
  printf("-------------------------------------\n\n");
  //Le peido al usuario que ingrese la cantidad de facturas a procesar
printf("ingrese el tipo de factura: ");
  scanf("%i",&tipoFac);

  printf("\ningrese la cantidad de articulos: ");
  scanf("%i",&cantItems);
//Ciclo for, va ingresando los datos de las facturas
  for(int i=0; i<cantItems; i++){
    printf("\ntipo de articulo: ");
    getchar();
    fgets(tipoArticulo, sizeof(tipoArticulo), stdin);
    printf("\nprecio del articulo: ");
    scanf("%i",&precio);
    printf("\ncantidad de articulo: ");
    scanf("%i",&cantMismoIt);
    printf("\narticulo cargado correctamente\n");
    //esta condicion es para saber cual es el articulo mas caro y muestra el nombre y el precio
    if(precio>mayorPrecio){
      mayorPrecio=precio;
      cantidadMayorPrecio = cantMismoIt;
      strcpy(nombreMayorPrecio,tipoArticulo);
      //Cuenta para calcular el total
       resultado = mayorPrecio * cantidadMayorPrecio;
    }
     promedio += resultado;
  }
  //cuenta para calcular el promedio
  promedio = (float)promedio / cantItems;
  //muestra los datos pedidos
  printf("\nEl item de mayor valor es: \n");
  printf("Nombre: %s\n", nombreMayorPrecio);
  printf("Precio: %i\n", mayorPrecio);
  printf("Cantidad: %i\n", cantidadMayorPrecio);
  printf("Importe total: %i\n",resultado);
printf("promedio de importe %2.f",promedio);
  return 0;
}

#-------------------------------------------------------------------------
#Ejercicio 30
