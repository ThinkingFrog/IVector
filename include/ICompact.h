#pragma once
#include "ILogger.h"
#include "IVector.h"
#include "RC.h"

class ICompact {
public:
    static ICompact* createCompact(IVector const * vec1, IVector const * vec2, size_t dim, const size_t *nodeQuantity);

    static ICompact* createIntersection(ICompact const *op1, ICompact const *op2, double tol);

    /* CompactSpan - компактная оболочка: строим наименьшее компактное множество, содержащее 2 переданных */
    static ICompact* createCompactSpan(ICompact const *op1, ICompact const *op2);

    class Index {
    	static Index * createIndex(size_t dim, const size_t* indices);

    	virtual RC getAxisIndex(size_t axes_index) const = 0;
    	virtual RC setAxisIndex(size_t axes_index) = 0;

    	virtual RC incAxisIndex(size_t axes_index, ssize_t val) = 0;

    	virtual ~Index() = 0;
    };

    virtual RC getVectorCopy(Index const *index, IVector *& val) const = 0;
    virtual RC getVectorCopy(Index const *index, IVector const *& val) const = 0;

    virtual RC getVectorCoord(Index const *index, IVector * const& val) const = 0;

    class IIterator {
    	virtual IIterator * getMoved(IVector const *inc) = 0;
    	virtual RC move(IVector const *inc) = 0;

    	virtual RC changeNorm(IVector::NORM new_norm) = 0;

		virtual RC getVectorCopy(IVector *& val) const = 0;
		virtual RC getVectorCopy(IVector const *& val) const = 0;

		virtual RC getVectorCoord(IVector * const& val) const = 0;

		virtual ~IIterator() = 0;
    };

    IIterator * getIterator(IVector const *vec, IVector::NORM n) const = 0;
    IIterator * getBegin() const = 0;
    IIterator * getEnd() const = 0;

    static RC setLogger(ILogger* const logger);

private:
    ICompact(const ICompact& compact) = delete;
    ICompact& operator=(const ICompact& compact) = delete;

protected:
    ICompact() = default;
};