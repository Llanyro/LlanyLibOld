#pragma once
#ifndef SOCKER_ENUMS_HPP_
#define SOCKER_ENUMS_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Enum {
			enum class SocketCode
			{
				NoCode,

				WSAStartupError,
				GetAddrInfoError,

				WSAStartupOK,
				GetAddrInfoOK,
				


			};
		}
	}
}
#endif // !SOCKER_ENUMS_HPP_
