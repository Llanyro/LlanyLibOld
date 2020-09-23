#include "Matriz.hpp"

#include <assert.h>

#pragma region DataSet
LlanyLib::Basic::AI::Objetos::DataSet::DataSet()
{
    this->rows = 0;
    this->cols = 0;
    this->data = nullptr;
}
LlanyLib::Basic::AI::Objetos::DataSet::DataSet(size_t rows, size_t cols, float** data) : DataSet()
{
    this->rows = rows;
    this->cols = cols;
    this->data = data;
}
LlanyLib::Basic::AI::Objetos::DataSet** LlanyLib::Basic::AI::Objetos::DataSet::createBatches(int numBatches) const
{
    DataSet** batches = new DataSet * [numBatches];
    int remainder = this->rows % numBatches;
    int curRow = 0;
    for (int i = 0; i < numBatches; i++) {
        size_t batchSize = this->rows / numBatches;
        if (remainder-- > 0)
            batchSize++;
        batches[i] = new DataSet(batchSize, this->cols, this->data + curRow);
        curRow += batchSize;
    }
    return batches;
}
void LlanyLib::Basic::AI::Objetos::DataSet::shuffleTogether(DataSet* other)
{
    assert(this->rows == other->rows);
    for (int i = 0; i < this->rows - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (this->rows - i) + 1);
        float* tmpA = this->data[j];
        this->data[j] = this->data[i];
        this->data[i] = tmpA;
        float* tmpB = other->data[j];
        other->data[j] = other->data[i];
        other->data[i] = tmpB;
    }
}
#pragma endregion

