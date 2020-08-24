#pragma once
#ifndef FAMILIAR_ENTIDADES_OBJECT_JUEGO_HPP_
#define FAMILIAR_ENTIDADES_OBJECT_JUEGO_HPP_

#include "Entidad.hpp"

namespace LlanyLib {
	namespace Juego {
		namespace Objetos {
			namespace Entidades {
				class Familiar : public Entidad
				{
					protected:
						Entidad* invocador;	// Puntero al invocador del familiar
					public:
						#pragma region Constructores
						Familiar();
						Familiar(const Familiar& other);
						bool operator=(const Familiar& other);
						~Familiar();
						#pragma endregion
						#pragma region Getters
						Entidad* getInvocador() const;
						#pragma endregion
						#pragma region Setters
						void setInvocador(Entidad* invocador);
						#pragma endregion
						#pragma region Adders

						#pragma endregion
						#pragma region Compares
						bool igual(const Familiar& other) const;
						//bool similar(const Familiar& other) const;
						#pragma endregion
						#pragma region Operators
						bool operator==(const Familiar& other) const;
						bool operator!=(const Familiar& other) const;
						#pragma endregion
						virtual Entidad* clone() const override;
				};
			}
		}
	}
}
#endif // !FAMILIAR_ENTIDADES_OBJECT_JUEGO_HPP_
