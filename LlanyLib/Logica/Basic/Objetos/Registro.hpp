#pragma once
#ifndef REGISTRO_OBJECT_BASIC_HPP_
#define REGISTRO_OBJECT_BASIC_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class Registro
			{
				protected:
					bool* registro;
					size_t size;
				public:
					Registro(const size_t& size);
					~Registro();
					bool setPosTrue();

					void setAll(const bool& value);

					bool isTrue() const;
			};
		}
	}
}
#endif // !REGISTRO_OBJECT_BASIC_HPP_
