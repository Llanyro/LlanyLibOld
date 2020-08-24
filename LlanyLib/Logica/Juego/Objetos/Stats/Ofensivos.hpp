#pragma once
#ifndef OFENSIVOS_STATS_OBJECT_JUEGO_HPP_
#define OFENSIVOS_STATS_OBJECT_JUEGO_HPP_

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
				class Ofensivos
				{
					private:
						#pragma region Varibales
						double fuerza;
						double destreza;
						double electro;
						double fuego;
						double hielo;
						double viento;
						double agua;
						double tierra;
						double oscuridad;
						double luz;
						double espiritu;
						#pragma endregion
					public:
						#pragma region Constructores
						Ofensivos();
						//Ofensivos(const String& contenidoJSON);
						Ofensivos(const Ofensivos& other);
						bool operator=(const Ofensivos& other);
						~Ofensivos();
						#pragma endregion
						#pragma region Getters	
						double getFuerza() const;
						double getDestreza() const;
						double getElectro() const;
						double getFuego() const;
						double getHielo() const;
						double getViento() const;
						double getAgua() const;
						double getTierra() const;
						double getOscuridad() const;
						double getLuz() const;
						double getEspiritu() const;
						#pragma endregion
						#pragma region Setters	
						void setFuerza(const double& value);
						void setDestreza(const double& value);
						void setElectro(const double& value);
						void setFuego(const double& value);
						void setHielo(const double& value);
						void setViento(const double& value);
						void setAgua(const double& value);
						void setTierra(const double& value);
						void setOscuridad(const double& value);
						void setLuz(const double& value);
						void setEspiritu(const double& value);
						#pragma endregion
						#pragma region Adders	
						void addFuerza(const double& value);
						void addDestreza(const double& value);
						void addElectro(const double& value);
						void addFuego(const double& value);
						void addHielo(const double& value);
						void addViento(const double& value);
						void addAgua(const double& value);
						void addTierra(const double& value);
						void addOscuridad(const double& value);
						void addLuz(const double& value);
						void addEspiritu(const double& value);
						#pragma endregion
						#pragma region Compares
						bool igual(const Ofensivos& other) const;
						//bool similar(const Ofensivos& other) const;
						#pragma endregion
						#pragma region Operators
						bool operator==(const Ofensivos& other) const;
						bool operator!=(const Ofensivos& other) const;
						void operator+=(const Ofensivos& other);
						void operator-=(const Ofensivos& other);
						Ofensivos* operator+(const Ofensivos& other);
						Ofensivos* operator-(const Ofensivos& other);
						Ofensivos* operator*(const Critico& other) const;
						#pragma endregion
						#pragma region Reajustar
						void reajustarTodo();
						void reajustarFuerza();
						void reajustarDestreza();
						void reajustarElectro();
						void reajustarFuego();
						void reajustarHielo();
						void reajustarViento();
						void reajustarAgua();
						void reajustarTierra();
						void reajustarOscuridad();
						void reajustarLuz();
						void reajustarEspiritu();
						#pragma endregion
						// Metodo JSON
						//String toJSON() const;
				};
			}
		}
	}
}
#endif // !OFENSIVOS_STATS_OBJECT_JUEGO_HPP_
