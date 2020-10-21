#include "ConnectionSocket.hpp"

LlanyLib::Net::Objetos::ConnectionSocket::ConnectionSocket()
{
	this->listenSocket = 0;
	this->responseSocket = 0;
}
LlanyLib::Net::Objetos::ConnectionSocket::ConnectionSocket(const unsigned int& listenSocket, const unsigned int& responseSocket)
{
	this->listenSocket = listenSocket;
	this->responseSocket = responseSocket;
}
LlanyLib::Net::Objetos::ConnectionSocket::~ConnectionSocket(){}
unsigned int LlanyLib::Net::Objetos::ConnectionSocket::getListenSocket() const
{
	return this->listenSocket;
}
unsigned int LlanyLib::Net::Objetos::ConnectionSocket::getResponseSocket() const
{
	return this->responseSocket;
}
void LlanyLib::Net::Objetos::ConnectionSocket::setListenSocket(const unsigned int& listenSocket)
{
	this->listenSocket = listenSocket;
}
void LlanyLib::Net::Objetos::ConnectionSocket::setResponseSocket(const unsigned int& responseSocket)
{
	this->responseSocket = responseSocket;
}
