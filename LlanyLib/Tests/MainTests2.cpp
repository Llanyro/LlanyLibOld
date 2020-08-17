#include <iostream>

#include "../Logica/Basic/Gestores/GestorSingletons.hpp"
#include "../Logica/Basic/Singletons/StringPrinter.hpp"
#include "../Logica/Basic/Singletons/System.hpp"
#include "../Logica/Basic/Singletons/Chars.hpp"
#include "../Logica/Basic/Singletons/Files.hpp"
#include "../Logica/Basic/Singletons/JSONConversor.hpp"

#include "../Logica/Basic/Objetos/String.hpp"
#include "../Logica/Basic/Plantillas/Listas/LinkedList.hpp"
#include "../Logica/Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"
#include "../Logica/Basic/Plantillas/Nodos/NodoDosObjetosDosPunteros.hpp"

#include "../Logica/Math/Singletons/Random.hpp"

#include "../Logica/Juego/Objetos/Plantillas/Item.hpp"
#include "../Logica/Juego/Objetos/Plantillas/Contenedor.hpp"
#include "../Logica/Juego/Objetos/Items/Elementos/Hidrogeno.hpp"
#include "../Logica/Juego/Objetos/Items/Contenedores/BotellaPlastico.hpp"

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

void j1()
{
	LlanyLib::Juego::Items::Item item;
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


	//j1();
	j2();
	
	FREE_SINGLETONS;

	return 0;
}
