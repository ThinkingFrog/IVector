#pragma once
#include "IVector.h"
#include "IMultiIndex.h"
#include <cstddef>

class ICompactControlBlock {
public:
    /*
    * Control block finds closest node to vector: val + shift, and stores this node elements in val
    * 
    * @param [in] current_index Multi-index of current iterator position
    *
    * @param [in] val Old iterator position, new position will be stored here
    *
    */
    virtual RC get(IMultiIndex * const &current_index, IVector* const &val) const = 0;

    virtual ~ICompactControlBlock() = 0;

private:
    ICompactControlBlock(ICompactControlBlock const &);
    ICompactControlBlock& operator=(ICompactControlBlock const &);

protected:
    ICompactControlBlock() = default;
};
