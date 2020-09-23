#pragma once
#ifndef DATE_OBJECT_HPP_
#define DATE_OBJECT_HPP_


namespace LlanyLib {
	namespace Basic {
		namespace Enum {
			enum class Dias;
			enum class Meses;
			enum class DateType;
		}
		namespace Objetos {
			class String;
			class JSONBuilder;
			class Date
			{
				protected:
					Enum::Dias dia_e;
					Enum::Meses mes_e;
					bool bisiesto;
					int hora;
					int min;
					int seg;
					int dia;
					int mes;
					int year;
				protected:
					void reestructurarDia();
					void reestructurarMes();
					void reestructurarYear();
					void reestructurarEnums();
				public:
					Date();
					Date(const Enum::DateType& type, const long_t& value);
					~Date();
					Enum::Dias getToday() const;
					String* toString() const;
					JSONBuilder* toJSON() const;
			};
		}
	}
}
#endif // !DATE_OBJECT_HPP_
