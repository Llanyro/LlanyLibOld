#include "ClientSocket.hpp"

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>

#include "String.hpp"
#include "StringBuilder.hpp"
#include "../Enumerators/SocketEnum.hpp"

void LlanyLib::Basic::Objetos::ClientSocket::connect()
{
    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

}

LlanyLib::Basic::Objetos::ClientSocket::ClientSocket(String* port) : Socket(port, "ClientSocket")
{

}
LlanyLib::Basic::Objetos::ClientSocket::ClientSocket(String* port, char const* const className) : Socket(port, className)
{

}
LlanyLib::Basic::Objetos::ClientSocket::~ClientSocket(){}

