#pragma once
#ifndef GENERADOR_LABERINTOS_SINGLETON_LABERINTOS_HPP_
#define GENERADOR_LABERINTOS_SINGLETON_LABERINTOS_HPP_

#include "../../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../../Basic/Gestores/SubscriptorSingletons.hpp"

#define GENERADOR_LABERINTOS LlanyLib::Laberintos::Singletons::GeneradorLaberintos::getInstancia()

namespace LlanyLib {
	namespace Laberintos {
		namespace Enum {
			enum class Dificultad;
		}
		namespace Objetos {
			class Laberinto2D;
			class Laberinto3D;
		}
		namespace Singletons {
			class GeneradorLaberintos : public Basic::Templates::Singleton<GeneradorLaberintos>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<GeneradorLaberintos>;
					GeneradorLaberintos();
					~GeneradorLaberintos();
				#pragma endregion
				protected:
					#pragma region Metodos de generacion
					#pragma region Kruskal
					void generarPorKruskalSimple2D(Objetos::Laberinto2D* laberinto) const;
					#pragma endregion
					#pragma region DepthFirstSearch
					#pragma endregion
					#pragma region Random
					void generarRandomFacil(Objetos::Laberinto2D* laberinto) const;
					void generarRandomMedio(Objetos::Laberinto2D* laberinto) const;
					#pragma endregion
					#pragma region Otros
					void eliminarParedes(Objetos::Laberinto2D* laberinto) const;
					void rellenarParedes(Objetos::Laberinto2D* laberinto) const;
					void generarCuboHueco(Objetos::Laberinto2D* laberinto) const;
					#pragma endregion
					#pragma endregion
				public:
					Objetos::Laberinto2D* generarLaberinto2D(const size_t& size, const Enum::Dificultad& diff) const;
					Objetos::Laberinto2D* generarLaberinto2D(const size_t& x, const size_t& y, const Enum::Dificultad& diff) const;
			};
		}
	}
}
#endif // !GENERADOR_LABERINTOS_SINGLETON_LABERINTOS_HPP_
