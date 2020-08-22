
/* yet to submit in leetcode */

/*  Algorithm 
 *
 *  Create a stack and keep inserting char by char*
 *
 *  i.e.
 *  insert if its an open bracket
 *  compare with the top element if its a closing bracket
 *  the top element should be the corresponding open bracket
 *  else return false
 *
 *  traverse string till end
 *  if stack is empty then string is balanced.
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
