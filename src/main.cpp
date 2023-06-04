#include <future>
#include <iostream>

#include "file.hpp"
#include "pipeline.hpp"
#include "window.hpp"

using namespace std;

constexpr auto nl = '\n';

int main() {
    yhy::Window window{ "first vulkan app", 800, 600 };

    while (window.Running()) {}

    return 0;
}