#pragma once
#ifndef HTTP_REQUEST_OBJECT_NET_HPP_
#define HTTP_REQUEST_OBJECT_NET_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class Stringictionary;
		}
	}
	namespace Net {
		namespace Objetos {
			class HttpRequest
			{
				protected:
					Basic::Objetos::String* peticion;	// GET,POST,OPTIONS
					Basic::Objetos::String* root;		// "/", "/index", ...
					Basic::Objetos::String* version;	// HTTP/1.1
					Basic::Objetos::String* host;		// localhost:8080
					Basic::Objetos::String* connection;	// keep-alive
					bool upgrade_insecure_requests;		// 0 o 1
					Basic::Objetos::Stringictionary* headers;
					Basic::Objetos::Stringictionary* parametros;
				public:
					HttpRequest();
					~HttpRequest();
					#pragma region Getters
					const Basic::Objetos::String* getPeticion() const;
					const Basic::Objetos::String* getRoot() const;
					const Basic::Objetos::String* getVersion() const;
					const Basic::Objetos::String* getHost() const;
					const Basic::Objetos::String* getConnection() const;
					bool getUpgradeInsecureRequests() const;
					const Basic::Objetos::Stringictionary* getParametros() const;
					const Basic::Objetos::Stringictionary* getHeaders() const;
					#pragma endregion
					#pragma region Setters
					void setPeticion(Basic::Objetos::String* petition);
					void setRoot(Basic::Objetos::String* root);
					void setVersion(Basic::Objetos::String* version);
					void setHost(Basic::Objetos::String* host);
					void setConnection(Basic::Objetos::String* connection);
					void setUpgradeInsecureRequests(const bool& upgrade);
					void addParametro(Basic::Objetos::String* key, Basic::Objetos::String* value);
					void addHeader(Basic::Objetos::String* key, Basic::Objetos::String* value);
					#pragma endregion

			};
		}
	}
}
#endif // !HTTP_REQUEST_OBJECT_NET_HPP_

