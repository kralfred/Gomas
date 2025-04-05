#pragma once
#ifdef GM_PLATFORM_WINDOWS

   #ifdef GM_BUILD_DLL

     #define GOMAS_API __declspec(dllexport)

     #else
     #define GOMAS_API __declspec(dllimport)
   #endif

#else 
#error Gomas only supports windows


#endif

#define BIT(x) (1 << x)
