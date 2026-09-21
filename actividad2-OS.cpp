//Lab2-OS.cpp
//actividad2-OS.cpp
#include <iostream>

using namespace std;

int main() {
    int variable = 50;

    // 1. Declarar un puntero a una variable
    int* puntero = &variable;

    // 2. Utilizar el puntero para acceder y modificar el valor de la variable
    *puntero = 150;
    cout << "Valor despues de modificar con el puntero: " << variable << endl;

    // 3. Crear una referencia a la variable y utilicela para modificar el valor
    int& referencia = variable;
    referencia = 300;
    cout << "Valor despues de modificar con la referencia: " << variable << endl;

    // 4. Presente las direcciones de memoria del puntero y la referencia
    cout << "Direccion de la variable original: " << &variable << endl;
    cout << "Direccion a la que apunta el puntero: " << puntero << endl;
    cout << "Direccion en memoria del propio puntero: " << &puntero << endl;
    cout << "Direccion de la referencia: " << &referencia << endl;

    return 0;
}