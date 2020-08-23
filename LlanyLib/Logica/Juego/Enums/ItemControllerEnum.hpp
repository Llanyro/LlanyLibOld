#pragma once
#ifndef ITEM_CONTROLLER_ENUM_JUEGO_HPP_
#define ITEM_CONTROLLER_ENUM_JUEGO_HPP_
namespace LlanyLib {
	namespace Juego {
		namespace Enums {
			enum class ItemControllerResults
			{
				NoResult,
				PunteroContenedorNull,
				NoEsContenedor,
				EsContenedor,

				PunteroItemNull,
				NoCumpleRequirimientosDelContenedor,

				AddItemExitoContenedor,
			};
		}
	}
}
#endif // !ITEM_CONTROLLER_ENUM_JUEGO_HPP_
