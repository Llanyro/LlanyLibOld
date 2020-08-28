#include "DateController.hpp"

#include <time.h>

#include "../Enumerators/DateEnum.hpp"

//#include "../Objetos/String.hpp"
#include "../Objetos/StringBuilder.hpp"

LlanyLib::Basic::Singletons::DateController::DateController() { DateController::subscribir(DateController::freeInstancia); }
LlanyLib::Basic::Singletons::DateController::~DateController(){}

bool LlanyLib::Basic::Singletons::DateController::esBisiesto(int year) const
{
	return ((year % 4 == 0) && ((year % 100 != 0) || (year % 400)));
}
int LlanyLib::Basic::Singletons::DateController::diasTotalesPorMeses(const int& mes, const bool& bisiesto) const
{
	/*int dias = 0;
	for (size_t i = 0; i < mes; i++)
		dias += DateController::diasPorMes(i + 1, bisiesto);
	return dias;*/
		int resultado = 0;
	switch (mes)
	{
		case 12:
			resultado += 31;
		case 11:
			resultado += 30;
		case 10:
			resultado += 31;
		case 9:
			resultado += 30;
		case 8:
			resultado += 31;
		case 7:
			resultado += 31;
		case 6:
			resultado += 30;
		case 5:
			resultado += 31;
		case 4:
			resultado += 30;
		case 3:
			resultado += 31;
		case 2:
			if(bisiesto) resultado++;
			resultado += 28;
		case 1:
			resultado += 31;
			break;
		default:
			break;
	}
	return resultado;
}
int LlanyLib::Basic::Singletons::DateController::diasPorMes(const int& mes, const bool& bisiesto) const
{
	int resultado = 0;
	switch (mes)
	{
		case 12:
			resultado = 31;
			break;
		case 11:
			resultado = 30;
			break;
		case 10:
			resultado = 31;
			break;
		case 9:
			resultado = 30;
			break;
		case 8:
			resultado = 31;
			break;
		case 7:
			resultado = 31;
			break;
		case 6:
			resultado = 30;
			break;
		case 5:
			resultado = 31;
			break;
		case 4:
			resultado = 30;
			break;
		case 3:
			resultado = 31;
			break;
		case 2:
			resultado = 28;
			if(bisiesto) resultado++;
			break;
		case 1:
			resultado = 31;
			break;
		default:
			break;
	}
	return resultado;}
LlanyLib::Basic::Enum::Dias LlanyLib::Basic::Singletons::DateController::today(const int& dia, const int& mes, const int& year, const bool& bisiesto) const
{
	int dias = 365 * (year - 2020);
	dias += dia;
	dias += DateController::diasTotalesPorMeses(mes - 1, bisiesto);
	dias += (int)Enum::Dias::Wednesday;
	dias--;
	return (Enum::Dias)(dias % 7);
}
tm* LlanyLib::Basic::Singletons::DateController::getTime() const
{
	time_t now = time(0);
	#ifdef _WIN32
	tm* ltm = new tm();
	localtime_s(ltm, &now);
	#elif __unix__
	tm* ltm = localtime(&now);
	#endif // _WIN32
	return ltm;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::DateController::diaToString(const Enum::Dias& dia) const
{
	Objetos::StringBuilder fecha;
	switch (dia)
	{
		case Enum::Dias::Monday:
			fecha.add("Monday");
			break;
		case Enum::Dias::Tuesday:
			fecha.add("Tuesday");
			break;
		case Enum::Dias::Wednesday:
			fecha.add("Wednesday");
			break;
		case Enum::Dias::Thursday:
			fecha.add("Thursday");
			break;
		case Enum::Dias::Friday:
			fecha.add("Friday");
			break;
		case Enum::Dias::Staturday:
			fecha.add("Staturday");
			break;
		case Enum::Dias::Sunday:
			fecha.add("Sunday");
			break;
		default:
			break;
	}
	return fecha.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::DateController::mesToString(const Enum::Meses& mes) const
{
	Objetos::StringBuilder fecha;
	switch (mes)
	{
		case Enum::Meses::January:
			fecha.add("January");
			break;
		case Enum::Meses::February:
			fecha.add("February");
			break;
		case Enum::Meses::March:
			fecha.add("March");
			break;
		case Enum::Meses::April:
			fecha.add("April");
			break;
		case Enum::Meses::May:
			fecha.add("May");
			break;
		case Enum::Meses::June:
			fecha.add("June");
			break;
		case Enum::Meses::July:
			fecha.add("July");
			break;
		case Enum::Meses::August:
			fecha.add("August");
			break;
		case Enum::Meses::September:
			fecha.add("September");
			break;
		case Enum::Meses::October:
			fecha.add("October");
			break;
		case Enum::Meses::November:
			fecha.add("November");
			break;
		case Enum::Meses::December:
			fecha.add("December");
			break;
		default:
			break;
	}
	return fecha.build();}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::DateController::formatedTime(const int& dia, const int& mes, const int& year, const int& hora, const int& min, const int& seg) const
{
	Objetos::StringBuilder fecha;
	fecha.add(dia);
	fecha += '/';
	fecha.add(mes);
	fecha += '/';
	fecha.add(year);
	fecha += ' ';
	fecha.add(hora);
	fecha += ':';
	fecha.add(min);
	fecha += ':';
	fecha.add(seg);
	return fecha.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Singletons::DateController::now() const
{
	tm* ltm = DateController::getTime();
	Objetos::String* result = DateController::formatedTime(ltm->tm_mday, ltm->tm_mon + 1,
		ltm->tm_year + 1900, ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
	delete ltm;
	return result;
}
