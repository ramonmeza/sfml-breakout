file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/game/*.hh")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/game/*.cc")

add_library(game ${SOURCE_LIST} ${HEADER_LIST})

target_compile_features(game PUBLIC cxx_std_17)

target_include_directories(game PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(game PUBLIC sfml-graphics)

source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_LIST}
)
