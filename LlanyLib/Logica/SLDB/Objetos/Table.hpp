#pragma once
#ifndef TABLE_OBJECT_LSDB_HPP_
#define TABLE_OBJECT_LSDB_HPP_

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
		namespace Objetos {
			class Table
			{
				protected:
					Basic::Templates::Listas::LinkedList<Basic::Objetos::String*>* columnas;
				public:
					#pragma region Constructores
					Table();
					~Table();
					#pragma endregion
					#pragma region Getters
					
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
#endif // !TABLE_OBJECT_LSDB_HPP_
