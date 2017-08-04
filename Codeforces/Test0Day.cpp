#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <winsock.h>
#include <string>
#include <direct.h>

#pragma comment(lib, "wsock32.lib")

using namespace std;

#define SERVER_PORT 80

void header();
int createConnection(string targetAddr, int targetPort);
int sendTransmission(string message);
string recvTransmission();
void cleanUp();

WORD sockVersion;
WSADATA wsaData;

int sock;
struct sockaddr_in rserver;

//Setup the server
int createConnection(string serverIP, int port)
{
        int result = 0, len = 0;

        sockVersion = MAKEWORD(1,1);
        WSAStartup(sockVersion, &wsaData);

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        {
                perror("error: socket()\n");
                result = 1;
        }

        rserver.sin_family = AF_INET;
        rserver.sin_port = htons(port);
        rserver.sin_addr.s_addr = inet_addr(serverIP.c_str());
        memset(&rserver.sin_zero, 0, 8);

        len = sizeof(struct sockaddr_in);

        if ((connect(sock, (struct sockaddr *)&rserver, sizeof(struct sockaddr_in))) == -1)
        {
                perror("error: connect()\n");
                result = 1;
        }

        return result;
}

void header()
{
printf("________________________________________________________\n");
printf("  ___            _             _             _     _ _ \n");
printf(" / __| __ _ _  _(_)_ _ _ _ ___| |___ ____ __| |___(_) |_ \n");
printf(" \__ \/ _` | || | | '_| '_/ -_) |___(_-< '_ \ / _ \ |  _|\n");
printf(" |___/\__, |\_,_|_|_| |_| \___|_|   /__/ .__/_\___/_|\__|\n");
printf("         |_|                           |_|               \n");
printf("\n");
printf("_________________________________________________________\n\n");
printf("Download : sourceforge.net/projects/squirrelsploit/ \n\n");
printf("Tutorial (English): youtube.com/watch?v=zfsBXz3lmRg \n\n");
printf("         (French) : youtube.com/watch?v=X_HGCXajyVA \n\n");
printf("set> stealmail xxxx@hotmail.com \n");

}

//Send a message
int sendTransmission(string message)
{
        int bytes_sent = 0;

        bytes_sent = send(sock, message.c_str(), message.length(), 0);
        if (bytes_sent < 0)
        {
                perror("error: send()\n");
                exit(1);
        }

        return bytes_sent;
}

//Receive a message
string recvTransmission()
{
        string result;
        char *c = new char[1];
        int bytes_recv = 0;

        while (c[0] != NULL)
        {
                bytes_recv = recv(sock, c, 1, 0);

                if (bytes_recv < 0)
                {
                        perror("error: recv()\n");
                        //exit(1);
                }

                result += c[0];
        }

        return result;
}

//Clean up the connection
void cleanUp()
{
        closesocket(sock);
        WSACleanup();
}
