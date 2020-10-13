#include "Socket.hpp"


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

/*
List<Servicio::EstadoServicio> Servicio::iniciarServicio(const String& nombre, const unsigned short& puertoEscucha)
{
	assert(&nombre != nullptr);
	assert(&puertoEscucha != nullptr);

	List<EstadoServicio> estadoServidor;

	// Si el servicio no esta inicializado
	if (!this->servicioIniciado)
	{
		#pragma region Seleccion de puerto
		// Creamos un socket
		this->socket_fd = socket(RED, SOCK_STREAM, 0);
		if (this->socket_fd < 0)
			estadoServidor.add(EstadoServicio::ErrorSocketNoDisponible);

		// Iniciamos el socket en el puerto 8080
		char option = 1;
		#ifdef _WIN32
		setsockopt(this->socket_fd, SOL_SOCKET, SO_BROADCAST, &option, sizeof(option));
		#elif __unix__
		setsockopt(this->socket_fd, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), &option, sizeof(option));
		#endif

		// Creamos una estructura con el puerto de escucha
		this->direccionIP->sin_family = RED;
		this->direccionIP->sin_addr.s_addr = INADDR_ANY;
		this->direccionIP->sin_port = htons(puertoEscucha);

		// Asignamos el socket al puerto de la estructura creada
		if (bind(this->socket_fd, (struct sockaddr*)this->direccionIP, sizeof(*this->direccionIP)) < 0)
			estadoServidor.add(EstadoServicio::ErrorOnBinding);

		// Empezamos a escuchar el puerto
		if (listen(this->socket_fd, 3) < 0)
			estadoServidor.add(EstadoServicio::ErrorNoEscuchando);
		#pragma endregion

		// Si hasta aqui no hay errores completamos la clase
		if (estadoServidor.getCount() == 0)
		{
			estadoServidor.add(EstadoServicio::Iniciado);
			this->servicioIniciado = true;
			// Nombre del servidor
			this->nombre->operator=(nombre);
		}
		// Si no, limpiamos los cambios
		else
			Servicio::clearServicio();
	}
	else
		estadoServidor.add(EstadoServicio::Iniciado);
	return estadoServidor;
}
*/

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




#pragma once
template <class T>
class List;
class String;
struct sockaddr_in;

/*
	Se recomienda solo hacer servidores con esta clase en unix ya que usa fork y otros
		(En proceso -> V3)
	V2
	Padre o plantilla de todos los servicios
	Al heredar se pueden modificar las funciones a gusto
	No se puede usar la clase directamente como un servicio:
	es decir, hay que heredarla de otra clase que sea un singleton
	Pd: Esta clase no se debe de modificar
	Pd: Los sockets no estan testeado en windows, solo en unix
	Funciones sobrecargables:
	virtual bool getServicioIniciado() const;					->	Public
	virtual String leerSocket(const int& newsock_fd) const;		-> Protected
	virtual String resolverSolicitud(String& solicitud) const;	-> Protected
*/
class Servicio
{
	public:
		#pragma region Enums
		// Lista de estados al iniciar el servicio
		enum class EstadoServicio
		{
			Iniciado,
			AnteriormenteIniciado,


			// Errores
			ErrorSocketNoDisponible,
			ErrorOnBinding,
			ErrorNoEscuchando


		};
		#pragma endregion
	protected:
		String* nombre;				// Nombre dado al servicio
		sockaddr_in* direccionIP;	// Estructura de la direccion ip del servidor/socket
		int socket_fd;				// Puerto de escucha (socket file descriptor)
		bool servicioIniciado;		// Si se ha iniciado el servicio
	protected:
		#pragma region Constructores
		Servicio();
		~Servicio();
		void clearServicio();
		#pragma endregion
		#pragma region Funciones del servicio no virtuales
		// Funcion: Recibe un socket de escharSolicitudes(), lee la peticion y la envia a
		//		"resolverSolicitud(const String) const"
		// Extra: Envia el string que recibe de la funcion mencionada
		// Precondiciones:
		//		sea un socket real
		// Complejidad temporal y espacial: O(1) y M(1)
		void resolverSolicitud(const int& newsock_fd) const;
		// Funcion: Ignora el socket indicado sin leerlo
		// Extra: Es decir solo lo cierra (RST)
		// Precondiciones:
		//		sea un socket real
		// Complejidad temporal y espacial: O(1) y M(1)
		void ignorarSolicitud(const int& newsock_fd) const;
		#pragma endregion
		#pragma region Funciones del servicio virtuales
		virtual String leerSocket(const int& newsock_fd) const;
		virtual String resolverSolicitud(String& solicitud) const;
		#pragma endregion
	public:
		#pragma region Funciones del servicio no virtuales
		// Funcion: Se queda a la espera de que se reciba una solicitud
		// Extra: Al recibir una solicitud la resuelve
		// Extra 2: Se mantiene en bucle si se pide
		// Complejidad temporal y espacial: O(1) y M(1)
		void escharSolicitudes(const bool& bucle) const;
		// Funcion: Inicia el servicio con unos parametros indicados
		// Retorno: El estado de iniciar el servicio
		// Complejidad temporal y espacial: O(1) y M(1)
		List<EstadoServicio> iniciarServicio(
			const String& nombre,
			const unsigned short& puertoEscucha);
		List<EstadoServicio> iniciarServicio(const unsigned short& puertoEscucha);
		List<EstadoServicio> iniciarServicio();
		#pragma endregion
		#pragma region Funciones del servicio virtuales
		virtual bool getServicioIniciado() const;
		#pragma endregion
		#pragma region Getters
		String getNombreServicio(void) const;
		#pragma endregion
		#pragma region Setters
		void setNombreServicio(const String& nuevoNombre);
		#pragma endregion
};
