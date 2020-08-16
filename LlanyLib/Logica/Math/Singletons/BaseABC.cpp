#include "BaseABC.hpp"

#include <cassert>

#include "../../Basic/Objetos/String.hpp"

#define BASE_ABC_VALUE 52

#pragma region Constructores
LlanyLib::Math::Singletons::BaseABC::BaseABC(){ BaseABC::subscribir(BaseABC::freeInstancia); }
LlanyLib::Math::Singletons::BaseABC::~BaseABC() {}
#pragma endregion
char LlanyLib::Math::Singletons::BaseABC::toChar(const short& value) const
{
	assert(&value != nullptr);

	short realValue = value % BASE_ABC_VALUE; // Si recibimos un numero mayor al que se debe
	char result;

	if (realValue < 26)
		result = realValue + 97;
	else if (realValue < 52)
		result = realValue + 39;

	return result;;
}
short LlanyLib::Math::Singletons::BaseABC::toShort(const char& caracter) const
{
	assert(&caracter != nullptr);
	short result = 0;
	if (caracter > 64 && caracter < 91)
		result = caracter - 39;
	else if(caracter > 96 && caracter < 123)
		result = caracter - 97;
	return result;
}
size_t LlanyLib::Math::Singletons::BaseABC::toValue(const Basic::Objetos::String* str) const
{
	assert(&str != nullptr);
	size_t value = 0;
	for (size_t i = 0; i < str->length(); i++)
		value += BaseABC::toShort(str->operator[](i));
	return value;
}
size_t LlanyLib::Math::Singletons::BaseABC::toValueClear(Basic::Objetos::String* str) const
{
	size_t val = BaseABC::toValue(str);
	delete str;
	return val;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::BaseABC::toString(const size_t& value) const
{
	return nullptr;
}
