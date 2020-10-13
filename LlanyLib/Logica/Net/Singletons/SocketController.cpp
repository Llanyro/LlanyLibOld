#include "SocketController.hpp"

#include <iostream>

#include "../Headers/SocketsHeaders.hpp"
#include "../Enums/HTTPEnum.hpp"

#include "../Objetos/ServerSocket.hpp"
#include "../Objetos/HTTPRequest.hpp"

#include "../../Basic/Objetos/StringBuilder.hpp"

LlanyLib::Net::Singletons::SocketController::SocketController() { SocketController::subscribir(SocketController::freeInstancia); }
LlanyLib::Net::Singletons::SocketController::~SocketController(){}

void LlanyLib::Net::Singletons::SocketController::printTest(const Objetos::ServerSocket* serverSocket) const
{
	char c;
	bool continuar = true;
	bool fin = false;
	bool finr = false;

	while (continuar) {
		recv(serverSocket->getClientSocket(), &c, 1, 0);
		putchar(c);
		switch (((c == '\n') ? (1 << 0) : 0) |	// 1
				((c == '\r') ? (1 << 1) : 0) |	// 2
				(fin ? (1 << 2) : 0) |			// 4
				(finr ? (1 << 3) : 0))			// 8
		{
			case 2:
			case 3:
			case 4:
			case 5:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 14:
			case 15:
				fin = false;
				finr = false;
				break;
			case 1:
				fin = true;
				break;
			case 6:
				finr = true;
				break;
			case 13:
				continuar = false;
				break;
		}
	}
	SocketController::shitSend(serverSocket);
}
void LlanyLib::Net::Singletons::SocketController::shitSend(const Objetos::ServerSocket* serverSocket) const
{
	int iSendResult;
	int iResult;

	iSendResult = send(serverSocket->getClientSocket(), "HTTP/1.1 200 YAY it works!!!\n\rAccept-Ranges: bytes\n\rAccess-Control-Allow-Origin: *\n\rContent-Length: 16\n\rContent-Type: text/html; charset=utf-8\n\rDate: Sun Oct 11 23:49:08 CEST 2020\n\rServer: Server Interfaz for PAWR\n\r\n\rHola mundo test", 233, 0);

	if (iSendResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(serverSocket->getClientSocket());
		WSACleanup();
	}
	else printf("Bytes sent: %d\n", iSendResult);

	// shutdown the connection since we're done
	iResult = shutdown(serverSocket->getClientSocket(), SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(serverSocket->getClientSocket());
		WSACleanup();
	}
	else {
		// cleanup
		closesocket(serverSocket->getClientSocket());
		WSACleanup();
	}
}
LlanyLib::Net::Objetos::HTTPRequest* LlanyLib::Net::Singletons::SocketController::getHTTPRequest(const Objetos::ServerSocket* serverSocket) const
{
	return SocketController::getHTTPRequest(serverSocket, Enum::ResponseProcess::SUPER_SLOW);
}
LlanyLib::Net::Objetos::HTTPRequest* LlanyLib::Net::Singletons::SocketController::getHTTPRequest(const Objetos::ServerSocket* serverSocket, const Enum::ResponseProcess& processType) const
{
	Objetos::HTTPRequest* request = nullptr;
	Basic::Objetos::StringBuilder builder;
	char c;
	bool continuar = true;
	bool fin = false;
	bool finr = false;
	while (continuar) {
		recv(serverSocket->getClientSocket(), &c, 1, 0);
		putchar(c);
		if (c != '\r')
			builder += c;
		switch (((c == '\n') ? (1 << 0) : 0) | ((c == '\r') ? (1 << 1) : 0) | (fin ? (1 << 2) : 0) | (finr ? (1 << 3) : 0))			// 8
		{
		case 2:
		case 3:
		case 4:
		case 5:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 14:
		case 15:
			fin = false;
			finr = false;
			break;
		case 1:
			fin = true;
			break;
		case 6:
			finr = true;
			break;
		case 13:
			continuar = false;
			break;
		}
	}
	request = new Objetos::HTTPRequest(builder.build(), processType);
	SocketController::shitSend(serverSocket);
	return request;
}

/*void LlanyLib::Net::Objetos::ServerSocket::acceptConn()
{
	// Accept a client socket
	this->clientSocket = accept(this->listenSocket, NULL, NULL);
	if (this->clientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(this->listenSocket);
		WSACleanup();
	}
	else
	{
		int iSendResult;
		char recvbuf[512];
		int recvbuflen = 512;

		// No longer need server socket
		closesocket(this->listenSocket);

		// Receive until the peer shuts down the connection
		do {

			iResult = recv(this->clientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0) {
				printf("Bytes received: %d\n", iResult);

				// Echo the buffer back to the sender
				iSendResult = send(this->clientSocket, recvbuf, iResult, 0);
				if (iSendResult == SOCKET_ERROR) {
					iResult = 0;
					printf("send failed with error: %d\n", WSAGetLastError());
					closesocket(this->clientSocket);
					WSACleanup();
				}
				else printf("Bytes sent: %d\n", iSendResult);
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else {
				printf("recv failed with error: %d\n", WSAGetLastError());
				closesocket(this->clientSocket);
				WSACleanup();
			}

		} while (iResult > 0);

		std::cout << recvbuf << std::endl;

		if (iResult > 0) {
			// shutdown the connection since we're done
			iResult = shutdown(this->clientSocket, SD_SEND);
			if (iResult == SOCKET_ERROR) {
				printf("shutdown failed with error: %d\n", WSAGetLastError());
				closesocket(this->clientSocket);
				WSACleanup();
			}
			else
			{
				// cleanup
				closesocket(this->clientSocket);
				WSACleanup();
			}
		}
	}
}*/