set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. DIRSRCS)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(permute SHARED ${DIRSRCS})
