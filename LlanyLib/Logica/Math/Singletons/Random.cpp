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
size_t LlanyLib::Math::Singletons::Random::random() const
{
	return rand();
}
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
	return (char)Random::range(ASCII_CHARS);
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
			c = (char)Random::range(33, 43);
			break;
		case 1:
			c = (char)Random::range(58, 65);
			break;
		case 2:
			c = (char)Random::range(128, 255);
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
// Adapted from https://gist.github.com/ne-sachirou/882192
// Adaptado de https://gist.github.com/fernandomv3/46a6d7656f50ee8d39dc
// std::rand() can be replaced with other algorithms as Xorshift for better perfomance
// Random seed must be initialized by user
/*	Testeos
	00000120-0000-400C-8000-000E40000000
	00000F70-0000-4001-9000-000001200000
	000000B3-0000-4000-8860-000000600000
*/
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Singletons::Random::uuid() const
{
	Basic::Objetos::StringBuilder buffer;
	char c[] = ABECEDARIO_NUMS_1;

	int rnd = 0;
	int r = 0;

	for (int i = 0; i < 36; i++) {
		if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
			if (rnd <= 0x02) {
				rnd = 0x2000000 + (rand() * 0x1000000) | 0;
			}
			rnd >>= 4;
			buffer += c[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
		}
		else if (i == 14)
			buffer += '4';
		else
			buffer += '-';
	}
	return buffer.build();
}
#pragma endregion
