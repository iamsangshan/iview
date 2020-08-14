/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* Algorithm : 

    2 cars, slow and fast moving in a road which has a loop
    will eventually meet at some point
    
    - have a slow +1 and fast +2 pointer
    - traverse the list till we reach end. (fast && fast.next)
    - at any point if slow == fast, then Loop!
*/
    
bool hasCycle(struct ListNode *head) {
    
    struct ListNode *slow, *fast;
    
    if (!head)
        return false;
    
    slow = head;
    fast = head->next;
    
    while(fast && fast->next) {
        if (fast == slow)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return false;
}