#pragma once
#ifndef CONTENEDOR_OBJECT_HPP_
#define CONTENEDOR_OBJECT_HPP_

#include "Item.hpp"

namespace LlanyLib
{
	namespace Base {
		namespace Objetos {
			class JSONBuilder;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
	}
	namespace Juego
	{
		namespace Enums {
			enum class TipoDeMaterial;
			enum class TipoObjeto;
		}
		namespace Items
		{
			class Contenedor : public Item
			{
				protected:
					Base::Templates::Listas::LinkedList<Item*>* contenedor;
					Enums::TipoDeMaterial tipoDeMaterialContenible;
					double capacidadOcupada;
					double capacidadMaxima;
				public:
					#pragma region Constructores
					Contenedor();
					~Contenedor();
					#pragma endregion
					virtual Basic::Objetos::JSONBuilder* toJSON() const override;
			};
		}
	}
}
#endif // !CONTENEDOR_OBJECT_HPP_
