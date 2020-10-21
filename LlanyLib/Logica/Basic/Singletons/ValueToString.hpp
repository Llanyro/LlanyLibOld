#pragma once
#ifndef VALUE_TO_STRING_SINGLETON_HPP_
#define VALUE_TO_STRING_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define VALUE_2_STRING LlanyLib::Basic::Singletons::ValueToString::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos { class String; }
		namespace Singletons {
			class ValueToString : public Templates::Singleton<ValueToString>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<ValueToString>;
					ValueToString();
					~ValueToString();
				#pragma endregion
				public:
					#pragma region Conversiones
					Objetos::String* toString(const bool& value) const;
					Objetos::String* toString(const short& value) const;
					Objetos::String* toString(const unsigned short& value) const;
					Objetos::String* toString(const int& value) const;
					Objetos::String* toString(const unsigned int& value) const;
					Objetos::String* toString(const float& value) const;
					Objetos::String* toString(const double& value) const;
					Objetos::String* toString(const long& value) const;
					Objetos::String* toString(const unsigned long& value) const;
					Objetos::String* toString(const long long& value) const;
					Objetos::String* toString(const unsigned long long& value) const;
					#pragma endregion
			};
		}
	}
}
#endif // !VALUE_TO_STRING_SINGLETON_HPP_
