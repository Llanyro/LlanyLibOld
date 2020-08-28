#pragma once
#ifndef SYSTEM_SINGLETON_HPP_
#define SYSTEM_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define SYSTEM LlanyLib::Basic::Singletons::System::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos { class String; }
		namespace Enum
		{
			enum class Error;
			enum class Codes;
		}
		namespace Singletons
		{
			class System : public Templates::Singleton<System>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<System>;
					System();
					~System();
				#pragma endregion
				public:
					#pragma region Commands
					// Funcion: Ejecuta un "comando" en el sistema indicado con popen
					// Extra: El commando a ejecutar depende del sistema y su consola/terminal
					// Retorno: El resultado de ejectuar el comando
					// Complejidad temporal y espacial: O(1) y M(1)
					Objetos::String* ejecutarCommand(const Objetos::String* command) const;
					Objetos::String* ejecutarCommandClear(const Objetos::String* command) const;
					#pragma endregion
					#pragma region System
					// Funcion: Comprueba si funciona system()
					// Retorno: El estado de system()
					// Complejidad temporal y espacial: O(1) y M(1)
					bool procesadorActivo() const;
					// Cierra el programa y devuelve el valor Codes
					// Funcion: Fuerza el cierre del programa con el valor del codigo indicado
					// Complejidad temporal y espacial: O(1) y M(1)
					void forzarCierre(const Enum::Codes& codigo) const;
					// Funcion: Comprueba si el procesador esta activo
					// Extra: Cierra el programa si no lo esta y permitimos el cierre
					// Retorno: El estado de system()
					// Complejidad temporal y espacial: O(1) y M(1)
					bool comprobarProcesador(const bool& value) const;
					#pragma endregion
			};
		}
	}
}
#endif // !SYSTEM_SINGLETON_HPP_
