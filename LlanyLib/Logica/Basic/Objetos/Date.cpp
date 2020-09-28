#pragma warning(disable:4244)
#include "Date.hpp"

#include <time.h>

#include "../Enumerators/DateEnum.hpp"
#include "JSONBuilder.hpp"
#include "StringBuilder.hpp"
#include "../Singletons/DateController.hpp"

void LlanyLib::Basic::Objetos::Date::reestructurarDia()
{
	int diasMes = DATE_CONTROLLER->diasPorMes(this->mes, this->bisiesto);
	while (this->dia > diasMes) {
		this->dia -= diasMes;
		this->mes++;
		Date::reestructurarMes();
		diasMes = DATE_CONTROLLER->diasPorMes(this->mes, this->bisiesto);
	}
}
void LlanyLib::Basic::Objetos::Date::reestructurarMes()
{
	while(this->mes > 12) {
		this->mes -= 12;
		this->year++;
		Date::reestructurarYear();
	}
}
void LlanyLib::Basic::Objetos::Date::reestructurarYear()
{
	this->bisiesto = DATE_CONTROLLER->esBisiesto(this->year);
	Date::reestructurarDia();
	Date::reestructurarEnums();
}
void LlanyLib::Basic::Objetos::Date::reestructurarEnums()
{
	// 1 enero 2020 = miercoles
	// Cada año se avanza 1 dia
	// Cada año se avanza 2 dias si es bisiesto
	// 1 enero 2021 = viernes
	// 1 enero de x año = 1 enero año anterior + 1 (si año anterior es bisiesto
	this->mes_e = (Enum::Meses)(this->mes - 1);
	this->dia_e = DATE_CONTROLLER->today(this->dia, this->mes, this->year, this->bisiesto);
}

LlanyLib::Basic::Objetos::Date::Date()
{
	tm* ltm = DATE_CONTROLLER->getTime();
	this->dia = ltm->tm_mday;
	this->mes = ltm->tm_mon + 1;
	this->year = ltm->tm_year + 1900;
	this->hora = ltm->tm_hour;
	this->min = ltm->tm_min;
	this->seg = ltm->tm_sec;
	this->bisiesto = DATE_CONTROLLER->esBisiesto(this->year);
	delete ltm;
	Date::reestructurarEnums();
}
LlanyLib::Basic::Objetos::Date::Date(const Enum::DateType& type, const long_t& value) : Date()
{
	switch (type)
	{
		case Enum::DateType::Years:
			this->year += value;
			Date::reestructurarYear();
			break;
		case Enum::DateType::Months:
			this->mes += value;
			Date::reestructurarMes();
			break;
		case Enum::DateType::Days:
			this->dia += value;
			Date::reestructurarDia();
			break;
		default:
			break;
	}
}
LlanyLib::Basic::Objetos::Date::~Date(){}
LlanyLib::Basic::Enum::Dias LlanyLib::Basic::Objetos::Date::getToday() const
{
	return this->dia_e;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Basic::Objetos::Date::toString() const
{
	return DATE_CONTROLLER->formatedTime(this->dia, this->mes, this->year, this->hora, this->min, this->seg);
}
LlanyLib::Basic::Objetos::JSONBuilder* LlanyLib::Basic::Objetos::Date::toJSON() const
{
	JSONBuilder* json = new JSONBuilder();
	json->add("bisiesto", this->bisiesto);
	json->add("hora", this->hora);
	json->add("min", this->min);
	json->add("seg", this->seg);
	json->add("dia", this->dia);
	json->add("mes", this->mes);
	json->add("year", this->year);
	json->add("dia_e", (int)this->dia_e);
	json->add("mes_e", (int)this->mes_e);
	return json;
}
