#pragma once
#ifndef COOKIE_OBJECT_NET_HPP_
#define COOKIE_OBJECT_NET_HPP_

#ifdef __unix__
struct sockaddr_in;
#elif _WIN32
struct WSAData;
struct addrinfo;
#endif // __unix__




namespace LlanyLib {
	namespace Basic {
		namespace Enum { enum class SocketCode; }
		namespace Objetos {
			class Logger;
			class String;
		}
	}
	namespace Net {
		namespace Objetos {
			class ClientSocket
			{
				protected:
					Basic::Objetos::Logger* logger;
					Basic::Objetos::String* nombre;		// Nombre dado al servicio
					Basic::Objetos::String* port;
					Basic::Objetos::String* ipServer;	//Dejar a nullptr si se usa como cliente
					Basic::Enum::SocketCode lastCode;
					/// Variables dependientes del sistema
					#ifdef __unix__
					sockaddr_in* direccionIP;			// Estructura de la direccion ip del servidor/socket
					int socket_fd;						// Puerto de escucha (socket file descriptor)
					#elif _WIN32
					WSAData* wsaData;
					struct addrinfo;
					addrinfo* result;
					addrinfo* ptr;
					addrinfo* hints;
					#endif // __unix__
				public:
					#pragma region Constructores
					ClientSocket();
					//ClientSocket(String* port, char const* const className);
					~ClientSocket();
					#pragma endregion
			};
		}
	}
}
#endif // !COOKIE_OBJECT_NET_HPP_
