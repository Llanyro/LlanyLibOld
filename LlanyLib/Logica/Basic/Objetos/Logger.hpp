#pragma once
#ifndef LOGGER_OBJECT_HPP_
#define LOGGER_OBJECT_HPP_

namespace LlanyLib
{
	namespace Basic
	{
		namespace Enum { enum class LogType; }
		namespace Objetos
		{
			class String;
			class Logger
			{
				protected:
					String* logPath;
					String* logClassName;
					String* logFile;
					String* logWarningFile;
					String* logErrorFile;
				protected:
					void log(const String* log, const Enum::LogType& type) const;
				protected:
					Logger(String* className);
					~Logger();
					void log(const String* log) const;
					void logWarning(const String* log) const;
					void logError(const String* log) const;
					void logClear(const String* log) const;
					void logWarningClear(const String* log) const;
					void logErrorClear(const String* log) const;
			};
		}
	}
}
#endif // !LOGGER_OBJECT_HPP_
