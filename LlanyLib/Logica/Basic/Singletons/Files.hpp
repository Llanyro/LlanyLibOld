#pragma once
#ifndef FILES_SINGLETON_HPP_
#define FILES_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define FILES LlanyLib::Basic::Singletons::Files::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos { class String; }
		namespace Enum { enum class FopenType; }
		namespace Singletons {
			class Files : public Templates::Singleton<Files>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<Files>;
					Files();
					~Files();
				#pragma endregion
				protected:
					#pragma region Protected
					const char* getParams(const Enum::FopenType& type) const;
					void escribirFicheroBase(const Objetos::String* fileName, const Objetos::String* content, const Enum::FopenType& type) const;
					void escribirFicheroBase(const Objetos::String* fileName, const char& caracter, const Enum::FopenType& type) const;
					void escribirFicheroBase(const Objetos::String* fileName, char const* const content, const Enum::FopenType& type) const;
					#pragma endregion
				public:
					#pragma region Lectura
					Objetos::String* leerFicheroFopenFseek(const Objetos::String* fileName) const;
					Objetos::String* leerFicheroFopenFseekClear(const Objetos::String* fileName) const;
					#pragma endregion
					#pragma region Escritura
					#pragma region Strings
					void escribirFichero(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroClear(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroClearFilename(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroClearContent(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroAppend(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroAppendClear(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroAppendClearFilename(const Objetos::String* fileName, const Objetos::String* content) const;
					void escribirFicheroAppendClearContent(const Objetos::String* fileName, const Objetos::String* content) const;
					#pragma endregion
					#pragma region Caracteres
					void escribirFichero(const Objetos::String* fileName, const char& caracter) const;
					void escribirFicheroClear(const Objetos::String* fileName, const char& caracter) const;
					void escribirFicheroAppend(const Objetos::String* fileName, const char& caracter) const;
					void escribirFicheroAppendClear(const Objetos::String* fileName, const char& caracter) const;
					#pragma endregion
					#pragma region Char const
					void escribirFichero(const Objetos::String* fileName, char const* const content) const;
					void escribirFicheroClear(const Objetos::String* fileName, char const* const content) const;
					void escribirFicheroAppend(const Objetos::String* fileName, char const* const content) const;
					void escribirFicheroAppendClear(const Objetos::String* fileName, char const* const content) const;
					#pragma endregion
					#pragma endregion
					#pragma region Directorios
					Objetos::String* crearPath(const Objetos::String* fileName) const;
					Objetos::String* crearPathClear(const Objetos::String* fileName) const;
					#pragma endregion
					#pragma region Otros
					// Funcion: Ejecuta un proceso para saber la ruta del programa
					// Extra: Solo funciona en _WIN32 y  __unix__
					// Retorno: La ruta de donde se esta ejecutando el programa
					// Complejidad temporal y espacial: O(1) y M(1)
					Objetos::String* origenPrograma() const;
					// Funcion: Devuelve el caracter que se usa por defecto para separar directorios
					// Extra: Depende del sistema en el que se esta
					// Complejidad temporal y espacial: O(1) y M(1)
					char caracterSeparadorDirectorios() const;
					#pragma endregion
			};
		}
	}
}
#endif // !FILES_SINGLETON_HPP_
