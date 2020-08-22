#include "Contenedor.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/JSONBuilder.hpp"

#include "../../Math/Singletons/Math.hpp"

#include "ListaItems.hpp"
#include "../Enums/ItemEnum.hpp"
#include "../Singletons/ItemController.hpp"

#pragma region Protected
bool LlanyLib::Juego::Objetos::Contenedor::sePuedeAñadir(const Item* item) const
{
	return (item->getTipoDeMaterial() == this->tipoDeMaterialContenible
		&& (this->capacidadMaxima >=
		(this->capacidadOcupada + (item->getCantidad() * item->getPeso()))));
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::addItemProtected(Item* item)
{
	Item* resultado = item;
	if (Contenedor::sePuedeAñadir(item))
		if (this->listaContenedor->add(item))
			resultado = nullptr;
	return resultado;
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::getItemProtected(const size_t& pos)
{
	Item* item = nullptr;
	/*if (this->listaContenedor->length() > pos) {
		item = *this->listaContenedor->get(pos);
		this->listaContenedor->remove(pos);
	}*/
	return item;
}
#pragma endregion
#pragma region Constructores
LlanyLib::Juego::Objetos::Contenedor::Contenedor() : Item()
{
	this->listaContenedor = new ListItem();
	this->capacidadOcupada = 0.0;
	this->capacidadMaxima = 0.0;
	this->tipoDeMaterialContenible = Enums::TipoDeMaterial::Irreal;
}
LlanyLib::Juego::Objetos::Contenedor::Contenedor(const Contenedor& other) : Contenedor()
{
	Contenedor::operator=(other);
}
LlanyLib::Juego::Objetos::Contenedor::Contenedor(const Contenedor* other) : Contenedor()
{
	if(other != nullptr)
		Contenedor::operator=(other);
}
inline bool LlanyLib::Juego::Objetos::Contenedor::operator=(const Contenedor& other)
{
	bool resultado = false;
	if (&other != nullptr) {
		this->capacidadOcupada = other.capacidadOcupada;
		this->capacidadMaxima = other.capacidadMaxima;
		this->tipoDeMaterialContenible = other.tipoDeMaterialContenible;
		resultado = true;
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Contenedor::~Contenedor()
{
	delete this->listaContenedor;
	/*if (this->listaContenedor != nullptr) {
		for (size_t i = 0; i < this->listaContenedor->length(); i++)
			delete* this->listaContenedor->get(i);
		delete this->listaContenedor;
		this->listaContenedor = nullptr;
	}*/
}
#pragma endregion
#pragma region Getter && add
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::addItem(Item* item)
{
	Item* resultado = Contenedor::addItemProtected(item);
	if (resultado == nullptr)
		this->capacidadOcupada += (item->getPeso() + item->getCantidad());
	return resultado;
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::getItem(const size_t& pos)
{
	Item* resultado = Contenedor::getItemProtected(pos);
	if (resultado != nullptr)
		this->capacidadOcupada -= (resultado->getPeso() + resultado->getCantidad());
	return resultado;
}
bool LlanyLib::Juego::Objetos::Contenedor::getCapacidadOcupada() const
{
	return this->capacidadOcupada;
}
bool LlanyLib::Juego::Objetos::Contenedor::getCapacidadMaxima() const
{
	return this->capacidadMaxima;
}
const LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::get(const size_t& pos) const
{
	return nullptr;
}
#pragma endregion
#pragma region Virtual
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::clone() const
{
	return new Contenedor(this);
}
LlanyLib::Basic::Objetos::JSONBuilder* LlanyLib::Juego::Objetos::Contenedor::toJSONBuilder() const
{
	Basic::Objetos::JSONBuilder* result = Item::toJSONBuilder();
	Basic::Objetos::JSONBuilder* json = new Basic::Objetos::JSONBuilder();

	json->addClear(new Basic::Objetos::String("capacidadOcupada"), this->capacidadOcupada);
	json->addClear(new Basic::Objetos::String("capacidadMaxima"), this->capacidadMaxima);
	json->addClear(new Basic::Objetos::String("tipoDeMaterialContenible"), (int)this->tipoDeMaterialContenible);
	json->addClear(new Basic::Objetos::String("listaContenedor"), ITEM_CONTROLLER->generateJSONString(this->listaContenedor->getList()), Basic::Objetos::JSONBuilder::PrepType::Nada);

	result->addClear(new Basic::Objetos::String("Contenedor"), json);

	return result;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Objetos::Contenedor::toJSON() const
{
	LlanyLib::Basic::Objetos::JSONBuilder* build = Contenedor::toJSONBuilder();
	LlanyLib::Basic::Objetos::String* str = build->build();
	delete build;
	return str;
}
void LlanyLib::Juego::Objetos::Contenedor::deleteItem()
{
	delete this;
}
int LlanyLib::Juego::Objetos::Contenedor::compare(const Contenedor& other) const
{
	int result = Item::compare(other);
	if (result == 0)
		result = MATH->compare(this->capacidadOcupada, other.capacidadOcupada);
	if(result == 0)
		result = MATH->compare(this->capacidadMaxima, other.capacidadMaxima);
	return result;
}
bool LlanyLib::Juego::Objetos::Contenedor::similar(const Contenedor& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
	if (Item::similar(other))
	if (this->capacidadMaxima == other.capacidadMaxima)
		temp = true;
	return temp;}
bool LlanyLib::Juego::Objetos::Contenedor::equals(const Contenedor& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
	if (Item::equals(other))
	if (this->capacidadMaxima == other.capacidadMaxima)
	if (this->capacidadOcupada == other.capacidadOcupada)
	if(this->listaContenedor->equals(*other.listaContenedor))
		temp = true;
	return temp;
}
bool LlanyLib::Juego::Objetos::Contenedor::igualMenosCantidad(const Contenedor& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
	if (Item::igualMenosCantidad(other))
	if (this->capacidadMaxima == other.capacidadMaxima)
	if (this->capacidadOcupada == other.capacidadOcupada)
	if(this->listaContenedor->equals(*other.listaContenedor))
		temp = true;
	return temp;
}
bool LlanyLib::Juego::Objetos::Contenedor::operator==(const Contenedor& other) const
{
	return Contenedor::equals(other);
}
bool LlanyLib::Juego::Objetos::Contenedor::operator!=(const Contenedor& other) const
{
	return !Contenedor::equals(other);
}
#pragma endregion
