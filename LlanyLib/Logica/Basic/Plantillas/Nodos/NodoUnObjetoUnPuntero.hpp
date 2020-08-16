#pragma once
#ifndef NODO_UN_OBJETO_UN_PUNTERO_TEMPLATE_HPP_
#define NODO_UN_OBJETO_UN_PUNTERO_TEMPLATE_HPP_

#include "../../Interfaces/VectorPunteros.hpp"
#include "../../Interfaces/Contenedor.hpp"

#define DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_UN_PUNTERO Interfaces::VectorPunteros<NUOUP<T>, 1>

namespace LlanyLib
{
	namespace Basic
	{
		namespace Templates
		{
			namespace Nodos
			{
				// Nodo de un objeto un puntero
				template <class T>
				class NUOUP : public Interfaces::Contenedor<T>, protected DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_UN_PUNTERO
				{
					public:
						inline NUOUP() : DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_UN_PUNTERO(){}
						inline NUOUP(const T& object0) : Interfaces::Contenedor<T>(object0), DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_UN_PUNTERO() {}
						inline ~NUOUP() {}
						// Retorno: Devuelve el primer nodo apuntado
						inline NUOUP<T>* getSiguienteNodo() const { return NUOUP::getPuntero(0); }
						// Funcion: Apunta el primer nodo al nodo indicado
						inline void setSiguienteNodo(NUOUP<T>* nodo) { NUOUP::setPuntero(nodo, 0); }
				};
			}
		}
	}
}
#endif // !NODO_UN_OBJETO_UN_PUNTERO_TEMPLATE_HPP_
