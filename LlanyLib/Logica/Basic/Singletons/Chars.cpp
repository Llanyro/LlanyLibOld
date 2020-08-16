#include "Chars.hpp"

#include <cassert>
#include <string>

#include "../LibreriasSimples/ASCII_Defines.h"
#include "../Objetos/String.hpp"
#include "Mem.hpp"

LlanyLib::Basic::Singletons::Chars::Chars() { Chars::subscribir(Chars::freeInstancia); }
LlanyLib::Basic::Singletons::Chars::~Chars(){}
#pragma region Vectores y strings
int LlanyLib::Basic::Singletons::Chars::vectorLen(const char* block, size_t* len)
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
inline size_t LlanyLib::Basic::Singletons::Chars::vectorLen(const char* block)
{
	size_t resultado = 0;
	if (block != nullptr){
		while (block[resultado] != '\0')
			resultado++;
	}
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::vectorLenMax(const char* block, size_t* len, const size_t& maxSize)
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
int LlanyLib::Basic::Singletons::Chars::compareMemoryBlocks(const char* block1, const size_t& size_1, const char* block2, const size_t& size_2, const size_t& sizeType, int Compare(const char* item_a, const char* item_b))
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
int LlanyLib::Basic::Singletons::Chars::compareString(const char* block1, const size_t& size_1, const char* block2, const size_t& size_2)
{
	return 0;//compareMemoryBlocks(block1, size_1, block2, size_2, sizeof(char), CHARS->compareChar);
}
int LlanyLib::Basic::Singletons::Chars::compareString(const char* string1, const char* string2)
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
int LlanyLib::Basic::Singletons::Chars::compareStringSimilar(const char* block1, const size_t& size_1, const char* block2, const size_t& size_2)
{
	return 0;// compareMemoryBlocks(block1, size_1, block2, size_2, sizeof(char), CHARS->compareCharSimilar);
}
int LlanyLib::Basic::Singletons::Chars::compareStringSimilar(const char* string1, const char* string2)
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
		resultado = compareStringSimilar(string1, sizeSting1, string2, sizeSting2);

	return resultado;
}
#pragma endregion
#pragma region Chars
int LlanyLib::Basic::Singletons::Chars::compareCharSimilar(const char* caracter1, const char* caracter2)
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
int LlanyLib::Basic::Singletons::Chars::compareChar(const char* caracter1, const char* caracter2)
{
	int resultado = 0;
	if (caracter1 == nullptr && caracter2 == nullptr) resultado = 0;	// Ambos son iguales
	else if (caracter1 == nullptr) resultado = -1;						// Caracter 2 mayor
	else if (caracter2 == nullptr) resultado = 1;						// Caracter 1 mayor
	else if (*caracter1 == *caracter2) resultado = 0;					// Ambos son iguales
	else if (*caracter1 > * caracter2) resultado = 1;					// Caracter 1 mayor
	else if (*caracter1 < *caracter2) resultado = -1;					// Caracter 2 mayor
	else resultado = -2;												// Other
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::isAlphabet(const char* caracter)
{
	int result = 0;
	if (caracter == nullptr) result = 0;						// Other
	else if (*caracter > 64 && *caracter < 91) result = 1;	// Mayus
	else if (*caracter > 96 && *caracter < 123) result = -1;// Minus
	else result = 0;										// Other
	return result;
}
int LlanyLib::Basic::Singletons::Chars::cambiarMayus(char* caracter)
{
	int resultado = 1;
	if (caracter == nullptr) resultado = -1;
	else if (isAlphabet(caracter) == -1)
		*caracter -= DIFERENCIA_MAYUS_MINUS;
	else resultado = 0;
	return resultado;
}
int LlanyLib::Basic::Singletons::Chars::cambiarMinus(char* caracter)
{
	int resultado = 1;
	if (caracter == nullptr) resultado = -1;
	else if (isAlphabet(caracter) == 1)
		*caracter += DIFERENCIA_MAYUS_MINUS;
	else resultado = 0;
	return resultado;
}
#pragma endregion
#pragma region Conversiones
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const bool& value) const
{
	LlanyLib::Basic::Objetos::String* resultado = nullptr;
	if (value)
		resultado = new LlanyLib::Basic::Objetos::String("True");
	else
		resultado = new LlanyLib::Basic::Objetos::String("False");
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const short& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const unsigned short& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const int& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const unsigned int& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const float& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const double& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const unsigned long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const long long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Chars::toString(const unsigned long long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
#pragma endregion
