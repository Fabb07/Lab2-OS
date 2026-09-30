//ipc_struct.cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

// b. Crear una estructura para el paso de mensajes
struct MensajeIPC {
    int id;
    char contenido[100];
};

int main() {
    int fd[2];
    int estadoPipe = pipe(fd);

    if (estadoPipe == -1) {
        cout << "Error al crear el canal de comunicacion." << endl;
    } else {
        // a. Usar fork() para crear un proceso hijo
        pid_t pid = fork();

        if (pid < 0) {
            cout << "Error al intentar crear el proceso hijo." << endl;
        } 
        else if (pid > 0) {
            // --- PROCESO PADRE ---
            // Cerramos el extremo de lectura
            close(fd[0]); 
            
            // Llenamos la estructura con los datos a enviar
            MensajeIPC mensajePadre;
            mensajePadre.id = 101;
            strcpy(mensajePadre.contenido, "Hola hijo, te envio este mensaje empaquetado en un struct.");
            
            // c. Enviar el mensaje (la estructura) al proceso hijo desde el padre
            write(fd[1], &mensajePadre, sizeof(MensajeIPC));
            
            // Cerramos escritura y esperamos al hijo
            close(fd[1]); 
            wait(NULL); 
        } 
        else {
            // --- PROCESO HIJO ---
            // Cerramos el extremo de escritura
            close(fd[1]); 
            
            MensajeIPC mensajeRecibido;
            
            // Leemos los bytes correspondientes al tamano de la estructura
            read(fd[0], &mensajeRecibido, sizeof(MensajeIPC));
            
            cout << "[Proceso Hijo] Recibi la siguiente estructura de mi padre:" << endl;
            cout << " - ID del mensaje: " << mensajeRecibido.id << endl;
            cout << " - Contenido: " << mensajeRecibido.contenido << endl;
            
            // Cerramos el extremo de lectura al terminar
            close(fd[0]); 
        }
    }

    return 0;
}