file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/tests/utils/*.cc")

add_executable(test_utils ${SOURCE_LIST})

target_compile_features(test_utils PRIVATE cxx_std_17)

target_link_libraries(test_utils PRIVATE utils GTest::gtest_main)

gtest_discover_tests(test_utils)
