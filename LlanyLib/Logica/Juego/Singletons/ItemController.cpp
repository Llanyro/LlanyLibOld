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
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Singletons::ItemContoller::generateJSONString(Basic::Templates::Listas::LinkedList<Objetos::Item*>* list) const
{
	Basic::Objetos::StringBuilder buffer;
	buffer += '[';
	Objetos::Item* temp = nullptr;
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
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Singletons::ItemContoller::generateJSONStringClear(Basic::Templates::Listas::LinkedList<Objetos::Item*>* list) const
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
LlanyLib::Juego::Enums::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::isContenedor(Objetos::Item* contenedor) const
{
	Enums::ItemControllerResults resultado = Enums::ItemControllerResults::NoResult;
	if(contenedor == nullptr)
		resultado = Enums::ItemControllerResults::PunteroContenedorNull;
	else
	{
		if (contenedor->getTipoObjeto() != Enums::TipoObjeto::Contenedor)
			resultado = Enums::ItemControllerResults::NoEsContenedor;
		else
			resultado = Enums::ItemControllerResults::EsContenedor;
	}
	return resultado;
}
LlanyLib::Juego::Enums::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::isContenedor(Objetos::Contenedor* contenedor) const
{
	return ItemContoller::isContenedor((Objetos::Item*)contenedor);
}
LlanyLib::Juego::Enums::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedor(Objetos::Item* contenedor, Objetos::Item* item) const
{
	Enums::ItemControllerResults resultado = ItemContoller::isContenedor(contenedor);
	if (resultado == Enums::ItemControllerResults::EsContenedor)
		resultado = ItemContoller::addItemToContenedor((Objetos::Contenedor*)contenedor, item);
	return resultado;
}
LlanyLib::Juego::Enums::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedorDelete(Objetos::Item* contenedor, Objetos::Item* item) const
{
	Enums::ItemControllerResults resultado = ItemContoller::addItemToContenedor(contenedor, item);
	if (resultado != Enums::ItemControllerResults::AddItemExitoContenedor)
		item->deleteItem();
	return resultado;
}
LlanyLib::Juego::Enums::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedor(Objetos::Contenedor* contenedor, Objetos::Item* item) const
{
	Enums::ItemControllerResults resultado = ItemContoller::isContenedor(contenedor);

	if (resultado == Enums::ItemControllerResults::EsContenedor) {
		if (item == nullptr)
			resultado = Enums::ItemControllerResults::PunteroItemNull;
		else {
			Objetos::Item* resultAdd = contenedor->add(item);
			if (resultAdd != nullptr) {
				resultado = Enums::ItemControllerResults::NoCumpleRequirimientosDelContenedor;
			}
			else
				resultado = Enums::ItemControllerResults::AddItemExitoContenedor;
		}
	}
	return resultado;
}
LlanyLib::Juego::Enums::ItemControllerResults LlanyLib::Juego::Singletons::ItemContoller::addItemToContenedorDelete(Objetos::Contenedor* contenedor, Objetos::Item* item) const
{
	Enums::ItemControllerResults resultado = ItemContoller::addItemToContenedor(contenedor, item);
	if (resultado != Enums::ItemControllerResults::AddItemExitoContenedor)
		item->deleteItem();
	return resultado;
}
#pragma endregion
