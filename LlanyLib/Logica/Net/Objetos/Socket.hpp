#pragma once
#ifndef SOCKET_OBJECT_HPP_
#define SOCKET_OBJECT_HPP_

#include "../../Basic/LibreriasSimples/LlanyTypes.h"



template <class T>
class List;
class String;

namespace LeerSocket
{
	// Funcion: Lee una peticion recibida en un socket
	// Precondiciones:
	//		el socket debe de existir
	// Retorno: Peticion leida
	// Complejidad temporal y espacial: O(1) y M(1)
	String leerSocket(const int& nuevoSocket, const char& finalDelMensaje);
	String leerSocket(const int& nuevoSocket, const size_t& sizeMensaje, bool na);
	List<String> leerSocketHTML(const int& nuevoSocket);
	String errorSocket();
}



/*#ifdef _WIN32
struct WSAData;
struct addrinfo;

namespace LlanyLib {
	namespace Basic {
		namespace Enum { enum class SocketCode; }
		namespace Objetos {
			class String;
			class JSONBuilder;
			class Logger;
			class Socket
			{
				protected:
					Logger* logger;
					String* port;
					String* ipServer;//Dejar a nullptr si se usa como cliente
					WSAData* wsaData;
					Enum::SocketCode lastCode;
					addrinfo* result;
					addrinfo* ptr;
					addrinfo* hints;


				protected:
					void startData();
					void getAddrInfo();
				public:
					Socket(String* port);
					Socket(String* port, char const* const className);
					~Socket();
			};
		}
	}
}
#elif __unix__
*/
namespace LlanyLib {
	namespace Basic {
		namespace Enum { enum class SocketCode; }
		namespace Objetos {
			class String;
			class JSONBuilder;
			class Logger;
			class Socket
			{
				protected:
					Logger* logger;
					String* port;
					String* ipServer;			//Dejar a nullptr si se usa como cliente
					WSAData* wsaData;
					Enum::SocketCode lastCode;
					addrinfo* result;
					addrinfo* ptr;
					addrinfo* hints;
				protected:
					void startData();
					void getAddrInfo();
				public:
					Socket(String* port);
					Socket(String* port, char const* const className);
					~Socket();
			};
		}
	}
}
#endif // __WIN32
#endif // !SOCKET_OBJECT_HPP_
