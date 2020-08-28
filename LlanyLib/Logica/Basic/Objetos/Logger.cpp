#include "Logger.hpp"

#include "../Singletons/Files.hpp"
#include "../Singletons/DateController.hpp"

#include "../Objetos/String.hpp"

#include "StringBuilder.hpp"

#include "../Enumerators/LoggerEnum.hpp"

/// Carpetas
#define DIRECTORIO_LOGS "Logs"
#define FILE_LOG "Log.txt"
#define FILE_LOGERROR "LogError.txt"
#define FILE_LOGWARNING "LogWarning.txt"

/*/// Errors
#define INPUT_FILENAME_LOG_ERROR "/LogErrorInput.txt"
#define OUTPUT_FILENAME_LOG_ERROR "/LogErrorOutput.txt"
#define CHARSCONTROL_FILENAME_LOG_ERROR "/LogErrorCharsControl.txt"

/// Warnings
#define INPUT_FILENAME_LOG_WARNING "/LogWarningInput.txt"
#define OUTPUT_FILENAME_LOG_WARNING "/LogWarningOutput.txt"
#define CHARSCONTROL_FILENAME_LOG_WARNING "/LogWarningCharsControl.txt"*/

void LlanyLib::Basic::Objetos::Logger::log(const String* log, const Enum::LogType& type) const
{
	String* fileName = nullptr;
	switch (type)
	{
		case Enum::LogType::Log:
			fileName = this->logFile;
			break;
		case Enum::LogType::Error:
			fileName = this->logErrorFile;
			break;
		case Enum::LogType::Warning:
			fileName = this->logWarningFile;
			break;
	}
	FILES->escribirFicheroAppendClearContent(fileName, DATE_CONTROLLER->now());
	FILES->escribirFicheroAppend(fileName, ' ');
	FILES->escribirFicheroAppend(fileName, log);
	FILES->escribirFicheroAppend(fileName, '\n');
}
LlanyLib::Basic::Objetos::Logger::Logger(String* className)
{
	this->logClassName = className;

	String* temp = nullptr;
	StringBuilder buff;

	temp = FILES->origenPrograma();
	buff.add(temp);
	delete temp;

	// Añadimos la carpta de logs base desde el origen del programa
	buff.add(FILES->caracterSeparadorDirectorios());
	buff.add(DIRECTORIO_LOGS);

	// Añadimos a la ruta el nombre de la clase
	buff.add(FILES->caracterSeparadorDirectorios());
	buff.add(className);
	//buff.add(SYSTEM->caracterSeparadorDirectorios());

	this->logPath = buff.build();
	
	delete FILES->crearPath(logPath);

	temp = this->logPath->operator+(FILES->caracterSeparadorDirectorios());

	this->logFile = temp->operator+(FILE_LOG);
	this->logErrorFile = temp->operator+(FILE_LOGERROR);
	this->logWarningFile = temp->operator+(FILE_LOGWARNING);
	delete temp;

	String* info = new String("Inicializado Logger de la clase: ");
	Logger::logClear(info->operator+(*className));
	delete info;
}
LlanyLib::Basic::Objetos::Logger::~Logger()
{
	if (this->logClassName)
		delete[] this->logClassName;
	if (this->logPath)
		delete[] this->logPath;

	if (this->logFile)
		delete[] this->logFile;
	if (this->logWarningFile)
		delete[] this->logWarningFile;
	if (this->logErrorFile)
		delete[] this->logErrorFile;

	this->logClassName = nullptr;
	this->logPath = nullptr;
	this->logFile = nullptr;
	this->logWarningFile = nullptr;
	this->logErrorFile = nullptr;
}
void LlanyLib::Basic::Objetos::Logger::log(const String* log) const
{
	Logger::log(log, Enum::LogType::Log);
}
void LlanyLib::Basic::Objetos::Logger::logWarning(const String* log) const
{
	Logger::log(log, Enum::LogType::Warning);
}
void LlanyLib::Basic::Objetos::Logger::logError(const String* log) const
{
	Logger::log(log, Enum::LogType::Error);
}
void LlanyLib::Basic::Objetos::Logger::logClear(const String* log) const
{
	Logger::log(log);
	delete log;
}
void LlanyLib::Basic::Objetos::Logger::logWarningClear(const String* log) const
{
	Logger::logWarning(log);
	delete log;
}
void LlanyLib::Basic::Objetos::Logger::logErrorClear(const String* log) const
{
	Logger::logError(log);
	delete log;
}
