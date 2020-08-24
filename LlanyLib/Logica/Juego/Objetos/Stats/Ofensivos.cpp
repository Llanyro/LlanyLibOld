#include "Ofensivos.hpp"
#include "Critico.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Stats::Ofensivos::Ofensivos()
{
	this->fuerza = 0.0;
	this->destreza = 0.0;
	this->electro = 0.0;
	this->fuego = 0.0;
	this->hielo = 0.0;
	this->viento = 0.0;
	this->agua = 0.0;
	this->tierra = 0.0;
	this->oscuridad = 0.0;
	this->luz = 0.0;
	this->espiritu = 0.0;
}
/*LlanyLib::Juego::Objetos::Stats::Ofensivos::Ofensivos(const String& contenidoJSON) : Ofensivos()
{
	assert(&contenidoJSON != nullptr);
	Diccionario<String, String> listaAtributos = JSON::evalV2(contenidoJSON);
	for (size_t i = 0; i < listaAtributos.getCount(); i++)
	{
		if (listaAtributos.getKey(i).similar("fuerza"))
			this->fuerza = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("destreza"))
			this->destreza = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("electro"))
			this->electro = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("fuego"))
			this->fuego = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("hielo"))
			this->hielo = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("viento"))
			this->viento = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("agua"))
			this->agua = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("tierra"))
			this->tierra = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("oscuridad"))
			this->oscuridad = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("luz"))
			this->luz = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("espiritu"))
			this->espiritu = listaAtributos.getValue(i).toDouble();
	}
}*/
LlanyLib::Juego::Objetos::Stats::Ofensivos::Ofensivos(const Ofensivos& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Stats::Ofensivos::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Stats::Ofensivos::operator=(const Ofensivos& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->fuerza = other.fuerza;
		this->destreza = other.destreza;
		this->electro = other.electro;
		this->fuego = other.fuego;
		this->hielo = other.hielo;
		this->viento = other.viento;
		this->agua = other.agua;
		this->tierra = other.tierra;
		this->oscuridad = other.oscuridad;
		this->luz = other.luz;
		this->espiritu = other.espiritu;
	}
	return temp;
}
LlanyLib::Juego::Objetos::Stats::Ofensivos::~Ofensivos()
{
	this->fuerza = 0.0;
	this->destreza = 0.0;
	this->electro = 0.0;
	this->fuego = 0.0;
	this->hielo = 0.0;
	this->viento = 0.0;
	this->agua = 0.0;
	this->tierra = 0.0;
	this->oscuridad = 0.0;
	this->luz = 0.0;
	this->espiritu = 0.0;
}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getFuerza() const
{
	return this->fuerza;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getDestreza() const
{
	return this->destreza;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getElectro() const
{
	return this->electro;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getFuego() const
{
	return this->fuego;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getHielo() const
{
	return this->hielo;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getViento() const
{
	return this->viento;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getAgua() const
{
	return this->agua;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getTierra() const
{
	return this->tierra;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getOscuridad() const
{
	return this->oscuridad;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getLuz() const
{
	return this->luz;
}
double LlanyLib::Juego::Objetos::Stats::Ofensivos::getEspiritu() const
{
	return this->espiritu;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setFuerza(const double& value)
{
	assert(&value != nullptr);
	this->fuerza = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setDestreza(const double& value)
{
	assert(&value != nullptr);
	this->destreza = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setElectro(const double& value)
{
	assert(&value != nullptr);
	this->electro = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setFuego(const double& value)
{
	assert(&value != nullptr);
	this->fuego = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setHielo(const double& value)
{
	assert(&value != nullptr);
	this->hielo = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setViento(const double& value)
{
	assert(&value != nullptr);
	this->viento = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setAgua(const double& value)
{
	assert(&value != nullptr);
	this->agua = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setTierra(const double& value)
{
	assert(&value != nullptr);
	this->tierra = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setOscuridad(const double& value)
{
	assert(&value != nullptr);
	this->oscuridad = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setLuz(const double& value)
{
	assert(&value != nullptr);
	this->luz = value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::setEspiritu(const double& value)
{
	assert(&value != nullptr);
	this->espiritu = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addFuerza(const double& value)
{
	assert(&value != nullptr);
	this->fuerza += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addDestreza(const double& value)
{
	assert(&value != nullptr);
	this->destreza += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addElectro(const double& value)
{
	assert(&value != nullptr);
	this->electro += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addFuego(const double& value)
{
	assert(&value != nullptr);
	this->fuego += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addHielo(const double& value)
{
	assert(&value != nullptr);
	this->hielo += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addViento(const double& value)
{
	assert(&value != nullptr);
	this->viento += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addAgua(const double& value)
{
	assert(&value != nullptr);
	this->agua += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addTierra(const double& value)
{
	assert(&value != nullptr);
	this->tierra += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addOscuridad(const double& value)
{
	assert(&value != nullptr);
	this->oscuridad += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addLuz(const double& value)
{
	assert(&value != nullptr);
	this->luz += value;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::addEspiritu(const double& value)
{
	assert(&value != nullptr);
	this->espiritu += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Stats::Ofensivos::igual(const Ofensivos& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
		if (this->fuerza == other.fuerza)
		if (this->destreza == other.destreza)
		if (this->electro == other.electro)
		if (this->fuego == other.fuego)
		if (this->hielo == other.hielo)
		if (this->viento == other.viento)
		if (this->agua == other.agua)
		if (this->tierra == other.tierra)
		if (this->oscuridad == other.oscuridad)
		if (this->luz == other.luz)
		if (this->espiritu == other.espiritu)
			temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Stats::Ofensivos::operator==(const Ofensivos& other) const
{
	return LlanyLib::Juego::Objetos::Stats::Ofensivos::igual(other);
}
bool LlanyLib::Juego::Objetos::Stats::Ofensivos::operator!=(const Ofensivos& other) const
{
	return !LlanyLib::Juego::Objetos::Stats::Ofensivos::igual(other);
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::operator+=(const Ofensivos& other)
{
	assert(&other != nullptr);
	this->fuerza += other.fuerza;
	this->destreza += other.destreza;
	this->electro += other.electro;
	this->fuego += other.fuego;
	this->hielo += other.hielo;
	this->viento += other.viento;
	this->agua += other.agua;
	this->tierra += other.tierra;
	this->oscuridad += other.oscuridad;
	this->luz += other.luz;
	this->espiritu += other.espiritu;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::operator-=(const Ofensivos& other)
{
	assert(&other != nullptr);
	this->fuerza -= other.fuerza;
	this->destreza -= other.destreza;
	this->electro -= other.electro;
	this->fuego -= other.fuego;
	this->hielo -= other.hielo;
	this->viento -= other.viento;
	this->agua -= other.agua;
	this->tierra -= other.tierra;
	this->oscuridad -= other.oscuridad;
	this->luz -= other.luz;
	this->espiritu -= other.espiritu;
}
LlanyLib::Juego::Objetos::Stats::Ofensivos* LlanyLib::Juego::Objetos::Stats::Ofensivos::operator+(const Ofensivos& other)
{
	assert(&other != nullptr);
	Ofensivos* result = new Ofensivos(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Stats::Ofensivos* LlanyLib::Juego::Objetos::Stats::Ofensivos::operator-(const Ofensivos& other)
{
	assert(&other != nullptr);
	Ofensivos* result = new Ofensivos(*this);
	result->operator-=(other);
	return result;
}
LlanyLib::Juego::Objetos::Stats::Ofensivos* LlanyLib::Juego::Objetos::Stats::Ofensivos::operator*(const Critico& other) const
{
	assert(&other != nullptr);
	Ofensivos* result = new Ofensivos();
	result->fuerza = this->fuerza * other.getFuerza();
	result->destreza = this->destreza * other.getDestreza();
	result->electro = this->electro * other.getElectro();
	result->fuego = this->fuego * other.getFuego();
	result->hielo = this->hielo * other.getHielo();
	result->viento = this->viento * other.getViento();
	result->agua = this->agua * other.getAgua();
	result->tierra = this->tierra * other.getTierra();
	result->oscuridad = this->oscuridad * other.getOscuridad();
	result->luz = this->luz * other.getLuz();
	result->espiritu = this->espiritu;
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarFuerza();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarDestreza();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarElectro();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarFuego();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarHielo();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarViento();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarAgua();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarTierra();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarOscuridad();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarLuz();
	LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarEspiritu();
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarFuerza()
{
	if (this->fuerza < 0.0)
		this->fuerza = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarDestreza()
{
	if (this->destreza < 0.0)
		this->destreza = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarElectro()
{
	if (this->electro < 0.0)
		this->electro = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarFuego()
{
	if (this->fuego < 0.0)
		this->fuego = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarHielo()
{
	if (this->hielo < 0.0)
		this->hielo = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarViento()
{
	if (this->viento < 0.0)
		this->viento = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarAgua()
{
	if (this->agua < 0.0)
		this->agua = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarTierra()
{
	if (this->tierra < 0.0)
		this->tierra = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarOscuridad()
{
	if (this->oscuridad < 0.0)
		this->oscuridad = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarLuz()
{
	if (this->luz < 0.0)
		this->luz = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Ofensivos::reajustarEspiritu()
{
	if (this->espiritu < 0.0)
		this->espiritu = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Stats::Ofensivos::toJSON() const
{
	JSON json;
	json.addVaribale("fuerza", this->fuerza);
	json.addVaribale("destreza", this->destreza);
	json.addVaribale("electro", this->electro);
	json.addVaribale("fuego", this->fuego);
	json.addVaribale("hielo", this->hielo);
	json.addVaribale("viento", this->viento);
	json.addVaribale("agua", this->agua);
	json.addVaribale("tierra", this->tierra);
	json.addVaribale("oscuridad", this->oscuridad);
	json.addVaribale("luz", this->luz);
	json.addVaribale("espiritu", this->espiritu);
	return json.cerrarYDevolverJSON();
}
*/
