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
		namespace Objetos {
			class ListItem;
			class Contenedor : public Item
			{
				protected:
					ListItem* listaContenedor;
					Enums::TipoDeMaterial tipoDeMaterialContenible;
					double capacidadOcupada;
					double capacidadMaxima;
				protected:
					#pragma region Protected
					virtual bool sePuedeAñadir(const Item* item) const;
					Item* addItemProtected(Item* item);
					Item* getItemProtected(const size_t& pos);
					#pragma endregion
				public:
					#pragma region Constructores
					Contenedor();
					Contenedor(const Contenedor& other);
					Contenedor(const Contenedor* other);
					bool operator=(const Contenedor& other);
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
					#pragma region Getter && add
					virtual Item* addItem(Item* item);
					virtual Item* getItem(const size_t& pos);

					bool getCapacidadOcupada() const;
					bool getCapacidadMaxima() const;
					const Item* get(const size_t& pos) const;
					#pragma endregion
					#pragma region Virtual
					virtual Item* clone() const;
					virtual Basic::Objetos::JSONBuilder* toJSONBuilder() const;
					virtual Basic::Objetos::String* toJSON() const;
					int compare(const Contenedor& other) const;
					bool similar(const Contenedor& other) const;
					bool equals(const Contenedor& other) const;
					bool igualMenosCantidad(const Contenedor& other) const;
					bool operator==(const Contenedor& other) const;
					bool operator!=(const Contenedor& other) const;
					#pragma endregion
			};
		}
	}
}
#endif // !CONTENEDOR_OBJECT_HPP_
