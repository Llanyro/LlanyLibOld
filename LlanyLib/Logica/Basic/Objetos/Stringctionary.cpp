#include "Stringctionary.hpp"

#include "../Plantillas/Dictionary/DictionaryLinkedList.hpp"

#include "String.hpp"

LlanyLib::Basic::Objetos::Stringictionary::Stringictionary()
{
	this->dict = new Templates::Diccionarios::DictionaryLinkedList<String*, String*>();
}
LlanyLib::Basic::Objetos::Stringictionary::~Stringictionary()
{
	Stringictionary::clear();
	delete this->dict;
}
#pragma region Funciones del diccionario
bool LlanyLib::Basic::Objetos::Stringictionary::add(char const* const key, char const* const value)
{
	return this->dict->add(new String(key), new String(value));
}
bool LlanyLib::Basic::Objetos::Stringictionary::add(String* key, char const* const value)
{
	return this->dict->add(key, new String(value));
}
bool LlanyLib::Basic::Objetos::Stringictionary::add(char const* const key, String* value)
{
	return this->dict->add(new String(key), value);
}
bool LlanyLib::Basic::Objetos::Stringictionary::add(String* key, String* value)
{
	return this->dict->add(key, value);
}
bool LlanyLib::Basic::Objetos::Stringictionary::remove(char const* const key)
{
	bool resultado = false;
	size_t pos = Stringictionary::getKeyPos(key);
	if (this->dict->length() > pos)
		resultado = this->dict->remove(*this->dict->getKey(pos));
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::remove(String* key)
{
	bool resultado = false;
	size_t pos = Stringictionary::getKeyPos(key);
	if (this->dict->length() > pos)
		resultado = this->dict->remove(*this->dict->getKey(pos));
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::removeSimilar(char const* const key)
{
	bool resultado = false;
	size_t pos = Stringictionary::getKeySimilarPos(key);
	if (this->dict->length() > pos)
		resultado = this->dict->remove(*this->dict->getKey(pos));
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::removeSimilar(String* key)
{
	bool resultado = false;
	size_t pos = Stringictionary::getKeySimilarPos(key);
	if (this->dict->length() > pos)
		resultado = this->dict->remove(*this->dict->getKey(pos));
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::remove(const size_t& pos)
{
	bool resultado = false;
	if (this->dict->length() > pos)
		resultado = this->dict->remove(*this->dict->getKey(pos));
	return resultado;
}
void LlanyLib::Basic::Objetos::Stringictionary::clear()
{
	for (size_t i = 0; i < this->dict->length(); i++) {
		delete *this->dict->getKey(i);
		delete *this->dict->getValue(i);
	}
	this->dict->clear();
}
#pragma endregion
#pragma region Getters
LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<LlanyLib::Basic::Objetos::String*, LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Objetos::Stringictionary::getDict() const
{
	return this->dict;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getNumElements() const
{
	return this->dict->length();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getValue(char const* const key)
{
	String* resultado = nullptr;
	size_t pos = Stringictionary::getKeyPos(key);
	if (pos < this->dict->length())
		resultado = *this->dict->getValue(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getValue(const String* key)
{
	String* resultado = nullptr;
	size_t pos = Stringictionary::getKeyPos(key);
	if (pos < this->dict->length())
		resultado = *this->dict->getValue(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getValueSimilar(char const* const key)
{
	String* resultado = nullptr;
	size_t pos = Stringictionary::getKeySimilarPos(key);
	if (pos < this->dict->length())
		resultado = *this->dict->getValue(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getValueSimilar(const String* key)
{
	String* resultado = nullptr;
	size_t pos = Stringictionary::getKeySimilarPos(key);
	if (pos < this->dict->length())
		resultado = *this->dict->getValue(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getKey(const size_t& pos)
{
	String* resultado = nullptr;
	if (pos < this->dict->length())
		resultado = *this->dict->getKey(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getValue(const size_t& pos)
{
	String* resultado = nullptr;
	if (pos < this->dict->length())
		resultado = *this->dict->getValue(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getKeyLow(const size_t& pos) const
{
	String* resultado = nullptr;
	if (pos < this->dict->length())
		resultado = *this->dict->getKeyLow(pos);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Stringictionary::getValueLow(const size_t& pos) const
{
	String* resultado = nullptr;
	if (pos < this->dict->length())
		resultado = *this->dict->getValueLow(pos);
	return resultado;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getKeyPos(char const* const key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getKeyPos(const String* key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(*key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getValuePos(char const* const key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->equals(key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getValuePos(const String* key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->equals(*key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getKeySimilarPos(char const* const key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getKeySimilarPos(const String* key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getValueSimilarPos(char const* const key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->similar(key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
size_t LlanyLib::Basic::Objetos::Stringictionary::getValueSimilarPos(const String* key)
{
	size_t pos = this->dict->length();
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->similar(key)) {
			pos = i;
			i = this->dict->length();
		}
	return pos;
}
#pragma endregion
#pragma region Busquedas
bool LlanyLib::Basic::Objetos::Stringictionary::containsKey(const String* key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(*key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsKey(char const* const key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsValue(const String* key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->equals(*key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsValue(char const* const key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->equals(key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::contains(const String* key, const String* value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(*key))
			if ((*this->dict->getValue(i))->equals(*value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::contains(char const* const key, const String* value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(key))
			if ((*this->dict->getValue(i))->equals(*value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::contains(const String* key, char const* const value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(*key))
			if ((*this->dict->getValue(i))->equals(value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::contains(char const* const key, char const* const value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->equals(key))
			if ((*this->dict->getValue(i))->equals(value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}

bool LlanyLib::Basic::Objetos::Stringictionary::containsKeySimilar(const String* key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsKeySimilar(char const* const key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsValueSimilar(const String* key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->similar(key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsValueSimilar(char const* const key) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getValue(i))->similar(key)) {
			resultado = true;
			i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsSimilar(const String* key, const String* value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key))
			if ((*this->dict->getValue(i))->similar(value)) {
				resultado = true;
				i = this->dict->length();
		}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsSimilar(char const* const key, const String* value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key))
			if ((*this->dict->getValue(i))->similar(value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsSimilar(const String* key, char const* const value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key))
			if ((*this->dict->getValue(i))->similar(value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}
bool LlanyLib::Basic::Objetos::Stringictionary::containsSimilar(char const* const key, char const* const value) const
{
	bool resultado = false;
	for (size_t i = 0; i < this->dict->length(); i++)
		if ((*this->dict->getKey(i))->similar(key))
			if ((*this->dict->getValue(i))->similar(value)) {
				resultado = true;
				i = this->dict->length();
			}
	return resultado;
}
#pragma endregion
