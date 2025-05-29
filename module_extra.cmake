
if(NOT TARGET libtag)
    find_package(libtag REQUIRED)
endif()

target_link_libraries(${PROJECT_NAME} debug ${LIBTAG_LIBRARIES_DEBUG} optimized ${LIBTAG_LIBRARIES_RELEASE})

# include srd dir and subdirectories of the libtag library
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBTAG_INCLUDE_DIR})
file(GLOB_RECURSE LIBTAG_INCLUDE_FILES ${LIBTAG_INCLUDE_DIR}/*.h)
foreach(file ${LIBTAG_INCLUDE_FILES})
    get_filename_component(dir ${file} DIRECTORY)
    if(NOT dir IN_LIST LIBTAG_INCLUDE_DIRS)
        list(APPEND LIBTAG_INCLUDE_DIRS ${dir})
    endif()
endforeach()

target_include_directories(${PROJECT_NAME} PUBLIC ${LIBTAG_INCLUDE_DIRS})
