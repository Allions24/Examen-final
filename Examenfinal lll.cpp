#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANO_ARREGLO 50000
#define NUM_EJECUCIONES 100

int busquedaSecuencial(int arreglo[], int n, int elemento)
{
    for (int i = 0; i < n; i++)
    {
        if (arreglo[i] == elemento)
        {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int arreglo[], int izquierda, int derecha, int elemento)
{
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arreglo[medio] == elemento)
        {
            return medio;
        }

        if (arreglo[medio] < elemento)
        {
            izquierda = medio + 1;
        }
        else {
            derecha = medio - 1;
        }
    }

    return -1;
}

int main()
{
    int arreglo[TAMANO_ARREGLO];
    clock_t inicio, fin;
    double tiempoPromedioSecuencial, tiempoMinimoSecuencial, tiempoMaximoSecuencial;
    double tiempoPromedioBinaria, tiempoMinimoBinaria, tiempoMaximoBinaria;

    srand(time(NULL));

    for (int i = 0; i < TAMANO_ARREGLO; i++)
    {
        arreglo[i] = i * 2;
    }

    tiempoPromedioSecuencial = 0;
    tiempoMinimoSecuencial = __DBL_MAX__;
    tiempoMaximoSecuencial = 0;

    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        int elementoBuscar = rand() % (TAMANO_ARREGLO * 2);
        inicio = clock();
        busquedaSecuencial(arreglo, TAMANO_ARREGLO, elementoBuscar);
        fin = clock();
        double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedioSecuencial += tiempoEjecucion;

        if (tiempoEjecucion < tiempoMinimoSecuencial) {
            tiempoMinimoSecuencial = tiempoEjecucion;
        }

        if (tiempoEjecucion > tiempoMaximoSecuencial) {
            tiempoMaximoSecuencial = tiempoEjecucion;
        }
    }

    tiempoPromedioSecuencial /= NUM_EJECUCIONES;

    printf("Busqueda Secuencial:\n");
    printf("Tiempo Promedio: %.9f ms\n", tiempoPromedioSecuencial);
    printf("Tiempo Minimo: %.9f ms\n", tiempoMinimoSecuencial);
    printf("Tiempo Maximo: %.9f ms\n\n", tiempoMaximoSecuencial);

    tiempoPromedioBinaria = 0;
    tiempoMinimoBinaria = __DBL_MAX__;
    tiempoMaximoBinaria = 0;

    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        int elementoBuscar = rand() % (TAMANO_ARREGLO * 2);
        inicio = clock();
        busquedaBinaria(arreglo, 0, TAMANO_ARREGLO - 1, elementoBuscar);
        fin = clock();
        double tiempoEjecucion = ((double)(fin - inicio) * 1000) / CLOCKS_PER_SEC;
        tiempoPromedioBinaria += tiempoEjecucion;

        if (tiempoEjecucion < tiempoMinimoBinaria) {
            tiempoMinimoBinaria = tiempoEjecucion;
        }

        if (tiempoEjecucion > tiempoMaximoBinaria) {
            tiempoMaximoBinaria = tiempoEjecucion;
        }
    }

    tiempoPromedioBinaria /= NUM_EJECUCIONES;

    printf("Busqueda Binaria:\n");
    printf("Tiempo Promedio: %.9f ms\n", tiempoPromedioBinaria);
    printf("Tiempo Minimo: %.9f ms\n", tiempoMinimoBinaria);
    printf("Tiempo Maximo: %.9f ms\n", tiempoMaximoBinaria);

    return 0;
}
