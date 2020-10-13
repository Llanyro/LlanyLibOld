#include "VistaItemController.hpp"

#include <iostream>

#include "ItemController.hpp"
#include "../Enums/ItemEnum.hpp"
#include "../Objetos/Items/Item.hpp"
#include "../Objetos/Items/Contenedor.hpp"

LlanyLib::Juego::Singletons::VistaItemContoller::VistaItemContoller() { VistaItemContoller::subscribir(VistaItemContoller::freeInstancia); }
LlanyLib::Juego::Singletons::VistaItemContoller::~VistaItemContoller(){}

void LlanyLib::Juego::Singletons::VistaItemContoller::printResultadoAddItemToContenedor(const Enum::ItemControllerResults& val, const Objetos::Items::Item* contenedor, const Objetos::Items::Item* item) const
{
	switch (val)
	{
		case Enum::ItemControllerResults::PunteroContenedorNull:
			std::cout << "La direccion del contenedor esta a nullptr" << std::endl;
			break;
		case Enum::ItemControllerResults::NoEsContenedor:
			std::cout << "El contenedor no es un contenedor real" << std::endl;
			break;
		case Enum::ItemControllerResults::PunteroItemNull:
			std::cout << "La direccion del item esta a nullptr" << std::endl;
			break;
		case Enum::ItemControllerResults::NoCumpleRequirimientosDelContenedor:
			std::cout << "El item no cumple los requisitos del contenedor" << std::endl;
			break;
		case Enum::ItemControllerResults::AddItemExitoContenedor:
			std::cout << "Se ha aniadido el item " << item->getItemID() << " al contenedor " << contenedor->getItemID() << std::endl;
			break;
		default:
			std::cout << "Debe de haber habido algun error en al añadir el objeto";
			break;
	}
}

#pragma region Items
void LlanyLib::Juego::Singletons::VistaItemContoller::deleteItem(Objetos::Items::Item* item) const
{
	if (item == nullptr)
		std::cout << "No se puede eliminar un item cuya direccion es nullptr" << std::endl;
	else {
		std::cout << "Se ha eliminado exitosamente el item " << item->getItemID();
		if (item->getTipoObjeto() == Enum::TipoObjeto::Contenedor)
			std::cout << ". Y todo su contenido." << std::endl;
		else
			std::cout << std::endl;
		item->deleteItem();
	}
}
#pragma endregion
#pragma region Contenedores
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::VistaItemContoller::addItemToContenedor(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = ITEM_CONTROLLER->addItemToContenedor(contenedor, item);
	VistaItemContoller::printResultadoAddItemToContenedor(resultado, contenedor, item);
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::VistaItemContoller::addItemToContenedorDelete(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = VistaItemContoller::addItemToContenedor(contenedor, item);
	if (resultado != Enum::ItemControllerResults::AddItemExitoContenedor)
		VistaItemContoller::deleteItem(item);
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::VistaItemContoller::addItemToContenedor(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = VistaItemContoller::addItemToContenedor((Objetos::Items::Item*)contenedor, item);
	return resultado;
}
LlanyLib::Juego::Enum::ItemControllerResults LlanyLib::Juego::Singletons::VistaItemContoller::addItemToContenedorDelete(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const
{
	Enum::ItemControllerResults resultado = VistaItemContoller::addItemToContenedor(contenedor, item);
	if (resultado != Enum::ItemControllerResults::AddItemExitoContenedor)
		VistaItemContoller::deleteItem(item);
	return resultado;
}
#pragma endregion
