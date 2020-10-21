#include "ValueToString.hpp"

#include <string>

#include "../Objetos/String.hpp"

LlanyLib::Basic::Singletons::ValueToString::ValueToString() { ValueToString::subscribir(ValueToString::freeInstancia); }
LlanyLib::Basic::Singletons::ValueToString::~ValueToString() {}

#pragma region Conversiones
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const bool& value) const
{
	LlanyLib::Basic::Objetos::String* resultado = nullptr;
	if (value)
		resultado = new LlanyLib::Basic::Objetos::String("True");
	else
		resultado = new LlanyLib::Basic::Objetos::String("False");
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const short& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const unsigned short& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const int& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const unsigned int& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const float& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const double& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const unsigned long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const long long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::ValueToString::toString(const unsigned long long& value) const
{
	return new LlanyLib::Basic::Objetos::String(&std::to_string(value)[0]);
}
#pragma endregion
