#pragma once

#if defined(Q_DECL_EXPORT) && defined(Q_DECL_IMPORT)

#   define API_DECL_EXPORT Q_DECL_EXPORT
#   define API_DECL_IMPORT Q_DECL_IMPORT

#else // defined(Q_DECL_EXPORT) && defined(Q_DECL_IMPORT)

/*
 * Compiler & system detection for API_DECL_EXPORT & API_DECL_IMPORT.
 * Not using QtCore cause it shouldn't depend on Qt.
*/

#if defined(_MSC_VER)
#   define API_DECL_EXPORT      __declspec(dllexport)
#   define API_DECL_IMPORT      __declspec(dllimport)
#elif defined(__ARMCC__) || defined(__CC_ARM)
#   if defined(ANDROID) || defined(__linux__) || defined(__linux)
#       define API_DECL_EXPORT  __attribute__((visibility("default")))
#       define API_DECL_IMPORT  __attribute__((visibility("default")))
#   else
#       define API_DECL_EXPORT  __declspec(dllexport)
#       define API_DECL_IMPORT  __declspec(dllimport)
#   endif
#elif defined(__GNUC__)
#   if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || \
       defined(WIN64) || defined(_WIN64) || defined(__WIN64__)
#       define API_DECL_EXPORT  __declspec(dllexport)
#       define API_DECL_IMPORT  __declspec(dllimport)
#   else
#       define API_DECL_EXPORT  __attribute__((visibility("default")))
#       define API_DECL_IMPORT  __attribute__((visibility("default")))
#   endif
#else
#   define API_DECL_EXPORT      __attribute__((visibility("default")))
#   define API_DECL_IMPORT      __attribute__((visibility("default")))
#endif

#endif // defined(Q_DECL_EXPORT) && defined(Q_DECL_IMPORT)

/*
 * Define API_EXPORT for exporting function & class.
*/

#ifndef API_EXPORT
#if defined(API_LIBRARY_SHARED_BUILDING__)
#  define API_EXPORT API_DECL_EXPORT
#elif defined(API_LIBRARY_SHARED_USING__)
#  define API_EXPORT API_DECL_IMPORT
#else
#  define API_EXPORT
#endif
#endif /*API_EXPORT*/