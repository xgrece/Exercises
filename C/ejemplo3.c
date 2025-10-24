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