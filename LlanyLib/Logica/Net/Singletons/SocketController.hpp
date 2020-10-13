#pragma once
#ifndef SOCKET_CONTROLLER_SINGLETON_NET_HPP_
#define SOCKET_CONTROLLER_SINGLETON_NET_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define SOCKET_CONTROLLER LlanyLib::Net::Singletons::SocketController::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Diccionarios {
				template<class T1, class T2>
				class DictionaryLinkedList;
			}
		}
	}
	namespace Net {
		namespace Enum {
			enum class ResponseProcess;
		}
		namespace Objetos {
			class ServerSocket;
			class HTTPRequest;
		}
		namespace Singletons {
			class SocketController : public Basic::Templates::Singleton<SocketController>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<SocketController>;
					SocketController();
					~SocketController();
				#pragma endregion
				public:
					void printTest(const Objetos::ServerSocket* serverSocket) const;
					void shitSend(const Objetos::ServerSocket* serverSocket) const;

					Objetos::HTTPRequest* getHTTPRequest(const Objetos::ServerSocket* serverSocket) const;
					Objetos::HTTPRequest* getHTTPRequest(const Objetos::ServerSocket* serverSocket, const Enum::ResponseProcess& processType) const;


			};
		}
	}
}
#endif // !SOCKET_CONTROLLER_SINGLETON_NET_HPP_
