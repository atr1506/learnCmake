cmake_minimum_required(VERSION 3.22)
project(learnCmake)

function(print_link_libs tgt)
    get_target_property(res ${tgt} LINK_LIBRARIES)
    message(STATUS "link libs of ${tgt}: ${res}")
    get_target_property(res ${tgt} INTERFACE_LINK_LIBRARIES)
    message(STATUS "interface link libs of ${tgt}: ${res}")
endfunction(print_link_libs tgt)



set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_C_STANDARD 11)

message(STATUS "source path: ${CMAKE_CURRENT_SOURCE_DIR}")

add_library(libmath STATIC math/math.c)

target_include_directories(libmath PUBLIC  math/interface)
target_include_directories(libmath PRIVATE math/include)#头文件属性只有在链接到了这个target时才生效，如果不链接到libmath时，头文件属性无效。


add_library(libstat STATIC stat/stat.c)
target_include_directories(libstat PUBLIC stat/include)
target_include_directories(libstat PRIVATE math/include) #target_include_directories的private表示其它target链接libstat时 libstat的头文件只对libstat可见，对其他target不可见。在main.c中调用包含mymath.h会报 “找不到头文件”

target_link_libraries(libstat PUBLIC libmath)#target_link_libraries的private表示其它target链接libstat时不会链接libmath，在main.c中调用math的函数会报“未定义的引用”错误
print_link_libs(libstat)


add_executable(learn main.c)
target_link_libraries(learn PUBLIC libstat)
print_link_libs(learn)

# add_executable(learnstat mainStat.c)
# # target_include_directories(learnstat PUBLIC stat/include)
# target_link_libraries(learnstat PUBLIC libstat)