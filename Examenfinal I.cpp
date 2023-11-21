#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30
clock_t inicio = clock();
void llenarMatriz(int matriz[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; ++i) 
	{
        for (int j = 0; j < SIZE; ++j) 
		{
            matriz[i][j] = rand() % 10;
        }
    }
}

void mostrarMatriz(int matriz[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; ++i) 
	{
        for (int j = 0; j < SIZE; ++j) 
		{
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void multiplicarMatrices(int matriz1[SIZE][SIZE], int matriz2[SIZE][SIZE], int resultado[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; ++i) 
	{
        for (int j = 0; j < SIZE; ++j) 
		{
            resultado[i][j] = 0;
            for (int k = 0; k < SIZE; ++k) 
			{
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}


int main() 
{
	
int matrizA[SIZE][SIZE];
int matrizB[SIZE][SIZE];
int resultado[SIZE][SIZE];

srand(time(NULL));
llenarMatriz(matrizA);
llenarMatriz(matrizB);
printf("Matriz A:\n");
mostrarMatriz(matrizA);
printf("Matriz B:\n");
mostrarMatriz(matrizB);
    

multiplicarMatrices(matrizA, matrizB, resultado);
clock_t fin = clock();
double tiempo = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
printf("Matriz Resultado:\n");
mostrarMatriz(resultado);
printf("Tiempo de ejecución: %.2f milisegundos\n", tiempo);

return 0;
}


