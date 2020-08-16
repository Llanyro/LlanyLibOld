#include "Random.hpp"

#include <time.h>
#include <stdlib.h>

#include <assert.h>

#include "BaseABC.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/LibreriasSimples/ASCII_Defines.h"
#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#pragma region Constructores
LlanyLib::Math::Singletons::Random::Random()
{
	srand(time(NULL));
	Random::subscribir(Random::freeInstancia);
}
LlanyLib::Math::Singletons::Random::~Random() {}
#pragma endregion
#pragma region Rangos
size_t LlanyLib::Math::Singletons::Random::range(const size_t& min, const size_t& max) const
{
	size_t resultado = 0;
	if (&min != nullptr && &max != nullptr)
		resultado = ((rand() % (max - min)) + min);
	else if (&min != nullptr)
		resultado = min;
	else if (&max != nullptr)
		resultado = max;
	return resultado;
}
size_t LlanyLib::Math::Singletons::Random::range(const size_t& value) const
{
	size_t resultado = 0;
	if (&value != nullptr)
		resultado = (rand() % value);
	return resultado;
}
char LlanyLib::Math::Singletons::Random::getRandomChar() const
{
	return Random::range(ASCII_CHARS);
}
char LlanyLib::Math::Singletons::Random::getRandomCharAbecedario() const
{
	return BASE_ABC->toChar(BASE_ABC->toChar(rand()));
}
char LlanyLib::Math::Singletons::Random::getRandomCharEspecial() const
{
	char c = 'X';
	switch (Random::range(3))
	{
		case 0:
			c = Random::range(33, 43);
			break;
		case 1:
			c = Random::range(58, 65);
			break;
		case 2:
			c = Random::range(128, 255);
			break;
	}

	return c;
}
#pragma endregion
#pragma region Strings
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::Random::stringAbecedario(const size_t& size) const
{
	assert(&size != nullptr);
	assert(size > 0);
	Basic::Objetos::StringBuilder buffer;
	for (size_t i = 0; i < size; i++)
		buffer += Random::getRandomCharAbecedario();
	return buffer.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::Random::stringCompleto(const size_t& size) const
{
	assert(&size != nullptr);
	assert(size > 0);
	Basic::Objetos::StringBuilder buffer;
	for (size_t i = 0; i < size; i++)
		buffer += Random::getRandomChar();
	return buffer.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::Random::stringEspeciales(const size_t& size) const
{
	assert(&size != nullptr);
	assert(size > 0);
	Basic::Objetos::StringBuilder buffer;
	for (size_t i = 0; i < size; i++)
		buffer += Random::getRandomCharEspecial();
	return buffer.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::Random::stringCaracteresEspecificos(const size_t& size, Basic::Templates::Listas::LinkedList<char>* listaCaracteres) const
{
	assert(&size != nullptr);
	assert(size > 0);
	Basic::Objetos::StringBuilder buffer;
	for (size_t i = 0; i < size; i++)
		buffer += *listaCaracteres->get(Random::range(listaCaracteres->length()));
	return buffer.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::Random::stringCaracteresEspecificosClear(const size_t& size, Basic::Templates::Listas::LinkedList<char>* listaCaracteres) const
{
	Basic::Objetos::String* str = Random::stringCaracteresEspecificos(size, listaCaracteres);
	delete listaCaracteres;
	return nullptr;
}
#pragma endregion
