#pragma once

#include <string>

#include "inc.hpp"

class GLFWwindow;

BEGIN_NAMESPACE(yhy)

class window {
   public:
    window(std::string_view name, uint32_t width, uint32_t heigth);
    virtual ~window();

    DENIED_COPY(window)
    ALLOWED_MOVE(window)

    /// @brief
    /// @return \a true: window가 유효하며 동작중 \n \a false: window가 유효하지 않거나 동작중이 아님
    bool running();
    bool valid();

   private:
    GLFWwindow* window_;
    std::string name_;
    const uint32_t width_;
    const uint32_t height_;
};

END_NAMESPACE