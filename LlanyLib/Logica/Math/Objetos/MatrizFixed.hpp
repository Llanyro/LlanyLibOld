#pragma once
#ifndef MATRIZ_FIXED_OBJECT_MATH_HPP_
#define MATRIZ_FIXED_OBJECT_MATH_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
	}
	namespace Math {
		namespace Objetos {
			class Racional;
			class Matriz;
			class MatrizFixed
			{
				protected:
					// filas -> columnas
					Racional** contenido;
					size_t filas;
					size_t columnas;

				protected:
					// comprobar sila matriz es coherente
					// 
				public:
					#pragma region Constructores
					MatrizFixed();
					MatrizFixed(const Matriz& matriz);
					MatrizFixed(const size_t& filas, const size_t& columnas);
					MatrizFixed(Racional** matriz, const size_t& filas, const size_t& columnas);
					~MatrizFixed();
					#pragma endregion
					#pragma region Getters
					size_t getNumeroFilas() const;
					size_t getNumeroColumnas() const;
					Racional* getValue(const size_t& fila, const size_t& columna) const;
					#pragma endregion
					#pragma region Set
					bool setValue(const Racional& value, const size_t& fila, const size_t& columna);
					#pragma endregion
					#pragma region Modificadores
					void randomize();
					
					#pragma endregion
					Basic::Objetos::String* toString() const;
			};
		}
	}
}
#endif // !MATRIZ_OBJECT_MATH_HPP_
