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
			class HttpRequest;
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
				protected:

					void getPetition(Objetos::HttpRequest* request, const Objetos::ServerSocket* serverSocket) const;
					void getKnownHeathers(Objetos::HttpRequest* request, const Objetos::ServerSocket* serverSocket) const;
					void getAllHeathers(Objetos::HttpRequest* request, const Objetos::ServerSocket* serverSocket) const;

					Objetos::HttpRequest* getHttpRequestPetition(const Objetos::ServerSocket* serverSocket);
					Objetos::HttpRequest* getHttpRequestPostContent(const Objetos::ServerSocket* serverSocket);
					Objetos::HttpRequest* getHttpRequestFast(const Objetos::ServerSocket* serverSocket);
					Objetos::HttpRequest* getHttpRequestSlow(const Objetos::ServerSocket* serverSocket);
					Objetos::HttpRequest* getHttpRequestFull(const Objetos::ServerSocket* serverSocket);

				public:
					void printTest(const Objetos::ServerSocket* serverSocket) const;
					void shitSend(const Objetos::ServerSocket* serverSocket) const;

					//Objetos::HTTPRequest* getHTTPRequest(const Objetos::ServerSocket* serverSocket) const;
					//Objetos::HTTPRequest* getHTTPRequest(const Objetos::ServerSocket* serverSocket, const Enum::ResponseProcess& processType) const;

					Objetos::HttpRequest* getHttpRequest(const Objetos::ServerSocket* serverSocket, const Enum::ResponseProcess& processType);

			};
		}
	}
}
#endif // !SOCKET_CONTROLLER_SINGLETON_NET_HPP_
