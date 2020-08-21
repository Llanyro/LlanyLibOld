#pragma once
#ifndef LINKED_LIST_TEMPLATE_HPP_
#define LINKED_LIST_TEMPLATE_HPP_

#include "../../Interfaces/List.hpp"
#include "../Nodos/NodoUnObjetoDoblePuntero.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedListAuto;

				template<class T>
				class LinkedList : public Interfaces::List<T>
				{
					protected:
						Nodos::NUODP<T>* raiz;
						// Falsos punteros para poder modificarlos sin quitar el const
						Nodos::NUODP<T>* cacheNodo;
						// Falsos punteros para poder modificarlos sin quitar el const
						size_t cachePosicionNodo;
						friend class LinkedListAuto<T>;
					protected:
						#pragma region Funciones de busquedas internas
						// Complejidad espacial y temporal peor O(n/2)
						// Complejidad espacial y temporal mejor O(1)
						// Complejidad espacial y temporal imprimir O(1)
						// Complejidad espacial y temporal media O(n/4) (No comprobado->aprox)
						///virtual Nodos::NUODP<T>* getNodo(const size_t& position);
						// Funcion: Busca el la lista el nodo solicitado
						// Extra: Guarda el ultimo nodo visitado
						// Version: Beta
						// Precondiciones:
						//		position != nullptr
						// Retorno: Nodo solicitado
						// Complejidad temporal y espacial: O(n/2) y M(1)
						virtual Nodos::NUODP<T>* getNodoNoCache(const size_t& position)
						{
							Nodos::NUODP<T>* nodoActual = nullptr;
							if (&position != nullptr && position < this->count)
							{
								nodoActual = this->raiz;
								if (position < this->count / 2)
									for (size_t i = 0; i < position; i++)
										nodoActual = nodoActual->getPrimerNodo();
								else
									for (size_t i = 0; i < this->count - position; i++)
										nodoActual = nodoActual->getSegundoNodo();
								// Guardamos el ultimo accedido
								this->cacheNodo = nodoActual;
								this->cachePosicionNodo = position;
							}
							return nodoActual;
						}
						// Funcion: Busca el la lista el nodo solicitado ademas de contar con el ultimo buscado
						// Version: Beta
						// Precondiciones:
						//		position != nullptr
						// Retorno: Nodo solicitado
						// Complejidad temporal y espacial peor: O(n/2) y M(1)
						// Complejidad temporal y espacial mejor: O(1) y M(1)
						virtual Nodos::NUODP<T>* getNodoCache(const size_t& position)
						{
							Nodos::NUODP<T>* nodoActual = nullptr;
							if (&position != nullptr && position < this->count)
							{
								if (position == 0)
									nodoActual = this->raiz;
								else if (position == (this->count - 1))
									nodoActual = this->raiz->getSegundoNodo();
								else if (this->cacheNodo != nullptr)
								{
									nodoActual = this->cacheNodo;
									if (position > this->cachePosicionNodo)
										for (size_t i = this->cachePosicionNodo; i < position; i++)
											nodoActual = nodoActual->getPrimerNodo();
									else
										for (size_t i = 0; i < this->cachePosicionNodo - position; i++)
											nodoActual = nodoActual->getSegundoNodo();
									// Guardamos el ultimo accedido
									this->cacheNodo = nodoActual;
									this->cachePosicionNodo = position;
								}
								else
									nodoActual = LinkedList::getNodoNoCache(position);
							}
							return nodoActual;
						}
						// Funcion: Busca el la lista el nodo solicitado
						// Extra: No guarda el ultimo nodo visitado
						// Version: Beta
						// Precondiciones:
						//		position != nullptr
						// Retorno: Void
						// Complejidad temporal y espacial: O(n/2) y M(1)
						virtual Nodos::NUODP<T>* getNodoLow(const size_t& position) const
						{
							Nodos::NUODP<T>* nodoActual = nullptr;
							if (&position != nullptr && position < this->count)
							{
								nodoActual = this->raiz;
								if (position < this->count / 2)
									for (size_t i = 0; i < position; i++)
										nodoActual = nodoActual->getPrimerNodo();
								else
									for (size_t i = 0; i < this->count - position; i++)
										nodoActual = nodoActual->getSegundoNodo();
							}
							return nodoActual;
						}
						#pragma endregion
					public:
						#pragma region Funciones Heredadas
						#pragma region Constructores
						// Funcion: Crea un objeto clon de este
						// Version: Beta
						// Retorno: El puntero al clon
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual Interfaces::List<T>* clone() const override { return new LinkedList<T>(*this); }
						// Funcion: Hace de proxy al operador =
						inline virtual bool copy(const Interfaces::List<T>& list) override { return LinkedList::operator=(list); }
						// Funcion: Copia la lista
						// Extra: Borra esta lista y copia la nueva
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						// Retorno: si se ha copiado
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual bool operator=(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0) LinkedList::clear();
							else
							{
								LinkedList::clear();
								LinkedList::add(list);
							}
							return resultado;
						}
						#pragma endregion
						#pragma region Getters
						// Version: Final
						// Retorno: Si la lista incrementa su capacidad maxima por si misma
						// Complejidad temporal y espacial: O(1) y M(1)
						inline virtual bool autoIncrementable() const override { return true; }
						// Funcion: Obtiene el objeto solicitado
						// Extra: Hay que pasar un puentero del tipo de objeto apuntando a nullptr
						// Extra2: Si el puntero contiene memoria no liberada, esta se pondra a nullptr pero no se liberara
						// Version: Beta
						// Precondiciones:
						//		posicion < count
						//		object == nullptr
						// Retorno: Si el objeto se ha obtenido
						// Complejidad temporal y espacial peor: O(n/2) y M(1)
						// Complejidad temporal y espacial mejor: O(1) y M(1)
						inline virtual T* get(const size_t& position) override
						{
							T* resultado = nullptr;
							if (&position != nullptr && position < this->count)
								resultado = &LinkedList::getNodoCache(position)->getObject0();
							return resultado;
						}
						// Funcion: Busca el objeto del nodo solicitado
						// Extra: No se recomienda buscar una posicion no valida
						// Throws: Exception
						// Version: Beta
						// Precondiciones:
						//		position < count
						// Retorno: Objeto solicitado
						// Complejidad temporal y espacial: O(n/2) y M(1)
						inline virtual T& operator[] (const size_t& position) const THROW override
						{
							if (position > this->count)
								throw Objetos::Excepcion("position > count: 'Position must be lower than list.count'", __FUNCTION__);
							return LinkedList::getNodoLow(position)->getObject0();
						}
						///inline virtual T* getVector() override { return nullptr; }
						#pragma endregion
						#pragma region Funciones de la lista
						// Funcion: Agrega un objeto al final de la lista
						// Version: Beta
						// Precondiciones:
						//		object != nullptr
						// Retorno: Si se ha agregado a la lista
						// Complejidad temporal y espacial: O(1) y M(1)
						virtual bool add(const T& object) override
						{
							bool resultado = false;
							if (&object != nullptr)
							{
								// Creamos el nodo
								Nodos::NUODP<T>* nuevoNodo = new Nodos::NUODP<T>(object);
								// Caso especial de que la lista este vacia
								if (this->count == 0)
								{
									this->raiz = nuevoNodo;
									nuevoNodo->setPrimerNodo(nuevoNodo);
									nuevoNodo->setSegundoNodo(nuevoNodo);
								}
								// Añadirmos al final
								else
								{
									// Guardamos los nodos que vamos a modificar
									Nodos::NUODP<T>* anteriorNodo = LinkedList::getNodoCache(this->count - 1);
									Nodos::NUODP<T>* siguienteNodo = anteriorNodo->getPrimerNodo();

									// Apuntamos correctamente el nodo entre los otros nodos
									nuevoNodo->setPrimerNodo(siguienteNodo);
									nuevoNodo->setSegundoNodo(anteriorNodo);
									// Hacemos que los otros nodos apunten al nuevo
									anteriorNodo->setPrimerNodo(nuevoNodo);
									siguienteNodo->setSegundoNodo(nuevoNodo);
								}
								// Incrementamos el tamaño
								this->count++;
								resultado = true;
							}
							return resultado;
						}
						// Funcion: Agrega una lista de objetos al final de esta lista
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si se ha agregado todos los objetos
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual bool add(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list != nullptr) {
								for (size_t i = 0; i < list.getCount() && resultado; i++)
									resultado = LinkedList::add(list[i]);
							}
							else resultado = false;
							return resultado;
						}
						// Funcion: Hace de proxy a la funcion add()
						virtual bool operator+=(const T& object) override { return LinkedList::add(object); }
						// Funcion: Hace de proxy a la funcion add()
						virtual bool operator+=(const Interfaces::List<T>& list) override { return LinkedList::add(list); }
						// Funcion: Inserta un objeto a la lista en la posicion indicada
						// Version: Beta
						// Precondiciones:
						//		object != nullptr
						//		position > count
						// Retorno: Si se ha insetado el objeto
						// Complejidad temporal y espacial peor: O(n/2) y M(1)
						// Complejidad temporal y espacial mejor: O(1) y M(1)
						virtual bool insert(const T& object, const size_t& position) override
						{
							bool resultado = false;
							if (&object != nullptr && &position != nullptr && position < this->count)
							{
								// Creamos el nodo
								Nodos::NUODP<T>* nuevoNodo = new Nodos::NUODP<T>(object);
								// Guardamos los nodos que vamos a modificar
								Nodos::NUODP<T>* anteriorNodo = nullptr;
								Nodos::NUODP<T>* siguienteNodo = nullptr;
								if (position == 0) anteriorNodo = LinkedList::getNodoCache(this->count - 1);
								else anteriorNodo = LinkedList::getNodoCache(position - 1);
								siguienteNodo = anteriorNodo->getPrimerNodo();
								// Apuntamos correctamente el nodo entre los otros nodos
								nuevoNodo->setPrimerNodo(siguienteNodo);
								nuevoNodo->setSegundoNodo(anteriorNodo);
								// Hacemos que los otros nodos apunten al nuevo
								anteriorNodo->setPrimerNodo(nuevoNodo);
								siguienteNodo->setSegundoNodo(nuevoNodo);
								// Incrementamos el tamaño
								this->count++;
								resultado = true;
							}
							return resultado;
						}
						// Funcion: Elimina un objeto de la lista
						// Version: Beta
						// Precondiciones:
						//		position < count
						// Retorno: Si se ha eliminado el objeto solicitado
						// Complejidad temporal y espacial peor: O(n/2) y M(1)
						// Complejidad temporal y espacial mejor: O(1) y M(1)
						virtual bool remove(const size_t& position) override
						{
							bool resultado = false;
							if (&position != nullptr && position < this->count) {
								// Nodos a modificar
								Nodos::NUODP<T>* nodoAEliminar = nullptr;
								if (this->count == 1) {
									nodoAEliminar = this->raiz;
									this->raiz = nullptr;
								}
								else {
									// Hacemos esto para aumentar al eficiencia al eliminar el nodo 0
									if (position == 0) nodoAEliminar = LinkedList::getNodoNoCache(position);
									else nodoAEliminar = LinkedList::getNodoCache(position);

									Nodos::NUODP<T>* nodoSiguiente = nodoAEliminar->getPrimerNodo();
									Nodos::NUODP<T>* nodoAnterior = nodoAEliminar->getSegundoNodo();
									// Modificamos los nodos
									nodoAnterior->setPrimerNodo(nodoSiguiente);
									nodoSiguiente->setSegundoNodo(nodoAnterior);
									// Si es un caso especial
									if (position == 0) this->raiz = nodoSiguiente;
									// Recolocamos el punto intermedio
									this->cacheNodo = nullptr;
									this->cachePosicionNodo = 0;
									// Incrementamos el tamaño
								}
								delete(nodoAEliminar);
								this->count--;
								resultado = true;
							}
							return resultado;
						}
						// Funcion: Limpia la lista
						// Extra: La deja preparada para poder volver a usarla
						// Version: Beta
						// Complejidad temporal y espacial: O(n) y M(1)
						inline virtual void clear() override
						{
							while (this->count > 0) LinkedList::remove(0);
							this->count = 0;
							this->raiz = nullptr;
							this->cacheNodo = nullptr;
							this->cachePosicionNodo = 0;
						}
						// Aun no planteada
						inline virtual void sort(int Compare(const void* a, const void* b)) override
						{

						}
						#pragma endregion
						#pragma region Busquedas
						// Funcion: Busca un objeto solicitado
						// Version: Beta
						// Precondiciones:
						//		object != nullptr
						// Retorno: Si el objeto existe
						// Complejidad temporal y espacial: O(n/2) y M(1)
						inline virtual bool contains(const T& object) const override
						{
							bool resultado = false;
							if (&object != nullptr)
								for (size_t i = 0; i < this->count && !resultado; i++)
									resultado = (LinkedList::operator[](i) == object);
							return resultado;
						}
						// Funcion: Busca un objeto solicitado utilizando una funcion
						// Extra: La funcion la define el usuario
						// Extra 2: Si la funcion es nullptr usara == de por defecto
						// Version: Beta
						// Precondiciones:
						//		object != nullptr
						//		Compare != nullptr
						// Retorno: Si el objeto existe
						// Complejidad temporal y espacial: O(n/2) y M(1)
						inline virtual bool contains(const T& object, bool Compare(const void* item_a, const void* item_b)) const override
						{
							bool resultado = false;
							if (&object != nullptr) {
								if (Compare != nullptr) {
									for (size_t i = 0; i < this->count && !resultado; i++)
										resultado = Compare(&LinkedList::operator[](i), &object);
								}
								else resultado = LinkedList::contains(object);
							}
							return resultado;
						}
						inline virtual bool find(const T& object, size_t* pos) const override
						{
							bool resultado = false;
							if (&object != nullptr)
								if(pos != nullptr)
									for (size_t i = 0; i < this->count && !resultado; i++)
										if (LinkedList::operator[](i) == object) {
											resultado = true;
											*pos = i;
										}
							return resultado;
						}
						inline virtual bool find(const T& object, size_t* pos, bool Compare(const void* item_a, const void* item_b)) const override
						{
							bool resultado = false;
							if (&object != nullptr) {
								if (Compare != nullptr) {
									for (size_t i = 0; i < this->count && !resultado; i++)
										if (Compare(&LinkedList::operator[](i), &object)) {
											resultado = true;
											*pos = i;
										}
								}
								else resultado = LinkedList::find(object, pos);
							}
							return resultado;
						}
						#pragma endregion
						#pragma region Comparaciones
						// Funcion: Compara el contenido de esta lista con el de otra lista
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si las listas son exactamente iguales
						// Complejidad temporal y espacial: O(n) y M(1)
						inline virtual bool equals(const Interfaces::List<T>& list) const override
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else
							{
								if (list.getCount() == this->count)
									for (size_t i = 0; i < this->count && resultado; i++)
										resultado = (LinkedList::operator[](i) == list[i]);
								else resultado = false;
							}
							return resultado;
						}
						// Funcion: Compara el contenido de esta lista con el de otra lista con una funcion
						// Extra: La funcion la define el usuario
						// Extra 2: Si la funcion es nullptr usara == de por defecto
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						//		Compare != nullptr
						// Retorno: Si las listas son exactamente iguales
						// Complejidad temporal y espacial: O(n) y M(1)
						inline virtual bool equals(const Interfaces::List<T>& list, bool Compare(const void* item_a, const void* item_b)) const override
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else if (Compare != nullptr)
							{
								if (list.getCount() == this->count)
									for (size_t i = 0; i < this->count && resultado; i++)
										resultado = Compare(&LinkedList::operator[](i), &list[i]);
								else resultado = false;
							}
							else resultado = LinkedList::equals(list);
							return resultado;
						}
						// Funcion: Compara dos listas si son similares
						// Extra: Un ejemplo seria dos listas que tienen los mismos objetos pero en orden distinto
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						// Retorno: Void
						// Complejidad temporal y espacial: O(n^2/2) y M(1)
						inline virtual bool similar(const Interfaces::List<T>& list) const override
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else
							{
								if (list.getCount() == this->count)
									for (size_t i = 0; i < this->count && resultado; i++)
										resultado = LinkedList::contains(list[i]);
								else resultado = false;
							}
							return resultado;
						}
						// Funcion: Compara dos listas si son similares con una funcion
						// Extra: La funcion la define el usuario
						// Extra 2: Si la funcion es nullptr usara == de por defecto
						// Extra 3: Un ejemplo seria dos listas que tienen los mismos objetos pero en orden distinto
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						//		Compare != nullptr
						// Retorno: Void
						// Complejidad temporal y espacial: O(n^2/2) y M(1)
						inline virtual bool similar(const Interfaces::List<T>& list, bool Compare(const void* item_a, const void* item_b)) const override
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else if (Compare != nullptr)
							{
								if (list.getCount() == this->count)
									for (size_t i = 0; i < this->count && resultado; i++)
										resultado = LinkedList::contains(list[i], Compare);
								else resultado = false;
							}
							else resultado = LinkedList::similar(list);
							return resultado;
						}
						// Funcion: Hace de proxy a la funcion equals()
						inline virtual bool operator==(const Interfaces::List<T>& list) const { return LinkedList::equals(list); }
						// Funcion: Hace de proxy a la funcion equals()
						inline virtual bool operator!=(const Interfaces::List<T>& list) const { return !LinkedList::equals(list); }
						#pragma endregion
						#pragma endregion
						#pragma region Funciones No Heredadas
						#pragma region Constructores
						// Funcion: Crea una lista segun otra lista copiandola
						// Extra: Hace de proxy al operador = (Si algo falla la deja vacia)
						// Version: Beta
						// Precondiciones:
						//		&list != nullptr
						// Retorno: Void
						// Complejidad temporal y espacial: O(n) y M(n)
						inline LinkedList(const Interfaces::List<T>& list) : LinkedList() { LinkedList::operator=(list); }
						// Funcion: Crea una lista doblemente enlazada circular
						// Version: Beta
						// Complejidad temporal y espacial: O(1) y M(1)
						inline LinkedList()
						{
							this->raiz = nullptr;
							this->cacheNodo = nullptr;
							this->cachePosicionNodo = 0;
						}
						inline LinkedList(const T& obj) : LinkedList() { LinkedList::add(obj); }
						// Funcion: Elimina la lista
						// Version: Beta
						// Complejidad temporal y espacial: O(n) y M(1)
						inline ~LinkedList()
						{
							LinkedList::clear();
							this->cacheNodo = nullptr;
							this->cachePosicionNodo = 0;
						}
						inline LinkedList(const LinkedList<T>& list) : LinkedList() { LinkedList::operator=(list); }
						inline bool operator=(const LinkedList<T>& list)
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0) LinkedList::clear();
							else
							{
								LinkedList::clear();
								LinkedList::add(list);
							}
							return resultado;
						}
						#pragma endregion
						#pragma region Funciones de la lista
						// Funcion: Agrega una lista de objetos al final de esta lista
						// Extra: Optimizado para mejorar la eficiencia de obtencion de nodo y copiado
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si se ha agregado todos los objetos
						// Complejidad temporal y espacial: O(n) y M(n)
						inline bool add(const LinkedList<T>& list)
						{
							bool resultado = true;
							if (&list != nullptr) {
								Nodos::NUODP<T>* nodoActual = list.raiz;
								for (size_t i = 0; i < list.getCount() && resultado; i++) {
									resultado = LinkedList::add(nodoActual->getObject0());
									nodoActual = nodoActual->getPrimerNodo();
								}
							}
							else resultado = false;
							return resultado;
						}
						#pragma endregion
						#pragma region Comparaciones
						// Funcion: Compara el contenido de esta lista con el de otra lista
						// Extra: Optimizado para mejorar la eficiencia de obtencion de nodo
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si las listas son exactamente iguales
						// Complejidad temporal y espacial: O(n) y M(1)
						inline bool equals(const LinkedList<T>& list) const
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else
							{
								if (list.getCount() == this->count)
								{
									Nodos::NUODP<T>* nodoActualThis = this->raiz;
									Nodos::NUODP<T>* nodoActualList = list.raiz;
									for (size_t i = 0; i < this->count && resultado; i++) {
										resultado = (nodoActualThis->getObject0() == nodoActualList->getObject0());
										nodoActualList = nodoActualList->getPrimerNodo();
										nodoActualThis = nodoActualThis->getPrimerNodo();
									}
								}
								else resultado = false;
							}
							return resultado;
						}
						// Funcion: Compara el contenido de esta lista con el de otra lista con una funcion
						// Extra: Optimizado para mejorar la eficiencia de obtencion de nodo
						// Extra 1: La funcion la define el usuario
						// Extra 2: Si la funcion es nullptr usara == de por defecto
						// Version: Beta
						// Precondiciones:
						//		list != nullptr
						//		Compare != nullptr
						// Retorno: Si las listas son exactamente iguales
						// Complejidad temporal y espacial: O(n) y M(1)
						inline bool equals(const LinkedList<T>& list, bool Compare(const void* item_a, const void* item_b)) const
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else if (Compare != nullptr)
							{
								if (list.getCount() == this->count)
								{
									Nodos::NUODP<T>* nodoActualThis = this->raiz;
									Nodos::NUODP<T>* nodoActualList = list.raiz;
									for (size_t i = 0; i < this->count && resultado; i++) {
										resultado = Compare(&nodoActualThis->getObject0(), &nodoActualList->getObject0());
										nodoActualList = nodoActualList->getPrimerNodo();
										nodoActualThis = nodoActualThis->getPrimerNodo();
									}
								}
								else resultado = false;
							}
							else resultado = LinkedList::equals(list);
							return resultado;
						}
						// Funcion: Compara dos listas si son similares
						// Extra: Optimizado para mejorar la eficiencia de obtencion de nodo
						// Extra 1: Un ejemplo seria dos listas que tienen los mismos objetos pero en orden distinto
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si las listas son iguales/similares
						// Complejidad temporal y espacial: O(n^2/2) y M(1)
						inline bool similar(const LinkedList<T>& list) const
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else
							{
								if (list.getCount() == this->count) {
									Nodos::NUODP<T>* nodoActual = list.raiz;
									for (size_t i = 0; i < this->count && resultado; i++) {
										resultado = LinkedList::contains(nodoActual->getObject0());
										nodoActual = nodoActual->getPrimerNodo();
									}
								}
								else resultado = false;
							}
							return resultado;
						}
						// Funcion: Compara dos listas si son similares
						// Extra: Optimizado para mejorar la eficiencia de obtencion de nodo
						// Extra 1: La funcion la define el usuario
						// Extra 2: Si la funcion es nullptr usara == de por defecto
						// Extra 3: Un ejemplo seria dos listas que tienen los mismos objetos pero en orden distinto
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						//		Compare != nullptr
						// Retorno: Si las listas son iguales/similares
						// Complejidad temporal y espacial: O(n^2/2) y M(1)
						inline bool similar(const LinkedList<T>& list, bool Compare(const void* item_a, const void* item_b)) const
						{
							bool resultado = true;
							if (&list == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&list == nullptr) resultado = false;
							else if (Compare != nullptr)
							{
								if (list.getCount() == this->count)
								{
									Nodos::NUODP<T>* nodoActual = list.raiz;
									for (size_t i = 0; i < this->count && resultado; i++) {
										resultado = LinkedList::contains(nodoActual->getObject0(), Compare);
										nodoActual = nodoActual->getPrimerNodo();
									}
								}
								else resultado = false;
							}
							else resultado = LinkedList::similar(list);
							return resultado;
						}
						// Funcion: Hace de proxy a la funcion equals()
						inline bool operator==(const LinkedList<T>& list) const { return LinkedList::equals(list); }
						// Funcion: Hace de proxy a la funcion equals()
						inline bool operator!=(const LinkedList<T>& list) const { return !LinkedList::equals(list); }
						#pragma endregion
						#pragma endregion
				};
			}
		}
	}
}
#endif // !LINKED_LIST_TEMPLATE_HPP_
