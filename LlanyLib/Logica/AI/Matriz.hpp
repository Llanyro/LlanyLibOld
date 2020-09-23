#pragma once
#ifndef MATRIZ_OBJECT_AI_HPP_
#define MATRIZ_OBJECT_AI_HPP_

namespace LlanyLib {
	namespace Basic {
		namespace Templates {
			namespace Listas {
				template<class T>
				class LinkedList;
			}
		}
		namespace AI {
			namespace Objetos {
				class DataSet
				{
					protected:
						size_t rows;
						size_t cols;
						float** data;

					public:
						DataSet();
						DataSet(size_t rows, size_t cols, float** data);

						DataSet** createBatches(int numBatches) const;
						void shuffleTogether(DataSet* other);



				};
				class Matriz
				{
					protected:
						size_t rows;
						size_t cols;
						float* data;
					protected:

					public:


				};
			}
		}
	}
}
#endif // !MATRIZ_OBJECT_AI_HPP_
