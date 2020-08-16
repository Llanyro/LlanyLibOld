#include "Cookie.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"

#pragma region Constructores
LlanyLib::Net::Objetos::Cookie::Cookie()
{
	this->key = nullptr;
	this->value = nullptr;
	this->fechaExpiracion = nullptr;
	this->dominio = nullptr;
	this->path = nullptr;
	this->seguro = false;
	this->httponly = false;
}
LlanyLib::Net::Objetos::Cookie::Cookie(Basic::Objetos::String* key, Basic::Objetos::String* value) : Cookie()
{
	Cookie::setCookie(key, value);
}
LlanyLib::Net::Objetos::Cookie::Cookie(char const* const key, char const* const value) : Cookie()
{
	Cookie::setCookie(key, value);
}
LlanyLib::Net::Objetos::Cookie::Cookie(Basic::Objetos::String* key, char const* const value) : Cookie()
{
	Cookie::setCookie(key, value);
}
LlanyLib::Net::Objetos::Cookie::Cookie(char const* const key, Basic::Objetos::String* value) : Cookie()
{
	Cookie::setCookie(key, value);
}
LlanyLib::Net::Objetos::Cookie::~Cookie()
{
	Basic::Objetos::String* nu = nullptr;
	Cookie::setKey(nu);
	Cookie::setValue(nu);
	Cookie::setFechaExpiracion(nu);
	Cookie::setDominio(nu);
	Cookie::setPath(nu);
	this->seguro = false;
	this->httponly = false;
}
#pragma endregion
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::Cookie::getKey() const
{
	return this->key;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::Cookie::getValue() const
{
	return this->value;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::Cookie::getFechaExpiracion() const
{
	return this->fechaExpiracion;
}
bool LlanyLib::Net::Objetos::Cookie::getSeguro() const
{
	return this->seguro;
}
bool LlanyLib::Net::Objetos::Cookie::getHTTPOnly() const
{
	return this->httponly;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::Cookie::getDominio() const
{
	return this->dominio;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::Cookie::getPath() const
{
	return this->path;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Net::Objetos::Cookie::setCookie(Basic::Objetos::String* key, Basic::Objetos::String* value)
{
	Cookie::setKey(key);
	Cookie::setValue(value);
}
void LlanyLib::Net::Objetos::Cookie::setCookie(char const* const key, char const* const value)
{
	Cookie::setKey(key);
	Cookie::setValue(value);
}
void LlanyLib::Net::Objetos::Cookie::setCookie(Basic::Objetos::String* key, char const* const value)
{
	Cookie::setKey(key);
	Cookie::setValue(value);
}
void LlanyLib::Net::Objetos::Cookie::setCookie(char const* const key, Basic::Objetos::String* value)
{
	Cookie::setKey(key);
	Cookie::setValue(value);
}
void LlanyLib::Net::Objetos::Cookie::setKey(Basic::Objetos::String* key)
{
	if (this->key != nullptr)
		delete this->key;
	this->key = key;
}
void LlanyLib::Net::Objetos::Cookie::setValue(Basic::Objetos::String* value)
{
	if (this->value != nullptr)
		delete this->value;
	this->value = value;
}
void LlanyLib::Net::Objetos::Cookie::setFechaExpiracion(Basic::Objetos::String* fechaExpiracion)
{
	if (this->fechaExpiracion != nullptr)
		delete this->fechaExpiracion;
	this->fechaExpiracion = fechaExpiracion;
}
void LlanyLib::Net::Objetos::Cookie::setDominio(Basic::Objetos::String* dominio)
{
	if (this->dominio != nullptr)
		delete this->dominio;
	this->dominio = dominio;
}
void LlanyLib::Net::Objetos::Cookie::setPath(Basic::Objetos::String* path)
{
	if (this->path != nullptr)
		delete this->path;
	this->path = path;
}
void LlanyLib::Net::Objetos::Cookie::setKey(char const* const key)
{
	Cookie::setKey(new Basic::Objetos::String(key));
}
void LlanyLib::Net::Objetos::Cookie::setValue(char const* const value)
{
	Cookie::setValue(new Basic::Objetos::String(value));
}
void LlanyLib::Net::Objetos::Cookie::setFechaExpiracion(char const* const fechaExpiracion)
{
	Cookie::setFechaExpiracion(new Basic::Objetos::String(fechaExpiracion));
}
void LlanyLib::Net::Objetos::Cookie::setDominio(char const* const dominio)
{
	Cookie::setDominio(new Basic::Objetos::String(dominio));
}
void LlanyLib::Net::Objetos::Cookie::setPath(char const* const path)
{
	Cookie::setPath(new Basic::Objetos::String(path));
}
void LlanyLib::Net::Objetos::Cookie::setFechaExpiracion(int fechaExpiracion)
{
	// generar una fecha desde hoy hasta la fecha indicada
}
void LlanyLib::Net::Objetos::Cookie::setSeguro(const bool& seguro)
{
	this->seguro = seguro;
}
void LlanyLib::Net::Objetos::Cookie::setHTTPOnly(const bool& httponly)
{
	this->httponly = httponly;
}
#pragma endregion
#pragma region Comparadores
bool LlanyLib::Net::Objetos::Cookie::equals(const Cookie& c) const
{
	return Cookie::equals(c.key, c.value);
}
bool LlanyLib::Net::Objetos::Cookie::equals(const Basic::Objetos::String* key, const Basic::Objetos::String* value) const
{
	return (Cookie::equals(key) && this->value->operator==(*value));
}
bool LlanyLib::Net::Objetos::Cookie::equals(const Basic::Objetos::String* key) const
{
	return this->key->operator==(*key);
}
bool LlanyLib::Net::Objetos::Cookie::equals(char const* const key, char const* const value) const
{
	return (Cookie::equals(key) && this->value->operator==(*value));
}
bool LlanyLib::Net::Objetos::Cookie::equals(char const* const key) const
{
	return this->key->operator==(*key);
}
#pragma endregion
LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::Cookie::toString() const
{
	Basic::Objetos::StringBuilder str;
	if (this->key != nullptr && this->value != nullptr) {
		str.add(this->key);
		str.add('=');
		str.add(this->value);

		// Expiracion
		if (this->fechaExpiracion != nullptr) {
			str.add("; expires=");
			str.add(this->fechaExpiracion);
		}
		// Dominio
		if (this->dominio != nullptr) {
			str.add("; domain=");
			str.add(this->dominio);
		}
		// Path
		if (this->path != nullptr) {
			str.add("; path=");
			str.add(this->path);
		}
		// Secure
		if (this->seguro == true)
			str.add("; secure");
		// HttpOnly
		if (this->httponly == true)
			str.add("; HttpOnly");
	}
	return str.build();
}
