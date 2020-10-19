#include "HttpResponse.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/Date.hpp"

#include "Cookie.hpp"

LlanyLib::Net::Objetos::HttpResponse::HttpResponse()
{
	this->responseCode = 200;
	this->response = nullptr;
	this->acessControlAllowOrigin = nullptr;
	this->serverName = nullptr;
	this->upgrade= nullptr;
	this->connection = nullptr;
	this->date = nullptr;
	this->contenido = nullptr;
	this->contentType = nullptr;
	this->encodingType = nullptr;
	this->cookieList = nullptr;
	this->cabecerasExtras = nullptr;
}
LlanyLib::Net::Objetos::HttpResponse::~HttpResponse()
{
	if(this->response == nullptr) delete this->response;
	if(this->acessControlAllowOrigin == nullptr) delete this->acessControlAllowOrigin;
	if(this->serverName == nullptr) delete this->serverName;
	if(this->upgrade == nullptr) delete this->upgrade;
	if(this->connection == nullptr) delete this->connection;
	if(this->date == nullptr) delete this->date;
	if(this->contenido == nullptr) delete this->contenido;
	if(this->contentType == nullptr) delete this->contentType;
	if(this->encodingType == nullptr) delete this->encodingType;

	//if(this->cookieList == nullptr) delete this->cookieList;
	//if(this->cabecerasExtras == nullptr) delete this->cabecerasExtras;

	this->responseCode = 200;
	this->response = nullptr;
	this->acessControlAllowOrigin = nullptr;
	this->serverName = nullptr;
	this->upgrade = nullptr;
	this->connection = nullptr;
	this->date = nullptr;
	this->contenido = nullptr;
	this->contentType = nullptr;
	this->encodingType = nullptr;
	this->cookieList = nullptr;
	this->cabecerasExtras = nullptr;
}
#pragma region Getters
int LlanyLib::Net::Objetos::HttpResponse::getResponseCode() const
{
	return this->responseCode;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getResponse() const
{
	return this->response;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getAcessControlAllowOrigin() const
{
	return this->acessControlAllowOrigin;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getServerName() const
{
	return this->serverName;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getUpgrade() const
{
	return this->upgrade;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getConnection() const
{
	return this->connection;
}

const LlanyLib::Basic::Objetos::Date* LlanyLib::Net::Objetos::HttpResponse::getDate() const
{
	return this->date;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getContent() const
{
	return this->contenido;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getContentType() const
{
	return this->contentType;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::getEncodingType() const
{
	return this->encodingType;
}
size_t LlanyLib::Net::Objetos::HttpResponse::getContentLength() const
{
	size_t len = 0;
	if (this->contenido != nullptr)
		len = this->contenido->length();
	return len;
}
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie*>* LlanyLib::Net::Objetos::HttpResponse::getCookieList() const
{
	return this->cookieList;
}
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* LlanyLib::Net::Objetos::HttpResponse::getCabecerasExtras() const
{
	return this->cabecerasExtras;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Net::Objetos::HttpResponse::setResponseCode(const int& responseCode)
{
	this->responseCode = responseCode;
}
void LlanyLib::Net::Objetos::HttpResponse::setResponse(char const* const reason)
{
	if (this->response != nullptr)
		delete this->response;
	this->response = new Basic::Objetos::String(reason);
}
void LlanyLib::Net::Objetos::HttpResponse::setResponse(Basic::Objetos::String* reason)
{
	if (this->response != nullptr)
		delete this->response;
	this->response = reason;
}
void LlanyLib::Net::Objetos::HttpResponse::setResponse(const int& responseCode, char const* const reason)
{
	HttpResponse::setResponseCode(responseCode);
	HttpResponse::setResponse(response);
}
void LlanyLib::Net::Objetos::HttpResponse::setResponse(const int& responseCode, Basic::Objetos::String* reason)
{
	HttpResponse::setResponseCode(responseCode);
	HttpResponse::setResponse(response);
}
void LlanyLib::Net::Objetos::HttpResponse::setAcessControlAllowOrigin(char const* const control)
{
	if (this->acessControlAllowOrigin != nullptr)
		delete this->acessControlAllowOrigin;
	this->acessControlAllowOrigin = new Basic::Objetos::String(control);
}
void LlanyLib::Net::Objetos::HttpResponse::setAcessControlAllowOrigin(Basic::Objetos::String* control)
{
	if (this->acessControlAllowOrigin != nullptr)
		delete this->acessControlAllowOrigin;
	this->acessControlAllowOrigin = control;
}

void LlanyLib::Net::Objetos::HttpResponse::setServerName(char const* const serverName)
{
	if (this->serverName != nullptr)
		delete this->serverName;
	this->serverName = new Basic::Objetos::String(serverName);
}
void LlanyLib::Net::Objetos::HttpResponse::setServerName(Basic::Objetos::String* serverName)
{
	if (this->serverName != nullptr)
		delete this->serverName;
	this->serverName = serverName;
}
void LlanyLib::Net::Objetos::HttpResponse::setUpgrade(char const* const upgrade)
{
	if (this->upgrade != nullptr)
		delete this->upgrade;
	this->upgrade = new Basic::Objetos::String(upgrade);
}
void LlanyLib::Net::Objetos::HttpResponse::setUpgrade(Basic::Objetos::String* upgrade)
{
	if (this->upgrade != nullptr)
		delete this->upgrade;
	this->upgrade = upgrade;
}
void LlanyLib::Net::Objetos::HttpResponse::setConnection(char const* const connection)
{
	if (this->connection != nullptr)
		delete this->connection;
	this->connection = new Basic::Objetos::String(connection);
}
void LlanyLib::Net::Objetos::HttpResponse::setConnection(Basic::Objetos::String* connection)
{
	if (this->connection != nullptr)
		delete this->connection;
	this->connection = connection;
}
void LlanyLib::Net::Objetos::HttpResponse::setDate(Basic::Objetos::Date* date)
{
	if (this->date != nullptr)
		delete this->date;
	this->date = date;
}
void LlanyLib::Net::Objetos::HttpResponse::setDate()
{
	if (this->date != nullptr)
		delete this->date;
	this->date = new Basic::Objetos::Date();
}
void LlanyLib::Net::Objetos::HttpResponse::setContenido(char const* const contenido)
{
	if (this->contenido != nullptr)
		delete this->contenido;
	this->contenido = new Basic::Objetos::String(contenido);
}
void LlanyLib::Net::Objetos::HttpResponse::setContenido(Basic::Objetos::String* contenido)
{
	if (this->contenido != nullptr)
		delete this->contenido;
	this->contenido = contenido;
}
void LlanyLib::Net::Objetos::HttpResponse::setContentType(char const* const contentType)
{
	if (this->contentType != nullptr)
		delete this->contentType;
	this->contentType = new Basic::Objetos::String(contentType);
}
void LlanyLib::Net::Objetos::HttpResponse::setContentType(Basic::Objetos::String* contentType)
{
	if (this->contentType != nullptr)
		delete this->contentType;
	this->contentType = contentType;
}
void LlanyLib::Net::Objetos::HttpResponse::setEncodingType(char const* const encodingType)
{
	if (this->encodingType != nullptr)
		delete this->encodingType;
	this->encodingType = new Basic::Objetos::String(encodingType);
}
void LlanyLib::Net::Objetos::HttpResponse::setEncodingType(Basic::Objetos::String* encodingType)
{
	if (this->encodingType != nullptr)
		delete this->encodingType;
	this->encodingType = encodingType;
}
#pragma endregion
#pragma region Adders


#pragma endregion
#pragma region Remove


#pragma endregion
LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpResponse::toString() const
{
	Basic::Objetos::StringBuilder str;
	/// Respuesta
	str.add("HTTP/1.1 ");
	str += this->responseCode;
	if(this->response != nullptr)
		str.add(this->response);
	else
		str.add("OK");
	str.add("\r\n");

	/// Datos del servicio
	if (this->acessControlAllowOrigin != nullptr) {
		str.add("Access-Control-Allow-Origin: ");
		str.add(this->acessControlAllowOrigin);
		str.add("\r\n");
	}
	if (this->serverName != nullptr) {
		str.add("Server: ");
		str.add(this->serverName);
		str.add("\r\n");
	}
	if (this->upgrade != nullptr) {
		str.add("Upgrade: ");
		str.add(this->upgrade);
		str.add("\r\n");
	}
	if (this->connection != nullptr) {
		str.add("Connection: ");
		str.addClear(this->connection);
		str.add("\r\n");
	}
	if (this->date != nullptr) {
		str.add("Date: ");
		str.addClear(this->date->toString());
		str.add("\r\n");
	}

	/// Cookies
	// No añadido

	/// Extras
	// No añadido
	Basic::Objetos::String** strtemp = nullptr;
	for (size_t i = 0; i < this->cabecerasExtras->length(); i++)
	{
		strtemp = this->cabecerasExtras->get(i);
		if (strtemp != nullptr)
			str.add(*strtemp);
	}

	/// Contenido Header
	str.add("Content-Length: ");
	if (this->contenido != nullptr)
		str += this->contenido->length();
	else
		str += 0;
	str.add("\r\n");

	/// Fin Headers
	str.add("Accept-Ranges: bytes\r\n");
	str.add("\r\n");

	/// Añadido de contenido si existe
	if (this->contenido != nullptr)
		str.add(this->contenido);

	return str.build();
}
