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
		}
		namespace Objetos {
			class String;
		}
	}
	namespace LSDB {
		namespace Enum {
			enum class Tipos;
		}
		namespace Objetos {
			class Columna
			{
				protected:
					Enum::Tipos columType;
					Basic::Objetos::String* columName;
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* filas;
				public:
					#pragma region Constructores
					Columna(const Enum::Tipos& tipo, Basic::Objetos::String* columName);
					~Columna();
					#pragma endregion
					#pragma region Getters
					size_t getFilas() const;
					const Basic::Objetos::String* getColumName() const;
					const Basic::Objetos::String* getElement(const size_t& position) const;

					#pragma endregion
					#pragma region Setters

					#pragma endregion
					#pragma region Comparadores

					#pragma endregion
					Basic::Objetos::String* toString() const;
			};
		}
	}
}
#endif // !COLUMNA_OBJECT_LSDB_HPP_
