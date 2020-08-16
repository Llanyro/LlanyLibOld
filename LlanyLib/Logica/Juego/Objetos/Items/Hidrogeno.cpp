#include "Hidrogeno.hpp"

#include "../../../Basic/Objetos/String.hpp"
#include "../../Enums/ObjetosEnum.hpp"

LlanyLib::Juego::Items::Generados::Hidrogeno::Hidrogeno()
	: Hidrogeno(1.0, Enums::TipoDeMaterial::Liquido){}
LlanyLib::Juego::Items::Generados::Hidrogeno::Hidrogeno(const double& cantidad, const Enums::TipoDeMaterial& material)
{
	this->valorActual = 1.0;
	this->valorMaximo = 1.0;
	this->durabilidad = 1.0;
	this->durabilidadMaxima = 1.0;
	this->cantidad = cantidad;
	this->peso = 0.07;

	this->itemName = new Basic::Objetos::String("Hidrogeno");
	this->tipoDeObjeto = Enums::TipoObjeto::ElementoPuro;
	this->tipoDeMaterial = material;

	this->temperatura = 20.28;
	this->resistenciaMaterial = 0.0;
}
LlanyLib::Juego::Items::Generados::Hidrogeno::Hidrogeno(const double& cantidad)
	: Hidrogeno(cantidad, Enums::TipoDeMaterial::Liquido){}
LlanyLib::Juego::Items::Generados::Hidrogeno::~Hidrogeno(){}
