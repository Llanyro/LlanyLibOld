#include "SocketController.hpp"

//#include <iostream>
#include <stdio.h>

#include "../../Basic/Singletons/Files.hpp"

#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/Registro.hpp"

#include "../Headers/SocketsHeaders.hpp"
#include "../Enums/HTTPEnum.hpp"

#include "../Objetos/ServerSocket.hpp"
#include "../Objetos/ConnectionSocket.hpp"
#include "../Objetos/HttpRequest.hpp"
#include "../Objetos/HTTPResponse.hpp"

#define HOST_STR "Host"
#define CONNECTION_STR "Connection"
#define UPGRADE_INSECURE_REQUESTS_STR "Upgrade-Insecure-Requests"
#define USER_AGENT_STR "User-Agent"
#define ACCEPT_STR "Accept"
#define ACCEPT_ENCODING_STR "Accept-Encoding"
#define ACCEPT_LANGUAJE_STR "Accept-Language"

LlanyLib::Net::Singletons::SocketController::SocketController() { SocketController::subscribir(SocketController::freeInstancia); }
LlanyLib::Net::Singletons::SocketController::~SocketController(){}

#pragma region HTTP
#define TEMPLATE "./Web/Templates/"
#define STATIC "./Web/Static/"

void LlanyLib::Net::Singletons::SocketController::getPetition(Objetos::HttpRequest* request, const Objetos::ConnectionSocket* connection) const
{
	Basic::Objetos::StringBuilder builder;
	Basic::Objetos::String* tempparam1 = nullptr;
	char c;
	bool continuar = true;
	int parte = 0;
	while (continuar) {
		recv(connection->getResponseSocket(), &c, 1, 0);
		putchar(c);
		if (c == ' ' || c == '\r') {
			switch (parte)
			{
				case 0:
					request->setPeticion(builder.build());
					break;
				case 1:
					if (tempparam1 != nullptr) {
						request->addParametro(tempparam1, builder.build());
						tempparam1 = nullptr;
					}
					else
						request->setRoot(builder.build());
					break;
				case 2:
					request->setVersion(builder.build());
					break;
			}
			parte++;
			builder.clear();
		}
		else if (c == '?') {
			request->setRoot(builder.build());
			builder.clear();
		}
		else if (c == '=') {
			tempparam1 = builder.build();
			builder.clear();
		}
		else if(c == '&') {
			request->addParametro(tempparam1, builder.build());
			builder.clear();
			tempparam1 = nullptr;
		}
		else if (c == '\n')
			continuar = false;
		else
			builder += c;
	}
}
void LlanyLib::Net::Singletons::SocketController::getKnownHeaders(Objetos::HttpRequest* request, const Objetos::ConnectionSocket* connection) const
{
	Basic::Objetos::Registro reg(3);
	Basic::Objetos::StringBuilder builder;
	Enum::HeatherType actualType = Enum::HeatherType::NONE;
	Basic::Objetos::String* temp = nullptr;
	char c;
	bool continuar = true;
	int parte = 0;
	while (continuar) {
		recv(connection->getResponseSocket(), &c, 1, 0);
		putchar(c);

		if (c == '\r') {
			if (*reg.getPos(0) == true)
				reg.setPosTrue(2);
			else
				reg.setPosTrue(0);
		}
		else if (c == '\n') {
			if (*reg.getPos(1) == true)
				continuar = false;
			else
				reg.setPosTrue(1);
		}




		if (c == '\r') {
			switch (actualType)
			{
				case Enum::HeatherType::HOST:
					request->setHost(builder.build());
					break;
			}
			builder.clear();
		}
		else if (c == '\n') {

		}
		if (c == ':') {
			if (builder.startWithSimilar(HOST_STR))
				actualType = Enum::HeatherType::HOST;
			//else if()



			builder.clear();
		}
		else builder += c;
	}

}
void LlanyLib::Net::Singletons::SocketController::getAllHeaders(Objetos::HttpRequest* request, const Objetos::ConnectionSocket* connection) const
{
	Basic::Objetos::Registro reg(3);
	Basic::Objetos::StringBuilder builder;
	Enum::HeatherType actualType = Enum::HeatherType::NONE;
	Basic::Objetos::String* temp = nullptr;
	char c;
	bool continuar = true;
	int parte = 0;
	while (continuar) {
		recv(connection->getResponseSocket(), &c, 1, 0);
		putchar(c);

		if (c == '\r') {
			if (*reg.getPos(0) == true)
				reg.setPosTrue(2);
			else
				reg.setPosTrue(0);
			if (temp != nullptr) {
				request->addHeader(temp, builder.build());
				temp = nullptr;
				builder.clear();
			}
		}
		else if (c == '\n') {
			if (*reg.getPos(1) == true)
				continuar = false;
			else
				reg.setPosTrue(1);
		}
		else if (c == ':' && temp == nullptr) {
			temp = builder.build();
			builder.clear();
		}
		else {
			if (c == ' ') {
				if (temp != nullptr && builder.contieneAlgo())
					builder += c;
			}
			else
				builder += c;
		}
	}
}
LlanyLib::Net::Objetos::HttpRequest* LlanyLib::Net::Singletons::SocketController::getHttpRequestPetition(const Objetos::ConnectionSocket* connection) const
{
	Objetos::HttpRequest* request = new Objetos::HttpRequest();
	SocketController::getPetition(request, connection);
	return request;
}
LlanyLib::Net::Objetos::HttpRequest* LlanyLib::Net::Singletons::SocketController::getHttpRequestPostContent(const Objetos::ConnectionSocket* connection) const
{
	return nullptr;
}
LlanyLib::Net::Objetos::HttpRequest* LlanyLib::Net::Singletons::SocketController::getHttpRequestFast(const Objetos::ConnectionSocket* connection) const
{
	return nullptr;
}
LlanyLib::Net::Objetos::HttpRequest* LlanyLib::Net::Singletons::SocketController::getHttpRequestSlow(const Objetos::ConnectionSocket* connection) const
{
	return nullptr;
}
LlanyLib::Net::Objetos::HttpRequest* LlanyLib::Net::Singletons::SocketController::getHttpRequestFull(const Objetos::ConnectionSocket* connection) const
{
	Objetos::HttpRequest* request = new Objetos::HttpRequest();
	SocketController::getPetition(request, connection);
	SocketController::getAllHeaders(request, connection);
	return request;
}
void LlanyLib::Net::Singletons::SocketController::sendHttpFileProtected(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const root, char const* const file) const
{
	Basic::Objetos::StringBuilder filePath;
	filePath.add(root);
	filePath.add(file);
	Basic::Objetos::String* fileName = filePath.build();
	Basic::Objetos::String* fileContent = FILES->leerFicheroFopenClear(fileName);

	if (fileContent != nullptr) {
		response->setContent(fileContent);
	}

	SocketController::sendMsgClear(connection, response->toString());
}
void LlanyLib::Net::Singletons::SocketController::sendHttpFileProtected(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const root, const Basic::Objetos::String* file) const
{
	Basic::Objetos::StringBuilder filePath;
	filePath.add(root);
	filePath.add(file);
	Basic::Objetos::String* fileName = filePath.build();
	Basic::Objetos::String* fileContent = FILES->leerFicheroFopenClear(fileName);

	if (fileContent != nullptr) {
		response->setContent(fileContent);
	}

	SocketController::sendMsgClear(connection, response->toString());
}
#pragma endregion

void LlanyLib::Net::Singletons::SocketController::printTest(const Objetos::ConnectionSocket* connection) const
{
	char c;
	bool continuar = true;
	bool fin = false;
	bool finr = false;

	while (continuar) {
		recv(connection->getResponseSocket(), &c, 1, 0);
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
	SocketController::shitSend(connection);
}
void LlanyLib::Net::Singletons::SocketController::shitSend(const Objetos::ConnectionSocket* connection) const
{
	int iSendResult;
	int iResult;

	iSendResult = send(connection->getResponseSocket(), "HTTP/1.1 200 YAY it works!!!\n\rAccept-Ranges: bytes\n\rAccess-Control-Allow-Origin: *\n\rContent-Length: 16\n\rContent-Type: text/html; charset=utf-8\n\rDate: Sun Oct 11 23:49:08 CEST 2020\n\rServer: Server Interfaz for PAWR\n\r\n\rHola mundo test", 233, 0);

	if (iSendResult == SOCKET_ERROR) {
		printf("send failed with error: %d\n", WSAGetLastError());
		closesocket(connection->getResponseSocket());
		WSACleanup();
	}
	else printf("Bytes sent: %d\n", iSendResult);

	// shutdown the connection since we're done
	iResult = shutdown(connection->getResponseSocket(), SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(connection->getResponseSocket());
		WSACleanup();
	}
	else {
		// cleanup
		closesocket(connection->getResponseSocket());
		WSACleanup();
	}
}

#pragma region HTTP
LlanyLib::Net::Objetos::HttpRequest* LlanyLib::Net::Singletons::SocketController::getHttpRequest(const Objetos::ConnectionSocket* connection, const Enum::ResponseProcess& processType) const
{
	LlanyLib::Net::Objetos::HttpRequest* request = nullptr;
	switch (processType)
	{
		case Enum::ResponseProcess::PETITION:
			request = SocketController::getHttpRequestPetition(connection);
			break;
		case Enum::ResponseProcess::POST_CONTENT:
			request = SocketController::getHttpRequestPetition(connection);
			break;
		case Enum::ResponseProcess::FAST:
			request = SocketController::getHttpRequestFast(connection);
			break;
		case Enum::ResponseProcess::SLOW:
			request = SocketController::getHttpRequestSlow(connection);
			break;
		case Enum::ResponseProcess::FULL:
			request = SocketController::getHttpRequestFull(connection);
			break;
	}
	return request;
}
void LlanyLib::Net::Singletons::SocketController::sendHttpResponse(const Objetos::ConnectionSocket* connection, const Objetos::HttpResponse* response) const
{
	SocketController::sendMsgClear(connection, response->toString());
}
void LlanyLib::Net::Singletons::SocketController::sendHttpTemplate(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const file) const
{
	SocketController::sendHttpFileProtected(connection, response, TEMPLATE, file);
}
void LlanyLib::Net::Singletons::SocketController::sendHttpTemplate(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, const Basic::Objetos::String* file) const
{
	SocketController::sendHttpFileProtected(connection, response, TEMPLATE, file);
}
void LlanyLib::Net::Singletons::SocketController::sendHttpTemplateClear(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, Basic::Objetos::String* file) const
{
	SocketController::sendHttpFileProtected(connection, response, TEMPLATE, file);
	delete file;
}
void LlanyLib::Net::Singletons::SocketController::sendHttpStatic(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const file) const
{
	SocketController::sendHttpFileProtected(connection, response, STATIC, file);
	delete file;
}
void LlanyLib::Net::Singletons::SocketController::sendHttpStatic(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, const Basic::Objetos::String* file) const
{
	SocketController::sendHttpFileProtected(connection, response, STATIC, file);
}
void LlanyLib::Net::Singletons::SocketController::sendHttpStaticClear(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, Basic::Objetos::String* file) const
{
	SocketController::sendHttpFileProtected(connection, response, STATIC, file);
	delete file;
}
#pragma endregion
#pragma region All
void LlanyLib::Net::Singletons::SocketController::sendMsg(const Objetos::ConnectionSocket* connection, const Basic::Objetos::String* msg) const
{
	for (size_t i = 0; i < msg->length(); i++)
		putchar(msg->operator[](i));
	send(connection->getResponseSocket(), msg->get(), msg->length(), 0);
}
void LlanyLib::Net::Singletons::SocketController::sendMsgClear(const Objetos::ConnectionSocket* connection, Basic::Objetos::String* msg) const
{
	SocketController::sendMsg(connection, msg);
	delete msg;
}
void LlanyLib::Net::Singletons::SocketController::closeConnectionSocket(const Objetos::ConnectionSocket* connection) const
{
	closesocket(connection->getResponseSocket());
	WSACleanup();
}
#pragma endregion

/*LlanyLib::Net::Objetos::HTTPRequest* LlanyLib::Net::Singletons::SocketController::getHTTPRequest(const Objetos::ConnectionSocket* connection) const
{
	return SocketController::getHTTPRequest(serverSocket, Enum::ResponseProcess::SUPER_SLOW);
}
LlanyLib::Net::Objetos::HTTPRequest* LlanyLib::Net::Singletons::SocketController::getHTTPRequest(const Objetos::ConnectionSocket* connection, const Enum::ResponseProcess& processType) const
{
	Objetos::HTTPRequest* request = nullptr;
	Basic::Objetos::StringBuilder builder;
	char c;
	bool continuar = true;
	bool fin = false;
	bool finr = false;
	while (continuar) {
		recv(connection->getResponseSocket(), &c, 1, 0);
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
*/
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
