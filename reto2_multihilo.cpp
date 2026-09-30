//reto2_multihilo.cpp
#include <iostream>
#include <pthread.h>

using namespace std;

// Estructura para pasar el numero al hilo y guardar su resultado
struct DatosFactorial {
    int numero;
    long long resultado;
};

void* calcularFactorial(void* arg) {
    DatosFactorial* datos = (DatosFactorial*)arg;
    long long factorial = 1;
    
    for (int i = 1; i <= datos->numero; i++) {
        factorial *= i;
    }
    
    datos->resultado = factorial;
    
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2, hilo3;
    
    // Asignamos tres numeros diferentes
    DatosFactorial datos1 = {4, 0};
    DatosFactorial datos2 = {5, 0};
    DatosFactorial datos3 = {6, 0};

    int estado1 = pthread_create(&hilo1, NULL, calcularFactorial, (void*)&datos1);
    int estado2 = pthread_create(&hilo2, NULL, calcularFactorial, (void*)&datos2);
    int estado3 = pthread_create(&hilo3, NULL, calcularFactorial, (void*)&datos3);

    if (estado1 != 0 || estado2 != 0 || estado3 != 0) {
        cout << "Error al crear los hilos." << endl;
    } else {
        // Esperamos a que los tres hilos terminen su ejecucion
        pthread_join(hilo1, NULL);
        pthread_join(hilo2, NULL);
        pthread_join(hilo3, NULL);

        cout << "[Hilo Principal] Factorial de " << datos1.numero << " es: " << datos1.resultado << endl;
        cout << "[Hilo Principal] Factorial de " << datos2.numero << " es: " << datos2.resultado << endl;
        cout << "[Hilo Principal] Factorial de " << datos3.numero << " es: " << datos3.resultado << endl;
    }

    return 0;
}