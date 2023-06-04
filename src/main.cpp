#include <future>
#include <iostream>

#include "window\window.hpp"

using namespace std;

constexpr auto nl = '\n';

int main() {
    yhy::window win{ "first vulkan window", 800, 600 };

    yhy::window temp{ std::move(win) };

    while (win.running()) {}

    wcout << L"invalid: win" << nl;
    while (temp.running()) {}

    return 0;
}