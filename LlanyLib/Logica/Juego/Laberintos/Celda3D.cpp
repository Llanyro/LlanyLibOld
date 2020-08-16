#include "Celda3D.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#pragma region Constructores
LlanyLib::Objetos::Celda3D::Celda3D()
{
	this->arriba = false;
	this->abajo = false;
	this->izquierda = false;
	this->derecha = false;
	this->delante = false;
	this->atras = false;
	this->visitada = false;
	this->grupo = new LlanyLib::Basic::Templates::Listas::LinkedList<Celda3D*>();
	this->grupo->add(this);
}
LlanyLib::Objetos::Celda3D::Celda3D(const bool& arriba, const bool& abajo, const bool& izquierda, const bool& derecha, const bool& delante, const bool& atras) : Celda3D()
{
	assert(&arriba != nullptr);
	assert(&abajo != nullptr);
	assert(&izquierda != nullptr);
	assert(&derecha != nullptr);
	assert(&delante != nullptr);
	assert(&atras != nullptr);
	this->arriba = arriba;
	this->abajo = abajo;
	this->izquierda = izquierda;
	this->derecha = derecha;
	this->delante = delante;
	this->atras = atras;
	this->visitada = false;
}
LlanyLib::Objetos::Celda3D::Celda3D(const Celda3D& other) : Celda3D()
{
	assert(&other != nullptr);
	bool temp = Celda3D::operator=(other);
	assert(temp);
}
bool LlanyLib::Objetos::Celda3D::operator=(const Celda3D& other)
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
LlanyLib::Objetos::Celda3D::~Celda3D()
{
	if (this->grupo != nullptr)
	{
		if (this->grupo->getCount() > 1)
			Celda3D::romperGrupo();
		delete this->grupo;
	}
	this->grupo = nullptr;
}
#pragma endregion
#pragma region Getters
bool LlanyLib::Objetos::Celda3D::getArriba() const
{
	return this->arriba;
}
bool LlanyLib::Objetos::Celda3D::getAbajo() const
{
	return this->abajo;
}
bool LlanyLib::Objetos::Celda3D::getIzquierda() const
{
	return this->izquierda;
}
bool LlanyLib::Objetos::Celda3D::getDerecha() const
{
	return this->derecha;
}
bool LlanyLib::Objetos::Celda3D::getVisitada() const
{
	return this->visitada;
}
const LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Objetos::Celda3D*>* LlanyLib::Objetos::Celda3D::getGrupo() const
{
	return this->grupo;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Objetos::Celda3D::setArriba(const bool& value)
{
	assert(&value != nullptr);
	this->arriba = value;
}
void LlanyLib::Objetos::Celda3D::setAbajo(const bool& value)
{
	assert(&value != nullptr);
	this->abajo = value;
}
void LlanyLib::Objetos::Celda3D::setIzquierda(const bool& value)
{
	assert(&value != nullptr);
	this->izquierda = value;
}
void LlanyLib::Objetos::Celda3D::setDerecha(const bool& value)
{
	assert(&value != nullptr);
	this->derecha = value;
}
void LlanyLib::Objetos::Celda3D::setVisitada(const bool& value)
{
	assert(&value != nullptr);
	this->visitada = value;
}
void LlanyLib::Objetos::Celda3D::setAllFalse()
{
	this->arriba = false;
	this->abajo = false;
	this->izquierda = false;
	this->derecha = false;
}
void LlanyLib::Objetos::Celda3D::setAllTrue()
{
	this->arriba = true;
	this->abajo = true;
	this->izquierda = true;
	this->derecha = true;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Objetos::Celda3D::igual(const Celda3D& other) const
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
bool LlanyLib::Objetos::Celda3D::operator==(const Celda3D& other) const
{
	return Celda3D::igual(other);
}
bool LlanyLib::Objetos::Celda3D::operator!=(const Celda3D& other) const
{
	return !Celda3D::igual(other);
}
#pragma endregion
void LlanyLib::Objetos::Celda3D::mergeGrupos(const Celda3D& other)
{
	LlanyLib::Basic::Templates::Listas::LinkedList<Celda3D*>* grupoAMezclar = other.grupo;
	for (size_t i = 0; i < grupoAMezclar->getCount(); i++)
	{
		Celda3D* celda = grupoAMezclar->operator[](i);
		celda->grupo = this->grupo;
		this->grupo->add(celda);
	}
	delete grupoAMezclar;
}
bool LlanyLib::Objetos::Celda3D::contiene(const Celda3D* other) const
{
	return this->grupo->contains((Celda3D*)other);
}
void LlanyLib::Objetos::Celda3D::romperGrupo()
{
	size_t pos = 0;
	if (this->grupo->find(this, &pos)) {
		this->grupo->remove(pos);
		this->grupo = new LlanyLib::Basic::Templates::Listas::LinkedList<Celda3D*>();
		this->grupo->add(this);
	}
}
