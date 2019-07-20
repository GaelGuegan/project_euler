get_filename_component(current ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${current} "${current}.cpp")
