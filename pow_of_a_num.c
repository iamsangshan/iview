/* getting stack overflow for a particular unknown input on leetcode. otherwise working code. */

double myPowrecursive (double x, int n)
{
    if (n == 0)
        return 1;
    
    return (x * myPowrecursive(x, n-1));
}

double myPow(double x, int n){
    
    double ans = 0;
    int pow = 0;
    
    /* X power n is X multiplied by X n times. 
        we can use recursion here  */
    
    if (n == 0)
        return 1;
    
    if (n < 0)
        pow = n - (2 * n); /* make it positive */
    else
        pow = n;
    
    ans = myPowrecursive(x, pow);
    
    if (n < 0)
        ans = 1/ans;
    
    return ans;

}
