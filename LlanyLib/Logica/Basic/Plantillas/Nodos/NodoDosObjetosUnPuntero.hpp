#pragma once
#ifndef NODO_DOS_OBJETOS_UN_PUNTERO_TEMPLATE_HPP_
#define NODO_DOS_OBJETOS_UN_PUNTERO_TEMPLATE_HPP_

#include "../../Interfaces/VectorPunteros.hpp"
#include "../../Interfaces/ContenedorDobleTipo.hpp"

#define DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_UN_PUNTERO Interfaces::VectorPunteros<NDOUP<T1, T2>, 1>

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Nodos {
				// Nodo dos objetos un puntero
				template <class T1, class T2>
				class NDOUP : public Interfaces::ContenedorDobleTipo<T1, T2>, protected DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_UN_PUNTERO
				{
					public:
						inline NDOUP() : DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_UN_PUNTERO() {}
						//inline NDOUP(const T1& key) : Interfaces::ContenedorDobleTipo<T1, T2>(key), DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_UN_PUNTERO() {}
						//inline NDOUP(const T2& value) : Interfaces::ContenedorDobleTipo<T1, T2>(value), DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_UN_PUNTERO() {}
						inline NDOUP(const T1& key, const T2& value) : Interfaces::ContenedorDobleTipo<T1, T2>(key, value), DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_UN_PUNTERO() {}
						inline ~NDOUP() {}
						// Retorno: Devuelve el primer nodo apuntado
						inline NDOUP<T1, T2>* getSiguienteNodo() const { return NDOUP::getPuntero(0); }
						// Funcion: Apunta el primer nodo al nodo indicado
						inline void setSiguienteNodo(NDOUP<T1, T2>* nodo) { NDOUP::setPuntero(nodo, 0); }
				};
			}
		}
	}
}
#endif // !NODO_DOS_OBJETOS_UN_PUNTERO_TEMPLATE_HPP_
