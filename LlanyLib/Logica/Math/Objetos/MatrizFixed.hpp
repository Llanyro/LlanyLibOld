#pragma once
#ifndef MATRIZ_FIXED_OBJECT_MATH_HPP_
#define MATRIZ_FIXED_OBJECT_MATH_HPP_

namespace LlanyLib {
	namespace Math {
		namespace Objetos {
			class Racional;
			class Matriz;
			class MatrizFixed
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
					Racional** contenido;
					size_t filas;
					size_t columnas;

				protected:
					// comprobar sila matriz es coherente
					// 
				public:
					MatrizFixed();
					~MatrizFixed();

					#pragma region Getters
					size_t getNumeroFilas() const;
					size_t getNumeroColumnas() const;
					Racional* getValue(const size_t& fila, const size_t& columna) const;
					#pragma endregion
					#pragma region Modificadores de matriz
					void multiplicarEscalar_(const Racional& escalar);
					#pragma endregion
					#pragma region Operaciones sin modificacion originales
					Matriz* multiplicarEscalar(const Racional& escalar) const;
					#pragma endregion
					#pragma region Obtencion de datos
					Racional* determinante() const;
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

					/// Con logger


			};
		}
	}
}
#endif // !MATRIZ_OBJECT_MATH_HPP_
