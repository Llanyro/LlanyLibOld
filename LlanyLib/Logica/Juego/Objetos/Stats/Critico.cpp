#include "Critico.hpp"
#include "Ofensivos.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Critico::Critico()
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
}
/*LlanyLib::Juego::Objetos::Critico::Critico(const String& contenidoJSON) : Critico()
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
	}
}*/
LlanyLib::Juego::Objetos::Critico::Critico(const Critico& other)
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Critico::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Critico::operator=(const Critico& other)
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
	}
	return temp;
}
LlanyLib::Juego::Objetos::Critico::~Critico()
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
}
#pragma endregion
#pragma region Getters
double LlanyLib::Juego::Objetos::Critico::getFuerza() const
{
	return this->fuerza;
}
double LlanyLib::Juego::Objetos::Critico::getDestreza() const
{
	return this->destreza;
}
double LlanyLib::Juego::Objetos::Critico::getElectro() const
{
	return this->electro;
}
double LlanyLib::Juego::Objetos::Critico::getFuego() const
{
	return this->fuego;
}
double LlanyLib::Juego::Objetos::Critico::getHielo() const
{
	return this->hielo;
}
double LlanyLib::Juego::Objetos::Critico::getViento() const
{
	return this->viento;
}
double LlanyLib::Juego::Objetos::Critico::getAgua() const
{
	return this->agua;
}
double LlanyLib::Juego::Objetos::Critico::getTierra() const
{
	return this->tierra;
}
double LlanyLib::Juego::Objetos::Critico::getOscuridad() const
{
	return this->oscuridad;
}
double LlanyLib::Juego::Objetos::Critico::getLuz() const
{
	return this->luz;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Critico::setFuerza(const double& value)
{
	assert(&value != nullptr);
	this->fuerza = value;
}
void LlanyLib::Juego::Objetos::Critico::setDestreza(const double& value)
{
	assert(&value != nullptr);
	this->destreza = value;
}
void LlanyLib::Juego::Objetos::Critico::setElectro(const double& value)
{
	assert(&value != nullptr);
	this->electro = value;
}
void LlanyLib::Juego::Objetos::Critico::setFuego(const double& value)
{
	assert(&value != nullptr);
	this->fuego = value;
}
void LlanyLib::Juego::Objetos::Critico::setHielo(const double& value)
{
	assert(&value != nullptr);
	this->hielo = value;
}
void LlanyLib::Juego::Objetos::Critico::setViento(const double& value)
{
	assert(&value != nullptr);
	this->viento = value;
}
void LlanyLib::Juego::Objetos::Critico::setAgua(const double& value)
{
	assert(&value != nullptr);
	this->agua = value;
}
void LlanyLib::Juego::Objetos::Critico::setTierra(const double& value)
{
	assert(&value != nullptr);
	this->tierra = value;
}
void LlanyLib::Juego::Objetos::Critico::setOscuridad(const double& value)
{
	assert(&value != nullptr);
	this->oscuridad = value;
}
void LlanyLib::Juego::Objetos::Critico::setLuz(const double& value)
{
	assert(&value != nullptr);
	this->luz = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Critico::addFuerza(const double& value)
{
	assert(&value != nullptr);
	this->fuerza += value;
}
void LlanyLib::Juego::Objetos::Critico::addDestreza(const double& value)
{
	assert(&value != nullptr);
	this->destreza += value;
}
void LlanyLib::Juego::Objetos::Critico::addElectro(const double& value)
{
	assert(&value != nullptr);
	this->electro += value;
}
void LlanyLib::Juego::Objetos::Critico::addFuego(const double& value)
{
	assert(&value != nullptr);
	this->fuego += value;
}
void LlanyLib::Juego::Objetos::Critico::addHielo(const double& value)
{
	assert(&value != nullptr);
	this->hielo += value;
}
void LlanyLib::Juego::Objetos::Critico::addViento(const double& value)
{
	assert(&value != nullptr);
	this->viento += value;
}
void LlanyLib::Juego::Objetos::Critico::addAgua(const double& value)
{
	assert(&value != nullptr);
	this->agua += value;
}
void LlanyLib::Juego::Objetos::Critico::addTierra(const double& value)
{
	assert(&value != nullptr);
	this->tierra += value;
}
void LlanyLib::Juego::Objetos::Critico::addOscuridad(const double& value)
{
	assert(&value != nullptr);
	this->oscuridad += value;
}
void LlanyLib::Juego::Objetos::Critico::addLuz(const double& value)
{
	assert(&value != nullptr);
	this->luz += value;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Critico::igual(const Critico& other) const
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
												temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Critico::operator==(const Critico& other) const
{
	return LlanyLib::Juego::Objetos::Critico::igual(other);
}
bool LlanyLib::Juego::Objetos::Critico::operator!=(const Critico& other) const
{
	return !LlanyLib::Juego::Objetos::Critico::igual(other);
}
LlanyLib::Juego::Objetos::Critico* LlanyLib::Juego::Objetos::Critico::operator+(const Critico& other)
{
	assert(&other != nullptr);
	Critico* result = new Critico(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Critico* LlanyLib::Juego::Objetos::Critico::operator-(const Critico& other)
{
	assert(&other != nullptr);
	Critico* result = new Critico(*this);
	result->operator-=(other);
	return result;
}
void LlanyLib::Juego::Objetos::Critico::operator+=(const Critico& other)
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
}
void LlanyLib::Juego::Objetos::Critico::operator-=(const Critico& other)
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
}
LlanyLib::Juego::Objetos::Ofensivos* LlanyLib::Juego::Objetos::Critico::operator*(const Ofensivos& other) const
{
	assert(&other != nullptr);
	Ofensivos* result = new Ofensivos();
	result->setFuerza(this->fuerza * other.getFuerza());
	result->setDestreza(this->destreza * other.getDestreza());
	result->setElectro(this->electro * other.getElectro());
	result->setFuego(this->fuego * other.getFuego());
	result->setHielo(this->hielo * other.getHielo());
	result->setViento(this->viento * other.getViento());
	result->setAgua(this->agua * other.getAgua());
	result->setTierra(this->tierra * other.getTierra());
	result->setOscuridad(this->oscuridad * other.getOscuridad());
	result->setLuz(this->luz * other.getLuz());
	result->setEspiritu(other.getEspiritu());
	return result;
}
#pragma endregion
#pragma region Reajustar
void LlanyLib::Juego::Objetos::Critico::reajustarTodo()
{
	LlanyLib::Juego::Objetos::Critico::reajustarFuerza();
	LlanyLib::Juego::Objetos::Critico::reajustarDestreza();
	LlanyLib::Juego::Objetos::Critico::reajustarElectro();
	LlanyLib::Juego::Objetos::Critico::reajustarFuego();
	LlanyLib::Juego::Objetos::Critico::reajustarHielo();
	LlanyLib::Juego::Objetos::Critico::reajustarViento();
	LlanyLib::Juego::Objetos::Critico::reajustarAgua();
	LlanyLib::Juego::Objetos::Critico::reajustarTierra();
	LlanyLib::Juego::Objetos::Critico::reajustarOscuridad();
	LlanyLib::Juego::Objetos::Critico::reajustarLuz();
}
void LlanyLib::Juego::Objetos::Critico::reajustarFuerza()
{
	if (this->fuerza < 0.0)
		this->fuerza = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarDestreza()
{
	if (this->destreza < 0.0)
		this->destreza = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarElectro()
{
	if (this->electro < 0.0)
		this->electro = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarFuego()
{
	if (this->fuego < 0.0)
		this->fuego = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarHielo()
{
	if (this->hielo < 0.0)
		this->hielo = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarViento()
{
	if (this->viento < 0.0)
		this->viento = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarAgua()
{
	if (this->agua < 0.0)
		this->agua = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarTierra()
{
	if (this->tierra < 0.0)
		this->tierra = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarOscuridad()
{
	if (this->oscuridad < 0.0)
		this->oscuridad = 0.0;
}
void LlanyLib::Juego::Objetos::Critico::reajustarLuz()
{
	if (this->luz < 0.0)
		this->luz = 0.0;
}
#pragma endregion
/*String LlanyLib::Juego::Objetos::Critico::toJSON() const
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
	return json.cerrarYDevolverJSON();
}
*/