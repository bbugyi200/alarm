include(../shared.cmake)

file(GLOB SOURCES "*.cc")
add_executable(countdown ${SOURCES})
install(TARGETS countdown DESTINATION bin)

prog_opts("countdown")
