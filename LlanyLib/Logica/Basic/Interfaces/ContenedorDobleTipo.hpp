#pragma once
#ifndef CONTENEDOR_DOBLE_TIPO_INTERFACE_HPP_
#define CONTENEDOR_DOBLE_TIPO_INTERFACE_HPP_

#include "Contenedor.hpp"

namespace LlanyLib
{
	namespace Basic
	{
		namespace Interfaces
		{
			template<class T0, class T1>
			class ContenedorDobleTipo : public Contenedor<T0>
			{
				protected:
					T1 object1;
				public:
					#pragma region Constructores
					inline ContenedorDobleTipo() : Contenedor<T0>() { this->object1 = T1(); }
					inline ContenedorDobleTipo(const ContenedorDobleTipo<T0, T1>* other) : Contenedor<T0>(other)
					{
						if (other != nullptr)
							this->object1 = other->object1;
						else
							this->object1 = T1();
					}
					/*inline ContenedorDobleTipo(const T0& object0) : Contenedor<T0>(object0)
					{
						this->object1 = T1();
					}
					inline ContenedorDobleTipo(const T1& object1) : Contenedor<T0>()
					{
						if (&object1 != nullptr)
							this->object1 = object1;
						else
							this->object1 = T1();
					}*/
					inline ContenedorDobleTipo(const T0& object0, const T1& object1) : Contenedor<T0>(object0)
					{
						if (&object1 != nullptr)
							this->object1 = object1;
						else
							this->object1 = T1();
					}
					inline ~ContenedorDobleTipo() {}
					#pragma endregion
					#pragma region Get/Set
					inline T1& getObject1() { return this->object1; }
					inline bool setObject1(const T1& object1)
					{
						bool resultado = true;
						if (&object1 != nullptr)
							this->object1 = object1;
						else
							resultado = false;
						return resultado;
					}
					#pragma endregion
			};
		}
	}
}
#endif // !CONTENEDOR_DOBLE_TIPO_INTERFACE_HPP_
