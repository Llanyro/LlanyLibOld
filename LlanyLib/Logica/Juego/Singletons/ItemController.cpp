#include "ItemController.hpp"

#include "../Objetos/Item.hpp"
#include "../Enums/ItemEnum.hpp"
#include "../../Basic/Objetos/String.hpp"
#include "../../Basic/Objetos/JSONBuilder.hpp"
#include "../../Basic/Objetos/StringBuilder.hpp"
#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

LlanyLib::Juego::Singletons::ItemContoller::ItemContoller() { ItemContoller::subscribir(ItemContoller::freeInstancia); }
LlanyLib::Juego::Singletons::ItemContoller::~ItemContoller(){}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Singletons::ItemContoller::generateJSONString(Basic::Templates::Listas::LinkedList<Objetos::Item*>* list) const
{
	Basic::Objetos::StringBuilder buffer;
	buffer += '[';
	Objetos::Item* temp = nullptr;
	for (size_t i = 0; i < list->length(); i++) {
		temp = *list->get(i);
		if (i != 0)
			buffer += ',';
		buffer += '{';
		buffer.addClear(temp->toJSON());
		buffer += '}';
	}
	buffer += ']';
	return buffer.build();
}
LlanyLib::Basic::Objetos::String* LlanyLib::Juego::Singletons::ItemContoller::generateJSONStringClear(Basic::Templates::Listas::LinkedList<Objetos::Item*>* list) const
{
	LlanyLib::Basic::Objetos::String* item = generateJSONString(list);
	for (size_t i = 0; i < list->length(); i++)
		delete* list->get(i);
	delete list;
	return item;
}
