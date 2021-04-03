#pragma once
#include "IProblem.h"
#include "IMultiIndex.h"

class IDiffProblem : public IProblem {
public:
    static IDiffProblem * createDiffProblem(ICompact const * const &params, ICompact const * const &args);

    virtual double evalDerivativeByArgs(IVector const *args, IMultiIndex const *index) const = 0;
    virtual double evalDerivativeByParams(IVector const *params, IMultiIndex const *index) const = 0;

    virtual IVector *evalGradientByArgs(IVector const *args) const = 0;
    virtual IVector *evalGradientByParams(IVector const *params) const = 0;

private:
    IDiffProblem(const IDiffProblem &) = delete;
    IDiffProblem& operator=(const IDiffProblem &) = delete;

protected:
    IDiffProblem() = default;
};
