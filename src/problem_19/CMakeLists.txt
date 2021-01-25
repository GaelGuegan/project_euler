get_filename_component(current ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${current} "${current}.cpp")
target_link_libraries(${current} utils gmp)
install(TARGETS ${current} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/build)