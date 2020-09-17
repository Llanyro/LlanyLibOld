#pragma once
#ifndef LOGGER_OBJECT_HPP_
#define LOGGER_OBJECT_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Enum { enum class LogType; }
		namespace Objetos {
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
					String* getFileName(const Enum::LogType& type) const;
					void log(const String* log, const Enum::LogType& type) const;
					void log(char const* const log, const Enum::LogType& type) const;
				public:
					Logger(String* className);
					Logger(char const* const className);
					~Logger();
					void log(const String* log) const;
					void logWarning(const String* log) const;
					void logError(const String* log) const;

					void log(char const* const log) const;
					void logWarning(char const* const log) const;
					void logError(char const* const log) const;

					void logClear(const String* log) const;
					void logWarningClear(const String* log) const;
					void logErrorClear(const String* log) const;
			};
		}
	}
}
#endif // !LOGGER_OBJECT_HPP_
