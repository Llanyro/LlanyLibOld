#include "GeneradorLaberintos.hpp"


#include "../../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../../Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../../../Basic/Plantillas/Nodos/NodoDosObjetosDosPunteros.hpp"

#include "../Laberintos/Laberinto.hpp"
#include "../Enums/Dificultad.hpp"

#include "../../../Math/Singletons/Random.hpp"
#include "../Celdas/Celda2D.hpp"

LlanyLib::Laberintos::Singletons::GeneradorLaberintos::GeneradorLaberintos(){ GeneradorLaberintos::subscribir(GeneradorLaberintos::freeInstancia); }
LlanyLib::Laberintos::Singletons::GeneradorLaberintos::~GeneradorLaberintos(){}
#pragma region Metodos de generacion
#pragma region Kruskal
void LlanyLib::Laberintos::Singletons::GeneradorLaberintos::generarPorKruskalSimple2D(Objetos::Laberinto2D* laberinto) const
{
	Objetos::Celda2D** lab = laberinto->getCeldas();
	size_t x = laberinto->getX();
	size_t y = laberinto->getY();

	bool continuar = true;
	while (continuar)
	{
		size_t x_ = RANDOM->range(x);	// colum o cell
		size_t y_ = RANDOM->range(y);	// row
		size_t edge = RANDOM->range(4);		//
		Objetos::Celda2D* c1 = &lab[x_][y_];
		Objetos::Celda2D* c2 = nullptr;
		switch (edge)
		{
			case 0:
				if (y_ > 0)
				{
					c2 = &lab[x_][y_ - 1];
					if (!c1->contiene(c2))
					{
						c1->setArriba(false);
						c2->setAbajo(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
			case 1:
				if (x_ < x - 1)
				{
					c2 = &lab[x_ + 1][y_];
					if (!c1->contiene(c2))
					{
						c1->setDerecha(false);
						c2->setIzquierda(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
			case 2:
				if (y_ < y - 1)
				{
					c2 = &lab[x_][y_ + 1];
					if (!c1->contiene(c2))
					{
						c1->setAbajo(false);
						c2->setArriba(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
			case 3:
				if (x_ > 0)
				{
					c2 = &lab[x_ - 1][y_];
					if (!c1->contiene(c2))
					{
						c1->setIzquierda(false);
						c2->setDerecha(false);
						c1->mergeGrupos(*c2);
					}
				}
				break;
		}
		if (c1->getGrupo()->getCount() == x * y)
			continuar = false;
	}
}
#pragma endregion
#pragma region DepthFirstSearch
#pragma endregion
#pragma region Random
void LlanyLib::Laberintos::Singletons::GeneradorLaberintos::generarRandomFacil(Objetos::Laberinto2D* laberinto) const
{
	Objetos::Celda2D** lab = laberinto->getCeldas();
	size_t x = laberinto->getX();
	size_t y = laberinto->getY();

	Basic::Templates::Diccionarios::DictionaryLinkedList<size_t, size_t> celdas;
	for (size_t i = 0; i < x; i++)
		for (size_t e = 0; e < y; e++)
			celdas.add(i, e);

	while (celdas.getCount() > 0)
	{
		size_t pos = RANDOM->range(celdas.getCount());
		Basic::Templates::Nodos::NDODP<size_t, size_t>* nodo = celdas.getObject(pos);
		size_t edge = RANDOM->range(4);		//
		switch (edge)
		{
			case 0:
				if (nodo->getObject1() > 0)
				{
					lab[nodo->getObject0()][nodo->getObject1()].setArriba(false);
					lab[nodo->getObject0()][nodo->getObject1() - 1].setAbajo(false);
					celdas.remove(pos);
				}
				break;
			case 1:
				if (nodo->getObject0() < x - 1)
				{
					lab[nodo->getObject0()][nodo->getObject1()].setDerecha(false);
					lab[nodo->getObject0() + 1][nodo->getObject1()].setIzquierda(false);
					celdas.remove(pos);
				}
				break;
			case 2:
				if (nodo->getObject1() < y - 1)
				{
					lab[nodo->getObject0()][nodo->getObject1()].setAbajo(false);
					lab[nodo->getObject0()][nodo->getObject1() + 1].setArriba(false);
					celdas.remove(pos);
				}
				break;
			case 3:
				if (nodo->getObject0() > 0)
				{
					lab[nodo->getObject0()][nodo->getObject1()].setIzquierda(false);
					lab[nodo->getObject0() - 1][nodo->getObject1()].setDerecha(false);
					celdas.remove(pos);
				}
				break;
		}

	}
}
void LlanyLib::Laberintos::Singletons::GeneradorLaberintos::generarRandomMedio(Objetos::Laberinto2D* laberinto) const
{
	Objetos::Celda2D** lab = laberinto->getCeldas();
	size_t x = laberinto->getX();
	size_t y = laberinto->getY();

	size_t numIntentos = 0;
	for (size_t i = 0; i < x; i++)
		for (size_t e = 0; e < y; e++)
		{
			Objetos::Celda2D* celdaSeleccionada = &lab[i][e];
			size_t edge = RANDOM->range(4);
			Objetos::Celda2D* celdaTemp = nullptr;
			switch (edge)
			{
				case 0:
					if (e > 0 && celdaSeleccionada->getArriba())
					{
						celdaTemp = &lab[i][e - 1];
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
					if (i < x - 1 && celdaSeleccionada->getDerecha())
					{
						celdaTemp = &lab[i + 1][e];
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
					if (e < y - 1 && celdaSeleccionada->getAbajo())
					{
						celdaTemp = &lab[i][e + 1];
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
						celdaTemp = &lab[i - 1][e];
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
void LlanyLib::Laberintos::Singletons::GeneradorLaberintos::eliminarParedes(Objetos::Laberinto2D* laberinto) const
{
	laberinto->setAllFalse();
}
void LlanyLib::Laberintos::Singletons::GeneradorLaberintos::rellenarParedes(Objetos::Laberinto2D* laberinto) const
{
	laberinto->setAllTrue();
}
void LlanyLib::Laberintos::Singletons::GeneradorLaberintos::generarCuboHueco(Objetos::Laberinto2D* laberinto) const
{
	Objetos::Celda2D** lab = laberinto->getCeldas();
	size_t x = laberinto->getX();
	size_t y = laberinto->getY();

	for (size_t i = 0; i < y; i++)
	{
		for (size_t e = 0; e < x; e++)
		{
			lab[i][e].setAllFalse();

			if (i == 0)
				lab[i][e].setArriba(true);
			else if (i == x - 1)
				lab[i][e].setAbajo(true);
			
			if (e == 0)
				lab[i][e].setIzquierda(true);
			else if (e == y - 1)
				lab[i][e].setDerecha(true);
		}
	}
}
#pragma endregion
#pragma endregion

LlanyLib::Laberintos::Objetos::Laberinto2D* LlanyLib::Laberintos::Singletons::GeneradorLaberintos::generarLaberinto2D(const size_t& size, const Enums::Dificultad& diff) const
{
	return GeneradorLaberintos::generarLaberinto2D(size, size, diff);
}
LlanyLib::Laberintos::Objetos::Laberinto2D* LlanyLib::Laberintos::Singletons::GeneradorLaberintos::generarLaberinto2D(const size_t& x, const size_t& y, const Enums::Dificultad& diff) const
{
	Objetos::Laberinto2D* laberinto = new Objetos::Laberinto2D(x, y, diff);
	switch (diff)
	{
		#pragma region Kruskal
			// Ponemos todas la paredes y luego hacemos el laberinto
		case Enums::Dificultad::KruskalSimple:
			GeneradorLaberintos::rellenarParedes(laberinto);
			GeneradorLaberintos::generarPorKruskalSimple2D(laberinto);
			break;

		#pragma endregion
		#pragma region Random
			// Ponemos todas la paredes y luego hacemos el laberinto
		case Enums::Dificultad::RandomMedio:
			GeneradorLaberintos::rellenarParedes(laberinto);
			GeneradorLaberintos::generarRandomMedio(laberinto);
			break;
			// Ponemos todas la paredes y luego hacemos el laberinto
		case Enums::Dificultad::RandomFacil:
			GeneradorLaberintos::rellenarParedes(laberinto);
			GeneradorLaberintos::generarRandomFacil(laberinto);
			break;

		#pragma endregion
		#pragma region Otros
		case Enums::Dificultad::SoloMuros:
			GeneradorLaberintos::rellenarParedes(laberinto);
			break;
		case Enums::Dificultad::Vacio:
			GeneradorLaberintos::eliminarParedes(laberinto);
			break;
		case Enums::Dificultad::CuboHueco:
			GeneradorLaberintos::generarCuboHueco(laberinto);
			break;
		#pragma endregion
	}
	return laberinto;
}
