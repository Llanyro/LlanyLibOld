#pragma once
#ifndef JSON_CONVERSOR_SINGLETON_HPP_
#define JSON_CONVERSOR_SINGLETON_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define JSON_CONVERSOR LlanyLib::Basic::Singletons::JSONConversor::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos { class String; }
		namespace Templates {
			namespace Diccionarios {
				template<class T1, class T2>
				class DictionaryLinkedList;
			}
		}
		namespace Singletons {
			class JSONConversor : public Templates::Singleton<JSONConversor>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<JSONConversor>;
					JSONConversor();
					~JSONConversor();
				#pragma endregion
				public:
					Objetos::String* toJSON(Templates::Diccionarios::DictionaryLinkedList<Objetos::String*, Objetos::String*>* dict) const;
					Objetos::String* toJSONClear(Templates::Diccionarios::DictionaryLinkedList<Objetos::String*, Objetos::String*>* dict) const;
					Templates::Diccionarios::DictionaryLinkedList<Objetos::String*, Objetos::String*>* toDict(const Objetos::String* json) const;
					Templates::Diccionarios::DictionaryLinkedList<Objetos::String*, Objetos::String*>* toDictClear(Objetos::String* json) const;
			};
		}
	}
}
#endif // !JSON_CONVERSOR_SINGLETON_HPP_
