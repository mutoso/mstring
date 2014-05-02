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

mstring mconcat(mstring s1, mstring s2)
{
    mstring out_str = malloc(sizeof(struct mstring));
    if (out_str)
    {
        out_str->len = s1->len + s2->len;
        out_str->str = calloc(1, out_str->len + 1);

        if (out_str->str)
        {
            strncat(out_str->str, s1->str, s1->len);
            strncat(out_str->str, s2->str, s2->len);

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

mstring mappend(mstring s1, char* s2)
{
    mstring out_str = malloc(sizeof(struct mstring));
    if (out_str)
    {
        out_str->len = s1->len + strlen(s2);
        out_str->str = calloc(1, out_str->len + 1);

        if (out_str->str)
        {
            strncat(out_str->str, s1->str, s1->len);
            strncat(out_str->str, s2, strlen(s2));

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
