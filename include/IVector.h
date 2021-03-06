#pragma once
#include <cstddef>
#include <functional>
#include "RC.h"

//size_t size = sizeof(Vector_Impl) + dim * sizeof(double)
//uint8_t* pInstance = new(std::nothrow) assert(pInstance)
//uint8_t* pData = pInstance + sizeof(Vector)
//memcpy(pData, (uint8_t*)ptrData, dim * sizeof(double))
//return new(pInstance) Vecotr_Impl(dim)

class Logger;

class IVector {
public:
    enum NORM {
        INFINITE,
        FIRST,
        SECOND
    };

    static IVector* createVector(size_t dim, double const* const ptr_data);
    static RC copyInstance(IVector* const dest, IVector const* const src);
    static RC moveInstance(IVector* const dest, IVector* const src);

    virtual IVector* clone() const = 0;
    virtual double const* getData() const = 0;

    static RC setLogger(Logger* const logger);

    virtual RC getCord(size_t index, double& val) const = 0;
    virtual RC setCord(size_t index, double val) = 0;
    virtual RC scale(double multiplier) = 0;
    virtual size_t getDim() const = 0;

    virtual RC inc(IVector const* const op) = 0;
    virtual RC dec(IVector const* const op) = 0;

    static IVector* add(IVector const* const op1, IVector const* const op2);
    static IVector* sub(IVector const* const op1, IVector const* const op2);

    static double dot(IVector const* const op1, IVector const* const op2);
    static bool equals(IVector const* const op1, IVector const* const op2, NORM n, double tol);
    virtual double norm(NORM n) const = 0;

    virtual RC applyFunction(const std::function<double(double)>& fun) = 0;
    virtual RC foreach(const std::function<void(double)>& fun) const = 0;

    virtual size_t sizeAllocated() const = 0;

    virtual ~IVector() = 0;

private:
    IVector(const IVector& vector) = delete;
    IVector& operator=(const IVector& vector) = delete;

protected:
    IVector() = default;
};