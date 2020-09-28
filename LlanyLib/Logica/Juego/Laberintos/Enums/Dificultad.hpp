#pragma once
#ifndef DIFICULTAD_ENUM_LABERINTO_HPP_
#define DIFICULTAD_ENUM_LABERINTO_HPP_

namespace LlanyLib {
	namespace Laberintos {
		namespace Enums {
			enum class Dificultad
			{
				KruskalSimple,
				KruskalConSalas,
				DepthFirstSearchSimple,
				DepthFirstSearchConSalas,

				// Random
				RandomFacil,
				RandomMedio,
				RandomDificil,

				// Otros
				SoloMuros,
				Vacio,
				CuboHueco,
			};
		}
	}
}
#endif // !DIFICULTAD_ENUM_LABERINTO_HPP_
