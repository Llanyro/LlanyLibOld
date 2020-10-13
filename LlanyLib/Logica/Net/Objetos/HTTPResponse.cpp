#include "HTTPResponse.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#include "Cookie.hpp"

#pragma region Getters
int LlanyLib::Net::Objetos::HTTPResponse::getResponseCode() const
{
	return this->responseCode;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::getResponse() const
{
	return this->response;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::getAcessControlAllowOrigin() const
{
	return this->acessControlAllowOrigin;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::getServerName() const
{
	return this->serverName;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::getContentType() const
{
	return this->contentType;
}
size_t LlanyLib::Net::Objetos::HTTPResponse::getContentLength() const
{
	size_t len = 0;
	if (this->contenido != nullptr)
		len = this->contenido->length();
	return len;
}
/*const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie*>* LlanyLib::Net::Objetos::Cabecera::getCookieList() const
{
	LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Net::Objetos::Cookie*>* list;

	return this->cookieList;
}*/
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* LlanyLib::Net::Objetos::HTTPResponse::getCabecerasExtras() const
{
	return this->cabecerasExtras;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::getUpgrade() const
{
	return this->upgrade;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::getConnection() const
{
	return this->connection;
}
#pragma endregion
#pragma region Setters


#pragma endregion
#pragma region Adders


#pragma endregion
#pragma region Remove


#pragma endregion
LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPResponse::toString() const
{




	return nullptr;
}
