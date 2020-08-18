#pragma once
#ifndef UNIT_CONVERSOR_SINGLETON_HPP_
#define UNIT_CONVERSOR_SINGLETON_HPP_

#include "../../Basic/Plantillas/Otros/Singleton.hpp"
#include "../../Basic/Gestores/SubscriptorSingletons.hpp"

#define MATH LlanyLib::Math::Singletons::UnitConversor::getInstancia()

namespace LlanyLib {
	namespace Math {
		namespace Singletons {
			class UnitConversor : public Basic::Templates::Singleton<Math>, Basic::Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<UnitConversor>;
					UnitConversor();
					~UnitConversor();
				#pragma endregion
				public:
				void toBinary() const;
				void toBinary() const;
				void toBinary() const;

				void toBinary() const;
			};
		}
	}
}
#endif // !UNIT_CONVERSOR_SINGLETON_HPP_
