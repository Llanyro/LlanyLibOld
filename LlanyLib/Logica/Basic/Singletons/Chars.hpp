#pragma once
#ifndef CHARS_SINGLETON_HPP_
#define CHARS_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define CHARS LlanyLib::Basic::Singletons::Chars::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Singletons {
			class Chars : public Templates::Singleton<Chars>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<Chars>;
					Chars();
					~Chars();
				#pragma endregion
				public:
					#pragma region Vectores y strings
					// Funcion: Lee toda una cadena de caracteres y devuelve el tamaño
					// Extra: Si no hay '\0' tarda hasta que encuentre basura que lo contenga
					// Version: Beta
					// Precondiciones:
					//		block != nullptr
					//		len != nullptr
					// Retorno: El tamaño del vector
					//		-1: block apunta a nullptr
					//		-2: len apunta a nullptr
					//		 0: operacion exitosa
					// Complejidad temporal y espacial: O(n) y M(1)
					inline int vectorLen(char const* const block, size_t* len) const;
					inline size_t vectorLen(char const* const block) const;
					// Funcion: Lee toda una cadena de caracteres y devuelve el tamaño
					// Extra: Si no hay '\0' tarda hasta que encuentre basura que lo contenga
					// Version: Beta
					// Precondiciones:
					//		block != nullptr
					//		len != nullptr
					// Retorno: El tamaño del vector
					//		-1: block apunta a nullptr
					//		-2: len apunta a nullptr
					//		-3: se ha excedido el tamaño indicado
					//		-4: el valor de el tamaño maximo es nullptr
					//		 0: operacion exitosa
					// Complejidad temporal y espacial: O(n) y M(1)
					inline int vectorLenMax(char const* const block, size_t* len, const size_t& maxSize) const;
					inline int compareMemoryBlocks(char const* const block1, const size_t& size_1, char const* const block2, const size_t& size_2, const size_t& sizeType, int Compare(char const* const item_a, char const* const item_b)) const;
					//inline int compareString(char const* const block1, const size_t& size_1, char const* const block2, const size_t& size_2) const;
					//inline int compareString(char const* const string1, char const* const string2) const;
					//inline int compareStringSimilar(char const* const block1, const size_t& size_1, char const* const block2, const size_t& size_2) const;
					//inline int compareStringSimilar(char const* const string1, char const* const string2) const;
					#pragma endregion
					#pragma region Chars
					int compareCharSimilar(char const* const caracter1, char const* const caracter2) const;
					inline int compareChar(const char* caracter1, const char* caracter2) const;
					inline int isAlphabet(char const* const caracter) const;
					inline int cambiarMayus(char* caracter) const;
					inline int cambiarMinus(char* caracter) const;
					#pragma endregion
			};
		}
	}
}
#endif // !CHARS_SINGLETON_HPP_
