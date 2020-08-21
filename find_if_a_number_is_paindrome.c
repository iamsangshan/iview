

bool isPalindrome(int x){
    
    int num, numdigits = 0;
    int arr[100], i, start, end;
    
    if (x < 0)
        return false;
    
    if (x == 0)
        return true;
    
    /*
     // giving runtime error
    arr = malloc (sizeof(numdigits));
    if (!arr) {
        return false;
    }
    */
        
    /* put the digits in an array n count the digits */
    num = x;
    i = 0;
    while (num && i < 99) {
        arr[i++] = num%10;
        num = num/10;
        numdigits++;
    }
    
    /* compare arr[start++] == arr[end--] */
    
    start = 0; end =  numdigits - 1;
    
    /* if last digit is 0, it cannot be a palindrome */
    if (arr[start] == 0)
        return false;
    
    while (start <= end && arr[start] == arr[end])
    { start++; end--;};
    
    if (start >= end)
        return true;
    else
        return false;
}
