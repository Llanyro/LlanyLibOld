#pragma once
#ifndef VECTOR3_OBJECT_MATH_HPP_
#define VECTOR3_OBJECT_MATH_HPP_

namespace LlanyLib {
	namespace Math {
		namespace Objetos {
			class Vector2;

			class Vector3
			{
				protected:
					double x;
					double y;
					double z;
				public:
					/// Constructores
					Vector3();
					Vector3(const double& x, const double& y, const double& z);
					Vector3(const Vector3& vector3);
					Vector3(const Vector2& vector2);
					~Vector3();

					/// Getters
					double getX() const;
					double getY() const;
					double getZ() const;

					/// Setters
					void setX(const double& x);
					void setY(const double& y);
					void setZ(const double& z);

					/// Addetters
					void addX(const double& x);
					void addY(const double& y);
					void addZ(const double& z);
			};
		}
	}
}
#endif // !VECTOR3_HPP_
