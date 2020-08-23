#include "Contenedor.hpp"

#include "../../../Basic/Objetos/String.hpp"
#include "../../../Basic/Objetos/JSONBuilder.hpp"
#include "../../../Basic/Plantillas/Listas/LinkedList.hpp"

#include "../../../Math/Singletons/Math.hpp"

#include "ListaItems.hpp"
#include "../../Enums/ItemEnum.hpp"
#include "../../Singletons/ItemController.hpp"

#pragma region No virtual
#pragma region Protected
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::addProtected(Item* item)
{
	Item* resultado = item;
	if (this->sePuedeAñadir(item))
		if (this->listaContenedor->add(item))
			resultado = nullptr;
	return resultado;
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
inline bool LlanyLib::Juego::Objetos::Contenedor::operator=(const Contenedor& other)
{
	bool resultado = false;
	if (&other != nullptr) {
		Item::operator=(other);
		this->capacidadOcupada = other.capacidadOcupada;
		this->capacidadMaxima = other.capacidadMaxima;
		this->tipoDeMaterialContenible = other.tipoDeMaterialContenible;
		this->listaContenedor->operator=(*other.listaContenedor);
		resultado = true;
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Contenedor::~Contenedor()
{
	delete this->listaContenedor;
}
#pragma endregion
#pragma region Getters
bool LlanyLib::Juego::Objetos::Contenedor::getCapacidadOcupada() const
{
	return this->capacidadOcupada;
}
bool LlanyLib::Juego::Objetos::Contenedor::getCapacidadMaxima() const
{
	return this->capacidadMaxima;
}
#pragma endregion
#pragma region Contenedor
void LlanyLib::Juego::Objetos::Contenedor::clear()
{
	this->listaContenedor->clear();
	this->capacidadOcupada = 0.0;
}
void LlanyLib::Juego::Objetos::Contenedor::ordenar(const Enums::Ordenamiento& ord)
{
}
const LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::get(const size_t& pos) const
{
	const Item* item = nullptr;
	if (pos < this->listaContenedor->getList()->length())
		item = this->listaContenedor->get(pos);
	return item;
}
#pragma endregion
#pragma endregion
#pragma region Virtual
#pragma region Protected
bool LlanyLib::Juego::Objetos::Contenedor::sePuedeAñadir(const Item* item) const
{
	return (item->getTipoDeMaterial() == this->tipoDeMaterialContenible
		&& this->cabeItem(item));
}
bool LlanyLib::Juego::Objetos::Contenedor::cabeItem(const Item* item) const
{
	return (this->capacidadMaxima >=
		(this->capacidadOcupada + (item->getCantidad() * item->getPeso())));
}
#pragma endregion
#pragma region Contenedor
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::add(Item* item)
{
	Item* resultado = Contenedor::addProtected(item);
	if (resultado == nullptr)
		this->capacidadOcupada += (item->getPeso() + item->getCantidad());
	return resultado;
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::extractItem(const size_t& pos)
{
	Item* item = this->listaContenedor->extractItem(pos);
	if (item != nullptr)
		this->capacidadOcupada -= (item->getPeso() * item->getCantidad());
	return item;
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::extractItem(const size_t& pos, const double& cantidad)
{
	Item* item = this->listaContenedor->extractItem(pos, cantidad);
	if (item != nullptr) 
		this->capacidadOcupada -= (item->getPeso() * cantidad);
	return item;
}
#pragma endregion
#pragma region Other
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::Contenedor::clone() const
{
	return new Contenedor(*this);
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
	if (result == 0)
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
	return temp;
}
bool LlanyLib::Juego::Objetos::Contenedor::equals(const Contenedor& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
		if (Item::equals(other))
			if (this->capacidadMaxima == other.capacidadMaxima)
				if (this->capacidadOcupada == other.capacidadOcupada)
					if (this->listaContenedor->equals(*other.listaContenedor))
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
					if (this->listaContenedor->equals(*other.listaContenedor))
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
#pragma endregion
