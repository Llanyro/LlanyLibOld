#include "Racional.hpp"

#include <cassert>

#include "../Singletons/Math.hpp"

#pragma region Private
void LlanyLib::Math::Objetos::Racional::IniciarRacional(const int& numerador, const int& denominador)
{
	this->numerador = numerador;
	this->denominador = denominador;
	LlanyLib::Math::Objetos::Racional::AjustarSignos();
}
void LlanyLib::Math::Objetos::Racional::AjustarSignos()
{
	if (this->denominador < 0)
	{
		this->numerador = -this->numerador;
		this->denominador = -this->denominador;
	}
	else if (this->denominador == 0)
		this->denominador = 1;
}
#pragma endregion
#pragma region Constructores
LlanyLib::Math::Objetos::Racional::Racional()
{
	Racional::IniciarRacional(1, 1);
}
LlanyLib::Math::Objetos::Racional::Racional(const int& numerador, const int& denominador)
{
	Racional::IniciarRacional(numerador, denominador);
}
LlanyLib::Math::Objetos::Racional::Racional(const Racional& other)
{
	assert(&other != nullptr);
	bool temp = Objetos::Racional::operator=(other);
	assert(temp);
}
bool LlanyLib::Math::Objetos::Racional::operator=(const Racional& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->numerador = other.numerador;
		this->denominador = other.denominador;
	}
	return temp;
}
LlanyLib::Math::Objetos::Racional::~Racional() {}
#pragma endregion
#pragma region Funciones
int LlanyLib::Math::Objetos::Racional::getNumerador() const
{
	return this->numerador;
}
int LlanyLib::Math::Objetos::Racional::getDenominador() const
{
	return this->denominador;
}
double LlanyLib::Math::Objetos::Racional::getValor() const
{
	return (this->numerador / (float)this->denominador);
}
void LlanyLib::Math::Objetos::Racional::setNumerador(const int& numerador)
{
	assert(&numerador != nullptr);
	this->numerador = numerador;
	Racional::AjustarSignos();
}
void LlanyLib::Math::Objetos::Racional::setDenominador(const int& denominador)
{
	assert(&denominador != nullptr);
	this->denominador = denominador;
	Racional::AjustarSignos();
}
void LlanyLib::Math::Objetos::Racional::Simplificar()
{
	// máximo común divisor del valor absoluto del denominador y del valor absoluto del denominador
	int maximoComunDivisor = (int)MATH->euclidesSimple(
		MATH->valorAbsoluto(this->numerador),
		MATH->valorAbsoluto(this->denominador));
	this->numerador = this->numerador / maximoComunDivisor;
	this->denominador = this->denominador / maximoComunDivisor;
}
#pragma endregion
#pragma region Operadores
LlanyLib::Math::Objetos::Racional* LlanyLib::Math::Objetos::Racional::operator+(const Racional& racional)
{
	assert(&racional != nullptr);
	int nuevoDenominador = denominador * racional.getDenominador();
	int numerador1 = numerador * racional.getDenominador();
	int numerador2 = racional.getNumerador() * denominador;
	int  nuevoNumerador = numerador1 + numerador2;
	return new Objetos::Racional(nuevoNumerador, nuevoDenominador);
}
LlanyLib::Math::Objetos::Racional* LlanyLib::Math::Objetos::Racional::operator-(const Racional& racional)
{
	assert(&racional != nullptr);
	int nuevoDenominador = denominador * racional.getDenominador();
	int numerador1 = numerador * racional.getDenominador();
	int numerador2 = racional.getNumerador() * denominador;
	int  nuevoNumerador = numerador1 - numerador2;
	return new Objetos::Racional(nuevoNumerador, nuevoDenominador);
}
void LlanyLib::Math::Objetos::Racional::operator+=(const Racional& racional)
{
	assert(&racional != nullptr);
	int nuevoDenominador = denominador * racional.getDenominador();
	int numerador1 = numerador * racional.getDenominador();
	int numerador2 = racional.getNumerador() * denominador;
	int  nuevoNumerador = numerador1 + numerador2;
	Objetos::Racional::IniciarRacional(nuevoNumerador, nuevoDenominador);
}
void LlanyLib::Math::Objetos::Racional::operator-=(const Racional& racional)
{
	assert(&racional != nullptr);
	int nuevoDenominador = denominador * racional.getDenominador();
	int numerador1 = numerador * racional.getDenominador();
	int numerador2 = racional.getNumerador() * denominador;
	int  nuevoNumerador = numerador1 - numerador2;
	Objetos::Racional::IniciarRacional(nuevoNumerador, nuevoDenominador);
}
LlanyLib::Math::Objetos::Racional* LlanyLib::Math::Objetos::Racional::operator*(const Racional& racional)
{
	assert(&racional != nullptr);
	return new Objetos::Racional(this->numerador * racional.getNumerador(), this->denominador * racional.getDenominador());
}
bool LlanyLib::Math::Objetos::Racional::operator>(const Racional& racional)
{
	assert(&racional != nullptr);
	return (Objetos::Racional::getValor() > racional.getValor());
}
bool LlanyLib::Math::Objetos::Racional::operator<(const Racional& racional)
{
	assert(&racional != nullptr);
	return (Objetos::Racional::getValor() < racional.getValor());
}
bool LlanyLib::Math::Objetos::Racional::operator==(const Racional& racional)
{
	bool resultado = true;
	if (&racional == this) resultado = true;
	else if (this == nullptr) resultado = false;
	else if (&racional == nullptr) resultado = false;
	else
		resultado = (Racional::getValor() == racional.getValor());
	return resultado;
}
bool LlanyLib::Math::Objetos::Racional::operator!=(const Racional& racional)
{
	return !Objetos::Racional::operator==(racional);
}
LlanyLib::Math::Objetos::Racional* LlanyLib::Math::Objetos::Racional::operator*(const int& valor)
{
	assert(&valor != nullptr);
	return new Objetos::Racional(this->numerador * valor, denominador);
}
void LlanyLib::Math::Objetos::Racional::operator*=(const int& valor)
{
	assert(&valor != nullptr);
	Objetos::Racional::IniciarRacional(this->numerador * valor, denominador);
}
#pragma endregion
