#pragma once
#include "IVector.h"
#include <cstddef>

class ICompactControlBlock {
public:
    /*
    * Control block finds closest node to vector: val + shift, and stores this node elements in val
    * 
    * @param [in] shift Shift, that defines changes of iterator position
    *
    * @param [in] val Old iterator position, new position will be stored here
    *
    */
    virtual RC get(IVector const* const &shift, IVector* const&val) const = 0;

    virtual ~ICompactControlBlock() = 0;

private:
    ICompactControlBlock(ICompactControlBlock const &);
    ICompactControlBlock& operator=(ICompactControlBlock const &);

protected:
    ICompactControlBlock() = default;
};
