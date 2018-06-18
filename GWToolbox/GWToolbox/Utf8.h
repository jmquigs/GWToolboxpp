#ifndef UTF8_H_INC
#define UTF8_H_INC

#include <stddef.h>

struct string {
	char  *bytes;
	size_t count;
};

static inline void free(string& s) {
	if (s.bytes) delete s.bytes;
}

// encode a unicode16 to utf8 using a allocated buffer (malloc).
string Unicode16ToUtf8(const wchar_t *str);
string Unicode16ToUtf8(const wchar_t *start, const wchar_t *end);

// encode a unicode16 to utf8 using the provided buffer.
string Unicode16ToUtf8(char *buffer, size_t n_buffer, const wchar_t *start, const wchar_t *end);

size_t Utf8ToUnicode(const char *str, wchar_t *buffer, size_t count);

// Custom normalization that returns a allocated buffer (malloc) and that do:
//  - change to lower case
//  - remove accent
//  - remove non-printable character (e.g. zero-width spaces)
string Utf8Normalize(const char *str);

#endif // UTF8_H_INC