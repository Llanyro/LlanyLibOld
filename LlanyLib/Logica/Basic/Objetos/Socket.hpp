#pragma once
#ifndef SOCKET_OBJECT_HPP_
#define SOCKET_OBJECT_HPP_

#include "../LibreriasSimples/LlanyTypes.h"

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
#endif // !SOCKET_OBJECT_HPP_
