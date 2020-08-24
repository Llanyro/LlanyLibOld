#include "Defensa.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Stats::Defensa::Defensa()
{
	this->golpes = 0.0;
	this->cortes = 0.0;
	this->penetracion = 0.0;
	this->explosiones = 0.0;
	this->electro = 0.0;
	this->fuego = 0.0;
	this->hielo = 0.0;
	this->viento = 0.0;
	this->agua = 0.0;
	this->tierra = 0.0;
	this->oscuridad = 0.0;
	this->luz = 0.0;
}
/*LlanyLib::Juego::Objetos::Stats::Defensa::Defensa(const String& contenidoJSON) : Defensa()
{
	assert(&contenidoJSON != nullptr);
	Diccionario<String, String> listaAtributos = JSON::evalV2(contenidoJSON);
	for (size_t i = 0; i < listaAtributos.getCount(); i++)
	{
		if (listaAtributos.getKey(i).similar("golpes"))
			this->golpes = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("cortes"))
			this->cortes = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("explosiones"))
			this->explosiones = listaAtributos.getValue(i).toDouble();
		else if (listaAtributos.getKey(i).similar("penetracion"))
			this->penetracion = listaAtributos.getValue(i).toDouble();
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
	}
}*/
LlanyLib::Juego::Objetos::Stats::Defensa::Defensa(const Defensa& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Stats::Defensa::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Stats::Defensa::operator=(const Defensa& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->golpes = other.golpes;
		this->cortes = other.cortes;
		this->penetracion = other.penetracion;
		this->explosiones = other.explosiones;
		this->electro = other.electro;
		this->fuego = other.fuego;
		this->hielo = other.hielo;
		this->viento = other.viento;
		this->agua = other.agua;
		this->tierra = other.tierra;
		this->oscuridad = other.oscuridad;
		this->luz = other.luz;
	}
	return temp;
}
LlanyLib::Juego::Objetos::Stats::Defensa::~Defensa()
{
	this->golpes = 0.0;
	this->cortes = 0.0;
	this->penetracion = 0.0;
	this->explosiones = 0.0;
	this->electro = 0.0;
	this->fuego = 0.0;
	this->hielo = 0.0;
	this->viento = 0.0;
	this->agua = 0.0;
	this->tierra = 0.0;
	this->oscuridad = 0.0;
	this->luz = 0.0;
}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Stats::Defensa::getGolpes() const
{
	return this->golpes;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getCortes() const
{
	return this->cortes;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getPenetracion() const
{
	return this->penetracion;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getExplosiones() const
{
	return this->explosiones;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getElectro() const
{
	return this->electro;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getFuego() const
{
	return this->fuego;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getHielo() const
{
	return this->hielo;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getViento() const
{
	return this->viento;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getAgua() const
{
	return this->agua;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getTierra() const
{
	return this->tierra;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getOscuridad() const
{
	return this->oscuridad;
}
double LlanyLib::Juego::Objetos::Stats::Defensa::getLuz() const
{
	return this->luz;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Stats::Defensa::setGolpes(const double& value)
{
	assert(&value != nullptr);
	this->golpes = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setCortes(const double& value)
{
	assert(&value != nullptr);
	this->cortes = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setPenetracion(const double& value)
{
	assert(&value != nullptr);
	this->penetracion = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setExplosiones(const double& value)
{
	assert(&value != nullptr);
	this->explosiones = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setElectro(const double& value)
{
	assert(&value != nullptr);
	this->electro = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setFuego(const double& value)
{
	assert(&value != nullptr);
	this->fuego = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setHielo(const double& value)
{
	assert(&value != nullptr);
	this->hielo = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setViento(const double& value)
{
	assert(&value != nullptr);
	this->viento = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setAgua(const double& value)
{
	assert(&value != nullptr);
	this->agua = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setTierra(const double& value)
{
	assert(&value != nullptr);
	this->tierra = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setOscuridad(const double& value)
{
	assert(&value != nullptr);
	this->oscuridad = value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::setLuz(const double& value)
{
	assert(&value != nullptr);
	this->luz = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Stats::Defensa::addGolpes(const double& value)
{
	assert(&value != nullptr);
	this->golpes += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addCortes(const double& value)
{
	assert(&value != nullptr);
	this->cortes += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addPenetracion(const double& value)
{
	assert(&value != nullptr);
	this->penetracion += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addExplosiones(const double& value)
{
	assert(&value != nullptr);
	this->explosiones += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addElectro(const double& value)
{
	assert(&value != nullptr);
	this->electro += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addFuego(const double& value)
{
	assert(&value != nullptr);
	this->fuego += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addHielo(const double& value)
{
	assert(&value != nullptr);
	this->hielo += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addViento(const double& value)
{
	assert(&value != nullptr);
	this->viento += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addAgua(const double& value)
{
	assert(&value != nullptr);
	this->agua += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addTierra(const double& value)
{
	assert(&value != nullptr);
	this->tierra += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addOscuridad(const double& value)
{
	assert(&value != nullptr);
	this->oscuridad += value;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::addLuz(const double& value)
{
	assert(&value != nullptr);
	this->luz += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Stats::Defensa::igual(const Defensa& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
	if (this->golpes == other.golpes)
	if (this->cortes == other.cortes)
	if (this->penetracion == other.penetracion)
	if (this->explosiones == other.explosiones)
	if (this->electro == other.electro)
	if (this->fuego == other.fuego)
	if (this->hielo == other.hielo)
	if (this->viento == other.viento)
	if (this->agua == other.agua)
	if (this->tierra == other.tierra)
	if (this->oscuridad == other.oscuridad)
	if (this->luz == other.luz)
		temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Stats::Defensa::operator==(const Defensa& other) const
{
	assert(&other != nullptr);
	return LlanyLib::Juego::Objetos::Stats::Defensa::igual(other);
}
bool LlanyLib::Juego::Objetos::Stats::Defensa::operator!=(const Defensa& other) const
{
	assert(&other != nullptr);
	return !LlanyLib::Juego::Objetos::Stats::Defensa::igual(other);
}
void LlanyLib::Juego::Objetos::Stats::Defensa::operator+=(const Defensa& other)
{
	assert(&other != nullptr);
	this->golpes += other.golpes;
	this->cortes += other.cortes;
	this->penetracion += other.penetracion;
	this->explosiones += other.explosiones;
	this->electro += other.electro;
	this->fuego += other.fuego;
	this->hielo += other.hielo;
	this->viento += other.viento;
	this->agua += other.agua;
	this->tierra += other.tierra;
	this->oscuridad += other.oscuridad;
	this->luz += other.luz;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::operator-=(const Defensa& other)
{
	assert(&other != nullptr);
	this->golpes -= other.golpes;
	this->cortes -= other.cortes;
	this->penetracion -= other.penetracion;
	this->explosiones -= other.explosiones;
	this->electro -= other.electro;
	this->fuego -= other.fuego;
	this->hielo -= other.hielo;
	this->viento -= other.viento;
	this->agua -= other.agua;
	this->tierra -= other.tierra;
	this->oscuridad -= other.oscuridad;
	this->luz -= other.luz;
}
LlanyLib::Juego::Objetos::Stats::Defensa* LlanyLib::Juego::Objetos::Stats::Defensa::operator+(const Defensa& other)
{
	assert(&other != nullptr);
	Defensa* result = new Defensa(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Stats::Defensa* LlanyLib::Juego::Objetos::Stats::Defensa::operator-(const Defensa& other)
{
	assert(&other != nullptr);
	Defensa* result = new Defensa(*this);
	result->operator-=(other);
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarGolpes();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarCortes();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarPenetracion();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarExplosiones();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarElectro();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarFuego();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarHielo();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarViento();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarAgua();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarTierra();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarOscuridad();
	LlanyLib::Juego::Objetos::Stats::Defensa::reajustarLuz();
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarGolpes()
{
	if (this->golpes < 0.0)
		this->golpes = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarCortes()
{
	if (this->cortes < 0.0)
		this->cortes = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarPenetracion()
{
	if (this->penetracion < 0.0)
		this->penetracion = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarExplosiones()
{
	if (this->explosiones < 0.0)
		this->explosiones = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarElectro()
{
	if (this->electro < 0.0)
		this->electro = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarFuego()
{
	if (this->fuego < 0.0)
		this->fuego = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarHielo()
{
	if (this->hielo < 0.0)
		this->hielo = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarViento()
{
	if (this->viento < 0.0)
		this->viento = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarAgua()
{
	if (this->agua < 0.0)
		this->agua = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarTierra()
{
	if (this->tierra < 0.0)
		this->tierra = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarOscuridad()
{
	if (this->oscuridad < 0.0)
		this->oscuridad = 0.0;
}
void LlanyLib::Juego::Objetos::Stats::Defensa::reajustarLuz()
{
	if (this->luz < 0.0)
		this->luz = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Stats::Defensa::toJSON() const
{
	JSON json;
	json.addVaribale("golpes", this->golpes);
	json.addVaribale("cortes", this->cortes);
	json.addVaribale("explosiones", this->explosiones);
	json.addVaribale("penetracion", this->penetracion);
	json.addVaribale("electro", this->electro);
	json.addVaribale("fuego", this->fuego);
	json.addVaribale("hielo", this->hielo);
	json.addVaribale("viento", this->viento);
	json.addVaribale("agua", this->agua);
	json.addVaribale("tierra", this->tierra);
	json.addVaribale("oscuridad", this->oscuridad);
	json.addVaribale("luz", this->luz);
	return json.cerrarYDevolverJSON();
}
*/
