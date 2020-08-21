#include <iostream>

#include "../Logica/Basic/Gestores/GestorSingletons.hpp"
#include "../Logica/Basic/Singletons/StringPrinter.hpp"
#include "../Logica/Basic/Singletons/System.hpp"
#include "../Logica/Basic/Singletons/Chars.hpp"
#include "../Logica/Basic/Singletons/Files.hpp"
#include "../Logica/Basic/Singletons/JSONConversor.hpp"

#include "../Logica/Basic/Objetos/String.hpp"
#include "../Logica/Basic/Objetos/StringBuilder.hpp"
#include "../Logica/Basic/LibreriasSimples/ASCII_Defines.h"
#include "../Logica/Basic/Plantillas/Listas/LinkedList.hpp"
#include "../Logica/Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../Logica/Basic/Plantillas/Nodos/NodoDosObjetosDosPunteros.hpp"

#include "../Logica/Math/Objetos/Unit.hpp"
#include "../Logica/Math/Enums/UnitEnum.hpp"
#include "../Logica/Math/Singletons/Math.hpp"
#include "../Logica/Math/Singletons/Random.hpp"
#include "../Logica/Math/Singletons/UnitConversor.hpp"

#include "../Logica/Juego/Objetos/Item.hpp"
#include "../Logica/Juego/Objetos/Contenedor.hpp"
#include "../Logica/Juego/Items/Elementos/Hidrogeno.hpp"
#include "../Logica/Juego/Items/Contenedores/BotellaPlastico.hpp"

using namespace std;

/*#include "../Logica/Basic/Objetos/Logger.hpp"

class Test : public LlanyLib::Basic::Objetos::Logger
{
	public:
		Test() : Logger(new LlanyLib::Basic::Objetos::String("Test")){}
		~Test(){}
};

void tt()
{
	//Test test;
	//test.logClear(new LlanyLib::Basic::Objetos::String("Testando log info"));
	//test.logWarningClear(new LlanyLib::Basic::Objetos::String("Testando log warning"));
	//test.logErrorClear(new LlanyLib::Basic::Objetos::String("Testando log error"));
}*/

void t1()
{
	LlanyLib::Basic::Objetos::String* str = new LlanyLib::Basic::Objetos::String("Hola mundo");
	LlanyLib::Basic::Templates::Listas::LinkedList<
		LlanyLib::Basic::Objetos::String*>*list = str->split(' ');

	cout << "Starts: " << str->startWith("hola") << endl;

	STRING_PRINTER->printLnClear(str);
	STRING_PRINTER->printClear(list);
}

void t2()
{
	LlanyLib::Basic::Objetos::String* str = 
		new LlanyLib::Basic::Objetos::String("C:\\Users\\Fran-Administrador\\source\\repos\\LlanyLib\\LlanyLib");
	LlanyLib::Basic::Templates::Listas::LinkedList<char>* sep = new LlanyLib::Basic::Templates::Listas::LinkedList<char>();
	sep->add('/');
	sep->add('\\');

	LlanyLib::Basic::Templates::Listas::LinkedList<
		LlanyLib::Basic::Objetos::String*>* list = str->splitClear(sep);

	STRING_PRINTER->printLnClear(list);
	STRING_PRINTER->printLnClear(str);
}

void t3()
{
	//STRING_PRINTER->printLnClear(CHARS->toString(true));
	//STRING_PRINTER->printLnClear(CHARS->toString(100));
	//STRING_PRINTER->printLnClear(CHARS->toString(100.0));
	//STRING_PRINTER->printLnClear(CHARS->toString(100.00f));


	STRING_PRINTER->printLnClear(SYSTEM->horaFechaNumericos());
}

void t4()
{
	STRING_PRINTER->printLnClear(SYSTEM->origenPrograma());
}

void t5()
{
	LlanyLib::Basic::Objetos::String* str1 = SYSTEM->origenPrograma();
	//LlanyLib::Basic::Objetos::String* str2 = new LlanyLib::Basic::Objetos::String("./Carpeta1/Carpeta2/Carpeta3");
	LlanyLib::Basic::Objetos::String* str2 = new LlanyLib::Basic::Objetos::String("/Carpeta1/Carpeta2/Carpeta3");
	LlanyLib::Basic::Objetos::String* str3 = str1->operator+(*str2);

	STRING_PRINTER->printLnClear(str1);
	STRING_PRINTER->printLnClear(str2);
	//STRING_PRINTER->printLnClear(str3);

	STRING_PRINTER->printLnClear(FILES->crearPathClear(str3));
	//delete str3;
}

void t6()
{
	LlanyLib::Basic::Objetos::String* str1 = new LlanyLib::Basic::Objetos::String("Str content");
	STRING_PRINTER->printLnClear(str1->operator+(" Hola mundo"));
	STRING_PRINTER->printLnClear(str1->operator+('A'));
	delete str1;
}

void t7()
{
	LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<
		LlanyLib::Basic::Objetos::String*,
		LlanyLib::Basic::Objetos::String*>* dict = new 
		LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<
			LlanyLib::Basic::Objetos::String*,
			LlanyLib::Basic::Objetos::String*>();

	dict->add(
		new LlanyLib::Basic::Objetos::String("Clave"),
		new LlanyLib::Basic::Objetos::String("Valor"));
	dict->add(
		new LlanyLib::Basic::Objetos::String("name"),
		new LlanyLib::Basic::Objetos::String("Chinesium"));
	dict->add(
		new LlanyLib::Basic::Objetos::String("DurabilidadMax"),
		new LlanyLib::Basic::Objetos::String("2"));
	dict->add(
		new LlanyLib::Basic::Objetos::String("Durabilidad"),
		new LlanyLib::Basic::Objetos::String("1"));

	LlanyLib::Basic::Objetos::String* json = JSON_CONVERSOR->toJSONClear(dict);

	STRING_PRINTER->printLn(json);

	LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<
		LlanyLib::Basic::Objetos::String*,
		LlanyLib::Basic::Objetos::String*>* dict2 = JSON_CONVERSOR->toDictClear(json);
	LlanyLib::Basic::Templates::Nodos::NDODP<
		LlanyLib::Basic::Objetos::String*,
		LlanyLib::Basic::Objetos::String*>* temp = nullptr;

	for (size_t i = 0; i < dict2->length(); i++) {
		temp = dict2->getObject(i);

		STRING_PRINTER->printLnClear(temp->getObject0());
		STRING_PRINTER->print('\t');
		STRING_PRINTER->printLnClear(temp->getObject1());
		STRING_PRINTER->print('\n');
	}
	delete dict2;

}

void t8()
{
	STRING_PRINTER->printClear(RANDOM->uuid());
}

/*
int charToIntHex(const char& caracter)
{
	int resultado = 0;

	if (caracter >= '0' && caracter <= '9')
		resultado = caracter - '0';
	else if (caracter >= 'A' && caracter <= 'F')
		resultado = caracter - 'A' + 10;
	else if (caracter >= 'a' && caracter <= 'f')
		resultado = caracter - 'a' + 10;

	return resultado;
}

char intHexToChar(const int& val)
{
	char resultado = 0;

	if (val < 10) {
		resultado = NUMS + val;
	}
	else if (val < 16) {
		resultado = MAYUS + val - 10;
	}
	else {
		resultado = 'F';
	}

	return resultado;
}

#define BIN_TO_HEX_GROUP_SIZE 4

#include "../Logica/Math/Libs/MathTypes.h"

// Bin to hex
/// OK
char binByteToHex(char const* const val, const size_t& size)
{
	char c = 0;
	for (size_t i = 0; i < size; i++)
		if (val[i] == '1')
			c += (int)MATH->elevarValor(2, (size - 1) - i);
	return c;
}
/// OK
LlanyLib::Basic::Objetos::String* binToHex(char const* const val)
{
	LlanyLib::Basic::Objetos::StringBuilder buffer;
	char* arr_p = (char*)val;
	size_t size_bin_c = strlen(val);
	size_t grupos = size_bin_c / BIN_TO_HEX_GROUP_SIZE;
	size_t grupoMenorSize = size_bin_c % BIN_TO_HEX_GROUP_SIZE;

	if (grupoMenorSize != 0) {
		buffer += binByteToHex(arr_p, grupoMenorSize);
		arr_p += grupoMenorSize;
	}

	for (size_t i = 0; i < grupos; i++) {
		buffer += binByteToHex(arr_p, BIN_TO_HEX_GROUP_SIZE);
		arr_p += BIN_TO_HEX_GROUP_SIZE;
	}

	return buffer.build();
}

// Bin to dec
long_t binToDec(char const* const val)
{
	long_t result = 0;
	size_t size = strlen(val);
	for (size_t i = 0; i < size; i++)
		if (val[i] == '1')
			result += (long_t)MATH->elevarValor(2, (size - 1) - i);
	return result;
}


// Decimal to hex
/// OK
LlanyLib::Basic::Objetos::String* decToHex(const long_t& val)
{
	LlanyLib::Basic::Objetos::StringBuilder buffer;

	long_t dec_temp = val;
	long_t coef = 0;
	long_t resto = 0;

	while (dec_temp > 0) {
		coef = dec_temp / 16;
		resto = dec_temp % 16;
		if (coef == 0) {
			dec_temp = 0;
			buffer += (char)resto;
		}
		else {
			dec_temp = coef;
			buffer += (char)resto;
		}
	}
	LlanyLib::Basic::Objetos::String* result = buffer.build();
	result->reverse();
	return result;
}
LlanyLib::Basic::Objetos::String* decToHex(char const* const val)
{
	return nullptr;
}

// Oct to bin
LlanyLib::Basic::Objetos::String* octToBin(char const* const val)
{
	LlanyLib::Basic::Objetos::StringBuilder buffer;
	size_t size_oct_c = strlen(val);
	for (size_t i = 0; i < size_oct_c; i++) {
		switch (val[i]) {
			case '0':
				buffer.add("0000");
				break;
			case '1':
				buffer.add("0001");
				break;
			case '2':
				buffer.add("0010");
				break;
			case '3':
				buffer.add("0011");
				break;
			case '4':
				buffer.add("0100");
				break;
			case '5':
				buffer.add("0101");
				break;
			case '6':
				buffer.add("0110");
				break;
			case '7':
				buffer.add("0111");
				break;
			case '8':
				buffer.add("1000");
				break;
			case '9':
				buffer.add("1001");
				break;
			case 'A':
				buffer.add("1010");
				break;
			case 'B':
				buffer.add("1011");
				break;
			case 'C':
				buffer.add("1100");
				break;
			case 'D':
				buffer.add("1101");
				break;
			case 'E':
				buffer.add("1110");
				break;
			case 'F':
				buffer.add("1111");
				break;
			default:
				buffer.add("0000");
				break;
		}
	}
	return buffer.build();
}

// Oct to dec
/// OK
long_t octToDec(char const* const val)
{
	long_t result = 0;
	size_t size = strlen(val);
	for (size_t i = 0; i < size; i++)
			result += (long_t)MATH->elevarValor(8, (size - 1) - i) * charToIntHex(val[i]);
	return result;
}

// Oct to hex
/// OK
LlanyLib::Basic::Objetos::String* octToHex(char const* const val)
{
	//LlanyLib::Basic::Objetos::String* bin_val = octToBin(val);
	//LlanyLib::Basic::Objetos::String* hex_val = binToHex(bin_val->get());
	//delete bin_val;
	//return hex_val;
	long_t dec = octToDec(val);
	return decToHex(dec);
}

void printHex(LlanyLib::Basic::Objetos::String* str)
{
	for (size_t i = 0; i < str->length() - 1; i++)
		putchar(intHexToChar(str->get()[i]));
	putchar('\n');
	delete str;
}

void m1()
{
	// 39
	char dec_c[] = "57";
	char oct_c[] = "71";

	//LlanyLib::Basic::Objetos::String* hex_f_dec_c = nullptr;
	//LlanyLib::Basic::Objetos::String* hex_f_oct_c = nullptr;

	LlanyLib::Basic::Objetos::StringBuilder buffer;
	
	size_t size_dec_c = strlen(dec_c);
	size_t size_oct_c = strlen(oct_c);

	/*long long dec_temp = dec_n;
	size_t coef = 0;
	size_t resto = 0;

	while (dec_temp > 0) {
		coef = dec_temp / 16;
		resto = dec_temp % 16;

		if (coef == 0) {
			dec_temp = 0;
			buffer += resto;
		}
		else {
			dec_temp = resto;
			buffer += coef;
		}
	}

	hex_f_dec_n = buffer.build();

	for (size_t i = 0; i < hex_f_dec_n->length() - 1; i++) {
		putchar(intHexToChar(hex_f_dec_n->get()[i]));
	}
	putchar('\n');
	delete hex_f_dec_n;


}

void m2()
{
	char oct_c[] = "71";
	size_t size_oct_c = strlen(oct_c);

	LlanyLib::Basic::Objetos::StringBuilder buffer;
	for (size_t i = 0; i < size_oct_c; i++) {
		switch (oct_c[i]) {
			case '0':
				buffer.add("0000");
				break;
			case '1':
				buffer.add("0001");
				break;
			case '2':
				buffer.add("0010");
				break;
			case '3':
				buffer.add("0011");
				break;
			case '4':
				buffer.add("0100");
				break;
			case '5':
				buffer.add("0101");
				break;
			case '6':
				buffer.add("0110");
				break;
			case '7':
				buffer.add("0111");
				break;
			case '8':
				buffer.add("1000");
				break;
			case '9':
				buffer.add("1001");
				break;
			case 'A':
				buffer.add("1010");
				break;
			case 'B':
				buffer.add("1011");
				break;
			case 'C':
				buffer.add("1100");
				break;
			case 'D':
				buffer.add("1101");
				break;
			case 'E':
				buffer.add("1110");
				break;
			case 'F':
				buffer.add("1111");
				break;
			default:
				buffer.add("0000");
				break;
		}
	}

	LlanyLib::Basic::Objetos::String* bin_f_oct = buffer.build();
	LlanyLib::Basic::Objetos::String* hex_f_oct_c = binToHex(bin_f_oct->get());

	for (size_t i = 0; i < bin_f_oct->length() - 1; i++)
		putchar(bin_f_oct->get()[i]);
	putchar('\n');

	for (size_t i = 0; i < hex_f_oct_c->length() - 1; i++)
		putchar(intHexToChar(hex_f_oct_c->get()[i]));
	putchar('\n');

	delete bin_f_oct;
	delete hex_f_oct_c;

	/*LlanyLib::Basic::Objetos::String* hex_f_oct_c = nullptr;

	long long dec_temp = 213;
	long_t coef = 0;
	long_t resto = 0;

	while (dec_temp > 0) {
		coef = dec_temp / 2;
		resto = dec_temp % 2;
		if (coef == 0) {
			dec_temp = 0;
			buffer += (char)resto;
		}
		else {
			dec_temp = coef;
			buffer += (char)resto;
		}
	}
	hex_f_oct_c = buffer.build();
	for (size_t i = 0; i < hex_f_oct_c->length() - 1; i++) {
		putchar(intHexToChar(hex_f_oct_c->get()[i]));
	}
	putchar('\n');
	delete hex_f_oct_c;
}
*/

void printHex(LlanyLib::Basic::Objetos::String* str)
{
	for (size_t i = 0; i < str->length() - 1; i++)
		putchar(UNIT_CONVERSOR->intHexToChar(str->get()[i]));
	putchar('\n');
	delete str;
}

void m3()
{
	//printHex(UNIT_CONVERSOR->binToRawHex("11111"));
	printHex(UNIT_CONVERSOR->binToRawHex("101011001110100100"));
	//printHex(UNIT_CONVERSOR->rawDecToRawHex(169323));
	//printHex(UNIT_CONVERSOR->octToRawHex("40"));
	//printHex(UNIT_CONVERSOR->rawDecToRawHex(16));
	//cout << UNIT_CONVERSOR->binToRawDec("101011001110100100") << endl;;

	//cout << UNIT_CONVERSOR->decToRawDec("100250") << endl;

	LlanyLib::Math::Objetos::Unit unit("101011001110100100", LlanyLib::Math::Enum::UnitType::Binary);
	printHex(unit.getHex());
}


void j1()
{
	LlanyLib::Juego::Objetos::Item item;
	STRING_PRINTER->printLnClear(item.toJSON());

	LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno hidrogeno;
	STRING_PRINTER->printLnClear(hidrogeno.toJSON());
}

void j2()
{
	LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico botella;
	STRING_PRINTER->printLnClear(botella.toJSONBuilder());
}

int main()
{
	//if (NULL == nullptr)
	//	cout << "Son iguales\n";
	//else
	//	cout << "No son iguales\n";


	//t1();
	//t2();
	//t3();
	//t4();
	//t5();
	//tt();
	//t6();
	//t7();
	//t8();

	//m1();
	//m2();
	m3();


	//j1();
	//j2();
	
	FREE_SINGLETONS;

	return 0;
}
