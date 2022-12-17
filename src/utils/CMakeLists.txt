file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/utils/*.hh")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/utils/*.cc")

add_library(utils ${SOURCE_LIST} ${HEADER_LIST})

target_include_directories(utils PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_compile_features(utils PUBLIC cxx_std_17)

source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_LIST}
)
