#include "Resistencia.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Stats::Resistencia::Resistencia()
{
	this->veneno = 0.0;
	this->sangrado = 0.0;
	this->congelado = 0.0;
	this->quemadura = 0.0;
	this->maldicion = 0.0;
	this->electrocutado = 0.0;
	this->sobrecargado = 0.0;
	this->isolacion = 0.0;
	this->anemia = 0.0;
	this->nausea = 0.0;
}
/*LlanyLib::Juego::Objetos::Stats::Resistencia::Resistencia(const String& contenidoJSON) : Resistencia()
{
	assert(&contenidoJSON != nullptr);
	Diccionario<String, String> listaAtributos = JSON::evalV2(contenidoJSON);
	for (size_t i = 0; i < listaAtributos.getCount(); i++)
	{
		if (listaAtributos.getKey(i).similar("veneno"))
			this->veneno = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("sangrado"))
			this->sangrado = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("congelado"))
			this->congelado = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("quemadura"))
			this->quemadura = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("maldicion"))
			this->maldicion = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("electrocutado"))
			this->electrocutado = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("sobrecargado"))
			this->sobrecargado = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("isolacion"))
			this->isolacion = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("anemia"))
			this->anemia = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("nausea"))
			this->nausea = listaAtributos.getValue(i).toDouble();
	}
}*/
LlanyLib::Juego::Objetos::Stats::Resistencia::Resistencia(const Resistencia& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Stats::Resistencia::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Stats::Resistencia::operator=(const Resistencia& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->veneno = other.veneno;
		this->sangrado = other.sangrado;
		this->congelado = other.congelado;
		this->quemadura = other.quemadura;
		this->maldicion = other.maldicion;
		this->electrocutado = other.electrocutado;
		this->sobrecargado = other.sobrecargado;
		this->isolacion = other.isolacion;
	}
	return temp;
}
LlanyLib::Juego::Objetos::Stats::Resistencia::~Resistencia(){}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Stats::Resistencia::getVeneno() const
{
	return this->veneno;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getSangrado() const
{
	return this->sangrado;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getCongelado() const
{
	return this->congelado;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getQuemadura() const
{
	return this->quemadura;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getMaldicion() const
{
	return this->maldicion;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getElectrocutado() const
{
	return this->electrocutado;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getSobrecargado() const
{
	return this->sobrecargado;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getIsolacion() const
{
	return this->isolacion;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getAnemia() const
{
	return this->anemia;
}
double LlanyLib::Juego::Objetos::Stats::Resistencia::getNausea() const
{
	return this->nausea;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Stats::Resistencia::setVeneno(const double& value)
{
	assert(&value != nullptr);
	this->veneno = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setSangrado(const double& value)
{
	assert(&value != nullptr);
	this->sangrado = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setCongelado(const double& value)
{
	assert(&value != nullptr);
	this->congelado = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setQuemadura(const double& value)
{
	assert(&value != nullptr);
	this->quemadura = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setMaldicion(const double& value)
{
	assert(&value != nullptr);
	this->maldicion = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setElectrocutado(const double& value)
{
	assert(&value != nullptr);
	this->electrocutado = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setSobrecargado(const double& value)
{
	assert(&value != nullptr);
	this->sobrecargado = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setIsolacion(const double& value)
{
	assert(&value != nullptr);
	this->isolacion = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setAnemia(const double& value)
{
	assert(&value != nullptr);
	this->anemia = value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::setNausea(const double& value)
{
	assert(&value != nullptr);
	this->nausea = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Stats::Resistencia::addVeneno(const double& value)
{
	assert(&value != nullptr);
	this->veneno += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addSangrado(const double& value)
{
	assert(&value != nullptr);
	this->sangrado += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addCongelado(const double& value)
{
	assert(&value != nullptr);
	this->congelado += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addQuemadura(const double& value)
{
	assert(&value != nullptr);
	this->quemadura += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addMaldicion(const double& value)
{
	assert(&value != nullptr);
	this->maldicion += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addElectrocutado(const double& value)
{
	assert(&value != nullptr);
	this->electrocutado += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addSobrecargado(const double& value)
{
	assert(&value != nullptr);
	this->sobrecargado += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addIsolacion(const double& value)
{
	assert(&value != nullptr);
	this->isolacion += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addAnemia(const double& value)
{
	assert(&value != nullptr);
	this->anemia += value;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::addNausea(const double& value)
{
	assert(&value != nullptr);
	this->nausea += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Stats::Resistencia::igual(const Resistencia& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
		if (this->veneno == other.veneno)
		if (this->sangrado == other.sangrado)
		if (this->congelado == other.congelado)
		if (this->quemadura == other.quemadura)
		if (this->maldicion == other.maldicion)
		if (this->electrocutado == other.electrocutado)
		if (this->sobrecargado == other.sobrecargado)
		if (this->isolacion == other.isolacion)
		if (this->anemia == other.anemia)
		if (this->nausea == other.nausea)
			temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Stats::Resistencia::operator==(const Resistencia& other) const
{
	return LlanyLib::Juego::Objetos::Stats::Resistencia::igual(other);
}
bool LlanyLib::Juego::Objetos::Stats::Resistencia::operator!=(const Resistencia& other) const
{
	return !LlanyLib::Juego::Objetos::Stats::Resistencia::igual(other);
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::operator+=(const Resistencia& other)
{
	assert(&other != nullptr);
	this->veneno += other.veneno;
	this->sangrado += other.sangrado;
	this->congelado += other.congelado;
	this->quemadura += other.quemadura;
	this->maldicion += other.maldicion;
	this->electrocutado += other.electrocutado;
	this->sobrecargado += other.sobrecargado;
	this->isolacion += other.isolacion;
	this->anemia += other.anemia;
	this->nausea += other.nausea;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::operator-=(const Resistencia& other)
{
	assert(&other != nullptr);
	this->veneno -= other.veneno;
	this->sangrado -= other.sangrado;
	this->congelado -= other.congelado;
	this->quemadura -= other.quemadura;
	this->maldicion -= other.maldicion;
	this->electrocutado -= other.electrocutado;
	this->sobrecargado -= other.sobrecargado;
	this->isolacion -= other.isolacion;
	this->anemia -= other.anemia;
	this->nausea -= other.nausea;
}
LlanyLib::Juego::Objetos::Stats::Resistencia* LlanyLib::Juego::Objetos::Stats::Resistencia::operator+(const Resistencia& other)
{
	assert(&other != nullptr);
	Resistencia* result = new Resistencia(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Stats::Resistencia* LlanyLib::Juego::Objetos::Stats::Resistencia::operator-(const Resistencia& other)
{
	assert(&other != nullptr);
	Resistencia* result = new Resistencia(*this);
	result->operator-=(other);
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarVeneno();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarSangrado();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarCongelado();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarQuemadura();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarMaldicion();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarElectrocutado();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarSobrecargado();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarIsolacion();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarAnemia();
	LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarNausea();
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarVeneno()
{
	if (this->veneno < 0.0)
		this->veneno = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarSangrado()
{
	if (this->sangrado < 0.0)
		this->sangrado = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarCongelado()
{
	if (this->congelado < 0.0)
		this->congelado = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarQuemadura()
{
	if (this->quemadura < 0.0)
		this->quemadura = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarMaldicion()
{
	if (this->maldicion < 0.0)
		this->maldicion = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarElectrocutado()
{
	if (this->electrocutado < 0.0)
		this->electrocutado = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarSobrecargado()
{
	if (this->sobrecargado < 0.0)
		this->sobrecargado = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarIsolacion()
{
	if (this->isolacion < 0.0)
		this->isolacion = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarAnemia()
{
	if (this->anemia < 0.0)
		this->anemia = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Resistencia::reajustarNausea()
{
	if (this->nausea < 0.0)
		this->nausea = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Stats::Resistencia::toJSON() const
{
	JSON json;
	json.addVaribale("veneno", this->veneno);
	json.addVaribale("sangrado", this->sangrado);
	json.addVaribale("congelado", this->congelado);
	json.addVaribale("quemadura", this->quemadura);
	json.addVaribale("maldicion", this->maldicion);
	json.addVaribale("electrocutado", this->electrocutado);
	json.addVaribale("sobrecargado", this->sobrecargado);
	json.addVaribale("isolacion", this->isolacion);
	json.addVaribale("anemia", this->anemia);
	json.addVaribale("nausea", this->nausea);
	return json.cerrarYDevolverJSON();
}
*/
