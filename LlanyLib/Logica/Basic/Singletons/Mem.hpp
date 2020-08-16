#pragma once
#ifndef MEM_SINGLETON_HPP_
#define MEM_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define MEM LlanyLib::Basic::Singletons::Mem::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Singletons {
			class Mem : public Templates::Singleton<Mem>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<Mem>;
					Mem();
					~Mem();
				#pragma endregion
				public:
					#pragma region Classic
					#pragma region Punteros
					// Realiza un calculo para devolver el puntero a la direccion de memoria deseada dentro de un bloque de memoria
					// Es muy util cuando se usa algoritmos de void*
					// Version: Beta
					// Precondiciones:
					//		memBlock != nullptr
					//		posicion >= 0, sizeType > 0
					// Retorno: La direccion de memoria deseada
					// Complejidad temporal y espacial: O(1) y M(1)
					void* autoPointer(
						// Bloque de memoria donde se quiere realizar el AutoPointer
						const void* memBlock,
						// Posicion del bloque de emmoria a la que queremos castear
						const size_t& posicion,
						// Bytes del tipo de cada elemento
						const size_t& sizeType) const;
					// DESCONOZCO SI FUNCIONA BIEN O COMPLETAMENTE BIEN (NO DEBUGEADO)
					// Realiza un calculo para devolver el puntero a la direccion de memoria deseada dentro de un bloque de memoria
					// Es muy util cuando se usa algoritmos de void**
					// Importante: Recuerda que solo funciona para bloques de memoria que contienen subBloques de memoria que poseen el mismo tamaño entre ellos
					//		Por lo que no funcionara con un bloque que posea 2 subbloques de 10 y 11 de tamaño respectivamente
					// Los parametros: posicionX -> al desacer el primer puntero, posicionY -> al desacer el segundo puntero
					// Precondiciones:
					//		memBlock != nullptr
					//		posicionX >= 0, posicionY >= 0, sizeType > 0
					// Retorno: La direccion de memoria deseada
					// Complejidad temporal y espacial: O(1) y M(1)
					void* autoPointer(
						// Bloque de memoria donde se quiere realizar el AutoPointer
						const void* memBlock,
						// SubBloque de memoria al que queremos acceder (Primer AutoPointer)
						const size_t& posicionX,
						// Dato del SubBloque de memoria al que queremos acceder (Segundo AutoPointer)
						const size_t& posicionY,
						// Bytes del tipo de cada elemento
						const size_t& sizeType,
						// Bytes del tipo de subBloque
						const size_t& sizeSubBlockType,
						// Tamaño de los subbloques contenidos en el bloque
						const size_t& sizeSubBlock) const;
					#pragma endregion
					#pragma region Control de memoria
					// Reserva tanta memoria como pedimos usando "malloc"
					// Retorno: Un puntero al inicio del bloque de datos(void*)
					// Precondicion:
					//		bytes > 0
					// Extra: Si falla "malloc" devuelve null
					// Complejidad temporal y espacial: O(1) y M(n)
					void* reservarMem(
						// Numero de bytes a reservar
						const size_t& bytes) const;
					// Copia tanta memoria de un bloque o item de datos a un void*
					// Retorno: La memoria copiada
					// Precondiciones:
					//		inicio >= 0, fin >= 0, sizeType > 0
					//		source != nullptr && dest != nullptr
					//		inicio < fin
					// Complejidad temporal y espacial: O(n) y M(1)
					void* copiarMemoria(
						// Destino donde se va ha copiar la memoria
						void* dest,
						// Bloque de memoria que se va a copiar
						const void* memBlock,
						// Posicion inicial del comienzo de la copia(Posicion incluida)
						const size_t& inicio,
						// Posicion final de la copia
						const size_t& fin,
						// Tamaño en bytes del tipo de la memoria
						const size_t& sizeType) const;
					// Copia tanta memoria de un bloque o item de datos a un void*
					// Retorno: La memoria creada y copiada
					// Precondiciones:
					//		inicio >= 0, fin >= 0, sizeType > 0
					//		source != nullptr
					//		inicio < fin
					// Complejidad temporal y espacial: O(n) y M(n) (En bytes)
					void* reservarYCopiar(
						// Bloque de memoria a copiar
						const void* memBlock,
						// Posicion inicial del comienzo de la copia(Posicion incluida)
						const size_t& inicio,
						// Posicion final de la copia
						const size_t& fin,
						// Tamaño en bytes del tipo de la memoria
						const size_t& sizeType) const;
					// Realoca el bloque de memoria a otro lugar con otro tamaño
					// Precondiciones: 
					//		sizeBlock > 0
					//		sizeType > 0
					// Complejidad temporal y espacial: O(n) y M(n)
					void* resize(
						// Bloque a realocar(realloc)
						void* memBlock,
						// Tamaño del bloque
						const size_t& sizeBlock,
						// Tamaño en bytes del tipo de la memoria
						const size_t& sizeType) const;
					// Libera la memoria ocupada
					// Usa la funcion free()
					// Precondiciones: 
					//		pointerToMemBlock != nullptr
					// Complejidad temporal y espacial: O(1) y M(1)
					void liberar(
						// Direccion de memoria del objeto que apunta a la memoria a liberar
						void** pointerToMemBlock) const;
					// DESCONOZCO SI FUNCIONA BIEN O COMPLETAMENTE BIEN (NO DEBUGEADO) (Usa la Liberar)
					// Cambia los datos de dos bloques de memoria usando un espacio de memoria auxiliar
					// Precondiciones:
					//		memBlock_a != nullptr && memBlock_b != nullptr
					//		sizeBlock > 0 && sizeType > 0
					// Complejidad temporal y espacial: O(1) y M(n)
					void swap(
						// Item o bloque 1
						void* memBlock_a,
						// Item o bloque 2
						void* memBlock_b,
						// Tamaño del bloque de memoria (Numero de items)
						const size_t& sizeBlock,
						// Bytes del tipo de cada elemento
						const size_t& sizeType) const;
					#pragma endregion
					#pragma region Busquedas
					// Busca item dentro de un bloque de memoria
					// Empieza a buscar desde: inicio hasta final
					// Precondiciones:
					//		memBlock != nullptr, item != nullptr
					//		posInicial < posFinal, sizeType > 0
					// Retorno: Si ha encontrado el elemento (True)
					// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
					bool buscarObjeto(
						// Bloque de datos a analizar
						const void* memBlock,
						// Posicion inicial al analizar (Incluida)
						const size_t& inicio,
						// Posicion final a analizar
						const size_t& fin,
						// Tamaño en bytes del tipo a analizar
						const size_t& sizeType,
						// Item a comparar
						const void* item,
						// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
						int Compare(const void* item_a,const void* item_b)) const;
					// Busca item dentro de un bloque de memoria
					// Empieza a buscar desde: final hasta inicio
					// Precondiciones:
					//		memBlock != nullptr, item != nullptr
					//		posInicial < posFinal, sizeType > 0
					// Retorno: Si ha encontrado el elemento (True)
					// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
					bool buscarObjetoInvertido(
						// Bloque de datos a analizar
						const void* memBlock,
						// Posicion inicial al analizar (Incluida)
						const size_t& inicio,
						// Posicion final a analizar
						const size_t& fin,
						// Tamaño en bytes del tipo a analizar
						const size_t& sizeType,
						// Item a comparar
						const void* item,
						// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
						int Compare(const void* item_a, const void* item_b)) const;
					// Busca item dentro de un bloque de memoria (El menor)
					// Empieza a buscar desde: inicio hasta final
					// Precondiciones:
					//		memBlock != nullptr
					//		posInicial < posFinal, sizeType > 0
					// Retorno: Posicion del item menor(Si hay varios devuelve el ultimo)
					// Complejidad temporal y espacial: O(sizeBlock - posInicial) y M(1)
					size_t buscarPosicionObjetoMenor(
						// Bloque de datos a analizar
						const void* memBlock,
						// Posicion inicial al analizar (Incluida)
						const size_t& inicio,
						// Posicion final a analizar
						const size_t& fin,
						// Tamaño en bytes del tipo a analizar
						const size_t& sizeType,
						// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
						int Compare(const void* item_a, const void* item_b)) const;
					// Busca item dentro de un bloque de memoria (El mayor)
					// Empieza a buscar desde: inicio hasta final
					// Precondiciones:
					//		memBlock != nullptr
					//		posInicial < posFinal, sizeType > 0
					// Retorno: Posicion del item mayor(Si hay varios devuelve el ultimo)
					// Complejidad temporal y espacial: O(sizeBlock - posInicial) y M(1)
					size_t buscarPosicionObjetoMayor(
						// Bloque de datos a analizar
						const void* memBlock,
						// Posicion inicial al analizar (Incluida)
						const size_t& inicio,
						// Posicion final a analizar
						const size_t& fin,
						// Tamaño en bytes del tipo a analizar
						const size_t& sizeType,
						// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
						int Compare(const void* item_a, const void* item_b)) const;
					#pragma endregion
					#pragma region Movimientos de memoria
					// Esta funcion es una version de "MemMove" que rellena los huecos vacios despues de mover datos
					// Mueve datos de un bloque de memoria de posicion
					// Usa la funcion "CopiarMemoria" y no "swap" para mover datos
					// El signo de "unidadesDesplazar" selecciona la direccion donde se van a mover los items (+ ->) (- <-)
					// Precondiciones:
					//		memBlock != nullptr, nullValue != nullptr
					//		posInicial >= 0, posFinal >= 0, sizeType > 0
					//		posInicial < posFinal
					//		unidadesDesplazar != 0
					//		sizeType > 0
					// Complejidad temporal y espacial: O(posFinal - posInicial + abs(unidadesDesplazar)) y M(1)
					void memMoveEsp(
						// Bloque de memoria donde se quiere realizar el movimiento
						const void* memBlock,
						// Posicion inicial del comienzo del movimiento(Posicion incluida)
						const size_t& inicio,
						// Posicion final del movimiento
						const size_t& fin,
						// Tamaño en bytes del tipo de la memoria
						const size_t& sizeType,
						// Posiciones a desplazar y que direccion
						const size_t& unidadesDesplazar,
						// Si es en sentido positivo
						const bool& adelante,
						// Objeto null del tipo guardado para rellenar los huecos
						const void* nullValue) const;
					// Mueve datos de un bloque de memoria de posicion
					// Usa la funcion "CopiarMemoria" y no "swap" para mover datos
					// El signo de "unidadesDesplazar" selecciona la direccion donde se van a mover los items
					// Precondiciones:
					//		memBlock != nullptr
					//		posInicial >= 0, posFinal >= 0, sizeType > 0
					//		posInicial < posFinal
					//		unidadesDesplazar != 0
					// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
					void memMove(
						// Bloque de memoria donde se quiere realizar el movimiento
						const void* memBlock,
						// Posicion inicial del comienzo del movimiento(Posicion incluida)
						const size_t& inicio,
						// Posicion final del movimiento
						const size_t& fin,
						// Tamaño en bytes del tipo de la memoria
						const size_t& sizeType,
						// Posiciones a desplazar y que direccion
						const size_t& unidadesDesplazar,
						// Si es en sentido positivo
						const bool& adelante) const;
					// Cambia la posicion de los items de un vector contiguo (0 -> sizeBlock - 1) , (1 -> sizeBlock - 2)... 
					// Usa la funcion "Swap" por lo que, salirse de memoria dara error
					// Precondiciones:
					//		memBlock != nullptr
					//		sizeBlock >= 0, sizeType > 0
					// Complejidad temporal y espacial: O(sizeBlock/2) y M(sizeType)
					void invertirBloque(
						// Bloque de memoria donde se quiere realizar el movimiento
						void* memBlock,
						// Tamaño de bloque
						const size_t& sizeBlock,
						// Tamaño del tipo en bytes
						const size_t& sizeType) const;
					#pragma endregion
					#pragma region Memoria compartida
					// Funcion: Genera un puntero a una memoria compartida
					// Extra: Solo funciona en unix
					// Precondiciones:
					//		bytes != 0
					// Retorno: El puntero a la memoria compartida
					// Complejidad temporal y espacial: O(1) y M(1)
					void* reservarMemoriaCompartida(const size_t& bytes) const;
					#pragma endregion
					#pragma region Template
					template<class T>
					T* autoPointer(const T* memBlock, const size_t& posicion) const
					{
						return (T*)Mem::autoPointer(memBlock, posicion, sizeof(T));
					}
					#pragma endregion
			};
		}
	}
}
#endif // !MEM_SINGLETON_HPP_
