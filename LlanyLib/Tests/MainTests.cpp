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
#include "../Logica/Net/Objetos/ConnectionSocket.hpp"
#include "../Logica/Net/Singletons/SocketController.hpp"
#include "../Logica/Net/Objetos/HttpRequest.hpp"
#include "../Logica/Net/Objetos/HTTPResponse.hpp"
#include "../Logica/Net/Enums/HTTPEnum.hpp"
#pragma endregion

using namespace std;

#pragma region Net
void n1()
{
	LlanyLib::Net::Objetos::ServerSocket* s = new LlanyLib::Net::Objetos::ServerSocket("9090");
	if (s->acceptClient()) {
		LlanyLib::Net::Objetos::ConnectionSocket* c = s->getConnectionSocket();
		SOCKET_CONTROLLER->printTest(c);
		delete c;
	}
	delete s;
}
void n2()
{
	LlanyLib::Net::Objetos::ServerSocket* s = new LlanyLib::Net::Objetos::ServerSocket("9090");
	LlanyLib::Net::Objetos::HttpRequest* req = nullptr;
	if (s->acceptClient()) {
		LlanyLib::Net::Objetos::ConnectionSocket* c = s->getConnectionSocket();
		req = SOCKET_CONTROLLER->getHttpRequest(c, LlanyLib::Net::Enum::ResponseProcess::FULL);
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
		STRING_PRINTER->print("Headers:\n");
		const LlanyLib::Basic::Objetos::Stringictionary* dict = req->getHeaders();
		for (size_t i = 0; i < dict->getNumElements(); i++) {
			STRING_PRINTER->print(*dict->getKeyLow(i));
			STRING_PRINTER->print(':');
			STRING_PRINTER->print(' ');
			STRING_PRINTER->printLn(*dict->getValueLow(i));
			//STRING_PRINTER->printValueLn((*dict->getValueLow(i)).operator[](0));
		}

		STRING_PRINTER->print("Parametros:\n");
		dict = req->getParametros();
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
		delete c;
	}
	delete s;
}
void n3()
{
	LlanyLib::Net::Objetos::HttpResponse* resp = new LlanyLib::Net::Objetos::HttpResponse();
	resp->setContent(FILES->leerFicheroFopen("./Web/Templates/chat.html"));
	STRING_PRINTER->printLnClear(resp->toString());
	delete resp;
}
void n4()
{
	LlanyLib::Net::Objetos::ServerSocket* s = new LlanyLib::Net::Objetos::ServerSocket("9090");
	LlanyLib::Net::Objetos::HttpRequest* req = nullptr;
	if (s->acceptClient()) {
		LlanyLib::Net::Objetos::ConnectionSocket* c = s->getConnectionSocket();
		req = SOCKET_CONTROLLER->getHttpRequest(c, LlanyLib::Net::Enum::ResponseProcess::FULL);
		STRING_PRINTER->printLn(req->getPeticion());
		STRING_PRINTER->printLn(req->getRoot());
		STRING_PRINTER->printLn(req->getVersion());
		STRING_PRINTER->print("Headers:\n");
		const LlanyLib::Basic::Objetos::Stringictionary* dict = req->getHeaders();
		for (size_t i = 0; i < dict->getNumElements(); i++) {
			STRING_PRINTER->print(*dict->getKeyLow(i));
			STRING_PRINTER->print(':');
			STRING_PRINTER->print(' ');
			STRING_PRINTER->printLn(*dict->getValueLow(i));
		}
		STRING_PRINTER->print("Parametros:\n");
		dict = req->getParametros();
		for (size_t i = 0; i < dict->getNumElements(); i++) {
			STRING_PRINTER->print(*dict->getKeyLow(i));
			STRING_PRINTER->print(':');
			STRING_PRINTER->print(' ');
			STRING_PRINTER->printLn(*dict->getValueLow(i));
		}
		delete req;


		LlanyLib::Net::Objetos::HttpResponse* resp = new LlanyLib::Net::Objetos::HttpResponse();
		resp->setContent(FILES->leerFicheroFopenFseek("./Web/Templates/chat.html"));
		SOCKET_CONTROLLER->sendHttpResponse(c, resp);
		delete resp;
		delete c;
	}
	delete s;
}

#define TEMPLATE "./Web/Templates/"
#define STATIC "./Web/Static/"

void n5()
{
	int num = 0;
	LlanyLib::Net::Objetos::ServerSocket* s = new LlanyLib::Net::Objetos::ServerSocket("9090");
	LlanyLib::Net::Objetos::HttpRequest* req = nullptr;

	LlanyLib::Basic::Objetos::String* google = FILES->leerFicheroFopen("./Web/Templates/google.html");

	//while (s->acceptClient() && num < 3) {
	if (s->acceptClient() && num < 3) {
		// Obtenemos el socket
		// Preparado para si se quiere usar por thread
		LlanyLib::Net::Objetos::ConnectionSocket* c = s->getConnectionSocket();

		// Obtenemos la request segun el socket
		req = SOCKET_CONTROLLER->getHttpRequest(c, LlanyLib::Net::Enum::ResponseProcess::FULL);
		
		// Printeamos (No necesario luego)
		STRING_PRINTER->printLn(req->getPeticion());
		STRING_PRINTER->printLn(req->getRoot());
		STRING_PRINTER->printLn(req->getVersion());
		STRING_PRINTER->print("Headers:\n");
		const LlanyLib::Basic::Objetos::Stringictionary* dict = req->getHeaders();
		for (size_t i = 0; i < dict->getNumElements(); i++) {
			STRING_PRINTER->print(*dict->getKeyLow(i));
			STRING_PRINTER->print(':');
			STRING_PRINTER->print(' ');
			STRING_PRINTER->printLn(*dict->getValueLow(i));
		}
		STRING_PRINTER->print("Parametros:\n");
		dict = req->getParametros();
		for (size_t i = 0; i < dict->getNumElements(); i++) {
			STRING_PRINTER->print(*dict->getKeyLow(i));
			STRING_PRINTER->print(':');
			STRING_PRINTER->print(' ');
			STRING_PRINTER->printLn(*dict->getValueLow(i));
		}

		LlanyLib::Net::Objetos::HttpResponse* resp = new LlanyLib::Net::Objetos::HttpResponse();

		if (req->getRoot()->equals('/') || req->getRoot()->similar("/index")) {
			resp->setResponseCode(201);
			resp->setResponse("De puta madre!");
			SOCKET_CONTROLLER->sendHttpTemplate(c, resp, "chat.html");
		}
		else {
			resp->setResponseCode(200);
			resp->setResponse("Not Found");
			resp->setContent(google);
			SOCKET_CONTROLLER->sendHttpResponse(c, resp);
			//SOCKET_CONTROLLER->sendHttpTemplate(c, resp, "google.html");
		}
		//else if (req->getRoot()->similar("/index")) {
		//}

		SOCKET_CONTROLLER->closeConnectionSocket(c);

		// Liberaciones de objetos/memoria
		delete req;
		delete resp;
		delete c;
		num++;
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
	//n2();
	//n3();
	//n4();
	n5();


	FREE_SINGLETONS;

	return 0;
}