#include "Unit.hpp"

#include "../Enums/UnitEnum.hpp"
#include "../Singletons/UnitConversor.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"

void LlanyLib::Math::Objetos::Unit::setValue(char const* const value, const Enum::UnitType& unitType)
{
	switch (unitType)
	{
		case Enum::UnitType::Hexadecimal:
			this->hexValue = UNIT_CONVERSOR->hexToRawHex(value);
			break;
		case Enum::UnitType::Binary:
			this->hexValue = UNIT_CONVERSOR->binToRawHex(value);
			break;
		case Enum::UnitType::Decimal:
			this->hexValue = UNIT_CONVERSOR->decToRawHex(value);
			break;
		case Enum::UnitType::Octal:
			this->hexValue = UNIT_CONVERSOR->octToRawHex(value);
			break;
	}
}
void LlanyLib::Math::Objetos::Unit::setValue(const long_t& value, const Enum::UnitType& unitType)
{
	switch (unitType)
	{
		case Enum::UnitType::Decimal:
			this->hexValue = UNIT_CONVERSOR->rawDecToRawHex(value);
			break;
		case Enum::UnitType::Octal:
			this->hexValue = UNIT_CONVERSOR->rawOctToRawHex(value);
			break;
	}
}
LlanyLib::Math::Objetos::Unit::Unit()
{
	this->hexValue = nullptr;
}
LlanyLib::Math::Objetos::Unit::Unit(char const* const value, const Enum::UnitType& unitType) : Unit()
{
	Unit::setValue(value, unitType);
}
LlanyLib::Math::Objetos::Unit::Unit(const long_t& value, const Enum::UnitType& unitType) : Unit()
{
	Unit::setValue(value, unitType);
}
LlanyLib::Math::Objetos::Unit::~Unit()
{
	if (this->hexValue != nullptr)
		delete this->hexValue;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Objetos::Unit::getHex() const
{
	return new Basic::Objetos::String(*this->hexValue);
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Objetos::Unit::getOct() const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Objetos::Unit::getBin() const
{
	return nullptr;
}
long_t LlanyLib::Math::Objetos::Unit::getDec() const
{
	return 0;
}
