#pragma once
#ifndef JSON_BUILDER_OBJECT_HPP_
#define JSON_BUILDER_OBJECT_HPP_

namespace LlanyLib
{
	namespace Basic
	{
		namespace Objetos
		{
			class String;
			class StringBuilder;
			class JSONBuilder
			{
				protected:
					StringBuilder* buffer;
					size_t n;

					void addKey(const String* key);
				public:
					JSONBuilder();
					~JSONBuilder();
					void add(const String* key, const String* value);
					void add(const String* key, const size_t& value);
					void add(const String* key, const int& value);
					void add(const String* key, const double& value);
					void add(const String* key, const float& value);
					void add(const String* key, const char& value);

					void addClearKey(String* key, const String* value);
					void addClearValue(const String* key, String* value);
					void addClear(String* key, String* value);

					void addClear(String* key, const size_t& value);
					void addClear(String* key, const int& value);
					void addClear(String* key, const double& value);
					void addClear(String* key, const float& value);
					void addClear(String* key, const char& value);

					void clear();
					String* build() const;
			};
		}
	}
}
#endif // !JSON_BUILDER_OBJECT_HPP_