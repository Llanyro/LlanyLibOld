#pragma once
#ifndef LIST_INTERFACE_HPP_
#define LIST_INTERFACE_HPP_

#include "../Objetos/Excepcion.hpp"
#include "Listas.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Interfaces {
			template<class T>
			class List : public Listas
			{
				protected:
					inline List() {}
				public:
					/// Contructores
					// Funcion: Copia los datos de una lista a esta lista
					// Precondiciones:
					//		Depende de la funcion original de cada lista
					// Retorno: Si se ha copiado correctamente
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool copy(const List<T>& list) { return false; }
					// Funcion: Elimina el objeto
					// Complejidad temporal y espacial: O(1) y M(1)
					inline virtual ~List() {}
					// Funcion: Copia la lista
					// Extra: Borra esta lista y copia la nueva
					// Precondiciones:
					//		list != nullptr
					// Retorno: Si se ha copiado correctamente
					// Complejidad temporal y espacial: O(n) y M(?)
					inline virtual bool operator=(const List<T>& list) { return false; }
					// Funcion: Crea un objeto clon de este
					// Retorno: El clon de este objeto
					// Complejidad temporal y espacial: O(n) y M(n)
					inline virtual List<T>* clone() const { return nullptr; }

					/// Getters
					// Retorno: Si la lista incrementa su capacidad maxima por si misma
					// Complejidad temporal y espacial: O(1) y M(1)
					inline virtual bool autoIncrementable() const override { return true; }
					// Funcion: Obtiene el puntero del objeto solicitado
					// Precondiciones:
					//		posicion < count
					// Retorno: El objeto solicitado
					//		Si la posicion es erronea devuelve nullptr
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual T* get(const size_t& position) { return nullptr; }
					// Funcion: Busca el objeto del nodo solicitado
					// Extra: No se recomienda buscar una posicion no valida
					// Throws: Exception
					// Precondiciones:
					//		position < count
					// Retorno: Objeto solicitado
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual T& operator[] (const size_t& position) const THROW
					{
						throw Objetos::Excepcion("List is an interface!", __FUNCTION__);
						T* temp = nullptr;
						return *temp;
					}
					///inline virtual T* getVector() { return nullptr; }

					/// Funciones de la lista
					// Funcion: Agrega un objeto al final de la lista
					// Precondiciones:
					//		object != nullptr
					// Retorno: Si se ha agregado a la lista
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool add(const T& object) { return false; }
					// Funcion: Agrega una lista de objetos al final de esta lista
					// Precondiciones:
					//		list != nullptr
					// Retorno: Si se ha agregado todos los objetos
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool add(const List<T>& list) { return false; }
					// Funcion: Hace de proxy a la funcion add()
					inline virtual bool operator+=(const T& object) { return List::add(object); }
					// Funcion: Hace de proxy a la funcion add()
					inline virtual bool operator+=(const List<T>& list) { return List::add(list); }
					// Funcion: Inserta un objeto a la lista en la posicion indicada
					// Precondiciones:
					//		object != nullptr
					//		position > count
					// Retorno: Si se ha insetado el objeto
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool insert(const T& object, const size_t& position) { return false; }
					// Funcion: Elimina un objeto de la lista
					// Precondiciones:
					//		position < count
					// Retorno: Si se ha eliminado el objeto solicitado
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool remove(const size_t& position) { return false; }
					inline virtual void sort(int Compare(const void* a, const void* b)){}

					/// Busquedas
					// Funcion: Busca un objeto solicitado usando ==
					// Precondiciones:
					//		object != nullptr
					// Retorno: Si el objeto existe
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool contains(const T& object) const { return false; }
					// Funcion: Busca un objeto solicitado utilizando una funcion de comparacion
					// Extra: La funcion la define el usuario
					// Extra 2: Si la funcion es nullptr usara el operador == de por defecto
					// Precondiciones:
					//		object != nullptr
					//		Compare != nullptr
					// Retorno: Si el objeto existe
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual bool contains(const T& object, bool Compare(const void* item_a, const void* item_b)) const { return false; }
					inline virtual bool find(const T& object, size_t* pos) const { return false; }
					inline virtual bool find(const T& object, size_t* pos, bool Compare(const void* item_a, const void* item_b)) const { return false; }

					/// Comparaciones
					// Funcion: Compara el contenido de esta lista con el de otra lista usando  == a cada objeto contenido
					// Precondiciones:
					//		list != nullptr
					// Retorno: Si las listas son exactamente iguales
					// Complejidad temporal y espacial: O(n) y M(1)
					inline virtual bool equals(const List<T>& list) const { return false; }
					// Funcion: Compara el contenido de esta lista con el de otra lista usando una funcion de comparacion a cada objeto contenido
					// Extra: La funcion la define el usuario
					// Extra 2: Si la funcion es nullptr usara el operador == de por defecto
					// Precondiciones:
					//		list != nullptr
					//		Compare != nullptr
					// Retorno: Si las listas son exactamente iguales
					// Complejidad temporal y espacial: O(n + Compare) y M(1 + Compare)
					inline virtual bool equals(const List<T>& list, bool Compare(const void* item_a, const void* item_b)) const { return false; }
					// Funcion: Compara dos listas si son similares usando == a cada objeto contenido
					// Extra: Un ejemplo seria dos listas que tienen los mismos objetos pero en orden distinto
					// Precondiciones:
					//		list != nullptr
					// Retorno: Si las listas son similares
					// Complejidad temporal y espacial: O(n^2/2) y M(?)
					inline virtual bool similar(const List<T>& list) const { return false; }
					// Funcion: Compara dos listas si son similares usando una funcion de comparacion a cada objeto contenido
					// Extra: La funcion la define el usuario
					// Extra 2: Si la funcion es nullptr usara el operador == de por defecto
					// Precondiciones:
					//		list != nullptr
					//		Compare != nullptr
					// Retorno: Si las listas son similares
					// Complejidad temporal y espacial: O((n^2/2) + Compare) y M(1 + Compare)
					inline virtual bool similar(const List<T>& list, bool Compare(const void* item_a, const void* item_b)) const { return false; }
					// Funcion: Hace de proxy a la funcion equals()
					inline virtual bool operator==(const List<T>& list) const { return false; }
					// Funcion: Hace de proxy a la funcion equals()
					inline virtual bool operator!=(const List<T>& list) const { return false; }
			};
		}
	}
}
#endif // !LIST_INTERFACE_HPP_
