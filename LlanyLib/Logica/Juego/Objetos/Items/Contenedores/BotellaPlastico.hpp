#pragma once
#ifndef BOTELLA_PLASTICO_ITEM_OBJECT_HPP_
#define BOTELLA_PLASTICO_ITEM_OBJECT_HPP_

#include "../../Plantillas/Contenedor.hpp"

namespace LlanyLib
{
	namespace Juego
	{
		namespace Enums {
			enum class TipoDeMaterial;
		}
		namespace Items {
			namespace Generados {
				namespace Contenedores {
					class BotellaPlastico : public Contenedor
					{
						public:
							#pragma region Constructores
							BotellaPlastico();
							~BotellaPlastico();
							#pragma endregion
					};
				}
			}
		}
	}
}
#endif // !BOTELLA_PLASTICO_ITEM_OBJECT_HPP_
