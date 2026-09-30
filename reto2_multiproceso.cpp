//reto2_multiproceso.cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int n1 = 5;
    int n2 = 6;
    
    pid_t pid = fork();

    if (pid < 0) {
        cout << "Error al crear el proceso hijo." << endl;
    } 
    else if (pid == 0) {
        // --- PROCESO HIJO ---
        long long factorialHijo = 1;
        
        for (int i = 1; i <= n1; i++) {
            factorialHijo *= i;
        }
        
        cout << "[Proceso Hijo] El factorial de " << n1 << " es: " << factorialHijo << endl;
    } 
    else {
        // --- PROCESO PADRE ---
        long long factorialPadre = 1;
        
        for (int i = 1; i <= n2; i++) {
            factorialPadre *= i;
        }
        
        cout << "[Proceso Padre] El factorial de " << n2 << " es: " << factorialPadre << endl;
        
        wait(NULL); // El padre espera a que el hijo termine
    }

    return 0;
}