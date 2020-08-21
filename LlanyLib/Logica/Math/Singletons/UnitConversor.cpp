#include "UnitConversor.hpp"

#include <string.h>

#include "Math.hpp"
#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/LibreriasSimples/ASCII_Defines.h"

#pragma region Singleton
LlanyLib::Math::Singletons::UnitConversor::UnitConversor() { UnitConversor::subscribir(UnitConversor::freeInstancia); }
LlanyLib::Math::Singletons::UnitConversor::~UnitConversor() {}
#pragma endregion
#pragma region Tools
int LlanyLib::Math::Singletons::UnitConversor::charToIntHex(const char& caracter) const
{
	int resultado = 0;
	if (caracter >= '0' && caracter <= '9')
		resultado = caracter - '0';
	else if (caracter >= 'A' && caracter <= 'F')
		resultado = caracter - 'A' + 10;
	else if (caracter >= 'a' && caracter <= 'f')
		resultado = caracter - 'a' + 10;
	return resultado;
}
char LlanyLib::Math::Singletons::UnitConversor::intHexToChar(const int& val) const
{
	char resultado = 0;
	if (val < 10)
		resultado = NUMS + val;
	else if (val < 16)
		resultado = MAYUS + val - 10;
	else
		resultado = 'F';
	return resultado;
}
#pragma endregion
#pragma region Raw
#pragma region Bin to ...
char LlanyLib::Math::Singletons::UnitConversor::binByteToRawHex(char const* const val, const size_t& size) const
{
	char c = 0;
	for (size_t i = 0; i < size; i++)
		if (val[i] == '1')
			c += (int)MATH->elevarValor(2, (size - 1) - i);
	return c;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::binToRawHex(char const* const val) const
{
	LlanyLib::Basic::Objetos::StringBuilder buffer;
	char* arr_p = (char*)val;
	size_t size_bin_c = strlen(val);
	size_t grupos = size_bin_c / BIN_TO_HEX_GROUP_SIZE;
	size_t grupoMenorSize = size_bin_c % BIN_TO_HEX_GROUP_SIZE;

	if (grupoMenorSize != 0) {
		buffer += binByteToRawHex(arr_p, grupoMenorSize);
		arr_p += grupoMenorSize;
	}

	for (size_t i = 0; i < grupos; i++) {
		buffer += binByteToRawHex(arr_p, BIN_TO_HEX_GROUP_SIZE);
		arr_p += BIN_TO_HEX_GROUP_SIZE;
	}

	return buffer.build();
}
long_t LlanyLib::Math::Singletons::UnitConversor::binToRawDec(char const* const val) const
{
	long_t result = 0;
	size_t size = strlen(val);
	for (size_t i = 0; i < size; i++)
		if (val[i] == '1')
			result += (long_t)MATH->elevarValor(2, (size - 1) - i);
	return result;
}
#pragma endregion
#pragma region Dec to ...
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawDecToRawBase(const long_t& val, const size_t& base) const
{
	LlanyLib::Basic::Objetos::StringBuilder buffer;
	long_t dec_temp = val;
	long_t coef = 0;
	long_t resto = 0;

	while (dec_temp > 0) {
		coef = dec_temp / base;
		resto = dec_temp % base;
		if (coef == 0) {
			dec_temp = 0;
			buffer += (char)resto;
		}
		else {
			dec_temp = coef;
			buffer += (char)resto;
		}
	}
	LlanyLib::Basic::Objetos::String* result = buffer.build();
	result->reverse();
	return result;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawDecToRawHex(const long_t& val) const
{
	return UnitConversor::rawDecToRawBase(val, 16);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawDecToRawBin(const long_t& val) const
{
	return UnitConversor::rawDecToRawBase(val, 2);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawDecToRawOct(const long_t& val) const
{
	return UnitConversor::rawDecToRawBase(val, 8);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::decToRawHex(char const* const val) const
{
	return UnitConversor::rawDecToRawHex(UnitConversor::decToRawDec(val));
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::decToRawBin(char const* const val) const
{
	return UnitConversor::rawDecToRawBin(UnitConversor::decToRawDec(val));
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::decToRawOct(char const* const val) const
{
	return UnitConversor::rawDecToRawOct(UnitConversor::decToRawDec(val));
}
long_t LlanyLib::Math::Singletons::UnitConversor::decToRawDec(char const* const val) const
{
	long_t resultado = 0;
	size_t size = strlen(val);
	for (size_t i = 0; i < size; i++)
		resultado += UnitConversor::charToIntHex(val[i]) * (long_t)MATH->elevarValor(10, (size - i) - 1);
	return resultado;
}
#pragma endregion
#pragma region Oct to ...
long_t LlanyLib::Math::Singletons::UnitConversor::rawOctToRawDec(const long_t& val) const
{
	return long_t();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawOctToRawHex(const long_t& val) const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::octToRawBin(char const* const val) const
{
	LlanyLib::Basic::Objetos::StringBuilder buffer;
	size_t size_oct_c = strlen(val);
	for (size_t i = 0; i < size_oct_c; i++) {
		switch (val[i]) {
		case '0':
			buffer.add("0000");
			break;
		case '1':
			buffer.add("0001");
			break;
		case '2':
			buffer.add("0010");
			break;
		case '3':
			buffer.add("0011");
			break;
		case '4':
			buffer.add("0100");
			break;
		case '5':
			buffer.add("0101");
			break;
		case '6':
			buffer.add("0110");
			break;
		case '7':
			buffer.add("0111");
			break;
		case '8':
			buffer.add("1000");
			break;
		case '9':
			buffer.add("1001");
			break;
		case 'A':
			buffer.add("1010");
			break;
		case 'B':
			buffer.add("1011");
			break;
		case 'C':
			buffer.add("1100");
			break;
		case 'D':
			buffer.add("1101");
			break;
		case 'E':
			buffer.add("1110");
			break;
		case 'F':
			buffer.add("1111");
			break;
		default:
			buffer.add("0000");
			break;
		}
	}
	return buffer.build();
}
long_t LlanyLib::Math::Singletons::UnitConversor::octToRawDec(char const* const val) const
{
	long_t result = 0;
	size_t size = strlen(val);
	for (size_t i = 0; i < size; i++)
		result += (long_t)MATH->elevarValor(8, (size - 1) - i) * charToIntHex(val[i]);
	return result;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::octToRawHex(char const* const val) const
{
	long_t dec = octToRawDec(val);
	return rawDecToRawHex(dec);
}
#pragma endregion
#pragma region Hex to ...
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::hexToRawHex(char const* const) const
{
	return nullptr;
}
long_t LlanyLib::Math::Singletons::UnitConversor::rawHexToRawDec(char const* const) const
{
	return long_t();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawHexToBin(char const* const) const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::UnitConversor::rawHexToOct(char const* const) const
{
	return nullptr;
}
#pragma endregion
#pragma endregion
#pragma region Formated
#pragma region Bin to ...

#pragma endregion
#pragma region Dec to ...

#pragma endregion
#pragma region Oct to ...

#pragma endregion
#pragma region Hex to ...

#pragma endregion
#pragma endregion
