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
