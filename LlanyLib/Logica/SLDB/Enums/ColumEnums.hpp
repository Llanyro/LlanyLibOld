#pragma once
#ifndef TYPES_ENUM_LSDB_HPP_
#define TYPES_ENUM_LSDB_HPP_

namespace LlanyLib {
	namespace LSDB {
		namespace Enum {
			enum class Tipos
			{
				BOOL,
				INT,
				CHAR,
				STRING
			};
			enum class Propiedades
			{
				MaxStringSize,
				ParamsNull,

			};
		}
	}
}
#endif // !TYPES_ENUM_LSDB_HPP_
