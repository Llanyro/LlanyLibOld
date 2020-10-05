#include "Server.hpp"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <Ws2tcpip.h>
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#elif __unix__
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#endif

#define RED AF_INET


#include "../../Basic/Objetos/Logger.hpp"
#include "../../Basic/Objetos/String.hpp"

#pragma region Protected
#pragma region Constructores
LlanyLib::Net::Iterface::Server::Server(char const* const serverName) : Server(serverName, "localhost") {}
LlanyLib::Net::Iterface::Server::Server(char const* const serverName, char const* const ipServer)
{
	this->logger = new Basic::Objetos::Logger(serverName);
	this->nombre = new Basic::Objetos::String(serverName);
	this->port = nullptr;
	this->ipServer = nullptr;
	this->lastCode = 0;
	this->direccionIP = new sockaddr_in();
	this->socket_fd = -1;
}
LlanyLib::Net::Iterface::Server::~Server()
{
	if(this->logger != nullptr) delete this->logger;
	if(this->nombre != nullptr) delete this->nombre;
	if(this->port != nullptr) delete this->port;
	if(this->ipServer != nullptr) delete this->ipServer;
	if(this->direccionIP != nullptr) delete this->direccionIP;
	
	this->logger = nullptr;
	this->nombre = nullptr;
	this->port = nullptr;
	this->ipServer = nullptr;
	this->lastCode = 0;
	this->direccionIP = nullptr;
	this->socket_fd = -1;
}
void LlanyLib::Net::Iterface::Server::clearServicio()
{

}
#pragma endregion

#pragma endregion


