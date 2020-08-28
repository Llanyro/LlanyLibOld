#pragma once
#ifndef COOKIE_OBJECT_NET_HPP_
#define COOKIE_OBJECT_NET_HPP_

#include "../../Math/Libs/MathTypes.h"

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class Date;
		}
		namespace Enum { enum class DateType; }
	}
	namespace Net {
		namespace Objetos {
			class Cookie
			{
				protected:
					Basic::Objetos::String* key;
					Basic::Objetos::String* value;
					Basic::Objetos::Date* fechaExpiracion;
					bool seguro;
					bool httponly;
					Basic::Objetos::String* dominio;
					Basic::Objetos::String* path;
				public:
					#pragma region Constructores
					Cookie();
					Cookie(Basic::Objetos::String* key, Basic::Objetos::String* value);
					Cookie(char const* const key, char const* const value);
					Cookie(Basic::Objetos::String* key, char const* const value);
					Cookie(char const* const key, Basic::Objetos::String* value);
					~Cookie();
					#pragma endregion
					#pragma region Getters
					const Basic::Objetos::String* getKey() const;
					const Basic::Objetos::String* getValue() const;
					const Basic::Objetos::Date* getFechaExpiracion() const;
					bool getSeguro() const;
					bool getHTTPOnly() const;
					const Basic::Objetos::String* getDominio() const;
					const Basic::Objetos::String* getPath() const;
					#pragma endregion
					#pragma region Setters
					void setCookie(Basic::Objetos::String* key, Basic::Objetos::String* value);
					void setCookie(char const* const key, char const* const value);
					void setCookie(Basic::Objetos::String* key, char const* const value);
					void setCookie(char const* const key, Basic::Objetos::String* value);

					void setKey(Basic::Objetos::String* key);
					void setValue(Basic::Objetos::String* value);
					void setFechaExpiracion(Basic::Objetos::Date* fechaExpiracion);
					void setDominio(Basic::Objetos::String* dominio);
					void setPath(Basic::Objetos::String* path);

					void setKey(char const* const key);
					void setValue(char const* const value);
					void setFechaExpiracion(const long_t& value, const Basic::Enum::DateType& type);
					void setDominio(char const* const dominio);
					void setPath(char const* const path);

					void setSeguro(const bool& seguro);
					void setHTTPOnly(const bool& httponly);
					#pragma endregion
					#pragma region Comparadores
					bool equals(const Cookie& c) const;
					bool equals(const Basic::Objetos::String* key, const Basic::Objetos::String* value) const;
					bool equals(const Basic::Objetos::String* key) const;
					bool equals(char const* const key, char const* const value) const;
					bool equals(char const* const key) const;
					#pragma endregion
					Basic::Objetos::String* toString() const;
			};
		}
	}
}
#endif // !COOKIE_OBJECT_NET_HPP_
