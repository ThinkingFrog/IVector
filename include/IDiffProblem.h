#pragma once
#include "IProblem.h"
#include "IMultiIndex.h"
#include "Interfacedllexport.h"

class LIB_EXPORT IDiffProblem : public IProblem {
public:
    static IDiffProblem * createDiffProblem(ICompact const * const &params, ICompact const * const &args);
    IDiffProblem * clone() const override = 0;

    static RC setLogger(ILogger * const logger);
    static ILogger* getLogger();

    bool isValidParams(IVector const * const &params) const override = 0;
    bool isValidArgs(IVector const * const &args) const override = 0;

    RC setParams(IVector const * const &params) override = 0;
    RC setArgs(IVector const * const &args) override = 0;

    double evalByParams(IVector const *const &params) const override = 0;
    double evalByArgs(IVector const *const &args) const override = 0;

    virtual double evalDerivativeByArgs(IVector const * const &args, IMultiIndex const * const &index) const = 0;
    virtual double evalDerivativeByParams(IVector const * const &params, IMultiIndex const * const &index) const = 0;

    virtual RC evalGradientByArgs(IVector const * const &args, IVector * const &val) const = 0;
    virtual RC evalGradientByParams(IVector const * const &params, IVector * const &val) const = 0;

    ~IDiffProblem() override = 0;

private:
    IDiffProblem(const IDiffProblem &) = delete;
    IDiffProblem& operator=(const IDiffProblem &) = delete;

protected:
    IDiffProblem() = default;
};
