
/* yet to submit in leetcode */

/*  
 *  Sangeetha Shanmugam
 *  Aug 2020
 *
 *  Algorithm 
 *
 *  Create a stack and keep inserting char by char*
 *
 *  i.e.
 *  1 insert if its an open bracket
 *  2 compare with the top element if its a closing bracket
 *  3 the top element should be the corresponding open bracket
 *  4 else return false
 *
 *  5 traverse string till end
 *  6 if stack is empty then string is balanced.
 */

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
