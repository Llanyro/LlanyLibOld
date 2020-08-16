#pragma once
#ifndef CELDA_3D_HPP_
#define CELDA_3D_HPP_

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
		class Celda3D
		{
			protected:
				bool arriba;	// Z+
				bool abajo;		// Z-
				bool izquierda;	// Y-
				bool derecha;	// Y+
				bool delante;	// X+
				bool atras;		// X-
				bool visitada;
				Basic::Templates::Listas::LinkedList<Celda3D*>* grupo;
			public:
				#pragma region Constructores
				Celda3D();
				Celda3D(
					const bool& arriba,		// Z+
					const bool& abajo,		// Z-
					const bool& izquierda,	// Y-
					const bool& derecha,	// Y+
					const bool& delante,	// X+
					const bool& atras);		// X-
				Celda3D(const Celda3D& other);
				bool operator=(const Celda3D& other);
				~Celda3D();
				#pragma endregion
				#pragma region Getters
				bool getArriba() const;
				bool getAbajo() const;
				bool getIzquierda() const;
				bool getDerecha() const;
				bool getDelante() const;
				bool getAtras() const;
				bool getVisitada() const;
				const Basic::Templates::Listas::LinkedList<Celda3D*>* getGrupo() const;
				#pragma endregion
				#pragma region Setters
				void setArriba(const bool& value);
				void setAbajo(const bool& value);
				void setIzquierda(const bool& value);
				void setDerecha(const bool& value);
				void setDelante(const bool& value);
				void setAtras(const bool& value);
				void setVisitada(const bool& value);
				void setAllFalse();
				void setAllTrue();
				#pragma endregion
				#pragma region Compares
				bool igual(const Celda3D& other) const;
				//bool similar(const Critico& other) const;
				#pragma endregion
				#pragma region Operators
				bool operator==(const Celda3D& other) const;
				bool operator!=(const Celda3D& other) const;
				#pragma endregion
				void mergeGrupos(const Celda3D& other);
				bool contiene(const Celda3D* other) const;
				void romperGrupo();
		};
	}
}

#endif // !CELDA_2D_HPP_
