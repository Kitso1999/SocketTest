#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main(){
    int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

    struct sockaddr_in bindAddr;
    bindAddr.sin_addr.s_addr = INADDR_ANY;
    bindAddr.sin_family = AF_INET;
    bindAddr.sin_port = 9002;

    connect(client_socket, (struct sockaddr*)&bindAddr, sizeof(bindAddr));
    puts("Connection established");

    char response[256];
    recv(client_socket, response, sizeof(response), 0);
    puts(response);

    close(client_socket);
    puts("connection ended");
}