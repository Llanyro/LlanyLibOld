#include "GestorItems.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../../Basic/Plantillas/Nodos/NodoDosObjetosDosPunteros.hpp"

#include "../../Basic/Objetos/String.hpp"

#include "../Objetos/Item.hpp"
#include "../Objetos/Contenedor.hpp"

#pragma region Singleton
LlanyLib::Juego::Gestores::GestorItems::GestorItems()
{
	GestorItems::subscribir(GestorItems::freeInstancia);
	this->registro = new Basic::Templates::Diccionarios::DictionaryLinkedList<
		Basic::Objetos::String*,
		Objetos::Item*
	>();
}
LlanyLib::Juego::Gestores::GestorItems::~GestorItems()
{
	NODO* temp = this->registro->getObject(0);
	for (size_t i = 0; i < this->registro->length(); i++) {
		delete temp->getObject0();
		temp->getObject1()->deleteItem();
		temp = temp->getPrimerNodo();
	}
	delete this->registro;
}
#pragma endregion
#pragma region Protected
bool LlanyLib::Juego::Gestores::GestorItems::containsName(char const* const registerName) const
{
	Basic::Templates::Nodos::NDODP<
		Basic::Objetos::String*,
		Objetos::Item*
	>* temp = this->registro->getObject(0);
	bool encontrado = false;
	for (size_t i = 0; i < this->registro->length(); i++) {
		if (temp->getObject0()->equals(registerName)) {
			encontrado = true;
			i = this->registro->length();
		}
		temp = temp->getPrimerNodo();
	}
	return encontrado;
}
NODO* LlanyLib::Juego::Gestores::GestorItems::buscarNodo(char const* const registerName) const
{
	NODO* temp = this->registro->getObject(0);
	NODO* result = nullptr;
	for (size_t i = 0; i < this->registro->length(); i++) {
		if (temp->getObject0()->equals(registerName)) {
			result = temp;
			i = this->registro->length();
		}
		temp = temp->getPrimerNodo();
	}
	return result;
}
long_t LlanyLib::Juego::Gestores::GestorItems::buscarID(char const* const registerName) const
{
	NODO* temp = this->registro->getObject(0);
	long_t resultado = 0;
	for (size_t i = 0; i < this->registro->length(); i++) {
		if (temp->getObject0()->equals(registerName)) {
			resultado = i;
			i = this->registro->length();
		}
		temp = temp->getPrimerNodo();
	}
	return resultado;
}
#pragma endregion
#pragma region Registro y generacion
bool LlanyLib::Juego::Gestores::GestorItems::itemRegister(Objetos::Item* item, char const* const registerName)
{
	bool resultado = false;
	if (!GestorItems::containsName(registerName)) {
		resultado = this->registro->add(new Basic::Objetos::String(registerName), item);
		///Puede que haya problemas aqui si se usan hilos
		item->itemID = this->registro->length();
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Gestores::GestorItems::newItem(char const* const registerName) const
{
	Objetos::Item* resultado = nullptr;
	NODO* nodo = GestorItems::buscarNodo(registerName);
	if (nodo != nullptr)
		resultado = nodo->getObject1()->clone();
	return resultado;
}
#pragma endregion
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Gestores::GestorItems::getRegisterName(const long_t& itemID) const
{
	LlanyLib::Basic::Objetos::String* res = nullptr;
	long_t realID = itemID - 1;
	if (realID < this->registro->length() && realID >= 0)
		res = this->registro->getObject((size_t)realID)->getObject0();
	return res;
}
long_t LlanyLib::Juego::Gestores::GestorItems::getID(char const* const registerName) const
{
	return GestorItems::buscarID(registerName) + 1;
}
long_t LlanyLib::Juego::Gestores::GestorItems::getID(Basic::Objetos::String* registerName) const
{
	return GestorItems::getID(registerName->get());
}
long_t LlanyLib::Juego::Gestores::GestorItems::getIDClear(Basic::Objetos::String* registerName) const
{
	long_t result = GestorItems::getID(registerName->get());
	delete registerName;
	return result;
}
#pragma endregion

