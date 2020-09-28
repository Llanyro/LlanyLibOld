/*#include "Laberinto2D.hpp"
#include "Celda2D.hpp"
#include "../../Herramientas/Singletons/Random.h"
#include "../../Herramientas/Plantillas/List.h"
#include "../../Herramientas/Plantillas/Diccionario.h"
#include "../../Herramientas/Objetos/String.h"
#include "../../Herramientas/Plantillas/Buffer.h"

#pragma region Private
#pragma region Generadores y otros
void Laberinto2D::generarLaberinto()const 
{
	switch (this->diff)
	{
		#pragma region Kruskal
			// Ponemos todas la paredes y luego hacemos el laberinto
		case Dificultad::KruskalSimple:
			Laberinto2D::rellenarParedes();
			Laberinto2D::generarPorKruskalSimple();
			break;

		#pragma endregion
		#pragma region Random
			// Ponemos todas la paredes y luego hacemos el laberinto
		case Dificultad::RandomMedio:
			Laberinto2D::rellenarParedes();
			Laberinto2D::generarRandomMedio();
			break;
			// Ponemos todas la paredes y luego hacemos el laberinto
		case Dificultad::RandomFacil:
			Laberinto2D::rellenarParedes();
			Laberinto2D::generarRandomFacil();
			break;


		#pragma endregion
		#pragma region Otros
		case Dificultad::SoloMuros:
			Laberinto2D::rellenarParedes();
			break;
		case Dificultad::Vacio:
			Laberinto2D::eliminarParedes();
			break;
		case Dificultad::CuboHueco:
			Laberinto2D::generarCuboHueco();
			break;
		#pragma endregion
	}
}
void Laberinto2D::clear()
{
	for (size_t i = 0; i < this->x; i++)
	{
		delete[] this->laberinto[i];
		this->laberinto[i] = nullptr;
	}
	if (this->laberinto != nullptr)
		delete[] this->laberinto;
	this->laberinto = nullptr;
	this->diff = Dificultad::KruskalSimple;
	this->x = 0;
	this->y = 0;
}
#pragma endregion
#pragma region Metodos de generacion
#pragma region Kruskal
void Laberinto2D::generarPorKruskalSimple() const
{
	bool continuar = true;
	while (continuar)
	{
		size_t x = RANDOM->range(this->x);	// colum o cell
		size_t y = RANDOM->range(this->y);	// row
		size_t edge = RANDOM->range(4);		//
		Celda2D* c1 = &this->laberinto[x][y];
		Celda2D* c2 = nullptr;
		switch (edge)
		{
			case 0:
				if (y > 0)
				{
					c2 = &this->laberinto[x][y - 1];
					if (!c1->contiene(c2))
					{
						c1->setArriba(false);
						c2->setAbajo(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
			case 1:
				if (x < this->x - 1)
				{
					c2 = &this->laberinto[x + 1][y];
					if (!c1->contiene(c2))
					{
						c1->setDerecha(false);
						c2->setIzquierda(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
			case 2:
				if (y < this->y - 1)
				{
					c2 = &this->laberinto[x][y + 1];
					if (!c1->contiene(c2))
					{
						c1->setAbajo(false);
						c2->setArriba(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
			case 3:
				if (x > 0)
				{
					c2 = &this->laberinto[x - 1][y];
					if (!c1->contiene(c2))
					{
						c1->setIzquierda(false);
						c2->setDerecha(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
		}
		if (c1->getGrupo()->getCount() == this->x * this->y)
			continuar = false;
	}
}
#pragma endregion
#pragma region DepthFirstSearch

#pragma endregion
#pragma region Random
void Laberinto2D::generarRandomFacil() const
{
	Diccionario<size_t, size_t> celdas;
	for (size_t i = 0; i < this->x; i++)
		for (size_t e = 0; e < this->y; e++)
			celdas.add(i, e);

	while (celdas.getCount() > 0)
	{
		size_t pos = RANDOM->range(celdas.getCount());
		size_t x = celdas.getValue(pos);
		size_t y = celdas.getKey(pos);
		size_t edge = RANDOM->range(4);		//
		switch (edge)
		{
			case 0:
				if (y > 0)
				{
					this->laberinto[x][y].setArriba(false);
					this->laberinto[x][y - 1].setAbajo(false);
					celdas.remove(pos);
				}
				break;
			case 1:
				if (x < this->x - 1)
				{
					this->laberinto[x][y].setDerecha(false);
					this->laberinto[x + 1][y].setIzquierda(false);
					celdas.remove(pos);
				}
				break;
			case 2:
				if (y < this->y - 1)
				{
					this->laberinto[x][y].setAbajo(false);
					this->laberinto[x][y + 1].setArriba(false);
					celdas.remove(pos);
				}
				break;
			case 3:
				if (x > 0)
				{
					this->laberinto[x][y].setIzquierda(false);
					this->laberinto[x - 1][y].setDerecha(false);
					celdas.remove(pos);
				}
				break;
		}

	}
}
void Laberinto2D::generarRandomMedio() const
{
	size_t numIntentos = 0;
	for (size_t i = 0; i < this->x; i++)
		for (size_t e = 0; e < this->y; e++)
		{
			Celda2D* celdaSeleccionada = &this->laberinto[i][e];
			size_t edge = RANDOM->range(4);
			Celda2D* celdaTemp = nullptr;
			switch (edge)
			{
				case 0:
					if (e > 0 && celdaSeleccionada->getArriba())
					{
						celdaTemp = &this->laberinto[i][e - 1];
						celdaSeleccionada->setArriba(false);
						celdaTemp->setAbajo(false);
					}
					else
					{
						e--;
						numIntentos++;
					}
					break;
				case 1:
					if (i < this->x - 1 && celdaSeleccionada->getDerecha())
					{
						celdaTemp = &this->laberinto[i + 1][e];
							celdaSeleccionada->setDerecha(false);
							celdaTemp->setIzquierda(false);
					}
					else
					{
						e--;
						numIntentos++;
					}
					break;
				case 2:
					if (e < this->y - 1 && celdaSeleccionada->getAbajo())
					{
						celdaTemp = &this->laberinto[i][e + 1];
						celdaSeleccionada->setAbajo(false);
						celdaTemp->setArriba(false);
					}
					else
					{
						e--;
						numIntentos++;
					}
					break;
				case 3:
					if (i > 0 && celdaSeleccionada->getIzquierda())
					{
						celdaTemp = &this->laberinto[i - 1][e];
						celdaSeleccionada->setIzquierda(false);
						celdaTemp->setDerecha(false);
					}
					else
					{
						e--;
						numIntentos++;
					}
					break;
			}
			if (numIntentos > 40)
				e++;
		}
}
#pragma endregion
#pragma region Otros
void Laberinto2D::eliminarParedes() const
{
	for (size_t i = 0; i < this->x; i++)
		for (size_t e = 0; e < this->y; e++)
			this->laberinto[i][e].setAllFalse();
}
void Laberinto2D::rellenarParedes() const
{
	for (size_t i = 0; i < this->x; i++)
		for (size_t e = 0; e < this->y; e++)
			this->laberinto[i][e].setAllTrue();
}
void Laberinto2D::generarCuboHueco() const
{
	for (size_t i = 0; i < this->x; i++)
	{
		for (size_t e = 0; e < this->y; e++)
		{
			this->laberinto[i][e].setAllFalse();

			if (i == 0)
				this->laberinto[i][e].setArriba(true);
			else if (i == this->x - 1)
				this->laberinto[i][e].setAbajo(true);

			if (e == 0)
				this->laberinto[i][e].setIzquierda(true);
			else if (e == this->y - 1)
				this->laberinto[i][e].setDerecha(true);
		}
	}
}
#pragma endregion
#pragma endregion
#pragma endregion
#pragma region Constructores
Laberinto2D::Laberinto2D()
{
	this->diff = Dificultad::KruskalSimple;
	this->x = 2;
	this->y = 2;
	this->laberinto = new Celda2D*[x];
	for (size_t i = 0; i < this->x; i++)
		this->laberinto[i] = new Celda2D[y];
	Laberinto2D::generarLaberinto();
}
Laberinto2D::Laberinto2D(const size_t& x, const size_t& y, const Dificultad& dif)
{
	assert(&x != nullptr);
	assert(&y != nullptr);
	assert(&dif != nullptr);
	assert(x > 0);
	assert(y > 0);
	this->diff = dif;
	this->x = x;
	this->y = y;
	this->laberinto = new Celda2D * [x];
	for (size_t i = 0; i < this->x; i++)
		this->laberinto[i] = new Celda2D[y];
	Laberinto2D::generarLaberinto();
}
Laberinto2D::Laberinto2D(const Laberinto2D& other)
{
	assert(&other != nullptr);
	bool temp = Laberinto2D::operator=(other);
	assert(temp);
}
bool Laberinto2D::operator=(const Laberinto2D& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->diff = other.diff;
		this->x = other.x;
		this->y = other.y;
		
		this->laberinto = new Celda2D * [x];
		for (size_t i = 0; i < this->x; i++)
		{
			this->laberinto[i] = new Celda2D[y];
			for (size_t e = 0; e < this->y; e++)
				this->laberinto[i][e] = other.laberinto[i][e];
		}
	}
	return temp;
}
Laberinto2D::~Laberinto2D()
{
	Laberinto2D::clear();
}
#pragma endregion
#pragma region Getters
size_t Laberinto2D::getX() const
{
	return this->x;
}
size_t Laberinto2D::getY() const
{
	return this->y;
}
Celda2D& Laberinto2D::getCelda(const size_t& x, const size_t& y) const
{
	assert(&x != nullptr);
	assert(&y != nullptr);
	assert(x < this->x);
	assert(y < this->y);
	return this->laberinto[x][y];
}
#pragma endregion
#pragma region Compares
bool Laberinto2D::igual(const Laberinto2D& other) const
{
	return false;
}
#pragma endregion
#pragma region Operators
bool Laberinto2D::operator==(const Laberinto2D& other) const
{
	return false;
}
bool Laberinto2D::operator!=(const Laberinto2D& other) const
{
	return false;
}
#pragma endregion
String Laberinto2D::toString() const
{
	Buffer<char> result;

	for (size_t e = 0; e < Laberinto2D::getY(); e++)
	{
		if (e == 0)
			for (size_t r = 0; r < 2; r++)
			{
				for (size_t i = 0; i < Laberinto2D::getX(); i++)
				{
					if (i == 0)
					{
						switch (r)
						{
						case 0:
							result += '#';

							if (Laberinto2D::getCelda(i, e).getArriba())
								result += '#';
							else
								result += ' ';

							result += '#';
							break;
						case 1:
							if (Laberinto2D::getCelda(i, e).getIzquierda())
								result += '#';
							else
								result += ' ';

							result += ' ';

							if (Laberinto2D::getCelda(i, e).getDerecha())
								result += '#';
							else
								result += ' ';
							break;
						}
					}
					else
					{
						switch (r)
						{
						case 0:
							if (Laberinto2D::getCelda(i, e).getArriba())
								result += '#';
							else
								result += ' ';

							result += '#';
							break;
						case 1:
							if (Laberinto2D::getCelda(i, e).getDerecha())
								result += '#';
							else
								result += ' ';

							result += ' ';
							break;
						}
					}
				}
				result += '\n';
			}
		else if (e == Laberinto2D::getY() - 1)
			for (size_t r = 0; r < 3; r++)
			{
				for (size_t i = 0; i < Laberinto2D::getX(); i++)
				{
					if (i == 0)
					{
						switch (r)
						{
						case 0:
							result += '#';
							if (Laberinto2D::getCelda(i, e).getArriba())
								result += '#';
							else
								result += ' ';
							result += '#';
							break;
						case 1:
							if (Laberinto2D::getCelda(i, e).getIzquierda())
								result += '#';
							else
								result += ' ';
							result += ' ';
							if (Laberinto2D::getCelda(i, e).getDerecha())
								result += '#';
							else
								result += ' ';
							break;
						case 2:
							result += '#';
							if (Laberinto2D::getCelda(i, e).getAbajo())
								result += '#';
							else
								result += ' ';
							result += '#';
							break;
						}
					}
					else
					{
						switch (r)
						{
						case 0:
							if (Laberinto2D::getCelda(i, e).getArriba())
								result += '#';
							else
								result += ' ';
							result += '#';
							break;
						case 1:
							result += ' ';
							if (Laberinto2D::getCelda(i, e).getDerecha())
								result += '#';
							else
								result += ' ';
							break;
						case 2:
							if (Laberinto2D::getCelda(i, e).getAbajo())
								result += '#';
							else
								result += ' ';
							result += '#';
							break;
						}
					}
				}
				result += '\n';
			}
		else
			for (size_t r = 0; r < 2; r++)
			{
				for (size_t i = 0; i < Laberinto2D::getX(); i++)
				{
					if (i == 0)
					{
						switch (r)
						{
						case 0:
							result += '#';
							if (Laberinto2D::getCelda(i, e).getArriba())
								result += '#';
							else
								result += ' ';
							result += '#';
							break;
						case 1:
							if (Laberinto2D::getCelda(i, e).getIzquierda())
								result += '#';
							else
								result += ' ';
							result += ' ';
							if (Laberinto2D::getCelda(i, e).getDerecha())
								result += '#';
							else
								result += ' ';
							break;
						}
					}
					else
					{
						switch (r)
						{
						case 0:
							if (Laberinto2D::getCelda(i, e).getArriba())
								result += '#';
							else
								result += ' ';
							result += '#';
							break;
						case 1:
							result += ' ';
							if (Laberinto2D::getCelda(i, e).getDerecha())
								result += '#';
							else
								result += ' ';
							break;
						}
					}
				}
				result += '\n';
			}
	}


	return result;
}
*/