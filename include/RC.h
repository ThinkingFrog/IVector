#pragma once

enum class RC {
    UNKNOWN,
    SUCCESS,
    INVALID_ARGUMENT,
    MISMATCHING_DIMENSIONS,
    INDEX_OUT_OF_BOUND,
    INFINITY_OVERFLOW,
    NOT_NUMBER,
    ALLOCATION_ERROR, // Couldn't allocate new memory
    NULLPTR_ERROR, // Received nullptr
    FILE_NOT_FOUND, // Couldn't file with corresponding name
    VECTOR_NOT_FOUND, // Couldn't find vector inst in ISet method
    IO_ERROR,// Couldn't write/read to/from file
    AMOUNT
};