#pragma warning(disable:4996)
#include "Entidad.hpp"

#include "../../../Basic/Objetos/String.hpp"

#include "Familiar.hpp"
#include "../Stats/Stats.hpp"

//#include "Familiar.h"
//#include "../../Stats/SubStats/Critico.h"
//#include "../../Stats/SubStats/Ofensivos.h"
//#include "../../Stats/SubStats/Energia.h"
//#include "../../Stats/SubStats/Resistencia.h"
//#include "../../Stats/SubStats/Survival.h"
//
///// Otros
//#include "../../System/ControladorEntidad.h"
//#include "../../Stats/Stats/Stats.h"
//#include "../../Inventario/Inventario.h"
//#include "../../Equipamiento/Equipamiento.h"

#pragma region Constructores
LlanyLib::Juego::Objetos::Entidades::Entidad::Entidad()
{
	this->tipoDeEntidad = Enum::TipoDeEntidad::ENTIDAD_NULL;
	this->nombre = new Basic::Objetos::String("ENTIDAD_NULL");
	this->stats = new Stats::Stats();
	//this->inventario = new Inventario();
	//this->equipamiento = new Equipamiento();
	this->familiar = nullptr;
}
LlanyLib::Juego::Objetos::Entidades::Entidad::Entidad(const Entidad& other) : Entidad()
{
	Entidad::operator=(other);
}
bool LlanyLib::Juego::Objetos::Entidades::Entidad::operator=(const Entidad& other)
{
	bool resultado = false;
	if (&other != nullptr)
	{
		this->nombre->operator=(*other.nombre);
		this->tipoDeEntidad = other.tipoDeEntidad;
		this->stats->operator=(*other.stats);
		//this->inventario->operator=(*other.inventario);
		//this->equipamiento->operator=(*other.equipamiento);
		//this->familiar = other.familiar->getClone();
		resultado = true;
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Entidades::Entidad::~Entidad()
{
	this->tipoDeEntidad = Enum::TipoDeEntidad::ENTIDAD_NULL;
	delete(this->nombre);
	delete(this->stats);
	//if (this->inventario != nullptr) delete(this->inventario);
	//if (this->equipamiento != nullptr) delete(this->equipamiento);
	if (this->familiar != nullptr) delete(this->familiar);
	//this->inventario = nullptr;
	//this->equipamiento = nullptr;
	this->familiar = nullptr;
}
#pragma endregion
#pragma region Getters
const LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Objetos::Entidades::Entidad::getNombre() const
{
	return this->nombre;
}
LlanyLib::Juego::Enum::TipoDeEntidad LlanyLib::Juego::Objetos::Entidades::Entidad::getTipoDeEntidad() const
{
	return this->tipoDeEntidad;
}
LlanyLib::Juego::Objetos::Entidades::Familiar* LlanyLib::Juego::Objetos::Entidades::Entidad::getFamiliar() const
{
	return this->familiar;
}
LlanyLib::Juego::Objetos::Stats::Stats* LlanyLib::Juego::Objetos::Entidades::Entidad::getStats() const
{
	return this->stats;
}
/*Inventario* LlanyLib::Juego::Objetos::Entidades::Entidad::getInventario() const
{
	return this->inventario;
}
Equipamiento* LlanyLib::Juego::Objetos::Entidades::Entidad::getEquipamiento() const
{
	return this->equipamiento;
}*/
#pragma endregion
#pragma region Setters
//void LlanyLib::Juego::Objetos::Entidades::Entidad::setNombre(const LlanyLib::Basic::Objetos::String& nombre)
//{
//	assert(&nombre != nullptr);
//	//this->nombre->operator=(nombre);
//}
void LlanyLib::Juego::Objetos::Entidades::Entidad::setTipoDeEntidad(const LlanyLib::Juego::Enum::TipoDeEntidad& value)
{
	this->tipoDeEntidad = value;
}
void LlanyLib::Juego::Objetos::Entidades::Entidad::setFamiliar(Familiar* familiar)
{
	this->familiar = familiar;
	familiar->setInvocador(this);
}
#pragma endregion
#pragma region Compares
bool LlanyLib::Juego::Objetos::Entidades::Entidad::igual(const Entidad& other) const
{
	bool temp = false;
	if (&other == nullptr && this == nullptr) temp = true;
	else if (&other != nullptr && this != nullptr)
	//if(this->nombre->operator==(*other.nombre))
	if (this->tipoDeEntidad == other.tipoDeEntidad)
	if (this->stats->operator==(*other.stats))
	//if (this->inventario->operator==(*other.inventario))
	//if (this->equipamiento->operator==(*other.equipamiento))
		temp = true;
	return temp;
}
#pragma endregion
#pragma region Operators
bool LlanyLib::Juego::Objetos::Entidades::Entidad::operator==(const Entidad& other) const
{
	return Entidad::igual(other);
}
bool LlanyLib::Juego::Objetos::Entidades::Entidad::operator!=(const Entidad& other) const
{
	return !Entidad::igual(other);
}
#pragma endregion
LlanyLib::Juego::Objetos::Entidades::Entidad* LlanyLib::Juego::Objetos::Entidades::Entidad::clone() const
{
	return new Entidad(*this);
}
/*String LlanyLib::Juego::Objetos::Entidades::Entidad::toJSON() const
{
	String entidad;
	entidad += '{';
	entidad += String("\"Nombre\":\"") + *this->nombre + String("\"");
	entidad += String(",\"TipoDeEntidad\":\"") + (size_t)this->tipoDeEntidad + String("\"");
	entidad += String(",\"Stats\":") + this->stats->toJSON();
	entidad += String(",\"Equipamiento\":") + this->equipamiento->toJSON();
	entidad += String(",\"Inventario\":") + this->inventario->toJSON();

	if (this->familiar != nullptr)
		entidad += String(",\"Familiar\":") + this->familiar->getFamiliar()->toJSON();

	entidad += '}';
	return entidad;
}
*/
