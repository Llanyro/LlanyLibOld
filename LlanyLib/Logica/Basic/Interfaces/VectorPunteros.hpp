#pragma once
#ifndef VECTOR_PUNTEROS_INTERFACE_HPP_
#define VECTOR_PUNTEROS_INTERFACE_HPP_

#include <cassert>

namespace LlanyLib
{
	namespace Basic
	{
		namespace Interfaces
		{
			template<class T, const size_t size>
			class VectorPunteros
			{
				protected:
					T** vectorPunteros;
				protected:
					inline void inicializarVectorSimple()
					{
						if (this->vectorPunteros == nullptr)
						{
							this->vectorPunteros =
								new T*[size];
							for (size_t i = 0; i < size; i++)
								this->vectorPunteros[i] = nullptr;
						}
					}
					inline void clear()
					{
						if(this->vectorPunteros != nullptr)
							delete[] this->vectorPunteros;
						this->vectorPunteros = nullptr;
					}
				public:
					#pragma region Constructores
					inline VectorPunteros()
					{
						this->vectorPunteros = nullptr;
						VectorPunteros::inicializarVectorSimple();
					}
					inline ~VectorPunteros() { VectorPunteros::clear(); }
					#pragma endregion
					#pragma region Get/Set
					inline size_t getNumeroPunteros() const { return size; }
					inline T* getPuntero(const size_t& posicion) const
					{
						assert(&posicion != nullptr);
						T* nodo = nullptr;
						if (posicion < size)
							nodo = this->vectorPunteros[posicion];
						return nodo;
					}
					inline bool setPuntero(T* puntero, const size_t& posicion)
					{
						assert(&posicion != nullptr);
						bool resultado = true;
						if (posicion < size)
							this->vectorPunteros[posicion] = puntero;
						else
							resultado = false;
						return resultado;
					}
					#pragma endregion
			};
		}
	}
}
#endif // !VECTOR_PUNTEROS_INTERFACE_HPP_
