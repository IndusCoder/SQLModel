#ifndef FIELDS_H
#define FIELDS_H

#include <cstddef>
#include <memory>

#define MK_FIELD(S,F,T) {#F, offsetof(S,F), T}

enum types{
    NUMBER = 0,
    STRING = 1,
    DATE = 2,
    TIME = 3,
    DATE_TIME = 4,
    BOOL = 5
};

struct FieldValue{
    const enum types type;
    std::shared_ptr<void *> data_ptr;

    int *toInt();
    char *toChar();
};

struct SQLDataFields{
    const char* name;
    const std::size_t offset;
    const enum types type;
};

const struct SQLDataFields *getFieldPtr(const char *name, const struct SQLDataFields *FIELDS);

#endif // FIELDS_H
