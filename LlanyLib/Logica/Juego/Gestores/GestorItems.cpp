#include "GestorItems.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"

#include "../../Basic/Objetos/String.hpp"

#include "../Objetos/Items/Item.hpp"
#include "../Objetos/Items/Contenedor.hpp"

#pragma region Singleton
LlanyLib::Juego::Gestores::GestorItems::GestorItems()
{
	GestorItems::subscribir(GestorItems::freeInstancia);
	this->registro = new Basic::Templates::Diccionarios::DictionaryLinkedList<
		Basic::Objetos::String*,
		Objetos::Items::Item*
	>();
}
LlanyLib::Juego::Gestores::GestorItems::~GestorItems()
{
	for (size_t i = 0; i < this->registro->length(); i++) {
		delete *this->registro->getKey(i);
		(*this->registro->getValue(i))->deleteItem();
	}
	delete this->registro;
}
#pragma endregion
#pragma region Protected
bool LlanyLib::Juego::Gestores::GestorItems::containsName(char const* const registerName) const
{
	bool encontrado = false;
	for (size_t i = 0; i < this->registro->length(); i++)
		if ((*this->registro->getKey(i))->similar(registerName)) {
			encontrado = true;
			i = this->registro->length();
		}
	return encontrado;
}
LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Gestores::GestorItems::getObjeto(char const* const registerName) const
{
	Objetos::Items::Item* resultado = nullptr;
	for (size_t i = 0; i < this->registro->length(); i++)
		if ((*this->registro->getKey(i))->similar(registerName)) {
			resultado = *this->registro->getValue(i);
			i = this->registro->length();
		}
	return resultado;
}
long_t LlanyLib::Juego::Gestores::GestorItems::buscarID(char const* const registerName) const
{
	long_t resultado = -1;
	for (size_t i = 0; i < this->registro->length(); i++)
		if ((*this->registro->getKey(i))->similar(registerName)) {
			resultado = i;
			i = this->registro->length();
		}
	return resultado;
}
#pragma endregion
#pragma region Registro y generacion
bool LlanyLib::Juego::Gestores::GestorItems::itemRegister(Objetos::Items::Item* item, char const* const registerName)
{
	bool resultado = false;
	if (!GestorItems::containsName(registerName)) {
		resultado = this->registro->add(new Basic::Objetos::String(registerName), item);
		///Puede que haya problemas aqui si se usan hilos
		item->itemID = this->registro->length();
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Gestores::GestorItems::newItem(char const* const registerName) const
{
	Objetos::Items::Item* resultado = GestorItems::getObjeto(registerName);
	if (resultado != nullptr)
		resultado = resultado->clone();
	return resultado;
}
#pragma endregion
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Gestores::GestorItems::getRegisterName(const long_t& itemID) const
{
	return *this->registro->getKey((size_t)itemID);
}
long_t LlanyLib::Juego::Gestores::GestorItems::getID(char const* const registerName) const
{
	return GestorItems::buscarID(registerName);
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
