#include "HttpRequest.hpp"

LlanyLib::Net::Objetos::HttpRequest::HttpRequest()
{
}
LlanyLib::Net::Objetos::HttpRequest::~HttpRequest()
{
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
#pragma endregion
#pragma region Setters
void LlanyLib::Net::Objetos::HttpRequest::setPeticion(Basic::Objetos::String* petition)
{
	if (this->peticion != nullptr)
		delete this->peticion;
	this->peticion = peticion;
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
#pragma endregion


