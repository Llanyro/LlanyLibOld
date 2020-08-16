#include "JSONConversor.hpp"

#include "../Objetos/String.hpp"
#include "../Objetos/StringBuilder.hpp"
#include "../Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../Plantillas/Nodos/NodoDosObjetosDosPunteros.hpp"

LlanyLib::Basic::Singletons::JSONConversor::JSONConversor() { JSONConversor::subscribir(JSONConversor::freeInstancia); }
LlanyLib::Basic::Singletons::JSONConversor::~JSONConversor(){}

LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::JSONConversor::toJSON(const Templates::Diccionarios::DictionaryLinkedList<Objetos::String*, Objetos::String*>* dict) const
{
	Objetos::StringBuilder str;
	str.add('{');

	Templates::Nodos::NDODP<Objetos::String*, Objetos::String*>* temp = nullptr;
	for (size_t i = 0; i < dict->length(); i++) {
		if(i != 0) 
			str.add(',');
		temp = dict->getObject(i);
		str.add('"');
		str.add(temp->getObject0());
		str.add("\": \"");
		str.add(temp->getObject1());
		str.add('"');
	}

	str.add('}');
	return str.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::JSONConversor::toJSONClear(const Templates::Diccionarios::DictionaryLinkedList<Objetos::String*, Objetos::String*>* dict) const
{
	LlanyLib::Basic::Objetos::String* res = JSONConversor::toJSON(dict);
	Templates::Nodos::NDODP<Objetos::String*, Objetos::String*>* temp = nullptr;
	for (size_t i = 0; i < dict->length(); i++) {
		temp = dict->getObject(i);
		delete temp->getObject0();
		delete temp->getObject1();
	}
	delete dict;
	return res;
}
LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<LlanyLib::Basic::Objetos::String*, LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Singletons::JSONConversor::toDict(const Objetos::String* json) const
{
	Basic::Templates::Diccionarios::DictionaryLinkedList<
		Basic::Objetos::String*,
		Basic::Objetos::String*>*
		dict = new Basic::Templates::Diccionarios::DictionaryLinkedList<
		Basic::Objetos::String*,
		Basic::Objetos::String*>();

	Basic::Objetos::StringBuilder key;
	Basic::Objetos::StringBuilder value;
	char c;
	bool _key = false;
	bool _value = false;
	bool _doblepunto = false;
	bool _espacio = false;

	for (size_t i = 0; i < json->length(); i++)
	{
		c = json->get()[i];

		// Si ya estamos analizando la clave
		if (_key) {
			if (c == '"')
				_key = false;
			else
				key.add(c);
		}
		// Si ya estamos analizando el valor
		else if(_value) {
			if (c == '"')
				_value = false;
			else
				value.add(c);
		}
		// Si aun no ha empezado nada
		else {
			switch (c)
			{
				case '"': {
					if (_espacio) {
						_value = true;
						_espacio = false;
						_doblepunto = false;
					}
					else
						_key = true;
					}
					break;
				case ':':
					_doblepunto = true;
					break;
				case ' ':
					if (_doblepunto)
						_espacio = true;
					break;
				case ',':
					dict->add(key.build(), value.build());
					key.clear();
					value.clear();
					break;
			}
		}
	}

	return dict;
}
LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<LlanyLib::Basic::Objetos::String*, LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Singletons::JSONConversor::toDictClear(Objetos::String* json) const
{
	Basic::Templates::Diccionarios::DictionaryLinkedList<
		Basic::Objetos::String*,
		Basic::Objetos::String*>*
		dict = JSONConversor::toDict(json);
	delete json;
	return dict;
}
