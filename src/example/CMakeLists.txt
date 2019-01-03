# set example files
SET(EXAMPLE_SRC main.cpp ExampleScene.h)

# add to executable
ADD_EXECUTABLE(library_example ${EXAMPLE_SRC})

# add the libs and includes
TARGET_LINK_LIBRARIES(library_example generic_library)
TARGET_INCLUDE_DIRECTORIES(library_example PUBLIC ../library)
