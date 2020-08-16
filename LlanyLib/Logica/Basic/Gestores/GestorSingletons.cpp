#include "GestorSingletons.hpp"

#include "../Plantillas/Listas/LinkedList.hpp"

LlanyLib::Basic::Gestores::GestorSingletons::GestorSingletons()
{
	this->list = new Templates::Listas::LinkedList<void*>();
}
LlanyLib::Basic::Gestores::GestorSingletons::~GestorSingletons()
{
	if (this->list != nullptr) {
		for (size_t i = 0; i < this->list->getCount(); i++)
			((void(*)(void))(this->list->operator[](i)))();
		delete this->list;
		this->list = nullptr;
	}
}
void LlanyLib::Basic::Gestores::GestorSingletons::subscribirse(void(*singFree)(void))
{
	this->list->add(singFree);
}
