#pragma once
#ifndef LINKED_LIST_AUTO_TEMPLATE_HPP_
#define LINKED_LIST_AUTO_TEMPLATE_HPP_

#include "LinkedList.hpp"

namespace LlanyLib
{
	namespace Basic
	{
		namespace Templates
		{
			namespace Listas
			{
				template<class T>
				class LinkedListAuto : public LinkedList<T>
				{
					protected:
						// Indica si la ordecacion de la lista es de menor a mayor o al reves
						bool ascendente;
					public:
						#pragma region Funciones Heredadas
						#pragma region Constructores
						/// LinkedListAuto
						inline LinkedListAuto() { this->ascendente = true; }
						inline LinkedListAuto(const T& obj) : LinkedListAuto() { LinkedListAuto::add(obj); }
						inline ~LinkedListAuto() {}
						inline LinkedListAuto(const LinkedListAuto<T>& list) : LinkedListAuto() { LinkedListAuto::operator=(list); }
						inline bool operator=(const LinkedListAuto<T>& list)
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0) LinkedListAuto::clear();
							else
							{
								LinkedListAuto::clear();
								LinkedListAuto::add(list);
							}
							return resultado;
						}

						/// LinkedList
						inline LinkedListAuto(const LinkedList<T>& list) : LinkedListAuto() { LinkedListAuto::operator=(list); }
						inline bool operator=(const LinkedList<T>& list)
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0) LinkedListAuto::clear();
							else
							{
								LinkedListAuto::clear();
								LinkedListAuto::add(list);
							}
							return resultado;
						}

						/// List
						// Funcion: Crea un objeto clon de este
						// Version: Alfa
						// Retorno: El puntero al clon
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual Interfaces::List<T>* clone() const override { return new LinkedListAuto<T>(*this); }
						// Funcion: Hace de proxy al operador =
						inline virtual bool copy(const Interfaces::List<T>& list) override { return LinkedListAuto::operator=(list); }
						// Funcion: Crea una lista segun otra lista copiandola
						// Extra: Hace de proxy al operador = (Si algo falla la deja vacia)
						// Version: Alfa
						// Precondiciones:
						//		&list != nullptr
						// Retorno: Void
						// Complejidad temporal y espacial: O(n) y M(n)
						inline LinkedListAuto(const Interfaces::List<T>& list) : LinkedListAuto() { LinkedListAuto::operator=(list); }
						// Funcion: Copia la lista
						// Extra: Borra esta lista y copia la nueva
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: si se ha copiado
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual bool operator=(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0) LinkedListAuto::clear();
							else
							{
								LinkedListAuto::clear();
								LinkedListAuto::add(list);
							}
							return resultado;
						}
						#pragma endregion
						#pragma region Funciones de la lista
						// Funcion: Agrega un objeto al final de la lista
						// Version: Alfa
						// Precondiciones:
						//		object != nullptr
						// Retorno: Si se ha agregado a la lista
						// Complejidad temporal y espacial: O(n) y M(1)
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
								// Si es menor al primer nodo
								else if (object <= this->raiz->getObject())
								{
									nuevoNodo->setPrimerNodo(this->raiz);
									nuevoNodo->setSegundoNodo(this->raiz->getSegundoNodo());

									this->raiz->getSegundoNodo()->setPrimerNodo(nuevoNodo);
									this->raiz->setSegundoNodo(nuevoNodo);

									this->raiz = nuevoNodo;
								}
								// Si es mayor al ultimo
								else if (object >= this->raiz->getSegundoNodo()->getObject())
								{
									nuevoNodo->setPrimerNodo(this->raiz);
									nuevoNodo->setSegundoNodo(this->raiz->getSegundoNodo());

									this->raiz->getSegundoNodo()->setPrimerNodo(nuevoNodo);
									this->raiz->setSegundoNodo(nuevoNodo);
								}
								// Buscamos posicion
								else
								{
									/// Llamamos a la funcion de busqueda de posicion
									/// O vamos desde aqui moviendonos posicion a posicion hasta la correcta
									/// Recuerda usar la posicion de cache
									Nodos::NUODP<T>* nodoTemp = this->raiz;
									for (size_t i = 0; i < this->count; i++) {
										if (object >= nodoTemp->getObject()) {
											if (object <= nodoTemp->getPrimerNodo()->getObject()) {
												i = this->count;

												nuevoNodo->setPrimerNodo(nodoTemp->getPrimerNodo());
												nuevoNodo->setSegundoNodo(nodoTemp);

												nodoTemp->getPrimerNodo()->setSegundoNodo(nuevoNodo);
												nodoTemp->setPrimerNodo(nuevoNodo);
											}
										}
										nodoTemp = nodoTemp->getPrimerNodo();
									}
								}
								// Incrementamos el tamaño
								this->count++;
								resultado = true;
							}
							return resultado;
						}
						// Funcion: Agrega una lista de objetos al final de esta lista
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si se ha agregado todos los objetos
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual bool add(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list != nullptr) {
								for (size_t i = 0; i < list.getCount() && resultado; i++)
									resultado = LinkedListAuto::add(list[i]);
							}
							else resultado = false;
							return resultado;
						}
						// Funcion: Hace de proxy a la funcion add()
						inline virtual bool operator+=(const T& object) override { return LinkedListAuto::add(object); }
						// Funcion: Hace de proxy a la funcion add()
						inline virtual bool operator+=(const Interfaces::List<T>& list) override { return LinkedListAuto::add(list); }
						// Funcion: Deshabilitado por razones obias
						// Retorno: Siempre false
						inline virtual bool insert(const T& object, const size_t& position) override { return false; }

						// Funcion: Agrega una lista de objetos al final de esta lista
						// Extra: Optimizado para mejorar la eficiencia de obtencion de nodo y copiado
						// Version: Alfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si se ha agregado todos los objetos
						// Complejidad temporal y espacial: O(n) y M(n)
						inline bool add(const LinkedListAuto<T>& list) 
						{
							bool resultado = true;
							if (&list != nullptr) {
								Nodos::NUODP<T>* nodoActual = list.raiz;
								for (size_t i = 0; i < list.getCount() && resultado; i++) {
									resultado = LinkedListAuto::add(nodoActual->getObject());
									nodoActual = nodoActual->getPrimerNodo();
								}
							}
							else resultado = false;
							return resultado;
						}
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
									resultado = LinkedListAuto::add(nodoActual->getObject());
									nodoActual = nodoActual->getPrimerNodo();
								}
							}
							else resultado = false;
							return resultado;
						}
						#pragma endregion
						#pragma endregion
				};
			}
		}
	}
}
#endif // !LINKED_LIST_AUTO_TEMPLATE_HPP_
