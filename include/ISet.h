#pragma once
#include <cstddef>
#include "IVector.h"
#include "RC.h"

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

	/*
	* Iterator object can be created with ISet methods ISet::getIterator, ISet::getBegin, ISet::getEnd
	*/
	class IIterator {
	public:
		/*
		* Create iterator associated with next/previous position
		*
		* @param [in] indexInc Quantity of steps forward
		*/
		virtual IIterator * getNext(size_t indexInc = 1) const = 0;
		virtual IIterator * getPrevious(size_t indexInc = 1) const = 0;

		/*
		* Moves iterator forward/backward
		*/
		virtual RC next(size_t indexInc = 1)  = 0;
		virtual RC previous(size_t indexInc = 1)  = 0;

		static bool equal(const IIterator *op1, const IIterator *op2);
		/*
		* Getter of value (same semantic as ISet::getCopy)
		*/
		virtual RC getVectorCopy(IVector const*& val) const = 0;
		virtual RC getVectorCopy(IVector *& val) const = 0;
		/*
		* Getter of value (same semantic as ISet::getCoords)
		*/
		virtual RC getVectorCoords(IVector * const& val) const = 0;

		virtual ~IIterator()  = 0;

	protected:
		/*
		* Returns pointer to associated vector (necessary for comparison IIterator::equal)
		*/
		virtual IVector const * const getPtr() const = 0;

	private:
		IIterator(const IIterator&);
		IIterator& operator=(const IIterator&);

	protected:
		IIterator() = default;
	};

	virtual IIterator *getIterator(size_t index) const = 0;
	virtual IIterator *getBegin() const = 0;
	virtual IIterator *getEnd() const = 0;

	virtual ~ISet() = 0;

private:
	ISet(const ISet& other);
	ISet &operator=(const ISet& other);

protected:
	ISet() = default;
};
