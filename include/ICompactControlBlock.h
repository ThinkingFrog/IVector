#pragma once
#include "IVector.h"
#include "IMultiIndex.h"
#include <cstddef>

class ICompactControlBlock {
public:
    /*
    * Control block moves iterator forward in grid of compact. When reached last node of an axis, next axis position will be incremented. Next axis defined by bypass_order
    * 
    * @param [in] current_index Multi-index of current iterator position
    *
    * @param [in] bypass_order Multi-index, that defining bypass orred of axis
    */
    virtual RC get(IMultiIndex * const &current_index, IMultiIndex const * const &bypass_order) const = 0;
    /*
    * Control block clculates vector corresponding to multi-index
    * 
    * @param [in] current_index Multi-index of current iterator position
    *
    * @param [in] val Buffer for vector data
    */
    virtual RC get(IMultiIndex const * const &current_indexIVector* const &val) const = 0;

    virtual ~ICompactControlBlock() = 0;

private:
    ICompactControlBlock(ICompactControlBlock const &);
    ICompactControlBlock& operator=(ICompactControlBlock const &);

protected:
    ICompactControlBlock() = default;
};
