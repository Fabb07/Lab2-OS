//multiproceso.cpp

#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Iniciando el programa. PID del proceso original: " << getpid() << endl;

    // 1. Crear un proceso hijo usando la funcion fork
    pid_t pid = fork();

    // fork() devuelve un valor diferente dependiendo de donde nos encontremos
    if (pid < 0) {
        // Si es menor a 0, hubo un error
        cout << "Error: No se pudo crear el proceso hijo." << endl;
    } 
    else if (pid == 0) {
        // Si es 0 estamos dentro del proceso HIJO
        // 2. Mostrar los IDs del proceso
        cout << "[Proceso Hijo] Mi PID es: " << getpid() << " | El PID de mi padre es: " << getppid() << endl;
    } 
    else {
        // Si es mayor a 0 estamos dentro del proceso PADRE
        // La variable pid contiene el ID del hijo que se acaba de crear
        cout << "[Proceso Padre] Mi PID es: " << getpid() << " | Cree un hijo con PID: " << pid << endl;
    }

    // Tanto el padre como el hijo ejecutaran esta linea al terminar su bloque if-else
    return 0;
}