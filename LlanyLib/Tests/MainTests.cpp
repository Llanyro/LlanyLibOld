#include <iostream>

#pragma region Basic
#include "../Logica/Basic/Enumerators/DateEnum.hpp"

#include "../Logica/Basic/LibreriasSimples/ASCII_Defines.h"

#include "../Logica/Basic/Gestores/GestorSingletons.hpp"

#include "../Logica/Basic/Plantillas/Listas/LinkedList.hpp"
#include "../Logica/Basic/Plantillas/Dictionary/DictionaryLinkedList.hpp"

#include "../Logica/Basic/Singletons/StringPrinter.hpp"
#include "../Logica/Basic/Singletons/System.hpp"
#include "../Logica/Basic/Singletons/Chars.hpp"
#include "../Logica/Basic/Singletons/Files.hpp"
#include "../Logica/Basic/Singletons/JSONConversor.hpp"
#include "../Logica/Basic/Singletons/DateController.hpp"

#include "../Logica/Basic/Objetos/Date.hpp"
#include "../Logica/Basic/Objetos/String.hpp"
#include "../Logica/Basic/Objetos/StringBuilder.hpp"
#include "../Logica/Basic/Objetos/Stringctionary.hpp"
#pragma endregion
#pragma region Net
#include "../Logica/Net/Objetos/ServerSocket.hpp"
#include "../Logica/Net/Singletons/SocketController.hpp"
#include "../Logica/Net/Objetos/HttpRequest.hpp"
#include "../Logica/Net/Enums/HTTPEnum.hpp"
#pragma endregion

using namespace std;

#pragma region Net
void n1()
{
	LlanyLib::Net::Objetos::ServerSocket* s = new LlanyLib::Net::Objetos::ServerSocket("9090");
	if (s->acceptClient())
		SOCKET_CONTROLLER->printTest(s);
	delete s;
}
void n2()
{
	LlanyLib::Net::Objetos::ServerSocket* s = new LlanyLib::Net::Objetos::ServerSocket("9090");
	LlanyLib::Net::Objetos::HttpRequest* req = nullptr;
	if (s->acceptClient()) {
		req = SOCKET_CONTROLLER->getHttpRequest(s, LlanyLib::Net::Enum::ResponseProcess::FULL);
		STRING_PRINTER->printLn(req->getPeticion());
		STRING_PRINTER->printLn(req->getRoot());
		STRING_PRINTER->printLn(req->getVersion());
		//
		//STRING_PRINTER->printLn(req->getHost());
		//STRING_PRINTER->printLn(req->getConnection());
		//
		//STRING_PRINTER->printBoolLn(req->getUpgradeInsecureRequests());
		//const LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<
		//	LlanyLib::Basic::Objetos::String*,
		//	LlanyLib::Basic::Objetos::String*>* dict = req->getParametros();
		const LlanyLib::Basic::Objetos::Stringictionary* dict = req->getParametros();

		for (size_t i = 0; i < dict->getNumElements(); i++) {
			STRING_PRINTER->print(*dict->getKeyLow(i));
			STRING_PRINTER->print(':');
			STRING_PRINTER->print(' ');
			STRING_PRINTER->printLn(*dict->getValueLow(i));
		}


		//STRING_PRINTER->printLn(req->getUserAgent());

		//for (size_t i = 0; i < req->getNumAcceptTypes(); i++)
		//	STRING_PRINTER->printLn(req->getAcceptedType(i));

		//for (size_t i = 0; i < req->getNumOther(); i++)
		//	STRING_PRINTER->printLn(req->getOtherStartWithSimilar(i

		delete req;
	}
	delete s;
}
#pragma endregion

int main()
{
	//LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<char, int>* dict = new
	//	LlanyLib::Basic::Templates::Diccionarios::DictionaryLinkedList<char, int>();
	//dict->getKey(0);
	//dict->geValue(0);
	//delete dict;

	//n1();
	n2();

	FREE_SINGLETONS;

	return 0;
}