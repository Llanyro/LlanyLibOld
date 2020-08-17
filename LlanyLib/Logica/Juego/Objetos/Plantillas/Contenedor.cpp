#include "Contenedor.hpp"

#include "../../Enums/ObjetosEnum.hpp"
#include "../Singletons/ItemController.hpp"
#include "../../../Basic/Objetos/String.hpp"
#include "../../../Basic/Objetos/JSONBuilder.hpp"
#include "../../../Basic/Plantillas/Listas/LinkedList.hpp"

bool LlanyLib::Juego::Items::Contenedor::sePuedeAñadir(const Item* item) const
{
	return (item->getTipoDeMaterial() == this->tipoDeMaterialContenible
		&& (this->capacidadMaxima >= 
			(this->capacidadOcupada + (item->getCantidad()* item->getPeso()))));
}
LlanyLib::Juego::Items::Item* LlanyLib::Juego::Items::Contenedor::addItemProtected(Item* item)
{
	Item* resultado = item;
	if (Contenedor::sePuedeAñadir(item))
		if (this->listaContenedor->add(item))
			resultado = nullptr;
	return resultado;
}
LlanyLib::Juego::Items::Item* LlanyLib::Juego::Items::Contenedor::getItemProtected(const size_t& pos)
{
	Item* item = nullptr;
	if (this->listaContenedor->length() > pos) {
		item = *this->listaContenedor->get(pos);
		this->listaContenedor->remove(pos);
	}
	return item;
}


LlanyLib::Juego::Items::Contenedor::Contenedor() : Item()
{
	this->listaContenedor = new Basic::Templates::Listas::LinkedList<Item*>();
	this->capacidadOcupada = 0.0;
	this->capacidadMaxima = 0.0;
	this->tipoDeMaterialContenible = Enums::TipoDeMaterial::Irreal;
}
LlanyLib::Juego::Items::Contenedor::~Contenedor()
{
	if (this->listaContenedor != nullptr) {
		for (size_t i = 0; i < this->listaContenedor->length(); i++)
			delete *this->listaContenedor->get(i);
		delete this->listaContenedor;
		this->listaContenedor = nullptr;
	}
}

LlanyLib::Juego::Items::Item* LlanyLib::Juego::Items::Contenedor::addItem(Item* item)
{
	Item* resultado = Contenedor::addItemProtected(item);
	if (resultado == nullptr)
		this->capacidadOcupada += (item->getPeso() + item->getCantidad());
	return resultado;
}
LlanyLib::Juego::Items::Item* LlanyLib::Juego::Items::Contenedor::getItem(const size_t& pos)
{
	Item* resultado = Contenedor::getItemProtected(pos);
	if (resultado != nullptr)
		this->capacidadOcupada -= (resultado->getPeso() + resultado->getCantidad());
	return resultado;
}


bool LlanyLib::Juego::Items::Contenedor::getCapacidadOcupada() const
{
	return this->capacidadOcupada;
}
bool LlanyLib::Juego::Items::Contenedor::getCapacidadMaxima() const
{
	return this->capacidadMaxima;
}
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Juego::Items::Item*>* LlanyLib::Juego::Items::Contenedor::getList() const
{
	return this->listaContenedor;
}


LlanyLib::Basic::Objetos::JSONBuilder* LlanyLib::Juego::Items::Contenedor::toJSONBuilder() const
{
	Basic::Objetos::JSONBuilder* result = Item::toJSONBuilder();
	Basic::Objetos::JSONBuilder* json = new Basic::Objetos::JSONBuilder();

	json->addClear(new Basic::Objetos::String("capacidadOcupada"), this->capacidadOcupada);
	json->addClear(new Basic::Objetos::String("capacidadMaxima"), this->capacidadMaxima);
	json->addClear(new Basic::Objetos::String("tipoDeMaterialContenible"), (int)this->tipoDeMaterialContenible);
	json->addClear(new Basic::Objetos::String("listaContenedor"), ITEM_CONTROLLER->generateJSONString(this->listaContenedor), Basic::Objetos::JSONBuilder::PrepType::Nada);

	result->addClear(new Basic::Objetos::String("Contenedor"), json);

	return result;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Items::Contenedor::toJSON() const
{
	LlanyLib::Basic::Objetos::JSONBuilder* build = Contenedor::toJSONBuilder();
	LlanyLib::Basic::Objetos::String* str = build->build();
	delete build;
	return str;
}
