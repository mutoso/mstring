/*
 * © 2014 Alastair Stuart Feille
 * License: CC0
 */

#include "mstring.h"

mstring mstr(const char* c_str)
{
    mstring out_str = malloc(sizeof(struct mstring));
    if (out_str)
    {
        out_str->len = strlen(c_str);

        out_str->str = calloc(1, out_str->len + 1);
        if (out_str->str)
        {
            strncpy(out_str->str, c_str, out_str->len);
            out_str->str[out_str->len] = '\0';

            return out_str;
        }
        else
        {
            free(out_str);
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

}

void mdestroy(mstring m_str)
{
    if (m_str)
    {
        free(m_str->str);
        m_str->len = 0;
        free(m_str);
    }
}
