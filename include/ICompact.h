#pragma once
#include "ILogger.h"
#include "IVector.h"
#include "RC.h"
#include "IMultiIndex.h"

class ICompact {
public:
    static ICompact* createCompact(IVector const * vec1, IVector const * vec2, size_t dim, const size_t *nodeQuantity);

    static ICompact* createIntersection(ICompact const *op1, ICompact const *op2, double tol);

    /* CompactSpan - компактная оболочка: строим наименьшее компактное множество, содержащее 2 переданных */
    static ICompact* createCompactSpan(ICompact const *op1, ICompact const *op2);

    virtual RC getVectorCopy(IMultiIndex const *index, IVector *& val) const = 0;
    virtual RC getVectorCopy(IMultiIndex const *index, IVector const *& val) const = 0;

    virtual RC getVectorCoord(IMultiIndex const *index, IVector * const& val) const = 0;

    class IIterator {
    public:
        virtual IIterator * getMovedIterator(IVector const *inc) = 0;
        virtual RC moveIterator(IVector const *inc) = 0;

        virtual RC getVectorCopy(IVector *& val) const = 0;
        virtual RC getVectorCopy(IVector const *& val) const = 0;

        virtual RC getVectorCoord(IVector * const& val) const = 0;

        virtual ~IIterator() = 0;

    private:
        IIterator(const IIterator&) = delete;
        IIterator& operator=(const IIterator&) = delete;

    protected:
        IIterator() = default;
    };

    IIterator * getIterator(IVector const *vec) const = 0;
    IIterator * getBegin() const = 0;
    IIterator * getEnd() const = 0;

    static RC setLogger(ILogger* const logger);

private:
    ICompact(const ICompact& compact) = delete;
    ICompact& operator=(const ICompact& compact) = delete;

protected:
    ICompact() = default;
};