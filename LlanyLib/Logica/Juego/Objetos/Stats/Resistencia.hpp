#pragma once
#ifndef RESISTENCIA_OBJECT_JUEGO_HPP_
#define RESISTENCIA_OBJECT_JUEGO_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
			class JSONBuilder;
		}
	}
	namespace Juego {
		namespace Objetos {
			// Contenedores para recibir un debuff
			class Resistencia
			{
				private:
					#pragma region Variables
					double veneno;
					double sangrado;
					double congelado;
					double quemadura;
					double maldicion;
					double electrocutado;
					double sobrecargado;
					double isolacion;
					double anemia;
					double nausea;
					#pragma endregion
				public:
					#pragma region Constructores
					Resistencia();
					//Resistencia(const String& contenidoJSON);
					Resistencia(const Resistencia& other);
					bool operator=(const Resistencia& other);
					~Resistencia();
					#pragma endregion
					#pragma region Getters	
					double getVeneno() const;
					double getSangrado() const;
					double getCongelado() const;
					double getQuemadura() const;
					double getMaldicion() const;
					double getElectrocutado() const;
					double getSobrecargado() const;
					double getIsolacion() const;
					double getAnemia() const;
					double getNausea() const;
					#pragma endregion
					#pragma region Setters	
					void setVeneno(const double& value);
					void setSangrado(const double& value);
					void setCongelado(const double& value);
					void setQuemadura(const double& value);
					void setMaldicion(const double& value);
					void setElectrocutado(const double& value);
					void setSobrecargado(const double& value);
					void setIsolacion(const double& value);
					void setAnemia(const double& value);
					void setNausea(const double& value);
					#pragma endregion
					#pragma region Adders	
					void addVeneno(const double& value);
					void addSangrado(const double& value);
					void addCongelado(const double& value);
					void addQuemadura(const double& value);
					void addMaldicion(const double& value);
					void addElectrocutado(const double& value);
					void addSobrecargado(const double& value);
					void addIsolacion(const double& value);
					void addAnemia(const double& value);
					void addNausea(const double& value);
					#pragma endregion
					#pragma region Compares
					bool igual(const Resistencia& other) const;
					//bool similar(const Resistencia& other) const;
					#pragma endregion
					#pragma region Operators
					bool operator==(const Resistencia& other) const;
					bool operator!=(const Resistencia& other) const;
					void operator+=(const Resistencia& other);
					void operator-=(const Resistencia& other);
					Resistencia* operator+(const Resistencia& other);
					Resistencia* operator-(const Resistencia& other);
					#pragma endregion
					#pragma region Reajustar
					void reajustarTodo();
					void reajustarVeneno();
					void reajustarSangrado();
					void reajustarCongelado();
					void reajustarQuemadura();
					void reajustarMaldicion();
					void reajustarElectrocutado();
					void reajustarSobrecargado();
					void reajustarIsolacion();
					void reajustarAnemia();
					void reajustarNausea();
					#pragma endregion
					// Metodo JSON
					//String toJSON() const;
			};
		}
	}
}
#endif // !RESISTENCIA_OBJECT_JUEGO_HPP_
