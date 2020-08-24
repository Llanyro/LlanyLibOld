#include "Item.hpp"

#include "../../../Basic/Objetos/String.hpp"
#include "../../../Basic/Objetos/JSONBuilder.hpp"

#include "../../../Math/Singletons/Math.hpp"

#include "../../Enums/ItemEnum.hpp"
#include "../../Gestores/GestorItems.hpp"

#pragma region Constructores
LlanyLib::Juego::Objetos::Items::Item::Item()
{
	this->itemID = -1;

	this->tipoDeMaterial = Enums::TipoDeMaterial::Irreal;
	this->tipoDeObjeto = Enums::TipoObjeto::Objeto;
	this->itemShowName = nullptr;

	this->valorActual = 0.0;
	this->valorMaximo = 0.0;
	this->durabilidad = 0.0;
	this->durabilidadMaxima = 0.0;
	this->cantidad = 0.0;
	this->peso = 0.0;

	this->temperatura = 0.0;
	this->resistenciaMaterial = 0.0;
}
LlanyLib::Juego::Objetos::Items::Item::Item(const Item& other) : Item()
{
	Item::operator=(other);
}
bool LlanyLib::Juego::Objetos::Items::Item::operator=(const Item& other)
{
	bool resultado = false;
	if (&other != nullptr) {
		this->itemID = other.itemID;

		this->tipoDeMaterial = other.tipoDeMaterial;
		this->tipoDeObjeto = other.tipoDeObjeto;
		if (this->itemShowName != nullptr)
			this->itemShowName->operator=(*other.itemShowName);
		else
			this->itemShowName = new Basic::Objetos::String(*other.itemShowName);

		this->valorActual = other.valorActual;
		this->valorMaximo = other.valorMaximo;
		this->durabilidad = other.durabilidad;
		this->durabilidadMaxima = other.durabilidadMaxima;
		this->cantidad = other.cantidad;
		this->peso = other.peso;

		this->temperatura = other.temperatura;
		this->resistenciaMaterial = other.resistenciaMaterial;
		resultado = true;
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Items::Item::~Item()
{
	if (this->itemShowName != nullptr)
		delete this->itemShowName;
}
#pragma endregion
#pragma region Getters
long_t LlanyLib::Juego::Objetos::Items::Item::getItemID() const
{
	return this->itemID;
}
LlanyLib::Juego::Enums::TipoDeMaterial LlanyLib::Juego::Objetos::Items::Item::getTipoDeMaterial() const
{
	return this->tipoDeMaterial;
}
LlanyLib::Juego::Enums::TipoObjeto LlanyLib::Juego::Objetos::Items::Item::getTipoObjeto() const
{
	return this->tipoDeObjeto;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Objetos::Items::Item::getShowName() const
{
	return this->itemShowName;
}
double LlanyLib::Juego::Objetos::Items::Item::getValorActual() const
{
	return this->valorActual;
}
double LlanyLib::Juego::Objetos::Items::Item::getValorMaximo() const
{
	return this->valorMaximo;
}
double LlanyLib::Juego::Objetos::Items::Item::getDurabilidad() const
{
	return this->durabilidad;
}
double LlanyLib::Juego::Objetos::Items::Item::getDurabilidadMaxima() const
{
	return this->durabilidadMaxima;
}
double LlanyLib::Juego::Objetos::Items::Item::getCantidad() const
{
	return this->cantidad;
}
double LlanyLib::Juego::Objetos::Items::Item::getPeso() const
{
	return this->peso;
}
double LlanyLib::Juego::Objetos::Items::Item::getTemperatura() const
{
	return this->temperatura;
}
double LlanyLib::Juego::Objetos::Items::Item::getResistenciaTemperatura() const
{
	return this->resistenciaMaterial;
}
#pragma endregion
#pragma region Setters
void LlanyLib::Juego::Objetos::Items::Item::setCantidad(const double& value)
{
	this->cantidad = value;
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Items::Item::addCantidad(const double& value)
{
	this->cantidad += value;
}
#pragma endregion
#pragma region Virtual
LlanyLib::Juego::Objetos::Items::Item* LlanyLib::Juego::Objetos::Items::Item::clone() const
{
	return new Item(*this);
}
LlanyLib::Basic::Objetos::JSONBuilder* LlanyLib::Juego::Objetos::Items::Item::toJSONBuilder() const
{
	Basic::Objetos::JSONBuilder* json = new Basic::Objetos::JSONBuilder();

	const Basic::Objetos::String* name = GESTOR_ITEMS->getRegisterName(this->itemID);
	json->addClearKey(new Basic::Objetos::String("itemName"), name, Basic::Objetos::JSONBuilder::PrepType::Comillas);
	

	json->addClearKey(new Basic::Objetos::String("itemShowName"), this->itemShowName, Basic::Objetos::JSONBuilder::PrepType::Comillas);
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
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Objetos::Items::Item::toJSON() const
{
	LlanyLib::Basic::Objetos::JSONBuilder* build = Item::toJSONBuilder();
	LlanyLib::Basic::Objetos::String* str = build->build();
	delete build;
	return str;
}
void LlanyLib::Juego::Objetos::Items::Item::deleteItem()
{
	delete this;
}
int LlanyLib::Juego::Objetos::Items::Item::compare(const Item& other) const
{
	int result = MATH->compare(this->itemID, other.itemID);
	if (result == 0)
		result = MATH->compare(this->cantidad, other.cantidad);
	return result;
}
bool LlanyLib::Juego::Objetos::Items::Item::similar(const Item& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
	if (this->itemID == other.itemID)
	if (this->tipoDeMaterial == other.tipoDeMaterial)
	if (this->tipoDeObjeto == other.tipoDeObjeto)
	if (this->valorMaximo == other.valorMaximo)
	if (this->durabilidadMaxima == other.durabilidadMaxima)
	if (this->peso == other.peso)
	if (this->resistenciaMaterial == other.resistenciaMaterial)
		temp = true;
	return temp;
}
bool LlanyLib::Juego::Objetos::Items::Item::equals(const Item& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
	if (this->itemID == other.itemID)
	if (this->tipoDeMaterial == other.tipoDeMaterial)
	if (this->tipoDeObjeto == other.tipoDeObjeto)
	if (this->valorActual == other.valorActual)
	if (this->valorMaximo == other.valorMaximo)
	if (this->durabilidad == other.durabilidad)
	if (this->durabilidadMaxima == other.durabilidadMaxima)
	if (this->cantidad == other.cantidad)
	if (this->peso == other.peso)
	if (this->temperatura == other.temperatura)
	if (this->resistenciaMaterial == other.resistenciaMaterial)
		temp = true;
	return temp;
}
bool LlanyLib::Juego::Objetos::Items::Item::igualMenosCantidad(const Item& other) const
{
	bool temp = false;
	if (&other != nullptr && this != nullptr)
	if (this->itemID == other.itemID)
	if (this->tipoDeMaterial == other.tipoDeMaterial)
	if (this->tipoDeObjeto == other.tipoDeObjeto)
	if (this->valorActual == other.valorActual)
	if (this->valorMaximo == other.valorMaximo)
	if (this->durabilidad == other.durabilidad)
	if (this->durabilidadMaxima == other.durabilidadMaxima)
	if (this->peso == other.peso)
	if (this->temperatura == other.temperatura)
	if (this->resistenciaMaterial == other.resistenciaMaterial)
		temp = true;
	return temp;
}
bool LlanyLib::Juego::Objetos::Items::Item::operator==(const Item& other) const
{
	return Item::equals(other);
}
bool LlanyLib::Juego::Objetos::Items::Item::operator!=(const Item& other) const
{
	return !Item::equals(other);
}
#pragma endregion
/*#pragma region Setters
void LlanyLib::Juego::Objetos::Items::Objetos::setItemName(char const* const nombre)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setItemName(Base::Objetos::String*& nombre)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setValorActual(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setValorMaximo(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setDurabilidad(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setDurabilidadMaxima(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setCantidad(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setPeso(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setTipoDeMaterial(const Base::Enums::TipoDeMaterial& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setTemperatura(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::setResistenciaTemperatura(const double& value)
{
}
#pragma endregion
#pragma region Adders
void LlanyLib::Juego::Objetos::Items::Objetos::addValorActual(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addValorMaximo(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addDurabilidad(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addDurabilidadMaxima(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addCantidad(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addPeso(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addTemperatura(const double& value)
{
}
void LlanyLib::Juego::Objetos::Items::Objetos::addResistenciaTemperatura(const double& value)
{
}
#pragma endregion*/
