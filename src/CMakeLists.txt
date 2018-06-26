include(../shared.cmake)

file(GLOB SOURCES "*.cc")
add_executable(countdown ${SOURCES})
target_link_libraries(countdown gutils)
target_include_directories(countdown PUBLIC ../include)

install(TARGETS countdown DESTINATION bin)

prog_opts("countdown")
