/*
 * © 2014 Alastair Stuart Feille
 * License: CC0
 */

#include <string.h>
#include <stdlib.h>

struct mstring
{
    char* str;
    size_t len;
};

typedef struct mstring* mstring;

mstring mstr(const char* c_str);

void mdestroy(mstring m_str);

mstring mconcat(mstring s1, mstring s2);

mstring mappend(mstring s1, const char* s2);

mstring msubstr(mstring m_str, size_t start, size_t len);
