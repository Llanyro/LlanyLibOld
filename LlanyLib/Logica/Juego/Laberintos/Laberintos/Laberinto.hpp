#pragma once
#ifndef LABERINTO2D_OBJECT_LABERINTOS_HPP_
#define LABERINTO2D_OBJECT_LABERINTOS_HPP_

namespace LlanyLib {
	namespace Laberintos {
		namespace Enum {
			enum class Dificultad;
		}
		namespace Objetos {
			class Celda2D;
			class Laberinto2D
			{
				protected:
					Celda2D** laberinto;
					size_t x;
					size_t y;
					Enum::Dificultad diff;
				public:
					#pragma region Constructores
					Laberinto2D();
					Laberinto2D(const size_t& x, const size_t& y, const Enum::Dificultad& diff);
					Laberinto2D(const size_t& size, const Enum::Dificultad& diff);
					Laberinto2D(const Laberinto2D& other);
					bool operator=(const Laberinto2D& other);
					~Laberinto2D();
					#pragma endregion
					#pragma region Getters
					size_t getX() const;
					size_t getY() const;
					Celda2D* getCelda(const size_t& x, const size_t& y) const;
					Celda2D** getCeldas() const;
					#pragma endregion
					#pragma region Setters
					void setCeldas(Celda2D** celdas, const size_t& x, const size_t& y, const Enum::Dificultad& diff);
					#pragma endregion
					#pragma region Compares
					bool igual(const Laberinto2D& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Laberinto2D& other) const;
					bool operator!=(const Laberinto2D& other) const;
					#pragma endregion
					void clear();
					void setAllFalse() const;
					void setAllTrue() const;
					//String toString() const;
			};
		}
	}
}
#endif // !LABERINTO2D_OBJECT_LABERINTOS_HPP_
