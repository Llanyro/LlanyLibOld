#include "Registro.hpp"

size_t LlanyLib::Basic::Objetos::Registro::lastTrueProtected(const size_t& pos) const
{
	size_t positionResultado = 0;
	if (pos == 0 || pos > this->count)
		positionResultado = 0;
	else if (this->registro[pos] == true)
		positionResultado = pos;
	else
		positionResultado = Registro::lastTrueProtected(pos - 1);
	return positionResultado;
}
LlanyLib::Basic::Objetos::Registro::Registro(const size_t& count)
{
	this->count = count;
	this->registro = new bool[count];
	Registro::setAll(false);
}
LlanyLib::Basic::Objetos::Registro::~Registro()
{
	delete[] this->registro;
	this->count = false;
}
bool LlanyLib::Basic::Objetos::Registro::setPosTrue(const size_t& pos)
{
	bool resultado = false;
	if (pos < this->count) {
		if (pos == 0) {
			this->registro[0] = true;
			resultado = true;
		}
		else if (this->registro[pos - 1] == true) {
			this->registro[pos] = true;
			resultado = true;
		}
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Registro::setPosFalse(const size_t& pos)
{
	bool resultado = false;
	if (pos < this->count) {
		for (size_t i = 0; i < pos; i++)
			this->registro[pos] = false;
		resultado = true;
	}
	return resultado;
}
void LlanyLib::Basic::Objetos::Registro::setAll(const bool& value)
{
	for (size_t i = 0; i < this->count; i++)
		this->registro[i] = value;
}
bool LlanyLib::Basic::Objetos::Registro::isTrue() const
{
	return this->registro[this->count - 1];
}
const bool* LlanyLib::Basic::Objetos::Registro::getPos(const size_t& pos) const
{
	bool* result = nullptr;
	if (this->count > pos)
		result = &this->registro[pos];
	return result;
}

size_t LlanyLib::Basic::Objetos::Registro::lastTrue() const
{
	return Registro::lastTrueProtected(this->count - 1);
}
