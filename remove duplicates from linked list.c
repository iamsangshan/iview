/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/* Algorithm 

i/p : 1 2 3 3 4 5 5 7 7 -> NULL
o/p : 1 2 3 4 5 7 -> NULL

 - traverse the list 
 - compare each node with the next node
 - if node == nextnode, then remove the next node
 - before removing, store the nextnode->next
 - adjust the pointers
*/

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *node, *nextnode, *save_next;
    
    if (!head)
        return NULL;
    
    node = head;
    nextnode = node->next;
    
    /* this check handles single node list */
    while (node && node->next) {
        
        if (node->val == node->next->val) {
          save_next = node->next->next;
          free(node->next);
          node->next = save_next;
        } else
          node = node->next;
    }
    return head;

}