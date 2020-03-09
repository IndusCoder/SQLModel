#ifndef FIELDS_H
#define FIELDS_H

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
};

#endif // FIELDS_H
