#pragma once

#include <filesystem>
#include <fstream>
#include <vector>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class File {
    using Bytes = std::vector<char>;

   public:
    static Bytes Read(std::string_view filepath);

   private:
};

END_NAMESPACE