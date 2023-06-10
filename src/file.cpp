#include "file.hpp"

#include <format>

#include "log.hpp"

BEGIN_NAMESPACE(yhy)

File::Bytes File::Read(const std::filesystem::path& filePath) {
    std::ifstream reader{ filePath, std::ios::ate | std::ios::binary };
    if (!reader) { Log::InsertLog(L"Failed to open file"); }

    auto file_size = static_cast<size_t>(reader.tellg());
    Bytes buffer;
    buffer.resize(file_size);

    reader.seekg(0);
    reader.read(buffer.data(), file_size);
    reader.close();

    return buffer;
}

void File::Write(const std::filesystem::path& filePath, std::wstring_view contents) {
    if (!std::filesystem::exists(filePath)) { Log::InsertLog(L"File does not exist in the path"); }
    std::wofstream writer{ filePath, std::ios::app };
    if (!writer) { Log::InsertLog(L"Failed to open file"); }
    writer << contents;
}

END_NAMESPACE