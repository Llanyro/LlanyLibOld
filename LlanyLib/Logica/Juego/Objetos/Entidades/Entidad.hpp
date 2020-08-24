#pragma once
#ifndef ENTIDAD_ENTIDADES_OBJECT_JUEGO_HPP_
#define ENTIDAD_ENTIDADES_OBJECT_JUEGO_HPP_

#include "../../Enums/EntidadesEnum.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			namespace Stats {
				class Stats;
			}
			namespace Entidades {
				class Familiar;
				class Entidad
				{
					protected:
						Basic::Objetos::String* nombre;		// Name
						Enums::TipoDeEntidad tipoDeEntidad;	// Tipo de entidad: Player, npc, familiar...
						Stats::Stats* stats;				// Stats de la entidad
						//Equipamiento* equipamiento;		// Equipamiento de la entidad
						//Inventario* inventario;			// Inventario de la entidad
						Familiar* familiar;					// Familiar de la entidad (Si añades un 2º player saldra aqui como familiar)
					public:
						#pragma region Constructores
						Entidad();
						//Entidad(const String& contenidoJSON);
						//Entidad(const Basic::Objetos::String& nombre, const Enums::TipoDeEntidad& tipoDeEntidad);
						Entidad(const Entidad& other);
						bool operator=(const Entidad& other);
						~Entidad();
						#pragma endregion
						#pragma region Getters
						const Basic::Objetos::String* getNombre() const;
						Stats::Stats* getStats() const;
						//Inventario* getInventario() const;
						//Equipamiento* getEquipamiento() const;
						Enums::TipoDeEntidad getTipoDeEntidad() const;
						Familiar* getFamiliar() const;
						#pragma endregion
						#pragma region Setters
						//void setNombre(const String& nombre);
						void setTipoDeEntidad(const Enums::TipoDeEntidad& value);
						// Se recoge el puntero, es decir, no se clona el familiar(Cuidado!)
						void setFamiliar(Familiar* familiar);
						#pragma endregion
						#pragma region Adders

						#pragma endregion
						#pragma region Compares
						bool igual(const Entidad& other) const;
						//bool similar(const Entidad& other) const;
						#pragma endregion
						#pragma region Operators
						bool operator==(const Entidad& other) const;
						bool operator!=(const Entidad& other) const;
						#pragma endregion
						virtual Entidad* clone() const;
						//String toJSON() const;
				};
			}
		}
	}
}
#endif // !ENTIDAD_ENTIDADES_OBJECT_JUEGO_HPP_
