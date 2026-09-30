//ipc_pipe.cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

int main() {
    // Arreglo para los descriptores de archivo del pipe:
    int fd[2]; 
    
    // b. Utilizar la funcion pipe() para crear el canal de comunicacion
    int estadoPipe = pipe(fd);

    if (estadoPipe == -1) {
        cout << "Error al crear el canal de comunicacion (pipe)." << endl;
    } else {
        // a. Usar fork() para crear un proceso hijo
        pid_t pid = fork();

        if (pid < 0) {
            cout << "Error al intentar crear el proceso hijo." << endl;
        } 
        else if (pid > 0) {
            // --- PROCESO PADRE ---
            // Cerramos el extremo de lectura porque el padre solo va a escribir
            close(fd[0]); 
            
            // c. Enviar un mensaje al proceso hijo desde el padre
            const char* mensaje = "Hola hijo, este es un mensaje de tu padre a traves del pipe.";
            write(fd[1], mensaje, strlen(mensaje) + 1);
            
            // Cerramos el extremo de escritura despues de enviar el mensaje
            close(fd[1]); 
            
            // Esperamos a que el proceso hijo termine su ejecucion
            wait(NULL); 
        } 
        else {
            // --- PROCESO HIJO ---
            // Cerramos el extremo de escritura porque el hijo solo va a leer
            close(fd[1]); 
            
            char buffer[200];
            // Leemos los datos que el padre envio por el pipe
            read(fd[0], buffer, sizeof(buffer));
            
            cout << "[Proceso Hijo] Recibi este mensaje: " << buffer << endl;
            
            // Cerramos el extremo de lectura al terminar
            close(fd[0]); 
        }
    }

    // Unico retorno de la funcion main
    return 0; 
}