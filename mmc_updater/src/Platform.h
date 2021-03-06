#pragma once

// basic platform defines
#ifdef __linux__
 #define PLATFORM_LINUX
#endif

#ifdef WIN32
 #define PLATFORM_WINDOWS
 #define WIN32_LEAN_AND_MEAN
 #include <windows.h>
 #include <shellapi.h>

 // disable warnings about exception specifications,
 // which are not implemented in Visual C++
    #ifdef MSVC
        #pragma warning(disable:4290)
    #endif
#endif

#ifdef __APPLE__
 #define PLATFORM_MAC
#endif

#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
 #define PLATFORM_UNIX
#endif

// platform-specific type aliases
#if defined(PLATFORM_UNIX)
 #define PLATFORM_PID pid_t
#else
 #define PLATFORM_PID DWORD
#endif
