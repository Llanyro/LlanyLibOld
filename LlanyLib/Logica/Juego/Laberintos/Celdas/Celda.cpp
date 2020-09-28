#include "Celda.hpp"

#include "../../../Basic/Plantillas/Listas/Array.hpp"
#include "../../../Basic/Plantillas/Listas/LinkedList.hpp"

#pragma region Constructores
LlanyLib::Laberintos::Objetos::Celda::Celda()
{
	this->posiciones = nullptr;
	this->grupo = nullptr;
}
LlanyLib::Laberintos::Objetos::Celda::Celda(const size_t& numPos)
{
	this->posiciones = new Basic::Templates::Listas::Array<bool>(numPos);
	this->grupo = new Basic::Templates::Listas::LinkedList<Celda*>();
	Celda::setAll(false);
}
LlanyLib::Laberintos::Objetos::Celda::Celda(const Celda& other) : Celda()
{
	assert(&other != nullptr);
	bool temp = Celda::operator=(other);
	assert(temp);
}
bool LlanyLib::Laberintos::Objetos::Celda::operator=(const Celda& other)
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
LlanyLib::Laberintos::Objetos::Celda::~Celda()
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
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Laberintos::Objetos::Celda*>* LlanyLib::Laberintos::Objetos::Celda::getGrupo() const
{
	return this->grupo;
}
const bool* LlanyLib::Laberintos::Objetos::Celda::getValue(const size_t& posicion) const
{
	bool* resultado = nullptr;
	if(this->posiciones != nullptr)
		resultado = this->posiciones->get(posicion);
	return resultado;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Laberintos::Objetos::Celda::setAll(const bool& value) const
{
	if (this->posiciones != nullptr)
		for (size_t i = 0; i < this->posiciones->length(); i++)
			*this->posiciones->get(i) = value;
}
bool LlanyLib::Laberintos::Objetos::Celda::set(const bool& value, const size_t& posicion) const
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
bool LlanyLib::Laberintos::Objetos::Celda::igual(const Celda& other) const
{
	bool resultado = true;
	if (other.posiciones->length() != this->posiciones->length())
		resultado = false;
	else 
		for (size_t i = 0; resultado && i < this->posiciones->length(); i++)
			resultado = this->posiciones[i] == other.posiciones[i];
	return resultado;
}
bool LlanyLib::Laberintos::Objetos::Celda::operator==(const Celda& other) const
{
	return Celda::igual(other);
}
bool LlanyLib::Laberintos::Objetos::Celda::operator!=(const Celda& other) const
{
	return !Celda::igual(other);
}
#pragma endregion
#pragma region Operators
void LlanyLib::Laberintos::Objetos::Celda::mergeGrupos(Celda* other)
{
	for (size_t i = 0; i < other->grupo->getCount(); i++)
	{
		Celda* celda = *other->grupo->get(i);
		celda->grupo = this->grupo;
		this->grupo->add(celda);
	}
	delete other->grupo;
}
bool LlanyLib::Laberintos::Objetos::Celda::contiene(Celda* other) const
{
	return this->grupo->contains(other);
}
void LlanyLib::Laberintos::Objetos::Celda::romperGrupo()
{
	size_t pos = 0;
	if (this->grupo->find(this, &pos)) {
		this->grupo->remove(pos);
		this->grupo = new LlanyLib::Basic::Templates::Listas::LinkedList<Celda*>();
		this->grupo->add(this);
	}
}
#pragma endregion
