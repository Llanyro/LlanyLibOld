#pragma once
#ifndef MATH_SINGLETON_MATH_HPP_
#define MATH_SINGLETON_MATH_HPP_

#include "../Libs/MathTypes.h"
#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define MATH LlanyLib::Math::Singletons::Math::getInstancia()

namespace LlanyLib {
	namespace Math {
		namespace Singletons {
			class Math : public Basic::Templates::Singleton<Math>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<Math>;
					Math();
					~Math();
				#pragma endregion
				public:
					int compare(const long_t& a, const long_t& b) const;
					int compare(const double& a, const double& b) const;

					// Funcion: Realiza los calculos para obtener el factorial de un numero
					// Version: Beta
					// Retorno: Factorial de el numero procesado
					//		Si value == 0 devuelve 1
					// Complejidad temporal y espacial: O(value) y M(1)
					size_t factorial(const size_t& value) const;

					// Funcion: Multiplica un numero por si mismo tantas veces como el exponente indica
					// Version: Beta
					// Retorno: El valor del numero procesado
					//		Resultado
					//		Si base es 0 devuelve 0 siempre
					//		Si el exponente es 0 devuelve 1 siempre(exceptuando caso anterior)
					// Complejidad temporal y espacial: O(exp) y M(1)
					double elevarValor(const double& base, const size_t& exp) const;
					// Funcion: Multiplica un numero por si mismo tantas veces como el exponente indica
					// Extra: tiene mas excepciones que elevarValor()
					// Version: Beta
					// Retorno: El valor del numero procesado
					//		Resultado
					//		Si el exponente es 0 devuelve 1 siempre
					// Complejidad temporal y espacial: O(exp) y M(1)
					double elevarValorEXP(const double& base, const size_t& exp) const;

					// Funcion: Realiza un sumatorio de inicio hasta fin de n en n
					// Version: Beta
					// Precondiciones:
					//		inicio < fin
					// Retorno: Valor del sumatorio
					// Complejidad temporal y espacial: O( (fin - inicio) / n) y M(1)
					size_t sumatorioSimple(const size_t& inicio, const size_t& fin, const size_t& n) const;

					// Funcion: Realiza el calculo para obtener el MCD de dos elementos
					// Version: Alfa
					// Precondiciones:
					//		num > 0 && num2 > 0
					//		num >= num2
					// Retorno: El maximo comun divisor de dos numeros
					// Complejidad temporal y espacial: O(?) y M(1)
					size_t euclidesSimple(const size_t& num, const size_t& num2) const;

					// Funcion: Procesa un numero para ver de cuantas cifras es (Sin decimales)
					// Version: Beta
					// Retorno: Numero de cifras de un numero
					// Complejidad temporal y espacial: O(numero de cifras) y M(1)
					size_t numeroDeCifras(const size_t& num) const;
					// Funcion: Procesa un numero para ver de cuantas cifras es
					// Version: Beta
					// Precondiciones:
					//		num2 == 10
					// Retorno: Numero de cifras de un numero
					// Complejidad temporal y espacial: O(numero de cifras) y M(1)
					size_t numeroDeCifras(const size_t& num, const size_t& num2) const;

					// Funcion: Procesa un valor para dejarlo en su forma absoluta
					// Version: Beta
					// Retorno: El valor absoluto del valor introduciodo
					// Complejidad temporal y espacial: O(1) y M(1)
					int valorAbsoluto(const int& valor) const;
			};
		}
	}
}
#endif // !MATH_SINGLETON_MATH_HPP_
