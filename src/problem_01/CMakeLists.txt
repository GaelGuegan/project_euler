get_filename_component(current ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${current} "${current}.cpp")
#set_target_properties(PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
