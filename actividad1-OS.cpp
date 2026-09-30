//Lab2-OS.cpp
#include <iostream>

using namespace std;

int main() {
    // 1. Declarar y asignar una variable entera
    int variable = 10;

    // 2. Presentar en pantalla la direccion de memoria de la variable
    cout << "Valor inicial de la variable: " << variable << endl;
    cout << "Direccion de memoria de la variable: " << &variable << endl;

    // 3. Modificar el valor de la variable indirectamente utilizando punteros
    int* punteroVariable = &variable;
    *punteroVariable = 99;

    // 4. Presentar nuevamente el valor de la variable y la direccion de memoria
    cout << "Nuevo valor de la variable: " << variable << endl;
    cout << "Direccion de memoria de la variable despues de modificar: " << &variable << endl;

    return 0;
}
