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
