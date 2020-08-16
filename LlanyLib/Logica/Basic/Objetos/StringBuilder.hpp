#pragma once
#ifndef STRING_BUILDER_OBJECT_HPP_
#define STRING_BUILDER_OBJECT_HPP_

namespace LlanyLib
{
	namespace Basic
	{
		namespace Templates {
			namespace Listas {
				template<class T>
				class Buffer;
			}
		}
		namespace Objetos
		{
			class String;
			class StringBuilder
			{
				protected:
					Templates::Listas::Buffer<char>* buffer;
				public:
					StringBuilder();
					~StringBuilder();
					bool add(const String* str);
					bool addClear(const String* str);
					bool add(char const* const str);
					bool add(const char& caracter);
					void clear();
					bool operator+=(const char& caracter);
					String* build() const;
			};
		}
	}
}
#endif // !STRING_BUILDER_OBJECT_HPP_
