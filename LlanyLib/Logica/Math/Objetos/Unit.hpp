#pragma once
#ifndef UNIT_OBJECT_MATH_HPP_
#define UNIT_OBJECT_MATH_HPP_

#include "../../Basic/LibreriasSimples/LlanyTypes.h"

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
					Basic::Objetos::String* hexValue;
				protected:
					void setValue(char const* const value, const Enum::UnitType& unitType);
					void setValue(const long_t& value, const Enum::UnitType& unitType);
				public:
					Unit();
					Unit(char const* const value, const Enum::UnitType& unitType);
					Unit(const long_t& value, const Enum::UnitType& unitType);
					~Unit();
					Basic::Objetos::String* getFromatedHex() const;
					Basic::Objetos::String* getFromatedOct() const;
					Basic::Objetos::String* getFromatedDec() const;
					Basic::Objetos::String* getFromatedBin() const;
					Basic::Objetos::String* getHex() const;
					Basic::Objetos::String* getOct() const;
					Basic::Objetos::String* getBin() const;
					long_t getDec() const;
			};
		}
	}
}
#endif // !UNIT_OBJECT_MATH_HPP_
