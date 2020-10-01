/*
Autores: Antonio Junco de Haas, Sergio Hernandez Castillo
Matrículas: A, A01025210
Descripción: Actividad 6 - Sockets y Señales

127.0.0.1
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define TCP_PORT 8000

int main(int argc, const char * argv){
    struct sockaddr_in direccion;
    char buffer[1000];
    int servidor;
    int cliente;
    int continuar = 1;
    ssize_t leidos;
    ssize_t escritos; 
    pid_t pid;

    if (argc != 2){
        printf("Usa: %s IP_Servidor\n", argv[0]);
        exit(-1);
    }

    // Se crea el socket
    servidor = socket(PF_INET, SOCK_STREAM, 0);

    // Enlance con el socket
    inet_aton(argv[1], &direccion.sin_addr);
    direccion.sin_port = htons(TCP_PORT);
    direccion.sin_family = AF_INET;

    bind(servidor, (struct sockaddr *) &direccion, sizeof(direccion));

    // Escuchar 
    listen(servidor, 4); // Porque son 4 semaforos

    escritos = sizeof(direccion);

    return 0;
}