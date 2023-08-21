cmake_minimum_required(VERSION 3.13)
project(Sombrosa)
set(CMAKE_CXX_STANDARD 20)

# Define the source files for your executable
set(SOURCE_FILES "./src/main.cpp" "./src/gl.c" "./src/shaderClass.cpp" "./src/VAO.cpp" "./src/VBO.cpp" "./src/EBO.cpp" "./src/ship.cpp" "./src/asteroid.cpp")

# Specify the path to the GLFW library
set(GLFW_LIB_PATH "./Libraries/lib/glfw3.lib")
set(OPENGL_LIB_PATH "./Libraries/lib/opengl32.lib")
set(HEADERS "./Libraries/include/GLFW/glfw3.h" "./Libraries/include/GLFW/glfw3native.h" "./Libraries/include/glad/gl.h" "./Libraries/include/KHR/khrplatform.h" "./src/Headers/shaderClass.h" "./src/Headers/VAO.h" "./src/Headers/VBO.h" "./src/Headers/EBO.h" "./src/Headers/ship.h" "./src/Headers/asteroid.h")

# Create an executable target
add_executable(Sombrosa ${SOURCE_FILES} ${HEADERS})

# Create a library target for GLFW
add_library(MyGLFWLibrary STATIC IMPORTED)
set_target_properties(MyGLFWLibrary PROPERTIES IMPORTED_LOCATION ${GLFW_LIB_PATH})

add_library(MyOpenGLLibrary STATIC IMPORTED)
set_target_properties(MyOpenGLLibrary PROPERTIES IMPORTED_LOCATION  ${OPENGL_LIB_PATH})

# Add include directories for GLFW
target_include_directories(Sombrosa PRIVATE "./Libraries/include/GLFW" "./Libraries/include/glad" "./Libraries/include/KHR")

# Link the GLFW library to your executable target
target_link_libraries(Sombrosa PRIVATE MyGLFWLibrary PRIVATE MyOpenGLLibrary)
