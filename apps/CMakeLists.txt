file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/apps/*.cc")
file(COPY "${PROJECT_SOURCE_DIR}/data/config.ini" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/data/")
file(COPY "${PROJECT_SOURCE_DIR}/data/textures/player.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/data/textures")

add_executable(app ${SOURCE_LIST})

target_compile_features(app PRIVATE cxx_std_17)

target_include_directories(app PUBLIC "${inireader_SOURCE_DIR}")
target_link_libraries(app PUBLIC sfml-graphics PRIVATE game utils)
