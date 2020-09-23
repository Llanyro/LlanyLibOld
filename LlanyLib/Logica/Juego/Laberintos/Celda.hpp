#pragma once
#ifndef CELDA_INTERFACE_HPP_
#define CELDA_INTERFACE_HPP_

namespace LlanyLib
{
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template <class T>
				class LinkedList;
			}
		}
	}
	namespace Objetos {
		template<class T>
		class Celda
		{
			protected:
				bool* posiciones;
				Basic::Templates::Listas::LinkedList<T*>* grupo;
			public:
				#pragma region Constructores
				Celda(const size_t& numPos)
				{
					this->posiciones = new bool[numPos];


				}
				Celda(const Celda& other);
				bool operator=(const Celda& other);
				~Celda();
				#pragma endregion
				#pragma region Getters
				bool getArriba() const;
				bool getAbajo() const;
				bool getIzquierda() const;
				bool getDerecha() const;
				bool getVisitada() const;
				const Basic::Templates::Listas::LinkedList<Celda2D*>* getGrupo() const;
				#pragma endregion
				#pragma region Setters
				void setArriba(const bool& arriba);
				void setAbajo(const bool& abajo);
				void setIzquierda(const bool& izquierda);
				void setDerecha(const bool& derecha);
				void setVisitada(const bool& visitada);
				void setAllFalse();
				void setAllTrue();
				#pragma endregion
				#pragma region Compares
				bool igual(const Celda2D& other) const;
				//bool similar(const Critico& other) const;
				#pragma endregion
				#pragma region Operators
				bool operator==(const Celda2D& other) const;
				bool operator!=(const Celda2D& other) const;
				#pragma endregion
				void mergeGrupos(const Celda2D& other);
				bool contiene(const Celda2D* other) const;
				void romperGrupo();
		};
	}
}

#endif // !CELDA_INTERFACE_HPP_
