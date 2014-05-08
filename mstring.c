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

bool mconcat(mstring s1, mstring s2)
{
    mstring out_str = mconcat_new(s1, s2);
    if (out_str)
    {
        free(s1->str);
        s1->str = out_str->str;
        s1->len = out_str->len;
        free(out_str);
        return true;
    }
    else
    {
        return false;
    }
}

mstring mconcat_new(mstring s1, mstring s2)
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

bool mappend(mstring s1, const char* s2)
{
    mstring out_str = mappend_new(s1, s2);
    if (out_str)
    {
        free(s1->str);
        s1->str = out_str->str;
        s1->len = out_str->len;
        free(out_str);
        return true;
    }
    else
    {
        return false;
    }
}

mstring mappend_new(mstring s1, const char* s2)
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

bool mprepend(mstring m_str, const char* prefix)
{
    mstring out_str = mprepend_new(m_str, prefix);
    if (out_str)
    {
        free(m_str->str);
        m_str->str = out_str->str;
        m_str->len = out_str->len;
        free(out_str);
        return true;
    }
    else
    {
        return false;
    }
}

mstring mprepend_new(mstring m_str, const char* prefix)
{
    if (!m_str || !prefix)
    {
        return NULL;
    }

    if (!m_str->str)
    {
        return NULL;
    }

    mstring out_str = malloc(sizeof(struct mstring));
    if (out_str)
    {
        out_str->len = strlen(prefix) + m_str->len;
        out_str->str = calloc(1, out_str->len + 1);

        if (out_str->str)
        {
            strncat(out_str->str, prefix, strlen(prefix));
            strncat(out_str->str, m_str->str, m_str->len);

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

int mfind(mstring haystack, const char* needle)
{
    char* pch = strstr(haystack->str, needle);
    if (pch)
    {
        return pch - haystack->str;
    }
    else
    {
        return -1;
    }
}

bool mreplace(mstring haystack, const char* needle, const char* replacement)
{
    mstring out_str = mreplace_new(haystack, needle, replacement);
    if (out_str)
    {
        free(haystack->str);
        haystack->str = out_str->str;
        haystack->len = out_str->len;
        free(out_str);
        return true;
    }
    else
    {
        return false;
    }
}

mstring mreplace_new(mstring haystack, const char* needle, const char* replacement)
{
    /*
     * indexofneedle marks the beginning of the needle
     * start marks the start of the section after the (current) needle
     */

    int start = 0;

    /* get pointer to first instance of needle in haystack */
    char* pch = strstr(haystack->str, needle);

    if (!pch)
    {
        return NULL;
    }

    mstring out_str = mstr("");

    /* subtract the memory addresses to get an index */
    size_t indexofneedle = pch - haystack->str;
    /* go from the start of the part after the needle
     * or if it's the first result start at index 0
     * and copy up to the next needle */
    char between[indexofneedle - start + 1];
    strncpy(between, haystack->str+start, indexofneedle - start);
    between[indexofneedle - start] = '\0';
    /* append the non-needle part of the string to the output */
    mappend(out_str, between);
    /* and put the replacement instead of the needle */
    mappend(out_str, replacement);
    /* get the index of the next part after the needle */
    start = indexofneedle + strlen(needle);
    /* append everything that's after the needle */
    mappend(out_str, haystack->str+start);

    return out_str;
}

bool mreplace_all(mstring haystack, const char* needle, const char* replacement)
{
    mstring out_str = mreplace_all_new(haystack, needle, replacement);
    if (out_str)
    {
        free(haystack->str);
        haystack->str = out_str->str;
        haystack->len = out_str->len;
        free(out_str);
        return true;
    }
    else
    {
        return false;
    }
}

mstring mreplace_all_new(mstring haystack, const char* needle, const char* replacement)
{
    /*
     * indexofneedle marks the beginning of the needle
     * start marks the start of the section after the (current) needle
     */

    int start = 0;
    char* between;

    /* get pointer to first instance of needle in haystack */
    char* pch = strstr(haystack->str, needle);

    if (!pch)
    {
        return NULL;
    }

    mstring out_str = mstr("");
    while (pch)
    {
        /* subtract the memory addresses to get an index */
        size_t indexofneedle = pch - haystack->str;
        /* go from the start of the part after the needle
         * or if it's the first result start at index 0
         * and copy up to the next needle */
        between = malloc(indexofneedle - start + 1);
        strncpy(between, haystack->str+start, indexofneedle - start);
        between[indexofneedle - start] = '\0';
        /* append the non-needle part of the string to the output */
        mappend(out_str, between);
        /* and put the replacement instead of the needle */
        mappend(out_str, replacement);
        /* find next needle */
        pch = strstr(pch+strlen(needle), needle);
        /* get the index of the next part after the needle */
        start = indexofneedle + strlen(needle);
        free(between);
    }
    /* append everything that's after the last needle */
    mappend(out_str, haystack->str+start);

    return out_str;
}
