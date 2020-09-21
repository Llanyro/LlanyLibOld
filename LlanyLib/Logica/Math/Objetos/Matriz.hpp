#pragma once
#ifndef MATRIZ_OBJECT_MATH_HPP_
#define MATRIZ_OBJECT_MATH_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
		namespace Math {
			namespace Objetos {
				// V22
				class Racional;
				class Matriz
				{
					protected:
						// filas -> columnas
						Basic::Templates::Listas::LinkedList<
							Basic::Templates::Listas::LinkedList<Racional>*>* contenido;

					protected:
						// comprobar sila matriz es coherente
						// 

					public:
						#pragma region Getters
						size_t getNumeroFilas() const;
						size_t getNumeroColumnas() const;
						size_t getNumeroColumnas(const size_t& columna) const;
						Racional* getValue(const size_t& fila, const size_t& columna) const;
						#pragma endregion
						#pragma region Modificadores de matriz
						void multiplicarEscalar_(const int& escalar);

						#pragma endregion
						#pragma region Operaciones sin modificacion originales
						Matriz* multiplicarEscalar(const int& escalar) const;

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
}
#endif // !MATRIZ_OBJECT_MATH_HPP_
