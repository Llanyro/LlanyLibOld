#pragma once
#ifndef ITEM_ENUM_JUEGO_HPP_
#define ITEM_ENUM_JUEGO_HPP_
namespace LlanyLib {
	namespace Juego {
		namespace Enum {
			enum class TipoObjeto
			{
				Objeto,

				// Se usa en el inventario y da un efecto al personaje + (Tesoros) y extrae todos los items
				Consumible,
				// No tiene uso directo en el inventario
				Contenedor,

				Municion,			// Municion de las armas de fuego (Y si eso de otros tambien)
				ElementoPuro,		// Elementos de la tabla periodica
				Compuesto,			// Comnpuestos de elementos puros haciendo otros nuevos
				Otro,				// Temporal

				Equipable
			};
			enum class TipoDeMaterial
			{
				Solido,
				Liquido,
				Gaseoso,
				Plasma,
				Irreal,
				LiquidoYGas
			};

		}
	}
}
#endif // !ITEM_ENUM_JUEGO_HPP_
