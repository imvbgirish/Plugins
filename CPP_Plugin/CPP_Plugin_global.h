#ifndef CPP_PLUGIN_GLOBAL_H
#define CPP_PLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CPP_PLUGIN_LIBRARY)
#define CPP_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#define CPP_PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // CPP_PLUGIN_GLOBAL_H
