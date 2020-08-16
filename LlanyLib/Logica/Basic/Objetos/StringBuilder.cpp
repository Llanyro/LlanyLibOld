#include "StringBuilder.hpp"

#include <string>

#include "../Plantillas/Listas/Buffer.hpp"
#include "../Objetos/String.hpp"

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
void LlanyLib::Basic::Objetos::StringBuilder::clear()
{
	this->buffer->clear();
}
bool LlanyLib::Basic::Objetos::StringBuilder::operator+=(const char& caracter)
{
	return StringBuilder::add(caracter);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::StringBuilder::build() const
{
	return new String(*this->buffer);
}
