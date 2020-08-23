#include "StringBuilder.hpp"

#include <string>

#include "../Plantillas/Listas/Buffer.hpp"
#include "../Objetos/String.hpp"
#include "../Singletons/Chars.hpp"

LlanyLib::Basic::Objetos::StringBuilder::StringBuilder()
{
	this->buffer = new Templates::Listas::Buffer<char>();
}
LlanyLib::Basic::Objetos::StringBuilder::~StringBuilder()
{
	delete this->buffer;
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const String* str)
{
	bool resultado = false;
	if(str != nullptr && str->length() > 1)
		resultado = this->buffer->add(str->get(), str->length() - 1);
	return resultado;
}
bool LlanyLib::Basic::Objetos::StringBuilder::addClear(const String* str)
{
	bool resultado = StringBuilder::add(str);
	delete str;
	return resultado;
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(char const* const str)
{
	return this->buffer->add(str, strlen(str));
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const char& caracter)
{
	return this->buffer->add(caracter);
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const int& val)
{
	return StringBuilder::addClear(CHARS->toString(val));
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const float& val)
{
	return StringBuilder::addClear(CHARS->toString(val));
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const double& val)
{
	return StringBuilder::addClear(CHARS->toString(val));
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const long_t& val)
{
	return StringBuilder::addClear(CHARS->toString(val));
}
bool LlanyLib::Basic::Objetos::StringBuilder::add(const size_t& val)
{
	return StringBuilder::addClear(CHARS->toString(val));
}
void LlanyLib::Basic::Objetos::StringBuilder::clear()
{
	this->buffer->clear();
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const String* str)
{
	return StringBuilder::add(str);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const char& caracter)
{
	return StringBuilder::add(caracter);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(char const* const str)
{
	return StringBuilder::add(str);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const int& val)
{
	return StringBuilder::add(val);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const float& val)
{
	return StringBuilder::add(val);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const double& val)
{
	return StringBuilder::add(val);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const long_t& val)
{
	return StringBuilder::add(val);
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const size_t& val)
{
	return StringBuilder::add(val);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::StringBuilder::build() const
{
	return new String(*this->buffer);
}
