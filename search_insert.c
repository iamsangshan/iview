
/* question link : 
 * https://leetcode.com/problems/search-insert-position/submissions/
 */

/* search for the targer element index by comparing each element
   from index 0. store the prev index value. 
   if you find the target value, return the current index. 
   if you find the element greater than 'target', then return the prev index. */

int searchInsert(int* nums, int numsSize, int target){
    
    int curr = 0;
    
    if (!nums)
        return 0;
    
    while (curr < numsSize) {
        if (nums[curr] >= target) {
            break;
        }
        curr++;
    }
    
    return curr;
}
