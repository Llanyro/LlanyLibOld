#pragma once
#ifndef CONTENEDOR_OBJECT_HPP_
#define CONTENEDOR_OBJECT_HPP_

#include "Item.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
	}
	namespace Juego {
		namespace Enums {
			enum class TipoDeMaterial;
			enum class TipoObjeto;
		}
		namespace Items {
			class Contenedor : public Item
			{
				protected:
					Basic::Templates::Listas::LinkedList<Item*>* listaContenedor;
					Enums::TipoDeMaterial tipoDeMaterialContenible;
					double capacidadOcupada;
					double capacidadMaxima;
				protected:
					virtual bool sePuedeAñadir(const Item* item) const;

					Item* addItemProtected(Item* item);
					Item* getItemProtected(const size_t& pos);


				public:
					#pragma region Constructores
					Contenedor();
					~Contenedor();
					#pragma endregion
					// Funcion: Añade un Item al contenedor
					// Extra: Si se intenta añadir un objeto y no se puede, devuelve el puntero al item
					// Version: Final/Beta/Alfa/PreAlfa
					// Precondiciones:
					//		item != nullptr
					// Retorno: 
					//		nullptr: Si se ha añadido el item
					//		pointer: Si se no ha añadido el item (el puntero del item pasado)
					// Complejidad temporal y espacial: O(1) y M(1)
					virtual Item* addItem(Item* item);
					virtual Item* getItem(const size_t& pos);

					bool getCapacidadOcupada() const;
					bool getCapacidadMaxima() const;
					const Basic::Templates::Listas::LinkedList<Item*>* getList() const;

					virtual Basic::Objetos::JSONBuilder* toJSONBuilder() const override;
					virtual Basic::Objetos::String* toJSON() const override;
			};
		}
	}
}
#endif // !CONTENEDOR_OBJECT_HPP_
