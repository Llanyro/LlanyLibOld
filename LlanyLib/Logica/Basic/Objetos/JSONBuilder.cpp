#include "JSONBuilder.hpp"

#include "../Singletons/Chars.hpp"

#include "StringBuilder.hpp"
#include "String.hpp"

void LlanyLib::Basic::Objetos::JSONBuilder::addKey(const String* key)
{
	this->buffer->add('"');
	this->buffer->add(key);
	this->buffer->add("\": \"");
}

LlanyLib::Basic::Objetos::JSONBuilder::JSONBuilder()
{
	this->buffer = new StringBuilder();
	this->n = 0;
}
LlanyLib::Basic::Objetos::JSONBuilder::~JSONBuilder()
{
	delete this->buffer;
}

void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const String* value)
{
	if (this->n > 0) this->buffer->add(',');
	JSONBuilder::addKey(key);
	this->buffer->add(value);
	this->buffer->add('"');
	this->n++;
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const size_t& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value));
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const int& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value));
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const double& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value));
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const float& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value));
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const char& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value));
}


void LlanyLib::Basic::Objetos::JSONBuilder::addClearKey(String* key, const String* value)
{
	JSONBuilder::add(key, value);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClearValue(const String* key, String* value)
{
	JSONBuilder::add(key, value);
	delete value;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, String* value)
{
	JSONBuilder::add(key, value);
	delete key;
	delete value;
}


void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, const size_t& value)
{
	JSONBuilder::add(key, value);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, const int& value)
{
	JSONBuilder::add(key, value);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, const double& value)
{
	JSONBuilder::add(key, value);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, const float& value)
{
	JSONBuilder::add(key, value);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, const char& value)
{
	JSONBuilder::add(key, value);
	delete key;
}

void LlanyLib::Basic::Objetos::JSONBuilder::clear()
{
	this->buffer->clear();
	this->n = 0;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::JSONBuilder::build() const
{
	return this->buffer->build();
}
