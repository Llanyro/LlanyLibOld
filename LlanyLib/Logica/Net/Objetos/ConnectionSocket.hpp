#pragma once
#ifndef CONNECTION_SOCKET_OBJECT_NET_HPP_
#define CONNECTION_SOCKET_OBJECT_NET_HPP_

namespace LlanyLib {
	namespace Net {
		namespace Objetos {
			class ConnectionSocket
			{
				protected:
					unsigned int listenSocket;
					unsigned int responseSocket;
				public:
					#pragma region Constructores
					ConnectionSocket();
					ConnectionSocket(const unsigned int& listenSocket, const unsigned int& responseSocket);
					~ConnectionSocket();
					#pragma endregion
					#pragma region Getters
					unsigned int getListenSocket() const;
					unsigned int getResponseSocket() const;
					#pragma endregion
					#pragma region Setters
					void setListenSocket(const unsigned int& listenSocket);
					void setResponseSocket(const unsigned int& responseSocket);
					#pragma endregion
			};
		}
	}
}
#endif // !CONNECTION_SOCKET_OBJECT_NET_HPP_
