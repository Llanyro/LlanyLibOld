#include "Item.hpp"

#include "../../Enums/ObjetosEnum.hpp"
#include "../../../Basic/Objetos/String.hpp"
#include "../../../Basic/Objetos/JSONBuilder.hpp"

#pragma region Constructores
LlanyLib::Juego::Items::Item::Item()
{
	this->itemName = nullptr;
	this->tipoDeMaterial = Enums::TipoDeMaterial::Irreal;
	this->tipoDeObjeto = Enums::TipoObjeto::Objeto;

	this->valorActual = 0.0;
	this->valorMaximo = 0.0;
	this->durabilidad = 0.0;
	this->durabilidadMaxima = 0.0;
	this->cantidad = 0.0;
	this->peso = 0.0;

	this->temperatura = 0.0;
	this->resistenciaMaterial = 0.0;
}
LlanyLib::Juego::Items::Item::~Item()
{
	if (this->itemName != nullptr)
		delete this->itemName;
}
#pragma endregion
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Items::Item::getItemName() const
{
	return this->itemName;
}
LlanyLib::Juego::Enums::TipoDeMaterial LlanyLib::Juego::Items::Item::getTipoDeMaterial() const
{
	return this->tipoDeMaterial;
}
LlanyLib::Juego::Enums::TipoObjeto LlanyLib::Juego::Items::Item::getTipoObjeto() const
{
	return this->tipoDeObjeto;
}
double LlanyLib::Juego::Items::Item::getValorActual() const
{
	return this->valorActual;
}
double LlanyLib::Juego::Items::Item::getValorMaximo() const
{
	return this->valorMaximo;
}
double LlanyLib::Juego::Items::Item::getDurabilidad() const
{
	return this->durabilidad;
}
double LlanyLib::Juego::Items::Item::getDurabilidadMaxima() const
{
	return this->durabilidadMaxima;
}
double LlanyLib::Juego::Items::Item::getCantidad() const
{
	return this->cantidad;
}
double LlanyLib::Juego::Items::Item::getPeso() const
{
	return this->peso;
}
double LlanyLib::Juego::Items::Item::getTemperatura() const
{
	return this->temperatura;
}
double LlanyLib::Juego::Items::Item::getResistenciaTemperatura() const
{
	return this->resistenciaMaterial;
}
#pragma endregion
/*#pragma region Setters
void LlanyLib::Juego::Items::Objetos::setItemName(char const* const nombre)
{
}
void LlanyLib::Juego::Items::Objetos::setItemName(Base::Objetos::String*& nombre)
{
}
void LlanyLib::Juego::Items::Objetos::setValorActual(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setValorMaximo(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setDurabilidad(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setDurabilidadMaxima(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setCantidad(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setPeso(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setTipoDeMaterial(const Base::Enums::TipoDeMaterial& value)
{
}
void LlanyLib::Juego::Items::Objetos::setTemperatura(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::setResistenciaTemperatura(const double& value)
{
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Items::Objetos::addValorActual(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addValorMaximo(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addDurabilidad(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addDurabilidadMaxima(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addCantidad(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addPeso(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addTemperatura(const double& value)
{
}
void LlanyLib::Juego::Items::Objetos::addResistenciaTemperatura(const double& value)
{
}
#pragma endregion*/
LlanyLib::Basic::Objetos::JSONBuilder* LlanyLib::Juego::Items::Item::toJSONBuilder() const
{
	Basic::Objetos::JSONBuilder* json = new Basic::Objetos::JSONBuilder();
	json->addClearKey(new Basic::Objetos::String("itemName"), this->itemName, Basic::Objetos::JSONBuilder::PrepType::Comillas);
	json->addClear(new Basic::Objetos::String("tipoDeMaterial"), (int)this->tipoDeMaterial);
	json->addClear(new Basic::Objetos::String("tipoDeObjeto"), (int)this->tipoDeObjeto);

	json->addClear(new Basic::Objetos::String("valorActual"), this->valorActual);
	json->addClear(new Basic::Objetos::String("valorMaximo"), this->valorMaximo);
	json->addClear(new Basic::Objetos::String("durabilidad"), this->durabilidad);
	json->addClear(new Basic::Objetos::String("durabilidadMaxima"), this->durabilidadMaxima);
	json->addClear(new Basic::Objetos::String("cantidad"), this->cantidad);
	json->addClear(new Basic::Objetos::String("peso"), this->peso);

	json->addClear(new Basic::Objetos::String("temperatura"), this->temperatura);
	json->addClear(new Basic::Objetos::String("resistenciaMaterial"), this->resistenciaMaterial);

	return json;
}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Items::Item::toJSON() const
{
	LlanyLib::Basic::Objetos::JSONBuilder* build = Item::toJSONBuilder();
	LlanyLib::Basic::Objetos::String* str = build->build();
	delete build;
	return str;
}
