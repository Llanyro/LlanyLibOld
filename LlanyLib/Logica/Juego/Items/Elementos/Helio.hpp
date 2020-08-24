#pragma once
#ifndef HELIO_ITEM_OBJECT_HPP_
#define HELIO_ITEM_OBJECT_HPP_

#include "../../Objetos/Items/Item.hpp"

#define LlanyLib_Juego_Items_Generados_Elementos_Helio "Helio"

namespace LlanyLib {
	namespace Juego {
		namespace Enums {
			enum class TipoDeMaterial;
		}
		namespace Items {
			namespace Generados {
				namespace Elementos {
					class Helio : public Objetos::Items::Item
					{
						public:
							Helio();
							Helio(
								// Cantidad en litros / unidades
								const double& cantidad,
								// Tipo de estado del material
								const Enums::TipoDeMaterial& material);
							Helio(
								// Cantidad en litros / unidades
								const double& cantidad);
							~Helio();
							Helio(const Helio& other);
							bool operator=(const Helio& other);
							virtual Item* clone() const;
							virtual void deleteItem() override;
					};
				}
			}
		}
	}
}
#endif // !HELIO_ITEM_OBJECT_HPP_
