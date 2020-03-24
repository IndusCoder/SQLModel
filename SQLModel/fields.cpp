#include <string.h>

#include "fields.h"

const struct SQLDataFields *getFieldPtr(const char *name, const struct SQLDataFields *FIELDS)
{
    for(const struct SQLDataFields *field=FIELDS; field->name; ++field)
        if(!strcmp(name,field->name))
            return field;

    return nullptr;
}
