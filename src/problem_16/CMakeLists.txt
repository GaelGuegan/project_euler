get_filename_component(current ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${current} "${current}.cpp")

#include_directories("/usr/gmp/include")
target_include_directories(${current} PUBLIC "/usr/gmp/include")
#link_directories("/usr/gmp/lib")
target_link_directories(${current} PUBLIC "/usr/gmp/lib")

target_link_libraries(${current} utils gmp)
install(TARGETS ${current} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/build)
