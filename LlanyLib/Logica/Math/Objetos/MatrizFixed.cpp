#include "MatrizFixed.hpp"

#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/Singletons/Chars.hpp"
#include "../Singletons/Random.hpp"

#include "Matriz.hpp"
#include "Racional.hpp"

#pragma region Constructores
LlanyLib::Math::Objetos::MatrizFixed::MatrizFixed()
{
	this->contenido = nullptr;
	this->columnas = 0;
	this->filas = 0;
}
LlanyLib::Math::Objetos::MatrizFixed::MatrizFixed(const Matriz& matriz) : MatrizFixed(matriz.getNumeroFilas(), matriz.getNumeroColumnas())
{
	for (size_t i = 0; i < this->filas; i++)
		for (size_t e = 0; e  < this->columnas; e ++)
			this->contenido[i][e] = *matriz.getValue(i, e);
}
LlanyLib::Math::Objetos::MatrizFixed::MatrizFixed(const size_t& filas, const size_t& columnas)
{
	this->filas = filas;
	this->columnas = columnas;
	this->contenido = new Racional*[filas];
	for (size_t i = 0; i < this->filas; i++)
		this->contenido[i] = new Racional[columnas];
}
LlanyLib::Math::Objetos::MatrizFixed::MatrizFixed(Racional** matriz, const size_t& filas, const size_t& columnas)
{
	this->contenido = matriz;
	this->filas = filas;
	this->columnas = columnas;
}
LlanyLib::Math::Objetos::MatrizFixed::~MatrizFixed()
{
	for (size_t i = 0; i < this->filas; i++)
		delete[] this->contenido[i];
	delete[] this->contenido;
}
#pragma endregion
#pragma region Getters
size_t LlanyLib::Math::Objetos::MatrizFixed::getNumeroFilas() const
{
	return this->filas;
}
size_t LlanyLib::Math::Objetos::MatrizFixed::getNumeroColumnas() const
{
	return this->columnas;
}
LlanyLib::Math::Objetos::Racional* LlanyLib::Math::Objetos::MatrizFixed::getValue(const size_t& fila, const size_t& columna) const
{
	Racional* value = nullptr;
	if (fila < this->filas && columna < this->columnas)
		value = &this->contenido[fila][columna];
	return value;
}
#pragma endregion
#pragma region Set
bool LlanyLib::Math::Objetos::MatrizFixed::setValue(const Racional& value, const size_t& fila, const size_t& columna)
{
	bool resultado = true;
	if (fila < this->filas && columna < this->columnas)
		this->contenido[fila][columna] = value;
	else resultado = false;
	return resultado;
}
#pragma endregion
#pragma region Modificadores
void LlanyLib::Math::Objetos::MatrizFixed::randomize()
{
	for (size_t i = 0; i < this->filas; i++)
		for (size_t e = 0; e < this->columnas; e++)
			this->contenido[i][e] = Racional(RANDOM->random(), RANDOM->random());
}
#pragma endregion
LlanyLib::Basic::Objetos::String* LlanyLib::Math::Objetos::MatrizFixed::toString() const
{
	Basic::Objetos::StringBuilder str;
	Racional* temp = nullptr;
	for (size_t i = 0; i < this->filas; i++){
		for (size_t e = 0; e < this->columnas; e++) {
			temp = &this->contenido[i][e];
			str.add(temp->getNumerador());
			if (temp->getDenominador() != 1) {
				str += '\\';
				str.add(temp->getDenominador());
			}
			str += ' ';
		}
		str += '\n';
	}
	return str.build();
}
