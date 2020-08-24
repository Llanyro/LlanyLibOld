#pragma once
#ifndef VISTA_GESTOR_ITEM_GESTORES_JUEGO_HPP_
#define VISTA_GESTOR_ITEM_GESTORES_JUEGO_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#include "../../Math/Libs/MathTypes.h"

#define VISTA_GESTOR_ITEMS LlanyLib::Juego::Gestores::VistaGestorItems::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
	}
	namespace Juego {
		namespace Objetos {
			namespace Items {
				class Item;
			}
		}
		namespace Gestores {
			class VistaGestorItems : public Basic::Templates::Singleton<VistaGestorItems>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<VistaGestorItems>;
					VistaGestorItems();
					~VistaGestorItems();
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
#endif // !VISTA_GESTOR_ITEM_GESTORES_JUEGO_HPP_
