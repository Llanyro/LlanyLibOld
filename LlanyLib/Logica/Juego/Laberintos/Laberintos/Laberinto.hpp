#pragma once
#ifndef LABERINTO2D_LABERINTOS_OBJECT_HPP_
#define LABERINTO2D_LABERINTOS_OBJECT_HPP_

namespace LlanyLib {
	enum class Dificultad;


	namespace Objetos {
		namespace Celdas {
			class Celda2D;
		}
		namespace Laberintos {
			class Laberinto2D
			{
				protected:
					Celdas::Celda2D** laberinto;
					size_t x;
					size_t y;
					Dificultad diff;
				public:
					#pragma region Constructores
					Laberinto2D();
					Laberinto2D(const Laberinto2D& other);
					bool operator=(const Laberinto2D& other);
					~Laberinto2D();
					#pragma endregion
					#pragma region Getters
					size_t getX() const;
					size_t getY() const;
					Celdas::Celda2D* getCelda(const size_t& x, const size_t& y) const;
					Celdas::Celda2D** getCeldas() const;
					#pragma endregion
					#pragma region Setters
					void setCeldas(Celdas::Celda2D** celdas, const size_t& x, const size_t& y, const size_t& diff);
					#pragma endregion
					#pragma region Compares
					bool igual(const Laberinto2D& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Laberinto2D& other) const;
					bool operator!=(const Laberinto2D& other) const;
					#pragma endregion
					//String toString() const;
			};
		}
	}
}
#endif // !LABERINTO2D_LABERINTOS_OBJECT_HPP_