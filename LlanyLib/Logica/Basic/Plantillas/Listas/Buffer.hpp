#pragma once
#ifndef BUFFER_LIST_TEMPLATE_HPP_
#define BUFFER_LIST_TEMPLATE_HPP_

#include "LinkedList.hpp"
#include "Array.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class Buffer : public Interfaces::List<T>
				{
					protected:
						// Tamaño de los blosques
						size_t sizeArray;
						// Lista de bloques del buffer
						LinkedList<Array<T>> listaArrays;
						// Array de datos actual (Donde metemos los datos)
						Array<T>* bloque;
					protected:
						#pragma region Funciones
						inline void crearNuevoArray()
						{
							// Creamos un bloque nuevo
							this->listaArrays.add(Array<T>(this->sizeArray));
							// Guardamos el puntero de el ultimo bloque(Actual)
							this->bloque = &this->listaArrays[this->listaArrays.getCount() - 1];
						}
						inline Array<T>* getArray(const size_t& position)
						{
							Array<T>* resultado = nullptr;
							if (&position != nullptr && position < this->listaArrays.getCount())
								resultado = this->listaArrays.get(position);
							return resultado;
						}
						#pragma endregion
					public:
						#pragma region Funciones Heredadas
						#pragma region Constructores
						inline virtual Buffer<T>* clone() const override { return new Buffer<T>(*this); }
						inline virtual bool copy(const Interfaces::List<T>& list) override { return Buffer::operator=(list); }
						inline Buffer(const Interfaces::List<T>& list) : Buffer() { Buffer::operator=(list); }
						inline virtual bool operator=(const Interfaces::List<T>& list) override
						{
							bool temp = true;
							if (&list == nullptr) temp = false;
							else if (list.getCount() == 0) temp = false;
							else
							{
								this->sizeArray = list.getCount();
								Buffer::clear();
								Buffer::add(list);
							}
							return temp;
						}
						#pragma endregion
						#pragma region Getters
						inline virtual bool autoIncrementable() const override { return true; }
						inline T* get(const size_t& position) override
						{
							T* resultado = nullptr;
							Array<T>* bloque = Buffer::getArray(position / this->sizeArray);
							if (bloque != nullptr)
								resultado = bloque->get(position % this->sizeArray);
							return resultado;
						}
						inline T& operator[](const size_t& position) const THROW override
						{
							if (position > this->count)
								throw Objetos::Excepcion("position > count: 'Position must be lower than list count'", __FUNCTION__);

							size_t arrpos = position / this->sizeArray;
							Array<T>* arrres = nullptr;
							if (arrpos < this->listaArrays.getCount())
								arrres = &this->listaArrays[position / this->sizeArray];
				
							size_t objpos = position % this->sizeArray;
							T* obj = nullptr;
							if (arrres != nullptr)
								obj = &arrres->operator[](objpos);

							if(obj == nullptr)
								throw Objetos::Excepcion("obj == nullptr: 'Did not find any object'", __FUNCTION__);
							return *obj;
						}
						///No preparado para obtener un array de Clases, solo usar cuando se tienen tipos simples
						inline virtual T* getVector() {
							T* vector = new T[this->count];
							size_t objAdded = 0;
							for (size_t i = 0; i < this->listaArrays.getCount(); i++)
							{
								MEM->copiarMemoria(
									&vector[objAdded], &this->listaArrays[i][0],
									0, this->listaArrays[i].getCount(), sizeof(T));
								objAdded += this->listaArrays[i].getCount();
							}
							return vector;
						}
						/*inline const Array<T>* getArray(const size_t& position)
						{
							Array<T>* resultado = nullptr;
							if (&position != nullptr && position < this->listaArrays.getCount())
								resultado = this->listaArrays.get(position);
							return resultado;
						}*/
						inline size_t getNumBlocks() const { return this->listaArrays.getCount(); }
						#pragma endregion
						#pragma region Funciones de la lista
						inline virtual bool add(const T& item) override
						{
							bool resultado = false;
							if (&item != nullptr)
							{
								// Si se puede añadir
								if (this->bloque->add(item))
									this->count++;
								// Si no se puede, es que esta lleno
								else
								{
									// Creamos un bloque nuevo
									Buffer::crearNuevoArray();
									// Llamamos de nuevo a la funcion y que se añada d eforma natural
									Buffer::add(item);
								}
								resultado = true;
							}
							return resultado;
						}
						inline virtual bool add(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list != nullptr)
							{
								for (size_t i = 0; i < list.getCount() && resultado; i++)
									resultado = Buffer::add(list[i]);
							}
							else resultado = false;
							return resultado;
						}
						inline virtual bool operator+=(const T& item) override { return Buffer::add(item); }
						inline virtual bool operator+=(const Interfaces::List<T>& list) override { return Buffer::add(list); }
						inline virtual bool insert(const T& object, const size_t& position) override { return false; }
						inline virtual bool remove(const size_t& position) override { return false; }
						void clear()
						{
							this->count = 0;
							this->listaArrays.clear();
							this->bloque = nullptr;
							Buffer::crearNuevoArray();
						}
						#pragma endregion
						/// Busquedas
						inline virtual bool contains(const T& object) const override { return false; }
						inline virtual bool contains(const T& object, bool Compare(const void* item_a, const void* item_b)) const override { return false; }
						/// Comparaciones
						inline virtual bool equals(const Interfaces::List<T>& list) const override { return false; }
						inline virtual bool equals(const Interfaces::List<T>& list, bool Compare(const void* item_a, const void* item_b)) const override { return false; }
						inline virtual bool similar(const Interfaces::List<T>& list) const override { return false; }
						inline virtual bool similar(const Interfaces::List<T>& list, bool Compare(const void* item_a, const void* item_b)) const override { return false; }
						inline virtual bool operator==(const Interfaces::List<T>& list) const override { return false; }
						inline virtual bool operator!=(const Interfaces::List<T>& list) const override { return false; }
						#pragma endregion
						#pragma region Funciones No Heredadas
						#pragma region Constructores
						inline Buffer() : Buffer(300) {}
						inline Buffer(const size_t& blockSize)
						{
							this->sizeArray = blockSize;
							this->count = 0;
							Buffer::crearNuevoArray();
						}
						inline Buffer(const Buffer<T>& buffer) : Buffer() { Buffer::operator=(buffer); }
						inline bool operator=(const Buffer<T>& buffer)
						{
							bool temp = true;
							if (&buffer == nullptr) temp = false;
							else if (buffer.getCount() == 0)
								Buffer::clear();
							else
							{
								this->sizeArray = buffer.sizeArray;
								Buffer::clear();
								Buffer::add(buffer);
							}
							return temp;
						}
						inline ~Buffer()
						{
							this->sizeArray = 0;
							this->count = 0;
							this->listaArrays.clear();
							this->bloque = nullptr;
						}
						#pragma endregion
						#pragma region Getters
						inline size_t getSize() const { return this->sizeArray; }
						inline size_t getNumArrays() const { return this->listaArrays.getCount(); }
						#pragma endregion
						#pragma region Funciones de la lista
						inline bool add(const T* block, const size_t& size)
						{
							bool resultado = false;
							if (block != nullptr && &size != nullptr && size > 0)
							{
								// Si solo es un item
								if (size == 1)
									Buffer::add(block[0]);
								// Si es mas de un item(Bloque de datos)
								else
								{
									// Intentamos añadirlo
									size_t result = this->bloque->add(block, size);
									// Si no se ha podido añadir todos los items
									if (result < size)
									{
										// Creamos un bloque nuevo
										Buffer::crearNuevoArray();

										//Si no se ha añadido ninguno es que el bloque esta lleno
										if (result == 0)
											Buffer::add(block, size);
										// Si se ha añadido algunos items
										else if (result < size)
											Buffer::add(block + result, size - result);
									}
									// Si todo sale bien, añadimos el conteo
									this->count += result;
									resultado = true;
								}
							}
							return resultado;
						}
						inline bool add(const Buffer<T>& other)
						{
							bool resultado = true;
							if (&other != nullptr)
							{
								for (size_t i = 0; i < other.listaArrays.getCount() && resultado; i++)
								{
									Array<T>* block = Buffer::getArray(i);
									if (block != nullptr && block->getCount() > 0)
										resultado = Buffer::add(&block->operator[](0), block->getCount());
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
#endif // !BUFFER_LIST_TEMPLATE_HPP_
