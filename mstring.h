/*
 * © 2014 Alastair Stuart Feille
 * License: CC0
 */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct mstring
{
    char* str;
    size_t len;
};

typedef struct mstring* mstring;

mstring mstr(const char* c_str);

void mdestroy(mstring m_str);

bool mconcat(mstring s1, mstring s2);

mstring mconcat_new(mstring s1, mstring s2);

bool mappend(mstring s1, const char* s2);

mstring mappend_new(mstring s1, const char* s2);

bool mprepend(mstring m_str, const char* prefix);

mstring mprepend_new(mstring m_str, const char* prefix);

mstring msubstr(mstring m_str, size_t start, size_t len);

bool mequals(mstring s1, mstring s2);

mstring mcopy(mstring m_str);

int mfind(mstring haystack, const char* needle);

bool mreplace(mstring haystack, const char* needle, const char* replacement);

mstring mreplace_new(mstring haystack, const char* needle, const char* replacement);

bool mreplace_all(mstring haystack, const char* needle, const char* replacement);

mstring mreplace_all_new(mstring haystack, const char* needle, const char* replacement);
