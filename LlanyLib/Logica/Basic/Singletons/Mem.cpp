#include "Mem.hpp"

#include <cassert>
#include <cstdlib>
#include <cstring>

LlanyLib::Basic::Singletons::Mem::Mem() { Mem::subscribir(Mem::freeInstancia); }
LlanyLib::Basic::Singletons::Mem::~Mem(){}

#pragma region Punteros
void* LlanyLib::Basic::Singletons::Mem::autoPointer(const void* memBlock, const size_t& posicion,
	const size_t& sizeType) const
{
	assert(memBlock != nullptr);
	assert(&posicion != nullptr);
	assert(&sizeType != nullptr);
	assert(sizeType > 0);
	assert(posicion >= 0);
	return ((char*)memBlock) + (sizeType * posicion);
}
void* LlanyLib::Basic::Singletons::Mem::autoPointer(const void* memBlock,
	const size_t& posicionX, const size_t& posicionY, const size_t& sizeType,
	const size_t& sizeSubBlockType, const size_t& sizeSubBlock) const
{
	assert(memBlock != nullptr);
	assert(&posicionX != nullptr);
	assert(&posicionY != nullptr);
	assert(&sizeType != nullptr);
	assert(&sizeSubBlockType != nullptr);
	assert(&sizeSubBlock != nullptr);
	assert(sizeType > 0);
	assert(sizeSubBlockType > 0);
	assert(sizeSubBlock > 0);
	assert(posicionX >= 0);
	assert(posicionY >= 0);
	return Mem::autoPointer(Mem::autoPointer(memBlock, posicionX, sizeSubBlock * sizeSubBlockType), posicionY, sizeType);
}
#pragma endregion
#pragma region Control de memoria
void* LlanyLib::Basic::Singletons::Mem::reservarMem(const size_t& bytes) const
{
	assert(&bytes != nullptr);
	assert(bytes > 0);
	return malloc(bytes);
}
void* LlanyLib::Basic::Singletons::Mem::copiarMemoria(void* dest, const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType) const
{
	assert(dest != nullptr);
	assert(memBlock != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	dest = memcpy(dest, Mem::autoPointer(memBlock, inicio, sizeType), (fin - inicio) * sizeType);
	return dest;
}
void* LlanyLib::Basic::Singletons::Mem::reservarYCopiar(const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType) const
{
	assert(memBlock != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	void* memRes = Mem::reservarMem((fin - inicio) * sizeType);
	Mem::copiarMemoria(memRes, memBlock, inicio, fin, sizeType);
	return memRes;
}
void* LlanyLib::Basic::Singletons::Mem::resize(void* memBlock, const size_t& sizeBlock, const size_t& sizeType) const
{
	assert(memBlock != nullptr);
	assert(&sizeBlock != nullptr);
	assert(&sizeType != nullptr);
	assert(sizeType > 0);
	assert(sizeBlock >= 0);
	return realloc(memBlock, sizeBlock * sizeType);
}
void LlanyLib::Basic::Singletons::Mem::liberar(void** pointerToMemBlock) const
{
	assert(pointerToMemBlock != nullptr);
	assert(*pointerToMemBlock != nullptr);
	free(*pointerToMemBlock);
	*pointerToMemBlock = nullptr;
}
void LlanyLib::Basic::Singletons::Mem::swap(void* memBlock_a, void* memBlock_b,
	const size_t& sizeBlock, const size_t& sizeType) const
{
	assert(memBlock_a != nullptr);
	assert(memBlock_b != nullptr);
	assert(&sizeBlock != nullptr);
	assert(&sizeType != nullptr);
	assert(sizeType > 0);
	assert(sizeBlock > 0);

	//Reservamos el espacio en memoria que queremos mover y lo copiamos
	void* memtemp = Mem::reservarYCopiar(memBlock_a, 0, 1, sizeBlock * sizeType);
	//Realizamos el swap con memcpy
	memcpy(memBlock_a, memBlock_b, sizeBlock * sizeType);
	memcpy(memBlock_b, memtemp, sizeBlock * sizeType);

	//Libaremos la memoria reservada temporal
	Mem::liberar(&memtemp);
}
#pragma endregion
#pragma region Busquedas
bool LlanyLib::Basic::Singletons::Mem::buscarObjeto(const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType,
	const void* item, int Compare(const void* item_a, const void* item_b)) const
{
	assert(memBlock != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(item != nullptr);
	assert(Compare != nullptr);
	assert(sizeType > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	bool temp = false;
	for (size_t i = inicio; i < fin && !temp; i++)
		if (Compare(Mem::autoPointer(memBlock, i, sizeType), item) == 0)
			temp = true;
	return temp;
}
bool LlanyLib::Basic::Singletons::Mem::buscarObjetoInvertido(const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType,
	const void* item, int Compare(const void* item_a, const void* item_b)) const
{
	assert(memBlock != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(item != nullptr);
	assert(Compare != nullptr);
	assert(sizeType > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	bool temp = false;
	for (size_t i = fin - 1; i > inicio && !temp; i--)
		if (Compare(Mem::autoPointer(memBlock, i, sizeType), item) == 0)
			temp = true;
	return temp;
}
size_t LlanyLib::Basic::Singletons::Mem::buscarPosicionObjetoMenor(const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType,
	int Compare(const void* item_a, const void* item_b)) const
{
	assert(memBlock != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(Compare != nullptr);
	assert(sizeType > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	size_t posMenor = inicio;
	for (size_t i = inicio + 1; i < fin; i++)
		if (Compare(
			Mem::autoPointer(memBlock, posMenor, sizeType),
			Mem::autoPointer(memBlock, i, sizeType)) == 1)
			posMenor = i;
	return posMenor;
}
#pragma endregion
#pragma region Movimientos de memoria
void LlanyLib::Basic::Singletons::Mem::memMoveEsp(const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType,
	const size_t& unidadesDesplazar, const bool& adelante, const void* nullValue) const
{
	assert(memBlock != nullptr);
	assert(nullValue != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(&unidadesDesplazar != nullptr);
	assert(&adelante != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	Mem::memMove(memBlock, inicio, fin, sizeType, unidadesDesplazar, adelante);
	if (adelante)
	{
		//O(unidadesDesplazar)
		for (size_t i = inicio; i < inicio + unidadesDesplazar; i++)
			Mem::copiarMemoria(
				Mem::autoPointer(memBlock, i, sizeType), nullValue, 0, 1, sizeType);
	}
	else
	{
		//O(unidadesDesplazar)
		for (size_t i = fin - unidadesDesplazar; i < fin; i++)
			Mem::copiarMemoria(
				Mem::autoPointer(memBlock, i, sizeType), nullValue, 0, 1, sizeType);
	}
}
void LlanyLib::Basic::Singletons::Mem::memMove(const void* memBlock,
	const size_t& inicio, const size_t& fin, const size_t& sizeType,
	const size_t& unidadesDesplazar, const bool& adelante) const
{
	assert(memBlock != nullptr);
	assert(&inicio != nullptr);
	assert(&fin != nullptr);
	assert(&sizeType != nullptr);
	assert(&unidadesDesplazar != nullptr);
	assert(&adelante != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	if (adelante)
	{
		//O(fin - inicio)
		for (size_t i = fin - 1; i > inicio; i--)
			Mem::copiarMemoria(
				Mem::autoPointer(memBlock, i, sizeType),
				Mem::autoPointer(memBlock, i - unidadesDesplazar, sizeType), 0, 1, sizeType);
	}
	else
	{
		//O(fin - inicio)
		for (size_t i = inicio; i < fin - 1; i++)
			Mem::copiarMemoria(
				Mem::autoPointer(memBlock, i, sizeType),
				Mem::autoPointer(memBlock, i + unidadesDesplazar, sizeType), 0, 1, sizeType);
	}
}
void LlanyLib::Basic::Singletons::Mem::invertirBloque(void* memBlock,
	const size_t& sizeBlock, const size_t& sizeType) const
{
	assert(memBlock != nullptr);
	assert(&sizeBlock != nullptr);
	assert(&sizeType != nullptr);
	assert(sizeType > 0);
	assert(sizeBlock > 0);
	for (size_t i = 0; i < (sizeBlock / 2); i++)
		Mem::swap(
			Mem::autoPointer(memBlock, i, sizeType),
			Mem::autoPointer(memBlock, sizeBlock - 1 - i, sizeType), 1, sizeType);
}
#pragma endregion
#pragma region Memoria compartida
void* LlanyLib::Basic::Singletons::Mem::reservarMemoriaCompartida(const size_t& bytes) const
{
	assert(&bytes != nullptr);
	assert(bytes > 0);
	void* memoria = nullptr;
	#ifdef _WIN32

	#elif __unix__
	memoria = mmap(NULL, bytes, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	#endif // _WIN32
	return memoria;
}
#pragma endregion
