#pragma once
#ifndef VECTOR2_HPP_
#define VECTOR2_HPP_

namespace LlanyLib {
	namespace Math {
		namespace Objetos {
			class Vector2
			{
				protected:
					double x;
					double y;
				public:
					/// Constructores
					Vector2();
					Vector2(const double& x, const double& y);
					Vector2(const Vector2& vector2);
					~Vector2();

					/// Getters
					double getX() const;
					double getY() const;

					/// Setters
					void setX(const double& x);
					void setY(const double& y);

					/// Addetters
					void addX(const double& x);
					void addY(const double& y);
			};
		}
	}
}
#endif // !VECTOR2_HPP_
