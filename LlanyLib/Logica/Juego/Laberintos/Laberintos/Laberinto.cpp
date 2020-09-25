#include "Laberinto.hpp"

#include "../Celdas/Celda2D.hpp"

#pragma region Constructores
LlanyLib::Objetos::Laberintos::Laberinto2D::Laberinto2D()
{
	this->laberinto = nullptr;
	this->x = 0;
	this->y = 0;
	//this->diff = 0;
}
LlanyLib::Objetos::Laberintos::Laberinto2D::Laberinto2D(const Laberinto2D& other)
{

}
bool LlanyLib::Objetos::Laberintos::Laberinto2D::operator=(const Laberinto2D& other)
{
	return false;
}
LlanyLib::Objetos::Laberintos::Laberinto2D::~Laberinto2D()
{
}
#pragma endregion
#pragma region Getters
size_t LlanyLib::Objetos::Laberintos::Laberinto2D::getX() const
{
	return this->x;
}
size_t LlanyLib::Objetos::Laberintos::Laberinto2D::getY() const
{
	return this->y;
}
LlanyLib::Objetos::Celdas::Celda2D* LlanyLib::Objetos::Laberintos::Laberinto2D::getCelda(const size_t& x, const size_t& y) const
{
	Celdas::Celda2D* celda = nullptr;
	if (x < this->x && y < this->y)
		celda = &this->laberinto[y][x];
	return celda;
}
LlanyLib::Objetos::Celdas::Celda2D** LlanyLib::Objetos::Laberintos::Laberinto2D::getCeldas() const
{
	return nullptr;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Objetos::Laberintos::Laberinto2D::setCeldas(Celdas::Celda2D** celdas, const size_t& x, const size_t& y, const size_t& diff)
{

}
#pragma endregion
#pragma region Compares
bool LlanyLib::Objetos::Laberintos::Laberinto2D::igual(const Laberinto2D& other) const
{
	return false;
}
bool LlanyLib::Objetos::Laberintos::Laberinto2D::operator==(const Laberinto2D& other) const
{
	return false;
}
#pragma endregion
bool LlanyLib::Objetos::Laberintos::Laberinto2D::operator!=(const Laberinto2D& other) const
{
	return false;
}
