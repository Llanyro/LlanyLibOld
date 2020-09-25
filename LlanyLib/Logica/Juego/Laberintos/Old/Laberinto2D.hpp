#pragma once

#ifdef _WIN32

#elif __unix__
#include <cstddef>
#endif // __linux__


class Celda2D;
class String;

enum class Dificultad
{ 
	KruskalSimple,
	KruskalConSalas,
	DepthFirstSearchSimple,
	DepthFirstSearchConSalas,

	// Ranfom
	RandomFacil,
	RandomMedio,
	RandomDificil,

	// Otros
	SoloMuros,
	Vacio,
	CuboHueco,
};

/*
	Recordatorio:
		True = pared
		False = hueco
*/
class Laberinto2D
{
	protected:
		Celda2D** laberinto;
		size_t x;
		size_t y;
		Dificultad diff;
		#pragma region Private
		#pragma region Generadores y otros
		void generarLaberinto() const;
		void clear();
		#pragma endregion
		#pragma region Metodos de generacion
		#pragma region Kruskal
		void generarPorKruskalSimple() const;
		void generarPorKruskalConSalas() const;
		#pragma endregion
		#pragma region DepthFirstSearch
		void generarPorDFSSimple() const;
		void generarPorDFSConSalas() const;
		#pragma endregion
		#pragma region Random
		void generarRandomFacil() const;
		void generarRandomMedio() const;
		void generarRandomDificil() const;
		#pragma endregion
		#pragma region Otros
		// Deja el laberinto del mismo tamaño pero elimina las paredes
		void eliminarParedes() const;
		// Pone todas las paredes del laberinto disponibles
		void rellenarParedes() const;
		// Pone solo las paredes para que se quede como una sala o cubo
		void generarCuboHueco() const;
		#pragma endregion
		#pragma endregion
		#pragma endregion
	public:
		#pragma region Constructores
		Laberinto2D();
		Laberinto2D(const size_t& x, const size_t& y, const Dificultad& dif);
		Laberinto2D(const Laberinto2D& other);
		bool operator=(const Laberinto2D& other);
		~Laberinto2D();
		#pragma endregion
		#pragma region Getters
		size_t getX() const;
		size_t getY() const;
		Celda2D& getCelda(const size_t& x, const size_t& y) const;
		#pragma endregion
		#pragma region Setters
		#pragma endregion
		#pragma region Compares
		bool igual(const Laberinto2D& other) const;
		//bool similar(const Critico& other) const;
		#pragma endregion
		#pragma region Operators
		bool operator==(const Laberinto2D& other) const;
		bool operator!=(const Laberinto2D& other) const;
		#pragma endregion
		String toString() const;
};
