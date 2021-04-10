#pragma once
#include "IVector.h"
#include <cstddef>

class IControlBlock {
public:
	virtual RC get(IVector *const &vec, size_t &index) const = 0;

private:
	IControlBlock(IControlBlock const &);
	IControlBlock& operator=(IControlBlock const &);

protected:
	IControlBlock() = default;
};