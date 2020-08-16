#include "Vector3.hpp"
#include "Vector2.hpp"

#include <cassert>

/// Constructores
LlanyLib::Math::Objetos::Vector3::Vector3()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}
LlanyLib::Math::Objetos::Vector3::Vector3(const double& x, const double& y, const double& z)
{
	Vector3::setX(x);
	Vector3::setY(y);
	Vector3::setZ(z);
}
LlanyLib::Math::Objetos::Vector3::Vector3(const Vector3& vector3)
{
	Vector3::setX(vector3.x);
	Vector3::setY(vector3.y);
	Vector3::setZ(vector3.z);
}
LlanyLib::Math::Objetos::Vector3::Vector3(const Objetos::Vector2& vector2)
{
	Vector3::setX(vector2.getX());
	Vector3::setY(vector2.getY());
}
LlanyLib::Math::Objetos::Vector3::~Vector3(){}

/// Getters
double LlanyLib::Math::Objetos::Vector3::getX() const { return this->x; }
double LlanyLib::Math::Objetos::Vector3::getY() const { return this->y; }
double LlanyLib::Math::Objetos::Vector3::getZ() const { return this->z; }

/// Setters
void LlanyLib::Math::Objetos::Vector3::setX(const double& x)
{
	assert(&x != nullptr);
	this->x = x;
}
void LlanyLib::Math::Objetos::Vector3::setY(const double& y)
{
	assert(&y != nullptr);
	this->y = y;
}
void LlanyLib::Math::Objetos::Vector3::setZ(const double& z)
{
	assert(&z != nullptr);
	this->z = z;
}


/// Addetters
void LlanyLib::Math::Objetos::Vector3::addX(const double& x)
{
	assert(&x != nullptr);
	this->x += x;
}
void LlanyLib::Math::Objetos::Vector3::addY(const double& y)
{
	assert(&y != nullptr);
	this->y += y;
}
void LlanyLib::Math::Objetos::Vector3::addZ(const double& z)
{
	assert(&z != nullptr);
	this->z += z;
}
