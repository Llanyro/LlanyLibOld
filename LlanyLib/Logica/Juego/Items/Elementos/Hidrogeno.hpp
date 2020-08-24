#pragma once
#ifndef HIDROGENO_ITEM_OBJECT_HPP_
#define HIDROGENO_ITEM_OBJECT_HPP_

#include "../../Objetos/Items/Item.hpp"

#define LlanyLib_Juego_Items_Generados_Elementos_Hidrogeno "Hidrogeno"

namespace LlanyLib {
	namespace Juego {
		namespace Enums {
			enum class TipoDeMaterial;
		}
		namespace Items {
			namespace Generados {
				namespace Elementos {
					class Hidrogeno : public Objetos::Items::Item
					{
						public:
							Hidrogeno();
							Hidrogeno(
								// Cantidad en litros / unidades
								const double& cantidad,
								// Tipo de estado del material
								const Enums::TipoDeMaterial& material);
							Hidrogeno(
								// Cantidad en litros / unidades
								const double& cantidad);
							~Hidrogeno();
							Hidrogeno(const Hidrogeno& other);
							bool operator=(const Hidrogeno& other);
							virtual Item* clone() const;
							virtual void deleteItem() override;
					};
				}
			}
		}
	}
}
#endif // !HIDROGENO_ITEM_OBJECT_HPP_
