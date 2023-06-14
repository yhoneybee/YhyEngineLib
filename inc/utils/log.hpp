#pragma once
#define TRACE(functionName) auto TRACE_FUNCTION_LOG = yhy::Log::CreateTrace(L## #functionName);

#include <filesystem>
#include <string>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class Log {
    class Trace {
       public:
        Trace(std::wstring_view functionName);
        ~Trace();

       private:
        std::wstring_view functionName_;
    };

   public:
    enum LogType { Info, Warning, Error };
    static Trace CreateTrace(std::wstring_view functionName);
    static void SetLogFolder(std::wstring_view path);
    static void InsertLog(std::wstring_view contents, LogType logType = LogType::Info);

   private:
    static std::wstring AddToDepths_();
    static void BeginTraceLog_(std::wstring_view functionName);
    static void EndTraceLog_(std::wstring_view functionName);

    static std::filesystem::path logFolder;
    static uint32_t depth_;

    friend Trace;
};

END_NAMESPACE