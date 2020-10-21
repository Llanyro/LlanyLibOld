#pragma once
#ifndef SOCKET_CONTROLLER_SINGLETON_NET_HPP_
#define SOCKET_CONTROLLER_SINGLETON_NET_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define SOCKET_CONTROLLER LlanyLib::Net::Singletons::SocketController::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
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
			//class ServerSocket;
			class HttpRequest;
			class HttpResponse;
			class ConnectionSocket;
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
					#pragma region HTTP
					void getPetition(Objetos::HttpRequest* request, const Objetos::ConnectionSocket* connection) const;
					void getKnownHeaders(Objetos::HttpRequest* request, const Objetos::ConnectionSocket* connection) const;
					void getAllHeaders(Objetos::HttpRequest* request, const Objetos::ConnectionSocket* connection) const;

					Objetos::HttpRequest* getHttpRequestPetition(const Objetos::ConnectionSocket* connection) const;
					Objetos::HttpRequest* getHttpRequestPostContent(const Objetos::ConnectionSocket* connection) const;
					Objetos::HttpRequest* getHttpRequestFast(const Objetos::ConnectionSocket* connection) const;
					Objetos::HttpRequest* getHttpRequestSlow(const Objetos::ConnectionSocket* connection) const;
					Objetos::HttpRequest* getHttpRequestFull(const Objetos::ConnectionSocket* connection) const;

					void sendHttpFileProtected(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const root, char const* const file) const;
					void sendHttpFileProtected(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const root, const Basic::Objetos::String* file) const;
					#pragma endregion
				public:
					void printTest(const Objetos::ConnectionSocket* connection) const;
					void shitSend(const Objetos::ConnectionSocket* connection) const;

					//Objetos::HTTPRequest* getHTTPRequest(const Objetos::ConnectionSocket* connection) const;
					//Objetos::HTTPRequest* getHTTPRequest(const Objetos::ConnectionSocket* connection, const Enum::ResponseProcess& processType) const;

					#pragma region HTTP
					Objetos::HttpRequest* getHttpRequest(const Objetos::ConnectionSocket* connection, const Enum::ResponseProcess& processType) const;
					void sendHttpResponse(const Objetos::ConnectionSocket* connection, const Objetos::HttpResponse* response) const;
					void sendHttpTemplate(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const file) const;
					void sendHttpTemplate(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, const Basic::Objetos::String* file) const;
					void sendHttpTemplateClear(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, Basic::Objetos::String* file) const;
					void sendHttpStatic(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, char const* const file) const;
					void sendHttpStatic(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, const Basic::Objetos::String* file) const;
					void sendHttpStaticClear(const Objetos::ConnectionSocket* connection, Objetos::HttpResponse* response, Basic::Objetos::String* file) const;
					#pragma endregion
					#pragma region All
					void sendMsg(const Objetos::ConnectionSocket* connection, const Basic::Objetos::String* msg) const;
					void sendMsgClear(const Objetos::ConnectionSocket* connection, Basic::Objetos::String* msg) const;
					void closeConnectionSocket(const Objetos::ConnectionSocket* connection) const;
					#pragma endregion
			};
		}
	}
}
#endif // !SOCKET_CONTROLLER_SINGLETON_NET_HPP_
