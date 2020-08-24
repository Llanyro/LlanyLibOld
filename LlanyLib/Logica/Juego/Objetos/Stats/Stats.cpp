#include "Stats.hpp"

#include "Critico.hpp"
#include "Ofensivos.hpp"
#include "Defensa.hpp"
#include "Energia.hpp"
#include "Resistencia.hpp"
#include "Survival.hpp"

#include <cassert>

#pragma region Constructores
LlanyLib::Juego::Objetos::Stats::Stats::Stats()
{
	this->nivel = 0ll;
	this->experiencia = 0ll;
	this->experienciaMaxima = 0ll;
	this->equipo = 0ull;
	this->pvp = true;
	this->fuegoAmigo = true;
	this->raza = Enums::Raza::Null;

	this->criticoBase = new Critico();
	this->critico = new Critico();
	this->ofensivos = new Ofensivos();
	this->defensa = new Defensa();
	this->energiaActual = new Energia();
	this->energiaMaxima = new Energia();
	this->contadorResistencias = new Resistencia();
	this->resistenciasMaximas = new Resistencia();
	this->survivalMax = new Survival();
	this->survivalActual = new Survival();
}
LlanyLib::Juego::Objetos::Stats::Stats::Stats(const Stats& other) : Stats()
{
	assert(&other != nullptr);
	bool temp = LlanyLib::Juego::Objetos::Stats::Stats::operator=(other);
	assert(temp);
}
bool LlanyLib::Juego::Objetos::Stats::Stats::operator=(const Stats& other)
{
	bool temp = true;
	if (&other == nullptr) temp = false;
	else
	{
		this->nivel = other.nivel;
		this->experiencia = other.experiencia;
		this->experienciaMaxima = other.experienciaMaxima;
		this->equipo = other.equipo;
		this->pvp = other.pvp;
		this->fuegoAmigo = other.pvp;
		this->raza = other.raza;

		this->criticoBase->operator=(*other.criticoBase);
		this->critico->operator=(*other.critico);
		this->ofensivos->operator=(*other.ofensivos);
		this->defensa->operator=(*other.defensa);
		this->energiaActual->operator=(*other.energiaActual);
		this->energiaMaxima->operator=(*other.energiaMaxima);
		this->contadorResistencias->operator=(*other.contadorResistencias);
		this->resistenciasMaximas->operator=(*other.resistenciasMaximas);
		this->survivalActual->operator=(*other.survivalActual);
		this->survivalMax->operator=(*other.survivalMax);
	}
	return temp;
}
LlanyLib::Juego::Objetos::Stats::Stats::~Stats()
{
	this->nivel = 0ll;
	this->experiencia = 0ll;
	this->experienciaMaxima = 0ll;
	this->equipo = 0ull;
	this->pvp = false;
	this->fuegoAmigo = false;
	this->raza = Enums::Raza::Null;
	if (this->criticoBase != nullptr) delete(this->criticoBase);
	if (this->critico != nullptr) delete(this->critico);
	if (this->ofensivos != nullptr) delete(this->ofensivos);
	if (this->defensa != nullptr) delete(this->defensa);
	if (this->energiaActual != nullptr) delete(this->energiaActual);
	if (this->energiaMaxima != nullptr) delete(this->energiaMaxima);
	if (this->contadorResistencias != nullptr) delete(this->contadorResistencias);
	if (this->resistenciasMaximas != nullptr) delete(this->resistenciasMaximas);
	if (this->survivalActual != nullptr) delete(this->survivalActual);
	if (this->survivalMax != nullptr) delete(this->survivalMax);
	this->criticoBase = nullptr;
	this->critico = nullptr;
	this->ofensivos = nullptr;
	this->defensa = nullptr;
	this->energiaActual = nullptr;
	this->energiaMaxima = nullptr;
	this->contadorResistencias = nullptr;
	this->resistenciasMaximas = nullptr;
	this->survivalActual = nullptr;
	this->survivalMax = nullptr;
}
#pragma endregion
#pragma region Getters
ulong_t LlanyLib::Juego::Objetos::Stats::Stats::getNivel() const
{
	return this->nivel;
}
ulong_t LlanyLib::Juego::Objetos::Stats::Stats::getExperiencia() const
{
	return this->experiencia;
}
ulong_t LlanyLib::Juego::Objetos::Stats::Stats::getExperienciaMaxima() const
{
	return this->experienciaMaxima;
}
ulong_t LlanyLib::Juego::Objetos::Stats::Stats::getEquipo() const
{
	return this->equipo;
}
bool LlanyLib::Juego::Objetos::Stats::Stats::getPVP() const
{
	return this->pvp;
}
bool LlanyLib::Juego::Objetos::Stats::Stats::getFuegoAmigo() const
{
	return this->fuegoAmigo;
}
LlanyLib::Juego::Enums::Raza LlanyLib::Juego::Objetos::Stats::Stats::getRaza() const
{
	return this->raza;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Stats::Stats::setNivel(const ulong_t& value)
{
	assert(&value != nullptr);
	this->nivel = value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::setExperiencia(const ulong_t& value)
{
	assert(&value != nullptr);
	this->experiencia = value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::setExperienciaMaxima(const ulong_t& value)
{
	assert(&value != nullptr);
	this->experienciaMaxima = value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::setEquipo(const ulong_t& value)
{
	assert(&value != nullptr);
	this->equipo = value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::setPVP(const bool& value)
{
	assert(&value != nullptr);
	this->pvp = value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::setFuegoAmigo(const bool& value)
{
	assert(&value != nullptr);
	this->fuegoAmigo = value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::setRaza(const LlanyLib::Juego::Enums::Raza& value)
{
	assert(&value != nullptr);
	this->raza = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Stats::Stats::addNivel(const ulong_t& value)
{
	assert(&value != nullptr);
	this->nivel += value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::addExperiencia(const ulong_t& value)
{
	assert(&value != nullptr);
	this->experiencia += value;
}
void LlanyLib::Juego::Objetos::Stats::Stats::addExperienciaMaxima(const ulong_t& value)
{
	assert(&value != nullptr);
	this->experienciaMaxima += value;
}
#pragma endregion
#pragma region Punteros
LlanyLib::Juego::Objetos::Stats::Critico* LlanyLib::Juego::Objetos::Stats::Stats::getCriticoBase() const
{
	return this->criticoBase;
}
LlanyLib::Juego::Objetos::Stats::Critico* LlanyLib::Juego::Objetos::Stats::Stats::getCritico() const
{
	return this->critico;
}
LlanyLib::Juego::Objetos::Stats::Ofensivos* LlanyLib::Juego::Objetos::Stats::Stats::getOfensivos() const
{
	return this->ofensivos;
}
LlanyLib::Juego::Objetos::Stats::Defensa* LlanyLib::Juego::Objetos::Stats::Stats::getDefensa() const
{
	return this->defensa;
}
LlanyLib::Juego::Objetos::Stats::Energia* LlanyLib::Juego::Objetos::Stats::Stats::getEnergiaActual() const
{
	return this->energiaActual;
}
LlanyLib::Juego::Objetos::Stats::Energia* LlanyLib::Juego::Objetos::Stats::Stats::getEnergiaMaxima() const
{
	return this->energiaMaxima;
}
LlanyLib::Juego::Objetos::Stats::Resistencia* LlanyLib::Juego::Objetos::Stats::Stats::getContadorResistencia() const
{
	return this->contadorResistencias;
}
LlanyLib::Juego::Objetos::Stats::Resistencia* LlanyLib::Juego::Objetos::Stats::Stats::getResistenciaMaxima() const
{
	return this->resistenciasMaximas;
}
LlanyLib::Juego::Objetos::Stats::Survival* LlanyLib::Juego::Objetos::Stats::Stats::getSurvivalActual() const
{
	return this->survivalActual;
}
LlanyLib::Juego::Objetos::Stats::Survival* LlanyLib::Juego::Objetos::Stats::Stats::getSurvivalMaximo() const
{
	return this->survivalMax;
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Stats::Stats::igual(const Stats& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
	if(this->raza != other.raza)
	if (this->nivel == other.nivel)
	if (this->experiencia == other.experiencia)
	if (this->experienciaMaxima == other.experienciaMaxima)
	if (this->criticoBase->igual(*other.criticoBase))
	if (this->critico->igual(*other.critico))
	if (this->ofensivos->igual(*other.ofensivos))
	if (this->defensa->igual(*other.defensa))
	if (this->energiaActual->igual(*other.energiaActual))
	if (this->energiaMaxima->igual(*other.energiaMaxima))
	if (this->contadorResistencias->igual(*other.contadorResistencias))
	if (this->resistenciasMaximas->igual(*other.resistenciasMaximas))
	if (this->survivalActual->igual(*other.survivalActual))
	if (this->survivalMax->igual(*other.survivalMax))
		temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Stats::Stats::operator==(const Stats& other) const
{
	return LlanyLib::Juego::Objetos::Stats::Stats::igual(other);
}
bool LlanyLib::Juego::Objetos::Stats::Stats::operator!=(const Stats& other) const
{
	return !LlanyLib::Juego::Objetos::Stats::Stats::igual(other);
}
LlanyLib::Juego::Objetos::Stats::Stats* LlanyLib::Juego::Objetos::Stats::Stats::operator+(const Stats& other)
{
	assert(&other != nullptr);
	Stats* result = new Stats(*this);
	result->operator+=(other);
	return result;
}
LlanyLib::Juego::Objetos::Stats::Stats* LlanyLib::Juego::Objetos::Stats::Stats::operator-(const Stats& other)
{
	assert(&other != nullptr);
	Stats* result = new Stats(*this);
	result->operator-=(other);
	return result;
}
/*LlanyLib::Juego::Objetos::Stats* LlanyLib::Juego::Objetos::Stats::Stats::operator+(const StatsEquipables& other)
{
	assert(&other != nullptr);
	Stats result;
	result = *this;
	result += other;
	return result;
}
LlanyLib::Juego::Objetos::Stats* LlanyLib::Juego::Objetos::Stats::Stats::operator-(const StatsEquipables& other)
{
	assert(&other != nullptr);
	Stats result;
	result = *this;
	result -= other;
	return result;
}*/
void LlanyLib::Juego::Objetos::Stats::Stats::operator+=(const Stats& other)
{
	assert(&other != nullptr);
	this->criticoBase->operator+=(*other.criticoBase);
	this->critico->operator+=(*other.critico);
	this->ofensivos->operator+=(*other.ofensivos);
	this->defensa->operator+=(*other.defensa);
	this->energiaActual->operator+=(*other.energiaActual);
	this->energiaMaxima->operator+=(*other.energiaMaxima);
	this->contadorResistencias->operator+=(*other.contadorResistencias);
	this->resistenciasMaximas->operator+=(*other.resistenciasMaximas);
	this->survivalActual->operator+=(*other.survivalActual);
	this->survivalMax->operator+=(*other.survivalMax);
}
void LlanyLib::Juego::Objetos::Stats::Stats::operator-=(const Stats& other)
{
	assert(&other != nullptr);
	this->criticoBase->operator-=(*other.criticoBase);
	this->critico->operator-=(*other.critico);
	this->ofensivos->operator-=(*other.ofensivos);
	this->defensa->operator-=(*other.defensa);
	this->energiaActual->operator-=(*other.energiaActual);
	this->energiaMaxima->operator-=(*other.energiaMaxima);
	this->contadorResistencias->operator-=(*other.contadorResistencias);
	this->resistenciasMaximas->operator-=(*other.resistenciasMaximas);
	this->survivalActual->operator-=(*other.survivalActual);
	this->survivalMax->operator-=(*other.survivalMax);
}
/*void LlanyLib::Juego::Objetos::Stats::Stats::operator+=(const StatsEquipables& other)
{
	assert(&other != nullptr);
	this->criticoBase->operator+=(*other.getCriticoBase());
	this->critico->operator+=(*other.getCritico());
	this->ofensivos->operator+=(*other.getOfensivos());
	this->defensa->operator+=(*other.getDefensa());
	this->energiaMaxima->operator+=(*other.getEnergia());
	this->resistenciasMaximas->operator+=(*other.getResistencia());
	this->survivalMax->operator+=(*other.getSurvival());
}
void LlanyLib::Juego::Objetos::Stats::Stats::operator-=(const StatsEquipables& other)
{
	assert(&other != nullptr);
	this->criticoBase->operator-=(*other.getCriticoBase());
	this->critico->operator-=(*other.getCritico());
	this->ofensivos->operator-=(*other.getOfensivos());
	this->defensa->operator-=(*other.getDefensa());
	this->energiaMaxima->operator-=(*other.getEnergia());
	this->resistenciasMaximas->operator-=(*other.getResistencia());
	this->survivalMax->operator-=(*other.getSurvival());
}*/
#pragma endregion
#pragma region Otros
#pragma region Reajustar Energia
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarTodasLasEnergias() const
{
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarSalud();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarResistencia();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarMana();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarCarga();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarIra();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarDivinidad();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarEnergia();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarFlujo();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarSangre();
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarSalud() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarSalud();
	this->energiaMaxima->reajustarSalud();
	// Reajustes por arriba
	if (this->energiaActual->getSalud() > this->energiaMaxima->getSalud())
		this->energiaActual->setSalud(this->energiaMaxima->getSalud());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarResistencia() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarResistencia();
	this->energiaMaxima->reajustarResistencia();
	// Reajustes por arriba
	if (this->energiaActual->getResistencia() > this->energiaMaxima->getResistencia())
		this->energiaActual->setResistencia(this->energiaMaxima->getResistencia());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarMana() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarMana();
	this->energiaMaxima->reajustarMana();
	// Reajustes por arriba
	if (this->energiaActual->getMana() > this->energiaMaxima->getMana())
		this->energiaActual->setMana(this->energiaMaxima->getMana());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarCarga() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarCarga();
	this->energiaMaxima->reajustarCarga();
	// Reajustes por arriba
	if (this->energiaActual->getCarga() > this->energiaMaxima->getCarga())
		this->energiaActual->setCarga(this->energiaMaxima->getCarga());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarIra() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarIra();
	this->energiaMaxima->reajustarIra();
	// Reajustes por arriba
	if (this->energiaActual->getIra() > this->energiaMaxima->getIra())
		this->energiaActual->setIra(this->energiaMaxima->getIra());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarDivinidad() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarDivinidad();
	this->energiaMaxima->reajustarDivinidad();
	// Reajustes por arriba
	if (this->energiaActual->getDivinidad() > this->energiaMaxima->getDivinidad())
		this->energiaActual->setDivinidad(this->energiaMaxima->getDivinidad());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarEnergia() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarEnergia();
	this->energiaMaxima->reajustarEnergia();
	// Reajustes por arriba
	if (this->energiaActual->getEnergia() > this->energiaMaxima->getEnergia())
		this->energiaActual->setEnergia(this->energiaMaxima->getEnergia());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarFlujo() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarFlujo();
	this->energiaMaxima->reajustarFlujo();
	// Reajustes por arriba
	if (this->energiaActual->getFlujo() > this->energiaMaxima->getFlujo())
		this->energiaActual->setFlujo(this->energiaMaxima->getFlujo());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarSangre() const
{
	// Reajustes por debajo
	this->energiaActual->reajustarSangre();
	this->energiaMaxima->reajustarSangre();
	// Reajustes por arriba
	if (this->energiaActual->getSangre() > this->energiaMaxima->getSangre())
		this->energiaActual->setSangre(this->energiaMaxima->getSangre());
}
#pragma endregion
#pragma region Reajustar Survival
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarTodasLosSurvival() const
{
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarHambre();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarSed();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarCansancio();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarOxigeno();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarBlindaje();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarRadiacion();
	LlanyLib::Juego::Objetos::Stats::Stats::reajustarOxido();
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarHambre() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarHambre();
	this->survivalMax->reajustarHambre();
	// Reajustes por arriba
	if (this->survivalActual->getHambre() > this->survivalMax->getHambre())
		this->survivalActual->setHambre(this->survivalMax->getHambre());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarSed() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarSed();
	this->survivalMax->reajustarSed();
	// Reajustes por arriba
	if (this->survivalActual->getSed() > this->survivalMax->getSed())
		this->survivalActual->setSed(this->survivalMax->getSed());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarCansancio() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarCansancio();
	this->survivalMax->reajustarCansancio();
	// Reajustes por arriba
	if (this->survivalActual->getCansancio() > this->survivalMax->getCansancio())
		this->survivalActual->setCansancio(this->survivalMax->getCansancio());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarOxigeno() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarOxigeno();
	this->survivalMax->reajustarOxigeno();
	// Reajustes por arriba
	if (this->survivalActual->getOxigeno() > this->survivalMax->getOxigeno())
		this->survivalActual->setOxigeno(this->survivalMax->getOxigeno());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarBlindaje() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarBlindaje();
	this->survivalMax->reajustarBlindaje();
	// Reajustes por arriba
	if (this->survivalActual->getBlindaje() > this->survivalMax->getBlindaje())
		this->survivalActual->setBlindaje(this->survivalMax->getBlindaje());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarRadiacion() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarRadiacion();
	this->survivalMax->reajustarRadiacion();
	// Reajustes por arriba
	if (this->survivalActual->getRadiacion() > this->survivalMax->getRadiacion())
		this->survivalActual->setRadiacion(this->survivalMax->getRadiacion());
}
void LlanyLib::Juego::Objetos::Stats::Stats::reajustarOxido() const
{
	// Reajustes por debajo
	this->survivalActual->reajustarOxido();
	this->survivalMax->reajustarOxido();
	// Reajustes por arriba
	if (this->survivalActual->getOxido() > this->survivalMax->getOxido())
		this->survivalActual->setOxido(this->survivalMax->getOxido());
}
#pragma endregion
#pragma endregion
