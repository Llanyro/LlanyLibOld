#pragma once
#ifndef ITEM_CONTROLLER_SINGLETON_HPP_
#define ITEM_CONTROLLER_SINGLETON_HPP_

#include "../../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../../Basic/Gestores/SubscriptorSingletons.hpp"

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
		namespace Items {
			class Item;
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
					Basic::Objetos::String* generateJSONString(Basic::Templates::Listas::LinkedList<Items::Item*>* list) const;
					Basic::Objetos::String* generateJSONStringClear(Basic::Templates::Listas::LinkedList<Items::Item*>* list) const;
			};
		}
	}
}
#endif // !ITEM_CONTROLLER_SINGLETON_HPP_
