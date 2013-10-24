IF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" )
    # up to some point clang used -std=c++0x
    # but we use features that come with clang 3.1 and newer
    # which knows -std=c++11 so we use that
    IF ( "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "3.1" )
        MESSAGE ( FATAL_ERROR "Clang 3.1 or newer required!" )
    ELSE ()
        SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
    ENDIF ()
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" )
    # from GCC 4.7 the flag -std=c++11 is supported
    # older versions only know -std=c++0x
    # but as we want to use some of the cooler C++11 features
    # we require 4.7 as a minimum
    IF ( "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "4.7" )
        MESSAGE ( FATAL_ERROR "GCC 4.7 or newer required!" )
    ELSE ()
        SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
    ENDIF ()
ELSEIF ( "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC" )
    # MSVC has C++11 enabled by default
    # but we require a minimum MSVC version
    # which provides all the C++11 features we use
    IF ( "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS "18.00" )
        MESSAGE ( FATAL_ERROR "Microsoft Visual C++ 2013 or newer required!" )
    ENDIF ()
ELSE ()
    MESSAGE ( FATAL_ERROR "Unsupported compiler... Don't know how to enable C++11!" )
ENDIF ()

MESSAGE ( STATUS "C++11 enabled." )
