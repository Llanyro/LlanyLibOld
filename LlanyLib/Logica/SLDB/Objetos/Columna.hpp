#pragma once
#ifndef COLUMNA_OBJECT_LSDB_HPP_
#define COLUMNA_OBJECT_LSDB_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
			namespace Diccionarios {
				template<class T1, class T2>
				class DictionaryLinkedList;
			}
		}
		namespace Objetos {
			class String;
		}
	}
	namespace LSDB {
		namespace Enum {
			enum class Tipos;
			enum class Propiedades;
		}
		namespace Objetos {
			class Columna
			{
				protected:
					Enum::Tipos columType;
					Basic::Objetos::String* columName;
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* filas;
					Basic::Templates::Diccionarios::DictionaryLinkedList<
						Enum::Propiedades,
						Basic::Objetos::String*
					>* prop;
				public:
					#pragma region Constructores
					Columna(const Enum::Tipos& tipo, Basic::Objetos::String* columName, const size_t& maxStringSize, const bool& paramNull);
					~Columna();
					#pragma endregion
					#pragma region Getters
					size_t getFilas() const;
					size_t getMaxStringSize() const;
					bool getParamNull() const;
					const Basic::Objetos::String* getColumName() const;
					const Basic::Objetos::String* getElement(const size_t& position) const;
					#pragma endregion
					#pragma region Setters
					void setMaxStringSize(const size_t& maxStringSize);
					void setColumName(Basic::Objetos::String* columName);
					void setParamNull(const bool& paramNull);
					bool setParamNullUpdateAll(const bool& paramNull);
					#pragma endregion
					#pragma region Modify
					bool addElement(Basic::Objetos::String* element) const;
					bool modifyElement(Basic::Objetos::String* element, const size_t& pos) const;
					bool removeElement(const size_t& pos);
					void clearColums();
					#pragma endregion
			};
		}
	}
}
#endif // !COLUMNA_OBJECT_LSDB_HPP_
