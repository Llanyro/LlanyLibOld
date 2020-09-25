#include "Celda2D.hpp"

#include "../../../Basic/Plantillas/Listas/Array.hpp"
#include "../../../Basic/Plantillas/Listas/LinkedList.hpp"

/*
	0 = Arriba		| Y+
	1 = Abajo		| Y-
	2 = Izquierda	| X+
	3 = Derecha		| X-
	4 = Visitada
*/
LlanyLib::Objetos::Celdas::Celda2D::Celda2D() : Celda(5){}
LlanyLib::Objetos::Celdas::Celda2D::~Celda2D(){}

bool LlanyLib::Objetos::Celdas::Celda2D::getArriba() const
{
	return Celda::getValue(0);
}
bool LlanyLib::Objetos::Celdas::Celda2D::getAbajo() const
{
	return Celda::getValue(1);
}
bool LlanyLib::Objetos::Celdas::Celda2D::getIzquierda() const
{
	return Celda::getValue(2);
}
bool LlanyLib::Objetos::Celdas::Celda2D::getDerecha() const
{
	return Celda::getValue(3);
}
bool LlanyLib::Objetos::Celdas::Celda2D::getVisitada() const
{
	return Celda::getValue(4);
}

void LlanyLib::Objetos::Celdas::Celda2D::setArriba(const bool& arriba)
{
	Celda::set(arriba, 0);
}
void LlanyLib::Objetos::Celdas::Celda2D::setAbajo(const bool& abajo)
{
	Celda::set(abajo, 1);
}
void LlanyLib::Objetos::Celdas::Celda2D::setIzquierda(const bool& izquierda)
{
	Celda::set(izquierda, 2);
}
void LlanyLib::Objetos::Celdas::Celda2D::setDerecha(const bool& derecha)
{
	Celda::set(derecha, 3);
}
void LlanyLib::Objetos::Celdas::Celda2D::setVisitada(const bool& visitada)
{
	Celda::set(visitada, 4);
}
void LlanyLib::Objetos::Celdas::Celda2D::setAllFalse()
{
	Celda2D::setArriba(false);
	Celda2D::setAbajo(false);
	Celda2D::setIzquierda(false);
	Celda2D::setDerecha(false);
}
void LlanyLib::Objetos::Celdas::Celda2D::setAllTrue()
{
	Celda2D::setArriba(true);
	Celda2D::setAbajo(true);
	Celda2D::setIzquierda(true);
	Celda2D::setDerecha(true);
}
