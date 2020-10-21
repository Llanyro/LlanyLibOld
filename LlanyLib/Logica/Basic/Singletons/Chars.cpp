#include "Chars.hpp"

#include <cassert>
#include <string>

#include "../LibreriasSimples/ASCII_Defines.h"

#include "Mem.hpp"

LlanyLib::Basic::Singletons::Chars::Chars() { Chars::subscribir(Chars::freeInstancia); }
LlanyLib::Basic::Singletons::Chars::~Chars(){}
#pragma region Vectores y strings
int LlanyLib::Basic::Singletons::Chars::vectorLen(char const* const block, size_t* len) const
{
	int resultado = 0;
	if (block == nullptr) resultado = -1;
	else if (len == nullptr) resultado = -2;
	else {
		*len = 0; // Si el bloque no es nullptr podemos empezar a contar
		while (block[*len] != '\0')
			(*len)++;
	}
	return resultado;
}
inline size_t LlanyLib::Basic::Singletons::Chars::vectorLen(char const* const block) const
{
	size_t resultado = 0;
	if (block != nullptr){
		while (block[resultado] != '\0')
			resultado++;
	}
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::vectorLenMax(char const* const block, size_t* len, const size_t& maxSize) const
{
	int resultado = 0;
	if (block == nullptr) resultado = -1;
	else if (len == nullptr) resultado = -2;
	else if (&maxSize == nullptr) resultado = -4;
	else {
		*len = 0; // Si el bloque no es nullptr podemos empezar a contar
		while (block[*len] != '\0' && *len < maxSize)
			(*len)++;
		if (*len >= maxSize)
			resultado = -3;
	}
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::compareMemoryBlocks(char const* const block1, const size_t& size_1, char const* const block2, const size_t& size_2, const size_t& sizeType, int Compare(char const* const item_a, char const* const item_b)) const
{
	assert(Compare != nullptr);
	assert(&size_1 != nullptr);
	assert(&size_2 != nullptr);
	assert(&sizeType != nullptr);
	int resultado = 0;
	if (block1 == nullptr && block2 == nullptr) resultado = 0;	// Iguales
	else if (block1 == nullptr) resultado = -1;					// Bloque 2 mayor
	else if (block2 == nullptr) resultado = 1;					// Bloque 1 mayor
	else if (size_1 > size_2) resultado = 1;					// Bloque 1 mayor
	else if (size_1 < size_2) resultado = -1;					// Bloque 2 mayor
	else {														// Mismo tamaño
		for (size_t i = 0; i < size_1 && resultado == 0; i++)
			resultado = Compare(
				MEM->autoPointer(block1, i),
				MEM->autoPointer(block2, i));
	}
	return resultado;
}
/*int LlanyLib::Basic::Singletons::Chars::compareString(char const* const block1, const size_t& size_1, char const* const block2, const size_t& size_2) const
{
	return 0;//Chars::compareMemoryBlocks(block1, size_1, block2, size_2, sizeof(char), CHARS->compareChar);
}
int LlanyLib::Basic::Singletons::Chars::compareString(char const* const string1, char const* const string2) const
{
	int resultado = 0;

	size_t sizeSting1 = 0;
	size_t sizeSting2 = 0;

	if (vectorLen(string1, &sizeSting1) == 0)
		if (vectorLen(string2, &sizeSting2) == 0)
			resultado = 0;
		else
			resultado = -1;
	else
		resultado = -2;

	if (resultado == 0)
		resultado = compareString(string1, sizeSting1, string2, sizeSting2);

	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::compareStringSimilar(char const* const block1, const size_t& size_1, char const* const block2, const size_t& size_2) const
{
	int resultado = 0;
	size_t min = 0;

	if (size_1 > size_2) {
		for (size_t i = 0; resultado == 0 && i < size_2; i++)
			resultado = Chars::compareCharSimilar(block1 + i, block2 + i);
		if (resultado == 0)
			resultado = 1;
	}
	else if(size_1 < size_2) {
		for (size_t i = 0; resultado == 0 && i < size_1; i++)
			resultado = Chars::compareCharSimilar(block1 + i, block2 + i);
		if (resultado == 0)
			resultado = -1;
	}
	else
		for (size_t i = 0; resultado == 0 && i < size_1; i++)
			resultado = Chars::compareCharSimilar(block1 + i, block2 + i);

	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::compareStringSimilar(char const* const string1, char const* const string2) const
{
	size_t sizeSting1 = strlen(string1);
	size_t sizeSting2 = strlen(string2);
	return compareStringSimilar(string1, sizeSting1, string2, sizeSting2);
}*/
#pragma endregion
#pragma region Chars
int LlanyLib::Basic::Singletons::Chars::compareCharSimilar(char const* const caracter1, char const* const caracter2) const
{
	int resultado = 0;
	if (caracter1 == nullptr && caracter2 == nullptr) resultado = 0;// Ambos son iguales
	else if (caracter1 == nullptr) resultado = -1;					// Caracter 2 mayor
	else if (caracter2 == nullptr) resultado = 1;					// Caracter 1 mayor
	else if (*caracter1 == *caracter2) resultado = 0;				// Ambos son iguales
	else {
		// Tipo de caracteres
		int caracterType1 = isAlphabet(caracter1);
		int caracterType2 = isAlphabet(caracter2);

		// Si ambos caracteres son del alfabeto
		// Si ambos son de tipo diferente(Mayus y minus)
		if (caracterType1 != 0 && caracterType2 != 0 && caracterType1 != caracterType2) {

			// Si la primera es mayus (La segunda minus)
			if (caracterType1 == 1 && (*caracter1 + DIFERENCIA_MAYUS_MINUS) == *caracter2)
				resultado = 0;
			// Si la primera es minus (La segunda mayus)
			else if (caracterType1 == -1 && (*caracter1 - DIFERENCIA_MAYUS_MINUS) == *caracter2)
				resultado = 0;
			else
				resultado = -2;
		}
		else if (*caracter1 > * caracter2) resultado = 1;			// Caracter 1 mayor
		else if (*caracter1 < *caracter2) resultado = -1;			// Caracter 2 mayor
		else
			resultado = -3;
	}

	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::compareChar(const char* caracter1, const char* caracter2) const{
	int resultado = 0;
	if (caracter1 == nullptr && caracter2 == nullptr) resultado = 0;			// Ambos son iguales
	else if (caracter1 == nullptr) resultado = -1;								// Caracter 2 mayor
	else if (caracter2 == nullptr) resultado = 1;								// Caracter 1 mayor
	else if (*caracter1 == *caracter2) resultado = 0;	// Ambos son iguales
	else if (*caracter1 > *caracter2) resultado = 1;	// Caracter 1 mayor
	else if (*caracter1 < *caracter2) resultado = -1;	// Caracter 2 mayor
	else resultado = -2;														// Other
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::isAlphabet(char const* const caracter) const
{
	int result = 0;
	if (caracter == nullptr) result = 0;						// Other
	else if (*caracter > 64 && *caracter < 91) result = 1;	// Mayus
	else if (*caracter > 96 && *caracter < 123) result = -1;// Minus
	else result = 0;										// Other
	return result;
}
int LlanyLib::Basic::Singletons::Chars::cambiarMayus(char* caracter) const
{
	int resultado = 1;
	if (caracter == nullptr) resultado = -1;
	else if (isAlphabet(caracter) == -1)
		*caracter -= DIFERENCIA_MAYUS_MINUS;
	else resultado = 0;
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::cambiarMinus(char* caracter) const
{
	int resultado = 1;
	if (caracter == nullptr) resultado = -1;
	else if (isAlphabet(caracter) == 1)
		*caracter += DIFERENCIA_MAYUS_MINUS;
	else resultado = 0;
	return resultado;
}
#pragma endregion
