#pragma once
#ifndef SYSTEM_ENUMS_HPP_
#define SYSTEM_ENUMS_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Enum {
			enum class Error
			{
				Input,
				Output,
				CharsControl,
				Popen,


			};
			enum class Warning
			{
				Input,
				Output,
				CharsControl,


			};
			enum class Codes
			{
				OK,
				PROCESADOR_NO_ACTIVO,

			};
		}
	}
}
#endif // !SYSTEM_ENUMS_HPP_
