#pragma once
#ifndef RACIONAL_TEMPLATE_HPP_
#define RACIONAL_TEMPLATE_HPP_

#include <cassert>

#include "../Singletons/Math.hpp"

namespace LlanyLib {
	namespace Math {
		namespace Templates {
			// V23
			template<class T>
			class Racional
			{
				protected:
					T numerador;	//Guarda el numerador del racional
					T denominador;	//Guarda el denominador del racional
					#pragma region Private
					// Inicia la clase racional
					// Complejidad temporal y espacial: O(1) y M(1)
					void IniciarRacional(const T& numerador, const T& denominador)
					{
						this->numerador = numerador;
						this->denominador = denominador;
						Racional::AjustarSignos();
					}
					// Ajusta los signos del numerador y el denominador
					// Complejidad temporal y espacial: O(1) y M(1)
					void AjustarSignos()
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
				public:
					#pragma region Constructores
					//Crea un racional 1/1
					Racional() { Racional::IniciarRacional(1, 1); }
					//Crea un racional recibiendo el numerador y el denominador
					Racional(const T& numerador, const T& denominador) { Racional::IniciarRacional(numerador, denominador); }
					//Copia un racional ya estructurado
					Racional(const Racional& other)
					{
						assert(&other != nullptr);
						bool temp = Racional::operator=(other);
						assert(temp);
					}
					//Copia un racional ya estructurado
					bool operator=(const Racional& other)
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
					//Destructor
					~Racional() {}
					#pragma endregion
					#pragma region Funciones
					// Devuelve el numerador del racional
					// Retorno: Numerador del racional
					// Complejidad temporal y espacial: O(1) y M(1)
					T getNumerador() const { return this->numerador; }
					// Devuelve el denominador del racional
					// Retorno: Denominador del racional
					// Complejidad temporal y espacial: O(1) y M(1)
					T getDenominador() const { return this->denominador; }
					// Devuelve la division real del racional
					// Retorno: Valor aproximado del racional
					// Complejidad temporal y espacial: O(1) y M(1)
					double getValor() const { return (this->numerador / (float)this->denominador); }
					// Cambia el valor del numerador segun el parametro value
					// Precondicion: numerador != 0
					// Complejidad temporal y espacial: O(1) y M(1)
					void setNumerador(const T& numerador)
					{
						assert(&numerador != nullptr);
						this->numerador = numerador;
						Racional::AjustarSignos();
					}
					// Cambia el valor del denominador segun el parametro value
					// Precondicion: denominador != 0
					// Complejidad temporal y espacial: O(1) y M(1)
					void setDenominador(const T& denominador)
					{
						assert(&denominador != nullptr);
						this->denominador = denominador;
						Racional::AjustarSignos();
					}
					// Simplifica el racional usando la funcion calcularMCD
					// No funciona aun
					// Complejidad temporal y espacial: O(1) y M(1)
					void Simplificar()
					{
						// máximo común divisor del valor absoluto del denominador y del valor absoluto del denominador
						int maximoComunDivisor = MATH->euclidesSimple(
							MATH->valorAbsoluto(numerador),
							MATH->valorAbsoluto(denominador));
						this->numerador = this->numerador / maximoComunDivisor;
						this->denominador = this->denominador / maximoComunDivisor;
					}
					#pragma endregion
					#pragma region Operadores
					///Con otros racionales
					// Suma dos racionales
					// Precondiciones:
					//		other != nullptr
					// Retorno: Racional resultado de la suma
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator+(const Racional& racional)
					{
						assert(&racional != nullptr);
						int nuevoDenominador = denominador * racional.getDenominador();
						int numerador1 = numerador * racional.getDenominador();
						int numerador2 = racional.getNumerador() * denominador;
						int  nuevoNumerador = numerador1 + numerador2;
						return new Racional(nuevoNumerador, nuevoDenominador);
					}
					// Resta dos racionales
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Racional resultado de la diferencia
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator-(const Racional& racional)
					{
						assert(&racional != nullptr);
						int nuevoDenominador = denominador * racional.getDenominador();
						int numerador1 = numerador * racional.getDenominador();
						int numerador2 = racional.getNumerador() * denominador;
						int  nuevoNumerador = numerador1 - numerador2;
						return new Racional(nuevoNumerador, nuevoDenominador);
					}
					// Suma un racional a este racional
					// Precondiciones:
					//		racional != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void operator+=(const Racional& racional)
					{
						assert(&racional != nullptr);
						int nuevoDenominador = denominador * racional.getDenominador();
						int numerador1 = numerador * racional.getDenominador();
						int numerador2 = racional.getNumerador() * denominador;
						int  nuevoNumerador = numerador1 + numerador2;
						Racional::IniciarRacional(nuevoNumerador, nuevoDenominador);
					}
					// Resta un racional a este racional
					// Precondiciones:
					//		racional != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void operator-=(const Racional& racional)
					{
						assert(&racional != nullptr);
						int nuevoDenominador = denominador * racional.getDenominador();
						int numerador1 = numerador * racional.getDenominador();
						int numerador2 = racional.getNumerador() * denominador;
						int  nuevoNumerador = numerador1 - numerador2;
						Racional::IniciarRacional(nuevoNumerador, nuevoDenominador);
					}
					// Multiplica dos racionales
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Racional resultado de la mutiplicacion
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator*(const Racional& racional)
					{
						assert(&racional != nullptr);
						return new Racional(this->numerador * racional.getNumerador(), this->denominador * racional.getDenominador());
					}
					// Compara dos racionales usando la funcion Valor
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Este objeto es mayor
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator>(const Racional& racional)
					{
						assert(&racional != nullptr);
						return (Racional::getValor() > racional.getValor());
					}
					// Compara dos racionales usando la funcion Valor
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Este objeto es menor
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator<(const Racional& racional)
					{
						assert(&racional != nullptr);
						return (Racional::getValor() < racional.getValor());
					}
					// Compara dos racionales usando la funcion Valor
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Los racionales son iguales
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator==(const Racional& racional)
					{
						bool resultado = true;
						if (&racional == this) resultado = true;
						else if (this == nullptr) resultado = false;
						else if (&racional == nullptr) resultado = false;
						else
							resultado = (Racional::getValor() == racional.getValor());
						return resultado;
					}
					// Compara dos racionales usando la funcion Valor
					// Si son diferentes devuelve true
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Los racionales no son iguales
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator!=(const Racional& racional) { return !Racional::operator==(racional); }

					///Con numeros
					// Multiplica un racional y un numero
					// Precondiciones:
					//		valor != nullptr
					// Retorno: Racional resultado de la multiplicacion
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator*(const T& valor)
					{
						assert(&valor != nullptr);
						return new Racional(this->numerador * valor, denominador);
					}
					// Multiplica un racional y un numero
					// Precondiciones:
					//		valor != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void operator*=(const T& valor)
					{
						assert(&valor != nullptr);
						Racional::IniciarRacional(this->numerador * valor, denominador);
					}
					#pragma endregion
			};
		}
	}
}
#endif // !RACIONAL_TEMPLATE_HPP_
