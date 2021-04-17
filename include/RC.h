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
    SOURCE_SET_DESTROYED,
    SOURCE_SET_EMPTY,
    VECTOR_ALREADY_EXIST,
    SET_INDEX_OVERFLOW,
    AMOUNT
};
