#include "ItemController.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/JSONBuilder.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#include "../Enums/ItemEnum.hpp"
#include "../Objetos/Items/Item.hpp"
#include "../Objetos/Items/Contenedor.hpp"


LlanyLib::Juego::Singletons::ItemContoller::ItemContoller() { ItemContoller::subscribir(ItemContoller::freeInstancia); }
LlanyLib::Juego::Singletons::ItemContoller::~ItemContoller(){}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Singletons::ItemContoller::generateJSONString(Basic::Templates::Listas::LinkedList<Objetos::Items::Item*>* list) const
{
	Basic::Objetos::StringBuilder buffer;
	buffer += '[';
	Objetos::Items::Item* temp = nullptr;
	for (size_t i = 0; i < list->length(); i++) {
		temp = *list->get(i);
		if (i != 0)
			buffer += ',';
		buffer += '{';
		buffer.addClear(temp->toJSON());
		buffer += '}';
	}
	buffer += ']';
	return buffer.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Singletons::ItemContoller::generateJSONStringClear(Basic::Templates::Listas::LinkedList<Objetos::Items::Item*>* list) const
{
	LlanyLib::Basic::Objetos::String* item = generateJSONString(list);
	for (size_t i = 0; i < list->length(); i++)
		delete* list->get(i);
	delete list;
	return item;
}

#pragma region Items

#pragma endregion
#pragma region Contenedores
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::isContenedor(Objetos::Items::Item* contenedor) const
{
	Enum::ItemControllerResults resultado = Enum::ItemControllerResults::NoResult;
	if(contenedor == nullptr)
		resultado = Enum::ItemControllerResults::PunteroContenedorNull;
	else
	{
		if (contenedor->getTipoObjeto() != Enum::TipoObjeto::Contenedor)
			resultado = Enum::ItemControllerResults::NoEsContenedor;
		else
			resultado = Enum::ItemControllerResults::EsContenedor;
	}
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::isContenedor(Objetos::Items::Contenedor* contenedor) const
{
	return ItemContoller::isContenedor((Objetos::Items::Item*)contenedor);
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedor(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = ItemContoller::isContenedor(contenedor);
	if (resultado == Enum::ItemControllerResults::EsContenedor)
		resultado = ItemContoller::addItemToContenedor((Objetos::Items::Contenedor*)contenedor, item);
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedorDelete(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = ItemContoller::addItemToContenedor(contenedor, item);
	if (resultado != Enum::ItemControllerResults::AddItemExitoContenedor)
		item->deleteItem();
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedor(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = ItemContoller::isContenedor(contenedor);

	if (resultado == Enum::ItemControllerResults::EsContenedor) {
		if (item == nullptr)
			resultado = Enum::ItemControllerResults::PunteroItemNull;
		else {
			Objetos::Items::Item* resultAdd = contenedor->add(item);
			if (resultAdd != nullptr) {
				resultado = Enum::ItemControllerResults::NoCumpleRequirimientosDelContenedor;
			}
			else
				resultado = Enum::ItemControllerResults::AddItemExitoContenedor;
		}
	}
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedorDelete(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = ItemContoller::addItemToContenedor(contenedor, item);
	if (resultado != Enum::ItemControllerResults::AddItemExitoContenedor)
		item->deleteItem();
	return resultado;
}
#pragma endregion
