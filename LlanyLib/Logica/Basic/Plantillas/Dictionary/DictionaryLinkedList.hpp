#pragma once
#ifndef DICTIONARY_LINKED_LIST_TEMPLATE_HPP_
#define DICTIONARY_LINKED_LIST_TEMPLATE_HPP_

#include "../../Interfaces/Dictionary.hpp"
#include "../Nodos/NodoDosObjetosDosPunteros.hpp"

namespace LlanyLib
{
	namespace Basic
	{
		namespace Interfaces {
			template<class T0, class T1>
			class ContenedorDobleTipo;
		}
		namespace Templates
		{
			namespace Diccionarios
			{
				template<class T1, class T2>
				class DictionaryLinkedList : public LlanyLib::Basic::Interfaces::Dictionary<T1, T2>
				{
					protected:
						Nodos::NDODP<T1, T2>* raiz;
						// Falsos punteros para poder modificarlos sin quitar el const
						Nodos::NDODP<T1, T2>* cacheNodo;
						// Falsos punteros para poder modificarlos sin quitar el const
						size_t cachePosicionNodo;
					protected:
						#pragma region Funciones de busquedas internas
						virtual Nodos::NDODP<T1, T2>* getNodoNoCache(const size_t& position)
						{
							Nodos::NDODP<T1, T2>* nodoActual = nullptr;
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
						virtual Nodos::NDODP<T1, T2>* getNodoCache(const size_t& position)
						{
							Nodos::NDODP<T1, T2>* nodoActual = nullptr;
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
									nodoActual = DictionaryLinkedList::getNodoNoCache(position);
							}
							return nodoActual;
						}
						virtual Nodos::NDODP<T1, T2>* getNodoLow(const size_t& position) const
						{
							Nodos::NDODP<T1, T2>* nodoActual = nullptr;
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
						virtual Nodos::NDODP<T1, T2>* getNodoKey(const T1& key) const
						{
							Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
							Nodos::NDODP<T1, T2>* nodoReturn = nullptr;
							for (size_t i = 0; i < this->count; i++)
							{
								if (nodoActual->getObject0() == key) {
									i = this->count;
									nodoReturn = nodoActual;
								}
								else
									nodoActual = nodoActual->getPrimerNodo();
							}
							return nodoReturn;
						}
						#pragma endregion
					public:
						#pragma region Funciones Heredadas
						#pragma region Constructores
						inline virtual bool copy(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) override { return DictionaryLinkedList::operator=(dict); }
						inline virtual bool operator=(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) override
						{
							bool resultado = true;
							if (&dict == nullptr) resultado = false;
							else if (dict.getCount() == 0) DictionaryLinkedList::clear();
							else
							{
								DictionaryLinkedList::clear();
								DictionaryLinkedList::add(dict);
							}
							return resultado;
						}
						inline virtual LlanyLib::Basic::Interfaces::Dictionary<T1, T2>* clone() const override { return new DictionaryLinkedList<T1, T2>(*this); }
						#pragma endregion
						#pragma region Getters
						inline virtual bool autoIncrementable() const override { return true; }
						inline virtual T2* get(const T1& key) override
						{
							T2* resultado = nullptr;
							if (&key != nullptr) {
								Nodos::NDODP<T1, T2>* nodo = DictionaryLinkedList::getNodoKey(key);
								if (nodo != nullptr)
									resultado = &nodo->getObject1();
							}
							return resultado;
						}
						inline virtual T2& operator[] (const T1& key) const THROW override
						{
							T2* resultado = nullptr;
							if (&key != nullptr) {
								Nodos::NDODP<T1, T2>* nodo = DictionaryLinkedList::getNodoKey(key);
								if (nodo != nullptr)
									resultado = &nodo->getObject1();
								else
									throw Objetos::Excepcion("Key dont exist in dict", __FUNCTION__);
							}
							return *resultado;
						}
						#pragma endregion
						#pragma region Funciones de la lista
						virtual bool add(const T1& key, const T2& value) override
						{
							bool resultado = false;
							if (&key != nullptr && &value != nullptr)
							{
								// Creamos el nodo
								Nodos::NDODP<T1, T2>* nuevoNodo = new Nodos::NDODP<T1, T2>(key, value);
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
									Nodos::NDODP<T1, T2>* anteriorNodo = DictionaryLinkedList::getNodoCache(this->count - 1);
									Nodos::NDODP<T1, T2>* siguienteNodo = anteriorNodo->getPrimerNodo();

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
						inline virtual bool add(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) override { return false; }
						inline virtual bool operator+=(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) override { return DictionaryLinkedList::add(dict); }
						virtual bool remove(const T1& key) override
						{
							bool resultado = false;
							if (&key != nullptr)
							{
								// Nodos a modificar
								Nodos::NDODP<T1, T2>* nodoAEliminar = nullptr;
								// Hacemos esto para aumentar al eficiencia al eliminar el nodo 0
								nodoAEliminar = DictionaryLinkedList::getNodoKey(key);

								Nodos::NDODP<T1, T2>* nodoSiguiente = nodoAEliminar->getPrimerNodo();
								Nodos::NDODP<T1, T2>* nodoAnterior = nodoAEliminar->getSegundoNodo();
								// Modificamos los nodos
								nodoAnterior->setPrimerNodo(nodoSiguiente);
								nodoSiguiente->setSegundoNodo(nodoAnterior);
								// Si es un caso especial
								if (nodoAEliminar == this->raiz)
									this->raiz = nodoSiguiente;
								// Recolocamos el punto intermedio
								this->cacheNodo = nullptr;
								this->cachePosicionNodo = 0;
								// Incrementamos el tamaño
								delete(nodoAEliminar);
								this->count--;
								resultado = true;
							}
							return resultado;
						}
						inline virtual void clear() override
						{
							// Penultimo
							Nodos::NDODP<T1, T2>* nodoActual = this->raiz->getSegundoNodo()->getSegundoNodo();
							Nodos::NDODP<T1, T2>* nodoAEliminar = nullptr;

							while (this->count > 1)
							{
								nodoAEliminar = nodoActual->getPrimerNodo();
								delete nodoAEliminar;
								nodoActual = nodoActual->getSegundoNodo();
								this->count--;
							}

							delete this->raiz;

							this->count = 0;
							this->raiz = nullptr;
							this->cacheNodo = nullptr;
							this->cachePosicionNodo = 0;
						}
						#pragma endregion
						#pragma region Busquedas
						inline virtual bool contains(const T1& key, const T2& value) const override
						{
							bool resultado = false;
							if (&key != nullptr) {
								Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
								for (size_t i = 0; i < this->count; i++) {
									if (nodoActual->getObject0() == key && nodoActual->getObject1() == value) {
										i = this->count;
										resultado = true;
									}
									else
										nodoActual = nodoActual->getPrimerNodo();
								}
							}
							return resultado;
						}
						inline virtual bool containsKey(const T1& key) const override
						{
							bool resultado = false;
							if (&key != nullptr) {
								Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
								for (size_t i = 0; i < this->count; i++) {
									if (nodoActual->getObject0() == key) {
										i = this->count;
										resultado = true;
									}
									else
										nodoActual = nodoActual->getPrimerNodo();
								}
							}
							return resultado;
						}
						inline virtual bool containsValue(const T2& value) const override
						{
							bool resultado = false;
							if (&value != nullptr) {
								Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
								for (size_t i = 0; i < this->count; i++) {
									if (nodoActual->getObject1() == value) {
										i = this->count;
										resultado = true;
									}
									else
										nodoActual = nodoActual->getPrimerNodo();
								}
							}
							return resultado;
						}
						inline virtual bool contains(const T1& key, const T2& value,
							bool CompareKey(const void* item_a, const void* item_b),
							bool CompareValue(const void* item_a, const void* item_b)) const override 
						{
							bool resultado = false;
							if (&key != nullptr) {
								Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
								for (size_t i = 0; i < this->count; i++) {
									if (CompareKey(&nodoActual->getObject0(), &key) && CompareValue(&nodoActual->getObject1(), &value)) {
										i = this->count;
										resultado = true;
									}
									else
										nodoActual = nodoActual->getPrimerNodo();
								}
							}
							return resultado;
						}
						/*inline virtual bool containsKey(const T1& key, bool CompareKey(const void* item_a, const void* item_b)) const override
						{
							bool resultado = false;
							if (&key != nullptr) {
								Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
								for (size_t i = 0; i < this->count; i++) {
									if (CompareKey(&nodoActual->getObject0(), &key)) {
										i = this->count;
										resultado = true;
									}
									else
										nodoActual = nodoActual->getPrimerNodo();
								}
							}
							return resultado;
						}
						inline virtual bool containsValue(const T2& value, bool CompareValue(const void* item_a, const void* item_b)) const override
						{
							bool resultado = false;
							if (&value != nullptr) {
								Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
								for (size_t i = 0; i < this->count; i++) {
									if (CompareValue(&nodoActual->getObject1(), &value)) {
										i = this->count;
										resultado = true;
									}
									else
										nodoActual = nodoActual->getPrimerNodo();
								}
							}
							return resultado;
						}*/
						#pragma endregion
						#pragma region Comparaciones
						inline virtual bool equals(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) const
						{
							return false;
						}
						inline virtual bool equals(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict,
							bool CompareKey(const void* item_a, const void* item_b),
							bool CompareValue(const void* item_a, const void* item_b)) const
						{
							return false;
						}
						inline virtual bool similar(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) const
						{
							bool resultado = true;
							if (&dict == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&dict == nullptr) resultado = false;
							else {
								if (dict.getCount() == this->count) {
									Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
									for (size_t i = 0; i < this->count && resultado; i++) {
										resultado = DictionaryLinkedList::contains(nodoActual->getObject0(), nodoActual->getObject1());
										nodoActual = nodoActual->getPrimerNodo();
									}
								}
								else resultado = false;
							}
							return resultado;
						}
						inline virtual bool similar(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict,
							bool CompareKey(const void* item_a, const void* item_b),
							bool CompareValue(const void* item_a, const void* item_b)) const
						{
							bool resultado = true;
							if (&dict == this) resultado = true;
							else if (this == nullptr) resultado = false;
							else if (&dict == nullptr) resultado = false;
							else {
								if (dict.getCount() == this->count) {
									Nodos::NDODP<T1, T2>* nodoActual = this->raiz;
									for (size_t i = 0; i < this->count && resultado; i++) {
										resultado = DictionaryLinkedList::contains(nodoActual->getObject0(), nodoActual->getObject1(), CompareKey, CompareValue);
										nodoActual = nodoActual->getPrimerNodo();
									}
								}
								else resultado = false;
							}
							return resultado;
						}
						inline virtual bool operator==(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) const override { return DictionaryLinkedList::equals(dict); }
						inline virtual bool operator!=(const LlanyLib::Basic::Interfaces::Dictionary<T1, T2>& dict) const override { return !DictionaryLinkedList::equals(dict); }
						#pragma endregion
						#pragma endregion
						#pragma region No Heredadas
						inline DictionaryLinkedList()
						{
							this->raiz = nullptr;
							this->cacheNodo = nullptr;
							this->cachePosicionNodo = 0;
						}
						inline ~DictionaryLinkedList()
						{
							DictionaryLinkedList::clear();
							this->cacheNodo = nullptr;
							this->cachePosicionNodo = 0;
						}
						inline Nodos::NDODP<T1, T2>* getObject(const size_t& pos) const THROW
						{
							if (pos > this->count)
								throw Objetos::Excepcion("position > count: 'Position must be lower than dict.count'", __FUNCTION__);
							return DictionaryLinkedList::getNodoLow(pos);
						}
						#pragma endregion
				};
			}
		}
	}
}
#endif // !DICTIONARY_LINKED_LIST_TEMPLATE_HPP_
