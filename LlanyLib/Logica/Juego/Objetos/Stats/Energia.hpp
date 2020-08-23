#pragma once
#ifndef ENERGIA_OBJECT_JUEGO_HPP_
#define ENERGIA_OBJECT_JUEGO_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			class Energia
			{
				private:
					#pragma region Variables
					// Si llega a 0 el player muere y puede revivir en un tiempo
					// Para los mechas es como durabilidad
					// El valor va desde Max a 0
					double salud;
					// Energia fisica del player, en el caso de los robot, es como la bateria 
					// Tambien se usa para ataques fisicos
					// Tambien se usa para habilidades fisicas
					double resistencia;
					// Energia para usar Hechizos 
					double mana;
					// Energia de los hechizos (Alquimia y varios) 
					double carga;
					// 
					double ira;
					// Energia para habilidades de tipo divino etc
					double divinidad;
					// Acumulacion de energia universal.
					// Se puede transformar a cualquier otro tipo de energia
					// Conversion actual:
					// 1 Energia = 1000 Mana
					// 1 Energia = 1000 Resistencia
					// 1 Energia = 100 Carga
					// 1 Energia = 100 Ira
					double energia;
					//
					double flujo;
					// Puede parecer salud, y por supuesto afecta a esta pero no es exactamente lo mismo
					double sangre;
					#pragma endregion
				public:
					#pragma region Constructores
					Energia();
					//Energia(const String& contenidoJSON);
					Energia(const Energia& other);
					bool operator=(const Energia& other);
					~Energia();
					#pragma endregion
					#pragma region Getters	
					double getSalud() const;
					double getResistencia() const;
					double getMana() const;
					double getCarga() const;
					double getIra() const;
					double getDivinidad() const;
					double getEnergia() const;
					double getFlujo() const;
					double getSangre() const;
					#pragma endregion
					#pragma region Setters	
					void setSalud(const double& value);
					void setResistencia(const double& value);
					void setMana(const double& value);
					void setCarga(const double& value);
					void setIra(const double& value);
					void setDivinidad(const double& value);
					void setEnergia(const double& value);
					void setFlujo(const double& value);
					void setSangre(const double& value);
					#pragma endregion
					#pragma region Adders
					void addSalud(const double& value);
					void addResistencia(const double& value);
					void addMana(const double& value);
					void addCarga(const double& value);
					void addIra(const double& value);
					void addDivinidad(const double& value);
					void addEnergia(const double& value);
					void addFlujo(const double& value);
					void addSangre(const double& value);
					#pragma endregion
					#pragma region Compares
					bool igual(const Energia& other) const;
					//bool similar(const Energia& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Energia& other) const;
					bool operator!=(const Energia& other) const;
					void operator+=(const Energia& other);
					void operator-=(const Energia& other);
					Energia* operator+(const Energia& other);
					Energia* operator-(const Energia& other);
					#pragma endregion
					#pragma region Reajustar
					void reajustarTodo();
					void reajustarSalud();
					void reajustarResistencia();
					void reajustarMana();
					void reajustarCarga();
					void reajustarIra();
					void reajustarDivinidad();
					void reajustarEnergia();
					void reajustarFlujo();
					void reajustarSangre();
					#pragma endregion
					// Metodo JSON
					//String toJSON() const;
			};
		}
	}
}
#endif // !ENERGIA_OBJECT_JUEGO_HPP_
