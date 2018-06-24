include(../shared.cmake)

file(GLOB SOURCES "*.cc")
add_executable(alarm ${SOURCES})
install(TARGETS alarm DESTINATION bin)

prog_opts(alarm)
