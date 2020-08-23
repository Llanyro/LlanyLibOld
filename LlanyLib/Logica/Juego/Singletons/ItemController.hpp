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
			class Item;
			class Contenedor;
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
					Basic::Objetos::String* generateJSONString(Basic::Templates::Listas::LinkedList<Objetos::Item*>* list) const;
					Basic::Objetos::String* generateJSONStringClear(Basic::Templates::Listas::LinkedList<Objetos::Item*>* list) const;
					#pragma region Items

					#pragma endregion
					#pragma region Contenedores
					Enums::ItemControllerResults isContenedor(Objetos::Item* contenedor) const;
					Enums::ItemControllerResults isContenedor(Objetos::Contenedor* contenedor) const;

					Enums::ItemControllerResults addItemToContenedor(Objetos::Item* contenedor, Objetos::Item* item) const;
					// Si no se a�ade borra el item
					Enums::ItemControllerResults addItemToContenedorDelete(Objetos::Item* contenedor, Objetos::Item* item) const;

					Enums::ItemControllerResults addItemToContenedor(Objetos::Contenedor* contenedor, Objetos::Item* item) const;
					// Si no se a�ade borra el item
					Enums::ItemControllerResults addItemToContenedorDelete(Objetos::Contenedor* contenedor, Objetos::Item* item) const;
					#pragma endregion
			};
		}
	}
}
#endif // !ITEM_CONTROLLER_SINGLETON_HPP_
