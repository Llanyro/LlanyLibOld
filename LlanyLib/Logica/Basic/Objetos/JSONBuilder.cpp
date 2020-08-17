#include "JSONBuilder.hpp"

#include "../Singletons/Chars.hpp"

#include "StringBuilder.hpp"
#include "String.hpp"

void LlanyLib::Basic::Objetos::JSONBuilder::addKey(const String* key, const PrepType& prepObject)
{
	this->buffer->add('"');
	this->buffer->add(key);
	this->buffer->add("\": ");
	JSONBuilder::addFin(prepObject, true);
}
void LlanyLib::Basic::Objetos::JSONBuilder::addFin(const PrepType& prepObject, const bool& delantero)
{
	switch (prepObject)
	{
		case JSONBuilder::PrepType::Comillas:
			this->buffer->add('"');
			break;
		case JSONBuilder::PrepType::Nada:
			break;
		case JSONBuilder::PrepType::Corchetes:
			if(delantero)
				this->buffer->add('{');
			else
				this->buffer->add('}');
			break;
	}
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

void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const String* value, const PrepType& prepObject)
{
	if (this->n > 0) this->buffer->add(',');
	JSONBuilder::addKey(key, prepObject);
	this->buffer->add(value);
	JSONBuilder::addFin(prepObject, false);
	this->n++;
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const size_t& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value), JSONBuilder::PrepType::Comillas);
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const int& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value), JSONBuilder::PrepType::Comillas);
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const double& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value), JSONBuilder::PrepType::Comillas);
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const float& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value), JSONBuilder::PrepType::Comillas);
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const char& value)
{
	JSONBuilder::addClearValue(key, CHARS->toString(value), JSONBuilder::PrepType::Comillas);
}
void LlanyLib::Basic::Objetos::JSONBuilder::add(const String* key, const JSONBuilder* json)
{
	/*if (this->n > 0) this->buffer->add(',');
	this->buffer->add('"');
	this->buffer->add(key);
	this->buffer->add("\": {");
	String* build = json->build();
	this->buffer->add(build);
	delete build;
	this->buffer->add('}');*/
	JSONBuilder::addClearValue(key, json->build(), JSONBuilder::PrepType::Corchetes);
}


void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, JSONBuilder* json)
{
	JSONBuilder::addClearKey(key, json);
	delete json;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClearKey(String* key, const JSONBuilder* json)
{
	JSONBuilder::add(key, json);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClearJSON(const String* key, JSONBuilder* json)
{
	JSONBuilder::add(key, json);
	delete json;
}

void LlanyLib::Basic::Objetos::JSONBuilder::addClearKey(String* key, const String* value, const PrepType& prepObject)
{
	JSONBuilder::add(key, value, prepObject);
	delete key;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClearValue(const String* key, String* value, const PrepType& prepObject)
{
	JSONBuilder::add(key, value, prepObject);
	delete value;
}
void LlanyLib::Basic::Objetos::JSONBuilder::addClear(String* key, String* value, const PrepType& prepObject)
{
	JSONBuilder::addClearKey(key, value, prepObject);
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
