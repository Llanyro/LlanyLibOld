#include "Vector2.hpp"

#include <cassert>

/// Constructores
LlanyLib::Math::Objetos::Vector2::Vector2()
{
	this->x = 0.0;
	this->y = 0.0;
}
LlanyLib::Math::Objetos::Vector2::Vector2(const double& x, const double& y)
{
	Vector2::setX(x);
	Vector2::setY(y);
}
LlanyLib::Math::Objetos::Vector2::Vector2(const Vector2& vector2) : Vector2(vector2.x, vector2.y){}
LlanyLib::Math::Objetos::Vector2::~Vector2() {}

/// Getters
double LlanyLib::Math::Objetos::Vector2::getX() const { return this->x; }
double LlanyLib::Math::Objetos::Vector2::getY() const { return this->y; }

/// Setters
void LlanyLib::Math::Objetos::Vector2::setX(const double& x)
{
	assert(&x != nullptr);
	this->x = x;
}
void LlanyLib::Math::Objetos::Vector2::setY(const double& y)
{
	assert(&y != nullptr);
	this->y = y;
}

/// Addetters
void LlanyLib::Math::Objetos::Vector2::addX(const double& x)
{
	assert(&x != nullptr);
	this->x += x;
}
void LlanyLib::Math::Objetos::Vector2::addY(const double& y)
{
	assert(&y != nullptr);
	this->y += y;
}
