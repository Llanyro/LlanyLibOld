#include "Math.hpp"

#include <cassert>

LlanyLib::Math::Singletons::Math::Math() { Math::subscribir(Math::freeInstancia); }
LlanyLib::Math::Singletons::Math::~Math() {}

int LlanyLib::Math::Singletons::Math::compare(const long_t& a, const long_t& b) const
{
	int res = 0;
	if (a > b) res = 1;
	else if (b > a) res = -1;
	return 0;
}
int LlanyLib::Math::Singletons::Math::compare(const double& a, const double& b) const
{
	int res = 0;
	if (a > b) res = 1;
	else if (b > a) res = -1;
	return 0;
}

size_t LlanyLib::Math::Singletons::Math::factorial(const size_t& value) const
{
	assert(&value != nullptr);
	return (value >= 0) ? (value * Math::factorial(value - 1)) : 1;
}
double LlanyLib::Math::Singletons::Math::elevarValor(const double& base, const size_t& exp) const
{
	assert(&base != nullptr);
	assert(&exp != nullptr);
	double resultado = 0.0;
	if (base == 0)
		resultado = 0.0;
	else if (exp == 0)
		resultado = 1.0;
	else
		resultado = Math::elevarValorEXP(base, exp);
	return resultado;
}
double LlanyLib::Math::Singletons::Math::elevarValorEXP(const double& base, const size_t& exp) const
{
	assert(&base != nullptr);
	assert(&exp != nullptr);
	return (exp > 0) ? (base * Math::elevarValor(base, exp - 1)) : 1;
}
size_t LlanyLib::Math::Singletons::Math::sumatorioSimple(const size_t& inicio, const size_t& fin, const size_t& n) const
{
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&n != nullptr);
	assert(inicio < fin);
	size_t temp = 0;
	for (size_t i = inicio; i < fin; i += n) temp += i;
	return temp;
}

size_t LlanyLib::Math::Singletons::Math::euclidesSimple(const size_t& num, const size_t& num2) const
{
	//assert(num > 0);
	//assert(num2 > 0);
	assert(&num != nullptr);
	assert(&num2 != nullptr);
	assert(num >= num2);
	return (num2 != 0) ? (Math::euclidesSimple(num2, num % num2)) : num;
}

size_t LlanyLib::Math::Singletons::Math::numeroDeCifras(const size_t& num) const
{
	assert(&num != nullptr);
	return Math::numeroDeCifras(num, 10);
}
size_t LlanyLib::Math::Singletons::Math::numeroDeCifras(const size_t& num, const size_t& num2) const
{
	assert(&num != nullptr);
	assert(&num2 != nullptr);
	assert(num >= 0);
	assert((num2 % 10) == 0);
	return (num != 0) ? (1 + Math::numeroDeCifras(num - (num % num2), num2 * 10)) : 1;
}

int LlanyLib::Math::Singletons::Math::valorAbsoluto(const int& valor) const
{
	assert(&valor != nullptr);
	int resultado = 0;
	if (valor >= 0)
		resultado = valor;
	else
		resultado -= valor;
	return valor;
}