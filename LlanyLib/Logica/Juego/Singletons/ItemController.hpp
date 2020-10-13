#pragma once
#ifndef ITEM_CONTROLLER_SINGLETON_HPP_
#define ITEM_CONTROLLER_SINGLETON_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#include "../Enums/ItemControllerEnum.hpp"

#define ITEM_CONTROLLER LlanyLib::Juego::Singletons::ItemContoller::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
	}
	namespace Juego {
		namespace Objetos {
			namespace Items {
				class Item;
				class Contenedor;
			}
		}
		namespace Singletons {
			class ItemContoller : public Basic::Templates::Singleton<ItemContoller>, Basic::Gestores::SubscriptorSingletons
			{
				private:
					#pragma region Constructores
					friend class Singleton<ItemContoller>;
					ItemContoller();
					~ItemContoller();
					#pragma endregion
				public:
					Basic::Objetos::String* generateJSONString(Basic::Templates::Listas::LinkedList<Objetos::Items::Item*>* list) const;
					Basic::Objetos::String* generateJSONStringClear(Basic::Templates::Listas::LinkedList<Objetos::Items::Item*>* list) const;
					#pragma region Items

					#pragma endregion
					#pragma region Contenedores
					Enum::ItemControllerResults isContenedor(Objetos::Items::Item* contenedor) const;
					Enum::ItemControllerResults isContenedor(Objetos::Items::Contenedor* contenedor) const;

					Enum::ItemControllerResults addItemToContenedor(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const;
					// Si no se añade borra el item
					Enum::ItemControllerResults addItemToContenedorDelete(Objetos::Items::Item* contenedor, Objetos::Items::Item* item) const;

					Enum::ItemControllerResults addItemToContenedor(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const;
					// Si no se añade borra el item
					Enum::ItemControllerResults addItemToContenedorDelete(Objetos::Items::Contenedor* contenedor, Objetos::Items::Item* item) const;
					#pragma endregion
			};
		}
	}
}
#endif // !ITEM_CONTROLLER_SINGLETON_HPP_
