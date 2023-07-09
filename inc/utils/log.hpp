#pragma once
#define TRACE(functionName) auto TRACE_FUNCTION_LOG = yhy::Log::CreateTrace(#functionName);

#include <filesystem>
#include <string>

#include "inc.hpp"

BEGIN_NAMESPACE(yhy)

class Log {
    class Trace {
       public:
        Trace(std::string_view functionName);
        ~Trace();

       private:
        std::string_view functionName_;
    };

   public:
    enum LogType { Info, Warning, Error };
    static Trace CreateTrace(std::string_view functionName);
    static void SetLogFolder(std::string_view path);
    static void InsertLog(std::string_view contents, LogType logType = LogType::Info);

   private:
    static std::string AddToDepths_();
    static void BeginTraceLog_(std::string_view functionName);
    static void EndTraceLog_(std::string_view functionName);

    static std::filesystem::path logFolder;
    static uint32_t depth_;

    friend Trace;
};

END_NAMESPACE