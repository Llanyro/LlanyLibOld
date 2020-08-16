#pragma once
#ifndef RANDOM_SINGLETON_HPP_
#define RANDOM_SINGLETON_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define RANDOM LlanyLib::Math::Singletons::Random::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
	}
	namespace Math {
		namespace Singletons {
			class Random : public Basic::Templates::Singleton<Random>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<Random>;
					Random();
					~Random();
				#pragma endregion
				public:
					#pragma region Rangos
					// Funcion: Devuelve un valor entero random entre los valores min y max
					// Retorno: Valor aleatorio
					// Complejidad temporal y espacial: O(1) y M(1)
					size_t range(const size_t& min, const size_t& max) const;
					// Funcion: Devuelve un valor entero random entre los valores 0 y value
					// Retorno: Valor aleatorio
					// Complejidad temporal y espacial: O(1) y M(1)
					size_t range(const size_t& value) const;
					char getRandomChar() const;
					char getRandomCharAbecedario() const;
					char getRandomCharEspecial() const;
					#pragma endregion
					#pragma region Strings
					// Devuelve un string aleatorio que solo posee caracteres del abecedario
					Basic::Objetos::String* stringAbecedario(const size_t& size) const;
					// Devuelve un string aleatorio que posee todo tipo de caracteres menos el '\0'
					Basic::Objetos::String* stringCompleto(const size_t& size) const;
					// Devuelve un string aleatorio que posee solo caracteres especiales '\0'
					Basic::Objetos::String* stringEspeciales(const size_t& size) const;
					Basic::Objetos::String* stringCaracteresEspecificos(const size_t& size, Basic::Templates::Listas::LinkedList<char>* listaCaracteres) const;
					Basic::Objetos::String* stringCaracteresEspecificosClear(const size_t& size, Basic::Templates::Listas::LinkedList<char>* listaCaracteres) const;
					#pragma endregion
			};
		}
	}
}
#endif // !RANDOM_SINGLETON_HPP_
