#pragma once
#include "IProblem.h"
#include "IMultiIndex.h"

class IDiffProblem : public IProblem {
public:
	static IDiffProblem * createDiffProblem(ICompact const * const &params, ICompact const * const &args);

	virtual double derivativeByArgs(IVector const *vec, IMultiIndex const *index);

	virtual IVector *evalGradientByArgs(IVector const *vec) const = 0;

private:
	IDiffProblem(const IDiffProblem &) = delete;
	IDiffProblem& operator=(const IDiffProblem &) = delete;

protected:
	IDiffProblem() = default;
};