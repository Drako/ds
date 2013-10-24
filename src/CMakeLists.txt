CONFIGURE_FILE        ( config.hxx.in config.hxx )

FILE                  ( GLOB ds_SOURCES *.cxx )
FILE                  ( GLOB ds_HEADERS *.hxx )

INCLUDE_DIRECTORIES   ( ${Boost_INCLUDE_DIRS} )
LINK_DIRECTORIES      ( ${Boost_LIBRARY_DIRES} )

ADD_EXECUTABLE        ( ds
    ${ds_SOURCES}
    ${ds_HEADERS}
    "${CMAKE_CURRENT_BINARY_DIR}/config.hxx"
)
TARGET_LINK_LIBRARIES ( ds ${Boost_LIBRARIES} )

INSTALL               ( TARGETS ds DESTINATION bin )
