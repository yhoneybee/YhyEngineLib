#include "log.hpp"

#include <filesystem>

#include "file.hpp"

BEGIN_NAMESPACE(yhy)

uint32_t Log::depth_ = 0;
std::filesystem::path Log::logFolder;

Log::Trace::Trace(std::wstring_view functionName) : functionName_{ functionName } {
    Log::depth_++;
    BeginTraceLog(functionName_);
}

Log::Trace::~Trace() {
    EndTraceLog(functionName_);
    Log::depth_--;
}

void Log::SetLogFolder(std::wstring_view path) {
    if (!std::filesystem::exists(path)) { std::filesystem::create_directories(path); }
    logFolder = path;
}

void Log::TimeLog(std::wstring_view contents) {
    TabToDepths();
}

void Log::ErrorLog(std::wstring_view contents, ErrorLevel errorLevel) {
    TabToDepths();
}

void Log::TabToDepths() {}

void Log::BeginTraceLog(std::wstring_view functionName) {
    TabToDepths();
}

void Log::EndTraceLog(std::wstring_view functionName) {
    TabToDepths();
}

void Log::AppendLog(std::wstring_view contents, bool newLine) {}

END_NAMESPACE