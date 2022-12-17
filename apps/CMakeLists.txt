file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/apps/*.cc")

add_executable(app ${SOURCE_LIST})

target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE utils)
