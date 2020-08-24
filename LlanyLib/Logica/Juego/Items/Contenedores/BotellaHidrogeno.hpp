#pragma once
#ifndef BOTELLA_HIDROGENO_ITEM_OBJECT_HPP_
#define BOTELLA_HIDROGENO_ITEM_OBJECT_HPP_

#include "../../Objetos/Items/Contenedor.hpp"

#define LlanyLib_Juego_Items_Generados_Contenedores_BotellaHidrogeno "BotellaHidrogeno"

namespace LlanyLib {
	namespace Juego {
		namespace Items {
			namespace Generados {
				namespace Contenedores {
					class BotellaHidrogeno : public Objetos::Items::Contenedor
					{
						protected:
							virtual bool sePuedeAñadir(const Item* item) const;
						public:
							BotellaHidrogeno();
							BotellaHidrogeno(const BotellaHidrogeno& other);
							bool operator=(const BotellaHidrogeno& other);
							~BotellaHidrogeno();
							#pragma region Other
							virtual Item* clone() const;
							virtual void deleteItem() override;
							#pragma endregion
					};
				}
			}
		}
	}
}
#endif // !BOTELLA_HIDROGENO_ITEM_OBJECT_HPP_
