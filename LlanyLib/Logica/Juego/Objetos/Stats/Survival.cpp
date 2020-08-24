#include "Survival.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Stats::Survival::Survival()
{
	this->hambre = 0.0;
	this->sed = 0.0;
	this->cansancio = 0.0;
	this->oxigeno = 0.0;
	this->blindaje = 0.0;
	this->radiacion = 0.0;
	this->oxido = 0.0;
}
/*LlanyLib::Juego::Objetos::Stats::Survival::Survival(const String& contenidoJSON) : Survival()
{
	assert(&contenidoJSON != nullptr);
	Diccionario<String, String> listaAtributos = JSON::evalV2(contenidoJSON);
	for (size_t i = 0; i < listaAtributos.getCount(); i++)
	{
		if (listaAtributos.getKey(i).similar("hambre"))
			this->hambre = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("sed"))
			this->sed = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("cansancio"))
			this->cansancio = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("oxigeno"))
			this->oxigeno = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("blindaje"))
			this->blindaje = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("radiacion"))
			this->radiacion = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("oxido"))
			this->oxido = listaAtributos.getValue(i).toDouble();
	}
}*/
LlanyLib::Juego::Objetos::Stats::Survival::Survival(const Survival& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Stats::Survival::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Stats::Survival::operator=(const Survival& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->hambre = other.hambre;
		this->sed = other.sed;
		this->cansancio = other.cansancio;
		this->oxigeno = other.oxigeno;
		this->blindaje = other.blindaje;
		this->radiacion = other.radiacion;
		this->oxido = other.oxido;
	}
	return temp;
}
LlanyLib::Juego::Objetos::Stats::Survival::~Survival()
{
	this->hambre = 0.0;
	this->sed = 0.0;
	this->cansancio = 0.0;
	this->oxigeno = 0.0;
	this->blindaje = 0.0;
	this->radiacion = 0.0;
	this->oxido = 0.0;
}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Stats::Survival::getHambre() const
{
	return this->hambre;
}
double LlanyLib::Juego::Objetos::Stats::Survival::getSed() const
{
	return this->sed;
}
double LlanyLib::Juego::Objetos::Stats::Survival::getCansancio() const
{
	return this->cansancio;
}
double LlanyLib::Juego::Objetos::Stats::Survival::getOxigeno() const
{
	return this->oxigeno;
}
double LlanyLib::Juego::Objetos::Stats::Survival::getBlindaje() const
{
	return this->blindaje;
}
double LlanyLib::Juego::Objetos::Stats::Survival::getRadiacion() const
{
	return this->radiacion;
}
double LlanyLib::Juego::Objetos::Stats::Survival::getOxido() const
{
	return this->oxido;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Stats::Survival::setHambre(const double& value)
{
	assert(&value != nullptr);
	this->hambre = value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::setSed(const double& value)
{
	assert(&value != nullptr);
	this->sed = value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::setCansancio(const double& value)
{
	assert(&value != nullptr);
	this->cansancio = value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::setOxigeno(const double& value)
{
	assert(&value != nullptr);
	this->oxigeno = value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::setBlindaje(const double& value)
{
	assert(&value != nullptr);
	this->blindaje = value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::setRadiacion(const double& value)
{
	assert(&value != nullptr);
	this->radiacion = value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::setOxido(const double& value)
{
	assert(&value != nullptr);
	this->oxido = value;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Stats::Survival::addHambre(const double& value)
{
	assert(&value != nullptr);
	this->hambre += value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::addSed(const double& value)
{
	assert(&value != nullptr);
	this->sed += value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::addCansancio(const double& value)
{
	assert(&value != nullptr);
	this->cansancio += value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::addOxigeno(const double& value)
{
	assert(&value != nullptr);
	this->oxigeno += value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::addBlindaje(const double& value)
{
	assert(&value != nullptr);
	this->blindaje += value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::addRadiacion(const double& value)
{
	assert(&value != nullptr);
	this->radiacion += value;
}
void LlanyLib::Juego::Objetos::Stats::Survival::addOxido(const double& value)
{
	assert(&value != nullptr);
	this->oxido += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Stats::Survival::igual(const Survival& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
		if (this->hambre == other.hambre)
		if (this->sed == other.sed)
			if (this->cansancio == other.cansancio)
				if (this->oxigeno == other.oxigeno)
					if (this->blindaje == other.blindaje)
						if (this->radiacion == other.radiacion)
							if (this->oxido == other.oxido)
								temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Stats::Survival::operator==(const Survival& other) const
{
	return LlanyLib::Juego::Objetos::Stats::Survival::igual(other);
}
bool LlanyLib::Juego::Objetos::Stats::Survival::operator!=(const Survival& other) const
{
	return !LlanyLib::Juego::Objetos::Stats::Survival::igual(other);
}
void LlanyLib::Juego::Objetos::Stats::Survival::operator+=(const Survival& other)
{
	assert(&other != nullptr);
	this->hambre += other.hambre;
	this->sed += other.sed;
	this->cansancio += other.cansancio;
	this->oxigeno += other.oxigeno;
	this->blindaje += other.blindaje;
	this->radiacion += other.radiacion;
	this->oxido += other.oxido;
}
void LlanyLib::Juego::Objetos::Stats::Survival::operator-=(const Survival& other)
{
	assert(&other != nullptr);
	this->hambre -= other.hambre;
	this->sed -= other.sed;
	this->cansancio -= other.cansancio;
	this->oxigeno -= other.oxigeno;
	this->blindaje -= other.blindaje;
	this->radiacion -= other.radiacion;
	this->oxido -= other.oxido;
}
LlanyLib::Juego::Objetos::Stats::Survival* LlanyLib::Juego::Objetos::Stats::Survival::operator+(const Survival& other)
{
	assert(&other != nullptr);
	Survival* result = new Survival(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Stats::Survival* LlanyLib::Juego::Objetos::Stats::Survival::operator-(const Survival& other)
{
	assert(&other != nullptr);
	Survival* result = new Survival(*this);
	result->operator-=(other);
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarHambre();
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarSed();
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarCansancio();
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarOxigeno();
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarBlindaje();
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarRadiacion();
	LlanyLib::Juego::Objetos::Stats::Survival::reajustarOxido();
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarHambre()
{
	if (this->hambre < 0.0)
		this->hambre = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarSed()
{
	if (this->sed < 0.0)
		this->sed = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarCansancio()
{
	if (this->cansancio < 0.0)
		this->cansancio = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarOxigeno()
{
	if (this->oxigeno < 0.0)
		this->oxigeno = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarBlindaje()
{
	if (this->blindaje < 0.0)
		this->blindaje = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarRadiacion()
{
	if (this->radiacion < 0.0)
		this->radiacion = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Survival::reajustarOxido()
{
	if (this->oxido < 0.0)
		this->oxido = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Stats::Survival::toJSON() const
{
	JSON json;
	json.addVaribale("hambre", this->hambre);
	json.addVaribale("sed", this->sed);
	json.addVaribale("cansancio", this->cansancio);
	json.addVaribale("oxigeno", this->oxigeno);
	json.addVaribale("blindaje", this->blindaje);
	json.addVaribale("radiacion", this->radiacion);
	json.addVaribale("oxido", this->oxido);
	return json.cerrarYDevolverJSON();
}
*/
