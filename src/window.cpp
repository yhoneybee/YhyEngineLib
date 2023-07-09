#define GLFW_INCLUDE_VULKAN

#include "window.hpp"

#include <GLFW/glfw3.h>

BEGIN_NAMESPACE(yhy)

Window::Window(std::string_view name, uint32_t width, uint32_t heigth) : name_{ name }, width_{ width }, height_{ heigth } {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window_ = glfwCreateWindow(width_, height_, "Test Window", nullptr, nullptr);
}
Window::Window(Window&& rhs) : name_{ rhs.name_ }, width_{ rhs.width_ }, height_{ rhs.height_ } {
    window_ = rhs.window_;
    rhs.window_ = nullptr;
}
Window::~Window() {
    if (!Valid()) return;
    glfwDestroyWindow(window_);
    glfwTerminate();
}
Window& Window::operator=(Window&& rhs) {
    window_ = rhs.window_;
    rhs.window_ = nullptr;
    return *this;
}
bool Window::Running() {
    glfwPollEvents();
    return Valid() && !glfwWindowShouldClose(window_);
}
bool Window::Valid() {
    return window_;
}

END_NAMESPACE