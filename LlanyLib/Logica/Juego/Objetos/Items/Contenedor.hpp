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
			enum class Ordenamiento;
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
				#pragma region No virtual
				protected:
					#pragma region Protected
					Item* addProtected(Item* item);
					#pragma endregion
				public:
					#pragma region Constructores
					Contenedor();
					Contenedor(const Contenedor& other);
					bool operator=(const Contenedor& other);
					~Contenedor();
					#pragma endregion
					#pragma region Getters
					bool getCapacidadOcupada() const;
					bool getCapacidadMaxima() const;
					#pragma endregion
					#pragma region Contenedor
					void clear();
					void ordenar(const Enums::Ordenamiento& ord);
					const Item* get(const size_t& pos) const;
					#pragma endregion
				#pragma endregion
				#pragma region Virtual
				protected:
					#pragma region Protected
					virtual bool sePuedeAñadir(const Item* item) const;
					virtual bool cabeItem(const Item* item) const;
					#pragma endregion
				public:
					#pragma region Contenedor
					virtual LlanyLib::Juego::Objetos::Item* add(Item* item);
					virtual Item* extractItem(const size_t& pos);
					virtual Item* extractItem(const size_t& pos, const double& cantidad);
					#pragma endregion
					#pragma region Other
					virtual Item* clone() const;
					virtual Basic::Objetos::JSONBuilder* toJSONBuilder() const;
					virtual Basic::Objetos::String* toJSON() const;
					virtual void deleteItem() override;
					virtual int compare(const Contenedor& other) const;
					virtual bool similar(const Contenedor& other) const;
					virtual bool equals(const Contenedor& other) const;
					virtual bool igualMenosCantidad(const Contenedor& other) const;
					virtual bool operator==(const Contenedor& other) const;
					virtual bool operator!=(const Contenedor& other) const;
					#pragma endregion
				#pragma endregion
			};
		}
	}
}
#endif // !CONTENEDOR_OBJECT_HPP_
