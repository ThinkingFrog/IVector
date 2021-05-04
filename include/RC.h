#pragma once

enum class RC {
    UNKNOWN,
    SUCCESS,
    INVALID_ARGUMENT,
    MISMATCHING_DIMENSIONS,
    INDEX_OUT_OF_BOUND,
    INFINITY_OVERFLOW, // Number is greater than infinity
    NOT_NUMBER,
    ALLOCATION_ERROR, // Couldn't allocate new memory
    NULLPTR_ERROR, // Received nullptr
    FILE_NOT_FOUND, // Couldn't find file with corresponding name
    VECTOR_NOT_FOUND, // Couldn't find vector instance in ISet method
    IO_ERROR, // Couldn't write/read to/from file
    MEMORY_INTERSECTION, // Found intersecting memory while copying instance
    SOURCE_SET_DESTROYED, // Iterator trying to work with dead set
    SOURCE_COMPACT_DESTROYED, // Iterator trying to work with dead compact
    SOURCE_SET_EMPTY, // Iterator trying to move to the begin/end of empty set
    VECTOR_ALREADY_EXIST,
    SET_INDEX_OVERFLOW,
    NO_ARGS_SET, // no arguments set for problem to evaluate or for solver to solve
    NO_PARAMS_SET, // no params set for problem to evaluate or for solver to solve
    NO_PROBLEM_SET, // no problem set for solver to solve
    AMOUNT
};
