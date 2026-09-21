//Lab2-OS.cpp
//extra-OS.cpp
#include <iostream>

using namespace std;

// Funcion de prueba para representar el segmento de codigo
void funcionPrueba() {
    int a = 0;
}

int main() {
    // 1. STACK: Las variables locales se almacenan en la pila
    int variableStack = 10;

    // 2. HEAP: La memoria solicitada dinamicamente (con new) va al monticulo
    int* variableHeap = new int;

    // 3. CODE: Las instrucciones de las funciones se guardan en el segmento de texto/codigo
    // Hacemos un cast a (void*) para que cout imprima la direccion en lugar de intentar evaluar la funcion
    
    cout << "--- Distribucion de Memoria en C++ ---" << endl;
    cout << "Direccion en el Stack (variable local): " << &variableStack << endl;
    cout << "Direccion en el Heap (memoria dinamica): " << variableHeap << endl;
    cout << "Direccion en el Code (funcionPrueba):   " << (void*)funcionPrueba << endl;
    cout << "Direccion en el Code (funcion main):    " << (void*)main << endl;

    // Liberamos la memoria del heap
    delete variableHeap;

    return 0;
}