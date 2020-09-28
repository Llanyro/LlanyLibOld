#pragma once
#ifndef NODO_DOS_OBJETOS_DOS_PUNTEROS_TEMPLATE_HPP_
#define NODO_DOS_OBJETOS_DOS_PUNTEROS_TEMPLATE_HPP_

#include "../../Interfaces/VectorPunteros.hpp"
#include "../../Interfaces/ContenedorDobleTipo.hpp"

#define DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_DOS_PUNTEROS Interfaces::VectorPunteros<NDODP<T1, T2>, 2>

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Nodos {
				// Nodo dos objetos un puntero
				template <class T1, class T2>
				class NDODP : public Interfaces::ContenedorDobleTipo<T1, T2>, protected DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_DOS_PUNTEROS
				{
					public:
						inline NDODP() : DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_DOS_PUNTEROS() {}
						//inline NDODP(const T1& key) : Interfaces::ContenedorDobleTipo<T1, T2>(key), DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_DOS_PUNTEROS() {}
						//inline NDODP(const T2& value) : Interfaces::ContenedorDobleTipo<T1, T2>(value), DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_DOS_PUNTEROS() {}
						inline NDODP(const T1& key, const T2& value) : Interfaces::ContenedorDobleTipo<T1, T2>(key, value), DECLARACION_HERENCIA_VECTOR_NODOS_DOS_OBJETOS_DOS_PUNTEROS() {}
						inline ~NDODP() {}
						// Retorno: Devuelve el primer nodo apuntado
						inline NDODP<T1, T2>* getPrimerNodo() const { return NDODP::getPuntero(0); }
						// Retorno: Devuelve el segundo nodo apuntado
						inline NDODP<T1, T2>* getSegundoNodo() const { return NDODP::getPuntero(1); }
						// Funcion: Apunta el primer nodo al nodo indicado
						inline void setPrimerNodo(NDODP<T1, T2>* nodo) { NDODP::setPuntero(nodo, 0); }
						// Funcion: Apunta el segundo nodo al nodo indicado
						inline void setSegundoNodo(NDODP<T1, T2>* nodo) { NDODP::setPuntero(nodo, 1); }
				};
			}
		}
	}
}
#endif // !NODO_DOS_OBJETOS_DOS_PUNTEROS_TEMPLATE_HPP_
