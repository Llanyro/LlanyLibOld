#pragma once
#ifndef CELDA_2D_HPP_
#define CELDA_2D_HPP_

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
	namespace Objetos
	{
		/*
			Recordatorio:
				True = pared
				False = hueco
		*/
		class Celda2D
		{
			protected:
				bool arriba;	// Y+
				bool abajo;		// Y-
				bool izquierda;	// X-
				bool derecha;	// X+
				bool visitada;
				Basic::Templates::Listas::LinkedList<Celda2D*>* grupo;
			public:
				#pragma region Constructores
				Celda2D();
				Celda2D(
					const bool& arriba,		// Y+
					const bool& abajo,		// Y-
					const bool& izquierda,	// X-
					const bool& derecha);	// X+
				Celda2D(const Celda2D& other);
				bool operator=(const Celda2D& other);
				~Celda2D();
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

#endif // !CELDA_2D_HPP_
