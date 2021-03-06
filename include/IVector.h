#pragma once
#include <cstddef>
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
        Infinite,
        First,
        Second
    };

    static IVector* createVector(size_t dim, double const* const& ptr_data, Logger* pLogger);
    virtual IVector* clone() const = 0;
    static RC copyInstance(IVector* dest, IVector const* const& src) const = 0;
    static RC moveInstance(IVector* dest, IVector* const& src) = 0;
    virtual double const * const getData() const = 0;

    virtual RC getCord(size_t index, double& val) const = 0;
    virtual RC setCord(size_t index, double val) = 0;
    virtual RC scale(double multiplier) = 0;
    virtual size_t dim() const = 0;

    //	Methods: increment, decrement
    //	Purpose: inplace add or subtract vector inplace (equal to vec1 = vec1 +/- vec2)
    //
    //	Param1: addend or subtrahend (for decrement)
    //	Param2: Logger for extended information about error
    //
    //	Return value: nullptr, if failed, or pointer to object,
    //	in order to make possible to construct such expressions like:
    //	vector1->decrement(vector2)->decrement(vector3)
    virtual IVector *increment(IVector * op, Logger* pLogger) = 0;
    virtual IVector *decrement(IVector * op, Logger* pLogger) = 0;

    static IVector* add(IVector const * op1, IVector const * op2, Logger* pLogger);
    static IVector* sub(IVector const * op1, IVector const * op2, Logger* pLogger);

    static double dot(IVector const * op1, IVector const * op2, Logger* pLogger);
    static bool equals(IVector const * op1, IVector const * op2, NORM n, double tol, Logger* pLogger);
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