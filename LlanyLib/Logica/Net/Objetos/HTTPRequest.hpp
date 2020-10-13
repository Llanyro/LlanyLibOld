#pragma once
#ifndef HTTP_REQUEST_OBJECT_NET_HPP_
#define HTTP_REQUEST_OBJECT_NET_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
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
					#pragma endregion
					#pragma region Setters
					void setPeticion(const Basic::Objetos::String* petition) const;
					void setRoot(const Basic::Objetos::String* root) const;
					void setVersion(const Basic::Objetos::String* version) const;
					void setHost(const Basic::Objetos::String* host) const;
					void setConnection(const Basic::Objetos::String* connection) const;
					void setUpgradeInsecureRequests(const bool& upgrade) const;
					#pragma endregion

			};
		}
	}
}
#endif // !HTTP_REQUEST_OBJECT_NET_HPP_

