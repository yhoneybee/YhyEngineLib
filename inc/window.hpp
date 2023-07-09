#pragma once

#include <string>

#include "inc.hpp"

class GLFWwindow;

BEGIN_NAMESPACE(yhy)

class Window {
   public:
    Window(std::string_view name, uint32_t width, uint32_t heigth);
    virtual ~Window();

    DENIED_COPY(Window)
    ALLOWED_MOVE(Window)

    bool Running();
    bool Valid();

   private:
    GLFWwindow* window_;
    std::string name_;
    const uint32_t width_;
    const uint32_t height_;
};

END_NAMESPACE