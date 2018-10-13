include_directories(SYSTEM
	${CMAKE_SOURCE_DIR}/googletest/googlemock/include)
include_directories(SYSTEM
	${CMAKE_SOURCE_DIR}/mock)

enable_testing()

FILE(GLOB TEST_SRC
	"*.cpp"
	"*.h")

SET(UNIT_UNDER_TEST_SRC
	../life/rules.cpp
	../life/board.cpp
	../life/game.cpp
	)

SET(TEST_NAME ${PROJECT_NAME}-test)
ADD_EXECUTABLE(${TEST_NAME}
	${TEST_SRC}
	${UNIT_UNDER_TEST_SRC})

SET_PROPERTY(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 17)
TARGET_LINK_LIBRARIES(${TEST_NAME}
	gtest
	gtest_main
	mock)

TARGET_COMPILE_FEATURES(${TEST_NAME} PUBLIC cxx_override)
ADD_TEST(NAME UnitTest COMMAND ${TEST_NAME})

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}-test
	POST_BUILD
	COMMAND ./${PROJECT_NAME}-test
)
