#pragma once
#ifndef SURVIVAL_OBJECT_JUEGO_HPP_
#define SURVIVAL_OBJECT_JUEGO_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			class Survival
			{
				private:
					#pragma region Variables
						// Cuando llega a 0 se pone un debuff que mantiene todas tus stats a 1
						// El valor va desde Max a 0
						double hambre;
						// Cuando llega a 0 se empieza a consumir vida por tiempo
						// El valor va desde Max a 0
						double sed;
						// Segun el cansancio los efectos de las habilidades, ataques, etc son menos efectivos
						// Si se llega a 0(Cansado), se te pone el debuff de cansado y empiezas a ver cosas que no existen para los demas
						// El valor va desde 0 a Max
						double cansancio;
						// Al llegar a 0 entras en un estado que te baja la vida por segundo aunque puedes moverte por 3 segundos mas
						// Al pasar el tiempo extra, no te podras mover y tu vida seguira bajando
						// Con los mechas es Oxido, y tiene efectos diferentes
						// El valor va desde Max a 0
						double oxigeno;
						// Segunda barra de salud
						// Generalmente no se regenera de ninguna manera
						// El valor va desde Max a 0
						double blindaje;
						// Al recoger radiacion este contador se incrementa
						// Al llegar al maximo, tienes un 70% de probabilidad de morir
						// Las otras 29% posibilidades son buffs negativos 
						// Y el 1% restante es un buff positivo (Incluido subir de nivel instantaneamente)
						// El valor va desde 0 a Max
						double radiacion;
						// Al llegar a un tope, se reduce la velocidad de movimiento, la velocidad de ataque, aumenta el cd de habilidades y hechizos
						// Solo afecta a los mechas
						// 
						// El valor va desde 0 a Max
						double oxido;
						#pragma endregion
				public:
					#pragma region Constructores
						Survival();
						//Survival(const String& contenidoJSON);
						Survival(const Survival& other);
						bool operator=(const Survival& other);
						~Survival();
						#pragma endregion
					#pragma region Getters
						double getHambre() const;
						double getSed() const;
						double getCansancio() const;
						double getOxigeno() const;
						double getBlindaje() const;
						double getRadiacion() const;
						double getOxido() const;
						#pragma endregion
					#pragma region Setters
						void setHambre(const double& value);
						void setSed(const double& value);
						void setCansancio(const double& value);
						void setOxigeno(const double& value);
						void setBlindaje(const double& value);
						void setRadiacion(const double& value);
						void setOxido(const double& value);
						#pragma endregion
					#pragma region Adders
						void addHambre(const double& value);
						void addSed(const double& value);
						void addCansancio(const double& value);
						void addOxigeno(const double& value);
						void addBlindaje(const double& value);
						void addRadiacion(const double& value);
						void addOxido(const double& value);
						#pragma endregion
					#pragma region Compares
						bool igual(const Survival& other) const;
						//bool similar(const Stats& other) const;
						#pragma endregion
					#pragma region Operators
						bool operator==(const Survival& other) const;
						bool operator!=(const Survival& other) const;
						void operator+=(const Survival& other);
						void operator-=(const Survival& other);
						Survival* operator+(const Survival& other);
						Survival* operator-(const Survival& other);
						#pragma endregion
					#pragma region Reajustar
						void reajustarTodo();
						void reajustarHambre();
						void reajustarSed();
						void reajustarCansancio();
						void reajustarOxigeno();
						void reajustarBlindaje();
						void reajustarRadiacion();
						void reajustarOxido();
						#pragma endregion
					// Metodo JSON
					//String toJSON() const;
			};
		}
	}
}
#endif // !SURVIVAL_OBJECT_JUEGO_HPP_
