#include "Familiar.hpp"

#pragma region Constructores
LlanyLib::Juego::Objetos::Entidades::Familiar::Familiar()
{
	this->invocador = nullptr;
}
LlanyLib::Juego::Objetos::Entidades::Familiar::Familiar(const Familiar& other) : Familiar()
{
	Familiar::operator=(other);
}
bool LlanyLib::Juego::Objetos::Entidades::Familiar::operator=(const Familiar& other)
{
	bool resultado = false;
	if (&other != nullptr) {
		Entidad::operator=(other);
		this->invocador = other.invocador;
		resultado = true;
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Entidades::Familiar::~Familiar()
{
	this->invocador = nullptr;
}
#pragma endregion
#pragma region Getters
LlanyLib::Juego::Objetos::Entidades::Entidad* LlanyLib::Juego::Objetos::Entidades::Familiar::getInvocador() const
{
	return this->invocador;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Entidades::Familiar::setInvocador(Entidad* invocador)
{
	this->invocador = invocador;
}
#pragma endregion
#pragma region Adders

#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Entidades::Familiar::igual(const Familiar& other) const
{
	return false;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Entidades::Familiar::operator==(const Familiar& other) const
{
	return false;
}
bool LlanyLib::Juego::Objetos::Entidades::Familiar::operator!=(const Familiar& other) const
{
	return false;
}
#pragma endregion
LlanyLib::Juego::Objetos::Entidades::Entidad* LlanyLib::Juego::Objetos::Entidades::Familiar::clone() const
{
	return new Familiar(*this);
}
