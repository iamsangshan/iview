
/* yet to submit in leetcode */



struct mystack {
    int top;
    char *str;
};

bool isValid(char * s){
  
    struct mystack stack;
    int len = 0;
    char curr;
    
    if (!s)
        return false;
    
    stack.top = -1;
    len = strlen(s);
    
    stack.str = (char *)malloc(len);
    
    while (*s++ != '\0') {
        
        curr = *s;
        
        switch (curr) {
            /* closing parantheses */
            case ')':
                if (stack.top >= 0 && stack.str[stack.top] == '(') {
                    stack.top--;
                }
                else
                    return false;
                break;
            case ']':
                if (stack.top >= 0 && stack.str[stack.top] == '[') {
                    stack.top--;
                }
                else
                    return false;
                break;
            case '}':
                if (stack.top >= 0 && stack.str[stack.top] == '{') {
                    stack.top--;
                }
                else
                    return false;
                break;
            /* open parantheses */
            default:
                stack.str[++stack.top] = curr;
                break;
        }
    }
    
  
        return false;
}
