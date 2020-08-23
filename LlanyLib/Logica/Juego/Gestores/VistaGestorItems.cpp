#include "VistaGestorItems.hpp"

#include <iostream>

#include "GestorItems.hpp"
#include "../Objetos/Items/Item.hpp"

#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Singletons/StringPrinter.hpp"

LlanyLib::Juego::Gestores::VistaGestorItems::VistaGestorItems() { VistaGestorItems::subscribir(VistaGestorItems::freeInstancia); }
LlanyLib::Juego::Gestores::VistaGestorItems::~VistaGestorItems(){}

bool LlanyLib::Juego::Gestores::VistaGestorItems::itemRegister(Objetos::Item* item, char const* const registerName)
{
	bool resultado = GESTOR_ITEMS->itemRegister(item, registerName);
	if (resultado) 
		std::cout 
			<< "Se ha aniadido el objeto \"" 
			<< registerName 
			<< "\" a la lista de items del juego correctamente" 
			<< std::endl;
	else {
		std::cout
			<< "No se ha añadido el objeto \""
			<< registerName
			<< "\" a la lista de items del juego."
			<< "\n\tComprueba si el registerName ya existe."
			<< "\n\tSe eliminara la instancia recibida"
			<< std::endl;
		item->deleteItem();
	}
	return resultado;
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Gestores::VistaGestorItems::newItem(char const* const registerName) const
{
	Objetos::Item* item = GESTOR_ITEMS->newItem(registerName);
	if (item != nullptr)
		std::cout
			<< "Se ha generado exitosamente el objeto \""
			<< registerName
			<< "\"."
			<< std::endl;
	else
		std::cout
			<< "No existe ningun objeto registrado con el nombre \""
			<< registerName
			<< "\" en el gestor de items."
			<< std::endl;
	return item;
}
const LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Gestores::VistaGestorItems::getRegisterName(const long_t& itemID) const
{
	const Basic::Objetos::String* str = GESTOR_ITEMS->getRegisterName(itemID);
	if (str != nullptr) 
		std::cout
			<< "El registerName del ID: "
			<< itemID
			<< " es \""
			<< str
			<< '"'
			<< std::endl;
	else
		std::cout
			<< "No se ha encontrado registerName para el ID: "
			<< itemID
			<< std::endl;
	return str;
}
long_t LlanyLib::Juego::Gestores::VistaGestorItems::getID(char const* const registerName) const
{
	long_t id = GESTOR_ITEMS->getID(registerName);
	if (id > 0)
		std::cout
			<< "El ID del registerName \""
			<< registerName
			<< "\" es: "
			<< id
			<< std::endl;
	else
		std::cout
			<< "No se ha encontrado ningun ID para el registerName \""
			<< registerName
			<< '"'
			<< std::endl;
	return id;
}
long_t LlanyLib::Juego::Gestores::VistaGestorItems::getID(Basic::Objetos::String* registerName) const
{
	long_t id = GESTOR_ITEMS->getID(registerName);
	if (id > 0)
		std::cout
			<< "El ID del registerName \""
			<< registerName
			<< "\" es: "
			<< id
			<< std::endl;
	else
		std::cout
			<< "No se ha encontrado ningun ID para el registerName \""
			<< registerName
			<< '"'
			<< std::endl;
	return id;
}
long_t LlanyLib::Juego::Gestores::VistaGestorItems::getIDClear(Basic::Objetos::String* registerName) const
{
	long_t id = VistaGestorItems::getID(registerName);
	delete registerName;
	return id;
}
