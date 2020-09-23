#include "Celda2D.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#pragma region Constructores
LlanyLib::Objetos::Celda2D::Celda2D()
{
	this->arriba = false;
	this->abajo = false;
	this->izquierda = false;
	this->derecha = false;
	this->visitada = false;
	this->grupo = new Basic::Templates::Listas::LinkedList<Celda2D*>();
	this->grupo->add(this);
}
LlanyLib::Objetos::Celda2D::Celda2D(const bool& arriba, const bool& abajo, const bool& izquierda, const bool& derecha) : Celda2D()
{
	assert(&arriba != nullptr);
	assert(&abajo != nullptr);
	assert(&izquierda != nullptr);
	assert(&derecha != nullptr);
	this->arriba = arriba;
	this->abajo = abajo;
	this->izquierda = izquierda;
	this->derecha = derecha;
	this->visitada = false;
}
LlanyLib::Objetos::Celda2D::Celda2D(const Celda2D& other) : Celda2D()
{
	assert(&other != nullptr);
	bool temp = Celda2D::operator=(other);
	assert(temp);
}
bool LlanyLib::Objetos::Celda2D::operator=(const Celda2D& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->arriba = other.arriba;
		this->abajo = other.abajo;
		this->izquierda = other.izquierda;
		this->derecha = other.derecha;
		this->visitada = other.visitada;
	}
	return temp;
}
LlanyLib::Objetos::Celda2D::~Celda2D()
{
	if (this->grupo != nullptr)
	{
		if (this->grupo->getCount() > 1)
			Celda2D::romperGrupo();
		delete this->grupo;
	}
	this->grupo = nullptr;
}
#pragma endregion
#pragma region Getters
bool LlanyLib::Objetos::Celda2D::getArriba() const
{
	return this->arriba;
}
bool LlanyLib::Objetos::Celda2D::getAbajo() const
{
	return this->abajo;
}
bool LlanyLib::Objetos::Celda2D::getIzquierda() const
{
	return this->izquierda;
}
bool LlanyLib::Objetos::Celda2D::getDerecha() const
{
	return this->derecha;
}
bool LlanyLib::Objetos::Celda2D::getVisitada() const
{
	return this->visitada;
}
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Objetos::Celda2D*>* LlanyLib::Objetos::Celda2D::getGrupo() const
{
	return this->grupo;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Objetos::Celda2D::setArriba(const bool& arriba)
{
	assert(&arriba != nullptr);
	this->arriba = arriba;
}
void LlanyLib::Objetos::Celda2D::setAbajo(const bool& abajo)
{
	assert(&abajo != nullptr);
	this->abajo = abajo;
}
void LlanyLib::Objetos::Celda2D::setIzquierda(const bool& izquierda)
{
	assert(&izquierda != nullptr);
	this->izquierda = izquierda;
}
void LlanyLib::Objetos::Celda2D::setDerecha(const bool& derecha)
{
	assert(&derecha != nullptr);
	this->derecha = derecha;
}
void LlanyLib::Objetos::Celda2D::setVisitada(const bool& visitada)
{
	assert(&visitada != nullptr);
	this->visitada = visitada;
}
void LlanyLib::Objetos::Celda2D::setAllFalse()
{
	this->arriba = false;
	this->abajo = false;
	this->izquierda = false;
	this->derecha = false;
}
void LlanyLib::Objetos::Celda2D::setAllTrue()
{
	this->arriba = true;
	this->abajo = true;
	this->izquierda = true;
	this->derecha = true;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Objetos::Celda2D::igual(const Celda2D& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
		if (this->arriba == other.arriba)
			if (this->abajo == other.abajo)
				if (this->derecha == other.derecha)
					if (this->izquierda == other.izquierda)
						if (this->visitada == other.visitada)
							temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Objetos::Celda2D::operator==(const Celda2D& other) const
{
	return Celda2D::igual(other);
}
bool LlanyLib::Objetos::Celda2D::operator!=(const Celda2D& other) const
{
	return !Celda2D::igual(other);
}
#pragma endregion
void LlanyLib::Objetos::Celda2D::mergeGrupos(const Celda2D& other)
{
	LlanyLib::Basic::Templates::Listas::LinkedList<Celda2D*>* grupoAMezclar = other.grupo;
	for (size_t i = 0; i < grupoAMezclar->getCount(); i++)
	{
		Celda2D* celda = *grupoAMezclar->get(i);
		celda->grupo = this->grupo;
		this->grupo->add(celda);
	}
	delete grupoAMezclar;
}
bool LlanyLib::Objetos::Celda2D::contiene(const Celda2D* other) const
{
	return this->grupo->contains((Celda2D*)other);
}
void LlanyLib::Objetos::Celda2D::romperGrupo()
{
	size_t pos = 0;
	if (this->grupo->find(this, &pos)) {
		this->grupo->remove(pos);
		this->grupo = new LlanyLib::Basic::Templates::Listas::LinkedList<Celda2D*>();
		this->grupo->add(this);
	}
}
