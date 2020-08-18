#pragma once
#ifndef BASE_ABC_SINGLETON_MATH_HPP_
#define BASE_ABC_SINGLETON_MATH_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define BASE_ABC LlanyLib::Math::Singletons::BaseABC::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class String;
		}
	}
	namespace Math {
		namespace Singletons {
			class BaseABC : public Basic::Templates::Singleton<BaseABC>, Basic::Gestores::SubscriptorSingletons
			{
				private:
					#pragma region Constructores
					friend class Singleton<BaseABC>;
					BaseABC();
					~BaseABC();
					#pragma endregion
				public:
					char toChar(const short& value) const;
					short toShort(const char& caracter) const;
					size_t toValue(const Basic::Objetos::String* str) const;
					size_t toValueClear(Basic::Objetos::String* str) const;
					Basic::Objetos::String* toString(const size_t& value) const;
			};
		}
	}
}
#endif // !BASE_ABC_SINGLETON_MATH_HPP_
