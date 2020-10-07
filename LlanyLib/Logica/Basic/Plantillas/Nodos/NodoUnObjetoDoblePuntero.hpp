#pragma once
#ifndef NODO_UN_OBJETO_UN_PUNTERO_TEMPLATE_HPP_
#define NODO_UN_OBJETO_UN_PUNTERO_TEMPLATE_HPP_

#include "../../Interfaces/VectorPunteros.hpp"
#include "../../Interfaces/Contenedor.hpp"

#define DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_DOBLE_PUNTERO Interfaces::VectorPunteros<NUODP<T>, 2>

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Nodos {
				// Nodo de un objeto doble puntero
				template <class T>
				class NUODP : public Interfaces::Contenedor<T>, protected DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_DOBLE_PUNTERO
				{
					public:
						inline NUODP() : DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_DOBLE_PUNTERO() {}
						inline NUODP(const T& object0) : Interfaces::Contenedor<T>(object0), DECLARACION_HERENCIA_VECTOR_NODOS_UN_OBJETO_DOBLE_PUNTERO() {}
						inline ~NUODP() {}
						// Retorno: Devuelve el primer nodo apuntado
						inline NUODP<T>* getPrimerNodo() const { return NUODP::getPuntero(0); }
						// Retorno: Devuelve el segundo nodo apuntado
						inline NUODP<T>* getSegundoNodo() const { return NUODP::getPuntero(1); }
						// Funcion: Apunta el primer nodo al nodo indicado
						inline void setPrimerNodo(NUODP<T>* nodo) { NUODP::setPuntero(nodo, 0); }
						// Funcion: Apunta el segundo nodo al nodo indicado
						inline void setSegundoNodo(NUODP<T>* nodo) { NUODP::setPuntero(nodo, 1); }
				};
			}
		}
	}
}
#endif // !NODO_UN_OBJETO_UN_PUNTERO_TEMPLATE_HPP_