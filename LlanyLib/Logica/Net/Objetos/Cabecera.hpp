#pragma once
#ifndef CABECERA_OBJECT_NET_HPP_
#define CABECERA_OBJECT_NET_HPP_

#include "../../Math/Libs/MathTypes.h"

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
			class Cabecera 
			{
				protected:
					int responseCode = 200;
					Basic::Objetos::String* response;
					Basic::Objetos::String* acessControlAllowOrigin;
					Basic::Objetos::String* serverName;
					Basic::Objetos::String* contentType; // if nullptr -> "text/html"
					Basic::Objetos::String* encodingType;// if nullptr -> "utf-8"
					LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie>* cookieList;
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* cabecerasExtras;
					Basic::Objetos::String* contenido;
					Basic::Objetos::String* upgrade;
					Basic::Objetos::String* connection;
					Basic::Objetos::Date* date;
				public:
					#pragma region Getters
					int getResponseCode() const;
					const Basic::Objetos::String* getResponse() const;
					const Basic::Objetos::String* getAcessControlAllowOrigin() const;
					const Basic::Objetos::String* getServerName() const;
					const Basic::Objetos::String* getContentType() const;
					size_t getContentLength() const;
					const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie*>* getCookieList() const;
					const Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* getCabecerasExtras() const;
					const Basic::Objetos::String* getUpgrade() const;
					const Basic::Objetos::String* getConnection() const;
					#pragma endregion
					#pragma region Setters
					void setResponseCode(const int& responseCode);

					void setResponse(char const* const reason);
					void setResponse(Basic::Objetos::String* reason);

					void setResponse(const int& responseCode, char const* const reason);
					void setResponse(const int& responseCode, Basic::Objetos::String* reason);

					void setAcessControlAllowOrigin(char const* const reason);
					void setAcessControlAllowOrigin(Basic::Objetos::String* reason);

					void setServerName(char const* const serverName);
					void setServerName(Basic::Objetos::String* serverName);

					void setContentType(char const* const contentType);
					void setContentType(Basic::Objetos::String* contentType);

					void setContenido(char const* const contenido);
					void setContenido(Basic::Objetos::String* contenido);

					void setUpgrade(char const* const upgrade);
					void setUpgrade(Basic::Objetos::String* upgrade);

					void setConnection(char const* const upgrade);
					void setConnection(Basic::Objetos::String* upgrade);

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
#endif // !CABECERA_OBJECT_NET_HPP_
