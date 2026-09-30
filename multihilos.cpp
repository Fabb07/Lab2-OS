//multihilos.cpp
#include <iostream>
#include <pthread.h>

using namespace std;

// 1. Implementar una funcion que ejecutara el hilo
void* funcionHilo(void* arg) {
    cout << "[Hilo Secundario] Ejecutando instrucciones dentro del nuevo hilo." << endl;
    
    return NULL;
}

int main() {
    pthread_t miHilo;

    // 2. Imprimir mensaje desde el hilo principal
    cout << "[Hilo Principal] Iniciando el programa. Creando el hilo secundario..." << endl;

    // 3. Usar pthread_create para iniciar un nuevo hilo
    int estadoCreacion = pthread_create(&miHilo, NULL, funcionHilo, NULL);

    if (estadoCreacion != 0) {
        cout << "[Hilo Principal] Error al crear el hilo." << endl;
    } else {
        // 4. Usar pthread_join para esperar a que el hilo complete su ejecucion
        pthread_join(miHilo, NULL);
        cout << "[Hilo Principal] El hilo secundario ha terminado. Finalizando programa." << endl;
    }

    return 0;
}