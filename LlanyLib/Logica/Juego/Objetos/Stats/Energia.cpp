#include "Energia.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Energia::Energia()
{
	this->salud = 0.0;
	this->resistencia = 0.0;
	this->mana = 0.0;
	this->carga = 0.0;
	this->ira = 0.0;
	this->divinidad = 0.0;
	this->energia = 0.0;
	this->flujo = 0.0;
	this->sangre = 0.0;
}
/*LlanyLib::Juego::Objetos::Energia::Energia(const String& contenidoJSON) : Energia()
{
	assert(&contenidoJSON != nullptr);
	Diccionario<String, String> listaAtributos = JSON::evalV2(contenidoJSON);
	for (size_t i = 0; i < listaAtributos.getCount(); i++)
	{
		if (listaAtributos.getKey(i).similar("salud"))
			this->salud = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("resistencia"))
			this->resistencia = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("mana"))
			this->mana = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("carga"))
			this->carga = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("ira"))
			this->ira = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("divinidad"))
			this->divinidad = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("energia"))
			this->energia = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("flujo"))
			this->flujo = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("sangre"))
			this->sangre = listaAtributos.getValue(i).toDouble();
	}
}*/
LlanyLib::Juego::Objetos::Energia::Energia(const Energia& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Energia::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Energia::operator=(const Energia& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->salud = other.salud;
		this->resistencia = other.resistencia;
		this->mana = other.mana;
		this->carga = other.carga;
		this->ira = other.ira;
		this->divinidad = other.divinidad;
		this->energia = other.energia;
		this->flujo = other.flujo;
		this->sangre = other.sangre;
	}
	return temp;
}
LlanyLib::Juego::Objetos::Energia::~Energia()
{
	this->salud = 0.0;
	this->resistencia = 0.0;
	this->mana = 0.0;
	this->carga = 0.0;
	this->ira = 0.0;
	this->divinidad = 0.0;
	this->energia = 0.0;
	this->flujo = 0.0;
	this->sangre = 0.0;
}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Energia::getSalud() const
{
	return this->salud;
}
double LlanyLib::Juego::Objetos::Energia::getResistencia() const
{
	return this->resistencia;
}
double LlanyLib::Juego::Objetos::Energia::getMana() const
{
	return this->mana;
}
double LlanyLib::Juego::Objetos::Energia::getCarga() const
{
	return this->carga;
}
double LlanyLib::Juego::Objetos::Energia::getIra() const
{
	return this->ira;
}
double LlanyLib::Juego::Objetos::Energia::getDivinidad() const
{
	return this->divinidad;
}
double LlanyLib::Juego::Objetos::Energia::getEnergia() const
{
	return this->energia;
}
double LlanyLib::Juego::Objetos::Energia::getFlujo() const
{
	return this->flujo;
}
double LlanyLib::Juego::Objetos::Energia::getSangre() const
{
	return this->sangre;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Energia::setSalud(const double& value)
{
	assert(&value != nullptr);
	this->salud = value;
}
void LlanyLib::Juego::Objetos::Energia::setResistencia(const double& value)
{
	assert(&value != nullptr);
	this->resistencia = value;
}
void LlanyLib::Juego::Objetos::Energia::setMana(const double& value)
{
	assert(&value != nullptr);
	this->mana = value;
}
void LlanyLib::Juego::Objetos::Energia::setCarga(const double& value)
{
	assert(&value != nullptr);
	this->carga = value;
}
void LlanyLib::Juego::Objetos::Energia::setIra(const double& value)
{
	assert(&value != nullptr);
	this->ira = value;
}
void LlanyLib::Juego::Objetos::Energia::setDivinidad(const double& value)
{
	assert(&value != nullptr);
	this->divinidad = value;
}
void LlanyLib::Juego::Objetos::Energia::setEnergia(const double& value)
{
	assert(&value != nullptr);
	this->energia = value;
}
void LlanyLib::Juego::Objetos::Energia::setFlujo(const double& value)
{
	assert(&value != nullptr);
	this->flujo = value;
}
void LlanyLib::Juego::Objetos::Energia::setSangre(const double& value)
{
	assert(&value != nullptr);
	this->sangre = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Energia::addSalud(const double& value)
{
	assert(&value != nullptr);
	this->salud += value;
}
void LlanyLib::Juego::Objetos::Energia::addResistencia(const double& value)
{
	assert(&value != nullptr);
	this->resistencia += value;
}
void LlanyLib::Juego::Objetos::Energia::addMana(const double& value)
{
	assert(&value != nullptr);
	this->mana += value;
}
void LlanyLib::Juego::Objetos::Energia::addCarga(const double& value)
{
	assert(&value != nullptr);
	this->carga += value;
}
void LlanyLib::Juego::Objetos::Energia::addIra(const double& value)
{
	assert(&value != nullptr);
	this->ira += value;
}
void LlanyLib::Juego::Objetos::Energia::addDivinidad(const double& value)
{
	assert(&value != nullptr);
	this->divinidad += value;
}
void LlanyLib::Juego::Objetos::Energia::addEnergia(const double& value)
{
	assert(&value != nullptr);
	this->energia += value;
}
void LlanyLib::Juego::Objetos::Energia::addFlujo(const double& value)
{
	assert(&value != nullptr);
	this->flujo += value;
}
void LlanyLib::Juego::Objetos::Energia::addSangre(const double& value)
{
	assert(&value != nullptr);
	this->sangre += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Energia::igual(const Energia& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
		if (this->salud == other.salud)
	if (this->resistencia == other.resistencia)
	if (this->mana == other.mana)
	if (this->carga == other.carga)
	if (this->ira == other.ira)
	if (this->divinidad == other.divinidad)
	if (this->energia == other.energia)
	if (this->flujo == other.flujo)
	if (this->sangre == other.sangre)
		temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Energia::operator==(const Energia& other) const
{
	return LlanyLib::Juego::Objetos::Energia::igual(other);
}
bool LlanyLib::Juego::Objetos::Energia::operator!=(const Energia& other) const
{
	return !LlanyLib::Juego::Objetos::Energia::igual(other);
}
void LlanyLib::Juego::Objetos::Energia::operator+=(const Energia& other)
{
	assert(&other != nullptr);
	this->salud += other.salud;
	this->resistencia += other.resistencia;
	this->mana += other.mana;
	this->carga += other.carga;
	this->ira += other.ira;
	this->divinidad += other.divinidad;
	this->energia += other.energia;
	this->flujo += other.flujo;
	this->sangre += other.sangre;
}
void LlanyLib::Juego::Objetos::Energia::operator-=(const Energia& other)
{
	assert(&other != nullptr);
	this->salud -= other.salud;
	this->resistencia -= other.resistencia;
	this->mana -= other.mana;
	this->carga -= other.carga;
	this->ira -= other.ira;
	this->divinidad -= other.divinidad;
	this->energia -= other.energia;
	this->flujo -= other.flujo;
	this->sangre -= other.sangre;
}
LlanyLib::Juego::Objetos::Energia* LlanyLib::Juego::Objetos::Energia::operator+(const Energia& other)
{
	assert(&other != nullptr);
	Energia* result = new Energia(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Energia* LlanyLib::Juego::Objetos::Energia::operator-(const Energia& other)
{
	assert(&other != nullptr);
	Energia* result = new Energia(*this);
	result->operator-=(other);
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Energia::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Energia::reajustarSalud();
	LlanyLib::Juego::Objetos::Energia::reajustarResistencia();
	LlanyLib::Juego::Objetos::Energia::reajustarMana();
	LlanyLib::Juego::Objetos::Energia::reajustarCarga();
	LlanyLib::Juego::Objetos::Energia::reajustarIra();
	LlanyLib::Juego::Objetos::Energia::reajustarDivinidad();
	LlanyLib::Juego::Objetos::Energia::reajustarEnergia();
	LlanyLib::Juego::Objetos::Energia::reajustarFlujo();
	LlanyLib::Juego::Objetos::Energia::reajustarSangre();
}
void LlanyLib::Juego::Objetos::Energia::reajustarSalud()
{
	if (this->salud < 0.0)
		this->salud = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarResistencia()
{
	if (this->resistencia < 0.0)
		this->resistencia = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarMana()
{
	if (this->mana < 0.0)
		this->mana = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarCarga()
{
	if (this->carga < 0.0)
		this->carga = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarIra()
{
	if (this->ira < 0.0)
		this->ira = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarDivinidad()
{
	if (this->divinidad < 0.0)
		this->divinidad = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarEnergia()
{
	if (this->energia < 0.0)
		this->energia = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarFlujo()
{
	if (this->flujo < 0.0)
		this->flujo = 0.0;
}
void LlanyLib::Juego::Objetos::Energia::reajustarSangre()
{
	if (this->sangre < 0.0)
		this->sangre = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Energia::toJSON() const
{
	JSON json;
	json.addVaribale("salud", this->salud);
	json.addVaribale("resistencia", this->resistencia);
	json.addVaribale("mana", this->mana);
	json.addVaribale("carga", this->carga);
	json.addVaribale("ira", this->ira);
	json.addVaribale("divinidad", this->divinidad);
	json.addVaribale("energia", this->energia);
	json.addVaribale("flujo", this->flujo);
	json.addVaribale("sangre", this->sangre);
	return json.cerrarYDevolverJSON();
}
*/
