#define GLFW_INCLUDE_VULKAN

#include "window/window.hpp"

#include <GLFW/glfw3.h>

BEGIN_NAMESPACE(yhy)

window::window(std::string_view name, uint32_t width, uint32_t heigth) : name_{ name }, width_{ width }, height_{ heigth } {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window_ = glfwCreateWindow(width_, height_, name_.c_str(), nullptr, nullptr);
}
window::window(window&& rhs) : name_{ rhs.name_ }, width_{ rhs.width_ }, height_{ rhs.height_ } {
    window_ = rhs.window_;
    rhs.window_ = nullptr;
}
window::~window() {
    if (!valid()) return;
    glfwDestroyWindow(window_);
    glfwTerminate();
}
window& window::operator=(window&& rhs) {
    window_ = rhs.window_;
    rhs.window_ = nullptr;
    return *this;
}
bool window::running() {
    glfwPollEvents();
    return valid() && !glfwWindowShouldClose(window_);
}
bool window::valid() {
    return window_;
}

END_NAMESPACE