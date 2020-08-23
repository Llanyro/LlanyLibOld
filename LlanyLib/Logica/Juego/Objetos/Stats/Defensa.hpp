#pragma once
#ifndef DEFENSA_OBJECT_JUEGO_HPP_
#define DEFENSA_OBJECT_JUEGO_HPP_

#define MAX_DEF 400

#define PORCENT_DEF MAX_DEF / 100

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			class Defensa
			{
				private:
					#pragma region Variables
					double golpes;
					double cortes;
					double penetracion;
					double explosiones;
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
					Defensa();
					//Defensa(const String& contenidoJSON);
					Defensa(const Defensa& other);
					bool operator=(const Defensa& other);
					~Defensa();
					#pragma endregion
					#pragma region Getters	
					double getGolpes() const;
					double getCortes() const;
					double getPenetracion() const;
					double getExplosiones() const;
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
					void setGolpes(const double& value);
					void setCortes(const double& value);
					void setPenetracion(const double& value);
					void setExplosiones(const double& value);
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
					void addGolpes(const double& value);
					void addCortes(const double& value);
					void addPenetracion(const double& value);
					void addExplosiones(const double& value);
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
					bool igual(const Defensa& other) const;
					//bool similar(const Critico& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Defensa& other) const;
					bool operator!=(const Defensa& other) const;
					void operator+=(const Defensa& other);
					void operator-=(const Defensa& other);
					Defensa* operator+(const Defensa& other);
					Defensa* operator-(const Defensa& other);
					#pragma endregion
					#pragma region Reajustar
					void reajustarTodo();
					void reajustarGolpes();
					void reajustarCortes();
					void reajustarPenetracion();
					void reajustarExplosiones();
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
#endif // !DEFENSA_OBJECT_JUEGO_HPP_
