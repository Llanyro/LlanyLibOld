#pragma once
#ifndef HTTP_RESPONSE_OBJECT_NET_HPP_
#define HTTP_RESPONSE_OBJECT_NET_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class Date;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
	}
	namespace Net {
		namespace Objetos {
			class Cookie;
			class HttpResponse
			{
				protected:												// Default
					/// Respuesta
					int responseCode;									// 200
					Basic::Objetos::String* response;					// OK
					
					/// Datos del servicio
					Basic::Objetos::String* acessControlAllowOrigin;	// None o *
					Basic::Objetos::String* serverName;					// None
					Basic::Objetos::String* upgrade;					// 
					Basic::Objetos::String* connection;					// 
					Basic::Objetos::Date* date;							// 

					/// Contenido
					Basic::Objetos::String* content;
					Basic::Objetos::String* contentType;				// if nullptr -> "text/html"
					Basic::Objetos::String* encodingType;				// if nullptr -> "utf-8"

					/// Cookies
					LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie*>* cookieList;

					/// Extras
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* cabecerasExtras;
				public:
					HttpResponse();
					~HttpResponse();
					#pragma region Getters
					/// Respuesta
					int getResponseCode() const;
					const Basic::Objetos::String* getResponse() const;

					/// Datos del servicio
					const Basic::Objetos::String* getAcessControlAllowOrigin() const;
					const Basic::Objetos::String* getServerName() const;
					const Basic::Objetos::String* getUpgrade() const;
					const Basic::Objetos::String* getConnection() const;
					const Basic::Objetos::Date* getDate() const;

					/// Contenido
					const Basic::Objetos::String* getContent() const;
					const Basic::Objetos::String* getContentType() const;
					const Basic::Objetos::String* getEncodingType() const;
					size_t getContentLength() const;

					/// Cookies
					const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie*>* getCookieList() const;

					/// Extras
					const Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* getCabecerasExtras() const;
					#pragma endregion
					#pragma region Setters
					/// Respuesta
					void setResponseCode(const int& responseCode);
					void setResponse(char const* const reason);
					void setResponse(Basic::Objetos::String* reason);
					void setResponse(const int& responseCode, char const* const reason);
					void setResponse(const int& responseCode, Basic::Objetos::String* reason);
					
					/// Datos del servicio
					void setAcessControlAllowOrigin(char const* const control);
					void setAcessControlAllowOrigin(Basic::Objetos::String* control);
					void setServerName(char const* const serverName);
					void setServerName(Basic::Objetos::String* serverName);
					void setUpgrade(char const* const upgrade);
					void setUpgrade(Basic::Objetos::String* upgrade);
					void setConnection(char const* const connection);
					void setConnection(Basic::Objetos::String* connection);
					void setDate(Basic::Objetos::Date* date);
					void setDate();

					/// Contenido
					void setContent(char const* const contenido);
					void setContent(Basic::Objetos::String* contenido);
					void setContentType(char const* const contentType);
					void setContentType(Basic::Objetos::String* contentType);
					void setEncodingType(char const* const encodingType);
					void setEncodingType(Basic::Objetos::String* encodingType);

					void setFechaExpiracionNow();
					#pragma endregion
					#pragma region Adders
					void addCookie(Cookie cookie);

					void addCookie(char const* const key, char const* const value);
					void addCookie(Basic::Objetos::String* key, char const* const value);
					void addCookie(char const* const key, Basic::Objetos::String* value);
					void addCookie(Basic::Objetos::String* key, Basic::Objetos::String* value);

					void addCabeceraExtra(char const* const cabecera);
					void addCabeceraExtra(Basic::Objetos::String* cabecera);
					#pragma endregion
					#pragma region Remove
					void removeCabeceraExtra(const size_t& pos);
					void removeCookie(const size_t& pos);
					void removeFechaExpiracion();
					#pragma endregion
					Basic::Objetos::String* toString() const;
			};
		}
	}
}
#endif // !HTTP_RESPONSE_OBJECT_NET_HPP_
