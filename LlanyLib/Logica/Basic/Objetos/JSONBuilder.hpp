#pragma once
#ifndef JSON_BUILDER_OBJECT_HPP_
#define JSON_BUILDER_OBJECT_HPP_

#include "../../Basic/LibreriasSimples/LlanyTypes.h"

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class StringBuilder;
			class JSONBuilder
			{
				public:
					enum class PrepType
					{
						Comillas,
						Corchetes,
						Nada
					};
				protected:
					StringBuilder* buffer;
					size_t n;
					void addKey(const String* key, const PrepType& prepObject);
					void addKey(char const* const key, const PrepType& prepObject);
					void addFin(const PrepType& prepObject, const bool& delantero);
				public:
					JSONBuilder();
					~JSONBuilder();
					void add(const String* key, const String* value, const PrepType& prepObject);
					void add(const String* key, const size_t& value);
					void add(const String* key, const bool& value);
					void add(const String* key, const int& value);
					void add(const String* key, const double& value);
					void add(const String* key, const float& value);
					void add(const String* key, const char& value);
					void add(const String* key, const long_t& value);
					void add(const String* key, const JSONBuilder* json);

					void add(char const* const key, const String* value, const PrepType& prepObject);
					void add(char const* const key, const size_t& value);
					void add(char const* const key, const bool& value);
					void add(char const* const key, const int& value);
					void add(char const* const key, const double& value);
					void add(char const* const key, const float& value);
					void add(char const* const key, const char& value);
					void add(char const* const key, const long_t& value);
					void add(char const* const key, const JSONBuilder* json);

					void addClear(String* key, JSONBuilder* json);
					void addClearKey(String* key, const JSONBuilder* json);
					void addClearJSON(const String* key, JSONBuilder* json);

					void addClearKey(String* key, const String* value, const PrepType& prepObject);
					void addClearValue(const String* key, String* value, const PrepType& prepObject);
					void addClearValue(char const* const key, String* value, const PrepType& prepObject);
					void addClear(String* key, String* value, const PrepType& prepObject);

					void addClear(String* key, const size_t& value);
					void addClear(String* key, const int& value);
					void addClear(String* key, const double& value);
					void addClear(String* key, const float& value);
					void addClear(String* key, const char& value);
					void addClear(String* key, const long_t& value);

					void clear();
					String* build() const;
			};
		}
	}
}
#endif // !JSON_BUILDER_OBJECT_HPP_