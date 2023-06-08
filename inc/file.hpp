#pragma once

#include <filesystem>
#include <fstream>
#include <vector>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class File {
    using Bytes = std::vector<char>;

   public:
    static Bytes Read(const std::filesystem::path& filePath);
    static void Write(const std::filesystem::path& filePath, std::string_view contents);

   private:
};

END_NAMESPACE