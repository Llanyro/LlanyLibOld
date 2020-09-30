#include "Matriz.hpp"


#include "../../Basic/Plantillas/Listas/LinkedList.hpp"
#include "../../Basic/Plantillas/Listas/Array.hpp"

#include "Racional.hpp"


#pragma region Getters
size_t LlanyLib::Math::Objetos::Matriz::getNumeroFilas() const
{
	return this->contenido->length();
}
size_t LlanyLib::Math::Objetos::Matriz::getNumeroColumnas() const
{
	size_t res = 0;
	if (this->contenido->length() > 0)
		res = (*this->contenido->get(0))->length();
	return res;
}
size_t LlanyLib::Math::Objetos::Matriz::getNumeroColumnas(const size_t& columna) const
{
	size_t res = 0;
	if (this->contenido->length() > columna)
		res = (*this->contenido->get(columna))->length();
	return res;
}
LlanyLib::Math::Objetos::Racional* LlanyLib::Math::Objetos::Matriz::getValue(const size_t& fila, const size_t& columna) const
{
	Racional* resultado = nullptr;
	if (fila < this->contenido->length())
		if (columna < (*this->contenido->get(fila))->length()) {
			resultado = (*this->contenido->get(fila))->get(columna);
		}
	return resultado;
}
#pragma endregion
#pragma region Add
bool LlanyLib::Math::Objetos::Matriz::addColum(LISTA_T<Racional>* columna)
{
	bool resultado = false;
	if (columna->length() == Matriz::getNumeroFilas()) {
		for (size_t i = 0; i < resultado && columna->length(); i++)
			resultado = this->contenido->operator[](i)->add(columna->operator[](i));
	}
	return resultado;
}
bool LlanyLib::Math::Objetos::Matriz::addFila(LISTA_T<Racional>* fila)
{
	bool resultado = false;
	if (fila->length() == Matriz::getNumeroColumnas()) {
		LISTA_T<Racional>* newlist = new LISTA_T<Racional>(*fila);
		resultado = this->contenido->add(newlist);
	}
	return resultado;
}
bool LlanyLib::Math::Objetos::Matriz::addColum(ARRAY_T<Racional>* columna)
{
	bool resultado = false;
	if (columna->length() == Matriz::getNumeroFilas()) {
		for (size_t i = 0; i < resultado && columna->length(); i++)
			resultado = this->contenido->operator[](i)->add(columna->operator[](i));
	}
	return resultado;
}
bool LlanyLib::Math::Objetos::Matriz::addFila(ARRAY_T<Racional>* fila)
{
	bool resultado = false;
	if (fila->length() == Matriz::getNumeroColumnas()) {
		LISTA_T<Racional>* newlist = new LISTA_T<Racional>(*fila);
		resultado = this->contenido->add(newlist);
	}
	return resultado;
}
#pragma endregion
#pragma region Remove
bool LlanyLib::Math::Objetos::Matriz::removeColum(const size_t& pos)
{
	bool resultado = false;
	if(this->contenido->length() > 0)
		if (pos < this->contenido->operator[](0)->length())
			for (size_t i = 0; i < this->contenido->length(); i++)
				resultado = this->contenido->operator[](i)->remove(pos);
	return resultado;
}
bool LlanyLib::Math::Objetos::Matriz::removeFila(const size_t& pos)
{
	return this->contenido->remove(pos);
}
#pragma endregion
#pragma region Modificadores de matriz
void LlanyLib::Math::Objetos::Matriz::multiplicarEscalar_(const int& escalar)
{
	LISTA_T<Racional>* actualList = nullptr;
	for (size_t i = 0; i < this->contenido->length(); i++) {
		actualList = this->contenido->operator[](i);
		for (size_t e = 0; e < actualList->length(); e++)
			actualList->operator[](e).escalar(escalar);
	}
}
void LlanyLib::Math::Objetos::Matriz::dividirEscalar_(const int& escalar)
{

}
#pragma endregion
#pragma region Operaciones sin modificacion originales
LlanyLib::Math::Objetos::Matriz* LlanyLib::Math::Objetos::Matriz::multiplicarEscalar(const int& escalar) const
{
	Matriz* mat = new Matriz(*this);
	mat->multiplicarEscalar_(escalar);
	return mat;
}
LlanyLib::Math::Objetos::Matriz* LlanyLib::Math::Objetos::Matriz::dividirEscalar(const int& escalar)
{
	return nullptr;
}


#pragma endregion