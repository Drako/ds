CONFIGURE_FILE ( config.hxx.in config.hxx )

FILE           ( GLOB ds_SOURCES *.cxx )
FILE           ( GLOB ds_HEADERS *.hxx )

ADD_EXECUTABLE ( ds
    ${ds_SOURCES}
    ${ds_HEADERS}
    "${CMAKE_CURRENT_BINARY_DIR}/config.hxx"
)

INSTALL        ( TARGETS ds DESTINATION bin )
