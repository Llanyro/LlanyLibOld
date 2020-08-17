#pragma once
#ifndef STRING_PRINTER_HPP_
#define STRING_PRINTER_HPP_

#include "../Plantillas/Otros/Singleton.hpp"
#include "../Gestores/SubscriptorSingletons.hpp"

#define STRING_PRINTER LlanyLib::Basic::Singletons::StringPrinter::getInstancia()

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class JSONBuilder;
			class String;
		}
		namespace Templates {
			namespace Listas {
				template<class T>
				class Buffer;
				template<class T>
				class LinkedList;
			}
		}
		namespace Singletons {
			class StringPrinter : public Templates::Singleton<StringPrinter>, Gestores::SubscriptorSingletons
			{
				#pragma region Singleton
				private:
					friend class Singleton<StringPrinter>;
					StringPrinter();
					~StringPrinter();
				#pragma endregion

				protected:
					//void print(const char* str) const;
				public:
					void print(const char& caracter) const;
					void print(const char* str, const size_t& size) const;
					void print(const Objetos::String* str) const;
					void print(const Objetos::String& str) const;
					void print(const Objetos::JSONBuilder* json) const;

					void printClear(Objetos::String* str) const;
					void printClear(Objetos::JSONBuilder* json) const;

					void printLn(const char& caracter) const;
					void printLn(const char* str, const size_t& size) const;
					void printLn(const Objetos::String* str) const;
					void printLn(const Objetos::JSONBuilder* str) const;

					void printLnClear(Objetos::String* str) const;
					void printLnClear(Objetos::JSONBuilder* json) const;

					void print(LlanyLib::Basic::Templates::Listas::LinkedList<
						LlanyLib::Basic::Objetos::String*>* list) const;
					void printClear(LlanyLib::Basic::Templates::Listas::LinkedList<
						LlanyLib::Basic::Objetos::String*>* list) const;

					void printLn(LlanyLib::Basic::Templates::Listas::LinkedList<
						LlanyLib::Basic::Objetos::String*>* list) const;
					void printLnClear(LlanyLib::Basic::Templates::Listas::LinkedList<
						LlanyLib::Basic::Objetos::String*>* list) const;

			};
		}
	}
}
#endif // !STRING_PRINTER_HPP_
