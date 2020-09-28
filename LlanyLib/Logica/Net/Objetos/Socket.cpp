#include "Socket.hpp"

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
/*
#include "Logger.hpp"
#include "String.hpp"
#include "StringBuilder.hpp"
#include "../Enumerators/SocketEnum.hpp"

void LlanyLib::Basic::Objetos::Socket::startData()
{
	if (this->lastCode == Enum::SocketCode::NoCode) {
		int iResult;
		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2, 2), this->wsaData);
		if (iResult != 0) {
			this->lastCode = Enum::SocketCode::WSAStartupError;
			StringBuilder buffer;
			buffer += "WSAStartup failed with error: ";
			buffer += iResult;
			buffer += "\n";
			this->logger->logErrorClear(buffer.build());
		}
		else
			this->lastCode = Enum::SocketCode::WSAStartupOK;
	}
}
void LlanyLib::Basic::Objetos::Socket::getAddrInfo()
{
	if (this->lastCode == Enum::SocketCode::WSAStartupOK) {
		int iResult;

		ZeroMemory(this->hints, sizeof(*hints));
		hints->ai_family = AF_UNSPEC;
		hints->ai_socktype = SOCK_STREAM;
		hints->ai_protocol = IPPROTO_TCP;

		// Resolve the server address and port
		if(this->ipServer == nullptr)
			iResult = getaddrinfo(NULL, this->port->get(), this->hints, &this->result);
		else
			iResult = getaddrinfo(this->ipServer->get(), this->port->get(), this->hints, &this->result);

		if (iResult != 0) {
			this->lastCode = Enum::SocketCode::GetAddrInfoError;
			StringBuilder buffer;
			buffer += "getaddrinfo failed with error: ";
			buffer += iResult;
			buffer += "\n";
			this->logger->logErrorClear(buffer.build());
			WSACleanup();
		}
		else
			this->lastCode = Enum::SocketCode::GetAddrInfoOK;
	}
}

LlanyLib::Basic::Objetos::Socket::Socket(String* port) : Socket(port, "Socket"){}
LlanyLib::Basic::Objetos::Socket::Socket(String* port, char const* const className)
{
	this->port = port;
	this->wsaData = new WSAData();
	this->logger = new Logger(className);
	this->port = port;
	this->ipServer = nullptr;
	this->lastCode = Enum::SocketCode::NoCode;

	this->result = nullptr;
	this->ptr = nullptr;
	this->hints = new addrinfo();

	Socket::startData();
}
LlanyLib::Basic::Objetos::Socket::~Socket()
{
	delete this->logger;
	delete this->wsaData;
	delete this->hints;
	delete this->port;

	if (this->ipServer != nullptr)
		delete this->ipServer;
}
*/