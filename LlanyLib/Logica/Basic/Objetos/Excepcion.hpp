#pragma once
#ifndef EXCEPCION_HPP_
#define EXCEPCION_HPP_
#pragma warning(disable:4290)

#define THROW throw(LlanyLib::Basic::Objetos::Excepcion)
#define CATCH catch (LlanyLib::Basic::Objetos::Excepcion& e)
#define EXCEPTION throw LlanyLib::Basic::Objetos::Excepcion
#define BACK_TRACE_EXCEPTION throw LlanyLib::Basic::Objetos::BackTraceException(__FUNCTION__)

namespace LlanyLib
{
	namespace Basic
	{
		namespace Objetos
		{
			class Excepcion
			{
				protected:
					char const* msg;
					char const* funcion;
					bool backTrace;
				public:
					Excepcion();
					Excepcion(char const* const excepcion);
					Excepcion(char const* const excepcion, char const* const funcion);
					Excepcion(char const* const funcion, const bool& backTrace);
					virtual ~Excepcion();
				public:
					virtual char const* getMensajeExcepcion() const;
					virtual char const* getFuncionExcepcion() const;
					virtual void print() const;
			};

			class BackTraceException : public Excepcion
			{
				public:
					BackTraceException();
					BackTraceException(char const* const funcion);
					~BackTraceException();
			};
		}
	}
}
#endif // EXCEPCION_HPP_
