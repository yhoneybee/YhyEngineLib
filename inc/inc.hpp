#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE }

#define DENIED_COPY(className)            \
    className(const className&) = delete; \
    className& operator=(const className&) = delete;

#define ALLOWED_COPY(className)  \
    className(const className&); \
    className& operator=(const className&);

#define DENIED_MOVE(ClassName)       \
    ClassName(ClassName&&) = delete; \
    ClassName& operator=(ClassName&&) = delete;

#define ALLOWED_MOVE(className) \
    className(className&&);     \
    className& operator=(className&&);

#define YHY_EXPORT __attribute__((__visibility__("default")))

#include <stdint.h>

#ifdef _DEBUG
#    define DEBUG_MODE true
#else
#    define DEBUG_MODE false
#endif