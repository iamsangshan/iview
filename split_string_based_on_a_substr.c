/*****************************************

Given a Main big string, split this string
based on a small substr given as input. 
Print all the parts.

Sangeetha Shanmugam
August 2020

******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* not tested */
void mysubstrfunc (char *str, char *delim) {

    int i = 0, j=0, row=0, col=0;
    char words[5][30];
    char *main_str = str;

    int ndelim = strlen(delim);
    int nmain_str = strlen(main_str);
    int delim_found = 0;

    
    while (main_str) {
        /* Traverse the string and store it in an array of words, till we find the delim */
        j = 0;
        col = 0;

        if (delim_found) {
            row++;
            delim_found = 0;
        }
        
        if (row >= 5)
            return;
        

        while (i < nmain_str -1 &&
         j < ndelim - 1 && col < 30 && main_str[i++] != delim[j]) {
            words[row][col++] = main_str[i++];
        }

        /* If we find the delimiter, store it in array of words */
        while (main_str[i++] == delim[j++] && i < ndelim-1 && j < ndelim - 1);


        /* found the delim */
        if (j == ndelim-1) {
            delim_found = 1;
            strncpy(words[row+1], delim, 30);
        } else {
            continue;
        }
    /* Continue the traversal till the end of the string */
    }

    printf("Words are .../n");
    for (i = 0; i < row-1; i++) {
        printf("%s ,");
    }
    printf("\n");
}

int main ()
{
    char *str = "This task is too tough to accomplish";
    char *delim = "too";

    mysubstrfunc(str, delim);
}
