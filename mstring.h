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
