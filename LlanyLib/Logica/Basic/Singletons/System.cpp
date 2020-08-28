#include "System.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Chars.hpp"
#include "../Objetos/String.hpp"
#include "../Objetos/StringBuilder.hpp"
#include "../Enumerators/SystemCodes.h"

LlanyLib::Basic::Singletons::System::System() { System::subscribir(System::freeInstancia); }
LlanyLib::Basic::Singletons::System::~System(){}

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
#pragma endregion
