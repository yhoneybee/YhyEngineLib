#pragma once

#include <string>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class Encoder {
   public:
    static std::wstring AsciiToUnicode(std::string_view str);
    static std::string UnicodeToAscii(std::wstring_view str);
};

END_NAMESPACE