#include "Registro.hpp"

LlanyLib::Basic::Objetos::Registro::Registro(const size_t& size)
{
	this->size = size;
	this->registro = new bool[size];
}

LlanyLib::Basic::Objetos::Registro::~Registro()
{
	delete[] this->registro;
	this->size = false;
}

void LlanyLib::Basic::Objetos::Registro::setAll(const bool& value)
{
	for (size_t i = 0; i < this->size; i++)
		this->registro[i] = value;
}

bool LlanyLib::Basic::Objetos::Registro::isTrue() const
{
	return this->registro[this->size-1];
}
