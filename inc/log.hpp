#pragma once
#define TRACE(functionName)

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
    enum ErrorLevel { Low, Middle, High };
    static void SetLogFolder(std::wstring_view path);
    /// @brief 로그 기록: [hh:mm:ss:mm] \a contents
    /// @param contents
    static void TimeLog(std::wstring_view contents);
    /// @brief 로그 기록: \a errorLevel Error! \a contents
    /// @param contents
    /// @param errorLevel
    static void ErrorLog(std::wstring_view contents, ErrorLevel errorLevel = ErrorLevel::Low);

   private:
    /// @brief 깊이 만큼 tab하는 함수
    static void TabToDepths();
    static void BeginTraceLog(std::wstring_view functionName);
    static void EndTraceLog(std::wstring_view functionName);
    static void AppendLog(std::wstring_view contents, bool newLine = false);

    static std::filesystem::path logFolder;
    static uint32_t depth_;

    friend Trace;
};

END_NAMESPACE