#include "HttpRequest.hpp"

#include "../../Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../../Basic/Objetos/String.hpp"

LlanyLib::Net::Objetos::HttpRequest::HttpRequest()
{
	this->peticion = nullptr;
	this->root = nullptr;
	this->version = nullptr;
	this->host = nullptr;
	this->connection = nullptr;
	this->parametros = nullptr;
	this->upgrade_insecure_requests = false;
}
LlanyLib::Net::Objetos::HttpRequest::~HttpRequest()
{
	if (this->peticion != nullptr) delete this->peticion;
	if (this->root != nullptr) delete this->root;
	if (this->version != nullptr) delete this->version;
	if (this->host != nullptr) delete this->host;
	if (this->connection != nullptr) delete this->connection;
	if (this->parametros != nullptr) {
		for (size_t i = 0; i < this->parametros->length(); i++) {
			delete *this->parametros->getKey(i);
			delete *this->parametros->getValue(i);
		}
		delete this->parametros;
	}
	this->peticion = nullptr;
	this->root = nullptr;
	this->version = nullptr;
	this->host = nullptr;
	this->connection = nullptr;
	this->parametros = nullptr;
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
const LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<
	LlanyLib::Basic::Objetos::String*, 
	LlanyLib::Basic::Objetos::String*>* 
	LlanyLib::Net::Objetos::HttpRequest::getParametros() const
{
	return this->parametros;
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
void LlanyLib::Net::Objetos::HttpRequest::setParametro(Basic::Objetos::String* key, Basic::Objetos::String* value)
{
	if (this->parametros == nullptr)
		this->parametros = new Basic::Templates::Diccionarios::DictionaryLinkedList<
		Basic::Objetos::String*,
		Basic::Objetos::String*>();
	this->parametros->add(key, value);
}
#pragma endregion
