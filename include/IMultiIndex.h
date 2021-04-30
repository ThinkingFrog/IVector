#pragma once
#include <cstddef>
#include <cstdlib>
#include "ILogger.h"

class LIB_EXPORT IMultiIndex {
public:
    static IMultiIndex * createMultiIndex(size_t dim, const size_t* indices);
    virtual IMultiIndex * clone() const = 0;

    virtual size_t getDim() const = 0;
    virtual const size_t *getData() const = 0;
    // Dim needs for double check that ptr_data have the same size as dimension of multi-index
    virtual RC setData(size_t dim, size_t const* const& ptr_data) = 0;

    static RC setLogger(ILogger * const pLogger);
    static ILogger* getLogger();

    virtual RC getAxisIndex(size_t axisIndex, size_t &val) const = 0;
    virtual RC setAxisIndex(size_t axisIndex, size_t val) = 0;

    virtual RC incAxisIndex(size_t axisIndex, ssize_t val) = 0;

    virtual ~IMultiIndex() = 0;

private:
    IMultiIndex(const IMultiIndex&) = delete;
    IMultiIndex& operator=(const IMultiIndex&) = delete;

protected:
    IMultiIndex() = default;
};
