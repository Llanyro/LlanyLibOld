#pragma once
#ifndef CELDA2D_CELDAS_OBJECT_HPP_
#define CELDA2D_CELDAS_OBJECT_HPP_

#include "Celda.hpp"

namespace LlanyLib {
	namespace Objetos {
		namespace Celdas {
			class Celda2D : Celda
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
#endif // !CELDA2D_CELDAS_OBJECT_HPP_
