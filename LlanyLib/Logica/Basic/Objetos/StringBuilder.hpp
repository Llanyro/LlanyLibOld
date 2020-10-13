#pragma once
#ifndef STRING_BUILDER_OBJECT_HPP_
#define STRING_BUILDER_OBJECT_HPP_

#include "../LibreriasSimples/LlanyTypes.h"

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class Buffer;
			}
		}
		namespace Objetos {
			class String;
			class StringBuilder
			{
				protected:
					Templates::Listas::Buffer<char>* buffer;
				public:
					StringBuilder();
					~StringBuilder();
					bool contieneAlgo() const;
					bool add(const String* str);
					bool addClear(const String* str);
					bool add(char const* const str);
					bool add(const char& caracter);
					bool add(const int& val);
					bool add(const float& val);
					bool add(const double& val);
					bool add(const long_t& val);
					bool add(const size_t& val);
					void clear();
					
					bool operator+=(const String* str);
					bool operator+=(const char& caracter);
					bool operator+=(char const* const str);
					bool operator+=(const int& val);
					bool operator+=(const float& val);
					bool operator+=(const double& val);
					bool operator+=(const long_t& val);
					bool operator+=(const size_t& val);

					String* build() const;
			};
		}
	}
}
#endif // !STRING_BUILDER_OBJECT_HPP_
