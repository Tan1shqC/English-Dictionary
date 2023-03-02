#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dictload.h>

dict* Load_Dflt_Dict()
{
    dict* D;
    D = Trie_Init();
    FILE *ptr = fopen(DFLT_DICT, "r");
    char *str = NULL;
    int len = 0;
    char c;
    c = getc(ptr);
    while (c != EOF)
    {
        if (c != '\n' && c != '\r')
        {
            len++;
            if (str == NULL)
            {
                str = (char *)malloc(sizeof(char));
                str[len - 1] = c;
            }
            else
            {
                str = (char *) realloc(str, len * sizeof(char));
                str[len - 1] = c;
            }
        }
        else
        {
            if (str != NULL)
            {
                len++;
                str = (char *) realloc(str, len * sizeof(char));
                str[len - 1] = '\0';
                Trie_Insert(D, str);
                free(str);
            }
            str = NULL;
            len = 0;
        }
        c = getc(ptr);
    }
    if (str != NULL)
    {
        len++;
        str = (char *) realloc(str, len * sizeof(char));
        str[len - 1] = '\0';
        Trie_Insert(D, str);
        free(str);
        str = NULL;
    }
    fclose(ptr);
    return D;
}

dict* Load_Dict(FILE* fname)
{
    dict* D;
    D = Trie_Init();
    char *str = NULL;
    int len = 0;
    char c;
    c = getc(fname);
    while (c != EOF)
    {
        if (c != '\n' && c != '\r')
        {
            len++;
            if (str == NULL)
            {
                str = (char *)malloc(sizeof(char));
                str[len - 1] = c;
            }
            else
            {
                str = (char *) realloc(str, len * sizeof(char));
                str[len - 1] = c;
            }
        }
        else
        {
            if (str != NULL)
            {
                len++;
                str = (char *) realloc(str, len * sizeof(char));
                str[len - 1] = '\0';
                Trie_Insert(D, str);
                free(str);
            }
            str = NULL;
            len = 0;
        }
        c = getc(fname);
    }
    if (str != NULL)
    {
        len++;
        str = (char *) realloc(str, len * sizeof(char));
        str[len - 1] = '\0';
        Trie_Insert(D, str);
        free(str);
        str = NULL;
    }
    return D;
}