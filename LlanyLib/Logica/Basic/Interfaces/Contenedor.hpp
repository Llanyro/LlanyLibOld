#pragma once
#ifndef CONTENEDOR_INTERFACE_HPP_
#define CONTENEDOR_INTERFACE_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Interfaces {
			template<class T>
			class Contenedor
			{
				protected:
					T object0;
				public:
					#pragma region Constructores
					inline Contenedor() { this->object0 = T(); }
					inline Contenedor(const T& object0)
					{
						if (&object0 != nullptr)
							this->object0 = object0;
						else
							this->object0 = T();
					}
					inline Contenedor(const Contenedor* other)
					{
						if (other != nullptr)
							this->object0 = other->object0;
						else
							this->object0 = T();
					}
					inline ~Contenedor() {}
					#pragma endregion
					#pragma region Get/Set
					inline T& getObject0() { return this->object0; }
					inline bool setObject0(const T& object)
					{
						bool resultado = true;
						if (&object != nullptr)
							this->object0 = object;
						else
							resultado = false;
						return resultado;
					}
					#pragma endregion
			};
		}
	}
}
#endif // !CONTENEDOR_INTERFACE_HPP_
