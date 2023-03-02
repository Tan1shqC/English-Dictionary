#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

char *copyString(char s[])
{

    char *s2, *p1, *p2;

    s2 = (char *)malloc(50 * sizeof(char));
    p1 = s;
    p2 = s2;

    while (*p1 != '\0')
    {
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0';

    return s2;
}

TrieNode *new_node(TrieNode *node)
{
    node = (TrieNode *)malloc(sizeof(TrieNode));
    node->endOfWord = 0;

    node->child = NULL;
    node->sibling = NULL;
    return node;
}

TrieNode *add_returnExisting_Sibling(TrieNode *curr_level, TrieNode *prev_level, char c)
{
    if (curr_level == NULL)
    {
        curr_level = new_node(curr_level);
        prev_level->child = curr_level;
        curr_level->alphabet = c;
        return curr_level;
    }
    if (curr_level->alphabet > c)
    {
        TrieNode *inserted_node;
        inserted_node = new_node(inserted_node);
        inserted_node->alphabet = c;
        prev_level->child = inserted_node;
        inserted_node->sibling = curr_level;
        return inserted_node;
    }
    else
    {
        while (curr_level->sibling != NULL)
        {
            if (curr_level->alphabet == c)
            {
                return curr_level;
            }
            else if (curr_level->alphabet < c && curr_level->sibling->alphabet > c)
            {
                TrieNode *inserted_node;
                inserted_node = new_node(inserted_node);
                inserted_node->alphabet = c;
                inserted_node->sibling = curr_level->sibling;
                curr_level->sibling = inserted_node;
                return inserted_node;
            }
            curr_level = curr_level->sibling;
        }
        if (curr_level->alphabet == c)
        {
            return curr_level;
        }
        else
        {
            TrieNode *inserted_node;
            inserted_node = new_node(inserted_node);
            inserted_node->alphabet = c;
            curr_level->sibling = inserted_node;
            return inserted_node;
        }
    }
}

void Recursive_List(TrieNode *node, char *due_str)
{
    if (node->endOfWord == 1)
        printf("%s\n", due_str);
    if (node->child == NULL)
        return;
    TrieNode *iter = node->child;
    while (iter)
    {
        char *new_due_str = copyString(due_str);
        new_due_str[strlen(new_due_str)] = '\0';
        new_due_str[strlen(new_due_str) + 1] = '\0';
        new_due_str[strlen(new_due_str)] = iter->alphabet;
        
        Recursive_List(iter, new_due_str);
        iter = iter->sibling;
        free(new_due_str);
    }
}

Trie *Trie_Init()
{
    Trie *T = (Trie *)malloc(sizeof(Trie));
    T->child = NULL;
    T->sibling = NULL;
    T->endOfWord = 0;
    T->alphabet = '\0';
    return T;
}

int Trie_Search(Trie *T, char S[])
{
    int len = strlen(S), i;
    TrieNode *iter = T->child;
    for (i = 0; i < len; i++)
    {
        if (iter == NULL)
            return 0;
        while (iter)
        {
            if (iter->alphabet == S[i])
                break;
            if(iter->sibling == NULL){
                if (iter->alphabet != S[i])
                    return 0;
            }
            iter = iter->sibling;
        }
        if (i == len - 1 && iter->endOfWord == 0)
            return 0;
        iter = iter->child;
    }
    return 1;
}

void Trie_Insert(Trie *T, char S[])
{
    TrieNode *prev_level = T;
    TrieNode *curr_level = T->child;

    int len = strlen(S), i;
    for (i = 0; i < len; i++)
    {
        curr_level = add_returnExisting_Sibling(curr_level, prev_level, S[i]);
        prev_level = curr_level;
        curr_level = curr_level->child;
    }
    prev_level->endOfWord = 1;
}

void List_All(Trie *T)
{
    TrieNode *node = T;
    char s[] = {'\0'};
    Recursive_List(node, s);
}