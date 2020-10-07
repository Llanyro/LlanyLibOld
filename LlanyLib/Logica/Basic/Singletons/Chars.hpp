#pragma once
#ifndef CHARS_SINGLETON_HPP_
#define CHARS_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define CHARS LlanyLib::Basic::Singletons::Chars::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos { class String; }
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
					inline int vectorLen(const char* block, size_t* len);
					inline size_t vectorLen(const char* block);
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
					inline int vectorLenMax(const char* block, size_t* len, const size_t& maxSize);
					inline int compareMemoryBlocks(const char* block1, const size_t& size_1, const char* block2, const size_t& size_2, const size_t& sizeType, int Compare(const char* item_a, const char* item_b));
					inline int compareString(const char* block1, const size_t& size_1, const char* block2, const size_t& size_2);
					inline int compareString(const char* string1, const char* string2);
					inline int compareStringSimilar(const char* block1, const size_t& size_1, const char* block2, const size_t& size_2);
					inline int compareStringSimilar(const char* string1, const char* string2);
					#pragma endregion
					#pragma region Chars
					int compareCharSimilar(const char* caracter1, const char* caracter2);
					inline int compareChar(const char* char_a, const char* char_b);
					inline int isAlphabet(const char* caracter);
					inline int cambiarMayus(char* caracter);
					inline int cambiarMinus(char* caracter);
					#pragma endregion
					#pragma region Conversiones
					Objetos::String* toString(const bool& value) const;
					Objetos::String* toString(const short& value) const;
					Objetos::String* toString(const unsigned short& value) const;
					Objetos::String* toString(const int& value) const;
					Objetos::String* toString(const unsigned int& value) const;
					Objetos::String* toString(const float& value) const;
					Objetos::String* toString(const double& value) const;
					Objetos::String* toString(const long& value) const;
					Objetos::String* toString(const unsigned long& value) const;
					Objetos::String* toString(const long long& value) const;
					Objetos::String* toString(const unsigned long long& value) const;
					#pragma endregion
			};
		}
	}
}
#endif // !CHARS_SINGLETON_HPP_
