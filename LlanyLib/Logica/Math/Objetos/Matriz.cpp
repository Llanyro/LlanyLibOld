#include "Matriz.hpp"


#include "../../Basic/Plantillas/Listas/LinkedList.hpp"

#include "Racional.hpp"


#pragma region Getters
size_t LlanyLib::Basic::Math::Objetos::Matriz::getNumeroFilas() const
{
	return this->contenido->length();
}
size_t LlanyLib::Basic::Math::Objetos::Matriz::getNumeroColumnas() const
{
	size_t res = 0;
	if (this->contenido->length() > 0)
		res = (*this->contenido->get(0))->length();
	return res;
}
size_t LlanyLib::Basic::Math::Objetos::Matriz::getNumeroColumnas(const size_t& columna) const
{
	size_t res = 0;
	if (this->contenido->length() > columna)
		res = (*this->contenido->get(columna))->length();
	return res;
}
LlanyLib::Basic::Math::Objetos::Racional* LlanyLib::Basic::Math::Objetos::Matriz::getValue(const size_t& fila, const size_t& columna) const
{
	Racional* resultado = nullptr;
	if (fila < this->contenido->length())
		if (columna < (*this->contenido->get(fila))->length()) {
			resultado = (*this->contenido->get(fila))->get(columna);
		}
	return resultado;
}
#pragma endregion
#pragma region Modificadores de matriz
void LlanyLib::Basic::Math::Objetos::Matriz::multiplicarEscalar_(const int& escalar)
{
	Templates::Listas::LinkedList<Racional>* list = nullptr;
	Math::Objetos::Racional* rac = nullptr;

	for (size_t i = 0; i < this->contenido->length(); i++) {
		list = *this->contenido->get(i);
		for (size_t e = 0; e < list->length(); e++) {
			list->get(e)->;
		}
	}


}

#pragma endregion
#pragma region Operaciones sin modificacion originales
LlanyLib::Basic::Math::Objetos::Matriz* LlanyLib::Basic::Math::Objetos::Matriz::multiplicarEscalar(const int& escalar) const
{





	return nullptr;
}


#pragma endregion