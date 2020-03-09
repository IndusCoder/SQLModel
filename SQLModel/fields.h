#ifndef FIELDS_H
#define FIELDS_H

#include <cstddef>

#define MK_FIELD(S,F,T) {#F, offsetof(S,F), T}

enum types{
    NUMBER = 0,
    STRING = 1,
    DATE = 2,
    TIME = 3,
    DATE_TIME = 4,
    BOOL = 5
};

struct SQLDataFields{
    const char* name;
    const std::size_t offset;
    const enum types type;
};

#endif // FIELDS_H
