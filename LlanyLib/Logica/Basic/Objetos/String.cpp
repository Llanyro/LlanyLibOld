#include "String.hpp"

#include <string>

#include "../Enumerators/StringEnum.hpp"

#include "../Singletons/Mem.hpp"
#include "../Singletons/Chars.hpp"

#include "../Plantillas/Listas/Buffer.hpp"

#include "StringBuilder.hpp"

inline int compareChar(const char* caracter1, const char* caracter2)
{
	int resultado = 0;
	if (caracter1 == nullptr && caracter2 == nullptr) resultado = 0;	// Ambos son iguales
	else if (caracter1 == nullptr) resultado = -1;						// Caracter 2 mayor
	else if (caracter2 == nullptr) resultado = 1;						// Caracter 1 mayor
	else if (*caracter1 == *caracter2) resultado = 0;					// Ambos son iguales
	else if (*caracter1 > * caracter2) resultado = 1;					// Caracter 1 mayor
	else if (*caracter1 < *caracter2) resultado = -1;					// Caracter 2 mayor
	else resultado = -2;												// Other
	return resultado;
}

#pragma region Protected
void LlanyLib::Basic::Objetos::String::inicializarString(const size_t& size)
{
	if (this->vector == nullptr && &size != nullptr) {
		this->count = size;
		this->vector = new char[size];
	}
}
void LlanyLib::Basic::Objetos::String::inicializarString(const char& caracter)
{
	if (&caracter != nullptr) {
		String::inicializarString((size_t)2);
		this->vector[0] = caracter;
		this->vector[1] = '\0';
	}
}
void LlanyLib::Basic::Objetos::String::inicializarString(const char* str)
{
	if (str != nullptr)
		String::inicializarString(str, strlen(str));
}
void LlanyLib::Basic::Objetos::String::inicializarString(const char* str, const size_t& size)
{
	if (str != nullptr && &size != nullptr) {
		String::inicializarString(size + 1);
		MEM->copiarMemoria(this->vector, str, 0, size, sizeof(char));
		this->vector[size] = '\0';
	}
}
void LlanyLib::Basic::Objetos::String::inicializarStringObj(const String& str)
{
	if (&str == nullptr || str.vector == nullptr)
		String::clear();
	else
		String::inicializarString(str.vector, str.count - 1);
}
void LlanyLib::Basic::Objetos::String::inicializarStringObj(const Templates::Listas::Buffer<char>& str)
{
	if (&str != nullptr && str.length() > 0) {
		String::inicializarString((size_t)str.length() + 1);
		for (size_t i = 0; i < this->count - 1; i++)
			this->vector[i] = str[i];
		this->vector[this->count - 1] = '\0';
	}
	else
		String::clear();
}
#pragma endregion
#pragma region Constructores
LlanyLib::Basic::Objetos::String::String() : Listas()
{
	this->vector = nullptr;
}
LlanyLib::Basic::Objetos::String::String(const size_t& size) : String()
{
	String::inicializarString(size);
}
LlanyLib::Basic::Objetos::String::String(const char& caracter) : String()
{
	String::inicializarString(caracter);
}
LlanyLib::Basic::Objetos::String::String(const char* str) : String()
{
	String::inicializarString(str);
}
LlanyLib::Basic::Objetos::String::String(const char* str, const size_t& size) : String()
{
	String::inicializarString(str, size);
}
LlanyLib::Basic::Objetos::String::String(const String& str) : String()
{
	String::inicializarStringObj(str);
}
LlanyLib::Basic::Objetos::String::String(const Templates::Listas::Buffer<char>& str) : String()
{
	String::inicializarStringObj(str);
}
bool LlanyLib::Basic::Objetos::String::operator=(const char& caracter)
{
	bool resultado = false;
	if (&caracter != nullptr) {
		String::clear();
		String::inicializarString(caracter);
	}
	else
		String::clear();
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::operator=(const char* str)
{
	bool resultado = false;
	if (str != nullptr) {
		String::clear();
		String::inicializarString(str);
	}
	else
		String::clear();
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::operator=(const String& str)
{
	bool resultado = false;
	if (&str != nullptr) {
		String::clear();
		String::inicializarStringObj(str);
	}
	else
		String::clear();
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::operator=(const Templates::Listas::Buffer<char>& str)
{
	bool resultado = false;
	if (&str != nullptr) {
		String::clear();
		String::inicializarStringObj(str);
	}
	else
		String::clear();
	return resultado;
}
LlanyLib::Basic::Objetos::String::~String()
{
	String::clear();
}
#pragma endregion
#pragma region Operators con strigs
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::operator+(const char& caracter)
{
	String* resultado = new String(this->count + 1);
	MEM->copiarMemoria(resultado->vector, this->vector, 0, this->count - 1, sizeof(char));
	resultado->vector[resultado->count - 2] = caracter;
	resultado->vector[resultado->count - 1] = '\0';
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::operator+(char const* const str)
{
	size_t len = strlen(str);
	String* resultado = new String(this->count + len);
	MEM->copiarMemoria(resultado->vector, this->vector, 0, this->count - 1, sizeof(char));
	MEM->copiarMemoria(resultado->vector + this->count - 1, str, 0, len, sizeof(char));
	resultado->vector[resultado->count - 1] = '\0';
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::operator+(const String& other)
{
	String* resultado = new String(this->count + other.count - 1);
	MEM->copiarMemoria(resultado->vector, this->vector, 0, this->count - 1, sizeof(char));
	MEM->copiarMemoria(resultado->vector + this->count - 1, other.vector, 0, other.count, sizeof(char));
	return resultado;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Basic::Objetos::String::similar(const char& caracter) const
{
	bool resultado = false;
	if (this->count == 2)
		resultado = CHARS->compareCharSimilar(this->vector, &caracter);
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::similar(char const* const str) const
{
	int resultado = 0;
	size_t size_2 = strlen(str);
	size_t min = 0;

	if (this->count > size_2) {
		for (size_t i = 0; resultado == 0 && i < size_2; i++)
			resultado = CHARS->compareCharSimilar(this->vector + i, str + i);
		if (resultado == 0)
			resultado = 1;
	}
	else if (this->count < size_2) {
		for (size_t i = 0; resultado == 0 && i < this->count; i++)
			resultado = CHARS->compareCharSimilar(this->vector + i, str + i);
		if (resultado == 0)
			resultado = -1;
	}
	else
		for (size_t i = 0; resultado == 0 && i < this->count; i++)
			resultado = CHARS->compareCharSimilar(this->vector + i, str + i);
	return (resultado == 0);
}
bool LlanyLib::Basic::Objetos::String::similar(const char* str, const size_t& size)
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::similar(const String* other)
{
	return false;
}
int LlanyLib::Basic::Objetos::String::compare(const char& caracter) const
{
	int resultado = 0;
	if (this->count == 2)
		resultado = compareChar(this->vector, &caracter);
	else
		resultado = -1;
	return resultado;
}
int LlanyLib::Basic::Objetos::String::compare(char const* const str) const
{
	int resultado = 0;
	if (str != this->vector) {
		if (str == nullptr) resultado = 1;
		else if (vector == nullptr) resultado = -1;
		else resultado = strcmp(this->vector, str);
	}
	return resultado;
	//return CHARS->compareString(this->vector, this->count, str, strlen(str));
}
int LlanyLib::Basic::Objetos::String::compare(const String& other) const
{
	int resultado = 0;
	if (&other != nullptr)
		resultado = String::compare(other.vector);
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::equals(const char& caracter) const
{
	return String::compare(caracter) == 0;
}
bool LlanyLib::Basic::Objetos::String::equals(char const* const str) const
{
	return String::compare(str) == 0;
}
bool LlanyLib::Basic::Objetos::String::equals(const String& other) const
{
	return String::compare(other) == 0;
}
bool LlanyLib::Basic::Objetos::String::operator==(const char& caracter) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::operator==(char const* const str) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::operator==(const String& other) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::operator!=(const char& caracter) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::operator!=(char const* const str) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::operator!=(const String& other) const
{
	return false;
}
#pragma endregion
#pragma region SubStrings
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::substring(const size_t& inicio, const size_t& end) const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::substring(const char& inicio, const char& end) const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::stringCensurado() const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::subStringCensurado(const size_t& inicio, const size_t& end) const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::buscarYBorrar(const char& caracter) const
{
	return nullptr;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::buscarYBorrarAll(const char& caracter) const
{
	StringBuilder str;
	for (size_t i = 0; i < this->count; i++)
		if (this->vector[i] != caracter)
			str.add(this->vector[i]);
	return str.build();
}
LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Objetos::String::split(const char& separador) const
{
	assert(&separador != nullptr);
	LlanyLib::Basic::Templates::Listas::LinkedList<String*>* result = 
		new LlanyLib::Basic::Templates::Listas::LinkedList<String*>();
	LlanyLib::Basic::Templates::Listas::Buffer<char> buffer(this->count / 2);
	for (size_t e = 0; e < this->count; e++)
	{
		// Si el caracter a guardar no es el separador
		if (this->vector[e] != separador)
			// Guardamos el caracter en un buffer
			buffer += this->vector[e];
		// Si lo es
		else
		{
			if (buffer.getCount() > 0) {
				// Añadimos el buffer a la lista
				result->add(new String(buffer));
				// Limpiamos el buffer para reutilizarlo
				buffer.clear();
			}
		}
	}
	if (buffer.getCount() > 1)
		result->add(new String(buffer));
	return result;
}
LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Objetos::String::split(char const* const separador) const
{
	Templates::Listas::LinkedList<String*>* result = nullptr;
	size_t sizeStr = strlen(separador);
	if (sizeStr == 2)
		result = String::split(separador[0]);
	else {
		StringBuilder buffer;
		result = new LlanyLib::Basic::Templates::Listas::LinkedList<String*>();
		for (size_t i = 0; i < this->count; i++) {
			// Si el caracter actual coincide con el primero del separador
			if (this->vector[i] == separador[0]) {
				for (size_t r = 1; r < sizeStr; r++) {
					// Si coincide el caracter actual + r con el caracter del separador + r 
					if (this->vector[i + r] == separador[r]) {
						if (r == sizeStr - 1) {
							// Añadimos el buffer cortado a la lista
							result->add(buffer.build());
							// Limpiamos el buffer para reutilizarlo
							buffer.clear();
							// Avanzamos tanas posiciones como caracteres coincidan
							i += r;
						}
					}
					// Si no
					else {
						// Guardamos el caracter en un buffer
						buffer += this->vector[i];
						// Salimos del bucle
						r = sizeStr;
					}
				}
			}
			// Si no coincide
			else
				// Guardamos el caracter en un buffer
				buffer += this->vector[i];
		}
		if (buffer.contieneAlgo())
			result->add(buffer.build());
	}

	return result;
}
LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Objetos::String::split(Templates::Listas::LinkedList<char>* list) const
{
	LlanyLib::Basic::Templates::Listas::LinkedList<String*>* result = nullptr;

	if (&list != nullptr && list->getCount() > 0) {
		if (list->getCount() == 1)
			result = String::split(*list->get(0));
		else
		{
			result = new LlanyLib::Basic::Templates::Listas::LinkedList<String*>();

			LlanyLib::Basic::Templates::Listas::Buffer<char> buffer(this->count / 2);
			for (size_t e = 0; e < this->count; e++)
			{
				// Si el caracter a guardar no es el separador(Ninguno de ellos)
				if (!list->contains(this->vector[e]))
					// Guardamos el caracter en un buffer
					buffer += this->vector[e];
				// Si lo es
				else
				{
					// Añadimos el buffer a la lista
					result->add(new String(buffer));
					// Limpiamos el buffer para reutilizarlo
					buffer.clear();
				}
			}
			if (buffer.getCount() > 1)
				result->add(new String(buffer));
		}
	}
	return result;
}
LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Basic::Objetos::String*>* LlanyLib::Basic::Objetos::String::splitClear(Templates::Listas::LinkedList<char>* list) const
{
	LlanyLib::Basic::Templates::Listas::LinkedList<String*>* result = String::split(list);
	delete list;
	return result;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::splitGetFirst(const char& separador) const
{
	String* resultado = nullptr;
	LlanyLib::Basic::Templates::Listas::LinkedList<String*>* lista = String::split(separador);
	for (size_t i = 0; i < lista->length(); i++) {
		if (i == 0)
			resultado = *lista->get(i);
		else
			delete *lista->get(i);
	}
	delete lista;
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::splitGetFirst(Templates::Listas::LinkedList<char>* list) const
{
	String* resultado = nullptr;
	LlanyLib::Basic::Templates::Listas::LinkedList<String*>* lista = String::split(list);
	for (size_t i = 0; i < lista->length(); i++) {
		if (i == 0)
			resultado = *lista->get(i);
		else
			delete* lista->get(i);
	}
	delete lista;
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::splitClearGetFirst(Templates::Listas::LinkedList<char>* list) const
{
	String* resultado = String::splitGetFirst(list);
	delete list;
	return resultado;
}
#pragma endregion
#pragma region Buscadores
bool LlanyLib::Basic::Objetos::String::containsChar(const char& caracter) const
{
	assert(&caracter != nullptr);
	bool res = false;
	for (size_t i = 0; i < this->count && !res; i++)
		res = (caracter == this->vector[i]);
	return res;
}
bool LlanyLib::Basic::Objetos::String::containsStr(char const* const str) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::containsStr(const char* str, const size_t& size) const
{
	return false;
}
bool LlanyLib::Basic::Objetos::String::containsStr(const String& other) const
{
	return false;
}
size_t LlanyLib::Basic::Objetos::String::containsCharValue(const char& caracter) const
{
	return 0;
}
size_t LlanyLib::Basic::Objetos::String::containsStrValue(char const* const str) const
{
	return 0;
}
size_t LlanyLib::Basic::Objetos::String::containsStrValue(const char* str, const size_t& size) const
{
	return 0;
}
size_t LlanyLib::Basic::Objetos::String::containsStrValue(const String& other) const
{
	return 0;
}
bool LlanyLib::Basic::Objetos::String::startWith(const char& caracter) const
{
	bool resultado = false;
	if (&caracter == this->vector) resultado = true;
	else if (&caracter != nullptr && this->vector != nullptr) {
		if (this->count == 1)
			resultado = caracter == this->vector[0];
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWith(char const* const str) const
{
	bool resultado = false;
	if (str == this->vector) resultado = true;
	else if (str != nullptr && this->vector != nullptr) {
		size_t size = strlen(str);
		resultado = String::startWith(str, size);
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWith(const char* str, const size_t& size) const
{
	bool resultado = false;
	if (str == this->vector) resultado = true;
	else if (str != nullptr && this->vector != nullptr) {
		if (this->count >= size) {
			// Si el primer caracter coincide
			bool temp = (this->vector[0] == str[0]);
			for (size_t i = 1; i < size && temp; i++)
				temp = (this->vector[i] == str[i]);
			resultado = temp;
		}
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWith(const String& other) const
{
	bool resultado = false;
	if (other.vector == this->vector) resultado = true;
	else if (&other.vector != nullptr && this->vector != nullptr)
		resultado = String::startWith(other.vector, other.count);
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWithSimilar(const char& caracter) const
{
	bool resultado = false;
	if (&caracter == this->vector) resultado = true;
	else if (&caracter != nullptr && this->vector != nullptr) {
		if (this->count == 1)
			resultado = (CHARS->compareCharSimilar(&caracter, &this->vector[0]) == 0);
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWithSimilar(char const* const str) const
{
	bool resultado = false;
	if (str == this->vector) resultado = true;
	else if (str != nullptr && this->vector != nullptr) {
		size_t size = strlen(str);
		resultado = String::startWithSimilar(str, size);
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWithSimilar(const char* str, const size_t& size) const
{
	bool resultado = false;
	if (str == this->vector) resultado = true;
	else if (str != nullptr && this->vector != nullptr) {
		if (this->count >= size) {
			// Si el primer caracter coincide
			bool temp = (CHARS->compareCharSimilar(&this->vector[0], &str[0]) == 0);
			for (size_t i = 1; i < size && temp; i++)
				temp = (CHARS->compareCharSimilar(&this->vector[i], &str[i]) == 0);
			resultado = temp;
		}
	}
	return resultado;
}
bool LlanyLib::Basic::Objetos::String::startWithSimilar(const String& other) const
{
	bool resultado = false;
	if (other.vector == this->vector) resultado = true;
	else if (&other.vector != nullptr && this->vector != nullptr)
		resultado = String::startWithSimilar(other.vector, other.count);
	return resultado;
}
#pragma endregion
#pragma region Modificadores
void LlanyLib::Basic::Objetos::String::reverse()
{
	MEM->invertirBloque(this->vector, this->count - 1, sizeof(char));
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::String::getModifiedString(const Enum::ModificadorString& modif) const
{
	String* str = new String(*this);
	str->modifyString(modif);
	return str;
}
size_t LlanyLib::Basic::Objetos::String::modifyString(const Enum::ModificadorString& modif)
{
	size_t cambios = 0;
	if (this->vector != nullptr) {
		for (size_t i = 0; i < this->count; i++) {
			switch (modif) {
				case Enum::ModificadorString::CENSOREALL:
					break;
				case Enum::ModificadorString::TOUPPER:
					//if (LlanySimpleLib::cambiarMayus(&this->vector[i]) == 1)
					//	cambios++;
					break;
				case Enum::ModificadorString::TOLOWER:
					//if (LlanySimpleLib::cambiarMinus(&this->vector[i]) == 1)
					//	cambios++;
					break;
			}
		}
	}
	return cambios;
}
void LlanyLib::Basic::Objetos::String::clear()
{
	if (this->vector != nullptr)
		delete[] this->vector;
	this->vector = nullptr;
	this->count = 0;
}
#pragma endregion
#pragma region Conversiones
bool LlanyLib::Basic::Objetos::String::toBool() const
{
	return String::equals("True");
}
short LlanyLib::Basic::Objetos::String::toShort() const
{
	return 0;
}
unsigned short LlanyLib::Basic::Objetos::String::toUnsignedShort() const
{
	return 0;
}
int LlanyLib::Basic::Objetos::String::toInt() const
{
	return 0;
}
unsigned int LlanyLib::Basic::Objetos::String::toUnsignedInt() const
{
	return 0;
}
float LlanyLib::Basic::Objetos::String::toFloat() const
{
	return 0.0f;
}
double LlanyLib::Basic::Objetos::String::toDouble() const
{
	return 0.0;
}
long LlanyLib::Basic::Objetos::String::toLong() const
{
	return 0;
}
unsigned long LlanyLib::Basic::Objetos::String::toUnsignedLong() const
{
	return 0;
}
long long LlanyLib::Basic::Objetos::String::toLongLong() const
{
	return 0;
}
unsigned long long LlanyLib::Basic::Objetos::String::toUnsignedLongLong() const
{
	return 0;
}
size_t LlanyLib::Basic::Objetos::String::toSize_T() const
{
	return 0;
}
#pragma endregion
#pragma region Otros operators
char& LlanyLib::Basic::Objetos::String::operator[](const size_t& position) const THROW
{
	char* p = nullptr;
	if (this->vector != nullptr)
		if (this->count > position)
			p = &this->vector[position];
		else
			throw LlanyLib::Basic::Objetos::Excepcion("La posicion indicada debe de ser inferior al total", __FUNCTION__);
	else
		throw LlanyLib::Basic::Objetos::Excepcion("No hay ningun vector al que hacer referencia", __FUNCTION__);
	return *p;
}
const char* LlanyLib::Basic::Objetos::String::operator()() const
{
	char* p = nullptr;
	if (this->vector != nullptr)
		if (this->count > 0)
			p = &this->vector[0];
	return p;
}
char* LlanyLib::Basic::Objetos::String::get() const
{
	return this->vector;
}
#pragma endregion
