#pragma once
#ifndef VISTA_ITEM_CONTROLLER_SINGLETON_HPP_
#define VISTA_ITEM_CONTROLLER_SINGLETON_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#include "../Enums/ItemControllerEnum.hpp"

#define VISTA_ITEM_CONTROLLER LlanyLib::Juego::Singletons::VistaItemContoller::getInstancia()

namespace LlanyLib {
	namespace Juego {
		namespace Objetos {
			namespace Items {
				class Item;
				class Contenedor;
			}
		}
		namespace Singletons {
			class VistaItemContoller : public Basic::Templates::Singleton<VistaItemContoller>, Basic::Gestores::SubscriptorSingletons
			{
				private:
					#pragma region Constructores
					friend class Singleton<VistaItemContoller>;
					VistaItemContoller();
					~VistaItemContoller();
					#pragma endregion
				protected:
					void printResultadoAddItemToContenedor(const Enums::ItemControllerResults& val, const Objetos::Items::Item* contenedor, const Objetos::Items::Item* item) const;
				public:
					#pragma region Items
					void deleteItem(Objetos::Items::Item* item) const;
					#pragma endregion
					#pragma region Contenedores
					Enums::ItemControllerResults addItemToContenedor(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const;
					// Si no se añade borra el item
					Enums::ItemControllerResults addItemToContenedorDelete(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const;

					Enums::ItemControllerResults addItemToContenedor(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const;
					// Si no se añade borra el item
					Enums::ItemControllerResults addItemToContenedorDelete(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const;
					#pragma endregion

			};
		}
	}
}
#endif // !VISTA_ITEM_CONTROLLER_SINGLETON_HPP_
