#include "Hidrogeno.hpp"

#include "../../Enums/ItemEnum.hpp"
#include "../../../Basic/Objetos/String.hpp"

LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::Hidrogeno()
	: Hidrogeno(1.0, Enums::TipoDeMaterial::Liquido){}
LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::Hidrogeno(const double& cantidad, const Enums::TipoDeMaterial& material)
{
	this->valorActual = 1.0;
	this->valorMaximo = 1.0;
	this->durabilidad = 1.0;
	this->durabilidadMaxima = 1.0;
	this->cantidad = cantidad;
	this->peso = 0.07;

	//this->itemShowName = new Basic::Objetos::String("Hidrogeno");

	this->tipoDeObjeto = Enums::TipoObjeto::ElementoPuro;
	this->tipoDeMaterial = material;

	this->temperatura = 20.28;
	this->resistenciaMaterial = 0.0;
}
LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::Hidrogeno(const double& cantidad)
	: Hidrogeno(cantidad, Enums::TipoDeMaterial::Liquido){}
LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::~Hidrogeno(){}
LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::Hidrogeno(const Hidrogeno& other) : Hidrogeno()
{
	Hidrogeno::operator=(other);
}
bool LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::operator=(const Hidrogeno& other)
{
	return Item::operator=(other);
}
LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::clone() const
{
	return new Hidrogeno(*this);
}
void LlanyLib::Juego::Items::Generados::Elementos::Hidrogeno::deleteItem()
{
	delete this;
}
