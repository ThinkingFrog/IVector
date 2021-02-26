#pragma once
#include <cstddef>

//Norm, RC = enum

class Logger;

class IVector {
public:
    static IVector* createVector(size_t dim, double const* ptr_data, Logger* pLogger);
    virtual IVector* clone() const = 0;
    
    virtual RC getCord(size_t index, double& val) const = 0;
    virtual RC setCord(size_t index, double val) = 0;
    virtual RC scale(double multiplier) = 0;
    virtual size_t dim() const = 0;

    static IVector* add(IVector const * op1, IVector const * op2);
    static IVector* sub(IVector const * op1, IVector const * op2);

    static double dot(IVector const * op1, IVector const * op2);
    static bool equals(IVector const * op1, IVector const * op2);
    virtual double norm(NORM n) const = 0;

    virtual ~IVector() = 0;
private:
    IVector(IVector const& vector) = delete;
    IVector& operator =(IVector const& vector) = delete;
protected:
    IVector() = default;
};