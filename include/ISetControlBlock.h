#pragma once
#include "IVector.h"
#include <cstddef>

class ISetControlBlock {
public:
    virtual RC getNext(IVector *const &vec, size_t &index, size_t indexInc = 1) const = 0;
    virtual RC getPrevious(IVector *const &vec, size_t &index, size_t indexInc = 1) const = 0;
    
    virtual RC getBegin(IVector *const &vec, size_t &index) const = 0;
    virtual RC getEnd(IVector *const &vec, size_t &index) const = 0;

    virtual ~ISetControlBlock() = 0;

private:
    ISetControlBlock(ISetControlBlock const &);
    ISetControlBlock& operator=(ISetControlBlock const &);

protected:
    ISetControlBlock() = default;
};
