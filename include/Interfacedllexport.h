#pragma once

#ifdef BUILD_INTERFACES //macro that means that dll building now
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif