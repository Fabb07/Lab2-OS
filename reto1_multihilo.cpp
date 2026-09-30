//reto1_multihilo.cpp
#include <iostream>
#include <pthread.h>

using namespace std;

// Arreglo global para que los hilos puedan acceder a el
int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Estructura para pasarle los limites de la mitad del arreglo a cada hilo
struct RangoSuma {
    int indiceInicio;
    int indiceFin;
    int sumaLocal;
};

void* calcularMitad(void* arg) {
    RangoSuma* rango = (RangoSuma*)arg;
    rango->sumaLocal = 0;
    
    for (int i = rango->indiceInicio; i < rango->indiceFin; i++) {
        rango->sumaLocal += numeros[i];
    }
    
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;
    
    // El hilo 1 sumara de los indices 0 al 4. El hilo 2 del 5 al 9.
    RangoSuma rango1 = {0, 5, 0};
    RangoSuma rango2 = {5, 10, 0};

    int estado1 = pthread_create(&hilo1, NULL, calcularMitad, (void*)&rango1);
    int estado2 = pthread_create(&hilo2, NULL, calcularMitad, (void*)&rango2);

    if (estado1 != 0 || estado2 != 0) {
        cout << "Error al crear los hilos." << endl;
    } else {
        // Esperamos a que ambos hilos terminen
        pthread_join(hilo1, NULL);
        pthread_join(hilo2, NULL);
        
        cout << "[Hilo Principal] Suma calculada por el primer hilo: " << rango1.sumaLocal << endl;
        cout << "[Hilo Principal] Suma calculada por el segundo hilo: " << rango2.sumaLocal << endl;
        
        int sumaTotal = rango1.sumaLocal + rango2.sumaLocal;
        cout << "[Hilo Principal] La suma total uniendo resultados es: " << sumaTotal << endl;
    }

    return 0;
}