#pragma once
#ifndef GESTOR_SINGLETONS_HPP_
#define GESTOR_SINGLETONS_HPP_

#include "../Plantillas/Otros/Singleton.hpp"

#define GESTOR_SINGLETONS LlanyLib::Basic::Gestores::GestorSingletons::getInstancia()
#define FREE_SINGLETONS LlanyLib::Basic::Gestores::GestorSingletons::freeInstancia()

namespace LlanyLib
{
	namespace Basic
	{
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
		namespace Gestores
		{
			class GestorSingletons : public Templates::Singleton<GestorSingletons>
			{
				#pragma region Singleton
				private:
					friend class Singleton<GestorSingletons>;
					GestorSingletons();
					~GestorSingletons();
				#pragma endregion
				protected:
					Templates::Listas::LinkedList<void*>* list;
				public:
					void subscribirse(void (*singFree)(void));
			};
		}
	}
}
#endif // !GESTOR_SINGLETONS_HPP_
