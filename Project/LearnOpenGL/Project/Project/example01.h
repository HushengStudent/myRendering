#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#ifndef EXAMPLE_01
#define  EXAMPLE_01

int example01_main();

void example01_framebuffer_size_callback(GLFWwindow* window, int width, int height);

void example01_processInput(GLFWwindow *window);

#endif