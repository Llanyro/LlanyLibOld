#pragma once
#ifndef ITEM_OBJECT_JUEGO_HPP_
#define ITEM_OBJECT_JUEGO_HPP_

#include "../../../Basic/LibreriasSimples/LlanyTypes.h"
//#include "../Gestores/GestorItems.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Gestores {
			class GestorItems;
		}
		namespace Enum {
			enum class TipoDeMaterial;
			enum class TipoObjeto;
		}
		namespace Objetos {
			namespace Items {
				class Item 
				{
					private:
						long_t itemID;							// Id del objeto
						friend class Gestores::GestorItems;
					protected:
						Enum::TipoDeMaterial tipoDeMaterial;	// Estado del material usado para definir en grupos y permitir o no el guardado en contenedores
						Enum::TipoObjeto tipoDeObjeto;			// Indica que grupo de objetos pertenece
						Basic::Objetos::String* itemShowName;		// Nombre a mostrar en el juego

						double valorActual;						// Valor actual del objeto
						double valorMaximo;						// Valor de inicio o valor maximo que se puede alcanzar
						double durabilidad;						// Durabilidad del item actual
						double durabilidadMaxima;				// Durabilidad maxima del item
						double cantidad;						// Cantidad de items iguales
						double peso;							// Peso actual del item, incluyendo en caso de ser un contenedor los pesos de los objetos guardados

						double temperatura;						// Cantidad de calor  del objeto
						double resistenciaMaterial;				// Resistencia a cambiar de temperatura de un objeto
					public:
						#pragma region Constructores
						Item();
						Item(const Item& other);
						bool operator=(const Item& other);
						~Item();
						#pragma endregion
						#pragma region Getters
						long_t getItemID() const;
						Enum::TipoDeMaterial getTipoDeMaterial() const;
						Enum::TipoObjeto getTipoObjeto() const;
						const Basic::Objetos::String* getShowName() const;
						double getValorActual() const;
						double getValorMaximo() const;
						double getDurabilidad() const;
						double getDurabilidadMaxima() const;
						double getCantidad() const;
						double getPeso() const;
						double getTemperatura() const;
						double getResistenciaTemperatura() const;
						#pragma endregion
						#pragma region Setters
						void setCantidad(const double& value);
						#pragma endregion
						#pragma region Adders
						void addCantidad(const double& value);
						#pragma endregion
						/*#pragma region Setters
						void setItemName(char const* const nombre);
						void setItemName(Base::Objetos::String*& nombre);
						void setValorActual(const double& value);
						void setValorMaximo(const double& value);
						void setDurabilidad(const double& value);
						void setDurabilidadMaxima(const double& value);
						void setCantidad(const double& value);
						void setPeso(const double& value);
						void setTipoDeMaterial(const Base::Enum::TipoDeMaterial& value);
						void setTemperatura(const double& value);
						void setResistenciaTemperatura(const double& value);
						#pragma endregion
						#pragma region Adders
						void addValorActual(const double& value);
						void addValorMaximo(const double& value);
						void addDurabilidad(const double& value);
						void addDurabilidadMaxima(const double& value);
						void addCantidad(const double& value);
						void addPeso(const double& value);
						void addTemperatura(const double& value);
						void addResistenciaTemperatura(const double& value);
						#pragma endregion*/
						#pragma region Virtual
						virtual Item* clone() const;
						virtual Basic::Objetos::JSONBuilder* toJSONBuilder() const;
						virtual Basic::Objetos::String* toJSON() const;
						virtual void deleteItem();
						int compare(const Item& other) const;
						bool similar(const Item& other) const;
						bool equals(const Item& other) const;
						bool igualMenosCantidad(const Item& other) const;
						bool operator==(const Item& other) const;
						bool operator!=(const Item& other) const;
						#pragma endregion
				};
			}
		}
	}
}
#endif // !ITEM_OBJECT_HPP_
