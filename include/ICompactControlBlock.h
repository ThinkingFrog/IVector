#pragma once
#include "IVector.h"
#include <cstddef>

class ICompactControlBlock {
public:
    virtual RC get(IVector const * const &shift, IVector * const&val) const = 0;

    virtual ~ICompactControlBlock() = 0

private:
    ICompactControlBlock(ICompactControlBlock const &);
    ICompactControlBlock& operator=(ICompactControlBlock const &);

protected:
    ICompactControlBlock() = default;
};
