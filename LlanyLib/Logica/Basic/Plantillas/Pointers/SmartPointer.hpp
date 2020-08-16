#pragma once
#ifndef SMART_POINTER_HPP_
#define SMART_POINTER_HPP_

namespace LlanyLib
{
	namespace Basic
	{
		namespace Templates
		{
			namespace Simple
			{
				// Only con operator new
				template<class T>
				class SmartPointer
				{
					protected:
						T* item;
					public:
						// Inicializar con new
						inline SmartPointer() { this->item = nullptr; }
						inline SmartPointer(T* item) { this->item = item; }
						inline bool operator=(const SmartPointer<T>& other)
						{
							bool resultado = false;
							if (&other != nullptr && other.item != nullptr) {
								this->item = other.item;
								//other.item = nullptr;
								resultado = true;
							}
							return resultado;
						}
						inline ~SmartPointer()
						{
							if (this->item != nullptr)
								delete this->item;
						}
						inline T* operator->() { return this->item; }
						inline bool operator==(const SmartPointer<T>& other) { return (*this->item) == (*other.item); }
						inline T* get() { return this->item; }
				};
			}
			namespace Vector
			{
				// Only con operator new[]
				template<class T>
				class SmartPointer
				{
					protected:
						T* item;
					public:
						// Inicializar con new[]
						inline SmartPointer(T* item) { this->item = item; }
						inline ~SmartPointer() { delete[] this->item; }
						inline T* operator->() { return this->item; }
						inline T* get() { return this->item; }
				};
			}
		}
	}
}
#endif // !SMART_POINTER_HPP_