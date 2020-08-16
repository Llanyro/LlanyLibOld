#include "Excepcion.hpp"

#include <iostream>

#pragma region Constructores
LlanyLib::Basic::Objetos::Excepcion::Excepcion()
{
	this->msg = nullptr;
	this->funcion = nullptr;
	this->backTrace = false;
}
LlanyLib::Basic::Objetos::Excepcion::Excepcion(char const* const excepcion) : Excepcion()
{
	this->msg = excepcion;
	this->funcion = __FUNCTION__;
}
LlanyLib::Basic::Objetos::Excepcion::Excepcion(char const* const excepcion, char const* const funcion) : Excepcion()
{
	this->msg = excepcion;
	this->funcion = funcion;
}
LlanyLib::Basic::Objetos::Excepcion::Excepcion(char const* const funcion, const bool& backTrace) : Excepcion()
{
	this->funcion = funcion;
	this->backTrace = backTrace;
}
LlanyLib::Basic::Objetos::Excepcion::~Excepcion() {}
#pragma endregion
#pragma region Otros
char const* LlanyLib::Basic::Objetos::Excepcion::getMensajeExcepcion() const
{
	return ((this->msg != nullptr) ? this->msg : "Excepcion no declarada");
}
char const* LlanyLib::Basic::Objetos::Excepcion::getFuncionExcepcion() const
{
	return ((this->funcion != nullptr) ? this->funcion : "Funcion no declarada");
}
void LlanyLib::Basic::Objetos::Excepcion::print() const
{
	if (this->backTrace)
		std::cout << "Funcion: " << LlanyLib::Basic::Objetos::Excepcion::getFuncionExcepcion() << std::endl;
	else
	{
		std::cout << "Error: " << LlanyLib::Basic::Objetos::Excepcion::getMensajeExcepcion() << std::endl;
		std::cout << "Funcion: " << LlanyLib::Basic::Objetos::Excepcion::getFuncionExcepcion() << std::endl;
	}
}
#pragma endregion
#pragma region BackTrace
LlanyLib::Basic::Objetos::BackTraceException::BackTraceException() : Excepcion(__FUNCTION__, true) {}
LlanyLib::Basic::Objetos::BackTraceException::BackTraceException(char const* const funcion) : Excepcion(funcion, true) {}
LlanyLib::Basic::Objetos::BackTraceException::~BackTraceException() {}
#pragma endregion
