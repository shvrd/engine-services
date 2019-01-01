INCLUDE(CTest)
ENABLE_TESTING()

IF(MINGW)
    SET(gtest_disable_pthreads on)
ENDIF()

INCLUDE(${DEPENDENCIES}/DownloadProject/DownloadProject.cmake)
DOWNLOAD_PROJECT(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

ADD_SUBDIRECTORY(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)