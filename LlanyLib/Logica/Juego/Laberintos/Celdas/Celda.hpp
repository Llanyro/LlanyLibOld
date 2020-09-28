#pragma once
#ifndef CELDA_INTERFACE_LABERINTOS_HPP_
#define CELDA_INTERFACE_LABERINTOS_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template <class T>
				class LinkedList;
				template<class T>
				class Array;
			}
		}
	}
	namespace Laberintos {
		namespace Objetos {
			class Celda
			{
				protected:
					Basic::Templates::Listas::Array<bool>* posiciones;
					Basic::Templates::Listas::LinkedList<Celda*>* grupo;
				public:
					#pragma region Constructores
					Celda();
					Celda(const size_t& numPos);				
					Celda(const Celda& other);
					bool operator=(const Celda& other);
					~Celda();
					#pragma endregion
					#pragma region Getters
					const Basic::Templates::Listas::LinkedList<Celda*>* getGrupo() const;
					const bool* getValue(const size_t& posicion) const;
					#pragma endregion
					#pragma region Setters
					void setAll(const bool& value) const;
					bool set(const bool& value, const size_t& posicion) const;
					#pragma endregion
					#pragma region Compares
					bool igual(const Celda& other) const;
					//bool similar(const Critico& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Celda& other) const;
					bool operator!=(const Celda& other) const;
					#pragma endregion
					void mergeGrupos(Celda* other);
					bool contiene(Celda* other) const;
					void romperGrupo();
			};
		}
	}
}
#endif // !CELDA_INTERFACE_LABERINTOS_HPP_