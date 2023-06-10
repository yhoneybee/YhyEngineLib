#include <future>
#include <iostream>

#include "file.hpp"
#include "log.hpp"
#include "pipeline.hpp"
#include "window.hpp"

using namespace std;

constexpr auto nl = '\n';

int main() {
    yhy::Log::SetLogFolder(LR"(C:\YhyEngineLogs)");

    TRACE(main);

    {
        TRACE(Level1);
        {
            TRACE(Level2);
            { TRACE(Level3); }
        }
    }

    // yhy::Window window{ L"first vulkan app", 800, 600 };

    // while (window.Running()) {}

    return 0;
}