#pragma once
#ifndef HTTP_ENUM_NET_HPP_
#define HTTP_ENUM_NET_HPP_
namespace LlanyLib {
	namespace Net {
		namespace Enum {
			enum class ContentType
			{
				JSON,
				TEXT,
				DEFAULT,
			};
			enum class ResponseProcess
			{
				// Only 1rst line
				PETITION,
				// 1rst line + content lenght + content
				POST_CONTENT,
				// 1rst line + content lenght + content
				// Insecure requests
				FAST,

				MEDIUM,
				SLOW,
				// Processes all
				SUPER_SLOW,
			};
		}
	}
}
#endif // !HTTP_ENUM_NET_HPP_
