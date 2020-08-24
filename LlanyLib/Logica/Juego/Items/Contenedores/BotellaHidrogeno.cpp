#include "BotellaHidrogeno.hpp"

#include "../../Enums/ItemEnum.hpp"
#include "../../../Basic/Objetos/String.hpp"

#include "../Elementos/Hidrogeno.hpp"

#include "../../Gestores/GestorItems.hpp"

bool LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::sePuedeAñadir(const Item* item) const
{
	return
		((GESTOR_ITEMS->getID(LlanyLib_Juego_Items_Generados_Elementos_Hidrogeno) == item->getItemID())
			&& Contenedor::cabeItem(item));
}

LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::BotellaHidrogeno()
{
	this->valorActual = 1.0;
	this->valorMaximo = 1.0;
	this->durabilidad = 1.0;
	this->durabilidadMaxima = 1.0;
	this->cantidad = 1;
	this->peso = 1;

	//this->itemShowName = new Basic::Objetos::String("BotellaPlastico");

	this->tipoDeObjeto = Enums::TipoObjeto::Contenedor;
	this->tipoDeMaterial = Enums::TipoDeMaterial::Solido;

	this->temperatura = 0;
	this->resistenciaMaterial = 0.0;


	// Contenedor
	this->capacidadMaxima = 100.0;
	this->capacidadOcupada = 0.0;
	this->tipoDeMaterialContenible = Enums::TipoDeMaterial::Gaseoso;
}
LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::BotellaHidrogeno(const BotellaHidrogeno& other)
{
	BotellaHidrogeno::operator=(other);
}
bool LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::operator=(const BotellaHidrogeno& other)
{
	return Contenedor::operator=(other);
}
LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::~BotellaHidrogeno(){}

LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::clone() const
{
	return new BotellaHidrogeno(*this);
}
void LlanyLib::Juego::Items::Generados::Contenedores::BotellaHidrogeno::deleteItem()
{
	delete this;
}
