// stdafx.h --- precompiled header                              -*- C++ -*-
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// Windows-related

#ifdef _WIN32
    // We must do all strictly!!!
    #define STRICT 1

    // the target versioning header
    #include "targetver.h"

    #if defined(_MSC_VER) && !defined(NDEBUG)
        // for detecting memory leak (MSVC only)
        #define _CRTDBG_MAP_ALLOC
        #include <crtdbg.h>
    #endif

    // Windows headers
    #include <windows.h>
    #include <tchar.h>
#endif

//////////////////////////////////////////////////////////////////////////////
// gtkmm headers

#include <gtkmm.h>
#include <gtkmm/main.h>

//////////////////////////////////////////////////////////////////////////////
// C headers

#include <cstdlib>
#include <cstdio>
#include <cstring>

//////////////////////////////////////////////////////////////////////////////
// C++ headers

#include <string>
#include <vector>
#include <new>

//////////////////////////////////////////////////////////////////////////////
// private headers

#include "TypicalGtkmmApp.h"
#include "MainWindow.h"

//////////////////////////////////////////////////////////////////////////////

#ifdef _WIN32
    #if defined(_MSC_VER) && !defined(NDEBUG)
        // for detecting memory leak (MSVC only)
        #define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
    #endif
#endif

//////////////////////////////////////////////////////////////////////////////
