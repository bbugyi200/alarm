project(alarm)

function(prog_opts exe)
    find_package(Boost COMPONENTS program_options REQUIRED)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${exe} ${Boost_LIBRARIES})
endfunction(prog_opts)
