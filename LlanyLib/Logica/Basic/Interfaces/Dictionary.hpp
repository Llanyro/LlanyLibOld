#pragma once
#ifndef DICTIONARY_INTERFACE_HPP_
#define DICTIONARY_INTERFACE_HPP_

#include "../Objetos/Excepcion.hpp"
#include "Listas.hpp"

namespace LlanyLib
{
	namespace Basic
	{
		namespace Interfaces
	{
		template<class T1, class T2>
		class Dictionary : public Listas
		{
			protected:
				inline Dictionary() {}
			public:
				/// Contructores
				inline virtual bool copy(const Dictionary<T1, T2>& dict) { return false; }
				inline virtual ~Dictionary() {}
				inline virtual bool operator=(const Dictionary<T1, T2>& dict) { return false; }
				inline virtual Dictionary<T1, T2>* clone() const { return nullptr; }

				/// Getters
				inline virtual bool autoIncrementable() const override { return true; }
				inline virtual T2* get(const T1& key) { return nullptr; }
				inline virtual T2& operator[] (const T1& key) const THROW
				{
					throw Objetos::Excepcion("Dictionary is an interface!", __FUNCTION__);
					T2* temp = nullptr;
					return *temp;
				}

				/// Funciones de los diccionarios
				inline virtual bool add(const T1& key, const T2& value) { return false; }
				inline virtual bool add(const Dictionary<T1, T2>& dict) { return false; }
				inline virtual bool operator+=(const Dictionary<T1, T2>& dict) { return Dictionary::add(dict); }
				inline virtual bool remove(const T1& key) { return false; }

				/// Busquedas
				inline virtual bool contains(const T1& key, const T2& value) const { return false; }
				inline virtual bool containsKey(const T1& key) const { return false; }
				inline virtual bool containsValue(const T2& value) const { return false; }
				inline virtual bool contains(const T1& key, const T2& value,
					bool CompareKey(const void* item_a, const void* item_b),
					bool CompareValue(const void* item_a, const void* item_b)) const { return false; }
				//inline virtual bool containsKey(const T1& key, bool CompareKey(const void* item_a, const void* item_b)) const { return false; }
				//inline virtual bool containsKey(const T2& value, bool CompareValue(const void* item_a, const void* item_b)) const { return false; }
				
				/// Comparaciones
				inline virtual bool equals(const Dictionary<T1, T2>& dict) const { return false; }
				inline virtual bool equals(const Dictionary<T1, T2>& dict,
					bool CompareKey(const void* item_a, const void* item_b),
					bool CompareValue(const void* item_a, const void* item_b)) const { return false; }
				inline virtual bool similar(const Dictionary<T1, T2>& dict) const { return false; }
				inline virtual bool similar(const Dictionary<T1, T2>& dict,
					bool CompareKey(const void* item_a, const void* item_b),
					bool CompareValue(const void* item_a, const void* item_b)) const { return false; }
				inline virtual bool operator==(const Dictionary<T1, T2>& dict) const { return false; }
				inline virtual bool operator!=(const Dictionary<T1, T2>& dict) const { return false; }
		};
	}
	}
}
#endif // !DICTIONARY_INTERFACE_HPP_
