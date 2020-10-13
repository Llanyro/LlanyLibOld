#include "HTTPRequest.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../../Basic/Plantillas/Nodos/NodoDosObjetosDosPunteros.hpp"

#include "../../Basic/Objetos/String.hpp"

#include "../Enums/HTTPEnum.hpp"

#define HOST "Host"
#define CONNECTION "Connection"
#define UPGRADE_INSECURE_REQUESTS "Upgrade-Insecure-Requests"
#define USER_AGENT "User-Agent"
#define ACCEPT "Accept"
#define ACCEPT_ENCODING "Accept-Encoding"
#define ACCEPT_LANGUAJE "Accept-Language"

void LlanyLib::Net::Objetos::HTTPRequest::processHTTPRequest(Basic::Objetos::String* all, const Enum::ResponseProcess& processType)
{
	switch (processType)
	{
		case Enum::ResponseProcess::PETITION:
			HTTPRequest::processPetition(all);
			break;
		case Enum::ResponseProcess::POST_CONTENT:
			HTTPRequest::processPostContent(all);
			break;
		//case Enum::ResponseProcess::FAST:
		//	HTTPRequest::processFast(all);
		//	break;
		//case Enum::ResponseProcess::MEDIUM:
		//	HTTPRequest::processFast(all);
		//	break;
		//case Enum::ResponseProcess::SLOW:
		//	HTTPRequest::processFast(all);
		//	break;
		case Enum::ResponseProcess::SUPER_SLOW:
			HTTPRequest::processSuperSlow(all);
			break;
	}
	delete all;
}
void LlanyLib::Net::Objetos::HTTPRequest::processPetition(Basic::Objetos::String* all)
{
	Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* list = all->split('\n');
	Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* tempList = nullptr;
	Basic::Objetos::String* temp = nullptr;

	if (list->length() > 0) {
		// Analizamos la primera linea
		temp = *list->get(0);
		tempList = temp->split(' ');
		if (tempList->length() >= 3) {
			this->peticion = *tempList->get(0);
			this->root = *tempList->get(1);
			this->version = *tempList->get(2);
			for (size_t i = 3; i < tempList->length(); i++)
				delete* tempList->get(i);
		}
		else
			for (size_t i = 0; i < tempList->length(); i++)
				delete* tempList->get(i);
		delete temp;
		delete tempList;
		// Borramos el resto de lineas
		for (size_t i = 1; i < list->length(); i++)
			delete* list->get(i);
		delete list;
	}
}
void LlanyLib::Net::Objetos::HTTPRequest::processPostContent(Basic::Objetos::String* all)
{
}
void LlanyLib::Net::Objetos::HTTPRequest::processFast(Basic::Objetos::String* all)
{
}
void LlanyLib::Net::Objetos::HTTPRequest::processSuperSlow(Basic::Objetos::String* all)
{
	Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* list = all->split('\n');
	Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* tempList = nullptr;
	Basic::Objetos::String* temp = nullptr;

	if (list->length() > 0) {
		// Analizamos la primera linea
		temp = *list->get(0);
		tempList = temp->split(' ');
		this->peticion = *tempList->get(0);
		this->root = *tempList->get(1);
		this->version = *tempList->get(2);
		delete temp;
		delete tempList;

		for (size_t i = 1; i < list->length(); i++) {
			temp = *list->get(i);
			tempList = temp->split(": ");

			if (tempList->length() == 2) {
				if (temp->startWithSimilar(HOST)) {
					// Guardamos el host
					this->host = *tempList->get(1);
					// Borramos el otro elemento
					delete* tempList->get(0);
				}
				else if (temp->startWithSimilar(CONNECTION)) {
					this->connection = *tempList->get(1);
					delete* tempList->get(0);
				}
				else if (temp->startWithSimilar(UPGRADE_INSECURE_REQUESTS)) {
					this->upgrade_insecure_requests = (*tempList->get(1))->equals('1');
					delete* tempList->get(1);
					delete* tempList->get(0);
				}
				else if (temp->startWithSimilar(USER_AGENT)) {
					this->userAgent = *tempList->get(1);
					delete* tempList->get(0);
				}
				else if (temp->startWithSimilar(ACCEPT_ENCODING)) {
					Basic::Objetos::String* tempTypes = *tempList->get(1);
					this->encodingsAccepted = tempTypes->split(", ");
					delete* tempList->get(1);
					delete* tempList->get(0);
				}
				else if (temp->startWithSimilar(ACCEPT_LANGUAJE)) {
					Basic::Objetos::String* tempTypes = *tempList->get(1);
					this->encodingsAccepted = tempTypes->split(",");
					delete* tempList->get(1);
					delete* tempList->get(0);
				}
				else if (temp->startWithSimilar(ACCEPT)) {
					Basic::Objetos::String* tempTypes = *tempList->get(1);
					this->typesAccepted = tempTypes->split(",");
					delete* tempList->get(1);
					delete* tempList->get(0);
				}
				else {
					if (this->other == nullptr)
						this->other = new Basic::Templates::Diccionarios::DictionaryLinkedList<
						Basic::Objetos::String*,
						Basic::Objetos::String*>();
					this->other->add(*tempList->get(0), *tempList->get(1));
				}
			}

			delete temp;
			delete tempList;
		}
		delete list;
	}
}

LlanyLib::Net::Objetos::HTTPRequest::HTTPRequest(Basic::Objetos::String* all) : HTTPRequest(all, Enum::ResponseProcess::SUPER_SLOW){}
LlanyLib::Net::Objetos::HTTPRequest::HTTPRequest(Basic::Objetos::String* all, const Enum::ResponseProcess& processType)
{
	this->peticion = nullptr;
	this->root = nullptr;
	this->version = nullptr;
	this->host = nullptr;
	this->connection = nullptr;
	this->upgrade_insecure_requests = false;
	this->userAgent = nullptr;
	this->other = nullptr;
	this->contenido = nullptr;
	this->typesAccepted = nullptr;
	HTTPRequest::processHTTPRequest(all, processType);
}
LlanyLib::Net::Objetos::HTTPRequest::~HTTPRequest()
{
	if (this->peticion != nullptr) delete this->peticion;
	if (this->root != nullptr) delete this->root;
	if (this->version != nullptr) delete this->version;
	if (this->host != nullptr) delete this->host;
	if (this->connection != nullptr) delete this->connection;
	if (this->userAgent != nullptr) delete this->userAgent;
	if (this->contenido != nullptr) delete this->contenido;
	if (this->typesAccepted != nullptr) {
		for (size_t i = 0; i < this->typesAccepted->length(); i++)
			delete *this->typesAccepted->get(i);
		delete this->typesAccepted;
	}
	if (this->other != nullptr) {
		LlanyLib::Basic::Templates::Nodos::NDODP<
			LlanyLib::Basic::Objetos::String*,
			LlanyLib::Basic::Objetos::String*>* temp = nullptr;
		for (size_t i = 0; i < this->other->length(); i++) {
			temp = this->other->getObject(i);
			delete temp->getObject0();
			delete temp->getObject1();
		}
		delete this->other;
	}
	this->peticion = nullptr;
	this->root = nullptr;
	this->version = nullptr;
	this->host = nullptr;
	this->connection = nullptr;
	this->userAgent = nullptr;
	this->other = nullptr;
	this->contenido = nullptr;
	this->typesAccepted = nullptr;
}
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getPeticion() const
{
	return this->peticion;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getRoot() const
{
	return this->root;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getVersion() const
{
	return this->version;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getHost() const
{
	return this->host;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getConnection() const
{
	return this->connection;
}
bool LlanyLib::Net::Objetos::HTTPRequest::getUpgradeInsecureRequests() const
{
	return this->upgrade_insecure_requests;
}
size_t LlanyLib::Net::Objetos::HTTPRequest::getNumAcceptTypes() const
{
	size_t resultado = 0;
	if (this->typesAccepted != nullptr)
		resultado = this->typesAccepted->length();
	return resultado;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getAcceptedType(const size_t& pos) const
{
	const LlanyLib::Basic::Objetos::String* resultado = nullptr;
	if (this->typesAccepted != nullptr)
		if (pos < this->typesAccepted->length())
			resultado = *this->typesAccepted->get(pos);
	return resultado;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getUserAgent() const
{
	return this->userAgent;
}
size_t LlanyLib::Net::Objetos::HTTPRequest::getNumOther() const
{
	return this->other->length();
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getOtherStartWithSimilar(char const* const str) const
{
	const LlanyLib::Basic::Objetos::String* resultado = nullptr;
	LlanyLib::Basic::Templates::Nodos::NDODP<
		LlanyLib::Basic::Objetos::String*,
		LlanyLib::Basic::Objetos::String*>* temp = nullptr;
	if(this->other != nullptr)
		for (size_t i = 0; i < this->other->length(); i++) {
			temp = this->other->getObject(i);
			if (temp->getObject0()->startWithSimilar(str)) {
				resultado = temp->getObject0();
				i = this->other->length();
			}
		}
	return resultado;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Net::Objetos::HTTPRequest::getContenido() const
{
	return this->contenido;
}
#pragma endregion
