#pragma once
#ifndef SINGLETON_SUBSCRIBER_TEMPLATE_HPP_
#define SINGLETON_SUBSCRIBER_TEMPLATE_HPP_

namespace LlanyLib
{
	namespace Templates
	{
		/*
			#pragma region Singleton
			private:
				friend class Singleton<class>;
				class();
				~class();
			#pragma endregion
		*/
		template <class T>
		class SingletonSub : public Singleton<T>
		{
			public:
				SingletonSub()
				{

				}
				~SingletonSub()
				{

				}
		};
	}
}
#endif // !SINGLETON_SUBSCRIBER_TEMPLATE_HPP_