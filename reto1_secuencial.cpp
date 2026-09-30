//reto1_secuencial.cpp
#include <iostream>

using namespace std;

int main() {
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int suma = 0;

    for (int i = 0; i < 10; i++) {
        suma += numeros[i];
    }

    cout << "[Secuencial] La suma total del arreglo es: " << suma << endl;

    return 0;
}