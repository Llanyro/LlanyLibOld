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
					Basic::Templates::Listas::LinkedList<Basic::Templates::Listas::LinkedList<Racional>*>* filas;

				protected:
					// comprobar sila matriz es coherente
						// 

				public:

					// devolver numero de filas
					// devolver numero de columnas


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
