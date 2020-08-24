#pragma once
#ifndef STATS_STATS_OBJECT_JUEGO_HPP_
#define STATS_STATS_OBJECT_JUEGO_HPP_

#include "../../Enums/StatsEnum.hpp"
#include "../../../Math/Libs/MathTypes.h"

#define MAX_LV 65400

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			namespace Stats {
				class Critico;
				class Ofensivos;
				class Defensa;
				class Energia;
				class Resistencia;
				class Survival;
				//class StatsEquipables;
				//class EstadoPasivo;
				//class EstadoPseudoPasivo;
				class Stats
				{
					protected:
						#pragma region Punteros
						// Multiplicador de daño base
						Critico* criticoBase;
						// Multiplicador de daño critico
						Critico* critico;
						// Stats Ofensivos
						Ofensivos* ofensivos;
						// Defensa actual
						Defensa* defensa;
						// Energias actuales (0 -> energiaMaxima)
						Energia* energiaActual;
						// Energias maximas (0 -> INF)
						Energia* energiaMaxima;
						// Contador de la acumulacion de cierto estado (0 -> resistenciasMaximas)
						Resistencia* contadorResistencias;
						// Maxima acumulacion para adquirir el estado (0 -> [INF o 200]
						Resistencia* resistenciasMaximas;
						// Contador de los stats de tipo survival (0 - survivalMax)
						Survival* survivalActual;
						// Max stat de tipo survival (0 -> INF)
						Survival* survivalMax;
						#pragma endregion
						#pragma region Varibales
						// Guarda el nivel y la experiencia de la clase
						ulong_t nivel;
						ulong_t experiencia;
						ulong_t experienciaMaxima;
						// 
						ulong_t equipo;
						bool pvp;
						bool fuegoAmigo;

						Enums::Raza raza;
						#pragma endregion
					public:
						#pragma region Constructores
						Stats();
						//Stats(const String& contenidoJSON);
						Stats(const Stats& other);
						bool operator=(const Stats& other);
						~Stats();
						#pragma endregion
						#pragma region Getters
						ulong_t getNivel() const;
						ulong_t getExperiencia() const;
						ulong_t getExperienciaMaxima() const;
						ulong_t getEquipo() const;
						bool getPVP() const;
						bool getFuegoAmigo() const;
						Enums::Raza getRaza() const;
						#pragma endregion
						#pragma region Setters
						void setNivel(const ulong_t& value);
						void setExperiencia(const ulong_t& value);
						void setExperienciaMaxima(const ulong_t& value);
						void setEquipo(const ulong_t& value);
						void setPVP(const bool& value);
						void setFuegoAmigo(const bool& value);
						void setRaza(const Enums::Raza& value);
						#pragma endregion
						#pragma region Adders
						void addNivel(const ulong_t& value);
						void addExperiencia(const ulong_t& value);
						void addExperienciaMaxima(const ulong_t& value);
						#pragma endregion
						#pragma region Punteros
						Critico* getCriticoBase() const;
						Critico* getCritico() const;
						Ofensivos* getOfensivos() const;
						Defensa* getDefensa() const;
						Energia* getEnergiaActual() const;
						Energia* getEnergiaMaxima() const;
						Resistencia* getContadorResistencia() const;
						Resistencia* getResistenciaMaxima() const;
						Survival* getSurvivalActual() const;
						Survival* getSurvivalMaximo() const;
						#pragma endregion
						#pragma region Compares
						bool igual(const Stats& other) const;
						//bool similar(const Stats& other) const;
						#pragma endregion
						#pragma region Operators
						bool operator==(const Stats& other) const;
						bool operator!=(const Stats& other) const;

						Stats* operator+(const Stats& other);
						Stats* operator-(const Stats& other);
						//Stats operator+(const StatsEquipables& other);
						//Stats operator-(const StatsEquipables& other);

						void operator+=(const Stats& other);
						void operator-=(const Stats& other);
						//void operator+=(const StatsEquipables& other);
						//void operator-=(const StatsEquipables& other);
						#pragma endregion
						#pragma region Otros
						#pragma region Reajustes
						#pragma region Reajustar Energia
						// Reajusta todas las energias por debajo y por encima
						void reajustarTodasLasEnergias() const;
						// Reajusta la salud por debajo (0.0)
						// Reajusta la Maxsalud por debajo (0.0)
						// Reajusta la salud por encima (MAXsalud)
						void reajustarSalud() const;
						// Reajusta la resistencia por debajo (0.0)
						// Reajusta la Maxresistencia por debajo (0.0)
						// Reajusta la resistencia por encima (MAXresistencia)
						void reajustarResistencia() const;
						// Reajusta la mana por debajo (0.0)
						// Reajusta la Maxmana por debajo (0.0)
						// Reajusta la mana por encima (MAXmana)
						void reajustarMana() const;
						// Reajusta la carga por debajo (0.0)
						// Reajusta la Maxcarga por debajo (0.0)
						// Reajusta la carga por encima (MAXcarga)
						void reajustarCarga() const;
						// Reajusta la ira por debajo (0.0)
						// Reajusta la Maxira por debajo (0.0)
						// Reajusta la ira por encima (MAXira)
						void reajustarIra() const;
						// Reajusta la divinidad por debajo (0.0)
						// Reajusta la Maxdivinidad por debajo (0.0)
						// Reajusta la divinidad por encima (MAXdivinidad)
						void reajustarDivinidad() const;
						// Reajusta la energia por debajo (0.0)
						// Reajusta la Maxenergia por debajo (0.0)
						// Reajusta la energia por encima (MAXenergia)
						void reajustarEnergia() const;
						// Reajusta la flujo por debajo (0.0)
						// Reajusta la Maxflujo por debajo (0.0)
						// Reajusta la flujo por encima (MAXflujo)
						void reajustarFlujo() const;
						// Reajusta la sangre por debajo (0.0)
						// Reajusta la Maxsangre por debajo (0.0)
						// Reajusta la sangre por encima (MAXsangre)
						void reajustarSangre() const;
						#pragma endregion
						#pragma region Reajustar Survival
						// Reajusta todas las energias por debajo y por encima
						void reajustarTodasLosSurvival() const;
						// Reajusta la hambre por debajo (0.0)
						// Reajusta la Maxhambre por debajo (0.0)
						// Reajusta la hambre por encima (MAXhambre)
						void reajustarHambre() const;
						// Reajusta la sed por debajo (0.0)
						// Reajusta la Maxsed por debajo (0.0)
						// Reajusta la sed por encima (MAXsed)
						void reajustarSed() const;
						// Reajusta la cansancio por debajo (0.0)
						// Reajusta la Maxcansancio por debajo (0.0)
						// Reajusta la cansancio por encima (MAXcansancio)
						void reajustarCansancio() const;
						// Reajusta la oxigeno por debajo (0.0)
						// Reajusta la Maxoxigeno por debajo (0.0)
						// Reajusta la oxigeno por encima (MAXoxigeno)
						void reajustarOxigeno() const;
						// Reajusta la blindaje por debajo (0.0)
						// Reajusta la Maxblindaje por debajo (0.0)
						// Reajusta la blindaje por encima (MAXblindaje)
						void reajustarBlindaje() const;
						// Reajusta la radiacion por debajo (0.0)
						// Reajusta la Maxradiacion por debajo (0.0)
						// Reajusta la radiacion por encima (MAXradiacion)
						void reajustarRadiacion() const;
						// Reajusta la oxido por debajo (0.0)
						// Reajusta la Maxoxido por debajo (0.0)
						// Reajusta la oxido por encima (MAXoxido)
						void reajustarOxido() const;
						#pragma endregion
						#pragma endregion
						#pragma region Estados
						#pragma region Pasivos

						#pragma endregion
						#pragma region PseudoPasivos

						#pragma endregion
						#pragma endregion
						#pragma endregion
						// Metodo JSON
						//String toJSON();
				};
			}
		}
	}
}
#endif // !STATS_STATS_OBJECT_JUEGO_HPP_
