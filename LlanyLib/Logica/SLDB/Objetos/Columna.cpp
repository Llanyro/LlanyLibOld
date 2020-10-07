#include "Columna.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../Basic/Objetos/String.hpp"

#include "../Enums/TypeEnums.hpp"

LlanyLib::LSDB::Objetos::Columna::Columna(const Enum::Tipos& tipo, Basic::Objetos::String* columName)
{
	this->columType = tipo;
	this->columName = columName;
	this->filas = new Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>();
}
LlanyLib::LSDB::Objetos::Columna::~Columna()
{
	delete this->filas;
	delete this->columName;
	this->columType = Enum::Tipos::STRING;
	this->columName = nullptr;
	this->filas = nullptr;
}
