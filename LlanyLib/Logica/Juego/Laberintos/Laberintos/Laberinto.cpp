#include "Laberinto.hpp"

#include "../Celdas/Celda2D.hpp"
#include "../Enums/Dificultad.hpp"

#pragma region Constructores
LlanyLib::Laberintos::Objetos::Laberinto2D::Laberinto2D()
{
	this->laberinto = nullptr;
	this->x = 0;
	this->y = 0;
	this->diff = Enum::Dificultad::Vacio;
}
LlanyLib::Laberintos::Objetos::Laberinto2D::Laberinto2D(const size_t& x, const size_t& y, const Enum::Dificultad& diff) : Laberinto2D()
{
	this->x = x;
	this->y = y;
	this->laberinto = new Celda2D * [this->y];
	for (size_t i = 0; i < this->y; i++)
		this->laberinto[i] = new Celda2D[this->x];
}
LlanyLib::Laberintos::Objetos::Laberinto2D::Laberinto2D(const size_t& size, const Enum::Dificultad& diff) : Laberinto2D(size, size, diff){}
LlanyLib::Laberintos::Objetos::Laberinto2D::Laberinto2D(const Laberinto2D& other) : Laberinto2D()
{
	if (&other != nullptr)
		Laberinto2D::operator=(other);
}
bool LlanyLib::Laberintos::Objetos::Laberinto2D::operator=(const Laberinto2D& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		Laberinto2D::clear();
		this->x = other.x;
		this->y = other.y;
		this->diff = other.diff;
		this->laberinto = new Celda2D*[this->y];
		for (size_t i = 0; i < this->y; i++)
		{
			this->laberinto[i] = new Celda2D[this->x];
			for (size_t j = 0; j < this->x; j++)
				this->laberinto[i][j].operator=(*other.getCelda(j, i));
		}
	}
	return temp;
}
LlanyLib::Laberintos::Objetos::Laberinto2D::~Laberinto2D()
{
	Laberinto2D::clear();
}
#pragma endregion
#pragma region Getters
size_t LlanyLib::Laberintos::Objetos::Laberinto2D::getX() const
{
	return this->x;
}
size_t LlanyLib::Laberintos::Objetos::Laberinto2D::getY() const
{
	return this->y;
}
LlanyLib::Laberintos::Objetos::Celda2D* LlanyLib::Laberintos::Objetos::Laberinto2D::getCelda(const size_t& x, const size_t& y) const
{
	Celda2D* celda = nullptr;
	if (x < this->x && y < this->y)
		celda = &this->laberinto[y][x];
	return celda;
}
LlanyLib::Laberintos::Objetos::Celda2D** LlanyLib::Laberintos::Objetos::Laberinto2D::getCeldas() const
{
	return this->laberinto;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Laberintos::Objetos::Laberinto2D::setCeldas(Celda2D** celdas, const size_t& x, const size_t& y, const Enum::Dificultad& diff)
{
	Laberinto2D::clear();
	this->laberinto = celdas;
	this->x = x;
	this->y = y;
	this->diff = diff;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Laberintos::Objetos::Laberinto2D::igual(const Laberinto2D& other) const
{
	bool resutlado = true;
	if (this->x == other.x && this->y == other.y)
		for (size_t i = 0; resutlado && i < y; i++)
			for (size_t j = 0; resutlado && j < x; j++)
				resutlado = Laberinto2D::getCelda(j, i)->igual(*other.getCelda(j, i));
	else
		resutlado = false;
	return resutlado;
}
bool LlanyLib::Laberintos::Objetos::Laberinto2D::operator==(const Laberinto2D& other) const
{
	return Laberinto2D::igual(other);
}
bool LlanyLib::Laberintos::Objetos::Laberinto2D::operator!=(const Laberinto2D& other) const
{
	return !Laberinto2D::igual(other);
}
#pragma endregion
void LlanyLib::Laberintos::Objetos::Laberinto2D::clear()
{
	for (size_t i = 0; i < this->y; i++)
		delete[] this->laberinto[i];
	delete[] this->laberinto;
	this->x = 0;
	this->y = 0;
	this->diff = Enum::Dificultad::Vacio;
	this->laberinto = nullptr;
}

void LlanyLib::Laberintos::Objetos::Laberinto2D::setAllFalse() const
{
	for (size_t i = 0; i < y; i++)
		for (size_t j = 0; j < x; j++)
			this->laberinto[i][j].setAllFalse();
}
void LlanyLib::Laberintos::Objetos::Laberinto2D::setAllTrue() const
{
	for (size_t i = 0; i < y; i++)
		for (size_t j = 0; j < x; j++)
			this->laberinto[i][j].setAllTrue();
}
