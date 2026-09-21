//Lab2-OS.cpp
//actividad4-OS.cpp
#include <iostream>

using namespace std;

int main() {
    int filas = 3;
    int columnas = 4;

    // 1 y 2. Crear un programa que use asignacion dinamica con new para una matriz 2D
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    // 3. Llenar la matriz con datos
    int contador = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = contador;
            contador++;
        }
    }

    // Mostrar la matriz en pantalla para verificar que se lleno correctamente
    cout << "Matriz 2D dinamica:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // 4. Liberar la memoria con delete cuando haya terminado
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i]; // Libera cada fila
    }
    delete[] matriz; // Libera el arreglo de punteros principal

    cout << "\nMemoria liberada correctamente." << endl;

    return 0;
}