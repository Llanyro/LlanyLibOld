#include "HttpRequest.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/Stringctionary.hpp"

LlanyLib::Net::Objetos::HttpRequest::HttpRequest()
{
	this->peticion = nullptr;
	this->root = nullptr;
	this->version = nullptr;
	this->host = nullptr;
	this->connection = nullptr;
	this->parametros = new Basic::Objetos::Stringictionary();
	this->headers = new Basic::Objetos::Stringictionary();
	this->upgrade_insecure_requests = false;
}
LlanyLib::Net::Objetos::HttpRequest::~HttpRequest()
{
	if (this->peticion != nullptr) delete this->peticion;
	if (this->root != nullptr) delete this->root;
	if (this->version != nullptr) delete this->version;
	if (this->host != nullptr) delete this->host;
	if (this->connection != nullptr) delete this->connection;
	
	delete this->parametros;
	delete this->headers;
	
	this->peticion = nullptr;
	this->root = nullptr;
	this->version = nullptr;
	this->host = nullptr;
	this->connection = nullptr;
	this->parametros = nullptr;
	this->headers = nullptr;
	this->upgrade_insecure_requests = false;
}
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpRequest::getPeticion() const
{
	return this->peticion;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpRequest::getRoot() const
{
	return this->root;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpRequest::getVersion() const
{
	return this->version;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpRequest::getHost() const
{
	return this->host;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HttpRequest::getConnection() const
{
	return this->connection;
}
bool LlanyLib::Net::Objetos::HttpRequest::getUpgradeInsecureRequests() const
{
	return this->upgrade_insecure_requests;
}
const LlanyLib::Basic::Objetos::Stringictionary* LlanyLib::Net::Objetos::HttpRequest::getParametros() const
{
	return this->parametros;
}
const LlanyLib::Basic::Objetos::Stringictionary* LlanyLib::Net::Objetos::HttpRequest::getHeaders() const
{
	return this->headers;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Net::Objetos::HttpRequest::setPeticion(Basic::Objetos::String* petition)
{
	if (this->peticion != nullptr)
		delete this->peticion;
	this->peticion = petition;
}
void LlanyLib::Net::Objetos::HttpRequest::setRoot(Basic::Objetos::String* root)
{
	if (this->root != nullptr)
		delete this->root;
	this->root = root;
}
void LlanyLib::Net::Objetos::HttpRequest::setVersion(Basic::Objetos::String* version)
{
	if (this->version != nullptr)
		delete this->version;
	this->version = version;
}
void LlanyLib::Net::Objetos::HttpRequest::setHost(Basic::Objetos::String* host)
{
	if (this->host != nullptr)
		delete this->host;
	this->host = host;
}
void LlanyLib::Net::Objetos::HttpRequest::setConnection(Basic::Objetos::String* connection)
{
	if (this->connection != nullptr)
		delete this->connection;
	this->connection = connection;
}
void LlanyLib::Net::Objetos::HttpRequest::setUpgradeInsecureRequests(const bool& upgrade)
{
	this->upgrade_insecure_requests = upgrade;
}
void LlanyLib::Net::Objetos::HttpRequest::addParametro(Basic::Objetos::String* key, Basic::Objetos::String* value)
{
	this->parametros->add(key, value);
}
void LlanyLib::Net::Objetos::HttpRequest::addHeader(Basic::Objetos::String* key, Basic::Objetos::String* value)
{
	this->headers->add(key, value);
}
#pragma endregion
