#include "Celda.hpp"

#include "../../../Basic/Plantillas/Listas/Array.hpp"
#include "../../../Basic/Plantillas/Listas/LinkedList.hpp"

#pragma region Constructores
LlanyLib::Objetos::Celdas::Celda::Celda()
{
	this->posiciones = nullptr;
	this->grupo = nullptr;
}
LlanyLib::Objetos::Celdas::Celda::Celda(const size_t& numPos)
{
	this->posiciones = new Basic::Templates::Listas::Array<bool>(numPos);
	this->grupo = new Basic::Templates::Listas::LinkedList<Celda*>();
	Celda::setAll(false);
}
LlanyLib::Objetos::Celdas::Celda::Celda(const Celda& other) : Celda()
{
	assert(&other != nullptr);
	bool temp = Celda::operator=(other);
	assert(temp);
}
bool LlanyLib::Objetos::Celdas::Celda::operator=(const Celda& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		if (this->posiciones == nullptr)
			this->posiciones =
			new Basic::Templates::Listas::Array<bool>(*other.posiciones);
		else
			this->posiciones->operator=(*other.posiciones);

		if (this->grupo == nullptr)
			this->grupo = new Basic::Templates::Listas::LinkedList<Celda*>();
	}
	return temp;
}
LlanyLib::Objetos::Celdas::Celda::~Celda()
{
	if (this->posiciones != nullptr)
		delete this->posiciones;
	if (this->grupo != nullptr)
	{
		if (this->grupo->length() > 1)
			Celda::romperGrupo();
		delete this->grupo;
	}
	this->grupo = nullptr;
	this->posiciones = nullptr;
}
#pragma endregion
#pragma region Getters
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Objetos::Celdas::Celda*>* LlanyLib::Objetos::Celdas::Celda::getGrupo() const
{
	return this->grupo;
}
const bool* LlanyLib::Objetos::Celdas::Celda::getValue(const size_t& posicion) const
{
	bool* resultado = nullptr;
	if(this->posiciones != nullptr)
		resultado = this->posiciones->get(posicion);
	return resultado;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Objetos::Celdas::Celda::setAll(const bool& value) const
{
	if (this->posiciones != nullptr)
		for (size_t i = 0; i < this->posiciones->length(); i++)
			*this->posiciones->get(i) = value;
}
bool LlanyLib::Objetos::Celdas::Celda::set(const bool& value, const size_t& posicion) const
{
	bool resultado = true;
	if (posicion < this->posiciones->length())
		*this->posiciones->get(posicion) = value;
	else
		resultado = false;
	return resultado;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Objetos::Celdas::Celda::igual(const Celda& other) const
{
	bool resultado = true;
	if (other.posiciones->length() != this->posiciones->length())
		resultado = false;
	else 
		for (size_t i = 0; resultado && i < this->posiciones->length(); i++)
			resultado = this->posiciones[i] == other.posiciones[i];
	return resultado;
}
bool LlanyLib::Objetos::Celdas::Celda::operator==(const Celda& other) const
{
	return Celda::igual(other);
}
bool LlanyLib::Objetos::Celdas::Celda::operator!=(const Celda& other) const
{
	return !Celda::igual(other);
}
#pragma endregion
#pragma region Operators
void LlanyLib::Objetos::Celdas::Celda::mergeGrupos(const Celda& other)
{
	LlanyLib::Basic::Templates::Listas::LinkedList<Celda*>* grupoAMezclar = other.grupo;
	for (size_t i = 0; i < grupoAMezclar->getCount(); i++)
	{
		Celda* celda = *grupoAMezclar->get(i);
		celda->grupo = this->grupo;
		this->grupo->add(celda);
	}
	delete grupoAMezclar;
}
bool LlanyLib::Objetos::Celdas::Celda::contiene(const Celda* other) const
{
	return this->grupo->contains((Celda*)other);
}
void LlanyLib::Objetos::Celdas::Celda::romperGrupo()
{
	size_t pos = 0;
	if (this->grupo->find(this, &pos)) {
		this->grupo->remove(pos);
		this->grupo = new LlanyLib::Basic::Templates::Listas::LinkedList<Celda*>();
		this->grupo->add(this);
	}
}
#pragma endregion
