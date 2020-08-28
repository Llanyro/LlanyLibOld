#pragma once
#ifndef DATE_CONTROLLER_SINGLETON_HPP_
#define DATE_CONTROLLER_SINGLETON_HPP_

#include "../../Math/Libs/MathTypes.h"
#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define DATE_CONTROLLER LlanyLib::Basic::Singletons::DateController::getInstancia()

struct tm;

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
		}
		namespace Singletons {
			class DateController : public Templates::Singleton<DateController>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<DateController>;
					DateController();
					~DateController();
				#pragma endregion
				public:
					bool esBisiesto(int year) const;
					int diasTotalesPorMeses(const int& mes, const bool& bisiesto) const;
					int diasPorMes(const int& mes, const bool& bisiesto) const;
					Enum::Dias today(const int& dia, const int& mes, const int& year, const bool& bisiesto) const;
					tm* getTime() const;
					Objetos::String* diaToString(const Enum::Dias& dia) const;
					Objetos::String* mesToString(const Enum::Meses& mes) const;
					Objetos::String* formatedTime(const int& dia, const int& mes, const int& year,
						const int& hora, const int& min, const int& seg) const;
					Objetos::String* now() const;
			};
		}
	}
}
#endif // !DATE_CONTROLLER_SINGLETON_HPP_
