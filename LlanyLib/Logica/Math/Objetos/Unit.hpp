#pragma once
#ifndef UNIT_OBJECT_MATH_HPP_
#define UNIT_OBJECT_MATH_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
	}
	namespace Math {
		namespace Enum {
			enum class UnitType;
		}
		namespace Objetos {
			class Unit
			{
				protected:
					Basic::Objetos::String* value;
					Enum::UnitType type;
				public:
				void toBinary() const;
				void toBinary() const;
				void toBinary() const;
				void toBinary() const;
			};
		}
	}
}
#endif // !UNIT_OBJECT_MATH_HPP_
