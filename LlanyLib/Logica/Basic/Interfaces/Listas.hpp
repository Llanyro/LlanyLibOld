#pragma once
#ifndef LISTAS_SIZE_INTERFACE_HPP_
#define LISTAS_SIZE_INTERFACE_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Interfaces {
			class Listas
			{
				protected:
					size_t count;
				protected:
					inline Listas() { this->count = 0; }
				public:
					inline virtual ~Listas() { this->count = 0; }
					// Retorno: Numero de objetos en la lista
					// Complejidad temporal y espacial: O(1) y M(1)
					inline size_t getCount() const { return this->count; }
					inline size_t length() const { return this->count; }
					inline size_t size() const { return this->count; }
					// Funcion: Limpia la lista
					// Complejidad temporal y espacial: O(?) y M(?)
					inline virtual void clear() {}
					// Retorno: Si la lista incrementa su capacidad maxima por si misma
					// Complejidad temporal y espacial: O(1) y M(1)
					inline virtual bool autoIncrementable() const { return false; }
			};
		}
	}
}
#endif // !LIST_INTERFACE_HPP_
