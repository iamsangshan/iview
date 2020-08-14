/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* ALgorithm

    - 2 cars traveling at a speed 10km and 20km. when fast car reaches destination, slow car        will be mid way
    
    - slow pointer, fast pointer, traverse the list till fast reaches the end
    
    - return slow pointer
    
    Note: start slow = fast =  head
    
*/

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow, *fast;
    
    if (!head)
        return NULL;
    
    slow = fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}