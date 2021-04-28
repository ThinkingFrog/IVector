#pragma once
#include "ILogger.h"
#include "ICompact.h"
#include "ISet.h"
#include "IProblem.h"
#include "Interfacedllexport.h"

class LIB_EXPORT ISolver {
    static ISolver* createSolver();
    static RC setLogger(ILogger* const pLogger);
    static ILogger* getLogger();
    
    virtual ISolver* clone() const = 0;

    virtual RC setProblem(IProblem const* const& pProblem) = 0;

    virtual bool isValidArgsDomain(ICompact const* const& args) const = 0;
    virtual bool isValidParamsDomain(ICompact const* const& params) const = 0;
    virtual RC setArgsDomain(ICompact const* const& args) = 0;
    virtual RC setParamsDomain(ICompact const* const& params) = 0;

    // initArg - starting point (x0)
    // solverParams - defined by developer of exact Solver, described in his header
    virtual RC solveByArgs(IVector const* const& initArg, IVector* const* const& solverParams) = 0;
    virtual RC solveByParams(IVector const* const& initParam, IVector* const* const& solverParams) = 0;
    virtual RC getSolution(IVector*& solution) const = 0;

    virtual ~ISolver() = 0;

private:
    ISolver(const ISolver &) = delete;
    ISolver& operator=(const ISolver &) = delete;

protected:
    ISolver() = default;
};
