#pragma once
#ifndef UNIT_CONVERSOR_SINGLETON_MATH_HPP_
#define UNIT_CONVERSOR_SINGLETON_MATH_HPP_

#include "../Libs/MathTypes.h"
#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define UNIT_CONVERSOR LlanyLib::Math::Singletons::UnitConversor::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
	}
	namespace Math {
		namespace Singletons {
			/*
				Help: https://www.rapidtables.com/convert/number/binary-to-hex.html
			*/
			class UnitConversor : public Basic::Templates::Singleton<UnitConversor>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<UnitConversor>;
					UnitConversor();
					~UnitConversor();
				#pragma endregion
				public:
					#pragma region Tools
					int charToIntHex(const char& caracter) const;	/// OK
					char intHexToChar(const int& val) const;		/// OK
					#pragma endregion
					#pragma region Raw
					#pragma region Bin to ...
					char binByteToRawHex(char const* const val, const size_t& size) const;	/// OK
					Basic::Objetos::String* binToRawHex(char const* const val) const;		/// OK
					long_t binToRawDec(char const* const val) const;							/// OK
					#pragma endregion
					#pragma region Dec to ...
					Basic::Objetos::String* rawDecToRawBase(const long_t& val, const size_t& base) const;	/// ???
					Basic::Objetos::String* rawDecToRawHex(const long_t& val) const;						/// OK
					Basic::Objetos::String* rawDecToRawBin(const long_t& val) const;						///	OK
					Basic::Objetos::String* rawDecToRawOct(const long_t& val) const;						///	OK
					Basic::Objetos::String* decToRawHex(char const* const val) const;
					Basic::Objetos::String* decToRawBin(char const* const val) const;
					Basic::Objetos::String* decToRawOct(char const* const val) const;
					long_t decToRawDec(char const* const val) const;
					#pragma endregion
					#pragma region Oct to ...
					long_t rawOctToRawDec(const long_t& val) const;						/// OK
					Basic::Objetos::String* rawOctToRawHex(const long_t& val) const;	/// OK

					// No funciona
					Basic::Objetos::String* octToRawBin(char const* const val) const;	/// NOT OK
					long_t octToRawDec(char const* const val) const;					/// OK
					Basic::Objetos::String* octToRawHex(char const* const val) const;	/// OK
					#pragma endregion
					#pragma region Hex to ...
					Basic::Objetos::String* hexToRawHex(char const* const) const;
					long_t rawHexToRawDec(char const* const) const;
					Basic::Objetos::String* rawHexToBin(char const* const) const;
					Basic::Objetos::String* rawHexToOct(char const* const) const;
					#pragma endregion
					#pragma endregion
					#pragma region Formated
					#pragma region Bin to ...

					#pragma endregion
					#pragma region Dec to ...
					//Basic::Objetos::String* decToHex(char const* const val) const;					/// NOT IMPLEMENTED
					//Basic::Objetos::String* decToBin(char const* const val) const;					/// NOT IMPLEMENTED
					//Basic::Objetos::String* decToOct(char const* const val) const;					/// NOT IMPLEMENTED
					#pragma endregion
					#pragma region Oct to ...
					#pragma endregion
					#pragma region Hex to ...
					#pragma endregion
					#pragma endregion
			};
		}
	}
}
#endif // !UNIT_CONVERSOR_SINGLETON_MATH_HPP_