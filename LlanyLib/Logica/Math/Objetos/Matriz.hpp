#pragma once
#ifndef MATRIZ_OBJECT_MATH_HPP_
#define MATRIZ_OBJECT_MATH_HPP_

#include "../../Basic/LibreriasSimples/ListaDefines.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
				template<class T>
				class Array;
			}
		}
	}
	namespace Math {
		namespace Objetos {
			class Racional;
			class Matriz
			{
				protected:
					/*
						
						++++ -> this->contenido[0][n]
						++++
						++++
						++++
						|------> this[n][0]
						 |------> this[n][1]
						  |------> this[n][2]
						   |------> this[n][3]

						Add
						
						Fila
						++++				++++
						++++		->		++++
						++++				++++
											++++
						this->contenido.add(newList)

						Columna
						+++					++++
						+++			->		++++
						+++					++++
						+++					++++
						this->contenido[0].add(newList[0])
						this->contenido[1].add(newList[1])
						this->contenido[2].add(newList[2])
						this->contenido[3].add(newList[3])

					*/


					// filas -> columnas
					LISTA_T<LISTA_T<Racional>*>* contenido;

				protected:
					// comprobar sila matriz es coherente
					// 

				public:
					Matriz();

					#pragma region Getters
						size_t getNumeroFilas() const;
						size_t getNumeroColumnas() const;
						size_t getNumeroColumnas(const size_t& columna) const;
						Racional* getValue(const size_t& fila, const size_t& columna) const;
						#pragma endregion
					#pragma region Add
						bool addColum(LISTA_T<Racional>* columna);
						bool addFila(LISTA_T<Racional>* fila);

						// Testear cuidadosamente antes de usar
						// Posiblemente fallo de herencia al crear el objeto LISTA_T y recibir como paramentro el array
						bool addColum(ARRAY_T<Racional>* columna);
						bool addFila(ARRAY_T<Racional>* fila);
						#pragma endregion
					#pragma region Remove
						bool removeColum(const size_t& pos);
						bool removeFila(const size_t& pos);
						#pragma endregion
					#pragma region Modificadores de matriz
					void multiplicarEscalar_(const int& escalar);
					void dividirEscalar_(const int& escalar);

					#pragma endregion
					#pragma region Operaciones sin modificacion originales
					Matriz* multiplicarEscalar(const int& escalar) const;
					Matriz* dividirEscalar(const int& escalar);

					#pragma endregion


					/// Sin logger
					// inversa
					// diagonalizar
					// rango
					// traspuesta
					// suma
					// resta
					// multiplicacion
					// multiplicacion por escalalr
					// determinante


					Matriz* asdf(const Matriz& other) const;

					/// Con logger


			};
		}
	}
}
#endif // !MATRIZ_OBJECT_MATH_HPP_
