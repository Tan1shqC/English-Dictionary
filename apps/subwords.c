#include <stdio.h>
#include <stdlib.h>
#include "../utils/wordutils.h"

int main()
{
    char _str[20];
    scanf("%s", _str);
    char* str = strdup(_str);
    dict* D;
    D = Load_Dflt_Dict();

    int i, len = strlen(str);
    for(i = 0; i < len; ++i)
    {
        char* temp_str;
        temp_str = (char *)malloc((len - 1) * sizeof(char));
        int j, k = 0;
        for(j = 0; j < len; ++j)
        {
            if(j == i){

            }
            else{
                temp_str[k] = str[j];
                k++;
            }
            if(j == len - 1){
                temp_str[k] = '\0';
            }
        }
        char** list = anagrams(D, temp_str);
        int list_len = sizeof(list) / sizeof(char *);
        for(j = 0; j < list_len - 1; ++j)
        {
            printf("%s\n", list[j]);
        }
        free(list);
        free(temp_str);
    }
}