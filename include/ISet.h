#pragma once
#include <cstddef>
#include "IVector.h"
#include "RC.h"

class ISetIterator {
public:
	/*
	* Create iterator associated with next/previous position
	*
	* @param [in] indexInc Quantity of steps forward
	*/
	virtual ISetIterator * getNext(size_t indexInc = 1)  = 0;
	/*
	* @param [in] indexInc Quantity of steps backward
	*/
	virtual ISetIterator * getPrevious(size_t indexDec = 1) = 0;

	/*
	* Moves iterator forward/backward
	*/
	virtual RC next(size_t indexInc = 1)  = 0;
	virtual RC previous(size_t indexDec = 1) = 0;

	static bool equal(const ISetIterator *op1, const ISetIterator *op2);
	/*
	* Getter of value (same semantic as ISet::get)
	*/
	virtual RC getValue(IVector const* val) = 0;

	virtual ~ISetIterator()  = 0;

private:
	/*
	* Returns pointer to associated vector (necessary for comparison ISetIterator::equal)
	*/
	virtual IVector const * const getPtr() = 0;

	ISetIterator(const ISetIterator&);
	ISetIterator& operator=(const ISetIterator&);

protected:
	ISetIterator() = default;
};

class ISet {
public:
	static RC setLogger(ILogger* const logger);

	static ISet* createSet(ILogger* pLogger);

	static ISet* cap(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static ISet* cup(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static ISet* sub(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static ISet* symSub(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);

	static bool equals(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static bool subSet(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);

	virtual size_t getDim() const = 0;
	virtual size_t getSize() const = 0;

	virtual RC get(size_t index, IVector const* val) const = 0;
	virtual RC findFirst(IVector const * const& pat, IVector::NORM n, double tol, IVector const *& val) const = 0;

	virtual RC insert(IVector const *& val, IVector::NORM n, double tol) = 0;

	virtual RC remove(size_t index) = 0;
	virtual RC remove(IVector const * const& pat, IVector::NORM n, double tol) = 0;

	virtual ISetIterator *getIterator(size_t index) const = 0;
	virtual ISetIterator *getBegin() const = 0;
	virtual ISetIterator *getEnd() const = 0;

	virtual ~ISet() = 0;

private:
	ISet(const ISet& other);
	ISet &operator=(const ISet& other);

protected:
	ISet() = default;
};
