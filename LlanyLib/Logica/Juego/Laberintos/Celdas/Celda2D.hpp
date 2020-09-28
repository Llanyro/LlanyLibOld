#pragma once
#ifndef CELDA2D_OBJECT_LABERINTOS_HPP_
#define CELDA2D_OBJECT_LABERINTOS_HPP_

#include "Celda.hpp"

namespace LlanyLib {
	namespace Laberintos {
		namespace Objetos {
			class Celda2D : public Celda
			{
				public:
					Celda2D();
					~Celda2D();

					bool getArriba() const;
					bool getAbajo() const;
					bool getIzquierda() const;
					bool getDerecha() const;
					bool getVisitada() const;

					void setArriba(const bool& arriba);
					void setAbajo(const bool& abajo);
					void setIzquierda(const bool& izquierda);
					void setDerecha(const bool& derecha);
					void setVisitada(const bool& visitada);

					void setAllFalse();
					void setAllTrue();
			};
		}
	}
}
#endif // !CELDA2D_OBJECT_LABERINTOS_HPP_
