#pragma once
#ifndef SINGLETON_TEMPLATE_HPP_
#define SINGLETON_TEMPLATE_HPP_

namespace LlanyLib
{
	namespace Basic
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
			class Singleton
			{
				#pragma region Singleton
				protected:
					Singleton() {}
					~Singleton() {}
					static T* instancia;
				public:
					static T* getInstancia()
					{
						if (Singleton<T>::instancia == nullptr)
							Singleton<T>::instancia = new T();
						return Singleton<T>::instancia;
					}
					static void freeInstancia()
					{
						if (Singleton<T>::instancia != nullptr)
							delete Singleton<T>::instancia;
						Singleton<T>::instancia = nullptr;
					}
				#pragma endregion
			};
			#pragma region Singleton
			template <class T>
			T* Singleton<T>::instancia = nullptr;
			#pragma endregion
		}
	}
}
#endif // !SINGLETON_TEMPLATE_HPP_