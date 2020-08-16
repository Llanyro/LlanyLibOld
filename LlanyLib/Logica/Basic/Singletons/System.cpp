#include "System.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "Chars.hpp"
#include "../Objetos/String.hpp"
#include "../Objetos/StringBuilder.hpp"
#include "../Enumerators/SystemCodes.h"

LlanyLib::Basic::Singletons::System::System() { System::subscribir(System::freeInstancia); }
LlanyLib::Basic::Singletons::System::~System(){}

#pragma region Time
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::System::horaFechaNumericos() const
{
	time_t now = time(0);
	#ifdef _WIN32
	tm* ltm = new tm();
	localtime_s(ltm, &now);
	#elif __unix__
	tm* ltm = localtime(&now);
	#endif // _WIN32
	Objetos::StringBuilder fecha;
	// Añadimos el dia al buffer
	LlanyLib::Basic::Objetos::String* temp = CHARS->toString(ltm->tm_mday);
	fecha.addClear(temp);
	fecha.add('/');
	// Añadimos el mes
	temp = CHARS->toString(1 + ltm->tm_mon);
	fecha.addClear(temp);
	fecha.add('/');
	// Añadimos el año
	temp = CHARS->toString(1900 + ltm->tm_year);
	fecha.addClear(temp);
	fecha.add(' ');
	// Añadimos la hora
	temp = CHARS->toString(ltm->tm_hour);
	fecha.addClear(temp);
	fecha.add(':');
	// Añadimos el minuto
	temp = CHARS->toString(ltm->tm_min);
	fecha.addClear(temp);
	fecha.add(':');
	// Añadimos el segundo
	temp = CHARS->toString(ltm->tm_sec);
	fecha.addClear(temp);
	delete ltm;
	return fecha.build();
}
#pragma endregion
#pragma region Commands
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::System::ejecutarCommand(const Objetos::String* command) const
{
	LlanyLib::Basic::Objetos::String* result = nullptr;
	if (command != nullptr && command->length() > 0)
	{
		Objetos::StringBuilder buffer;
		FILE* process = nullptr;

		#ifdef _WIN32
		process = _popen(command->get(), "r");
		#elif __unix__
		process = popen(command->get(), "r");
		#endif // _WIN32

		if (process != nullptr)
		{
			char c;
			do {
				c = getc(process);
				buffer.add(c);
			} while (c != EOF);

			#ifdef _WIN32
			_pclose(process);
			#elif __unix__
			pclose(process);
			#endif // _WIN32
		}
		//else
		//	LlanySimpleLib::LogErrorClearString(
		//		LlanySimpleLib::newString(
		//			"popen() fallido! Orden a ejecutar: ") + command, Error::Popen);

		result = buffer.build();
	}
	return result;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::System::ejecutarCommandClear(const Objetos::String* command) const
{
	LlanyLib::Basic::Objetos::String* result = System::ejecutarCommand(command);
	delete command;
	return result;
}
#pragma endregion
#pragma region System
bool LlanyLib::Basic::Singletons::System::procesadorActivo() const
{
	return (system(NULL) == 0);
}
void LlanyLib::Basic::Singletons::System::forzarCierre(const Enum::Codes& codigo) const
{
	assert(&codigo != nullptr);
	exit((int)codigo);
}
bool LlanyLib::Basic::Singletons::System::comprobarProcesador(const bool& value) const
{
	assert(&value != nullptr);
	bool resultado = System::procesadorActivo();
	if (resultado && value)
		System::forzarCierre(Enum::Codes::PROCESADOR_NO_ACTIVO);
	return resultado;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::System::origenPrograma() const
{
	Objetos::String* resultado = nullptr;

	#ifdef _WIN32
	Objetos::String* temp = System::ejecutarCommandClear(new LlanyLib::Basic::Objetos::String("cd"));
	resultado = temp->splitGetFirst('\n');
	delete temp;
	#elif __unix__
	return System::ejecutarCommandClear("pwd").splitIn2('\n')[0];
	#else
	return "No preparado para este sistema";
	#endif // _WIN32

	return resultado;
}
char LlanyLib::Basic::Singletons::System::caracterSeparadorDirectorios() const
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
