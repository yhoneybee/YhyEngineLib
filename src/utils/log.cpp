#include "log.hpp"

#include <filesystem>
#include <format>

#include "file.hpp"

BEGIN_NAMESPACE(yhy)

uint32_t Log::depth_ = 0;
std::filesystem::path Log::logFolder;

Log::Trace::Trace(std::string_view functionName) : functionName_{ functionName } {
    BeginTraceLog_(functionName_);
    Log::depth_++;
}

Log::Trace::~Trace() {
    Log::depth_--;
    EndTraceLog_(functionName_);
}

Log::Trace Log::CreateTrace(std::string_view functionName) {
    return Trace{ functionName };
}

void Log::SetLogFolder(std::string_view path) {
    if (!std::filesystem::exists(path)) { std::filesystem::create_directories(path); }
    logFolder = path;
}

void Log::InsertLog(std::string_view contents, LogType logType) {
    std::string logTypeString;
    switch (logType) {
    case LogType::Info: logTypeString = "INFO"; break;
    case LogType::Warning: logTypeString = "WARNING"; break;
    case LogType::Error: logTypeString = "ERROR"; break;
    }

    File::Write(std::format(R"({0}\{1}.yhylog)", logFolder.string().c_str(), "TempDate"),
                std::format("[{0} {1}] {2}{3}\n", "TempTime", logTypeString, AddToDepths_(), contents));
}

std::string Log::AddToDepths_() {
    std::string adds;
    for (size_t i = 0; i < depth_; i++) { adds += "|  "; }
    return adds;
}

void Log::BeginTraceLog_(std::string_view functionName) {
    InsertLog(std::format("{0}", functionName));
}

void Log::EndTraceLog_(std::string_view functionName) {
    InsertLog(std::format("{0}", functionName));
}

END_NAMESPACE