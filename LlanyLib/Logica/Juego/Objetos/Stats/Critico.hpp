#pragma once
#ifndef CRITICO_OBJECT_JUEGO_HPP_
#define CRITICO_OBJECT_JUEGO_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			class Ofensivos;
			class Critico
			{
				private:
					#pragma region Variables
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
					#pragma endregion
				public:
					#pragma region Constructores
					Critico();
					//Critico(const String& contenidoJSON);
					Critico(const Critico& other);
					bool operator=(const Critico& other);
					~Critico();
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
					#pragma endregion
					#pragma region Compares
					bool igual(const Critico& other) const;
					//bool similar(const Critico& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Critico& other) const;
					bool operator!=(const Critico& other) const;
					Critico* operator+(const Critico& other);
					Critico* operator-(const Critico& other);
					void operator+=(const Critico& other);
					void operator-=(const Critico& other);
					Ofensivos* operator*(const Ofensivos& other) const;
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
					#pragma endregion
					// Metodo JSON
					//String toJSON() const;
			};
		}
	}
}
#endif // !CRITICO_OBJECT_JUEGO_HPP_
