#include "BotellaPlastico.hpp"

#include "../../Enums/ItemEnum.hpp"
#include "../../../Basic/Objetos/String.hpp"

#include "../Elementos/Hidrogeno.hpp"

LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::BotellaPlastico() : Contenedor()
{
	this->valorActual = 1.0;
	this->valorMaximo = 1.0;
	this->durabilidad = 1.0;
	this->durabilidadMaxima = 1.0;
	this->cantidad = 1;
	this->peso = 1;

	//this->itemShowName = new Basic::Objetos::String("BotellaPlastico");

	this->tipoDeObjeto = Enum::TipoObjeto::Contenedor;
	this->tipoDeMaterial = Enum::TipoDeMaterial::Solido;

	this->temperatura = 10;
	this->resistenciaMaterial = 0.0;


	// Contenedor
	this->capacidadMaxima = 100.0;
	this->capacidadOcupada = 0.0;
	this->tipoDeMaterialContenible = Enum::TipoDeMaterial::Liquido;


	/*Item* tmp = nullptr;

	tmp = BotellaPlastico::addItem(new Elementos::Hidrogeno());
	if (tmp != nullptr)
		delete tmp;

	tmp = BotellaPlastico::addItem(new Elementos::Hidrogeno());
	if (tmp != nullptr)
		delete tmp;

	tmp = BotellaPlastico::addItem(new Elementos::Hidrogeno(3));
	if (tmp != nullptr)
		delete tmp;*/
}
LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::BotellaPlastico(const BotellaPlastico& other) : BotellaPlastico()
{
	BotellaPlastico::operator=(other);
}
bool LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::operator=(const BotellaPlastico& other)
{
	return Contenedor::operator=(other);
}
LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::~BotellaPlastico(){}
LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::clone() const
{
	return new BotellaPlastico(*this);
}
void LlanyLib::Juego::Items::Generados::Contenedores::BotellaPlastico::deleteItem()
{
	delete this;
}
