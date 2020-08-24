#pragma once
#ifndef STATS_ENUM_JUEGO_HPP_
#define STATS_ENUM_JUEGO_HPP_

namespace LlanyLib {
	namespace Juego {
		namespace Enums {
			enum class Raza
			{
				#pragma region No agrupados
				Null,
				Mestizo,
				#pragma endregion
				#pragma region Espirituales
				Elemental,
				Espiritu,
				Dementor,
				Pesadilla,
				Sombras,
				#pragma endregion
				#pragma region No muertos
				FantasmaGlobo,
				Fantasma,
				Esqueleto,
				Zombie,
				#pragma endregion
				#pragma region Acuaticos
				Triton,
				Sirena,
				Undine,
				Addanc,
				Merrow,
				Hippocampus,
				Each_Uisge,
				#pragma endregion
				#pragma region Mecanicos
				Mecha,
				Cyborg,
				Androide,
				#pragma endregion
				#pragma region Terrestre
				Orco,
				Duende,
				Enano,
				Gigante,
				Humano,

				SeresBestia,
				Minotauro,
				HombreLobo,
				Arpia,
				Draconico,
				Centauro,
				Aracne,
				Demigato,
				Demiperro,
				Demiconejo,
				#pragma endregion
				#pragma region Criaturas del bosque
				Hada,
				Elfo,
				ElfoOscuro,
				Ninfa,
				Driada,
				Ent,
				Sprigan,
				#pragma endregion
				#pragma region Demonios
				Imp,
				Ghoul,
				Sucubus,
				Incubo,
				Gargola,
				DeidadDemoniaca,
				#pragma endregion
				#pragma region Angeles
				Angel,
				Valquiria,
				Arcangel,
				DeiadAgelical,
				#pragma endregion
				#pragma region Vampiros
				SiervoVampiro,
				Vampiro,
				VampiroPuro,
				Alucard,
				//Dhanpir
				#pragma endregion
			};
		}
	}
}
#endif // !STATS_ENUM_JUEGO_HPP_
