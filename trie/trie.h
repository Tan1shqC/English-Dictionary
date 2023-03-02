#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _TrieNode
{
    struct _TrieNode *child;
    struct _TrieNode *sibling;
    char alphabet;
    int endOfWord;
};

typedef struct _TrieNode Trie;
typedef struct _TrieNode TrieNode;

extern Trie* Trie_Init();
extern int Trie_Search(Trie* T, char S[]);
extern void Trie_Insert(Trie* T, char S[]);
extern void List_All(Trie* T);