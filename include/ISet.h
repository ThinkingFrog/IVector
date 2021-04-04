#pragma once
#include <cstddef>
#include "IVector.h"
#include "RC.h"

class ISet {
public:
	static RC setLogger(ILogger* const logger);
	
	static ISet* createSet();

	static ISet* makeIntersection(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static ISet* makeUnion(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static ISet* sub(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static ISet* symSub(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);

	static bool equals(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);
	static bool subSet(ISet const * const& op1, ISet const * const& op2, IVector::NORM n, double tol);

	virtual size_t getDim() const = 0;
	virtual size_t getSize() const = 0;

	/*
	 * Method creating new IVector and assigning new address to val
	 */
	virtual RC getCopy(size_t index, IVector const*& val) const = 0;
	virtual RC getCopy(size_t index, IVector *& val) const = 0;
	virtual RC findFirstAndCopy(IVector const * const& pat, IVector::NORM n, double tol, IVector const *& val) const = 0;
	virtual RC findFirstAndCopy(IVector const * const& pat, IVector::NORM n, double tol, IVector *& val) const = 0;

	/*
	 * Method copy data from vector in ISet to vector val
	 */
	virtual RC getCoords(size_t index, IVector * const& val) const = 0;
	virtual RC findFirstAndCopyCoords(IVector const * const& pat, IVector::NORM n, double tol, IVector * const& val) const = 0;

	virtual RC insert(IVector const * const& val, IVector::NORM n, double tol) = 0;

	virtual RC remove(size_t index) = 0;
	virtual RC remove(IVector const * const& pat, IVector::NORM n, double tol) = 0;

	virtual ~ISet() = 0;

private:	
	ISet(const ISet& other);
	ISet &operator=(const ISet& other);

protected:
	ISet() = default;
};
