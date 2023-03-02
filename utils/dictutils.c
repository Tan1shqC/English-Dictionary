#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dictutils.h>


int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int ceilIndex(char S[], char first, int l, int r)
{
    int res = l, i;
    for (i = l + 1; i <= r; ++i)
    {
        if (first < S[i] && S[i] < S[res])
            res = i;
    }
    return res;
}

char *add_before(dict *D, char S[])
{
    char *res_str = (char *)malloc(sizeof(char));
    res_str[0] = '\0';
    char *test_str;
    test_str = (char *)malloc(((strlen(S) + 1) * sizeof(char)) + sizeof(char));
    int i = 26;
    while (i)
    {
        char temp_str[] = {('a' + 26 - i), '\0'};
        strcpy(test_str, temp_str);
        test_str = strcat(test_str, S);
        if (Trie_Search(D, test_str) == 1)
        {
            res_str = realloc(res_str, sizeof(res_str) + sizeof(char));
            res_str[strlen(res_str) + 1] = '\0';
            res_str[strlen(res_str)] = ('a' + 26 - i);
        }
        i--;
    }
    return res_str;
}
char *add_after(dict *D, char S[])
{
    char *res_str = (char *)malloc(sizeof(char));
    res_str[0] = '\0';
    char *test_str;
    test_str = (char *)malloc(((strlen(S) + 1) * sizeof(char)) + sizeof(char));
    int i = 26;
    while (i)
    {
        char temp_str[] = {('a' + 26 - i), '\0'};
        strcpy(test_str, S);
        test_str = strcat(test_str, temp_str);
        if (Trie_Search(D, test_str) == 1)
        {
            res_str = realloc(res_str, sizeof(res_str) + sizeof(char));
            res_str[strlen(res_str) + 1] = '\0';
            res_str[strlen(res_str)] = ('a' + 26 - i);
        }
        i--;
    }
    return res_str;
}
char **anagrams(dict *D, char S[])
{
    char **distinct_anagrams = NULL;
    int size = strlen(S);
    qsort(S, size, sizeof(char), compare);
    int is_not_finished = 1;
    int str_index = 0;

    distinct_anagrams = (char **)malloc(sizeof(char *));
    char tmp_1[] = {'\0'};
    distinct_anagrams[str_index] = strdup(tmp_1);

    while (is_not_finished)
    {
        int i, _ceilIndex;

        if (Trie_Search(D, S) == 1)
        {
            str_index++;
            distinct_anagrams = realloc(distinct_anagrams, (1 + str_index) * sizeof(char *));
            const char *tmp = S;
            distinct_anagrams[str_index] = strdup(tmp);
            printf("%s\n", distinct_anagrams[str_index]);
        }

        for (i = size - 2; i >= 0; --i)
        {
            if (S[i] < S[i + 1])
                break;
        }

        if (i == -1)
            is_not_finished = 0;
        else
        {
            _ceilIndex = ceilIndex(S, S[i], i + 1, size - 1);
            swap(&S[i], &S[_ceilIndex]);
            qsort(S + i + 1, size - i - 1, sizeof(S[i]), compare);
        }
    }
    return distinct_anagrams;
}