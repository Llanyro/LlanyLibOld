#pragma once
#ifndef CLIENT_SOCKET_OBJECT_HPP_
#define CLIENT_SOCKET_OBJECT_HPP_

#include "Socket.hpp"

struct WSAData;

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class ClientSocket : Socket
			{
				protected:
					void connect();


				public:
					ClientSocket(String* port);
					ClientSocket(String* port, char const* const className);
					~ClientSocket();

					void send(String* content) const;
			};
		}
	}
}
#endif // !CLIENT_SOCKET_OBJECT_HPP_
