project(04_MedianOfTwoSortedArrays)

add_executable(${PROJECT_NAME} ./main.cpp)
target_include_directories(${PROJECT_NAME} 
    PRIVATE ${PRIVATE_DEPEND_INCLUDES})
target_link_libraries(${PROJECT_NAME} ${PRIVATE_DEPEND_LIBS})