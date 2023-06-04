#define BEGIN_NAMESPACE(name) namespace name {
#define END_NAMESPACE }

#define DENIED_COPY(name)       \
    name(const name&) = delete; \
    name& operator=(const name&) = delete;

#define ALLOWED_COPY(name) \
    name(const name&);     \
    name& operator=(const name&);

#define DENIED_MOVE(name)  \
    name(name&&) = delete; \
    name& operator=(name&&) = delete;

#define ALLOWED_MOVE(name) \
    name(name&&);          \
    name& operator=(name&&);

#define YHY_EXPORT __attribute__((__visibility__("default")))

#include <stdint.h>
