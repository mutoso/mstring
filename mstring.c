/*
 * © 2014 Alastair Stuart Feille
 * License: CC0
 */

#include "mstring.h"

mstring mstr(const char* c_str)
{
    if (!c_str)
    {
        return NULL;
    }

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
    if (!s1 || !s2)
    {
        return NULL;
    }

    if (!s1->str || !s2->str)
    {
        return NULL;
    }

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

mstring mappend(mstring s1, const char* s2)
{
    if (!s1 || !s2)
    {
        return NULL;
    }

    if (!s1->str)
    {
        return NULL;
    }

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

mstring msubstr(mstring m_str, size_t start, size_t len)
{
    /* validate input */
    if (!m_str)
    {
        return NULL;
    }
    if (!m_str->str)
    {
        return NULL;
    }

    /* if start is outside of the string, return an empty string */
    if (start >= m_str->len)
    {
        return mstr("");
    }

    /* if len goes past the end of the string, stop at the end */
    if (start + len >= m_str->len)
    {
        len = m_str->len - start;
    }

    mstring substring = malloc(sizeof(struct mstring));
    if (substring)
    {
        substring->len = len;
        substring->str = calloc(1, substring->len + 1);

        if (substring->str)
        {
            for (size_t i = 0; i < len; i++)
            {
                substring->str[i] = m_str->str[start+i];
            }

            substring->str[substring->len] = '\0';
            return substring;
        }
        else
        {
            free(substring);
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

}

bool mequals(mstring s1, mstring s2)
{
    if (!s1 || !s2)
    {
        return false;
    }

    if (!s1->str || !s2->str)
    {
        return false;
    }

    return strcmp(s1->str, s2->str) == 0;
}

mstring mcopy(mstring m_str)
{
    if (!m_str)
    {
        return NULL;
    }
    if (!m_str->str)
    {
        return NULL;
    }

    return mstr(m_str->str);
}
