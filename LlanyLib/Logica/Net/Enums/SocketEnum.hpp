#pragma once
#ifndef SOCKET_ENUMS_HPP_
#define SOCKET_ENUMS_HPP_

namespace LlanyLib {
	namespace Net {
		namespace Enum {
				#ifdef __unix__
				enum class SocketCode
				{
					NoCode,

					ErrorSocketNoDisponible,
					ErrorOnBinding,
					ErrorNoEscuchando,

					IniciadoCorrectamente

				};
				#elif _WIN32
				enum class SocketCode
				{
					NoCode,

					WSAStartupError,
					GetAddrInfoError,
					ErrorPuertoEscucha,
					ErrorOnBinding,
					ErrorNoEscuchando,

					IniciadoCorrectamente,
					ErrorAceptarCliente,


				};
				#endif // __unix__

				enum class ReadSocketType
				{
					HTTP,
					JSON,



				};
		}
	}
}
#endif // !SOCKET_ENUMS_HPP_
