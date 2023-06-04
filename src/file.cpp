#include "file.hpp"

#include <format>

BEGIN_NAMESPACE(yhy)

File::Bytes File::Read(std::string_view filepath) {
    std::ifstream reader{ filepath.data(), std::ios::ate | std::ios::binary };
    if (!reader.is_open()) throw std::runtime_error(std::format("failed to open file > {0}", filepath));

    auto file_size = static_cast<size_t>(reader.tellg());
    Bytes buffer;
    buffer.resize(file_size);

    reader.seekg(0);
    reader.read(buffer.data(), file_size);
    reader.close();

    return buffer;
}

END_NAMESPACE