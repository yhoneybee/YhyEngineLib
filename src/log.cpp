#include "log.hpp"

#include <filesystem>
#include <format>

#include "file.hpp"

BEGIN_NAMESPACE(yhy)

uint32_t Log::depth_ = 0;
std::filesystem::path Log::logFolder;

Log::Trace::Trace(std::wstring_view functionName) : functionName_{ functionName } {
    BeginTraceLog_(functionName_);
    Log::depth_++;
}

Log::Trace::~Trace() {
    Log::depth_--;
    EndTraceLog_(functionName_);
}

Log::Trace Log::CreateTrace(std::wstring_view functionName) {
    return Trace{ functionName };
}

void Log::SetLogFolder(std::wstring_view path) {
    if (!std::filesystem::exists(path)) { std::filesystem::create_directories(path); }
    logFolder = path;
}

void Log::InsertLog(std::wstring_view contents, LogType logType) {
    std::wstring logTypeString;
    switch (logType) {
    case LogType::Info: logTypeString = L"INFO"; break;
    case LogType::Warning: logTypeString = L"WARNING"; break;
    case LogType::Error: logTypeString = L"ERROR"; break;
    }
    File::Write(std::format(LR"({0}\{1}.yhylog)", logFolder.c_str(), L"TempDate"),
                std::format(L"[{0} {1}] {2}{3}\n", L"TempTime", logTypeString, AddToDepths_(), contents));
}

std::wstring Log::AddToDepths_() {
    std::wstring adds;
    for (size_t i = 0; i < depth_; i++) { adds += L"|  "; }
    return adds;
}

void Log::BeginTraceLog_(std::wstring_view functionName) {
    InsertLog(std::format(L"{0}", functionName));
}

void Log::EndTraceLog_(std::wstring_view functionName) {
    InsertLog(std::format(L"{0}", functionName));
}

END_NAMESPACE