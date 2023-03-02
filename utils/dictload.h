#include <stdio.h>
#include <stdlib.h>
#include "dicttype.h"
#define DFLT_DICT "../dict/words.txt"

extern dict* Load_Dflt_Dict();
extern dict* Load_Dict(FILE* fname);