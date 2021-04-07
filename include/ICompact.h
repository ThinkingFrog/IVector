#pragma once
#include "ILogger.h"
#include "IVector.h"
#include "RC.h"
#include "IMultiIndex.h"

class ICompact {
public:
    static ICompact* createCompact(IVector const * vec1, IVector const * vec2, IMultiIndex const *nodeQuantities);

    static ICompact* createIntersection(ICompact const *op1, ICompact const *op2, double tol);

    /* CompactSpan - компактная оболочка: строим наименьшее компактное множество, содержащее 2 переданных */
    static ICompact* createCompactSpan(ICompact const *op1, ICompact const *op2);

    virtual ICompact *clone() const = 0;

    /*
    * Method creating new IVector and assigning new address to val
    */
    virtual RC getVectorCopy(IMultiIndex const *index, IVector *& val) const = 0;
    virtual RC getVectorCopy(IMultiIndex const *index, IVector const *& val) const = 0;
    /*
    * Method copy data from vector in ISet to vector val
    */
    virtual RC getVectorCoords(IMultiIndex const *index, IVector * const& val) const = 0;

    class IIterator {
    public:
        virtual IIterator * getMovedIterator(IVector const *inc) = 0;
        virtual RC moveIterator(IVector const *inc) = 0;
        /*
        * Method creating new IVector and assigning new address to val
        */
        virtual RC getVectorCopy(IVector *& val) const = 0;
        virtual RC getVectorCopy(IVector const *& val) const = 0;
        /*
        * Method copy data from vector in ISet to vector val
        */
        virtual RC getVectorCoords(IVector * const& val) const = 0;

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