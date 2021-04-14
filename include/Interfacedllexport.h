#pragma once

#if defined _WIN32 || defined __CYGWIN__
    #define LIB_DLL_IMPORT __declspec(dllimport)
    #define LIB_DLL_EXPORT __declspec(dllexport)
    #define LIB_DLL_LOCAL_VISIBILITY
#elif __GNUC__ >= 4
    #define LIB_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define LIB_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define LIB_DLL_LOCAL_VISIBILITY  __attribute__ ((visibility ("hidden")))
#else
    #define LIB_DLL_IMPORT
    #define LIB_DLL_EXPORT
    #define LIB_DLL_LOCAL_VISIBILITY
#endif


#ifdef BUILD_INTERFACES //macro that means that dll building now
#define LIB_EXPORT LIB_DLL_EXPORT
#else
#define LIB_EXPORT LIB_DLL_IMPORT
#endif

#define LIB_LOCAL LIB_DLL_LOCAL_VISIBILITY