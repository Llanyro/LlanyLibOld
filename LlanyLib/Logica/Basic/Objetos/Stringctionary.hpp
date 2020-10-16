#pragma once
#ifndef STRINGICTIONARY_OBJECT_BASIC_HPP_
#define STRINGICTIONARY_OBJECT_BASIC_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Diccionarios {
				template<class T1, class T2>
				class DictionaryLinkedList;
			}
		}
		namespace Objetos {
			class String;
			class Stringictionary
			{
				protected:
					Templates::Diccionarios::DictionaryLinkedList<String*, String*>* dict;
				public:
					Stringictionary();
					~Stringictionary();
					#pragma region Funciones del diccionario
					bool add(char const* const key, char const* const value);
					bool add(String* key, char const* const value);
					bool add(char const* const key, String* value);
					bool add(String* key, String* value);
					bool remove(char const* const key);
					bool remove(String* key);
					bool removeSimilar(char const* const key);
					bool removeSimilar(String* key);
					bool remove(const size_t& pos);
					void clear();
					#pragma endregion
					#pragma region Getters
					Templates::Diccionarios::DictionaryLinkedList<String*, String*>* getDict() const;
					size_t getNumElements() const;
					String* getValue(char const* const key);
					String* getValue(const String* key);
					String* getValueSimilar(char const* const key);
					String* getValueSimilar(const String* key);
					String* getKey(const size_t& pos);
					String* getValue(const size_t& pos);
					String* getKeyLow(const size_t& pos) const;
					String* getValueLow(const size_t& pos) const;

					size_t getKeyPos(char const* const key);
					size_t getKeyPos(const String* key);
					size_t getValuePos(char const* const key);
					size_t getValuePos(const String* key);
					size_t getKeySimilarPos(char const* const key);
					size_t getKeySimilarPos(const String* key);
					size_t getValueSimilarPos(char const* const key);
					size_t getValueSimilarPos(const String* key);
					#pragma endregion
					#pragma region Busquedas
					bool containsKey(const String* key) const;
					bool containsKey(char const* const key) const;
					bool containsValue(const String* key) const;
					bool containsValue(char const* const key) const;
					bool contains(const String* key, const String* value) const;
					bool contains(char const* const key, const String* value) const;
					bool contains(const String* key, char const* const value) const;
					bool contains(char const* const key, char const* const value) const;

					bool containsKeySimilar(const String* key) const;
					bool containsKeySimilar(char const* const key) const;
					bool containsValueSimilar(const String* key) const;
					bool containsValueSimilar(char const* const key) const;
					bool containsSimilar(const String* key, const String* value) const;
					bool containsSimilar(char const* const key, const String* value) const;
					bool containsSimilar(const String* key, char const* const value) const;
					bool containsSimilar(char const* const key, char const* const value) const;
					#pragma endregion
			};
		}
	}
}
#endif // !STRINGICTIONARY_OBJECT_BASIC_HPP_
