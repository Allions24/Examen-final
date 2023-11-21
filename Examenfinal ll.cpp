#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_ARREGLO 10000
#define NUM_EJECUCIONES 100


void intercambiar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arreglo[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arreglo[j] > arreglo[j + 1])
            {
                intercambiar(&arreglo[j], &arreglo[j + 1]);
            }
        }
    }
}

void insertionSort(int arreglo[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arreglo[i];
        j = i - 1;

        while (j >= 0 && arreglo[j] > key)
        {
            arreglo[j + 1] = arreglo[j];
            j = j - 1;
        }
        arreglo[j + 1] = key;
    }
}

int particion(int arreglo[], int bajo, int alto)
{
    int pivote = arreglo[alto];
    int i = bajo - 1;

    for (int j = bajo; j <= alto - 1; j++)
    {
        if (arreglo[j] < pivote)
        {
            i++;
            intercambiar(&arreglo[i], &arreglo[j]);
        }
    }
    intercambiar(&arreglo[i + 1], &arreglo[alto]);
    return i + 1;
}

void quickSort(int arreglo[], int bajo, int alto)
{
    if (bajo < alto)
    {
        int pi = particion(arreglo, bajo, alto);

        quickSort(arreglo, bajo, pi - 1);
        quickSort(arreglo, pi + 1, alto);
    }
}

int main()
{
    int arregloOriginal[TAMANO_ARREGLO];
    int arregloCopia[TAMANO_ARREGLO];
    clock_t inicio, fin;
    double tiempoPromedio, tiempoMinimo, tiempoMaximo;

    srand(time(NULL));

    for (int i = 0; i < TAMANO_ARREGLO; i++)
    {
        arregloOriginal[i] = rand() % 10000;
    }

    tiempoPromedio = 0;
    tiempoMinimo = __DBL_MAX__;
    tiempoMaximo = 0;

    for (int i = 0; i < NUM_EJECUCIONES; i++)
    {
        for (int j = 0; j < TAMANO_ARREGLO; j++)
        {
            arregloCopia[j] = arregloOriginal[j];
        }

        inicio = clock();
        bubbleSort(arregloCopia, TAMANO_ARREGLO);
        fin = clock();

        double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedio += tiempoEjecucion;

        if (tiempoEjecucion < tiempoMinimo)
        {
            tiempoMinimo = tiempoEjecucion;
        }

        if (tiempoEjecucion > tiempoMaximo)
        {
            tiempoMaximo = tiempoEjecucion;
        }
    }

    tiempoPromedio /= NUM_EJECUCIONES;

    printf("Bubble Sort:\n");
    printf("Tiempo Promedio: %.6f ms\n", tiempoPromedio);
    printf("Tiempo Mínimo: %.6f ms\n", tiempoMinimo);
    printf("Tiempo Máximo: %.6f ms\n\n", tiempoMaximo);

    tiempoPromedio = 0;
    tiempoMinimo = __DBL_MAX__;
    tiempoMaximo = 0;

    for (int i = 0; i < NUM_EJECUCIONES; i++)
    {
        for (int j = 0; j < TAMANO_ARREGLO; j++)
        {
            arregloCopia[j] = arregloOriginal[j];
        }

        inicio = clock();
        insertionSort(arregloCopia, TAMANO_ARREGLO);
        fin = clock();

        double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedio += tiempoEjecucion;

        if (tiempoEjecucion < tiempoMinimo)
        {
            tiempoMinimo = tiempoEjecucion;
        }

        if (tiempoEjecucion > tiempoMaximo)
        {
            tiempoMaximo = tiempoEjecucion;
        }
    }

    tiempoPromedio /= NUM_EJECUCIONES;

    printf("Insertion Sort:\n");
    printf("Tiempo Promedio: %.6f ms\n", tiempoPromedio);
    printf("Tiempo Mínimo: %.6f ms\n", tiempoMinimo);
    printf("Tiempo Máximo: %.6f ms\n\n", tiempoMaximo);

    tiempoPromedio = 0;
    tiempoMinimo = __DBL_MAX__;
    tiempoMaximo = 0;

    for (int i = 0; i < NUM_EJECUCIONES; i++)
    {
        for (int j = 0; j < TAMANO_ARREGLO; j++)
        {
            arregloCopia[j] = arregloOriginal[j];
        }

        inicio = clock();
        quickSort(arregloCopia, 0, TAMANO_ARREGLO - 1);
        fin = clock();

        double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedio += tiempoEjecucion;

        if (tiempoEjecucion < tiempoMinimo)
        {
            tiempoMinimo = tiempoEjecucion;
        }

        if (tiempoEjecucion > tiempoMaximo)
        {
            tiempoMaximo = tiempoEjecucion;
        }
    }

    tiempoPromedio /= NUM_EJECUCIONES;

    printf("Quick Sort:\n");
    printf("Tiempo Promedio: %.6f ms\n", tiempoPromedio);
    printf("Tiempo Mínimo: %.6f ms\n", tiempoMinimo);
    printf("Tiempo Máximo: %.6f ms\n", tiempoMaximo);

    return 0;
}

