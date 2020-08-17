#include "BotellaPlastico.hpp"

#include "../../../Enums/ObjetosEnum.hpp"
#include "../../../../Basic/Objetos/String.hpp"

#include "../Elementos/Hidrogeno.hpp"

LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::BotellaPlastico() : Contenedor()
{
	this->valorActual = 1.0;
	this->valorMaximo = 1.0;
	this->durabilidad = 1.0;
	this->durabilidadMaxima = 1.0;
	this->cantidad = 1;
	this->peso = 1;

	this->itemName = new Basic::Objetos::String("BotellaPlastico");
	this->tipoDeObjeto = Enums::TipoObjeto::Contenedor;
	this->tipoDeMaterial = Enums::TipoDeMaterial::Solido;

	this->temperatura = 10;
	this->resistenciaMaterial = 0.0;


	// Contenedor
	this->capacidadMaxima = 100.0;
	this->capacidadOcupada = 0.0;
	this->tipoDeMaterialContenible = Enums::TipoDeMaterial::Liquido;


	Item* tmp = nullptr;

	tmp = BotellaPlastico::addItem(new Elementos::Hidrogeno());
	if (tmp != nullptr)
		delete tmp;

	tmp = BotellaPlastico::addItem(new Elementos::Hidrogeno());
	if (tmp != nullptr)
		delete tmp;

	tmp = BotellaPlastico::addItem(new Elementos::Hidrogeno(3));
	if (tmp != nullptr)
		delete tmp;
}
LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::~BotellaPlastico(){}