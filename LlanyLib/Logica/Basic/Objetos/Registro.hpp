#pragma once
#ifndef REGISTRO_OBJECT_BASIC_HPP_
#define REGISTRO_OBJECT_BASIC_HPP_

#include "../Interfaces/Listas.hpp"

namespace LlanyLib {
	namespace Basic {
		namespace Objetos {
			class Registro : public Interfaces::Listas
			{
				protected:
					bool* registro;
				protected:
					size_t lastTrueProtected(const size_t& pos) const;
				public:
					Registro(const size_t& size);
					~Registro();
					//bool setPos(const size_t& pos, const bool& value);
					bool setPosTrue(const size_t& pos);
					bool setPosFalse(const size_t& pos);
					void setAll(const bool& value);
					bool isTrue() const;
					const bool* getPos(const size_t& pos) const;
					size_t lastTrue() const;
			};
		}
	}
}
#endif // !REGISTRO_OBJECT_BASIC_HPP_
