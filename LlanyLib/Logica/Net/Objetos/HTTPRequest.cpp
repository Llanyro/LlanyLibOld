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
void LlanyLib::Net::Objetos::HttpRequest::setPeticion(const Basic::Objetos::String* petition) const
{
	if (this->peticion != nullptr)
		delete this->peticion;
}
void LlanyLib::Net::Objetos::HttpRequest::setRoot(const Basic::Objetos::String* root) const
{
	if (this->root != nullptr)
		delete this->root;
}
void LlanyLib::Net::Objetos::HttpRequest::setVersion(const Basic::Objetos::String* version) const
{
	if (this->version != nullptr)
		delete this->version;
}
void LlanyLib::Net::Objetos::HttpRequest::setHost(const Basic::Objetos::String* host) const
{
	if (this->host != nullptr)
		delete this->host;
}
void LlanyLib::Net::Objetos::HttpRequest::setConnection(const Basic::Objetos::String* connection) const
{
	if (this->connection != nullptr)
		delete this->connection;
}
void LlanyLib::Net::Objetos::HttpRequest::setUpgradeInsecureRequests(const bool& upgrade) const
{
	this->upgrade_insecure_requests = upgrade;
}
#pragma endregion


