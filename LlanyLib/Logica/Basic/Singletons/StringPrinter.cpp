#include "StringPrinter.hpp"

#include <stdio.h>

#include "../Objetos/String.hpp"
#include "../Objetos/JSONBuilder.hpp"
#include "../Plantillas/Listas/LinkedList.hpp"
#include "../Plantillas/Pointers/SmartPointer.hpp"
//#include "FuncionesCaracteres.hpp"

#define STRING_NULL "Se ha introducido un string apuntando a nullptr. Se ha ignorado esto"
#define CADENA_NULL "Se ha introducido un string apuntando a nullptr. Se ha ignorado esto"
#define SIZE_NULL "Se ha introducido un size apuntando a nullptr. Se ha ignorado esto"

LlanyLib::Basic::Singletons::StringPrinter::StringPrinter() { StringPrinter::subscribir(StringPrinter::freeInstancia); }
LlanyLib::Basic::Singletons::StringPrinter::~StringPrinter(){}

void LlanyLib::Basic::Singletons::StringPrinter::printBool(const bool& value) const
{
	if(value)
		StringPrinter::print("True");
	else
		StringPrinter::print("False");
	StringPrinter::print('\n');
}

void LlanyLib::Basic::Singletons::StringPrinter::print(const char& caracter) const
{
	putchar(caracter);
}
void LlanyLib::Basic::Singletons::StringPrinter::print(const char* str, const size_t& size) const
{
	if (str == nullptr)
		StringPrinter::print(CADENA_NULL);
	else if(&size == nullptr)
		StringPrinter::print(SIZE_NULL);
	else {
		for (size_t i = 0; i < size; i++)
			putchar(str[i]);
	}
}
void LlanyLib::Basic::Singletons::StringPrinter::print(const LlanyLib::Basic::Objetos::String* str) const
{
	if (str == nullptr)
		StringPrinter::print(STRING_NULL);
	else
		StringPrinter::print(str->get(), str->length());
}
void LlanyLib::Basic::Singletons::StringPrinter::print(const LlanyLib::Basic::Objetos::String& str) const
{
	if (str == nullptr)
		StringPrinter::print(STRING_NULL);
	else
		StringPrinter::print(str(), str.length());
}
void LlanyLib::Basic::Singletons::StringPrinter::print(const Objetos::JSONBuilder* json) const
{
	StringPrinter::print('{');
	StringPrinter::printClear(json->build());
	StringPrinter::print('}');
}

void LlanyLib::Basic::Singletons::StringPrinter::printClear(LlanyLib::Basic::Objetos::String* str) const
{
	StringPrinter::print(str);
	if (str != nullptr)
		delete str;
}
void LlanyLib::Basic::Singletons::StringPrinter::printClear(Objetos::JSONBuilder* json) const
{
	StringPrinter::print(json);
	delete json;
}

void LlanyLib::Basic::Singletons::StringPrinter::printBoolLn(const bool& value) const
{
	StringPrinter::printBool(value);
	StringPrinter::print('\n');
}

void LlanyLib::Basic::Singletons::StringPrinter::printLn(const char& caracter) const
{
	StringPrinter::print(caracter);
	StringPrinter::print('\n');
}
void LlanyLib::Basic::Singletons::StringPrinter::printLn(const char* str, const size_t& size) const
{
	StringPrinter::print(str, size);
	StringPrinter::print('\n');
}
void LlanyLib::Basic::Singletons::StringPrinter::printLn(const Objetos::String* str) const
{
	StringPrinter::print(str);
	StringPrinter::print('\n');
}
void LlanyLib::Basic::Singletons::StringPrinter::printLn(const Objetos::JSONBuilder* json) const
{
	StringPrinter::print(json);
	StringPrinter::print('\n');
}

void LlanyLib::Basic::Singletons::StringPrinter::printLnClear(Objetos::String* str) const
{
	StringPrinter::printClear(str);
	StringPrinter::print('\n');
}
void LlanyLib::Basic::Singletons::StringPrinter::printLnClear(Objetos::JSONBuilder* json) const
{
	StringPrinter::printClear(json);
	StringPrinter::print('\n');
}

void LlanyLib::Basic::Singletons::StringPrinter::print(LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* list) const
{
	if (list != nullptr)
		for (size_t i = 0; i < list->size(); i++) {
			StringPrinter::print(*list->get(i));
			StringPrinter::print('\n');
		}
}
void LlanyLib::Basic::Singletons::StringPrinter::printClear(LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* list) const
{
	if (list != nullptr) {
		LlanyLib::Basic::Objetos::String* str = nullptr;
		for (size_t i = 0; i < list->size(); i++) {
			str = *list->get(i);
			StringPrinter::print(str);
			StringPrinter::print('\n');
			delete str;
		}
		delete list;
	}
}

void LlanyLib::Basic::Singletons::StringPrinter::printLn(LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* list) const
{
	StringPrinter::print(list);
	StringPrinter::print('\n');
}
void LlanyLib::Basic::Singletons::StringPrinter::printLnClear(LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* list) const
{
	StringPrinter::printClear(list);
	StringPrinter::print('\n');
}
