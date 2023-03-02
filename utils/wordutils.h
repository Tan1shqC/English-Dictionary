#include "dictutils.h"

extern dict* Load_Dflt_Dict();
extern dict* Load_Dict(FILE* fname);
extern char* add_before(dict* D, char str[]);
extern char* add_after(dict* D, char str[]);
extern char** anagrams(dict* D, char S[]);