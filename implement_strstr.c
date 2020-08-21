#include <string.h>
/* working code */

int strStr(char * haystack, char * needle){
    
    int i, j;
    int haylen = strlen(haystack);
    int needlelen = strlen(needle);
    
    if (!haystack || !needle)
        return -1;
    
    if (!haylen && !needlelen)
        return 0;
    
    if (strncmp(haystack, needle, needlelen) == 0)
        return 0;
    
    
       
    for (i = 0; i <= haylen-1; i++) {
        for (j = 0; j <= needlelen-1 && needle[j] == haystack[i+j]; j++);
        
         if (j >= needlelen) {
            return i;
         }
    }
    
    return -1;
  }
