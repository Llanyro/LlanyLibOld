#pragma once
#ifndef GESTOR_ITEM_GESTORES_JUEGO_HPP_
#define GESTOR_ITEM_GESTORES_JUEGO_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#include "../../Basic/LibreriasSimples/LlanyTypes.h"

#define GESTOR_ITEMS LlanyLib::Juego::Gestores::GestorItems::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
		namespace Templates {
			namespace Diccionarios {
				template<class T1, class T2>
				class DictionaryLinkedList;
			}
			namespace Nodos {
				template<class T1, class T2>
				class NDODP;
			}
		}
	}
	namespace Juego {
		namespace Objetos {
			namespace Items{
				class Item;
			}
		}
		namespace Gestores {
			#define NODO LlanyLib::Basic::Templates::Nodos::NDODP<LlanyLib::Basic::Objetos::String*, LlanyLib::Juego::Objetos::Items::Item*>

			class GestorItems : public Basic::Templates::Singleton<GestorItems>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<GestorItems>;
					GestorItems();
					~GestorItems();
				#pragma endregion
				protected:
					Basic::Templates::Diccionarios::DictionaryLinkedList<
						Basic::Objetos::String*, 
						Objetos::Items::Item*
					>* registro;
				protected:
					#pragma region Protected
					bool containsName(char const* const registerName) const;
					NODO* buscarNodo(char const* const registerName) const;
					long_t buscarID(char const* const registerName) const;
					#pragma endregion
				public:
					#pragma region Registro y generacion
					bool itemRegister(Objetos::Items::Item* item, char const* const registerName);
					Objetos::Items::Item* newItem(char const* const registerName) const;
					#pragma endregion
					#pragma region Getters
					const Basic::Objetos::String* getRegisterName(const long_t& itemID) const;
					long_t getID(char const* const registerName) const;
					long_t getID(Basic::Objetos::String* registerName) const;
					long_t getIDClear(Basic::Objetos::String* registerName) const;
					#pragma endregion
			};
		}
	}
}
#endif // !GESTOR_ITEM_GESTORES_JUEGO_HPP_
