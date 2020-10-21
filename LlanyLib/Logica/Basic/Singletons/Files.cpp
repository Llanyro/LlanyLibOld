#pragma warning(disable:4996)
#include "Files.hpp"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "System.hpp"
#include "../Objetos/String.hpp"
#include "../Objetos/StringBuilder.hpp"
#include "../Plantillas/Listas/LinkedList.hpp"
#include "../Enumerators/FilesEnum.hpp"

#define COMMAND_MKDIR "mkdir "


void fileputs(FILE* file, const LlanyLib::Basic::Objetos::String* content)
{
	for (size_t i = 0; i < content->length() - 1; i++)
		fputc(content->get()[i], file);
}
void fileputs(FILE* file, const char* const content)
{
	size_t size = strlen(content);
	for (size_t i = 0; i < size; i++)
		fputc(content[i], file);
}

#pragma region Singleton
LlanyLib::Basic::Singletons::Files::Files() { Files::subscribir(Files::freeInstancia); }
LlanyLib::Basic::Singletons::Files::~Files() {}
#pragma endregion
#pragma region Protected
const char* LlanyLib::Basic::Singletons::Files::getParams(const Enum::FopenType& type) const
{
	const char* params = nullptr;
	switch (type)
	{
	case Enum::FopenType::Create:
		params = "w";
		break;
	case Enum::FopenType::Append:
		params = "a";
		break;
	case Enum::FopenType::CreateBinary:
		params = "wb";
		break;
	case Enum::FopenType::AppendBinary:
		params = "ab";
		break;
	default:
		params = "a";
		break;
	}
	return params;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroBase(const Objetos::String* fileName, const Objetos::String* content, const Enum::FopenType& type) const
{
	assert(fileName != nullptr);
	assert(content != nullptr);
	FILE* file = fopen(fileName->get(), Files::getParams(type));
	fileputs(file, content);
	fclose(file);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroBase(const Objetos::String* fileName, const char& caracter, const Enum::FopenType& type) const
{
	assert(fileName != nullptr);
	FILE* file = fopen(fileName->get(), Files::getParams(type));
	fputc(caracter, file);
	fclose(file);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroBase(const Objetos::String* fileName, char const* const content, const Enum::FopenType& type) const
{
	assert(fileName != nullptr);
	assert(content != nullptr);
	FILE* file = fopen(fileName->get(), Files::getParams(type));
	fileputs(file, content);
	fclose(file);
}
#pragma endregion
#pragma region Lectura
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::leerFicheroFopenFseek(char const* const fileName) const
{
	Objetos::String* str = nullptr;
	FILE* file = fopen(fileName, "r");
	if (file != nullptr)
	{
		fseek(file, 0, SEEK_END);
		str = new Objetos::String((size_t)ftell(file));
		fseek(file, 0, SEEK_SET);
		fread(str->get(), 1, str->length(), file);
		fclose(file);
	}
	return str;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::leerFicheroFopenFseek(const Objetos::String* fileName) const
{
	//assert(fileName != nullptr);
	//Objetos::String* str = nullptr;
	//FILE* file = fopen(fileName->get(), "r");
	//if (file != nullptr)
	//{
	//	fseek(file, 0, SEEK_END);
	//	str = new Objetos::String((size_t)ftell(file));
	//	fseek(file, 0, SEEK_SET);
	//	fread(str->get(), 1, str->length(), file);
	//	fclose(file);
	//}
	//return str;
	return Files::leerFicheroFopenFseek(fileName->get());
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::leerFicheroFopenFseekClear(const Objetos::String* fileName) const
{
	Objetos::String* str = Files::leerFicheroFopenFseek(fileName);
	delete fileName;
	return str;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::leerFicheroFopen(char const* const fileName) const
{
	Objetos::StringBuilder str;
	FILE* file = fopen(fileName, "r");
	if (file != nullptr) {
		char c;
		while ((c = getc(file)) != EOF)
			str += c;
		fclose(file);
	}
	return str.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::leerFicheroFopen(const Objetos::String* fileName) const
{
	return Files::leerFicheroFopen(fileName->get());
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::leerFicheroFopenClear(const Objetos::String* fileName) const
{
	Objetos::String* str = Files::leerFicheroFopen(fileName);
	delete fileName;
	return str;
}
#pragma endregion
#pragma region Escritura
#pragma region Strings
void LlanyLib::Basic::Singletons::Files::escribirFichero(const Objetos::String* fileName, const Objetos::String* content) const
{
	assert(fileName != nullptr);
	assert(content != nullptr);
	Files::escribirFicheroBase(fileName, content, Enum::FopenType::Create);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroClear(const Objetos::String* fileName, const Objetos::String* content) const
{
	assert(fileName != nullptr);
	Files::escribirFichero(fileName, content);
	delete fileName;
	delete content;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroClearFilename(const Objetos::String* fileName, const Objetos::String* content) const
{
	assert(fileName != nullptr);
	Files::escribirFichero(fileName, content);
	delete fileName;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroClearContent(const Objetos::String* fileName, const Objetos::String* content) const
{
	assert(fileName != nullptr);
	Files::escribirFichero(fileName, content);
	delete content;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppend(const Objetos::String* fileName, const Objetos::String* content) const
{
	assert(fileName != nullptr);
	assert(content != nullptr);
	Files::escribirFicheroBase(fileName, content, Enum::FopenType::Append);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppendClear(const Objetos::String* fileName, const Objetos::String* content) const
{
	Files::escribirFicheroAppend(fileName, content);
	delete fileName;
	delete content;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppendClearFilename(const Objetos::String* fileName, const Objetos::String* content) const
{
	Files::escribirFicheroAppend(fileName, content);
	delete fileName;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppendClearContent(const Objetos::String* fileName, const Objetos::String* content) const
{
	Files::escribirFicheroAppend(fileName, content);
	delete content;
}
#pragma endregion
#pragma region Caracteres
void LlanyLib::Basic::Singletons::Files::escribirFichero(const Objetos::String* fileName, const char& caracter) const
{
	Files::escribirFicheroBase(fileName, caracter, Enum::FopenType::Create);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroClear(const Objetos::String* fileName, const char& caracter) const
{
	Files::escribirFichero(fileName, caracter);
	delete fileName;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppend(const Objetos::String* fileName, const char& caracter) const
{
	Files::escribirFicheroBase(fileName, caracter, Enum::FopenType::Append);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppendClear(const Objetos::String* fileName, const char& caracter) const
{
	Files::escribirFicheroAppend(fileName, caracter);
	delete fileName;
}
#pragma endregion
#pragma region Char const
void LlanyLib::Basic::Singletons::Files::escribirFichero(const Objetos::String* fileName, char const* const content) const
{
	assert(fileName != nullptr);
	Files::escribirFicheroBase(fileName, content, Enum::FopenType::Create);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroClear(const Objetos::String* fileName, char const* const content) const
{
	assert(fileName != nullptr);
	Files::escribirFichero(fileName, content);
	delete fileName;
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppend(const Objetos::String* fileName, char const* const content) const
{
	assert(fileName != nullptr);
	Files::escribirFicheroBase(fileName, content, Enum::FopenType::Append);
}
void LlanyLib::Basic::Singletons::Files::escribirFicheroAppendClear(const Objetos::String* fileName, char const* const content) const
{
	assert(fileName != nullptr);
	Files::escribirFicheroAppend(fileName, content);
	delete fileName;
}
#pragma endregion
#pragma endregion
#pragma region Directorios
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::crearPath(const Objetos::String* fileName) const
{
	Templates::Listas::LinkedList<char> separadores;
	separadores.add('/');
	separadores.add('\\');

	Templates::Listas::LinkedList<Objetos::String*>* list = fileName->split(&separadores);
	Objetos::StringBuilder buffer;
	Objetos::String* temp = nullptr;
	char sep = Files::caracterSeparadorDirectorios();

	buffer.add("mkdir ");

	for (size_t i = 0; i < list->getCount(); i++) {
		for (size_t e = 0; e < i + 1; e++) {
			temp = *list->get(e);
			// Si estamos por ejemplo en C:
			if (temp->containsChar(':')) {
				// Y ademas no estamos poniendolo solo
				if (i != 0)
					buffer.add(temp);
			}
			else {
				if (e != 0) buffer.add(sep);
				buffer.add(temp);
			}
		}
		buffer.add(' ');
	}

	for (size_t i = 0; i < list->getCount(); i++)
		delete *list->get(i);
	delete list;

	// Objetos::String* temp = Objetos::String(COMMAND_MKDIR) + *fileName;
	// SYSTEM->ejecutarCommandClear(temp);

	//return new Objetos::String(buffer);
	return SYSTEM->ejecutarCommandClear(buffer.build());
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::crearPathClear(const Objetos::String* fileName) const
{
	LlanyLib::Basic::Objetos::String* temp = Files::crearPath(fileName);
	delete fileName;
	return temp;
}
#pragma endregion
#pragma region Otros
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::Files::origenPrograma() const
{
	Objetos::String* resultado = nullptr;

	#ifdef _WIN32
	Objetos::String* temp = SYSTEM->ejecutarCommandClear(new LlanyLib::Basic::Objetos::String("cd"));
	resultado = temp->splitGetFirst('\n');
	delete temp;
	#elif __unix__
	return System::ejecutarCommandClear("pwd").splitIn2('\n')[0];
	#else
	return "No preparado para este sistema";
	#endif // _WIN32

	return resultado;
}
char LlanyLib::Basic::Singletons::Files::caracterSeparadorDirectorios() const
{
	char c;
	#ifdef _WIN32
	c = '\\';
	#elif __unix__
	c = '/';
	#endif // _WIN32
	return c;
}
#pragma endregion
