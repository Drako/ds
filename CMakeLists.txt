PROJECT                ( DragonScript )
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8.10 )

# custom cmake modules are places here
SET                    ( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" )

# so we can include git revision in the program
FIND_PACKAGE           ( Git REQUIRED )
INCLUDE                ( GetGitRevisionDescription )
GET_GIT_HEAD_REVISION  ( GIT_REFSPEC GIT_HASH )

# we want to use current C++ features ;-)
INCLUDE                ( C++11 )

# for config.hxx
SET                    ( CMAKE_INCLUDE_CURRENT_DIR ON )

# the sources
ADD_SUBDIRECTORY       ( src )
