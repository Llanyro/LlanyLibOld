#pragma once
#ifndef DATE_ENUM_HPP_
#define DATE_ENUM_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Enum {
			enum class Dias
			{
				Monday,
				Tuesday,
				Wednesday,
				Thursday,
				Friday,
				Staturday,
				Sunday
			};
			enum class Meses
			{
				January,
				February,
				March,
				April,
				May,
				June,
				July,
				August,
				September,
				October,
				November,
				December
			};
			enum class DateType
			{
				Days,
				Months,
				Years,
				WTF
			};
		}
	}
}
#endif // !DATE_ENUM_HPP_
