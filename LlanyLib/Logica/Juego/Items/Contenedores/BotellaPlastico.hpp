#pragma once
#ifndef BOTELLA_PLASTICO_ITEM_OBJECT_HPP_
#define BOTELLA_PLASTICO_ITEM_OBJECT_HPP_

#include "../../Objetos/Items/Contenedor.hpp"

#define LlanyLib_Juego_Items_Generados_Contenedores_BotellaPlastico "BotellaPlastico"

namespace LlanyLib {
	namespace Juego {
		namespace Items {
			namespace Generados {
				namespace Contenedores {
					class BotellaPlastico : public Objetos::Items::Contenedor
					{
						public:
							BotellaPlastico();
							BotellaPlastico(const BotellaPlastico& other);
							bool operator=(const BotellaPlastico& other);
							~BotellaPlastico();
							virtual Item* clone() const;
							virtual void deleteItem() override;
					};
				}
			}
		}
	}
}
#endif // !BOTELLA_PLASTICO_ITEM_OBJECT_HPP_
