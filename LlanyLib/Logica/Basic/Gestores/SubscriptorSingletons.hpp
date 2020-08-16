#pragma once
#ifndef SUBSCRIPTOR_SINGLETONS_HPP_
#define SUBSCRIPTOR_SINGLETONS_HPP_

namespace LlanyLib
{
	namespace Basic
	{
		namespace Gestores
		{
			class SubscriptorSingletons
			{
				public:
					SubscriptorSingletons();
					~SubscriptorSingletons();
					void subscribir(void (*singFree)(void));
			};
		}
	}
}
#endif // !SUBSCRIPTOR_SINGLETONS_HPP_
