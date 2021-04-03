#pragma once
#include <cstddef>

class IMultiIndex {
public:
    static IMultiIndex * createMultiIndex(size_t dim, const size_t* indices);

    virtual RC getAxisIndex(size_t axisIndex, size_t &val) const = 0;
    virtual RC setAxisIndex(size_t axisIndex, size_t val) = 0;

    virtual RC incAxisIndex(size_t axisIndex, ssize_t val) = 0;

    virtual size_t getDim() const = 0;
    virtual const size_t *getData() const = 0;

    virtual ~IMultiIndex() = 0;

private:
    IMultiIndex(const IMultiIndex&) = delete;
    IMultiIndex& operator=(const IMultiIndex&) = delete;

protected:
    IMultiIndex() = default;
};