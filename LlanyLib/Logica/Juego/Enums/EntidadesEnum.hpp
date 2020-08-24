#pragma once
#ifndef ENTIDAD_ENUM_JUEGO_HPP_
#define ENTIDAD_ENUM_JUEGO_HPP_
namespace LlanyLib {
	namespace Juego {
		namespace Enums {
			enum class TipoDeEntidad
			{
				ENTIDAD_NULL,
				Jugador,
				Acompañante,
				NPC,
				ObjetoInertePosicionable,
				ObjetoInerteFlotante
			};
		}
	}
}
#endif // !ENTIDAD_ENUM_JUEGO_HPP_
