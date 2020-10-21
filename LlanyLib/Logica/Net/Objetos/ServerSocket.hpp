#pragma once
#ifndef SERVER_SOCKET_OBJECT_NET_HPP_
#define SERVER_SOCKET_OBJECT_NET_HPP_

//#define __unix__
//#define SO_REUSEPORT 0x004

#ifdef __unix__
struct sockaddr_in;
#elif _WIN32
struct WSAData;
struct addrinfo;
#endif // __unix__

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class Logger;
			class String;
		}
	}
	namespace Net {
		namespace Enum {
			enum class SocketCode;
			enum class ReadSocketType;
		}
		namespace Objetos {
			class ConnectionSocket;
			class ServerSocket
			{
				protected:
					Basic::Objetos::Logger* logger;
					Basic::Objetos::String* nombre;		// Nombre dado al servicio
					Basic::Objetos::String* port_win32;
					unsigned short port_unix;
					Enum::SocketCode lastCode;
					/// Variables dependientes del sistema
					#ifdef __unix__
					sockaddr_in* direccionIP;			// Estructura de la direccion ip del servidor/socket
					int socket_fd;						// Puerto de escucha (socket file descriptor)
					#elif _WIN32
					int iResult;
					WSAData* wsaData;
					addrinfo* result;
					addrinfo* hints;
					unsigned int listenSocket;
					unsigned int responseSocket;
					#endif // __unix__
				private:
					void completarClase();
					#ifdef __unix__
					void iniciarSocketUnix();
					void crearSocket();
					void obtenerPuerto();
					void bindSocket();
					void escucharSocket();
					#elif _WIN32
					void iniciarSocketWin32();
					void WSADataStartup();
					void vaciarHints();
					void resolverIPServerYPuerto();
					void crearSocketEscucha();
					void setTCPSocket();
					void escucharSocket();
					#endif // __unix__
				public:
					#pragma region Constructores
					ServerSocket(char const* const port_win32);
					ServerSocket(const unsigned short& port_unix);
					ServerSocket(char const* const serverName, char const* const port_win32);
					ServerSocket(char const* const serverName, const unsigned short& port_unix);
					~ServerSocket();
					#pragma endregion
					#pragma region Getters
					#ifdef __unix__

					#elif _WIN32
					ConnectionSocket* getConnectionSocket();
					#endif // __unix__
					Enum::SocketCode getLastCode() const;
					bool acceptClient();
					#pragma endregion
					//Basic::Objetos::String* readAll(const Enum::ReadSocketType& mode) const;
					//Basic::Objetos::String* readAll() const;
					//Basic::Objetos::String* read(const size_t& caracteres) const;
					//char readChar() const;
					//void write(const Basic::Objetos::String* contenido) const;
					//void writeClear(Basic::Objetos::String* contenido) const;
			};
		}
	}
}
#endif // !SERVER_SOCKET_OBJECT_NET_HPP_
