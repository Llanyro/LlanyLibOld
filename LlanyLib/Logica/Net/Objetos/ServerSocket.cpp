#include "ServerSocket.hpp"

//#include "../../Basic/Singletons/Chars.hpp"
#include "../../Basic/Singletons/ValueToString.hpp"

#include "../../Basic/Objetos/Logger.hpp"
#include "../../Basic/Objetos/String.hpp"


#include "../Headers/SocketsHeaders.hpp"

#include "../Enums/SocketEnum.hpp"

#include "ConnectionSocket.hpp"

#define SERVER_SIN_NOMBRE "NoNameServer"

#pragma region Private
void LlanyLib::Net::Objetos::ServerSocket::completarClase()
{
	this->lastCode = Enum::SocketCode::NoCode;

	#ifdef __unix__
	sockaddr_in* direccionIP = new sockaddr_in();
	int socket_fd = -1;
	ServerSocket::iniciarSocketUnix();
	#elif _WIN32
	this->iResult = 0;
	this->wsaData = new WSAData();
	this->result = nullptr;
	this->hints = new addrinfo();
	this->listenSocket = INVALID_SOCKET;
	this->responseSocket = INVALID_SOCKET;
	ServerSocket::iniciarSocketWin32();
	#endif // __unix__
}
#ifdef __unix__
void LlanyLib::Net::Objetos::ServerSocket::iniciarSocketUnix()
{
	ServerSocket::crearSocket();
	if (this->lastCode == Enum::SocketCode::NoCode) {
		ServerSocket::obtenerPuerto();
		ServerSocket::bindSocket();
		if (this->lastCode == Enum::SocketCode::NoCode) {
			ServerSocket::escucharSocket();
			if (this->lastCode == Enum::SocketCode::NoCode)
				this->lastCode = Enum::SocketCode::IniciadoCorrectamente;
		}
	}
}
void LlanyLib::Net::Objetos::ServerSocket::crearSocket()
{
	// Creamos un socket
	this->socket_fd = socket(RED, SOCK_STREAM, 0);
	if (this->socket_fd < 0)
		this->lastCode = Enum::SocketCode::ErrorSocketNoDisponible;
}
void LlanyLib::Net::Objetos::ServerSocket::obtenerPuerto()
{
	// Iniciamos el socket en el puerto 8080
	char option = 1;
	setsockopt(this->socket_fd, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), &option, sizeof(option));
}
void LlanyLib::Net::Objetos::ServerSocket::bindSocket()
{
	// Creamos una estructura con el puerto de escucha
	this->direccionIP->sin_family = RED;
	this->direccionIP->sin_addr.s_addr = INADDR_ANY;
	this->direccionIP->sin_port = htons(this->port_unix);

	// Asignamos el socket al puerto de la estructura creada
	if (bind(this->socket_fd, (struct sockaddr*)this->direccionIP, sizeof(*this->direccionIP)) < 0)
		this->lastCode = Enum::SocketCode::ErrorOnBinding;
}
void LlanyLib::Net::Objetos::ServerSocket::escucharSocket()
{
	// Empezamos a escuchar el puerto
	if (listen(this->socket_fd, 3) < 0)
		this->lastCode = Enum::SocketCode::ErrorNoEscuchando;
}
#elif _WIN32
void LlanyLib::Net::Objetos::ServerSocket::iniciarSocketWin32()
{
	ServerSocket::WSADataStartup();
	if (this->lastCode == Enum::SocketCode::NoCode) {
		ServerSocket::vaciarHints();
		ServerSocket::resolverIPServerYPuerto();
		if (this->lastCode == Enum::SocketCode::NoCode) {
			ServerSocket::crearSocketEscucha();
			if (this->lastCode == Enum::SocketCode::NoCode) {
				ServerSocket::setTCPSocket();
				if (this->lastCode == Enum::SocketCode::NoCode) {
					ServerSocket::escucharSocket();
					if (this->lastCode == Enum::SocketCode::NoCode)
						this->lastCode = Enum::SocketCode::IniciadoCorrectamente;
				}
			}
		}
	}
}
void LlanyLib::Net::Objetos::ServerSocket::WSADataStartup()
{
	// Initialize Winsock
	this->iResult = WSAStartup(MAKEWORD(2, 2), this->wsaData);
	if (this->iResult != 0)
		this->lastCode = Enum::SocketCode::WSAStartupError;
}
void LlanyLib::Net::Objetos::ServerSocket::vaciarHints()
{
	ZeroMemory(this->hints, sizeof(*this->hints));
	this->hints->ai_family = AF_INET;
	this->hints->ai_socktype = SOCK_STREAM;
	this->hints->ai_protocol = IPPROTO_TCP;
	this->hints->ai_flags = AI_PASSIVE;
}
void LlanyLib::Net::Objetos::ServerSocket::resolverIPServerYPuerto()
{
	// Resolve the server address and port
	this->iResult = getaddrinfo(NULL, this->port_win32->get(), this->hints, &this->result);
	//iResult = getaddrinfo(this->ipServer->get(), this->port_win32->get(), this->hints, &this->result);
	if (this->iResult != 0) {
		this->lastCode = Enum::SocketCode::GetAddrInfoError;
		WSACleanup();
	}
}
void LlanyLib::Net::Objetos::ServerSocket::crearSocketEscucha()
{
	// Create a SOCKET for connecting to server
	this->listenSocket = socket(this->result->ai_family, this->result->ai_socktype, this->result->ai_protocol);
	if (listenSocket == INVALID_SOCKET) {
		this->lastCode = Enum::SocketCode::ErrorPuertoEscucha;
		freeaddrinfo(this->result);
		WSACleanup();
	}
}
void LlanyLib::Net::Objetos::ServerSocket::setTCPSocket()
{
	// Setup the TCP listening socket
	this->iResult = bind(this->listenSocket, this->result->ai_addr, (int)this->result->ai_addrlen);
	if (this->iResult == SOCKET_ERROR) {
		this->lastCode = Enum::SocketCode::ErrorOnBinding;
		freeaddrinfo(this->result);
		closesocket(this->listenSocket);
		WSACleanup();
	}
	else freeaddrinfo(this->result);
}
void LlanyLib::Net::Objetos::ServerSocket::escucharSocket()
{
	this->iResult = listen(this->listenSocket, SOMAXCONN);
	if (this->iResult == SOCKET_ERROR) {
		this->lastCode = Enum::SocketCode::ErrorNoEscuchando;
		closesocket(this->listenSocket);
		WSACleanup();
	}
}
#endif // __unix__
#pragma endregion
#pragma region Constructores
LlanyLib::Net::Objetos::ServerSocket::ServerSocket(char const* const port_win32) : ServerSocket(SERVER_SIN_NOMBRE, port_win32) {}
LlanyLib::Net::Objetos::ServerSocket::ServerSocket(const unsigned short& port_unix) : ServerSocket(SERVER_SIN_NOMBRE, port_unix){}
LlanyLib::Net::Objetos::ServerSocket::ServerSocket(char const* const serverName, char const* const port_win32)
{
	this->logger = new Basic::Objetos::Logger(serverName);
	this->nombre = new Basic::Objetos::String(serverName);
	this->port_win32 = new Basic::Objetos::String(port_win32);
	this->port_unix = this->port_win32->toUnsignedShort();
	ServerSocket::completarClase();
}
LlanyLib::Net::Objetos::ServerSocket::ServerSocket(char const* const serverName, const unsigned short& port_unix)
{
	this->logger = new Basic::Objetos::Logger(serverName);
	this->nombre = new Basic::Objetos::String(serverName);
	this->port_win32 = VALUE_2_STRING->toString(port_unix);
	this->port_unix = port_unix;
	ServerSocket::completarClase();
}
LlanyLib::Net::Objetos::ServerSocket::~ServerSocket()
{
	if (this->logger != nullptr) delete this->logger;
	if (this->nombre != nullptr) delete this->nombre;
	if (this->port_win32 != nullptr) delete this->port_win32;

	this->logger = nullptr;
	this->nombre = nullptr;
	this->port_win32 = nullptr;
	this->port_unix = 0;
	this->lastCode = Enum::SocketCode::NoCode;

	#ifdef __unix__
	if (this->direccionIP != nullptr) delete this->direccionIP;
	this->direccionIP = nullptr;
	int socket_fd = -1;
	#elif _WIN32
	if (this->wsaData != nullptr) delete this->wsaData;
	//if (this->result != nullptr) delete this->result;
	if (this->hints != nullptr) delete this->hints;
	this->wsaData = nullptr;
	//this->result = nullptr;
	this->hints = nullptr;
	#endif // __unix__
}
#pragma endregion
#pragma region Getters
#ifdef __unix__

#elif _WIN32
LlanyLib::Net::Objetos::ConnectionSocket* LlanyLib::Net::Objetos::ServerSocket::getConnectionSocket()
{
	ConnectionSocket* s = new ConnectionSocket(this->listenSocket, this->responseSocket);
	this->responseSocket = INVALID_SOCKET;
	return s;
}
#endif // __unix__
LlanyLib::Net::Enum::SocketCode LlanyLib::Net::Objetos::ServerSocket::getLastCode() const
{
	return this->lastCode;
}
bool LlanyLib::Net::Objetos::ServerSocket::acceptClient()
{
	// Accept a client socket
	bool resultado = true;
	this->responseSocket = accept(this->listenSocket, NULL, NULL);
	if (this->responseSocket == INVALID_SOCKET) {
		this->lastCode = Enum::SocketCode::ErrorAceptarCliente;
		closesocket(this->listenSocket);
		WSACleanup();
		resultado = false;
	}
	return resultado;
}
#pragma endregion
