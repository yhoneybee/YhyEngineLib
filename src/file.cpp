#include "file.hpp"

#include <format>

#include "log.hpp"

BEGIN_NAMESPACE(yhy)

File::Bytes File::Read(const std::filesystem::path& filePath) {
    std::ifstream reader{ filePath, std::ios::ate | std::ios::binary };
    if (!reader) { Log::ErrorLog(L"open file failed!"); }

    auto file_size = static_cast<size_t>(reader.tellg());
    Bytes buffer;
    buffer.resize(file_size);

    reader.seekg(0);
    reader.read(buffer.data(), file_size);
    reader.close();

    return buffer;
}

void File::Write(const std::filesystem::path& filePath, std::string_view contents) {
    if (!std::filesystem::exists(filePath)) { Log::ErrorLog(L"not exists path!"); }
    std::ofstream writer{ filePath, std::ios::app };
    if (!writer) { Log::ErrorLog(L"open file failed!"); }
    writer << contents;
}

END_NAMESPACE