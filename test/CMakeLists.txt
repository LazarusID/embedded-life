include_directories(SYSTEM
	${CMAKE_SOURCE_DIR}/googletest/googlemock/include)
include_directories(SYSTEM
	${CMAKE_SOURCE_DIR}/mock)

enable_testing()

FILE(GLOB TEST_SRC
	"*.cpp"
	"*.h")

SET(UNIT_UNDER_TEST_SRC
	../unit.cpp)

SET(TEST_NAME ${PROJECT_NAME}-test)
ADD_EXECUTABLE(${TEST_NAME}
	${TEST_SRC}
	${UNIT_UNDER_TEST_SRC})

SET_PROPERTY(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(${TEST_NAME}
	gmock
	gtest
	gtest_main)

TARGET_COMPILE_FEATURES(${TEST_NAME} PUBLIC cxx_override)
ADD_TEST(UnitTest ${TEST_NAME})
