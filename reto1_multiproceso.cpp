//reto1_multiproceso.cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int fd[2];
    int estadoPipe = pipe(fd);

    if (estadoPipe == -1) {
        cout << "Error al crear el pipe de comunicacion." << endl;
    } else {
        pid_t pid = fork();

        if (pid < 0) {
            cout << "Error al crear el proceso hijo." << endl;
        } 
        else if (pid == 0) {
            // --- PROCESO HIJO (Suma la segunda mitad: indices 5 al 9) ---
            close(fd[0]); // Cierra lectura
            int sumaHijo = 0;
            
            for (int i = 5; i < 10; i++) {
                sumaHijo += numeros[i];
            }
            
            cout << "[Proceso Hijo] Mi suma parcial es: " << sumaHijo << endl;
            write(fd[1], &sumaHijo, sizeof(sumaHijo)); // Envia resultado al padre
            close(fd[1]);
        } 
        else {
            // --- PROCESO PADRE (Suma la primera mitad: indices 0 al 4) ---
            close(fd[1]); // Cierra escritura
            int sumaPadre = 0;
            
            for (int i = 0; i < 5; i++) {
                sumaPadre += numeros[i];
            }
            cout << "[Proceso Padre] Mi suma parcial es: " << sumaPadre << endl;
            
            int sumaRecibidaDelHijo = 0;
            read(fd[0], &sumaRecibidaDelHijo, sizeof(sumaRecibidaDelHijo)); // Lee resultado del hijo
            close(fd[0]);
            
            wait(NULL); // Espera a que termine el hijo
            
            int sumaTotal = sumaPadre + sumaRecibidaDelHijo;
            cout << "[Proceso Padre] La suma total uniendo resultados es: " << sumaTotal << endl;
        }
    }

    return 0;
}