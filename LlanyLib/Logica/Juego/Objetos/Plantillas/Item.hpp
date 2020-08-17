#pragma once
#ifndef ITEM_OBJECT_HPP_
#define ITEM_OBJECT_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Enums {
			enum class TipoDeMaterial;
			enum class TipoObjeto;
		}
		namespace Items {
			class Item
			{
				protected:
					Basic::Objetos::String* itemName;			// Id del nombre del objeto
					Enums::TipoDeMaterial tipoDeMaterial;	// Estado del material usado para definir en grupos y permitir o no el guardado en contenedores
					Enums::TipoObjeto tipoDeObjeto;		// Indica que grupo de objetos pertenece

					double valorActual;							// Valor actual del objeto
					double valorMaximo;							// Valor de inicio o valor maximo que se puede alcanzar
					double durabilidad;							// Durabilidad del item actual
					double durabilidadMaxima;					// Durabilidad maxima del item
					double cantidad;							// Cantidad de items iguales
					//double maxStack;							// Maximo que se puede stackear de un item
					double peso;								// Peso actual del item, incluyendo en caso de ser un contenedor los pesos de los objetos guardados

					double temperatura;							// Cantidad de calor  del objeto
					double resistenciaMaterial;					// Resistencia a cambiar de temperatura de un objeto
				public:
					#pragma region Constructores
					Item();
					~Item();
					#pragma endregion
					#pragma region Getters
					const Basic::Objetos::String* getItemName() const;
					Enums::TipoDeMaterial getTipoDeMaterial() const;
					Enums::TipoObjeto getTipoObjeto() const;
					double getValorActual() const;
					double getValorMaximo() const;
					double getDurabilidad() const;
					double getDurabilidadMaxima() const;
					double getCantidad() const;
					double getPeso() const;
					double getTemperatura() const;
					double getResistenciaTemperatura() const;
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
					void setTipoDeMaterial(const Base::Enums::TipoDeMaterial& value);
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
					virtual Basic::Objetos::JSONBuilder* toJSONBuilder() const;
					virtual Basic::Objetos::String* toJSON() const;
			};
		}
	}
}
#endif // !ITEM_OBJECT_HPP_
