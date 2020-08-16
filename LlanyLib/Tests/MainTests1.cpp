//#include "../Logica/Plantillas/Listas/LinkedListAuto.hpp"
#include "../Logica/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../Logica/Plantillas/Listas/All.hpp"
#include "../Logica/Objetos/StringSimple.h"

#include "../Logica/LibreriasSimples/File.h"
#include "../Logica/LibreriasSimples/String.h"
#include "../Logica/LibreriasSimples/AdvancedString.h"

#include <iostream>

using namespace std;

void t1()
{
	LlanyLib::Templates::Listas::LinkedList<size_t> listaEnteros;
	for (size_t i = 0; i < 10; i++) {
		listaEnteros.add(rand() % 10);

		for (size_t i = 0; i < listaEnteros.getCount(); i++) {
			try {
				std::cout << listaEnteros[i] << " ";
			}
			CATCH{
				e.print();
				std::cout << "Error al intentar extraer el valor de la posicion " << i << std::endl;
			}
		}
		std::cout << std::endl;
	}

	size_t pos = 0;

	if (listaEnteros.find(8, &pos)) std::cout << "Pos del valor "<< pos << ": " << pos << std::endl;
	else std::cout << "No se ha encontrado el objeto en la lista" << std::endl;


	/*for (size_t i = 0; i < listaEnteros.getCount(); i++) {
		try {
			std::cout << listaEnteros[i] << " ";
		}
		CATCH{
			e.print();
			std::cout << "Error al intentar extraer el valor de la posicion " << i << std::endl;
		}
	}*/
}

void t2()
{
	LlanyLib::Templates::Diccionarios::DictionaryLinkedList<char, size_t> dict;
	for (size_t i = 0; i < 10; i++) {
		dict.add('a' + i, i);
	}

	std::cout << "Valor del caracter 'c' " << dict['c'] << std::endl;



}

void t3()
{
	LlanyLib::Templates::Listas::Array<char> vec(11, 0);
	vec.add("Hola mundo", 11);
	for (size_t i = 0; i < vec.getCount(); i++)
		std::cout << vec[i] << " ";

}

void t4()
{
	LlanyLib::Objetos::StringSimple str("Hola mundo");
	LlanyLib::Objetos::StringSimple str2 = str.getModifiedString(LlanyLib::Enum::ModificadorString::TOUPPER);
	LlanyLib::Objetos::StringSimple str3 = str.getModifiedString(LlanyLib::Enum::ModificadorString::TOLOWER);

	cout << str() << endl;
	cout << str2() << endl;
	cout << str3() << endl;


}

void t5()
{
	LlanySimpleLib::String* str = LlanySimpleLib::newString("C:\\Users/Fran-Administrador\\source/repos");
	
	LlanySimpleLib::escribirFicheroClear("./tescarpt/testfile.txt", str);
	
	LlanyLib::Templates::Listas::LinkedList<char> sep;
	sep.add('\\');
	sep.add('/');
	
	LlanyLib::Templates::Listas::LinkedList<LlanySimpleLib::String*> list = LlanySimpleLib::split(str, sep);

	LlanySimpleLib::deleteString(str);

	for (size_t i = 0; i < list.getCount(); i++) {
		LlanySimpleLib::printf(list[i]);
		std::cout << endl;
		LlanySimpleLib::deleteString(list[i]);
	}
}

void t6()
{
	LlanySimpleLib::String* str1 = LlanySimpleLib::newString("Hola mundo");
	LlanySimpleLib::String* str2 = LlanySimpleLib::newString("Hola test");

	LlanySimpleLib::String* str = LlanySimpleLib::operatorSum(str1, str2);

	LlanySimpleLib::printf(str1);
	LlanySimpleLib::printf(str2);
	LlanySimpleLib::printf(str);

	LlanySimpleLib::deleteString(str);
	LlanySimpleLib::deleteString(str1);
	LlanySimpleLib::deleteString(str2);
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
	t6();


	return 0;
}


