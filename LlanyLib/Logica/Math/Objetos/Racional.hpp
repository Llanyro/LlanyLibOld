#pragma once
#ifndef RACIONAL_OBJECT_MATH_HPP_
#define RACIONAL_OBJECT_MATH_HPP_

namespace LlanyLib {
	namespace Math {
		namespace Objetos {
			// V22
			class Racional
			{
				protected:
					int numerador;		//Guarda el numerador del racional
					int denominador;	//Guarda el denominador del racional

					#pragma region Private
					// Inicia la clase racional
					// Complejidad temporal y espacial: O(1) y M(1)
					void IniciarRacional(const int& numerador, const int& denominador);
					// Ajusta los signos del numerador y el denominador
					// Complejidad temporal y espacial: O(1) y M(1)
					void AjustarSignos();
					#pragma endregion
				public:
					#pragma region Constructores
					//Crea un racional 1/1
					Racional();
					//Crea un racional recibiendo el numerador y el denominador
					Racional(const int& numerador, const int& denominador);
					//Copia un racional ya estructurado
					Racional(const Racional& other);
					//Copia un racional ya estructurado
					bool operator=(const Racional& other);
					//Destructor
					~Racional();
					#pragma endregion
					#pragma region Funciones
					// Devuelve el numerador del racional
					// Retorno: Numerador del racional
					// Complejidad temporal y espacial: O(1) y M(1)
					int getNumerador() const;
					// Devuelve el denominador del racional
					// Retorno: Denominador del racional
					// Complejidad temporal y espacial: O(1) y M(1)
					int getDenominador() const;
					// Devuelve la division real del racional
					// Retorno: Valor aproximado del racional
					// Complejidad temporal y espacial: O(1) y M(1)
					double getValor() const;
					// Cambia el valor del numerador segun el parametro value
					// Precondicion: numerador != 0
					// Complejidad temporal y espacial: O(1) y M(1)
					void setNumerador(const int& numerador);
					// Cambia el valor del denominador segun el parametro value
					// Precondicion: denominador != 0
					// Complejidad temporal y espacial: O(1) y M(1)
					void setDenominador(const int& denominador);
					// Simplifica el racional usando la funcion calcularMCD
					// Complejidad temporal y espacial: O(1) y M(1)
					void Simplificar();
					#pragma endregion
					#pragma region Operadores
					///Con otros racionales
					// Suma dos racionales
					// Precondiciones:
					//		other != nullptr
					// Retorno: Racional resultado de la suma
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator+(const Racional& racional);
					// Resta dos racionales
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Racional resultado de la diferencia
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator-(const Racional& racional);
					// Suma un racional a este racional
					// Precondiciones:
					//		racional != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void operator+=(const Racional& racional);
					// Resta un racional a este racional
					// Precondiciones:
					//		racional != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void operator-=(const Racional& racional);
					// Multiplica dos racionales
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Racional resultado de la mutiplicacion
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator*(const Racional& racional);
					// Compara dos racionales usando la funcion Valor
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Este objeto es mayor
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator>(const Racional& racional);
					// Compara dos racionales usando la funcion Valor
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Este objeto es menor
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator<(const Racional& racional);
					// Compara dos racionales usando la funcion Valor
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Los racionales son iguales
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator==(const Racional& racional);
					// Compara dos racionales usando la funcion Valor
					// Si son diferentes devuelve true
					// Precondiciones:
					//		racional != nullptr
					// Retorno: Los racionales no son iguales
					// Complejidad temporal y espacial: O(1) y M(1)
					bool operator!=(const Racional& racional);

					///Con numeros
					// Multiplica un racional y un numero
					// Precondiciones:
					//		valor != nullptr
					// Retorno: Racional resultado de la multiplicacion
					// Complejidad temporal y espacial: O(1) y M(1)
					Racional* operator*(const int& valor);
					// Multiplica un racional y un numero
					// Precondiciones:
					//		valor != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void operator*=(const int& valor);
					#pragma endregion
					#pragma region Modificadores
					void escalar(const int& escalar);
					#pragma endregion
			};	
		}
	}
}
#endif // !RACIONAL_OBJECT_MATH_HPP_
