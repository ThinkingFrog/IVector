#pragma once
#include "ILogger.h"
#include "IVector.h"
#include "RC.h"
#include "IMultiIndex.h"

class ICompact {
public:
    static ICompact* createCompact(IVector const * vec1, IVector const * vec2, IMultiIndex const *nodeQuantities);

    virtual ICompact *clone() const = 0;

    static RC setLogger(ILogger* const logger);

    virtual size_t getDim() const = 0;
    virtual IMultiIndex* getGrid() const = 0;

    virtual bool isInside(IVector const * const&vec) const = 0;
    /*
    * Method creating new IVector and assigning new address to val
    */
    virtual RC getVectorCopy(IMultiIndex const *index, IVector *& val) const = 0;
    /*
    * Method copy data from vector in ISet to vector val
    */
    virtual RC getVectorCoords(IMultiIndex const *index, IVector * const& val) const = 0;

    virtual RC setLeftBoundary(IVector const * vec) = 0;
    virtual RC setRightBoundary(IVector const * vec) = 0;
    virtual RC setGrid(IMultiIndex const *nodeQuantities) = 0;

    static ICompact* createIntersection(ICompact const *op1, ICompact const *op2, double tol);
    /* CompactSpan - компактная оболочка: строим наименьшее компактное множество, содержащее 2 переданных */
    static ICompact* createCompactSpan(ICompact const *op1, ICompact const *op2);

    class IIterator {
    public:
        virtual IIterator * getMovedIterator(IVector const *inc) = 0;
        virtual IIterator * clone() const = 0;

        static RC setLogger(ILogger * const pLogger);

        virtual RC moveIterator(IVector const *inc) = 0;

        static bool equal(const IIterator *op1, const IIterator *op2);

        /*
        * Method creating new IVector and assigning new address to val
        */
        virtual RC getVectorCopy(IVector *& val) const = 0;
        /*
        * Method copy data from vector in ISet to vector val
        */
        virtual RC getVectorCoords(IVector * const& val) const = 0;

        virtual ~IIterator() = 0;

    protected:
        /*
         * Every iterator corresponds to grid node -> corresponds to some multi-index, method necessary for comparison
         */
        virtual IMultiIndex const * const getIndex() const = 0;

    private:
        IIterator(const IIterator&) = delete;
        IIterator& operator=(const IIterator&) = delete;

    protected:
        IIterator() = default;
    };

    IIterator * getIterator(IVector const *vec) const = 0;
    IIterator * getBegin() const = 0;
    IIterator * getEnd() const = 0;

private:
    ICompact(const ICompact& compact) = delete;
    ICompact& operator=(const ICompact& compact) = delete;

protected:
    ICompact() = default;
};