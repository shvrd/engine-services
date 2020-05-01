# unit tests for the library
INCLUDE(SetupGTest.cmake)

# Code Coverage with gcov
ADD_COMPILE_OPTIONS(--coverage)

SET(TEST_SRC main.cpp util/TimerTest.cpp util/TimerUtilTest.cpp types/ColorTest.cpp util/MathTest.cpp log/LoggerTest.cpp)

ADD_EXECUTABLE(shvrd_test ${TEST_SRC})
TARGET_LINK_LIBRARIES(shvrd_test gtest gmock gcov shvrd_library)
TARGET_INCLUDE_DIRECTORIES(shvrd_test PUBLIC ${LIBRARY_INCLUDE_DIRS})
