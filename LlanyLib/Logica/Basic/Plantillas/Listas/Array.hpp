#pragma once
#ifndef ARRAY_LIST_TEMPLATE_HPP_
#define ARRAY_LIST_TEMPLATE_HPP_

#include <cassert>

#include "../../Interfaces/List.hpp"
#include "../../Singletons/Mem.hpp"

namespace LlanyLib {
	namespace Basic 	{
		namespace Templates {
			namespace Listas {
				template<class T>
				class Array : public Interfaces::List<T>
				{
					protected:
						// Bloque de datos de los objetos(array)
						T* bloque;
						// Numero de objetos que caben en el bloque(MAX)
						size_t size;
						// Numero de huecos extra al llegar al maximo (0 Si es una lista cerrada)
						size_t incremento;
					protected:
						#pragma region Funciones internas lista
						// Funcion: Inicializa los parametros internos de la lista
						// Extra: incremento = 0
						// Version: Final/Beta/Alfa/PreAlfa
						// Complejidad temporal y espacial: O(1) y M(1)
						inline void inicializarArray(const size_t& size, const size_t& incremento)
						{
							this->bloque = nullptr;
							this->size = size;
							this->incremento = incremento;
							this->count = 0; // Puede que esto sea omitible
						}
						// Funcion: Limpia la lista dejandola a nullptr
						// Version: Beta
						// Complejidad temporal y espacial: O(1) y M(1)
						inline void clearSimpleArray()
						{
							if (this->bloque != nullptr)
								MEM->liberar((void**)(&this->bloque));
							this->bloque = nullptr;
							this->count = 0;
						}
						// Funcion: Limpia la lista dejandola a nullptr, reiniciada completamente
						// Version: Beta
						// Complejidad temporal y espacial: O(1) y M(1)
						inline void clearArray()
						{
							Array::clearSimpleArray();
							this->incremento = 0;
							this->size = 0;
						}
						// Funcion: Genera la lista con el tamaño que se ha solicitado
						// Extra: Si existe la lista la elimina
						// Version: Final/Beta/Alfa/PreAlfa
						// Complejidad temporal y espacial: O(1) y M(1)
						inline void newList()
						{
							if (this->bloque != nullptr)
								Array::clearSimpleArray();
							this->bloque = (T*)MEM->reservarMem(sizeof(T) * this->size);
						}
						// Version: Final/Beta/Alfa/PreAlfa
						// Retorno: Nos indica si se puede añadir n elementos nuevos
						// Complejidad temporal y espacial: O(1) y M(1)
						inline bool sePuedeAñadir(const size_t& numObjectAdd) const
						{
							bool resultado = false;
							if(&numObjectAdd != nullptr)
								resultado = (this->count + numObjectAdd <= this->size);
							return resultado;
						}
						inline size_t cuantosSePuedenAñadir(const size_t& numObjectAdd) const
						{
							size_t resultado = 0;
							if (&numObjectAdd != nullptr) {
								resultado = (this->size - this->count);
								if (resultado > numObjectAdd)
									resultado = numObjectAdd;
							}
							return resultado;
						}
						// Version: Final/Beta/Alfa/PreAlfa
						// Retorno: Nos indica si la lista puede aumentar de tamaño
						// Complejidad temporal y espacial: O(1) y M(1)
						inline bool sePuedeIncrementar() const { return (this->incremento > 0); }
						// Funcion: Incrementa el tamaño del array segun el incremento
						// Extra: Se recomienda usar solo cuando incremento > 0, sino solo es malgasto de tiempo
						// Version: Beta
						// Complejidad temporal y espacial: O(n) y M(n)
						inline void resize(const size_t& numItems)
						{
							if (this->incremento > 0)
							{
								size_t sizetemp = this->size; // Backup por si fallos
								// Incrementamos mientras tengamos menos espacio en el vector
								while (this->count + numItems > this->size)
									this->size += this->incremento;
								// Realojamos el vector
								T* temp = (T*)MEM->resize(this->bloque, this->size, sizeof(T));
								// Guardamos el vector si todo ha ido bien
								if (temp != nullptr)
									this->bloque = temp;
								else
									this->size = sizetemp;
							}
						}
						#pragma endregion
					public:
						#pragma region Funciones Heredadas
						#pragma region Constructores
						// Funcion: Crea un objeto clon de este
						// Version: Beta
						// Retorno: El puntero al clon
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual Interfaces::List<T>* clone() const override { return new Array<T>(*this); }
						// Funcion: Crea un vector de elementos
						// Version: Beta
						// Complejidad temporal y espacial: O(n) y M(n)
						inline virtual bool copy(const Interfaces::List<T>& list) override { return Array::operator=(list); }
						inline Array(const Interfaces::List<T>& list) : Array() { Array::operator=(list); }
						inline virtual bool operator=(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0) resultado = false;
							else
							{
								Array::clearArray(); // Limpiamos la lista completamente
								Array::inicializarArray(list.getCount(), 0); // Reseteamos todo
								Array::newList(); // Generamos la lista de nievo
								Array::add(list); // Añadimos la lista a copiar a esta lista
							}
							return resultado;
						}
						#pragma endregion
						#pragma region Getters
						// Version: Final
						// Retorno: Si la lista incrementa su capacidad maxima por si misma
						// Complejidad temporal y espacial: O(1) y M(1)
						inline virtual bool autoIncrementable() const override { return (this->incremento > 0); }
						// Funcion: Obtiene el objeto solicitado
						// Extra: Hay que pasar un puentero del tipo de objeto apuntando a nullptr
						// Extra2: Si el puntero contiene memoria no liberada, esta se pondra a nullptr pero no se liberara
						// Version: Final/Beta/Alfa/PreAlfa
						// Precondiciones:
						//		posicion < count
						//		object == nullptr
						// Retorno: Si el objeto se ha obtenido
						// Complejidad temporal y espacial mejor: O(1) y M(1)
						inline virtual T* get(const size_t& position) override
						{
							T* resultado = nullptr;
							if (&position != nullptr && position < this->count)
								resultado = &this->bloque[position];
							return resultado;
						}
						// Funcion: Busca el objeto solicitado
						// Extra: No se recomienda buscar una posicion no valida
						// Throws: Exception
						// Version: Final/Beta/Alfa/PreAlfa
						// Precondiciones:
						//		position < count
						// Retorno: Objeto solicitado
						// Complejidad temporal y espacial: O(1) y M(1)
						inline virtual T& operator[] (const size_t& position) const THROW override
						{
							if (position > this->count)
								throw Objetos::Excepcion("position > count: 'Position must be lower than list count'", __FUNCTION__);
							return this->bloque[position];
						}
						///inline virtual T* getVector() override { return this->bloque; }
						#pragma endregion
						#pragma region Funciones de la lista
						// Funcion: Agrega un objeto al final de la lista
						// Extra: Si la lista esta llena lo añade si el incremento es mayor a 0
						// Version: Beta
						// Precondiciones:
						//		object != nullptr
						// Retorno: Si se ha agregado a la lista
						// Complejidad temporal y espacial mejor: O(1) y M(1)
						// Complejidad temporal y espacial peor: O(size) y M(size+incremento)
						inline virtual bool add(const T& object) override
						{
							bool resultado = false;
							if (&object != nullptr)
							{
								if (Array::sePuedeAñadir(1))
								{
									this->bloque[this->count] = object;
									this->count++;
									resultado = true;
								}
								else if (Array::sePuedeIncrementar())
								{
									Array::resize(1);
									resultado = Array::add(object);
								}
							}
							return resultado;
						}
						// Funcion: Agrega una lista de objetos al final de esta lista
						// Extra: Si la lista esta llena los añade si el incremento es mayor a 0
						// Version: PreAlfa
						// Precondiciones:
						//		list != nullptr
						// Retorno: Si se ha agregado todos los objetos
						// Complejidad temporal y espacial mejor: O(n) y M(n)
						// Complejidad temporal y espacial peor: O(size + list.getCount()) y M(size+incremento+list.getCount())
						inline virtual bool add(const Interfaces::List<T>& list) override
						{
							bool resultado = true;
							if (&list != nullptr)
							{
								if (Array::sePuedeAñadir(list.getCount()))
								{
									for (size_t i = 0; i < list.getCount() && resultado; i++)
										resultado = Array::add(list[i]);
								}
								else if (Array::sePuedeIncrementar())
								{
									for (size_t i = 0; i < list.getCount() && resultado; i++)
										resultado = Array::add(list[i]);
								}
								else resultado = false;
							}
							else resultado = false;
							return resultado;
						}
						// Funcion: Redirige a la funcion add()
						inline virtual bool operator+=(const T& object) { return Array::add(object); }
						// Funcion: Redirige a la funcion add()
						inline virtual bool operator+=(const Interfaces::List<T>& list) { return Array::add(list); }
						// Funcion: Inserta un elemento en la lista
						// Version: Beta
						// Precondiciones:
						//		&object != nullptr
						//		position < this->count
						// Retorno: Si lo ha insertado
						// Complejidad temporal y espacial mejor: O(this->count - position) y M(1)
						// Complejidad temporal y espacial peor: O(this->count - position) y M(n)
						inline virtual bool insert(const T& object, const size_t& position) override
						{
							bool resultado = false;
							if (&position != nullptr && position < this->count && &object != nullptr)
							{
								if (Array::sePuedeAñadir(1))
								{
									MEM->memMove(this->bloque, position, this->count, sizeof(T), 1, true);
									this->bloque[position] = object;
									this->count++;
									resultado = true;
								}
								else if (Array::sePuedeIncrementar())
								{
									Array::resize(1);
									resultado = Array::insert(object, position);
								}
							}
							return resultado;
						}
						// Funcion: Elimina un elemento de la lista
						// Version: Beta
						// Precondiciones:
						//		position < this->count
						// Retorno: Si ha eliminado el objeto
						// Complejidad temporal y espacial: O(this->count - position) y M(1)
						inline virtual bool remove(const size_t& position) override
						{
							bool resultado = false;
							if (&position != nullptr && position < this->count)
							{
								MEM->memMove(this->bloque, position, this->count, sizeof(T), 1, false);
								this->count--;
								resultado = true;
							}
							return resultado;
						}
						// Funcion: Limpia la lista
						// Extra: La deja preparada para poder volver a usarla
						// Version: Beta
						// Complejidad temporal y espacial: O(n) y M(1)
						inline virtual void clear() override { Array::clearArray(); }
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
									resultado = (Array::operator[](i) == object);
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
							if (&object != nullptr)
							{
								if (Compare != nullptr)
								{
									for (size_t i = 0; i < this->count && !resultado; i++)
										resultado = Compare(&Array::operator[](i), &object);
								}
								else resultado = Array::contains(object);
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
										resultado = (Array::operator[](i) == list[i]);
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
										resultado = Compare(&Array::operator[](i), &list[i]);
								else resultado = false;
							}
							else resultado = Array::equals(list);
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
										resultado = Array::contains(list[i]);
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
										resultado = Array::contains(list[i], Compare);
								else resultado = false;
							}
							else resultado = Array::similar(list);
							return resultado;
						}
						// Funcion: Redirige a la funcion equals()
						inline virtual bool operator==(const Interfaces::List<T>& list) const { return Array::equals(list); }
						// Funcion: Redirige a la funcion equals()
						inline virtual bool operator!=(const Interfaces::List<T>& list) const { return !Array::equals(list); }
						#pragma endregion
						#pragma endregion
						#pragma region Funciones No Heredadas
						#pragma region Constructores
						/// Inicializar en blanco
						inline Array(const size_t& size, const size_t& incremento)
						{
							Array::inicializarArray(size, incremento); // Seteamos el tamaño e iniciamos todo
							Array::newList(); // Hacemos que se genere la lista vacia
						}
						inline Array(const size_t& size) : Array((size_t)size, (size_t)0) {}
						inline Array() : Array((size_t)300, (size_t)0) {}

						// Funcion: Crea un vector de elementos
						// Version: Beta
						// Complejidad temporal y espacial: O(1) y M(300)
						// Funcion: Crea un vector de elementos
						// Version: Beta
						// Complejidad temporal y espacial: O(1) y M(n)
						inline Array(const Array<T>& list) : Array() { Array::operator=(list); }
						inline bool operator=(const Array<T>& list)
						{
							bool resultado = true;
							if (&list == nullptr) resultado = false;
							else if (list.getCount() == 0)
							{
								Array::clearArray(); // Limpiamos la lista completamente
								Array::inicializarArray(list.size, list.incremento); // Reseteamos todo
								Array::newList(); // Generamos la lista de nuevo
							}
							else
							{
								Array::clearArray(); // Limpiamos la lista completamente
								Array::inicializarArray(list.size, list.incremento); // Reseteamos todo
								Array::newList(); // Generamos la lista de nuevo
								Array::add(list); // Añadimos la lista a copiar a esta lista
							}
							return resultado;
						}
						inline ~Array() { Array::clearArray(); }
						#pragma endregion
						#pragma region Getters
						inline size_t getSize() const { return this->size; }
						#pragma endregion
						#pragma region Funciones de la lista
						inline size_t add(const T* vector, const size_t& vectorSize)
						{
							size_t resultado = 0;
							if (vector != nullptr)
							{
								if (Array::sePuedeAñadir(vectorSize))
								{
									MEM->copiarMemoria(&this->bloque[this->count], vector, 0, vectorSize, sizeof(T));
									this->count += vectorSize;
									resultado = vectorSize;
								}
								else
								{
									size_t num = Array::cuantosSePuedenAñadir(vectorSize);
									if (num > 0)
										resultado = Array::add(vector, num);
								}
							}
							return resultado;
						}
						inline size_t add(const Array<T>& list)
						{
							size_t resultado = 0;
							if (&list != nullptr)
								resultado = Array::add(list.bloque, list.count);
							return resultado;
						}
						#pragma endregion
						#pragma endregion
				};
			}
		}
	}
}
#endif // !ARRAY_LIST_TEMPLATE_HPP_
