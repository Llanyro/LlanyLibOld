#pragma once
#ifndef LISTA_ITEM_OBJECT_JUEGO_HPP_
#define LISTA_ITEM_OBJECT_JUEGO_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
	}
	namespace Juego {
		namespace Enum { enum class Ordenamiento; }
		namespace Objetos {
			namespace Items {
				class Item;
				class ListItem
				{
					protected:
						Basic::Templates::Listas::LinkedList<Item*>* list;
					protected:
						Item* getItemIgual(Item* item) const;
					public:
						ListItem();
						~ListItem();
						bool operator=(const ListItem& other);
						bool add(Item* item);
						void clear();
						void ordenar(const Enum::Ordenamiento& ord);
						const Item* get(const size_t& pos) const;
						Item* extractItem(const size_t& pos) const;
						Item* extractItem(const size_t& pos, const double& cantidad) const;
						bool equals(const ListItem& other) const;
						Basic::Templates::Listas::LinkedList<Item*>* getList() const;
				};
			}
		}
	}
}
#endif // !LISTA_ITEM_OBJECT_JUEGO_HPP_
