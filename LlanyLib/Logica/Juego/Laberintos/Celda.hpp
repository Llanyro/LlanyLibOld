#pragma once
#ifndef CELDA_INTERFACE_HPP_
#define CELDA_INTERFACE_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template <class T>
				class LinkedList;
				template<class T>
				class Array;
			}
		}
	}
	namespace Objetos {
		class Celda
		{
			protected:
				Basic::Templates::Listas::Array<bool>* posiciones;
				Basic::Templates::Listas::LinkedList<Celda*>* grupo;
			public:
				Celda(const size_t& numPos);
				Celda(const Celda& other);
				bool operator=(const Celda& other);
				~Celda();

				const Basic::Templates::Listas::LinkedList<Celda*>* getGrupo() const;

				void setAll(const bool& value);

				bool igual(const Celda& other) const;
				//bool similar(const Critico& other) const;

				bool operator==(const Celda& other) const;
				bool operator!=(const Celda& other) const;

				void mergeGrupos(const Celda& other);
				bool contiene(const Celda* other) const;
				void romperGrupo();
		};
	}
}

#endif // !CELDA_INTERFACE_HPP_
