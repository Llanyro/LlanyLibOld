#pragma once
#ifndef HIDROGENO_ITEM_OBJECT_HPP_
#define HIDROGENO_ITEM_OBJECT_HPP_

#include "../../Plantillas/Item.hpp"

namespace LlanyLib {
	namespace Juego {
		namespace Enums {
			enum class TipoDeMaterial;
		}
		namespace Items {
			namespace Generados {
				namespace Elementos {
					class Hidrogeno : public Item
					{
						public:
							#pragma region Constructores
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
							#pragma endregion
					};
				}
			}
		}
	}
}
#endif // !HIDROGENO_ITEM_OBJECT_HPP_
