//Lab2-OS.cpp
//actividad3-OS.cpp
#include <iostream>

using namespace std;

int main() {
    // 1. Declarar un array de numeros enteros
    int miArray[5] = {10, 20, 30, 40, 50};

    // 2. Utilizar punteros para acceder a los elementos del array y modificar su contenido
    int* punteroArray = miArray;

    // Modificamos el segundo elemento y el cuarto elemento usando el puntero
    *(punteroArray + 1) = 99; 
    *(punteroArray + 3) = 88; 

    cout << "Valores del array despues de la modificacion:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << miArray[i] << endl;
    }

    // 3. Presente la direccion de memoria del array y del puntero
    cout << "\nDireccion de memoria del array (miArray): " << miArray << endl;
    cout << "Direccion almacenada en el puntero (punteroArray): " << punteroArray << endl;
    cout << "Direccion de memoria del propio puntero (&punteroArray): " << &punteroArray << endl;

    return 0;
}
