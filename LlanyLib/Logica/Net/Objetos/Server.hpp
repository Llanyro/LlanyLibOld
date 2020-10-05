#pragma once
#ifndef SERVER_INTERFACE_NET_HPP_
#define SERVER_INTERFACE_NET_HPP_

struct sockaddr_in;

namespace LlanyLib {
	namespace Basic {
		namespace Enum { enum class SocketCode; }
		namespace Objetos {
			class Logger;
			class String;
		}
	}
	namespace Net {
		namespace Iterface {
			class Server
			{
				protected:
					Basic::Objetos::Logger* logger;
					Basic::Objetos::String* nombre;		// Nombre dado al servicio
					Basic::Objetos::String* port;
					Basic::Objetos::String* ipServer;	//Dejar a nullptr si se usa como cliente
					Basic::Enum::SocketCode lastCode;

					sockaddr_in* direccionIP;			// Estructura de la direccion ip del servidor/socket
					int socket_fd;						// Puerto de escucha (socket file descriptor)
				protected:
					#pragma region Constructores
					Server(char const* const serverName);
					Server(char const* const serverName, char const* const ipServer);
					~Server();
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
					Basic::Objetos::String* resolverSolicitudClear(const Basic::Objetos::String& solicitud) const;
					#pragma endregion
					#pragma region Funciones del servicio virtuales
					virtual Basic::Objetos::String* leerSocket(const int& newsock_fd) const;
					virtual Basic::Objetos::String* resolverSolicitud(const Basic::Objetos::String& solicitud) const;
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
					bool iniciarServicio(char const* const nombre, const unsigned short& puertoEscucha);
					bool iniciarServicio(const unsigned short& puertoEscucha);
					bool iniciarServicio();
					#pragma endregion
					#pragma region Funciones del servicio virtuales
					virtual bool getServicioIniciado() const;
					#pragma endregion
					#pragma region Getters
					const Basic::Objetos::String* getNombreServicio() const;
					#pragma endregion
					#pragma region Setters
					void setNombreServicio(char const* const nuevoNombre);
					#pragma endregion
			};
		}
	}
}
#endif // !SERVER_INTERFACE_NET_HPP_
