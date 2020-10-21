#pragma once
#ifndef STRING_OBJECT_HPP_
#define STRING_OBJECT_HPP_

#include "Excepcion.hpp"
#include "../Interfaces/Listas.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Enum { enum class ModificadorString; }
		namespace Templates {
			namespace Listas {
				template<class T>
				class Buffer;
				template<class T>
				class LinkedList;
			}
			namespace Simple {
				template<class T>
				class SmartPointer;
			}
		}
		namespace Objetos {
			class String : public Interfaces::Listas
			{
				protected:
					char* vector;
				protected:
					void inicializarString(const size_t& size);
					void inicializarString(const char& caracter);
					void inicializarString(const char* str);
					void inicializarString(const char* str, const size_t& size);
					void inicializarStringObj(const String& str);
					void inicializarStringObj(const Templates::Listas::Buffer<char>& str);
				public:
					#pragma region Constructores
					String();
					String(const size_t& size);
					String(const char& caracter);
					String(char const* const str);
					String(const char* block, const size_t& size);
					String(const String& other);
					String(const Templates::Listas::Buffer<char>& str);
					bool operator=(const char& caracter);
					bool operator=(char const* const str);
					bool operator=(const String& other);
					bool operator=(const Templates::Listas::Buffer<char>& str);
					~String();
					#pragma endregion
					#pragma region Operators con strigs
					String* operator+(const char& caracter);
					String* operator+(char const* const str);
					String* operator+(const String& other);
					//bool operator+=(const char& caracter);
					//bool operator+=(char const* const str);
					//bool operator+=(const String& other);
					#pragma endregion
					#pragma region Compares
					bool similar(const char& caracter) const;
					bool similar(char const* const str) const;
					bool similar(const char* str, const size_t& size);
					bool similar(const String* other);
					int compare(const char& caracter) const;
					int compare(char const* const str) const;
					int compare(const String& other) const;
					bool equals(const char& caracter) const;
					bool equals(char const* const str) const;
					bool equals(const String& other) const;
					bool operator==(const char& caracter) const;
					bool operator==(char const* const str) const;
					bool operator==(const String& other) const;
					bool operator!=(const char& caracter) const;
					bool operator!=(char const* const str) const;
					bool operator!=(const String& other) const;
					#pragma endregion
					#pragma region SubStrings
					String* substring(const size_t& inicio, const size_t& end) const;
					String* substring(const char& inicio, const char& end) const;
					String* stringCensurado() const;
					String* subStringCensurado(const size_t& inicio, const size_t& end) const;
					String* buscarYBorrar(const char& caracter) const;
					String* buscarYBorrarAll(const char& caracter) const;
					Templates::Listas::LinkedList<String*>* split(const char& separador) const;
					Templates::Listas::LinkedList<String*>* split(char const* const separador) const;
					Templates::Listas::LinkedList<String*>* split(Templates::Listas::LinkedList<char>* list) const;
					Templates::Listas::LinkedList<String*>* splitClear(Templates::Listas::LinkedList<char>* list) const;
					String* splitGetFirst(const char& separador) const;
					String* splitGetFirst(Templates::Listas::LinkedList<char>* list) const;
					String* splitClearGetFirst(Templates::Listas::LinkedList<char>* list) const;
					#pragma endregion
					#pragma region Buscadores
					bool containsChar(const char& caracter) const;
					bool containsStr(char const* const str) const;
					bool containsStr(const char* str, const size_t& size) const;
					bool containsStr(const String& other) const;
					size_t containsCharValue(const char& caracter) const;
					size_t containsStrValue(char const* const str) const;
					size_t containsStrValue(const char* str, const size_t& size) const;
					size_t containsStrValue(const String& other) const;
					//bool startWith(const char& caracter) const;
					//bool startWith(char const* const str) const;
					//bool startWith(const char* str, const size_t& size) const;
					bool startWith(const char& caracter) const;
					bool startWith(char const* const str) const;
					bool startWith(const char* str, const size_t& size) const;
					bool startWith(const String& other) const;
					bool startWithSimilar(const char& caracter) const;
					bool startWithSimilar(char const* const str) const;
					bool startWithSimilar(const char* str, const size_t& size) const;
					bool startWithSimilar(const String& other) const;
					#pragma endregion
					#pragma region Modificadores
					void reverse();
					String* getModifiedString(const Enum::ModificadorString& modif) const;
					size_t modifyString(const Enum::ModificadorString& modif);
					inline void clear() override;
					#pragma endregion
					#pragma region Conversiones
					bool toBool() const;
					short toShort() const;
					unsigned short toUnsignedShort() const;
					int toInt() const;
					unsigned int toUnsignedInt() const;
					float toFloat() const;
					double toDouble() const;
					long toLong() const;
					unsigned long toUnsignedLong() const;
					long long toLongLong() const;
					unsigned long long toUnsignedLongLong() const;
					size_t toSize_T() const;
					#pragma endregion
					#pragma region Otros operators
					char& operator[](const size_t& position) const THROW;
					const char* operator()() const;
					char* get() const;
					#pragma endregion
			};
		}
	}
}
#endif // !STRING_OBJECT_HPP_
