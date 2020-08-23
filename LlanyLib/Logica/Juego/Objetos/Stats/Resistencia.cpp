#include "Resistencia.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Resistencia::Resistencia()
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
/*LlanyLib::Juego::Objetos::Resistencia::Resistencia(const String& contenidoJSON) : Resistencia()
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
LlanyLib::Juego::Objetos::Resistencia::Resistencia(const Resistencia& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Resistencia::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Resistencia::operator=(const Resistencia& other)
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
LlanyLib::Juego::Objetos::Resistencia::~Resistencia(){}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Resistencia::getVeneno() const
{
	return this->veneno;
}
double LlanyLib::Juego::Objetos::Resistencia::getSangrado() const
{
	return this->sangrado;
}
double LlanyLib::Juego::Objetos::Resistencia::getCongelado() const
{
	return this->congelado;
}
double LlanyLib::Juego::Objetos::Resistencia::getQuemadura() const
{
	return this->quemadura;
}
double LlanyLib::Juego::Objetos::Resistencia::getMaldicion() const
{
	return this->maldicion;
}
double LlanyLib::Juego::Objetos::Resistencia::getElectrocutado() const
{
	return this->electrocutado;
}
double LlanyLib::Juego::Objetos::Resistencia::getSobrecargado() const
{
	return this->sobrecargado;
}
double LlanyLib::Juego::Objetos::Resistencia::getIsolacion() const
{
	return this->isolacion;
}
double LlanyLib::Juego::Objetos::Resistencia::getAnemia() const
{
	return this->anemia;
}
double LlanyLib::Juego::Objetos::Resistencia::getNausea() const
{
	return this->nausea;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Resistencia::setVeneno(const double& value)
{
	assert(&value != nullptr);
	this->veneno = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setSangrado(const double& value)
{
	assert(&value != nullptr);
	this->sangrado = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setCongelado(const double& value)
{
	assert(&value != nullptr);
	this->congelado = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setQuemadura(const double& value)
{
	assert(&value != nullptr);
	this->quemadura = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setMaldicion(const double& value)
{
	assert(&value != nullptr);
	this->maldicion = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setElectrocutado(const double& value)
{
	assert(&value != nullptr);
	this->electrocutado = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setSobrecargado(const double& value)
{
	assert(&value != nullptr);
	this->sobrecargado = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setIsolacion(const double& value)
{
	assert(&value != nullptr);
	this->isolacion = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setAnemia(const double& value)
{
	assert(&value != nullptr);
	this->anemia = value;
}
void LlanyLib::Juego::Objetos::Resistencia::setNausea(const double& value)
{
	assert(&value != nullptr);
	this->nausea = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Resistencia::addVeneno(const double& value)
{
	assert(&value != nullptr);
	this->veneno += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addSangrado(const double& value)
{
	assert(&value != nullptr);
	this->sangrado += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addCongelado(const double& value)
{
	assert(&value != nullptr);
	this->congelado += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addQuemadura(const double& value)
{
	assert(&value != nullptr);
	this->quemadura += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addMaldicion(const double& value)
{
	assert(&value != nullptr);
	this->maldicion += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addElectrocutado(const double& value)
{
	assert(&value != nullptr);
	this->electrocutado += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addSobrecargado(const double& value)
{
	assert(&value != nullptr);
	this->sobrecargado += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addIsolacion(const double& value)
{
	assert(&value != nullptr);
	this->isolacion += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addAnemia(const double& value)
{
	assert(&value != nullptr);
	this->anemia += value;
}
void LlanyLib::Juego::Objetos::Resistencia::addNausea(const double& value)
{
	assert(&value != nullptr);
	this->nausea += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Resistencia::igual(const Resistencia& other) const
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
bool LlanyLib::Juego::Objetos::Resistencia::operator==(const Resistencia& other) const
{
	return LlanyLib::Juego::Objetos::Resistencia::igual(other);
}
bool LlanyLib::Juego::Objetos::Resistencia::operator!=(const Resistencia& other) const
{
	return !LlanyLib::Juego::Objetos::Resistencia::igual(other);
}
void LlanyLib::Juego::Objetos::Resistencia::operator+=(const Resistencia& other)
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
void LlanyLib::Juego::Objetos::Resistencia::operator-=(const Resistencia& other)
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
LlanyLib::Juego::Objetos::Resistencia* LlanyLib::Juego::Objetos::Resistencia::operator+(const Resistencia& other)
{
	assert(&other != nullptr);
	Resistencia* result = new Resistencia(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Resistencia* LlanyLib::Juego::Objetos::Resistencia::operator-(const Resistencia& other)
{
	assert(&other != nullptr);
	Resistencia* result = new Resistencia(*this);
	result->operator-=(other);
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Resistencia::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Resistencia::reajustarVeneno();
	LlanyLib::Juego::Objetos::Resistencia::reajustarSangrado();
	LlanyLib::Juego::Objetos::Resistencia::reajustarCongelado();
	LlanyLib::Juego::Objetos::Resistencia::reajustarQuemadura();
	LlanyLib::Juego::Objetos::Resistencia::reajustarMaldicion();
	LlanyLib::Juego::Objetos::Resistencia::reajustarElectrocutado();
	LlanyLib::Juego::Objetos::Resistencia::reajustarSobrecargado();
	LlanyLib::Juego::Objetos::Resistencia::reajustarIsolacion();
	LlanyLib::Juego::Objetos::Resistencia::reajustarAnemia();
	LlanyLib::Juego::Objetos::Resistencia::reajustarNausea();
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarVeneno()
{
	if (this->veneno < 0.0)
		this->veneno = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarSangrado()
{
	if (this->sangrado < 0.0)
		this->sangrado = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarCongelado()
{
	if (this->congelado < 0.0)
		this->congelado = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarQuemadura()
{
	if (this->quemadura < 0.0)
		this->quemadura = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarMaldicion()
{
	if (this->maldicion < 0.0)
		this->maldicion = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarElectrocutado()
{
	if (this->electrocutado < 0.0)
		this->electrocutado = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarSobrecargado()
{
	if (this->sobrecargado < 0.0)
		this->sobrecargado = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarIsolacion()
{
	if (this->isolacion < 0.0)
		this->isolacion = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarAnemia()
{
	if (this->anemia < 0.0)
		this->anemia = 0.0;
}
void LlanyLib::Juego::Objetos::Resistencia::reajustarNausea()
{
	if (this->nausea < 0.0)
		this->nausea = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Resistencia::toJSON() const
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
