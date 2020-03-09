#ifndef SQLMODEL_GLOBAL_H
#define SQLMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SQLMODEL_LIBRARY)
#  define SQLMODEL_EXPORT Q_DECL_EXPORT
#else
#  define SQLMODEL_EXPORT Q_DECL_IMPORT
#endif

#endif // SQLMODEL_GLOBAL_H
