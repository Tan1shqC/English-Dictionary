#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictload.h"

extern char* add_before(dict* D, char str[]);
extern char* add_after(dict* D, char str[]);
extern char** anagrams(dict* D, char S[]);