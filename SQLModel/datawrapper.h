#ifndef SQLDATAWRAPPER_H
#define SQLDATAWRAPPER_H

#include <list>
#include <iterator>
#include <memory>

#include "fields.h"

template <typename T>
class DataWrapper
{
    const DataWrapper *m_FIELDS;
    std::list<std::shared_ptr<T>> m_fList;

    T* (*foo)(void *);
public:
    template<typename R>
    static DataWrapper *createWrapper(const struct SQLDataFields *FIELDS)
    {
        int counter=0;
        for(const struct SQLDataFields *field=FIELDS; field->name; ++field)
        {
            counter++;
        }
        if(!counter)
            return nullptr;

        return new DataWrapper<R>(FIELDS);
    }

    FieldValue *data(int row, const char *name)
    {
        if(m_fList.size()<=row)
            return nullptr;
        const SQLDataFields *f=getFieldPtr(name,m_FIELDS);
        if(!f)
            return nullptr;

        auto it=std::advance(m_fList.begin(),row);
        std::shared_ptr<T> p((*it));

        void *ptr=p.get();
        void *dataPtr=(char*)ptr + f->offset;

        FieldValue *v=new FieldValue({f->type,std::shared_ptr<T>(dataPtr)});
        return v;
    }

    std::shared_ptr<T> getRow(int row){
        if(row<m_fList.size())
            return nullptr;
        auto it=std::advance(m_fList.begin(),row);
        return (*it);
    }

private:
    DataWrapper(const struct SQLDataFields *FIELDS):
        m_FIELDS(FIELDS)
    {}
};

#endif // SQLDATAWRAPPER_H
