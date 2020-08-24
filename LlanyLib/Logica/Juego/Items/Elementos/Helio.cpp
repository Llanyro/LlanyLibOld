#include "Helio.hpp"

#include "../../Enums/ItemEnum.hpp"
#include "../../../Basic/Objetos/String.hpp"

LlanyLib::Juego::Items::Generados::Elementos::Helio::Helio()
	: Helio(1.0, Enums::TipoDeMaterial::Liquido){}
LlanyLib::Juego::Items::Generados::Elementos::Helio::Helio(const double& cantidad, const Enums::TipoDeMaterial& material)
{
	this->valorActual = 1.0;
	this->valorMaximo = 1.0;
	this->durabilidad = 1.0;
	this->durabilidadMaxima = 1.0;
	this->cantidad = cantidad;
	this->peso = 0.125;

	//this->itemShowName = new Basic::Objetos::String("Hidrogeno");

	this->tipoDeObjeto = Enums::TipoObjeto::ElementoPuro;
	this->tipoDeMaterial = material;

	this->temperatura = 5.2;
	this->resistenciaMaterial = 0.0;
}
LlanyLib::Juego::Items::Generados::Elementos::Helio::Helio(const double& cantidad)
	: Helio(cantidad, Enums::TipoDeMaterial::Liquido) {}
LlanyLib::Juego::Items::Generados::Elementos::Helio::~Helio(){}
LlanyLib::Juego::Items::Generados::Elementos::Helio::Helio(const Helio& other)
{
	Helio::operator=(other);
}
bool LlanyLib::Juego::Items::Generados::Elementos::Helio::operator=(const Helio& other)
{
	return 	Item::operator=(other);
}
LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Items::Generados::Elementos::Helio::clone() const
{
	return new Helio(*this);
}
void LlanyLib::Juego::Items::Generados::Elementos::Helio::deleteItem()
{
	delete this;
}
