#include "ListaItems.hpp"

#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#include "Item.hpp"

#define MAX_STACK 64

LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::ListItem::getItemIgual(Item* item) const
{
	Item* resultado = nullptr;
	Item* temp = nullptr;
	for (size_t i = 0; i < this->list->length(); i++) {
		temp = *this->list->get(i);
		if (temp->igualMenosCantidad(*item)) {
			resultado = temp;
			i = this->list->length();
		}
	}
	return resultado;
}

LlanyLib::Juego::Objetos::ListItem::ListItem()
{
	this->list = new LlanyLib::Basic::Templates::Listas::LinkedList<Item*>();
}
LlanyLib::Juego::Objetos::ListItem::~ListItem()
{
	if (this->list != nullptr) {
		ListItem::clear();
		delete this->list;
	}
}
bool LlanyLib::Juego::Objetos::ListItem::add(Item* item)
{
	bool resultado = false;
	Item* temp = ListItem::getItemIgual(item);
	if (temp == nullptr) {
		resultado = this->list->add(item);
	}
	else {
		temp->addCantidad(item->getCantidad());
		if (temp->getCantidad() > MAX_STACK) {
			item->setCantidad(temp->getCantidad() - MAX_STACK);
			temp->setCantidad(MAX_STACK);
			resultado = this->list->add(item);
		}
		else resultado = true;
	}
	return resultado;
}
void LlanyLib::Juego::Objetos::ListItem::clear()
{
	for (size_t i = 0; i < this->list->length(); i++)
		ListItem::extractItem(i)->deleteItem();
}
void LlanyLib::Juego::Objetos::ListItem::ordenar(const Enums::Ordenamiento& ord)
{
}
const LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::ListItem::get(const size_t& pos) const
{
	return *this->list->get(pos);
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::ListItem::extractItem(const size_t& pos) const
{
	return ListItem::extractItem(pos, MAX_STACK);
}
LlanyLib::Juego::Objetos::Item* LlanyLib::Juego::Objetos::ListItem::extractItem(const size_t& pos, const double& cantidad) const
{
	Item* resultado = nullptr;
	if (pos < this->list->length()) {
		resultado = *this->list->get(pos);
		if(resultado->getCantidad() <= cantidad)
			this->list->remove(pos);
		else {
			resultado->addCantidad(-cantidad);
			resultado = resultado->clone();
			resultado->setCantidad(cantidad);
		}
	}
	return resultado;
}
bool LlanyLib::Juego::Objetos::ListItem::equals(const ListItem& other) const
{
	bool resultado = false;
	if (&other != nullptr && this != nullptr) {
	if (this->list != nullptr && other.list != nullptr) {
		if (this->list->length() == other.list->length()) {
				bool encontrado = false;
				resultado = true;
				Item* a = nullptr;
				Item* b = nullptr;
				for (size_t i = 0; i < this->list->length(); i++) {
					encontrado = false;
					a = *this->list->get(i);
					for (size_t e = 0; e < other.list->length() && !encontrado; e++) {
						b = *other.list->get(e);
						encontrado = a->equals(*b);
					}
					if (!encontrado) {
						resultado = false;
						i = this->list->length();
					}
				}
			}
		}
	}
	return resultado;
}

LlanyLib::Basic::Templates::Listas::LinkedList<LlanyLib::Juego::Objetos::Item*>* LlanyLib::Juego::Objetos::ListItem::getList() const
{
	return this->list;
}
