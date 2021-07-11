#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

    struct sockaddr_in bindAddr;
    bindAddr.sin_addr.s_addr = INADDR_ANY;
    bindAddr.sin_family = AF_INET;
    bindAddr.sin_port = 9002;

    bind(server_socket, (struct sockaddr*)&bindAddr, sizeof(bindAddr));

    listen(server_socket, 5);
    puts("Listening...");

    int client_socket = accept(server_socket, NULL, NULL);
    puts("Connection established");

    char response[] = "Hello, mate!";

    send(client_socket, response, sizeof(response), 0);

    close(server_socket);
    puts("connection ended");
}