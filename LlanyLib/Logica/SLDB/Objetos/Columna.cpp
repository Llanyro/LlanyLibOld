#include "Columna.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../Basic/Objetos/String.hpp"

#include "../Enums/ColumEnums.hpp"

#pragma region Constructores
LlanyLib::LSDB::Objetos::Columna::Columna(const Enum::Tipos& tipo, Basic::Objetos::String* columName, const size_t& maxStringSize, const bool& paramNull)
{
	this->paramNull = paramNull;
	this->columType = tipo;
	this->columName = columName;
	this->maxStringSize = maxStringSize;
	this->filas = new Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>();
}
LlanyLib::LSDB::Objetos::Columna::~Columna()
{
	delete this->filas;
	delete this->columName;
	this->paramNull = true;
	this->maxStringSize = 0;
	this->columType = Enum::Tipos::STRING;
	this->columName = nullptr;
	this->filas = nullptr;
}
#pragma endregion
#pragma region Getters
size_t LlanyLib::LSDB::Objetos::Columna::getFilas() const
{
	return this->filas->getCount();
}
size_t LlanyLib::LSDB::Objetos::Columna::getMaxStringSize() const
{
	return this->maxStringSize;
}
bool LlanyLib::LSDB::Objetos::Columna::getParamNull() const
{
	return this->paramNull;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::LSDB::Objetos::Columna::getColumName() const
{
	return this->columName;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::LSDB::Objetos::Columna::getElement(const size_t& position) const
{
	LlanyLib::Basic::Objetos::String* result = nullptr;
	if (this->filas->get(position) != nullptr)
		result = *this->filas->get(position);
	return result;
}
#pragma endregion
#pragma region Setters
void LlanyLib::LSDB::Objetos::Columna::setMaxStringSize(const size_t& maxStringSize)
{
	this->maxStringSize = maxStringSize;
}
void LlanyLib::LSDB::Objetos::Columna::setColumName(Basic::Objetos::String* columName)
{
	if (this->columName != nullptr)
		delete this->columName;
	this->columName = columName;
}
void LlanyLib::LSDB::Objetos::Columna::setParamNull(const bool& paramNull)
{
	this->paramNull = paramNull;
}
bool LlanyLib::LSDB::Objetos::Columna::setParamNullUpdateAll(const bool& paramNull)
{
	return false;
}
#pragma endregion
#pragma region Modify
bool LlanyLib::LSDB::Objetos::Columna::addElement(Basic::Objetos::String* element) const
{
	return this->filas->add(element);
}
bool LlanyLib::LSDB::Objetos::Columna::modifyElement(Basic::Objetos::String* element, const size_t& pos) const
{
	bool resultado = false;
	if (this->filas->length() > pos)
		if (this->filas->insert(element, pos))
			resultado = this->filas->remove(pos + 1);
	return resultado;
}
bool LlanyLib::LSDB::Objetos::Columna::removeElement(const size_t& pos)
{
	return this->filas->remove(pos + 1);
}
void LlanyLib::LSDB::Objetos::Columna::clearColums()
{
	this->filas->clear();
}
#pragma endregion
